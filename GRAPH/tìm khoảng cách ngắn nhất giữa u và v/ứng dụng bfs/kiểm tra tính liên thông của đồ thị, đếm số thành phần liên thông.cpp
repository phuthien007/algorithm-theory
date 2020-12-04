#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <list>
#include <io.h>
/*
gọi khoảng cách giữa 2 đỉnh là 1 dv do thi vo huong
*/

using namespace std;
int n, m;
vector<list<int>> arr1;
vector<bool> visited;
vector<int> d;
queue<int> q;
//tao danh sach ke
void Create() {
	cin >> n >> m;
	arr1.resize(n + 1);
	visited.resize(n + 1, false);
	d.resize(n + 1, 0);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr1[x].push_back(y);
		arr1[y].push_back(x);
	}
}
//thuat toan BFS tìm quãng đường ngắn nhất từ u đến v
void BFS(int u) {
	visited[u] = true;
	q.push(u);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for (auto i = arr1[v].begin(); i != arr1[v].end(); i++)
			if (visited[*i] == false)
			{
				visited[*i] = true;
				q.push(*i);
			}
	}
}
FILE* fi;
int main()
{
	freopen_s(&fi, "input.txt", "r", stdin);
	int lt = 0;
	Create();
	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == false)
		{
			BFS(i);
			lt += 1;
		}
	}
	if (lt == 1) cout << "do thi lien thong";
	else
		cout << "so thanh phan lien thong la: " << lt;
	return 0;
}
