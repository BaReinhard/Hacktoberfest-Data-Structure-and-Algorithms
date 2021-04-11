/**
 * Joint sets with an array abroad
 */

#include <bits/stdc++.h>

#define ARR_SIZE 10

using namespace std;

// function prototypes
int find(int *arr, int a);
void join(int *arr, int a, int b);

int main(int argc, char const *argv[]) {
	
	int arr[ARR_SIZE], ct = 0;

	for (int i = 0; i < ARR_SIZE; ++i) {
		arr[i] = i;
	}

	join(arr, 1, 4);
	join(arr, 1, 5);
	join(arr, 6, 7);

	for (int i = 0; i < ARR_SIZE; ++i) {
		if(arr[i] == i) ct++;
	}

	cout << ct << " disjoint sets" << endl;

	return 0;
}

/**
 * @brief      Join elements a and b.
 *
 * @param      arr   The arr.
 * @param[in]  a     The first element to join.
 * @param[in]  b     The second element to join.
 */
void join(int *arr, int a, int b) {
	int r = find(arr, b);
	int s = find(arr, a);

	arr[r] = arr[s];
}

/**
 * @brief      Find the set representant of some element.
 *
 * @param      arr   The arr.
 * @param[in]  a     representant.
 *
 * @return     The representant of the set.
 */
int find(int *arr, int a) {
	if(arr[a] == a)
		return a;

	find(arr, arr[a]);
}

