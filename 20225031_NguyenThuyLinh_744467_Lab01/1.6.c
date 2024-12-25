//Nguyễn Thùy Linh_20225031
//Viết hàm đảo ngược một mảng các số nguyên theo hai cách: dùng chỉ số và dùng con trỏ.
#include <iostream>
void reversearray(int arr[],int size){
    int l = 0, r= size - 1, tmp;
    while ( l < r)
    {
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++; r--;
    }
}
void ptr_reversearray(int *arr,int size){
    int l = 0, r= size - 1, tmp;
    while ( l < r)
    {
        tmp = *(arr + l);
        *(arr + l) = *(arr + r);
        *(arr + r) = tmp;
        l++; r--;
    }
}