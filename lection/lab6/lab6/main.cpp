#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

struct Numbers
{
	vector<int> M;
	vector<int> N;
};

Numbers ReadFile(const string & nameFile)
{
	ifstream inpFile(nameFile);
	if (!inpFile.is_open())
	{
		cout << "File not found!";
		exit(1);
	}

	int numStr = 0;
	Numbers numbers;
	int num;
	while (!inpFile.eof())
	{
		string mainString;
		std::getline(inpFile, mainString);
		for (size_t i = 0; i < mainString.size(); i++)
		{
			if (mainString[i] >= '0' && mainString[i] <= '9')
			{
				num = mainString[i] - '0';
				if (numStr == 0)
				{
					numbers.M.push_back(num);
				}
				else if (numStr == 1)
				{
					numbers.N.push_back(num);
				}
			}
		}
		++numStr;
	}
	return numbers;
}

vector<int> CalcRaznost(Numbers & num)
{
	int countN = num.N.size() - 1;
	int countM = num.M.size() - 1;
	while (countN >= 0)
	{
		int localCountM = countM - 1;
		if (num.M[countM] >= num.N[countN])
		{
			num.M[countM] = num.M[countM] - num.N[countN];
		}
		else
		{
			while (num.M[localCountM] == 0)
			{
				--localCountM;
			}
			if (num.M[localCountM] != 1)
			{
				num.M[localCountM] -= 1;
				num.M[countM] = num.M[countM] + 10 - num.N[countN];
			}
			else
			{
				num.M[localCountM] = 0;
				while (localCountM != countM - 1)
				{
					++localCountM;
					num.M[localCountM] = 9;
				}
				num.M[countM] = num.M[countM] + 10 - num.N[countN];
			}
		}
		--countM;
		--countN;
	}
	return num.M;
}

void OutFile(vector<int> num, string outFileName)
{
	ofstream outFile(outFileName);
	while (num[0] == 0)
	{
		num.erase(num.begin());
	}

	for (auto i : num)
	{
		outFile << i;
	}
}
int main()
{
	string inputFileName;
	cout << "Enter input file" << endl;
	cin >> inputFileName;
	Numbers num = ReadFile(inputFileName);
	vector<int> nums = CalcRaznost(num);
	OutFile(nums, "outFile.txt");
	system("pause");
	return 0;
}