#include "io.hpp"
#include "sort_operations.hpp"
#include <vector>

int main() {
    int n = io::input_length();
    std::vector<int> array = io::input_array(n);
    sort_operations::selection_sort(array);
    io::print_array("sorted array:", array);
    return 0;
}