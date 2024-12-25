#include<bits/stdc++.h>
using namespace std;
int count(const string &s){
    unordered_map<int,int> balanceCount;
    balanceCount[0] = 1;
    int balance = 0;
    int count = 0;
    for (char c: s){
        if (c == '0') {
            balance--;
        }
        else {
            balance++;
        }
        if (balanceCount.find(balance) != balanceCount.end()) {
            count += balanceCount[balance];
        }
        balanceCount[balance]++;
    }
    return count;
}
int main(){
    ifstream f("input4.13.txt");
    string s;
    f>> s;
    cout<< count(s)<<endl;
    cout<<"NguyenThuyLinh_20225031";
    return 0;
}