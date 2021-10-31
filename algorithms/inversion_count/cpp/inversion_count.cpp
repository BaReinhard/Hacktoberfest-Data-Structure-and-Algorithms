#include <bits/stdc++.h>
using namespace std;

long merge(vector<int> &arr, vector<int> &tmp, int left, int mid, int right) {
	int i = left;
	int k = left;
	int j = mid;
	long count = 0;
	while(i <= (mid-1) && j <= right) {
		if(arr[i] <= arr[j] ) tmp[k++] = arr[i++];
		else {
			tmp[k++] = arr[j++];
			count += mid - i;
		}
	}
	while(i <= mid - 1)
		tmp[k++] = arr[i++];
	while(j <= right)
		tmp[k++] = arr[j++];
	for (int i = left; i <= right; ++i) {
		arr[i] = tmp[i];
	}
	return count;
}

long mergeSort(vector<int> &arr, vector<int> &tmp, int left, int right) {
	long count = 0;
	int mid;
	if(left < right) {
		mid = (right + left)/2;
		count += mergeSort(arr, tmp, left, mid);
		count += mergeSort(arr, tmp , mid+1 , right);
		count += merge(arr, tmp, left, mid+1, right);
	}
	return count;
}

long countInversions(vector<int> arr) {
   vector<int> tmp(arr.size());
   return mergeSort(arr, tmp, 0, arr.size()-1);
}

int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int arr_i = 0; arr_i < n; arr_i++) {
       cin >> arr[arr_i];
    }
    long result = countInversions(arr);
    cout << result << endl;
    return 0;
}