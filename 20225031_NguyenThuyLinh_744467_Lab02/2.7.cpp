//NguyenThuyLinh_20225031
#include <iostream>
using namespace std;
template <typename T>
// Viết func tính tổng với temp
T arr_sum( T* m1, int n1, T* m2, int n2){
    T sum = 0;
    for (int i = 0; i < n1; i++) sum += m1[i];
    for (int j = 0; j < n2; j++) sum += m2[j];
    return sum;
}
int main() {
    int val;cin >> val;
    {int a[] = {3, 2, 0, val};
    int b[] = {5, 6, 1, 2, 7};
    cout << arr_sum(a, 4, b, 5) << endl;}
    {double a[] = {3.0, 2, 0, val * 1.0};
    double b[] = {5, 6.1, 1, 2.3, 7};
    cout << arr_sum(a, 4, b, 5) << endl;}
    return 0;
}
//NguyenThuyLinh_20225031
