#include <iostream>
#include <queue>
#include <iomanip>
using namespace std;

// M x N matrix
#define M 10
#define N 10

// Below arrays details all 8 possible movements
int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

// check if it is possible to go to pixel (x, y) from
// current pixel. The function returns false if the pixel
// has different color or it is not a valid pixel
bool isSafe(char mat[M][N], int x, int y, char target)
{
	return (x >= 0 && x < M && y >= 0 && y < N)
		&& mat[x][y] == target;
}

// Flood fill using BFS
void floodfill(char mat[M][N], int x, int y, char replacement)
{
	// create a queue and enqueue starting pixel
	queue<pair<int, int>> q;
	q.push({x, y});

	// get target color
	char target = mat[x][y];

	// run till queue is empty
	while (!q.empty())
	{
		// pop front node from queue and process it
		pair<int, int> node = q.front();
		q.pop();

		// (x, y) represents current pixel
		int x = node.first, y = node.second;

		// replace current pixel color with that of replacement
		mat[x][y] = replacement;

		// process all 8 adjacent pixels of current pixel and
		// enqueue each valid pixel
		for (int k = 0; k < 8; k++)
		{
			// if adjacent pixel at position (x + row[k], y + col[k]) is
			// a valid pixel and have same color as that of current pixel
			if (isSafe(mat, x + row[k], y + col[k], target))
			{
				// enqueue adjacent pixel
				q.push({x + row[k], y + col[k]});
			}
		}
	}
}

int main()
{
	// matrix showing portion of the screen having different colors
	char mat[M][N] =
	{
		{ 'Y', 'Y', 'Y', 'G', 'G', 'G', 'G', 'G', 'G', 'G' },
		{ 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'G', 'X', 'X', 'X' },
		{ 'G', 'G', 'G', 'G', 'G', 'G', 'G', 'X', 'X', 'X' },
		{ 'W', 'W', 'W', 'W', 'W', 'G', 'G', 'G', 'G', 'X' },
		{ 'W', 'R', 'R', 'R', 'R', 'R', 'G', 'X', 'X', 'X' },
		{ 'W', 'W', 'W', 'R', 'R', 'G', 'G', 'X', 'X', 'X' },
		{ 'W', 'B', 'W', 'R', 'R', 'R', 'R', 'R', 'R', 'X' },
		{ 'W', 'B', 'B', 'B', 'B', 'R', 'R', 'X', 'X', 'X' },
		{ 'W', 'B', 'B', 'X', 'B', 'B', 'B', 'B', 'X', 'X' },
		{ 'W', 'B', 'B', 'X', 'X', 'X', 'X', 'X', 'X', 'X' }
	};

	// start node
	int x = 3, y = 9;	// target color = "X"

	// replacement color
	char replacement = 'C';

	// replace target color with replacement color
	floodfill(mat, x, y, replacement);

	// print the colors after replacement
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
			cout << setw(3) << mat[i][j];

		cout << '\n';
	}
}
