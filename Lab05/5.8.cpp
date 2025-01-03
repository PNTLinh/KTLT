#include <bits/stdc++.h>
using namespace std;
int w, h;
int table[601][601];
void init() {
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            table[i][j] = i*j;
        }
    }
}
int main(){//NguyenThuyLinh_20225031
    ios::sync_with_stdio(false);
    cin.tie();
    int w, h, m;
    cin >> w >> h;
    cin >> m;
    init();
    for (int i=0; i<m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        table[tmp2][tmp1] = 0;
    }
    for (int i=1; i<=h; i++) {
        for (int j=1; j<=w; j++) {
            int minWaste = table[i][j];
            // horizonal cut
            for(int k=1; k<=i; k++) {// cắt hình theo chiều ngang
                minWaste = min(minWaste, table[k][j] + table[i-k][j]);
            }
            // vertical cut
            for (int k=1; k<=j; k++) {// cắt theo chiều dọc // fix here //k<=i ==> k<=j
                minWaste = min(minWaste, table[i][k] + table[i][j-k]);
            }
            table[i][j] = minWaste;
        }
    }
    cout << table[h][w] << endl;
}
