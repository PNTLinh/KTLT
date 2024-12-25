#include <iostream>
using namespace std;
int gcd(int a, int b){// de quy
    if ( b == 0) return a;
    return gcd(b,a % b);
}
//NguyenThuyLinh_20225031
int gcd2(int a, int b){// khu de quy
    int temp;
    while ( b != 0){
        temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}
int main()
{
    int a,b; cin >> a >> b;
    cout<< gcd(a,b) << endl << gcd2(a,b);
    return 0;
}
//NguyenThuyLinh_20225031
