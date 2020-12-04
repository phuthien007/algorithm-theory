#include <iostream>
#include <vector>
using namespace std;
int n,m, a[100][100];
vector<int> arr[1000];
void matranke() {
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		a[x][y] = 1;
		a[y][x] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void matrantrongso() {
	for (int i = 0; i < m; i++)
	{
		int x, y,c;
		cin >> x >> y>>c;
		a[x][y] = c;
		a[y][x] = c;
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
void danhsachke() {
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		cin >> x >> y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
	{
		cout << i<<": ";
		for (auto x : arr[i])
			cout << x << " ";
		cout << endl;
	}
}
int main() {
	danhsachke();
	return 0;
}