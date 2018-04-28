#include "DocumentWorkspace.h"
#include "AddVectorGraphicCommand.h"
#include "EraseVectorGraphicCommand.h"

DocumentWorkspace::DocumentWorkspace(const std::shared_ptr<Document>& document) {
  _document = document;
}

void DocumentWorkspace::DispatchGUIMessage(Application& application, GUI_MESSAGE message) {
  switch(message) {
    case GUI_MESSAGE::NEW_DOCUMENT: {
      _document = std::make_shared<Document>();
    } break;
    case GUI_MESSAGE::OPEN_FILE: {
      _document = OpenFile(GetFilename());
    } break;
    case GUI_MESSAGE::SAVE_FILE: {
      SaveFile(GetFilename());
    } break;
    case GUI_MESSAGE::CLOSE_DOCUMENT: {
      ChangeState(application, std::make_shared<EmptyWorkspace>());
    } break;
    case GUI_MESSAGE::PICK_POINT_INSTRUMENT:
    case GUI_MESSAGE::PICK_LINE_INSTRUMENT:
    case GUI_MESSAGE::PICK_TEXT_INSTRUMENT:
    case GUI_MESSAGE::PICK_RECTANGLE_INSTRUMENT:
    case GUI_MESSAGE::PICK_ERASER_INSTRUMENT: {
      _document->SetCommand(GetGraphicCommand(message));
    } break;
    case GUI_MESSAGE::CLICK_ON_DOCUMENT: {
      _document->Click();
    }
    case GUI_MESSAGE::REFRESH_VIEW: {
      _document->Draw();
    }
  }
}

void DocumentWorkspace::SaveFile(const std::string& filename) const {
  auto writer = GetDocumentIO(filename);
  writer->WriteDocument(filename, _document);
}

std::shared_ptr<GraphicCommand> DocumentWorkspace::GetGraphicCommand(GUI_MESSAGE message) {
  const auto commandItr = _drawingCommands.find(message);
  if(std::cend(_drawingCommands) != commandItr)
    return commandItr->second;
  else {
    std::shared_ptr<GraphicCommand> command;
    switch(message) {
      case GUI_MESSAGE::PICK_POINT_INSTRUMENT: {
        command = std::make_shared<AddVectorPointCommand>(_document);
      } break;
      case GUI_MESSAGE::PICK_LINE_INSTRUMENT: {
        command = std::make_shared<AddVectorLineCommand>(_document);
      } break;
      case GUI_MESSAGE::PICK_TEXT_INSTRUMENT: {
        command = std::make_shared<AddVectorTextCommand>(_document);
      } break;
      case GUI_MESSAGE::PICK_RECTANGLE_INSTRUMENT: {
        command = std::make_shared<AddVectorRectangleCommand>(_document);
      } break;
      case GUI_MESSAGE::PICK_ERASER_INSTRUMENT:  {
        command = std::make_shared<EraseVectorGraphicCommand>(_document);
      } break;
      default:
        throw std::invalid_argument("There's no graphic coomand for this gui message.");
    }
    _drawingCommands[message] = command;
    return command;
  }
}
