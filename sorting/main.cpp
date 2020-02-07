#include "bubble_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "element.h"
#include "partition.h"

void print(std::vector<int>& arr){
    for (auto item: arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

int main()
{
    /*
    std::vector<element> arr;
    reverse_array(arr, 10);
    std::cout << "Original array" << std::endl;
    print(arr);
    bubble_sort(arr);
    std::cout << "Bubble sort :: Sorted array with " << element::get_count() << " swaps" << std::endl;
    print(arr);

    std::cout << "Original array" << std::endl;
    reverse_array(arr, 10);
    print(arr);
    selection_sort(arr);
    std::cout << "Selection sort :: Sorted array with " << element::get_count() << " swaps" << std::endl;
    print(arr);

    std::cout << "Original array" << std::endl;
    reverse_array(arr, 10);
    print(arr);
    merge_sort(arr, 0, 10);
    std::cout << "Merge sort :: Sorted array with " << element::get_count() << " swaps" << std::endl;
    print(arr);
    */

    std::vector<int> array = {1 , -1, 2, -2, 3, -3, 4, -4, 5, -5};
    print(array);
    partition(array.begin(), array.end(), [](int x) {return x<0;});
    print(array);

    return 0;
}
