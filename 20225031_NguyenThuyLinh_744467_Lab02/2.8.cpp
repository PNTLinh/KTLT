#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
//NguyenThuyLinh_20225031
int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };
//Viết hàm sắp xếp vector
sort(a.begin(), a.end(), []( vector< int >& v1, vector < int>& v2){
    return accumulate( v1.begin(), v1.end(), 0) > accumulate( v2.begin(), v2.end(), 0);
});
for (const auto &v : a) {
    for (int it : v) {
        cout << it << ' ';
    }
        cout << endl;
    }
return 0;
}
//NguyenThuyLinh_20225031
