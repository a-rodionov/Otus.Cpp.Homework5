#pragma once

#include "ApplicationState.h"

class EmptyWorkspace final : public ApplicationState
{

public:

  void DispatchGUIMessage(Application& application, GUI_MESSAGE message) override;

private:

  std::string GetFilename() const;

};
