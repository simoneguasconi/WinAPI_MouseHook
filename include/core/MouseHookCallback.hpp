#pragma once
#include "../core/MouseHook.hpp"
#include "../core/enums/MouseButtonsEnum.hpp"

namespace mouse_hook {
namespace core {
auto __stdcall mouse_callback(int nCode,
                              unsigned long long wParam,
                              long long lParam)
  -> long long;
} // core
} // mouse_hook