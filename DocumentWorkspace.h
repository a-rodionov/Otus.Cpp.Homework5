#pragma once

#include <map>
#include "ApplicationState.h"
#include "Document.h"
#include "GraphicCommand.h"
#include "Document_IO.h"

using DocumentFile = std::pair<std::shared_ptr<Document>, std::string>;

class DocumentWorkspace final : public ApplicationState
{

public:

  DocumentWorkspace();

  explicit DocumentWorkspace(const std::string& filename);

  void DispatchGUIMessage(Application& application, GUI_MESSAGE message) override;

private:

  void OpenDocument(const std::string& filename);

  void SaveDocument() const;

  std::string GetFilename() const;

  std::shared_ptr<GraphicCommand> GetGraphicCommand(GUI_MESSAGE message);

  std::shared_ptr<Document_IO> GetDocumentIO(const std::string& filename) const;

  DocumentFile _document;
  std::map<GUI_MESSAGE, std::shared_ptr<GraphicCommand>> _drawingCommands;

};
