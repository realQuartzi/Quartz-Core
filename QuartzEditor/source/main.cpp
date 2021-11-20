#include <iostream>
#include "quartz/engine.h"

int main()
{
    Quartz::Engine& engine = Quartz::Engine::Instance();
    engine.Run();

    std::cout << "Press ENTER to continue...";
    std::cin.ignore();

    return 0;
}