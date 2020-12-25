#include <iostream>
#include <vector>
using namespace std;
int n;
vector<int> a;
//tao hang doi uu tien bang heap
void MAX_HEAPIFY(int i, int n) {
	int luu;
	if (2 * i <= n) {
		if (2 * i + 1 <= n)
			a[2 * i + 1] > a[2 * i] ? luu = 2 * i + 1 : luu = 2 * i;
		else luu = 2 * i;
		if (a[i] < a[luu])
			swap(a[i], a[luu]);
		MAX_HEAPIFY(luu, n);
	}
	else return;
}
void BUILT_MAX_HEAP(int n) {
	for (int i = n / 2; i >= 1; i--)
		MAX_HEAPIFY(i, n);
}
// tra lai phan tu co khoa lon nhat trong a
int MAXIMUM() { return a[1]; }
// loai bo va tra lai phan tu cua a voi khoa lon nhat
int EXTRACT_MAX() {
	int temp = MAXIMUM();
	swap(a[1], a[n]);
	n -= 1;
	MAX_HEAPIFY(1, n);
	return temp;
}
// tang gia tri khoa cua phan tu  x len k
void INCREASE_KEY( int x, int k) {
	a[x] = k;
	while (x / 2 >= 1 && a[x] > a[x/2])
	{
		swap(a[x], a[x / 2]);
		x /= 2;
	}
}
// bo sung phan tu x vao tap a
void INSERT( int k) {
	a.push_back(0);
	n += 1;
	INCREASE_KEY(n, k);
}

/*
5
7 4 3 1 2*/
int main() {
	cin >> n;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	BUILT_MAX_HEAP(n);
	INSERT(5);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}