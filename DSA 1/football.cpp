#include "football.h"

int ConvertCharToIndex(char _char)
{
    if (_char >= '0' && _char <= '9')
        return ((int)_char - (int)'0') + 1;
    
    if (_char >= 'a' && _char <= 'z')
        return ((int)_char - (int)'a') + 11;
    
    if (_char >= 'A' && _char <= 'Z')
        return ((int)_char - (int)'A') + 37;
    
    return -1;
}

char ConvertIndexToChar(int n)
{
    if(n == 0)
        return '\0';
    if (n >= 1 && n <= 10)
        return '0' + (n - 1);
    
    if (n >= 11 && n <= 36)
        return 'a' + (n - 11);

    if (n >= 37 && n <= 62)
        return 'A' + (n - 37);

    return '\0';
}

void CountSortNConvert(char* items, size_t count)
{
    const size_t DOMAIN_SIZE = 63;
    int counts[DOMAIN_SIZE] = {0};
    
    for(size_t i = 0; i < count; i++)
        counts[ConvertCharToIndex(items[i])]++;
    
    for (size_t i = 1; i < DOMAIN_SIZE; i++)
    {
        for (size_t k = 0; k < counts[i]; k++)
            std::cout << ConvertIndexToChar(i);
    }
    
    std::cout << std::endl;
}