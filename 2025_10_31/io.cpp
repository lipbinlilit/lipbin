#include "io.hpp"
#include <iostream>

int io::input_length() {
    std::cout << "Enter array length:" << std::endl;
    int n;
    std::cin >> n;
    return n;
}

int* io::input_array(int n) {
    std::cout << "Enter " << n << " array elements" << std::endl;
    int* array = new int[n];
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    return array;
}

void io::print_array(const char* mes, const int* array, int n) {
    std::cout << mes << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}