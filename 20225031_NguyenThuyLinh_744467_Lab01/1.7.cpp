//Nguyễn Thùy Linh_20225031
//Viết chương trình nhập vào một mảng các số nguyên với số lượng các phần tử nhập từ bàn phím. 
//Sau đó sắp xếp mảng theo thứ tự tăng dần. 
//Hiển thị danh sách mảng trước và sau khi sắp xếp.
//Yêu cầu chỉ sử dụng con trỏ để truy cập mảng, không truy cập theo index mảng.
#include <stdio.h>
#include <stdlib.h>
// đổi giá trị 2 biến cho nhau
void swap( int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
int *a;
int n;
int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    a= new int[n];
    for (int i = 0; i < n; i++) 
        scanf("%d", a + i);
    printf("The input array is: \n");
    for (int i = 0; i < n; i++) 
        printf("%d ", *(a + i));
    printf("\n");
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
            if (*(a + i) > *(a + j)) swap((a + i),(a + j));// sắp xếp mảng theo thứ tự tăng dần
        }
    }
    printf("The sorted array is: \n");
    for (int i = 0; i < n; i++) 
        printf("%d ", *(a + i));// in mảng sau khi sắp xếp
    delete [] a;
    return 0;
}