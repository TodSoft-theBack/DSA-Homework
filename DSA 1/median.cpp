#include "median.h"   

int Insert(int* arr, int len, int n)
{
    int j = len - 1;
    
    while (j >= 0 && arr[j] > n) 
    {
        arr[j + 1] = arr[j];
        j--;
    }
    
    return j + 1;
}


void insertionSort(int* arr, int len) 
{
    for (int i = 0; i < len; i++) 
    {
        int key = arr[i];
        int insertIndex = Insert(arr,i, key);
        arr[insertIndex] = key;
        
        double median = arr[i];

        // if ( i == 0)
        // {
        //     std::cout << arr[i] << std::endl;
        //     continue;
        // }
        
        if((i + 1) % 2 == 0)
            median = (arr[i / 2] + arr[i / 2 + 1])/2.0;
        else
            median =  arr[i / 2];
        
        std::cout << median << std::endl;
    }
}

int Median()
{
    int N;
    std::cin >> N;
    
    int* arr = new int[N];
    
    for(int i = 0; i < N; i++)
        std::cin >> arr[i];

    insertionSort(arr, N);
    
    delete[] arr;
      
    return EXIT_SUCCESS;
}