#pragma once

#include <memory>
#include "gui_message.h"
#include "ApplicationState.h"

class Application
{
  
public:

  static Application& Instance()
  {
    static Application application;
    return application;
  }

  void DispatchGUIMessage(GUI_MESSAGE message);

private:

  Application();
  Application(const Application&) = delete;
  Application& operator=(const Application&) = delete;

  friend class ApplicationState;
  
  void ChangeState(std::unique_ptr<ApplicationState> state);

  std::unique_ptr<ApplicationState> _state;
};
