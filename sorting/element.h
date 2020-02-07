#pragma once

#include <ostream>
#include <vector>
#include <iostream>

class element {
public:
    element(int x):data(x){}
    element& operator= (const element& rhs) {
        this->data = rhs.data;
        ++count;
        return *this;
    }
    static void reset() {
        count = 0;
    }
    static int get_count() {
        return count;
    }
    int get_data() const {
        return data;
    }
private:
    static int count;
    int data;
};

std::ostream& operator << (std::ostream& out, const element& item);
bool operator < (const element& lhs, const element& rhs);
bool operator > (const element& lhs, const element& rhs);
bool operator == (const element& lhs, const element& rhs);
void print(std::vector<element>& arr);
void set_array(std::vector<element>& arr);
void reverse_array(std::vector<element>& arr, int max_items);
void random_array(std::vector<element>& arr, int max_items);
