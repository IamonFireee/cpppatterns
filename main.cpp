#include <iostream>

#include "singleton/singleton.h"

int main() {
    std::cout << &ClassicSingleton::getInstance() << std::endl;
    std::cout << &MayersSingleton::getInstance() << std::endl;
    std::cout << &DoubleCheckSingleton::getInstance() << std::endl;

}
