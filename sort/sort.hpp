/*
* AUTHOR: ASHWIN ABRAHAM
*/
// note: These algorithms have been made only for integer arrays

#ifndef SORT_HPP
#define SORT_HPP
namespace sort
{
    // these algorithms sort integer arrays
    void bubblesort(int *, int, int = 0);
    void selectionsort(int *, int, int = 0);
    void insertionsort(int *, int, int = 0);
    void fast_insertionsort(int *, int, int = 0);
    void countingsort(int *, int, int = 0);
    void mergesort(int *, int, int = 0);
    void heapsort(int *, int, int = 0);
    void quicksort(int *, int, int = 0);
    void sleepsort(int *, int, int = 0);
    void threadsort(int *, int, int = 0);
    void thread_quicksort(int *, int, int = 0);

    // returns whether or not an integer is present in the array
    bool linearsearch(int *, int, int, int = 0);
    // returns whether or not an integer is present in the array (only for sorted arrays)
    bool binarysearch(int *, int, int, int = 0);
    // returns index of the first element > parameter (returns end if all elements are <= parameter) (only for sorted arrays)
    int upperlim(int *, int, int, int = 0);
    // returns index of the first element >= parameter (returns end if all elements are < parameter) (only for sorted arrays)
    int lowerlim(int *, int, int, int = 0);
}
#endif