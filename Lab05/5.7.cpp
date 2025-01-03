#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0, sum = 0;
    while(n--){
        int k, t;
        cin >> k >> t;
        if(t == 1){// bỏ if ra ngoài vòng lặp while để giảm các trường hợp phải kiểm tra
            while(k--){
                int a;
                cin >> a;
                sum += a;
                ans = max(ans, -sum);
            }
        } else {// t chỉ có 2 trường hợp 1 và -1 ứng với việc nhận và cho tiền
            while(k--){
                int a;
                cin >> a;
                sum -= a;
                ans = max(ans, -sum);
            }
        }
    }
    cout << ans;
}
//NguyenThuyLinh_20225031
