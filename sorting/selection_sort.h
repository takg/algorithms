#pragma once

#include <vector>
#include <iterator>

template <typename T>
void selection_sort(std::vector<T>& arr) {
    for (size_t n = 0; n < arr.size()-1 ; ++n) { // N-1
        size_t index = 0;
        T temp = arr[index];
        size_t loop1 = 1;

        for (; loop1 < arr.size() - n; ++loop1) {
            if (temp < arr[loop1]) {
                temp = arr[loop1];
                index = loop1;
            }
        }

        if (temp > arr[arr.size()-n-1]) {
            std::swap(arr[index], arr[arr.size()-n-1]);
        }
    } // end of for

    return;
}
