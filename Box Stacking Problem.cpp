#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Data structure to store a box (L x W x H)
struct Box {
	// constraint: width is never more than length
	int length, width, height;
};

// Function to generate rotations of all the boxes
vector<Box> createAllRotations(const vector<Box> &boxes)
{
	// stores all rotations of each box
	vector<Box> rotations;

	// do for each box
	for (const Box &box: boxes)
	{
		// push the original box: {L x W x H}
		rotations.push_back(box);

		// push the first rotation: {max(L, H) x min(L, H) x W}
		rotations.push_back({ max(box.length, box.height),
						min(box.length, box.height),
						box.width });

		// push the second rotation: {max(W, H) x min(W, H) x L}
		rotations.push_back({ max(box.width, box.height),
						min(box.width, box.height),
						box.length });
	}

	return rotations;
}

// Create a stack of boxes which is as tall as possible
int maxHeight(vector<Box> const& boxes)
{
	// generate rotations of each box
	vector<Box> rotations = createAllRotations(boxes);

	// sort the boxes in descending order of area(L x W)
	sort(rotations.begin(),
		rotations.end(),
		[](const Box &x, const Box &y) {
			return x.length * x.width > y.length * y.width;
		});

	// max_height[i] stores the maximum possible height when i'th box is on the top
	vector<int> max_height(rotations.size());

	// fill max_height[] in bottom-up manner
	for (int i = 0; i < rotations.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			// dimensions of the lower box are each strictly larger than those
			// of the higher box
			if (rotations[i].length < rotations[j].length &&
					rotations[i].width < rotations[j].width) {
				max_height[i] = max(max_height[i], max_height[j]);
			}
		}

		max_height[i] += rotations[i].height;
	}

	// return the maximum value in max_height[]
	return *max_element(max_height.begin(), max_height.end());
}

int main()
{
	// input boxes
	vector<Box> boxes {
		{ 4, 2, 5 },
		{ 3, 1, 6 },
		{ 3, 2, 1 },
		{ 6, 3, 8 }
	};

	cout << "The maximum height is " << maxHeight(boxes);

	return 0;
}
