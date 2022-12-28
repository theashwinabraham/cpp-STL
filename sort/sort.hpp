/*
* AUTHOR: ASHWIN ABRAHAM
*/
// note: These algorithms have been made only for integer arrays

#ifndef SORT_HPP
#define SORT_HPP
namespace sort
{
    // these algorithms sort integer arrays
    void bubblesort(int *, long long int, long long int = 0);
    void selectionsort(int *, long long int, long long int = 0);
    void insertionsort(int *, long long int, long long int = 0);
    void fast_insertionsort(int *, long long int, long long int = 0);
    void countingsort(int *, long long int, long long int = 0);
    void mergesort(int *, long long int, long long int = 0);
    void heapsort(int *, long long int, long long int = 0);
    void quicksort(int *, long long int, long long int = 0);
    void sleepsort(int *, long long int, long long int = 0);
    void threadsort(int *, long long int, long long int = 0);
    void thread_quicksort(int *, long long int, long long int = 0);

    // returns whether or not an integer is present in the array
    bool linearsearch(int *, int, long long int, long long int = 0);
    bool threadsearch(int *, int, long long int, long long int = 0);
    // returns whether or not an integer is present in the array (only for sorted arrays)
    bool binarysearch(int *, int, long long int, long long int = 0);
    // returns index of the first element > parameter (returns end if all elements are <= parameter) (only for sorted arrays)
    int upperlim(int *, int, long long int, long long int = 0);
    // returns index of the first element >= parameter (returns end if all elements are < parameter) (only for sorted arrays)
    int lowerlim(int *, int, long long int, long long int = 0);
}
#endif