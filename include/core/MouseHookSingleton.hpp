#pragma once
#include <iostream>
#include <windows.h>
#include "../core/MouseHookCallback.hpp"
#include "../core/MouseHookSingleton.hpp"

namespace mouse_hook
{
  namespace core
  {
    class MouseHookSingleton
    {
    public:
      static MouseHookSingleton& instance();
      ~MouseHookSingleton();
      unsigned long long get_messages();
      MSG msg;
      HHOOK hook;
    private:
      MouseHookSingleton();
      // non construction-copyable
      MouseHookSingleton(const MouseHookSingleton&) = delete;
      // non copyable
      MouseHookSingleton& operator=(const MouseHookSingleton&) = delete;
    private:
      void set_hook();
      void unhook();
    };
  }
}