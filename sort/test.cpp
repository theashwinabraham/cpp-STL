#include <iostream>
#include <cstdlib>
#include <chrono>
#include "sort.hpp"

constexpr std::size_t SIZE = 100'000'000;
constexpr std::size_t RANGE = 3001;

int main(int argc, char ** argv)
{
    int *arr = new int[SIZE];
    for(int i = 0; i < SIZE; ++i) arr[i] = rand() % RANGE;
    auto t1 = std::chrono::high_resolution_clock::now();
    sort::insertionsort(arr, SIZE);
    auto t2 = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration<double, std::milli>(t2 - t1).count() << '\n';
    delete [] arr;
}
