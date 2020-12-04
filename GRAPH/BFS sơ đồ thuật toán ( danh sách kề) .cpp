#include<iostream>
#include<vector>
#include<queue>
using namespace std;
queue<int> q;
vector<int> a[1000];
bool visited[1000];
int d[1000];
void BFS(int k) {
	visited[k] = true;
	d[k] = 0;
	q.push(k);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (auto i : a[u]) {
			if (visited[i] == false)
			{
				visited[i] = true;
				d[i] = d[u] + 1;
				q.push(i);
			}
		}
	}
	return;
}
int main() {
	int n,m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x].push_back(y);
		a[y].push_back(x);
	}
	BFS(1);
	return 0;
}