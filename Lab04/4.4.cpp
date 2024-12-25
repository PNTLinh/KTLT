#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print_vector(const vector<int>& a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}
//NguyenThuyLinh_20225031
void delete_even(vector<int>& a) {
    for (auto i = a.begin(); i != a.end();) {
        if (*i % 2 == 0)
            i = a.erase(i);  
        else
            ++i; 
    }
}
void sort_decrease(vector<int>& a) {
    sort(a.begin(), a.end(), greater<int>());
}
vector<int> merge_vectors(const vector<int>& a, const vector<int>& b) {
    vector<int> result = a;
    result.insert(result.end(), b.begin(), b.end());
    return result;
}
int main() {
    int m, n, u;
    vector<int> a, b;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        cin >> u;
        a.push_back(u);
    }
    for (int i = 0; i < n; i++) {
        cin >> u;
        b.push_back(u);
    }
    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);
    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);
    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);
    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);
    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
     sort_decrease(c);
    print_vector(c);
    return 0;
}
//NguyenThuyLinh_20225031
