#pragma once

#include <map>
#include "EmptyWorkspace.h"
#include "Document.h"
#include "GraphicCommand.h"

class DocumentWorkspace final : public EmptyWorkspace
{

public:

  explicit DocumentWorkspace(const std::shared_ptr<Document>& document);

  void DispatchGUIMessage(Application& application, GUI_MESSAGE message) override;

private:

  void SaveFile(const std::string& filename) const;

  std::shared_ptr<GraphicCommand> GetGraphicCommand(GUI_MESSAGE message);

  std::shared_ptr<Document> _document;
  std::map<GUI_MESSAGE, std::shared_ptr<GraphicCommand>> _drawingCommands;

};
