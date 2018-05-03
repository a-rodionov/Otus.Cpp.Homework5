#include "Application.h"
#include "EmptyWorkspace.h"
#include "DocumentWorkspace.h"

Application::Application()
{
  _state = std::make_unique<EmptyWorkspace>();
}

void Application::DispatchGUIMessage(GUI_MESSAGE message)
{
  _state->DispatchGUIMessage(*this, message);
}

void Application::ChangeState(std::unique_ptr<ApplicationState> state) {
  _state.reset(state.release());
}
