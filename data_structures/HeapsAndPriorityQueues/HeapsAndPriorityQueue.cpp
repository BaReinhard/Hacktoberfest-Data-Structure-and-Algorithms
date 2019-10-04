#include <bits/stdc++.h>

using namespace std;

void minheapify(int* arr, int k, int n)
{
	int l, r, smallest;
	smallest = k;
	l = 2 * k + 1;
	r = 2 * k + 2;

	if (l < n && arr[l] < arr[smallest])
		smallest = l;
	if (r < n && arr[r] < arr[smallest])
		smallest = r;

	if (smallest != k)
	{
		int temp = arr[k];
		arr[k] = arr[smallest];
		arr[smallest] = temp;
		minheapify(arr, smallest, n);
	}
}

void min_heap(int* arr, int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
	{
		minheapify(arr, i, n);
	}
}

void heapsort(int* arr, int n)
{
	min_heap(arr, n);
	for (int i = n - 1; i >= 1; i--)
	{
		int temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		minheapify(arr, 0, i);
	}
}

void print(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
}

void Heap_Minimum(int* arr, int n)
{
	min_heap(arr, n);

	cout << "Element with the smallest key " << arr[0] << endl;
}

void Heap_Extract_Min(int* arr, int& n)
{
	min_heap(arr, n);
	int min = arr[0];
	arr[0] = arr[n - 1];
	n = n - 1;
	minheapify(arr, 0, n);
}

void Heap_decrease_key(int* arr, int l, int key, int n)
{
	if (key > arr[l])
	{
		cout << "Entered key is greater than the already present key" << endl;
		return;
	}
	arr[l] = key;
	while (l > 0 && arr[l / 2] > arr[l])
	{
		swap(arr[l / 2], arr[l]);
		l = l / 2;
	}
}

void Min_heap_insert(int* arr, int key, int& n)
{
	n = n + 1;
	arr[n] = 10000;
	Heap_decrease_key(arr, n - 1, key, n);
}

int main()
{
	int n, j;
	cout << "Press 1 for HeapSort Implementation" << endl;
	cout << "Press 2 for Priority Queue Implementation" << endl;
	cin >> j;
	switch (j)
	{
	case 1:
	{
		cout << "Enter the number of elements in the heap" << endl;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		heapsort(a, n);
		print(a, n);
		break;
	}
	case 2:
	{
		cout << "Enter the number of elements in the Priority Queue" << endl;
		cin >> n;
		int a[n];
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}

		Heap_Minimum(a, n);
		print(a, n);
		cout << endl;
		Heap_Extract_Min(a, n);
		print(a, n);
		cout << endl;
		Heap_decrease_key(a, 4, 9, n);
		print(a, n);
		cout << endl;
		Min_heap_insert(a, 6, n);

		print(a, n);

		break;
	}
	default:
	{
		cout << "1 or 2 either are not pressed" << endl;
		break;
	}
	}


	return 0;
}



