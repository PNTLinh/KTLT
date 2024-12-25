#include <iostream>
#include <string>
using namespace std;
void gen(string s, int n, int a, int b) {
    if (s.length() == n) {
        cout << s << endl;
        return;
    }
    if (s.empty()) {
        gen(s + '0', n, a, b);// xau bắt đầu với 0
        for (int i = a; i <= b && s.length() + i <= n; ++i) {// thêm chuỗi 1
            string temp(i, '1');
            gen(s + temp, n, a, b);
        }
    } else if (s.back() == '0') {// nếu kết thúc bằng 0 thì chỉ thêm chuỗi 1
        for (int i = a; i <= b && s.length() + i <= n; ++i) {
            string temp(i, '1');
            gen(s + temp, n, a, b);
        }
    } else {
        gen(s + '0', n, a, b);// ngược lại thì chỉ thêm 1 số 0
    }
}
int main() {
    int n, a, b; cin >> n >> a >> b;
    cout<<"NguyenThuyLinh_20225031"<< endl;
    gen("", n, a, b);
    return 0;
}
