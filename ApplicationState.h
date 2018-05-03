#pragma once

#include <memory>
#include "gui_message.h"

class Application;

class ApplicationState
{

public:

  virtual ~ApplicationState(){};

  virtual void DispatchGUIMessage(Application& application, GUI_MESSAGE message) = 0;

protected:

  void ChangeState(Application& application, std::unique_ptr<ApplicationState> applicationState);

};
