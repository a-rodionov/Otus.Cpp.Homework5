#include "Application.h"
#include "EmptyWorkspace.h"
#include "DocumentWorkspace.h"

Application::Application()
{
  _state = std::make_shared<EmptyWorkspace>();
}

void Application::DispatchGUIMessage(GUI_MESSAGE message)
{
  _state->DispatchGUIMessage(*this, message);
}

void Application::ChangeState(const std::shared_ptr<ApplicationState>& state) {
  _state = state;
}
