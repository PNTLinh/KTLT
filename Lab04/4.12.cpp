#include <bits/stdc++.h>
using namespace std;
long maxRec(int n, vector<long>& h) {
    stack<int> s;
    long maxArea = 0;
    for (int i = 0; i <= n; i++) {
        while (!s.empty() && (i == n || h[s.top()] > h[i])) {
            long height = h[s.top()];
            s.pop();
            long width = s.empty() ? i : i - s.top() - 1;
            maxArea = max(maxArea, height * width);
        }
        s.push(i);
    }
    return maxArea;
}
int main() {
    ifstream f("input4.12.txt");
    int n;
    f >> n;
    vector<long> h(n);
    for (int i = 0; i < n; i++) f >> h[i];
    cout << maxRec(n,h) << endl;
    cout << "NguyenThuyLinh_20225031" << endl;
    return 0;
}
