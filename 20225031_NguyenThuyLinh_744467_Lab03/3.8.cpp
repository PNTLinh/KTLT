#include <iostream>
#include <stack>
using namespace std;
struct state {
    int i, j;
    state(int _i = 0, int _j = -1) : i(_i), j(_j) {}
};
int main() {
    int n, M; cin >> n >> M;
    int m[n + 1];
    for (int i = 1; i <= n; ++i) cin >> m[i];
    int x[n + 1];
    stack<state> s;
    int sum = 0;
    s.push(state(1, -1));
    bool noPop = true;
    x[1] = -1;
    cout<<"NguyenThuyLinh_20225031"<<endl;
    while (!s.empty()) { 
        state& top = s.top();
        if (top.i > n) {
            sum = 0;
            for (int i = 1; i <= n; ++i) {
                sum += x[i] * m[i];
            }
            if (sum == M) {
                for (int i = 1; i <= n; ++i) {
                    if (x[i] == -1) cout << '-' << m[i];
                    if (x[i] == 1) cout << '+' << m[i];
                }
                cout << "=" << M;
                exit(0);
            }
            s.pop();
            noPop = false;
            continue;
        }
        if (noPop == true) { //creat top
            state newState = state(top.i + 1, -1);
            s.push(newState);
            x[newState.i] = newState.j;
        }
        else {
            if (top.j != 1) { //change top
                top.j++;
                x[top.i] = top.j;
                noPop = true;
            }
            else { //earse top
                s.pop();
                noPop = false;
            }
        }   
    }
    cout << -1;
    return 0;
}
//NguyenThuyLinh_20225031
