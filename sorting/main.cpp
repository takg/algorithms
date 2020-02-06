#include <iostream>
#include "bubble_sort.h"
#include "selection_sort.h"

using namespace std;

void print(std::vector<int>& arr){
    for (auto item: arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void set_array(std::vector<int>& arr) {
    arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
}

void reverse_array(std::vector<int>& arr, int max_items) {
    arr.reserve(max_items);
    arr.clear();
    for (int loop = max_items; loop != 0; --loop) {
        arr.push_back(loop);
    }
    return;
}

void random_array(std::vector<int>& arr, int max_items) {
    arr.reserve(max_items);
    const int SEED = 10000;
    std::srand(SEED);

    for (int i = 0 ; i < max_items; ++i) {
        arr[i] = std::rand();
    }

    return;
}

int main()
{
    std::vector<int> arr;
    //set_array(arr);
    reverse_array(arr, 10);

    std::cout << "Original array" << std::endl;
    print(arr);
    std::cout << "Bubble sort :: Sorted array with " << bubble_sort(arr) << " swaps" << std::endl;
    print(arr);
    std::cout << "Original array" << std::endl;
    reverse_array(arr, 10);
    print(arr);
    std::cout << "Selection sort :: Sorted array with " << selection_sort(arr) << " swaps" << std::endl;
    print(arr);

    return 0;
}
