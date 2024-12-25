//Viết hàm hoán vị vòng tròn 3 biến a, b, c. 
//Sau khi thực hiện hàm, các biến a, b, c tương ứng nhận các giá trị mới b, c, a.
//NguyenThuyLinh_20225031
#include<stdio.h>
//viết hàm đảo 3 biến đã cho
void rotate(int &a, int &b, int &c){
    int temp = a;
    a = b;
    b = c;
    c = temp;
}
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    printf("Before: %d, %d, %d\n", a, b, c);// in ra 3 biến lúc đầu
    rotate( a, b, c);
    printf("After: %d, %d, %d", a, b, c);// in ra 3 biến lúc sau
    return 0;
}
//NguyenThuyLinh_20225031
