//Viết chương trình yêu cầu nhập giá trị cho số nguyên x nhỏ hơn 100. 
//In ra giá trị ax^2+bx+c  với a, b, c định sẵn.
//NguyenThuyLinh_20225031
#include<stdio.h>
int get_value( int x, int a = 2, int b = 1, int c = 0){
    return a*x*x + b*x + c;
}
int main(){
    // nhập các số theo yêu cầu
    int x, a = 2, b = 1, c = 0; scanf("%d %d %d %d", &x, &a, &b, &c);
    printf("a=2, b=1, c=0: %d\n", get_value(x));
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a));
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));
    return 0;
}
//NguyenThuyLinh_20225031
