#include "tours.h"

void Tours(std::vector<size_t>& w, size_t Q, const size_t* mins, const size_t* maxes)
{
    std::sort(w.begin(), w.end());
    for (size_t q = 0; q < Q; q++)
    {
        int count = 0;
        
        auto lB = std::lower_bound(w.begin(), w.end(), mins[q]);
        auto uB = std::upper_bound(w.begin(), w.end(), maxes[q]);
        // std::cout << << ", " <<  << std::endl;


        std::cout << ((int)(uB - w.begin()) - (int)(lB - w.begin())) << std::endl;
    }
    
}

void ToursInput()
{
    size_t N, Q;
    std::cin >> N >> Q;
    std::vector<size_t> w(N);

    for (size_t i = 0; i < N; i++)
        std::cin >> w[i];

    size_t* mins = new size_t[Q];
    size_t* maxes = new size_t[Q];

    for (size_t i = 0; i < Q; i++)
        std::cin >> mins[i] >> maxes[i];

    if (N == 0)
    {
        for (size_t i = 0; i < Q; i++)
            std::cout << 0 << std::endl;
        
        delete[] mins;
        delete[] maxes;
        return;
    }

    if (N == 1)
    {
        for (size_t i = 0; i < Q; i++)
        if (w[0] >= mins[i] && w[0] <= maxes[i])
            std::cout << 1 << std::endl;
        else
            std::cout << 0 << std::endl;

        delete[] mins;
        delete[] maxes;
        return;
    }
    
    

    Tours(w, Q, mins, maxes);
    
    delete[] mins;
    delete[] maxes;
}