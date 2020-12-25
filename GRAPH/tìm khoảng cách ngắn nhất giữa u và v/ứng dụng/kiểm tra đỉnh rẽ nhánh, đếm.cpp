#include <iostream>
#include <vector>
#include <queue>
#include <list>
using namespace std;
int n, m;
vector<list<int>> arr1;
vector<bool> visited;
queue<int> q;
//tao danh sach ke
void Create() {
	cin >> n >> m;
	arr1.resize(n + 1);
	visited.resize(n + 1,false);
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr1[x].push_back(y);
		arr1[y].push_back(x);
	}
}
void bfs(int u, vector<list<int>> &arr1) {
	visited[u] = true;
	q.push(u);
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto i : arr1[v])
			if (visited[i] == false)
			{
				visited[i] = true;
				q.push(i);
			}
	}
}
int Countlt(int u, vector<list<int>> &arr) {
	int d = 0;
	for(int i=1;i<=n;i++)
		if (i != u)
		{
			if (visited[i] == false)
			{
				bfs(i,arr);
				d += 1;
			}
		}
	return d;
}
void removed(vector<list<int>> &arr,int u) {
	for (int i = 1; i <= n; i++)
		if (i != u)
			for (auto k : arr1[i])
				if (k != u)
					arr[i].push_back(k);
}
void reset() {
	for (int i = 1; i <= n; i++)
		visited[i] = false;
}
FILE* fi;
int main() {
	int dc = 0;
	vector<int> luu;
	freopen_s(&fi, "input.txt", "r", stdin);
	Create();
	int	Entry = Countlt(0,arr1);
	cout << Entry << endl;
	reset();
	for (int i = 1; i <= n; i++)
	{
		visited.resize(n + 1, false);
		int temp;
		vector<list<int>> arr(n+1);
		removed(arr, i);
		temp = Countlt(i,arr);
		reset();
		if (temp > Entry)
		{
			dc += 1;
			luu.push_back(i);
		}
	}
	cout << dc;
	fclose(fi);
}