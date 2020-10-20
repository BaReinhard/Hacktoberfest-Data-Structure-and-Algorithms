#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// A min-heap node
struct Node
{
	// val stores the element,
	// i stores list number of the element,
	// index stores column number of the list from which element was taken
	int val, i, index;
};

// Comparison object to be used to order the min-heap
struct comp
{
	bool operator()(const Node lhs, const Node rhs) const
	{
		return lhs.val > rhs.val;
	}
};

// Function to merge M sorted lists of variable length and
// print them in ascending order
void printSorted(vector<int> list[], int M)
{
	// create an empty min-heap
	priority_queue<Node, std::vector<Node>, comp> pq;

	// push first element of each list into the min-heap
	// along with list number and their index in the list
	for (int i = 0; i < M; i++) {
		if (list[i].size() >= 1) {
			pq.push({list[i][0], i, 0});
		}
	}

	// run till min-heap is empty
	while (!pq.empty())
	{
		// extract minimum node from the min-heap
		Node min = pq.top();
		pq.pop();

		// print the minimum element
		cout << min.val << " ";

		// take next element from "same" list and
		// insert it into the min-heap
		if (min.index + 1 < list[min.i].size())
		{
			min.index += 1;
			min.val = list[min.i][min.index];
			pq.push(min);
		}
	}
}

int main()
{
	// M arrays of variable size
	vector<int> list[] =
	{
		{ 10, 20, 30, 40 },
		{ 15, 25, 35 },
		{ 27, 29, 37, 48, 93 },
		{ 32, 33 }
	};

	int M = sizeof(list) / sizeof(list[0]);

	printSorted(list, M);

	return 0;
}
