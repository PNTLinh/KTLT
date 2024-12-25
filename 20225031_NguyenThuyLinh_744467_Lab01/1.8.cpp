//Nguyễn Thùy Linh_20225031
//Viết chương trình nhập vào một ma trận 2 chiều kích thước m*n với m và n nhập từ bàn phím. 
//Sau đó đưa ra tổng các phần tử chẵn của ma trận đó.
#include<stdio.h>
//khởi tạo mảng động 2 chiều
void allocate_mem( int ***mt, int m, int n){
    *mt=new int *[m];
    for(int i = 0; i < m; i++){
        (*mt)[i] = new int[n];
    }
}
//hàm nhập ma trận
void input( int **mt, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("mt[%d][%d] = ",i,j);
            scanf("%d", mt[i]+j);
        } 
    }
}
//hàm in ra kết quả
void output(int **mt, int m, int n){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            printf("%d ", *(mt[i]+j));
        } 
        printf("\n");
    }
}
int process(int **mt, int m, int n){
    int sum=0;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if((*(mt[i]+j)) %2==0) sum+=(*(mt[i]+j));// tìm các phần tử chẵn để tính tổng
        }
    }
    return sum;
}
// xóa bộ nhớ sau cấp phát
void free_mem (int **mt, int m, int n){
    for(int i=0; i<m; i++) delete [] mt[i];
    delete [] mt;
}
int main(){
    int m, n, **mt;
    printf("Enter m, n = ");
    scanf("%d %d", &m, &n);
    allocate_mem(&mt, m, n);
    input(mt, m, n);
    output(mt, m, n);
    printf("The sum of all even elements is %d", process(mt, m, n));
    free_mem(mt, m, n);
    return 0;
}