#pragma once

#include "Application.h"

class ApplicationState
{

public:

  virtual ~ApplicationState(){};

  virtual void DispatchGUIMessage(Application& application, GUI_MESSAGE message) = 0;

protected:

  void ChangeState(Application& application, const std::shared_ptr<ApplicationState>& applicationState) {
    application.ChangeState(applicationState);
  }

};
