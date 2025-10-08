#include <iostream>
#include <vector>
#include <string> 

using namespace std;

int main(){
    cout << "введите длину массива"<<endl;
    int n;
    cin >> n;
    cout << "введите " << n << " чисел массива"<<endl;
    vector<int> a(n);
    for (int i = 0;i < n;++i) {
        cin >> a[i];
    }
    for (int i = 0;i < n - 1;++i) {
        for (int j = i + 1;j < n;++j) {
            if (a[i] > a[j]) {
                swap(a[i], a[j]);
            }
        }
    }
    cout << "отсортированный массив:" << endl;
    for (int i = 0;i < n;++i) {
        cout << a[i] << " ";
    }
}

