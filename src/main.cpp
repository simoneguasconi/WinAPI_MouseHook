#include "../include/MouseHookLib.hpp"
using namespace mouse_hook;

int main()
{
  try {
    core::MouseHook::Factory::build()
      .get_messages();
  } catch (std::exception& e) {
    std::cout << e.what() << '\n';
  }
}