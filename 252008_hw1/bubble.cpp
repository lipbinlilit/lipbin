#include <iostream>
#include <vector>
#include <string> 

int main(){
    std::cout << "введите длину массива"<<std::endl;
    std::int16_t n;
    std::cin >> n;
    std::cout << "введите " << n << " чисел массива"<<std::endl;
    std::vector<int> a(n);
    for (int i = 0;i < n;++i) {
        std::cin >> a[i];
    }
    for (int i = 0;i < n - 1;++i) {
        for (int j = i + 1;j < n;++j) {
            if (a[i] > a[j]) {
                std::swap(a[i], a[j]);
            }
        }
    }
    std::cout << "отсортированный массив:" << std::endl;
    for (int i = 0;i < n;++i) {
        std::cout << a[i] << " ";
    }
}

