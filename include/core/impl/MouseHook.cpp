#include "../MouseHook.hpp"

using namespace mouse_hook;
using namespace mouse_hook::core;

MouseHook::MouseHook()
  : msg()
  , hook(nullptr)
{
  set_hook();
}

MouseHook::~MouseHook()
{
  unhook();
}

auto MouseHook::Factory::build()
-> MouseHook
{
  return MouseHook();
}

auto MouseHook::set_hook() -> void
{
  hook = SetWindowsHookEx(WH_MOUSE_LL,
                          core::mouse_callback,
                          nullptr,
                          0);
  if (!hook) {
    MessageBox(nullptr,
               L"set_hook() failed.",
               L"Error",
               MB_ICONERROR);
  }
}

auto MouseHook::unhook() -> void
{
  UnhookWindowsHookEx(hook);
}

auto MouseHook::get_messages() 
-> unsigned long long
{
  GetMessage(&msg, nullptr, 0, 0);
  return msg.wParam;
}