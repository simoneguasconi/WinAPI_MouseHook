#pragma once
#include "../core/MouseHookSingleton.hpp"
#include "../core/enums/MouseButtonsEnum.hpp"

namespace mouse_hook
{
  namespace core
  {
    long long int __stdcall mouse_callback(int nCode,
                                           unsigned long long wParam,
                                           long long lParam);
  }
}