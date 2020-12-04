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
	visited.resize(n + 1,false);
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
	d[u] = 0;
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		for(auto i= arr1[v].begin();i!= arr1[v].end(); i++)
			if (visited[*i] == false)
			{
				
				visited[*i] = true;
				d[*i] += d[v]+1;
				q.push(*i);
			}
	}
}
FILE* fi;
int main()
{
	
	freopen_s( &fi,"input.txt", "r", stdin);
	int u, v;
	Create();
	cout << "nhap hai dinh muon tim khoang cach : ";
	cin >> u >> v;
	cout << u << " " << v<<endl;
	BFS(u);
	if (d[v] == 0)
		cout << "khong co duong di tu u den v";
	else cout << d[v];
	fclose(fi);
	return 0;
}
