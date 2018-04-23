#pragma once

#include <memory>
#include "gui_message.h"

class ApplicationState;

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
  
  void ChangeState(const std::shared_ptr<ApplicationState>& state);

  std::shared_ptr<ApplicationState> _state;
};
