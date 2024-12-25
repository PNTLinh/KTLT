#include <stdio.h>
//NguyenThuyLinh_20225031
void print(int n) {
    printf("n=%d\n", n);// hàm in ra kết quả
}
int mul3plus1(int n) {
    return n * 3 + 1;
}
int div2(int n) {
    return n / 2;
}
// Viết hàm kiểm tra giả thuyết 
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int)) {
    (*output)(n);
    if (n == 1) return;
    if (n % 2 == 0) {
        n = (*even)(n);
    } else {
        n = (*odd)(n);
    }
    simulate(n, odd, even, output);
}
int main() {
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;
    even = div2;
    odd = mul3plus1;
    int n; scanf("%d", &n);
    simulate(n, odd, even, print);
    return 0;
}
//NguyenThuyLinh_20225031
