#include <bits/stdc++.h>
using namespace std;
template<class T>
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> key;
    for (const auto &x : a){
        for (const auto &y : b){
            if (x.first == y.first) {
                key.insert({x.first, max(x.second, y.second)});
                break;
            }
        }
        if (key.find(x.first) == key.end()) key.insert({x.first, x.second});
    }
    for ( const auto &x: b){
        for (const auto &y: a){
            if (!(a.find( x.first) != a.end())) key.insert({x.first, max(x.second, y.second)});
        }
    }
    return key;
}
template<class T>
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    map<T, double> key;
    for (const auto &x: a){
        for (const auto &y : b){
            if (x.first == y.first) {
                key.insert({x.first, min(x.second, y.second)});
            }
        }
    }
    return key;
}
//NguyenThuyLinh_20225031
