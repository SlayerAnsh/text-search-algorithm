#include "print.h"

#include <iomanip>
#include <iostream>

using namespace std;

void HELPER::printTimings(double duration)
{
    std::cout << std::fixed << duration << "(nano seconds)";
}

void HELPER::printSearchIndex(std::vector<int64_t> search_indexes)
{
    for (auto index : search_indexes) {
        std::cout << index << " ";
    }
    std::cout << std::endl;
}
