#pragma once

#include "ApplicationState.h"
#include "Document_IO.h"

class EmptyWorkspace : public ApplicationState
{

public:

  void DispatchGUIMessage(Application& application, GUI_MESSAGE message) override;

protected:

  std::string GetFilename() const;

  std::unique_ptr<Document_IO> GetDocumentIO(const std::string& filename) const;

  std::unique_ptr<Document> OpenFile(const std::string& filename) const;

};
