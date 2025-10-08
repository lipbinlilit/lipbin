#include "io.hpp"
#include <iostream>
#include <string>

int io::input_length() {
    std::cout << "enter array lenght:" << std::endl;
    int n;
    std::cin >> n;
    return n;
}

std::vector<int> io::input_array(int n) {
    std::cout << "enter " << n << " array elements" << std::endl;
    std::vector<int> array(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> array[i];
    }
    return array;
}

void io::print_array(const std::string& mes, const std::vector<int>& array) {
    std::cout << mes << std::endl;
    for (size_t i = 0; i < array.size(); ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}