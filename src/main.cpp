#include "../include/MouseHookLib.hpp"
using namespace mouse_hook;

int main()
{
  try {
    core::MouseHook::Factory::build()
      .get_mouse_info();
  } catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
}