#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
vector<vector<int>> G;
vector<int> mark;
int n, k, m;
int depth; 
int cnt; //so path do dai k
void DFS(int s) {//NguyenThuyLinh_20225031
	mark[s] = 1;
	for (int i = 0; i < n; i++) {
		if (mark[i] != 0) continue;
		if (G[s][i] == 0) continue;
		mark[i] = 1;
		depth++;
		if (depth < k) {
			DFS(i);
		}
		else {
			cnt++;
		}
		depth--;
		mark[i] = 0;
	}
	mark[s] = 0;
}

int main() {
 //NguyenThuyLinh_20225031
	ifstream f("input12.txt");
	f >> n >> k >> m;
	vector<pair<int, int>> V;
	for (int i = 0; i < m; i++) {
		pair<int, int> element;
		f >> element.first >> element.second;
		V.push_back(element);
	}
	for (int i = 0; i < n; i++) {// cai dat do thi
		vector<int> element;
		for (int j = 0; j < n; j++) {
			element.push_back(0);
		}
		G.push_back(element);
	}
	for (int i = 0; i < V.size(); i++) {
		G[V[i].first - 1][V[i].second - 1] = 1;
		G[V[i].second - 1][V[i].first - 1] = 1;
	}
	for (int i = 0; i < n; i++) {
		mark.push_back(0);// danh dau 
	}
	cnt = 0;
	for (int s = 0; s < n; s++) {
		depth = 0;
		DFS(s);
	}
	cout << cnt / 2 << endl; // so duong di bi lap lai
	cout<<"NguyenThuyLinh_20225031";
	f.close();
	return 0;
}