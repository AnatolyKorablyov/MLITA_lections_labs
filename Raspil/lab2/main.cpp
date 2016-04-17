﻿// Кораблёв Анатолий, ПС-22
// 14.10. Распил бруса 2 (9)
//На пилораму привезли брус длиной L метров.Требуется сделать N распилов.Распилы делят
//
//брус на части, длина которых выражается натуральными числами.Стоимость одного распила
//
//равна длине распиливаемого бруса.Определить минимальную стоимость распила.
//
//Ввод.В первой строке содержатся через пробел натуральные числа L(2 ≤ L ≤ 105) и N(N < L) –
//
//	длина бруса и число распилов.
//
//	Вывод.В единственной строке вывести минимальную стоимость распилов.
//
//	Примеры
//
//	Ввод 1         Ввод 2
//
//	100 3          10 4
//
//	Вывод 1        Вывод 2
//
//	105            18

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Broos
{
	int length = 0;
	int numCut;
};

vector<int> EnterWithSpaces(string string)
{
	vector<int> numbers;
	int len = string.length();
	int i = 0;
	int m_number = 0;
	while (i <= len)
	{
		if (string[i] >= '0' && string[i] <= '9')
		{
			m_number = m_number * 10 + (string[i] - '0');
		}
		else
		{
			numbers.push_back(m_number);
			m_number = 0;
		}
		i++;
	}
	return numbers;
}

Broos ReadFile(const string & inputFileName)
{
	ifstream inpFile(inputFileName);

	if (!inpFile.is_open())
	{
		cout << "File not found!";
		exit(1);
	}

	int numStr = 0;
	Broos bros;
	while (!inpFile.eof())
	{
		string mainString;
		std::getline(inpFile, mainString);
		std::cout << mainString << std::endl;
		vector<int> numbers;
		if (numStr == 0)
		{
			numbers = EnterWithSpaces(mainString);
			bros.length = numbers[0];
			bros.numCut = numbers[1];
		}
		++numStr;
	}
	return bros;
}

int CalcBisection(const Broos & bros)
{
	int numCuts = bros.numCut;
	int price = 0;
	int length = bros.length;
	vector<int> numbersBros = { length };

	while (numCuts > 0)
	{
		if (numbersBros[0] > 1)
		{
			price += numbersBros[0];
			length = numbersBros[0];
			numbersBros.push_back(length / 2);
			numbersBros.push_back(length - length / 2);
			--numCuts;
			numbersBros.erase(numbersBros.begin());
			sort(numbersBros.begin(), numbersBros.end());
		}
		else
		{
			numbersBros.erase(numbersBros.begin());
		}

	}
	return price;
}

int CalcSubstraction(const Broos & bros)
{
	int length = bros.length;

	Broos locBros = bros;

	locBros.length = bros.numCut;
	locBros.numCut = bros.numCut - 1;
	int price = CalcBisection(locBros) + length;
	return price;
}

int CalcMinPrice(const Broos & bros)
{
	int length = bros.length;
	int numCuts = bros.numCut;

	if (numCuts >= length || numCuts <= 0)
	{
		return 0;
	}

	

	int minPrice = CalcBisection(bros);
	int locPrice = CalcSubstraction(bros);

	if (minPrice > locPrice)
	{
		minPrice = locPrice;
	}
	return minPrice;
}

int main()
{
			string nameInputFile = "input.txt";
	string nameOutFile = "output.txt";
	ofstream outFile(nameOutFile);
	Broos bros;
	bros = ReadFile(nameInputFile);


	while (bros.length != -1)
	{
		cin >> bros.length;
		cin >> bros.numCut;
		cout << "Price: " <<  CalcMinPrice(bros) << endl;
	}
	return 0;
}