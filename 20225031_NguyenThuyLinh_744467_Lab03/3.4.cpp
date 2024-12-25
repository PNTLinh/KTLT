#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải
void init() {
    memset(mem, -1, sizeof(mem));
}
int lis(int i) {
    //NguyenThuyLinh_20225031
    if (mem[i] > 0) return mem[i]; // Nếu đã tính toán trước đó, trả về luôn
    mem[i] = 1; // LIS tại vị trí i ít nhất là 1 (chỉ gồm chính nó)
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i] && mem[i] < lis(j) + 1) { // xet xem có mo rong them duoc khong
            mem[i] = lis(j) + 1;
        }
    }
    return mem[i];
}
//# Truy vet loi giai
void trace(int i) {
    for (int j = 0; j < i; j++) {
        if (a[j] < a[i] && mem[i] == 1 + mem[j]) {
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}
int main() {
    init();
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    for (int i = 0; i < n; i++) {
        if (res < lis(i)) {
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
//NguyenThuyLinh_20225031
