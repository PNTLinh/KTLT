#include <iostream>
using namespace std;
int n;
int X[100], Y[100]; //Lưu tọa độ các bước di chuyển cua quân mã
int mark[100][100]; //Đánh dâu vị trí các ô mà quân mã đã di chuyển qua
//Mang hx, hy mô ta 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};
//In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; j++) 
        printf ("(%d %d)\n",X[j], Y[j]);
    exit(0);
}
//NguyenThuyLinh_20225031
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];
        int yy = Y[k-1] + hy[i];
        if ( mark[xx][yy] == 1) continue;// neu da tham thi bo qua
        if ( xx < 1 || yy < 1 || xx > n || yy > n ) continue;// neu tran ra ngoai thi bo qua
        X[k] = xx;
        Y[k] = yy;
        mark[xx][yy] = 1;
        if (k == n * n) print_sol(); else TRY( k + 1);
        mark[xx][yy] = 0;
    }
}
int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
//NguyenThuyLinh_20225031
