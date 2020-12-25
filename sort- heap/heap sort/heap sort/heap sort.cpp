#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, a[1000],luu;
void MAX_HEAPIFY(int i,int n){
	if (2 * i <= n)
	{
		if (2 * i + 1 <= n)
		{
			a[2 * i] < a[2 * i + 1] ? luu = 2 * i + 1 : luu = 2 * i;
		}
		else luu = 2 * i;
		if(a[i] < a[luu])
			swap(a[i], a[luu]);
		MAX_HEAPIFY(luu,n);
	}
	else return;
}
/* 19 1 16 12 4 7 */
void BUILB_MAX_HEAP(int a[],int n) {
	for (int i = n / 2; i >= 1; i--)
		MAX_HEAPIFY(i,n);
}
void HEAP_SORT(int a[],int n) {
	if (n == 1) return;
	swap(a[1], a[n]);
	MAX_HEAPIFY(1, n - 1);
	HEAP_SORT(a, n - 1);
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)	
		cin >> a[i];
	BUILB_MAX_HEAP(a, n);
	HEAP_SORT(a,n);
	for (int i = 1; i <= n; i++)
		cout << a[i] << " ";
	return 0;
}