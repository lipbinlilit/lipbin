#include "sort_operations.hpp"

void sort_operations::selection_sort(std::vector<int>& array) {
    int n = array.size();
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int current = array[i];
        while (j >= 0 && array[j] > current) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = current;
    }
}