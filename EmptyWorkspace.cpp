#include "EmptyWorkspace.h"
#include "DocumentWorkspace.h"

void EmptyWorkspace::DispatchGUIMessage(Application& application, GUI_MESSAGE message) {
  switch(message) {
    case GUI_MESSAGE::NEW_DOCUMENT: {
      ChangeState(application,
                  std::make_shared<DocumentWorkspace>());
    } break;
    case GUI_MESSAGE::OPEN_DOCUMENT: {
      ChangeState(application,
                  std::make_shared<DocumentWorkspace>(GetFilename()));
    } break;
  }
}

std::string EmptyWorkspace::GetFilename() const {
  return "vector_drawings.wmf";
}
