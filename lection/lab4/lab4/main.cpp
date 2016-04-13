#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
#include <vector>
#include <algorithm>

int ReadFile(std::string nameFile)
{
	std::ifstream inpFile(nameFile);
	if (!inpFile.is_open())
	{
		std::cout << "Error open file\n";
		system("pause");
		exit(1);
	}
	int num = 0;
	while (!inpFile.eof())
	{
		std::string string;
		std::getline(inpFile, string);
		if (num == 0)
		{
			num = atoi(string.c_str());
		}
	}
	return num;
}

void CalcArea(int ConstNumber)
{
	std::vector<int> mass;
	std::vector<std::vector<int>> massMass;
	int koren2 = int(sqrt(ConstNumber));
	int koren = koren2;
	for (int j = 0; j < koren2; j++)
	{
		int number = ConstNumber;
		koren = koren2 - j;
		number = number - (koren * koren);
		mass.push_back(koren*koren);
		while (koren >= 1)
		{
			koren = int(sqrt(number));
			number = number - (koren * koren);
			if (koren != 0)
				mass.push_back(koren*koren);
		}
		massMass.push_back(mass);
		mass.clear();
	}


	int min = 99999;
	for (auto i : massMass)
	{
		if (i.size() < min) {
			min = i.size();
			mass = i;
		}
	}
	std::cout << min << "\n";
	for (auto j : mass)
	{
		std::cout << j << ", ";
	}
	std::cout << "\n\n";
}

int main()
{
	std::string nameFile;
	std::cout << "Input File name: ";
	std::cin >> nameFile;
	int number = ReadFile(nameFile);
	CalcArea(number);
	system("pause");
	return 0;
}