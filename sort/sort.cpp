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

void sort::bubblesort(int arr[], long long int end, long long int begin /*= 0*/)
{
    for(long long int right = end; right > begin + 1; --right)
    {
        bool sorted = true;
        for (long long int i = begin; i < right - 1; ++i)
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

void sort::selectionsort(int arr[], long long int end, long long int begin /*= 0*/)
{
    for(long long int right = end; right > begin + 1; --right)
    {
        long long int maxind = begin;
        for (long long int i = 1 + begin; i < right; ++i)
        {
            if (arr[i] > arr[maxind])
            {
                maxind = i;
            }
        }
        swap(arr[maxind], arr[right - 1]);
    }
}

void sort::insertionsort(int arr[], long long int end, long long int begin /*= 0*/)
{
    for (long long int i = begin; i < end; ++i)
    {
        long long int j = begin;
        for (; j < i; ++j)
        {
            if (arr[j] > arr[i])
                break;
        }
        int temp = arr[i];
        for (long long int k = i; k > j; --k)
            arr[k] = arr[k - 1];
        arr[j] = temp;
    }
}

void sort::fast_insertionsort(int arr[], long long int end, long long int begin /*= 0*/)
{
    for(long long int i = begin; i < end - 1; ++i)
    {
        int val = arr[i + 1];
        long long int pos = sort::upperlim(arr, val, i + 1);
        for(long long int j = i; j >= pos; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[pos] = val;
    }
}

void sort::countingsort(int arr[], long long int end, long long int begin /*= 0*/)
{
    if (end - begin <= 1) return;
    int min = arr[begin], max = arr[begin];
    for (long long int i = 1 + begin; i < end; ++i)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int *book = new int[max - min + 1]();
    for (long long int i = begin; i < end; ++i) ++book[arr[i] - min];

    long long int pos = 0;
    for(int val = min; val <= max; ++val)
    {
        for(int j = 0; j < book[val - min]; ++j) arr[pos + j] = val;
        pos += book[val - min];
    }

    delete [] book;
}

void sort::mergesort(int arr[], long long int end, long long int begin /*= 0*/)
{
    if ((end - begin) <= 1)
        return;
    sort::mergesort(arr, (begin + end) / 2, begin);
    sort::mergesort(arr, end, (begin + end) / 2);
    long long int kl = begin, kr = (begin + end) / 2;
    int *sortedarr = new int[end - begin]();
    for (long long int i = 0; i < (end - begin); ++i)
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
    for (long long int i = begin; i < end; ++i)
        arr[i] = sortedarr[i - begin];
    delete [] sortedarr;
}

void sort::heapsort(int arr[], long long int end, long long int begin /*= 0*/)
{
    if(end - begin <= 1) return;
    for(long long int i = end - begin - 1; i >= 0; --i)
    {
        for(long long int heap_violator = i; ;)
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
    for(long long int i = end - begin - 1; i >= 0; --i)
    {
        swap(arr[begin], arr[begin + i]);
        for(long long int heap_violator = 0; ; )
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

void sort::quicksort(int arr[], long long int end, long long int begin /*= 0*/)
{
    if ((end - begin) <= 1)
        return;
    long long int pivot = begin + rand() % (end - begin), num_less = 0;
    for (long long int i = begin; i < end; ++i)
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

void sort::sleepsort(int arr[], long long int end, long long int begin /*= 0*/)
{
    if(end - begin <= 1) return;
    std::mutex locker;
    auto sleeper_func = [&locker](int val, long long int *num_sorted, int min, int *ptr){ sleep(val - min + 1); locker.lock(); ptr[*num_sorted] = val; ++(*num_sorted); locker.unlock(); };
    int min = arr[begin];
    for(long long int i = begin + 1; i < end; ++i)
    {
        if(arr[i] < min) min = arr[i];
    }

    long long int num_sorted = begin;
    std::thread *threads = new std::thread[end - begin - 1];
    for(long long int i = begin; i < end - 1; ++i)
    {
        threads[i - begin] = std::thread(sleeper_func, arr[i], &num_sorted, min, arr);
    }
    sleeper_func(arr[end - 1], &num_sorted, min, arr);
    for(int i = begin; i < end - 1; ++i) threads[i - begin].join();
    delete [] threads;
}

void sort::threadsort(int arr[], long long int end, long long int begin /*= 0*/)
{
    static constexpr long long unsigned int max_threads = 8ul;
    static long long unsigned int num_threads = 1ul;
    static std::mutex locker;

    if (end - begin <= 1) return;
    if(num_threads < max_threads)
    {
        locker.lock();
        ++num_threads;
        locker.unlock();
        std::thread t(sort::threadsort, arr, (begin + end) / 2, begin);
        sort::threadsort(arr, end, (begin + end) / 2);
        t.join();
        locker.lock();
        --num_threads;
        locker.unlock();
    }
    else
    {
        sort::threadsort(arr, (begin + end)/2, begin);
        sort::threadsort(arr, end, (begin + end)/2);
    }
    long long int kl = begin, kr = (begin + end) / 2;
    int *sortedarr = new int[end - begin]();
    for (long long int i = 0; i < (end - begin); ++i)
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
    for (long long int i = begin; i < end; ++i) arr[i] = sortedarr[i - begin];
    delete [] sortedarr;
}

void sort::thread_quicksort(int arr[], long long int end, long long int begin /*= 0*/)
{
    static constexpr long long unsigned int max_threads = 8;
    static long long unsigned int num_threads = 1;
    static std::mutex locker;

    if(end - begin <= 1) return;
    int pivot = begin + rand() % (end - begin), num_less = 0;
    for (long long int i = begin; i < end; ++i)
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
    if(num_threads < max_threads)
    {
        locker.lock();
        ++num_threads;
        locker.unlock();
        std::thread t(sort::thread_quicksort, arr, begin + num_less, begin);
        sort::thread_quicksort(arr, end, begin + num_less + 1);
        t.join();
        locker.lock();
        --num_threads;
        locker.unlock();
    }
    else 
    {
        sort::thread_quicksort(arr, begin + num_less, begin);
        sort::thread_quicksort(arr, end, begin + num_less + 1);
    }
}

bool sort::binarysearch(int arr[], int search, long long int end, long long int begin /*= 0*/)
{
    if (end <= begin || arr[begin] > search || arr[end - 1] < search) return false;
    if(arr[begin] == search || arr[end - 1] == search) return true;
    long long int x_left = begin, x_right = end - 1;
    while(x_right - x_left > 1)
    {
        if(arr[(x_left + x_right)/2] > search) x_right = (x_left + x_right)/2;
        else if(arr[(x_left + x_right)/2] < search) x_left = (x_left + x_right)/2;
        else return true;
    }
    return false;
}

int sort::upperlim(int arr[], int search, long long int end, long long int begin /*= 0*/)
{
    if(end <= begin || arr[end - 1] <= search) return end;
    if(arr[begin] > search) return begin;
    long long int x_left = begin, x_right = end - 1; // arr[x_left] <= search, arr[x_right] > search
    while(x_right - x_left > 1)
    {
        if(arr[(x_left + x_right)/2] <= search) x_left = (x_left + x_right)/2;
        else x_right = (x_left + x_right)/2;
    }
    return x_right;
}

int sort::lowerlim(int arr[], int search, long long int end, long long int begin /*= 0*/)
{
    if(end <= begin || arr[end - 1] < search) return end;
    if(arr[begin] >= search) return begin;
    long long int x_left = begin, x_right = end - 1; // arr[x_left] < search, arr[x_right] >= search
    while(x_right - x_left > 1)
    {
        if(arr[(x_left + x_right)/2] < search) x_left = (x_left + x_right)/2;
        else x_right = (x_left + x_right)/2;
    }
    return x_right;
}

bool sort::linearsearch(int arr[], int search, long long int end, long long int begin /*= 0*/)
{
    for(long long int i = begin; i < end; ++i) if(arr[i] == search) return true;
    return false;
}

bool sort::threadsearch(int arr[], int search, long long int end, long long int begin /*= 0*/)
{
    static bool found = false;
    static constexpr long long unsigned int max_threads = 8;
    static long long unsigned int num_threads = 1;
    static std::mutex thread_locker;
    static std::mutex return_locker;
    if(num_threads == 1) found = false; // no need for mutex here
    if(found) return true;
    if(end <= begin) return false;
    if(num_threads < max_threads)
    {
        thread_locker.lock();
        ++num_threads;
        thread_locker.unlock();
        std::thread t(sort::threadsearch, arr, search, (begin + end)/2, begin);
        sort::threadsearch(arr, search, end, (begin + end)/2);
        t.join();
        thread_locker.lock();
        --num_threads;
        thread_locker.unlock();
        return found;
    }
    else
    {
        for(long long int i = begin; !found && i < end; ++i)
        {
            if(arr[i] == search)
            {
                return_locker.lock();
                found = true;
                return_locker.unlock();
                return found;
            }
        }
        return found;
    }
}