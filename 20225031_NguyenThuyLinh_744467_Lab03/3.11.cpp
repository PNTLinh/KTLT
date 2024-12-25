#include<bits/stdc++.h>
using namespace std;
int cmin; // chi phi di chuyen giua 2 thanh pho khac nhau
int best; // chi phi tot nhat
int curr; // chi phi tinh toi thoi diem hien tai
vector<vector<int>> G;// do thi di chuyen
vector<int> mark, x; // danh dau da tham chua, luu mang truy vet
int N;
void TRY(int k) {
    //NguyenThuyLinh_20225031
	for (int i = 1; i < N - 1; i++) {
		if (mark[i] == 1) continue; //da tham thi bo qua
		if (G[x[k - 1]][i] == 0) continue;
		int miniumCost = curr + G[x[k - 1]][i] + (N - k - 1) * cmin; // giam chi phi di giua cac thanh pho lan can
		if (miniumCost >= best) continue; // neu lon hon best thi bo qua
		mark[i] = 1;// danh dau da tham
		x[k] = i;
		curr += G[x[k - 1]][i];// cap nhat gia tri
		if (k < N - 2) {
			TRY(k + 1);
		}
		else {
			if (G[x[k]][N - 1] != 0) {
				curr += G[x[k]][N - 1];
				x[N - 1] = N - 1;
				if (curr < best) {
					best = curr;
				}
			}
			curr -= G[x[k]][N - 1];// quay lai gia tri truoc
		}
		mark[i] = 0;// quay lai trang thai truoc
		curr -= G[x[k - 1]][i];
	}

}
//NguyenThuyLinh_20225031
int costTravel(vector<vector<int>> G) {// ham chi phi
	N = G.size();
	cmin = INT_MAX;
	best = INT_MAX;
	curr = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (G[i][j] == 0) continue;
			cmin = min(cmin, G[i][j]);
		}
	}
	mark.clear();
	x.clear();
	for (int i = 0; i < G.size(); i++) {
		x.push_back(0);
		mark.push_back(0);
	}
	TRY(1);
	if (best == INT_MAX) return 0;
	return best;
}

int main() {
    //NguyenThuyLinh_20225031
	ifstream f("input.txt");
	vector<vector<int>> c;
	int n, r; f >> n >> r;
	for (int i = 0; i < n; i++) {
		vector<int> elementArr;
		for (int i = 0; i < n; i++) {
			int element;
			f >> element;
			elementArr.push_back(element);
		}
		c.push_back(elementArr);
	}
	string line;
	while (getline(f, line)) {
		istringstream iss(line);
		int element;
		vector<int> E;
		while (iss >> element) {
			E.push_back(element - 1);
		}
		G.clear();
		for (int i = 0; i < E.size(); i++) {
			vector<int> elementVector;
			for (int j = 0; j < E.size(); j++) {
				elementVector.push_back(c[E[i]][E[j]]);
			}
			G.push_back(elementVector);
		}
		if (G.size() == 0) continue;
		cout << costTravel(G) << endl;
	}
	cout<< "NguyenThuyLinh_20225031";
	f.close();
}