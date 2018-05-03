#include "Application.h"

void ApplicationState::ChangeState(Application& application, std::unique_ptr<ApplicationState> applicationState) {
  application.ChangeState(std::move(applicationState));
}
