#pragma once
#include <iostream>


template <typename T>
void merge_sort(std::vector<T>& arr,
               size_t start,
               size_t end) //end is exclusive
{
    int size = end - start;

    if (size <= 1) {
        return; // sorted array for single element
    }

    size /= 2;
    size_t e1 = start+size;

    merge_sort(arr, start, e1);
    merge_sort(arr, e1, end);

    // merge the two sorted arrays
    merge(arr, start, e1, e1, end);

    return;
}

template <typename T>
void merge(std::vector<T>& arr,
           size_t start1,
           size_t end1,
           size_t start2,
           size_t end2
           ) // end is exclusive
{
    std::vector<T> arr1(&arr[start1], &arr[end1]);
    std::vector<T> arr2(&arr[start2], &arr[end2]);

    size_t i = 0, j = 0, k = start1;

    // copy the elements to original array in order
    while(start1 < end1 && start2 < end2) {
        if (arr1[i] < arr2[j]) {
            arr[k++] = arr1[i++];
            start1++;
        }
        else {
            arr[k++] = arr2[j++];
            start2++;
        }
    }

    // copy the rest of left section
    while (start1 < end1) {
        arr[k++] = arr1[i++];
        start1++;
    }
    // copy the rest of right section
    while (start2 < end2) {
        arr[k++] = arr2[j++];
        start2++;
    }

    return;
}
