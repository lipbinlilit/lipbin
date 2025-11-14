#include "io.hpp"
#include "pve.hpp"

int main() {
    int n = io::input_length();
    int* array = io::input_array(n);
    pve::selection_sort(array, n);
    io::print_array("Sorted array:", array, n);
    return 0;
}