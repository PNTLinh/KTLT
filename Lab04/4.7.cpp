#include <iostream>
#include <set>
using namespace std;
template<class T>
set<T> set_union(const set<T> &a, const set<T> &b) {
    set<T> key;
    for (const T &x: a) key.insert(x);
    for (const T &x: b) key.insert(x);
    return key;
}
template<class T>
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    set<T> key;
    for (const T &x : a){
        if (b.find(x) != b.end()) key.insert(x);
    }
    return key;
}
//NguyenThuyLinh_20225031
