//NguyenThuyLinh_20225031
//Viết chương trình nhập vào 2 ma trận vuông cùng kích thước n*n, trong đó n nhập từ bàn phím. 
//Sau đó tính tổng và tích của hai ma trận đó và đưa kết quả ra màn hình.
#include<iostream>
#include<cstdlib>
class matran{
    public:int n,** mt;
    //khoi tao
    matran( int size ){
        n= size;
        mt = new int*[n];
        for (int i = 0; i < n ; ++i){
            mt[i] = new int[n];
        }
    }
    //nhap ma tran
    void nhap(){
        for (int i = 0; i < n ; i++){
            for (int j = 0; j < n ; j++){
                scanf("%d", mt[i]+j );
            }
        }
    }
    //giai phong bo nho
    ~matran(){
        for (int i = 0; i < n ; i++) {free( mt[i] );}
        free( mt );
    }
    //hien thi
    void hien_thi(){
        for (int i = 0; i < n ; i++){
            for (int j = 0; j < n ; j++){
                printf("%d ", mt[i][j]);
        }
            printf("\n");
        }
    }
};
// tinh tong 2 ma tran
matran tong(const matran& a, const matran& b){
    matran c(a.n);
    for (int i = 0; i < a.n ; i++){
        for (int j = 0; j < a.n ; j++){
            c.mt[i][j] = a.mt[i][j] + b.mt[i][j];
        }
    }
    return c;
}
// tinh tich 2 ma tran
matran tich( const matran& a, const matran& b){
    matran c(a.n);
    for (int i = 0; i < a.n ; i++){
        for (int j = 0; j < a.n ; j++){
            c.mt[i][j] = 0;
            for (int k = 0; k < a.n ; k++){
                c.mt[i][j] += a.mt[i][k] * b.mt[k][j];
            }
        }
    }
    return c;
}
int main(){
    int n;
    scanf("%d", &n);
    matran a(n), b(n);
    a.nhap();
    b.nhap();
    printf("ket qua: \n");
    matran c= tong(a,b);
    c.hien_thi();
    matran d = tich(a,b);
    d.hien_thi();
    return 0;
}
