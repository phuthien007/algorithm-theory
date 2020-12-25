#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int n, m;
vector<list<int>> arr1;
vector<bool> visited;
vector<int> distant;
queue<int> q;
//tao danh sach ke
void Create() {
	cin >> n >> m;
	arr1.resize(n + 1);
	visited.resize(n + 1, false);
	visited.resize(n + 1, false);
	distant.resize(n + 1);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr1[x].push_back(y);
		arr1[y].push_back(x);
	}
}

int main() {

	return 0;
}