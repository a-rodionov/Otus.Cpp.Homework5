#include <algorithm>
#include "DocumentWorkspace.h"
#include "EmptyWorkspace.h"
#include "AddVectorGraphicCommand.h"
#include "EraseVectorGraphicCommand.h"

DocumentWorkspace::DocumentWorkspace() {
  OpenDocument("");
}

DocumentWorkspace::DocumentWorkspace(const std::string& filename) {
  OpenDocument(filename);
}

void DocumentWorkspace::DispatchGUIMessage(Application& application, GUI_MESSAGE message) {
  switch(message) {
    case GUI_MESSAGE::NEW_DOCUMENT: {
      OpenDocument("");
    } break;
    case GUI_MESSAGE::OPEN_DOCUMENT: {
      OpenDocument(GetFilename());
    } break;
    case GUI_MESSAGE::SAVE_DOCUMENT: {
      SaveDocument();
    } break;
    case GUI_MESSAGE::CLOSE_DOCUMENT: {
      ChangeState(application, std::make_shared<EmptyWorkspace>());
    } break;
    case GUI_MESSAGE::PICK_POINT_INSTRUMENT:
    case GUI_MESSAGE::PICK_LINE_INSTRUMENT:
    case GUI_MESSAGE::PICK_TEXT_INSTRUMENT:
    case GUI_MESSAGE::PICK_RECTANGLE_INSTRUMENT:
    case GUI_MESSAGE::PICK_ERASER_INSTRUMENT: {
      _document.first->SetCommand(GetGraphicCommand(message));
    } break;
    case GUI_MESSAGE::CLICK_ON_DOCUMENT: {
      _document.first->Click();
    }
    case GUI_MESSAGE::REFRESH_VIEW: {
      _document.first->Draw();
    }
  }
}

void DocumentWorkspace::OpenDocument(const std::string& filename) {
  if(filename.empty())
    _document = std::make_pair(std::make_shared<Document>(), "");
  else {
    auto reader = GetDocumentIO(filename);
    _document = std::make_pair(reader->ReadDocument(filename), filename);
  }
}

void DocumentWorkspace::SaveDocument() const {
  auto filename = _document.second;
  if(filename.empty())
    filename = GetFilename();
  auto writer = GetDocumentIO(filename);
  writer->WriteDocument(filename, _document.first);
}

std::string DocumentWorkspace::GetFilename() const {
  return "vector_drawings.cdr";
}

std::shared_ptr<GraphicCommand> DocumentWorkspace::GetGraphicCommand(GUI_MESSAGE message) {
  const auto commandItr = _drawingCommands.find(message);
  if(std::cend(_drawingCommands) != commandItr)
    return commandItr->second;
  else {
    std::shared_ptr<GraphicCommand> command;
    switch(message) {
      case GUI_MESSAGE::PICK_POINT_INSTRUMENT: {
        command = std::make_shared<AddVectorPointCommand>(_document.first);
      } break;
      case GUI_MESSAGE::PICK_LINE_INSTRUMENT: {
        command = std::make_shared<AddVectorLineCommand>(_document.first);
      } break;
      case GUI_MESSAGE::PICK_TEXT_INSTRUMENT: {
        command = std::make_shared<AddVectorTextCommand>(_document.first);
      } break;
      case GUI_MESSAGE::PICK_RECTANGLE_INSTRUMENT: {
        command = std::make_shared<AddVectorRectangleCommand>(_document.first);
      } break;
      case GUI_MESSAGE::PICK_ERASER_INSTRUMENT:  {
        command = std::make_shared<EraseVectorGraphicCommand>(_document.first);
      } break;
      default:
        throw std::invalid_argument("There's no graphic coomand for this gui message.");
    }
    _drawingCommands[message] = command;
    return command;
  }
}

std::shared_ptr<Document_IO> DocumentWorkspace::GetDocumentIO(const std::string& filename) const {
  auto dotPosition = filename.find_last_of('.');
  if(std::string::npos == dotPosition)
    throw std::invalid_argument("File format isn't supported.");

  auto fileExtension = filename.substr(++dotPosition);
  std::transform(std::begin(fileExtension), std::end(fileExtension), std::begin(fileExtension), ::toupper);
  if(FILE_EXTENSION_WMF == fileExtension)
    return std::make_shared<Document_IO_WMF>();
  else if(FILE_EXTENSION_CDR == fileExtension)
    return std::make_shared<Document_IO_CDR>();
  else
    throw std::invalid_argument("File format isn't supported.");
}
