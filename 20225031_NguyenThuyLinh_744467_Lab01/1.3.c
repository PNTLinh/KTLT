//Nguyễn Thùy Linh_20225031
// Viết chương trình yêu cầu nhập giá trị cho 3 biến số nguyên x, y, z kiểu int. 
//Sau đó sử dụng duy nhất một con trỏ để cộng giá trị của mỗi biến thêm 100
#include<stdio.h>
int main(){
    int x, y, z, *p;
    scanf("%d %d %d", &x, &y, &z);// nhập 3 số vào
    printf("Here are the values of x, y, and z:\n");
    printf("%d %d %d\n", x, y, z);
    //gán con trỏ cho từng biến và cộng biến với 100
    p=&x;*p+=100;
    p=&y;*p+=100;
    p=&z;*p+=100;
    printf("Once again, here are the values of x, y, and z:\n");// in ra kết quả
    printf("%d %d %d\n", x, y, z);
    return 0;
}