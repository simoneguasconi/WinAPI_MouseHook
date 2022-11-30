#pragma once
#include <type_traits>

namespace mouse_hook
{
  namespace core
  {
    namespace enums
    {
      enum class MouseButtonsEnum
        : unsigned short
      {
        LeftButton,
        MiddleButton,
        RightButton,
        NoneButton
      };

      constexpr auto get_button_type(MouseButtonsEnum button)
      {
        return std::underlying_type_t<MouseButtonsEnum>(button);
      }
    }
  }
}