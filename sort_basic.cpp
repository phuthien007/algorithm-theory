#include <iostream>
#include <vector>
using namespace std;
int n, a[100];
void bubbleSort() {
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			swap(a[i], a[j]);
}
void insertionSort() {
	int index, value;
	for (int i = 1; i < n; i++)
	{
		index = i;
		value = a[i];
		while (index > 0 && a[index - 1] > value)
		{
			a[index] = a[index - 1];
			index -= 1;
		}
		a[index] = value;
	}
}
void selectionSort() {
	int index;
	for (int i = 0; i < n; i++)
	{
		int index = i;
		for (int j = index; j < n; j++)
			if (a[j] < a[index])
				index = j;
		if (index != i)
			swap(a[i], a[index]);
	}
}
void quicksort(int d, int c) {
	int i = 0, j = c;
	int mid = (c + d) / 2;
	while (i < j)
	{
		while (a[i] < a[mid]) i += 1;
		while (a[j] > a[mid]) j -= 1;
		if (i <= j)
		{
			swap(a[i], a[j]);
			i += 1;
			j -= 1;
		}
	}
	if (i < c) quicksort(i, c);
	if (d < j) quicksort(d, j);
}
void merge(int d,int m,int c) {
	int a1[100], a2[100];
	int n1 = m - d + 1, n2 = c - m;
	for (int i = 0; i < n1; i++)
		a1[i] = a[i + d ];
	for (int i = 0; i < n2; i++)
		a2[i] = a[m + i+1];
	int i = 0, j = 0, k = d;
	while (i < n1 and j < n2) {
		if (a1[i] < a2[j])
		{
			a[k] = a1[i];
			k += 1; i += 1;
		}
		else {
			a[k] = a2[j];
			k += 1; j += 1;
		}
	}
	while (i < n1)
	{
		a[k] = a1[i];
		k += 1; i += 1;
	}
	while (j < n2)
	{
		a[k] = a2[j];
		k += 1; j += 1;
	}
}
void MergeSort(int a[], int l, int r) {
	if (l < r)
	{
		int mid = l + (r - l) / 2;
		MergeSort(a, l, mid);
		MergeSort(a, mid + 1, r);
		merge(l, mid, r);
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		a[i] = n-i+2;
	quicksort(0, n - 1);
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";

}
