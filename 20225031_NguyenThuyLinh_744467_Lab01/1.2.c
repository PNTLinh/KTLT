//Nguyễn Thùy Linh_20225031
// Viết chương trình in ra địa chỉ của 5 phần tử đầu tiên 
//trong mảng được định nghĩa sau đây: int a[7]= {13, -355, 235, 47, 67, 943, 1222}
#include<stdio.h>
int main(){
    int a[7]={13, -355, 235, 47, 67, 943, 1222};// khai báo mảng với các phần tử đã cho
    printf("address of first five elements in memory. \n");
    for (int i=0; i<5; i++) printf("\ta[%d]: %p\n", i, (a+i) );// lấy ra địa chỉ của từng phần tử
    printf("\n");
    return 0;
}