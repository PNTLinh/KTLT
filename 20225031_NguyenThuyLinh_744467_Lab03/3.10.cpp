#include <iostream>
#include <string>
using namespace std;
int countOnes(const string &s) {// hàm đếm số 1 trong 1 xâu cho trước
    int count = 0;
    for (char c : s) {if (c == '1') count++;}
    return count;
}
void print(string s) { cout << s << endl;}// hàm in ra kết quả
void gen(int n, int h) {// hàm sinh ra xâu thỏa mãn
    string s(n, '0'); 
    while (true) {
        if (countOnes(s) == h) print(s);
        int i = n - 1;
        while (i >= 0 && s[i] == '1') {i--;}
        if (i == -1) { break;}
        s[i] = '1';
        for (int j = i + 1; j < n; j++) s[j] = '0';
    }
}
int main() {
    int m; cin >>m;
    for (int i = 0; i < m; i++){
        int n,h; cin >>n >>h;
        gen(n,h);}
    cout<<"NguyenThuyLinh_20225031"<< endl;
    return 0;
}
