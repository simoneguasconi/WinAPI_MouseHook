#include "../include/core/MouseHookCallback.hpp"
#include "../include/core/MouseHookSingleton.hpp"
#include "../include/core/enums/MouseButtonsEnum.hpp"

using namespace mouse_hook;
using namespace mouse_hook::core;
using namespace mouse_hook::core::enums;

MouseHookSingleton::MouseHookSingleton()
  : msg()
  , hook(nullptr)
{
  set_hook();
}

MouseHookSingleton::~MouseHookSingleton()
{
  unhook();
}

MouseHookSingleton& MouseHookSingleton::instance()
{
  static MouseHookSingleton mh{};
  return mh;
}

void MouseHookSingleton::set_hook()
{
  hook = SetWindowsHookEx(WH_MOUSE_LL,
                          mouse_callback,
                          nullptr,
                          0);
  if (!hook) {
    MessageBox(nullptr,
               L"set_hook() failed.",
               L"Error",
               MB_ICONERROR);
  }
}

void MouseHookSingleton::unhook()
{
  UnhookWindowsHookEx(hook);
}

unsigned long long MouseHookSingleton::get_messages()
{
  GetMessage(&msg, nullptr, 0, 0);
  return msg.wParam;
}
