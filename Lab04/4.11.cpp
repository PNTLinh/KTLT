#include <iostream>
#include <fstream>
#include <queue>
using namespace std;
struct Data {
    int a;
    int k;
    Data(int a, int k) {
        this->a = a;//so luong ten giac tan cong
        this->k = k;//hieu qua phong thu
    }
};
struct compare {
    bool operator() (Data a, Data b) {
        int ra, rb;
        if (a.a <= a.k) ra = a.a;
        else ra = a.k;
        if (b.a <= b.k) rb = b.a;
        else rb = b.k;
        return ra < rb;
    }
};
int main() {
    ifstream f("input4.11.txt");
    int n, s, kill, total;
    priority_queue<Data, vector<Data>, compare> pq;
    f >> n >> s;
    kill = 0;
    total = 0;
    for (int i = 0; i < n; i++) {
        int temp1, temp2;
        f >> temp1 >> temp2;
        total += temp1;
        pq.push(Data(temp1, temp2));
    }
    while (!pq.empty() && s > 0) {
        Data infomation = pq.top(); pq.pop();
        if (infomation.a <= infomation.k) {
            kill += infomation.a;
        }
        else {
            int nenemy = infomation.a - infomation.k;
            pq.push(Data(nenemy, infomation.k));
            kill += infomation.k;
        }
        s--;
    }
    cout << total - kill << endl;
    cout << "NguyenThuyLinh_20225031";
    return 0;
}
