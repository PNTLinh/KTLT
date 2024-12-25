//Viết các hàm tính lập phương của số nguyên và số thực.
//NguyenThuyLinh_20225031
#include<iostream>
// hàm với số nguyên
int cube(int a){
    return a*a*a;
}
// hàm với số thực
double cube(double a){
    return a*a*a;
}
int main(){
    int a; double b;
    scanf("%d %lf", &a, &b);
    printf("Int: %d\n", cube(a) );
    printf("Double: %.2lf", cube(b));
    return 0;
}
//NguyenThuyLinh_20225031
