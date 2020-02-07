#include "bubble_sort.h"
#include "selection_sort.h"
#include "merge_sort.h"
#include "element.h"

int main()
{
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

    return 0;
}
