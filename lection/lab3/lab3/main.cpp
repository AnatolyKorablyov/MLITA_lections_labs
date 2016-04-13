#include <iostream>
#include <string>
#include <fstream>
#include <vector>


int readFirst(std::string string, std::vector<std::vector<int>> &matrix)
{
	int  len = string.length();
	int m_number = 0;
	int num = 0;

	while (string[num] >= '0' && string[num] <= '9' && num <= len) {
		m_number = m_number * 10 + (string[num] - '0');
		num++;
	}
	int numWeidth = m_number;
	m_number = 0;
	num++;

	while (string[num] >= '0' && string[num] <= '9' && num <= len) {
		m_number = m_number * 10 + (string[num] - '0');
		num++;
	}
	int numHeight = m_number;
	matrix.resize(numWeidth);
	return numHeight;
}

void readString(int numH, int numW, int & num, std::string string, std::vector<std::vector<int>> & matrix)
{
	int len = string.length();
	int m_number = 0;
	bool minus = false;
	std::vector<int> locMatrix;
	while (string[num] >= '0' && string[num] <= '9' && num <= len || (string[num] == '-')) {
		if (string[num] == '-') 
		{
			minus = true;
		}
		else 
		{
			m_number = m_number * 10 + (string[num] - '0');
		}
		
		num++;
	}
	if (minus)
	{
		m_number *= -1;
	}
	matrix[numH][numW] = m_number;
	num++;
}

void MatrixInit(std::vector<std::vector<int>> & matrix, int num) 
{
	for (int i = 0; i < matrix.size(); i++)
	{
		matrix[i].resize(num);
		for (int j = 0; j < num; j++)
		{
			matrix[i][j] = 0;
		}
	}
}

void FindPath(std::vector<std::vector<int>> & matrix)
{
	std::vector<std::vector<int>> mtrx;
	mtrx.resize(matrix.size());
	MatrixInit(mtrx, matrix[0].size());
	mtrx[0][0] = matrix[0][0];
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			if (j < matrix[i].size() - 1)
			{
				if ((mtrx[i][j] + matrix[i][j + 1] < mtrx[i][j + 1]) || mtrx[i][j + 1] == 0)
				{
					mtrx[i][j + 1] = mtrx[i][j] + matrix[i][j + 1];
				}
			}
			if (i < matrix.size() - 1)
			{
				if (mtrx[i][j] + matrix[i + 1][j] < mtrx[i + 1][j] || mtrx[i + 1][j] == 0)
				{
					mtrx[i + 1][j] = mtrx[i][j] + matrix[i + 1][j];
				}
			}
		}
	}
	matrix = mtrx;
}

void Application(std::string inputFileName, std::string outFileName)
{
	std::ifstream inpFile(inputFileName);
	if (!inpFile.is_open())
	{
		std::cout << "Error open file\n";
		system("pause");
		exit(1);
	}
	std::string string;
	int firstStr = 0;
	std::vector<std::vector<int>> matrix;
	int N;
	while (!inpFile.eof())
	{
		std::getline(inpFile, string);
		if (firstStr == 0)
		{
			N = readFirst(string, matrix);
			MatrixInit(matrix, N);
		}
		else
		{
			matrix[firstStr - 1].resize(N);
			int it = 0;
			for (int i = 0; i < N; i++)
			{
				readString(firstStr - 1, i, it, string, matrix);
			}
		}
		firstStr++;
	}
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	FindPath(matrix);
	std::cout << "\n\n\n";
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].size(); j++)
		{
			std::cout << matrix[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::ofstream outFile(outFileName);
	int i = matrix.size() - 1;
	int j = matrix[i].size() - 1;
	outFile << matrix[i][j];
}

int main()
{
	std::string inputFileName;
	std::cout << "Enter input file name\n";
	std::cin >> inputFileName;

	std::string outputFileName;
	std::cout << "Enter output file name\n";
	std::cin >> outputFileName;
	Application(inputFileName, outputFileName);
	system("pause");
	return 0;
}