#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int n, c[MAX][MAX]; //# sô* thành phô* và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nho% nhâ*t giữa hai thành phô* khác nhau
int best = INT_MAX; //# tô%ng chi phí nho% nhâ*t câIn tìm, ban đâIu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr = 0 ; //# tô%ng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dâ*u những thành phô* đã đi
int x[MAX]; //# lưu giữ các thành phô* đã đi
//# Đọc dữ liệu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);
        }
}
//# Thuật toán quay lui
void TRY(int k){
    //NguyenThuyLinh_20225031
    for (int i = 2; i <=n; i++){
        if (!mark[i] && c[x[k-1]][i] >0){
            x[k] = i;// luu thanh pho tiep theo la i
            mark[i] = 1;// danh dau da tham
            curr += c[x[k-1]][i]; // cap nhat chi phi
            if ( k == n){// sau khi tham het cac thanh pho
                int total_cost = curr + c[x[k]][1];// cong them chi phi quay ve
                best = min (best, total_cost);
            }
            else{
                if (curr + cmin * (n - k +1) < best) TRY(k+1);// cat tia
            }
            // backtrack
            mark[i] = 0;// danh dau la chua tham
            curr -= c[x[k-1]][i];// cap nhat lai chi phi
        }
    }
}
int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
//NguyenThuyLinh_20225031
