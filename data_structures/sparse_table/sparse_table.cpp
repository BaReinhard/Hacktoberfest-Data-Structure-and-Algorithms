#include<bits/stdc++.h>

using namespace std;


class SparseTable {

public:
	vector<int> input;
	vector< vector<int> > sparseTable;
	int n;
	int logVal;

	SparseTable(int inputSize)
	{
		n = inputSize;
		input.resize(n);
		sparseTable.resize(n);
		logVal = log2(n);
		for(int i = 0; i < n; i++)
		{
			sparseTable[i].resize(logVal);
		}
	}

	void preprocess();
	void getInput(vector<int>);
	int rangeMinQuery(int, int);
};

void SparseTable :: preprocess()
{
	for(int i = 0; i < n; i++)
	{
		sparseTable[i][0] = i;
	}
	for(int j = 1; 1 << j <= n; j++)
	{
		for(int i = 0; i + (1 << j) - 1 < n; i++)
		{
			if(input[sparseTable[i][j - 1]] < input[sparseTable[i + (1 << (j - 1))][j - 1]])
			{
				sparseTable[i][j] = sparseTable[i][j - 1];
			}
			else
			{
				sparseTable[i][j] = sparseTable[i + (1 << (j - 1))][j - 1];
			}
		}
	}
}

void SparseTable :: getInput(vector<int> arr)
{
	input = arr;
}

int SparseTable :: rangeMinQuery(int low, int high)
{
	int totalElements = high - low + 1;
	int currLog = log2(totalElements);
	return min(input[sparseTable[low][currLog]], input[sparseTable[low + totalElements - (1 << currLog)][currLog]]);
}

int main()
{
	int n;
	n = 5;
	vector<int> arr(n);
	arr[0] = -1;
	arr[1] = 2;
	arr[2] = 10;
	arr[3] = 3;
	arr[4] = 5;
	SparseTable *sparseTable = new SparseTable(n);
	sparseTable -> getInput(arr);
	sparseTable -> preprocess();
	for(int i = 0; i < n; i++)
	{
		for(int j = i; j < n; j++)
		{
			cout << sparseTable -> rangeMinQuery(i, j) << '\n';
		}
	}
	return 0;
}