#include "singleton.h"

ClassicSingleton* ClassicSingleton::instance = new ClassicSingleton();

DoubleCheckSingleton* DoubleCheckSingleton::instance = nullptr;

std::mutex DoubleCheckSingleton::mutex;