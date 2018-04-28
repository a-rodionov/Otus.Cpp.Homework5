#include <algorithm>
#include "EmptyWorkspace.h"
#include "DocumentWorkspace.h"

void EmptyWorkspace::DispatchGUIMessage(Application& application, GUI_MESSAGE message) {
  switch(message) {
    case GUI_MESSAGE::NEW_DOCUMENT: {
      ChangeState(application, 
                  std::make_shared<DocumentWorkspace>(std::make_shared<Document>()));
    } break;
    case GUI_MESSAGE::OPEN_FILE: {
      ChangeState(application,
                  std::make_shared<DocumentWorkspace>(OpenFile(GetFilename())));
    } break;
  }
}

std::string EmptyWorkspace::GetFilename() const {
  return "vector_drawings.wmf";
}

std::shared_ptr<Document_IO> EmptyWorkspace::GetDocumentIO(const std::string& filename) const {
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

std::shared_ptr<Document> EmptyWorkspace::OpenFile(const std::string& filename) {
  if(filename.empty())
    return std::make_shared<Document>();
  else {
    auto reader = GetDocumentIO(filename);
    return reader->ReadDocument(filename);
  }
}
