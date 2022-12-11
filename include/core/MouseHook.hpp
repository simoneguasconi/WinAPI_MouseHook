#pragma once
#include <iostream>
#include <windows.h>
#include "../core/MouseHookCallback.hpp"

namespace mouse_hook {
namespace core {
class MouseHook
{
public:
  struct Factory
  {
    static MouseHook build();
  };
private:
  MouseHook();
public:
  ~MouseHook();
public:
  auto get_messages() 
    -> unsigned long long;
public:
  MSG msg;
  HHOOK hook;
private:
  auto set_hook() -> void;
  auto unhook() -> void;
};
} // core
} // mouse_hook