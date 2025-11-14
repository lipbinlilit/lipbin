#include "pve.hpp"

void pve::selection_sort(int* array, int n) {
    for (int i = 1; i < n; ++i) {
        int j = i - 1;
        int current = array[i];
        while (j >= 0 && array[j] > current) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = current;
    }
}