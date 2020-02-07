#include "element.h"

int element::count = 0;

std::ostream& operator << (std::ostream& out, const element& item) {
    out << item.get_data();
    return out;
}

bool operator < (const element& lhs, const element& rhs) {
    return lhs.get_data() < rhs.get_data();
}

bool operator > (const element& lhs, const element& rhs) {
    return lhs.get_data() > rhs.get_data();
}

bool operator == (const element& lhs, const element& rhs) {
    return lhs.get_data() == rhs.get_data();
}

void print(std::vector<element>& arr){
    for (auto item: arr) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void set_array(std::vector<element>& arr) {
    arr = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    element::reset();
}

void reverse_array(std::vector<element>& arr, int max_items) {
    arr.reserve(max_items);
    arr.clear();

    for (int loop = max_items; loop != 0; --loop) {
        arr.push_back(loop);
    }
    element::reset();
    return;
}

void random_array(std::vector<element>& arr, int max_items) {
    arr.reserve(max_items);
    const int SEED = 10000;
    std::srand(SEED);

    for (int i = 0 ; i < max_items; ++i) {
        arr[i] = std::rand();
    }

    element::reset();
    return;
}
