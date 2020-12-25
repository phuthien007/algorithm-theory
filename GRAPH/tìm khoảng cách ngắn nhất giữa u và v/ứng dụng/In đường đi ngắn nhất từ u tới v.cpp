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
void bfs(int u) {
	visited[u] = true;
	q.push(u);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		for(auto i:arr1[v])
			if (visited[i]==false) {
				visited[i] = true;
				distant[i] = v;
				q.push(i);
			}
	}
}
FILE* fi;
int main() {
	freopen_s(&fi, "input.txt", "r", stdin);
	Create();
	int u, v;
	cin >> u >> v;
	bfs(u);
	if (distant[v] == 0)
		cout << "khong co duong di tu " << u << " toi " << v;
	else {
		while (distant[v])
		{
			cout << v << " ";
			v = distant[v];
		}
	}
	return 0;
}