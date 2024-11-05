#include <iostream>
#include <vector>
#include "../utils.hpp"
#include "football.h"



int main()
{
    size_t N;
    std::cin >> N;

    char* symbols = new char[N];

    for (size_t i = 0; i < N; i++)
        std::cin >> symbols[i];
    
    CountSortNConvert(symbols, N);

    return 0;
}