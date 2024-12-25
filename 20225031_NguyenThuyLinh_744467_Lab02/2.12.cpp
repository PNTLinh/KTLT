#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;
//NguyenThuyLinh_20225031
struct node {
	int key = 0;
	int value = 0;
};// khai bao node
int main() {
	ifstream f("input12.txt");// doc file du lieu
	if (!f.is_open()) {
		cerr << "Can not open file" << endl;
		return 1;
	}
	vector<node> list;
	node pt;
	while (f >> pt.key >> pt.value) {list.push_back(pt);}
	sort(list.begin(), list.end(),// sap xep 
		[](node a, node b) {
			if (a.value > b.value) return true;
			else if (a.value < b.value) return false;
			else return a.key >= b.key;
		}
	);
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].key << " " << list[i].value << endl;
	}
	f.close();// dong file 
	return 0;
}
