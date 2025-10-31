#ifndef IO_HPP
#define IO_HPP

#include <vector>
#include <string>

namespace io {
    int input_length();
    std::vector<int> input_array(int n);
    void print_array(const std::string& mes, const std::vector<int>& array);
}

#endif