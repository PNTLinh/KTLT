#include <bits/stdc++.h>
using namespace std;
struct state{
    int i, j, old_L;
    //# constructor
    state(int _i = 0, int _j = 0, int _L = 0):
        i(_i), j(_j), old_L(_L){}
};
int main() {
    int n, k;
    cin >> n >> k;
    int x[n+1];
    stack<state> s;
    //# number of consecutive suffix 1
    int L = 0;
    s.push(state(1, 0));
    bool noPop = true;
    x[1] = 0;
    while (!s.empty()){
        state &top = s.top();
        //# if a new binary sequence is found
        if (top.i > n){
            for (int i = 1; i <= n; ++i)
                cout << x[i] << " \n"[i == n];
            s.pop();
            noPop = false;
            continue;
        }
        //NguyenThuyLinh_20225031
        if (noPop == true) {
        	//creat new state and push
        	state newState = state(top.i + 1, 0);
        	s.push(newState);
        	//get value of x[i]
			x[newState.i] = newState.j;
		} else {
			//get previous top
			s.pop(); //earse top
			if (s.empty() == false) { //have previous top
				state prevTop = s.top();
				noPop = false;
				x[top.i] = -1;
				
				//get top.old_L if top can change 
				top.old_L = prevTop.old_L + 1;
			} else { //no have previous top
				top.old_L = 1;
			}
			L = top.old_L;
			if (top.j == 0 && L < k) { //if top can change, push top again
				//change top
				top.j = 1;
				//push top again
				s.push(top);
				noPop = true;
				//get value of x[i]
				x[top.i] = top.j;
			} else { //if top can not change
				continue;			
			}
		}
    }
    return 0;
}
//NguyenThuyLinh_20225031
