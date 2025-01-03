#include <iostream>
using namespace std;
int n, M, m[100], v[100];
int x[100], best, sumV, sumM, all[100];
void init(){
    for (int i = n; i >= 1; --i){
        all[i] = all[i+1] + v[i];// goi sai tên hàm
    }
}
void print() {
    cout << best;
}
void process(int i){
    if (sumV + all[i] <= best || sumM > M) return ;// trả về giá trị không đúng
    if (i > n){
        best = sumV;
        return ;// trả về giá trị không đúng
    }
    process(i+1);
    sumM += m[i];
    sumV += v[i];
    process(i+1);
    sumM -= m[i];
    sumV -= v[i];
}
int main() {
    cin >> n >> M;
    for (int i = 1; i <= n; ++i)
        cin >> m[i] >> v[i];
    init();
    process(1);
    print();
    return 0;
}
//NguyenThuyLinh_20225031
