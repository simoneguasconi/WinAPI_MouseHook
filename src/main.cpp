#include "../include/MouseHook.hpp"
using namespace mouse_hook;

int main()
{
  core::MouseHookSingleton::instance()
    .get_messages();
}