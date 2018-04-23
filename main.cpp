#include <iostream>
#include "Application.h"
#include "gui_message.h"

int main(int argc, char const *argv[])
{
  try
  {
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::NEW_DOCUMENT);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::PICK_POINT_INSTRUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::CLICK_ON_DOCUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::REFRESH_VIEW);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::PICK_LINE_INSTRUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::CLICK_ON_DOCUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::REFRESH_VIEW);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::PICK_TEXT_INSTRUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::CLICK_ON_DOCUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::REFRESH_VIEW);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::PICK_RECTANGLE_INSTRUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::CLICK_ON_DOCUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::REFRESH_VIEW);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::SAVE_DOCUMENT);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::CLOSE_DOCUMENT);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::OPEN_DOCUMENT);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::PICK_ERASER_INSTRUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::CLICK_ON_DOCUMENT);
    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::REFRESH_VIEW);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::SAVE_DOCUMENT);

    Application::Instance().DispatchGUIMessage(GUI_MESSAGE::CLOSE_DOCUMENT);
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << std::endl;
  }
  return 0;
}
