#include <iostream>
#include <vector>
using namespace std;
//NguyenThuyLinh_20225031
//viết lại hàm nhân 2 đa thức
vector<int> operator* (vector<int> A, vector<int> B) {
	vector<int> C; //lưu kết quả
	int n = A.size() + B.size() - 1;// kích thước kết quả
	for (int k = 0; k < n; k++) {
		int sum = 0; 
		for (int i = 0; i <= k; i++) {
			int a, b;
			if (i < A.size()) {a = A[i]; } else a = 0;
			if (k - i < B.size()) {b = B[k - i];} else b = 0;
			sum += a * b;
		}
		C.push_back(sum);
	}
	return C;
}
//NguyenThuyLinh_20225031
int main() {
	freopen("input11.txt", "r", stdin);// đọc dữ liệu từ file( vì quá dài)
	vector<int> a, b;
	int N, M; cin >> N;
	for (int i = 0; i <= N; i++) {
		int pt; cin >> pt;
		a.push_back(pt);
	}
	cin >> M;
	for (int i = 0; i <= M; i++) {
		int pt; cin >> pt;
		b.push_back(pt);
	}
	vector<int> c = a * b;
	int ans = c[0];
	for (int i = 1; i < c.size(); i++) ans = ans ^ c[i];
	cout << ans;
	return 0;
}

