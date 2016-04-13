// FindMinPath.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>				
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

typedef vector<vector<int>> Matrix;
typedef vector<pair<int, pair<int, int>>> MatrixPath;

bool comp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
	return a.first < b.first;
}

MatrixPath SortMinMatrix(const Matrix & matrix)
{
	MatrixPath matrixPath;
	for (int i = 0; i < matrix.size(); ++i)
	{
		for (int j = 0; j < matrix[i].size(); ++j)
		{
			matrixPath.push_back(make_pair(matrix[i][j], make_pair(i, j)));
			//cout << matrix[i][j] << " ";
		}
		//cout << endl;
	}
	//cout << endl;
	sort(matrixPath.begin(), matrixPath.end(), comp);
	//for (auto i : matrixPath)
	//{
	//	cout << i.first << " x "<< i.second.first << ", " << i.second.second << "; " << endl;
	//}
	//cout << endl;
	return matrixPath;
}


bool CompareIntAndVector(int a, vector<int> path)
{
	for (auto i : path)
	{
		if (i == a)
		{
			return true;
		}
	}
	return false;
}
int FindMinOstov(Matrix & matrix, MatrixPath & matrixPath)
{
	vector<int> path;
	int price = 0;
	for (auto i : matrixPath)
	{
		if (i.first != 0)
		{
			if (!CompareIntAndVector(i.second.first, path) || !CompareIntAndVector(i.second.second, path))
			{
				path.push_back(i.second.first);
				path.push_back(i.second.second);
				price += i.first;
			}
		}
	}
	for (auto i : path)
	{
		cout << i << ", ";
	}
	cout << endl;
	return price;
}

int main()
{
	Matrix matrix;
	matrix.push_back({ 0, 6, 1, 5, 0, 0 });
	matrix.push_back({ 6, 0, 5, 0, 3, 0 });
	matrix.push_back({ 1, 5, 0, 5, 6, 4 });
	matrix.push_back({ 5, 0, 4, 0, 0, 2 });
	matrix.push_back({ 0, 3, 6, 0, 0, 7 });
	matrix.push_back({ 0, 0, 4, 2, 7, 0 });
	MatrixPath matrixPath = SortMinMatrix(matrix);
	cout << FindMinOstov(matrix, matrixPath) << endl;
    return 0;
}

