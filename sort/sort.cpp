/*
* AUTHOR: ASHWIN ABRAHAM
*/

// note: These algorithms have been made only for integer arrays

#include <cstdlib>
#include <mutex>
#include <thread>
#include <unistd.h>
#include "sort.hpp"

static inline void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sort::bubblesort(int arr[], int end, int begin /*= 0*/)
{
    for(int right = end; right > begin + 1; --right)
    {
        bool sorted = true;
        for (int i = begin; i < right - 1; ++i)
        {
            if (arr[i] > arr[i + 1])
            {
                sorted = false;
                swap(arr[i], arr[i + 1]);
            }
        }
        if (sorted) break;
    }
}

void sort::selectionsort(int arr[], int end, int begin /*= 0*/)
{
    for(int right = end; right > begin + 1; --right)
    {
        int maxind = begin;
        for (int i = 1 + begin; i < right; ++i)
        {
            if (arr[i] > arr[maxind])
            {
                maxind = i;
            }
        }
        swap(arr[maxind], arr[right - 1]);
    }
}

void sort::insertionsort(int arr[], int end, int begin /*= 0*/)
{
    for (int i = begin; i < end; ++i)
    {
        int j = begin;
        for (; j < i; ++j)
        {
            if (arr[j] > arr[i])
                break;
        }
        int temp = arr[i];
        for (int k = i; k > j; --k)
            arr[k] = arr[k - 1];
        arr[j] = temp;
    }
}

void sort::fast_insertionsort(int arr[], int end, int begin /*= 0*/)
{
    for(int i = begin; i < end - 1; ++i)
    {
        int val = arr[i + 1];
        int pos = sort::upperlim(arr, val, i + 1);
        for(int j = i; j >= pos; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[pos] = val;
    }
}

void sort::countingsort(int arr[], int end, int begin /*= 0*/)
{
    if (end - begin <= 1) return;
    int min = arr[begin], max = arr[begin];
    for (int i = 1 + begin; i < end; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int *book = new int[max - min + 1]();
    for (int i = begin; i < end; ++i) ++book[arr[i] - min];

    for(int val = min, pos = 0; val <= max; ++val)
    {
        for(int j = 0; j < book[val - min]; ++j) arr[pos + j] = val;
        pos += book[val - min];
    }

    delete [] book;
}

void sort::mergesort(int arr[], int end, int begin /*= 0*/)
{
    if ((end - begin) <= 1)
        return;
    sort::mergesort(arr, (begin + end) / 2, begin);
    sort::mergesort(arr, end, (begin + end) / 2);
    int kl = begin, kr = (begin + end) / 2;
    int *sortedarr = new int[end - begin]();
    for (int i = 0; i < (end - begin); ++i)
    {
        if (kl < (begin + end) / 2)
        {
            if (kr < end)
            {
                if (arr[kl] < arr[kr])
                {
                    sortedarr[i] = arr[kl];
                    ++kl;
                }
                else
                {
                    sortedarr[i] = arr[kr];
                    ++kr;
                }
            }
            else
            {
                sortedarr[i] = arr[kl];
                ++kl;
            }
        }
        else if (kr < end)
        {
            sortedarr[i] = arr[kr];
            ++kr;
        }
        else
            break;
    }
    for (int i = begin; i < end; ++i)
        arr[i] = sortedarr[i - begin];
    delete [] sortedarr;
}

void sort::heapsort(int arr[], int end, int begin /*= 0*/)
{
    if(end - begin <= 1) return;
    for(int i = end - begin - 1; i >= 0; --i)
    {
        for(int heap_violator = i; ;)
        {
            if(2*heap_violator + 2 < end - begin)
            {
                if(arr[begin + 2*heap_violator + 1] > arr[begin + 2*heap_violator + 2])
                {
                    if(arr[begin + heap_violator] < arr[begin + 2*heap_violator + 1])
                    {
                        swap(arr[begin + heap_violator], arr[begin + 2*heap_violator + 1]);
                        heap_violator = 2*heap_violator + 1;
                    }
                    else break;
                }
                else
                {
                    if(arr[begin + heap_violator] < arr[begin + 2*heap_violator + 2])
                    {
                        swap(arr[begin + heap_violator], arr[begin + 2*heap_violator + 2]);
                        heap_violator = 2*heap_violator + 2;
                    }
                    else break;
                }
            }
            else if(2*heap_violator + 2 == end - begin)
            {
                if(arr[begin + heap_violator] < arr[begin + 2*heap_violator + 1])
                {
                    swap(arr[begin + heap_violator], arr[begin + 2*heap_violator + 1]);
                    heap_violator = 2*heap_violator + 1;
                }
                else break;
            }
            else break;
        }
    }
    for(int i = end - begin - 1; i >= 0; --i)
    {
        swap(arr[begin], arr[begin + i]);
        for(int heap_violator = 0; ; )
        {
            if(2*heap_violator + 2 < i)
            {
                if(arr[begin + 2*heap_violator + 1] > arr[begin + 2*heap_violator + 2])
                {
                    if(arr[begin + heap_violator] < arr[begin + 2*heap_violator + 1])
                    {
                        swap(arr[begin + heap_violator], arr[begin + 2*heap_violator + 1]);
                        heap_violator = 2*heap_violator + 1;
                    }
                    else break;
                }
                else
                {
                    if(arr[begin + heap_violator] < arr[begin + 2*heap_violator + 2])
                    {
                        swap(arr[begin + heap_violator], arr[begin + 2*heap_violator + 2]);
                        heap_violator = 2*heap_violator + 2;
                    }
                    else break;
                }
            }
            else if(2*heap_violator + 2 == i)
            {
                if(arr[begin + heap_violator] < arr[begin + 2*heap_violator + 1])
                {
                    swap(arr[begin + heap_violator], arr[begin + 2*heap_violator + 1]);
                    heap_violator = 2*heap_violator + 1;
                }
                else break;
            }
            else break;
        }
    }
}

void sort::quicksort(int arr[], int end, int begin /*= 0*/)
{
    if ((end - begin) <= 1)
        return;
    int pivot = begin + rand() % (end - begin), num_less = 0;
    for (int i = begin; i < end; ++i)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr[i], arr[begin + num_less]);
            if (begin + num_less == pivot)
                pivot = i;
            ++num_less;
        }
    }
    swap(arr[begin + num_less], arr[pivot]);
    sort::quicksort(arr, begin + num_less, begin);
    sort::quicksort(arr, end, begin + num_less + 1);
}

void sort::sleepsort(int arr[], int end, int begin /*= 0*/)
{
    if(end - begin <= 1) return;
    std::mutex locker;
    auto sleeper_func = [&locker](int val, int *num_sorted, int min, int *ptr){ sleep(val - min + 1); locker.lock(); ptr[*num_sorted] = val; ++(*num_sorted); locker.unlock(); };
    int min = arr[begin];
    for(int i = begin + 1; i < end; ++i)
    {
        if(arr[i] < min) min = arr[i];
    }

    int num_sorted = begin;
    std::thread *threads = new std::thread[end - begin - 1];
    for(int i = begin; i < end - 1; ++i)
    {
        threads[i - begin] = std::thread(sleeper_func, arr[i], &num_sorted, min, arr);
    }
    sleeper_func(arr[end - 1], &num_sorted, min, arr);
    for(int i = begin; i < end - 1; ++i) threads[i - begin].join();
    delete [] threads;
}

void sort::threadsort(int arr[], int end, int begin /*= 0*/)
{
    if ((end - begin) <= 1)
        return;
    std::thread t(sort::mergesort, arr, (begin + end) / 2, begin);
    sort::mergesort(arr, end, (begin + end) / 2);
    t.join();
    int kl = begin, kr = (begin + end) / 2;
    int *sortedarr = new int[end - begin]();
    for (int i = 0; i < (end - begin); ++i)
    {
        if (kl < (begin + end) / 2)
        {
            if (kr < end)
            {
                if (arr[kl] < arr[kr])
                {
                    sortedarr[i] = arr[kl];
                    ++kl;
                }
                else
                {
                    sortedarr[i] = arr[kr];
                    ++kr;
                }
            }
            else
            {
                sortedarr[i] = arr[kl];
                ++kl;
            }
        }
        else if (kr < end)
        {
            sortedarr[i] = arr[kr];
            ++kr;
        }
        else
            break;
    }
    for (int i = begin; i < end; ++i)
        arr[i] = sortedarr[i - begin];
    delete [] sortedarr;
}

void sort::thread_quicksort(int arr[], int end, int begin /*= 0*/)
{
    if(end - begin <= 1) return;
    int pivot = begin + rand() % (end - begin), num_less = 0;
    for (int i = begin; i < end; ++i)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr[i], arr[begin + num_less]);
            if (begin + num_less == pivot)
                pivot = i;
            ++num_less;
        }
    }
    swap(arr[begin + num_less], arr[pivot]);
    std::thread t(sort::quicksort, arr, begin + num_less, begin);
    sort::quicksort(arr, end, begin + num_less + 1);
    t.join();
}

bool sort::binarysearch(int arr[], int search, int end, int begin /*= 0*/)
{
    if (end <= begin || arr[begin] > search || arr[end - 1] < search) return false;
    if(arr[begin] == search || arr[end - 1] == search) return true;
    int x_left = begin, x_right = end - 1;
    while(x_right - x_left > 1)
    {
        if(arr[(x_left + x_right)/2] > search) x_right = (x_left + x_right)/2;
        else if(arr[(x_left + x_right)/2] < search) x_left = (x_left + x_right)/2;
        else return true;
    }
    return false;
}

int sort::upperlim(int arr[], int search, int end, int begin /*= 0*/)
{
    if(end <= begin || arr[end - 1] <= search) return end;
    if(arr[begin] > search) return begin;
    int x_left = begin, x_right = end - 1; // arr[x_left] <= search, arr[x_right] > search
    while(x_right - x_left > 1)
    {
        if(arr[(x_left + x_right)/2] <= search) x_left = (x_left + x_right)/2;
        else x_right = (x_left + x_right)/2;
    }
    return x_right;
}

int sort::lowerlim(int arr[], int search, int end, int begin /*= 0*/)
{
    if(end <= begin || arr[end - 1] < search) return end;
    if(arr[begin] >= search) return begin;
    int x_left = begin, x_right = end - 1; // arr[x_left] < search, arr[x_right] >= search
    while(x_right - x_left > 1)
    {
        if(arr[(x_left + x_right)/2] < search) x_left = (x_left + x_right)/2;
        else x_right = (x_left + x_right)/2;
    }
    return x_right;
}

bool sort::linearsearch(int arr[], int search, int end, int begin /*= 0*/)
{
    for(int i = begin; i < end; ++i) if(arr[i] == search) return true;
    return false;
}
