#include "../MouseHookCallback.hpp"

auto mouse_hook::core::mouse_callback(int nCode, 
                                      unsigned long long wParam, 
                                      long long lParam)
  -> long long 
{
  MSLLHOOKSTRUCT* msllhkstruct = reinterpret_cast<MSLLHOOKSTRUCT*>(lParam);
  if (nCode == HC_ACTION) {
    if (msllhkstruct) {
      printf_s("{ x='%i', y='%i' }\n", msllhkstruct->pt.x, msllhkstruct->pt.y);

      const char* button_name[] = { "left", "middle", "right" };
      enums::MouseButtonsEnum button = enums::MouseButtonsEnum::NoneButton;

      const char* button_state[] = { "up", "down" };
      const char* wheel_scroll[] = { "forward", "backward" };

      bool down = false;
      switch (wParam) {
        case WM_LBUTTONDOWN: down = true;
        case WM_LBUTTONUP: button = enums::MouseButtonsEnum::LeftButton;
          break;
        case WM_RBUTTONDOWN: down = true;
        case WM_RBUTTONUP: button = enums::MouseButtonsEnum::RightButton;
          break;
        case WM_MBUTTONDOWN: down = true;
        case WM_MBUTTONUP: button = enums::MouseButtonsEnum::MiddleButton;
          break;
        case WM_MOUSEWHEEL:
          down = static_cast<std::make_signed_t<WORD>>(
            HIWORD(msllhkstruct->mouseData)) < 0;
          printf_s("[mouse wheel scrolled %s]\n", wheel_scroll[down]);
          break;
      }

      if (button != enums::MouseButtonsEnum::NoneButton) {
        printf_s("[button='%s', state='%s']\n"
                 , button_name[get_button_type(button)]
                 , button_state[down]);
      }
    }
  }
  return CallNextHookEx(
    MouseHook::Factory::build().hook, nCode, wParam, lParam);
}

