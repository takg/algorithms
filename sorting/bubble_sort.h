#pragma once

#include <vector>
#include <iterator>

template <typename T>
int bubble_sort(std::vector<T>& arr) {
    int swaps = 0;
    for (size_t loop1 = 0; loop1 < arr.size()-1 ; ++loop1) { // N-1
        bool flag = true;

        for (size_t loop2 = 0; loop2 < arr.size() - loop1 - 1 ; ++loop2) {
            if (arr[loop2] > arr[loop2+1]) {
                std::swap(arr[loop2], arr[loop2+1]);
                ++swaps;
                flag = false;
            }
        }

        if (flag) {
            break;
        }
    }

    return swaps;
}
