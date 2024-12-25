//Nguyễn Thùy Linh_20225031
//Viết chương trình in ra tất cả các dãy con của một dãy cho trước
#include<stdio.h>
int main(){
    int n;
    printf("Nhap so phan tu cua day: \n");
    scanf("%d", &n);
    //khoi tao mang dong
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Nhap cac phan tu cua day: \n");
    for(int i = 0; i < n; i++) scanf("%d", arr+i);
    printf("ket qua la: \n");
    for(int i = 0; i < n; i++){
        int d = 0;
        while (d < (n-i)){
            for (int j = 0; j <= d; j++) printf("%d ", arr[i+j]);
            printf("\n");
            d++;
        }
    }
    //giai phong bo nho
    free(arr);
    return 0;
}