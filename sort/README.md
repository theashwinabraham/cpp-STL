# Sorting Algorithms

This file compiles some common sorting algorithms along with a few that search sorted arrays.

## Usage Instructions

To build the Shared Library, enter:

    make Lib

and to install it, enter:

    sudo make install

Include ```sort.hpp``` in your code (```#include <sort.hpp>```).

The compiler options to be used while compiling your code with this library are ```-lsort``` and ```-lpthread```.
If you have only built the library and not installed it, you must also add ```-I</path/to/dir/of/header> -L</path/to/dir/of/lib> -Wl,</path/to/lib>```

## Performance Analysis

### STL Algorithms

| Algorithm/Size                 | 1            |        10   |         100 |       1,000 |        10,000 |      100,000 |       1,000,000 |        10,000,000 |      100,000,000 |     1,000,000,000  |
|--------------------------------|--------------|-------------|-------------|-------------|---------------|--------------|-----------------|-------------------|------------------|--------------------|
| ```std::find```                |$0.05 \mu s$  |$0.061 \mu s$| $0.08 \mu s$| $0.09 \mu s$| $0.089 \mu s$ |$0.095 \mu s$ |$0.12 \mu s$     |  $0.11 \mu s$     | $0.128 \mu s$    | $0.102 \mu s$      |
| ```std::binary_search```       | $0.065 \mu s$|$0.112 \mu s$|$0.111 \mu s$|$0.098 \mu s$|$0.102 \mu s$  |$0.124 \mu s$ |$0.236 \mu s$    | $0.983 \mu s$     | $1.64 \mu s$     | $2.49 \mu s$       |
| ```std::upper_bound```         | $0.069 \mu s$|$0.087 \mu s$|$0.117 \mu s$|$0.14 \mu s$ | $0.135 \mu s$ |$0.196 \mu s$ |$0.289 \mu s$    | $1.71 \mu s$      | $2.41 \mu s$     | $2.74 \mu s$       |
| ```std::lower_bound```         |$0.071 \mu s$ |$0.09 \mu s$ |$0.127 \mu s$|$0.132 \mu s$|$0.138 \mu s$  |$0.143 \mu s$ |$0.327 \mu s$    | $1.41 \mu s$      | $1.92 \mu s$     | $3.00 \mu s$       |
| ```std::sort```                |$0.101 \mu s$ |$1.12 \mu s$ |$2.72 \mu s$ |$32.27 \mu s$|$388.53 \mu s$ |$3.64 ms$     |$39.3 ms$        |$408.28 ms$        |$4.13 s$          | $45.87 s$          |

### Library Algorithms

| Algorithm/Size                 | 1            |        10   |         100 |       1,000 |        10,000 |      100,000 |       1,000,000 |        10,000,000 |      100,000,000 |     1,000,000,000  |
|--------------------------------|--------------|-------------|-------------|-------------|---------------|--------------|-----------------|-------------------|------------------|--------------------|
| ```sort::linearsearch```       | $0.434 \mu s$|$0.558 \mu s$|$0.537 \mu s$| $0.75 \mu s$| $5.45 \mu s$  |$25.36 \mu s$ |$460.5 \mu s$    |  $3.71 ms$        | $35.85 ms$       | $375.66 ms$        |
| ```sort::binarysearch```       |$0.537 \mu s$ |$0.712 \mu s$|$0.561 \mu s$|$0.647 \mu s$| $0.66 \mu s$  |$0.727 \mu s$ |$1.05 \mu s$     | $1.46 \mu s$      | $1.48 \mu s$     | $1.75 \mu s$       |
| ```sort::upperlim```           | $0.559 \mu s$|$0.592 \mu s$|$0.566 \mu s$|$0.654 \mu s$|$0.645 \mu s$  |$0.831 \mu s$ |$1.45 \mu s$     | $3.56 \mu s$      | $5.27 \mu s$     | $10.92 \mu s$      |
| ```sort::lowerlim```           |$0.434 \mu s$ |$0.516 \mu s$|$0.55 \mu s$ |$0.528 \mu s$|$0.683 \mu s$  |$0.942 \mu s$ |$1.228 \mu s$    |$3.23 \mu s$       | $5.34 \mu s$     | $7.45 \mu s$       |
| ```sort::quicksort```          |$0.35 \mu s$  |$0.814 \mu s$|$4.57 \mu s$ |$63.77 \mu s$|$543.94 \mu s$ |$6.16 ms$     |$148.58 ms$      |$10.22 s$          |$17 m 57.25s$     | $ > 1hr$           |
| ```sort::mergesort```          |$0.39 \mu s$  |$2.86 \mu s$ |$7.55 \mu s$ |$63.45 \mu s$|$741.02 \mu s$ |$7.17 ms$     |$85.96 ms$       |$831.93 ms$        |$9.79 s$          |$2m 8.5s$           |
| ```sort::heapsort```           |$0.552 \mu s$ |$1.1 \mu s$  |$5.27 \mu s$ |$64.23 \mu s$|$840.4 \mu s$  |$9.59 ms$     |$135.9 ms$       |$2.1 s$            |$27.3 s$          |$4m 52.17s$         |
| ```sort::countingsort```       |$0.791 \mu s$ |$1.24 ms$    |$1.79 ms$    |$1.586 ms$   |$1.83 ms$      |$3.42 ms$     |$17.70 ms$       |$44.78 ms$         |$322.13 ms$       |$3.33 s$            |
| ```sort::fast_insertionsort``` |$0.771 \mu s$ |$1.87 \mu s$ |$4.64 \mu s$ |$61.48 \mu s$|$1.72 ms$      |$190.53 ms$   |$26.86 s$        |                   |                  |                    |
| ```sort::insertionsort```      |$0.728 \mu s$ |$2.48 \mu s$ |$5.44 \mu s$ |$228.8 \mu s$|$14.49 ms$     |$1.54 s$      |$3m 33.56s$      |                   |                  |                    |
| ```sort::selectionsort```      |$0.843 \mu s$ |$1.13 \mu s$ |$7.48 \mu s$ |$419.5 \mu s$|$38.62 ms$     |$4.12 s$      |                 |                   |                  |                    |
| ```sort::bubblesort```         |$0.745 \mu s$ |$1.2 \mu s$  |$16.4 \mu s$ |$900.2 \mu s$|$84.86 ms$     |$19.68 s$     |                 |                   |                  |                    |
| ```sort::threadsort```         |$0.57 \mu s$  |$234.2 \mu s$|$245.6 \mu s$|$352.4 \mu s$|$670.47 \mu s$ |$4.57 ms$     |$55.61 ms$       |$610.74 ms$        |$6.26 s$          |$86.54 s$           |
| ```sort::thread_quicksort```   |$1.03 \mu s$  |$237.2 \mu s$|$235.2 \mu s$|$280.6 \mu s$|$739.6 \mu s$  |$8.62 ms$     |$78.23 ms$       |$845.26 ms$        |$12.73 s$         |$5m 50.63s$         |
| ```sort::sleepsort```          |$0.55 \mu s$  |$2m 43s$     |$2m 54s$     |$3m$         |$3m 0.4s$      |Out of Memory |Out of Memory    |Out of Memory      |Out of Memory     |Out of Memory       |
