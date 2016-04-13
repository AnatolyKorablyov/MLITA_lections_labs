#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
std::vector<_int64> ReadFile(std::string nameFile)
{
	std::ifstream inpFile(nameFile);
	if (!inpFile.is_open())
	{
		std::cout << "Error open file\n";
		system("pause");
		exit(1);
	}
	int num = 0;
	std::vector<_int64> numbers;
	while (!inpFile.eof())
	{
		std::string string;
		std::getline(inpFile, string);
		if (num == 0)
		{
			num = atoi(string.c_str());
		}
		else
		{
			int i = 0;
			_int64 m_number = 0;
			int len = string.length();
			bool minus = false;
			while (i <= len)
			{
				
				if (string[i] == '-')
				{
					minus = true;
				}
				else if (string[i] >= '0' && string[i] <= '9') 
				{
					m_number = m_number * 10 + (string[i] - '0');
				}
				else
				{
					if (minus)
					{
						m_number *= -1;
					}
					minus = false;
					numbers.push_back(m_number);
					m_number = 0;
				}
				i++;
			}
		}
	}
	return numbers;
}

int main()
{
	std::string nameFile;
	std::cout << "Input File name: ";
	std::cin >> nameFile;
	std::vector<_int64> numbers = ReadFile(nameFile);
	std::cout << "read Complete!\n";
	std::sort(numbers.begin(), numbers.end());
	std::ofstream outFile("output.txt");
	_int64 numb = 0;
	int count = 1;
	if (numbers.size() > 1)
	{
		int localCount = 1;
		for (size_t i = 1; i < numbers.size(); i++)
		{
			if (numbers[i] == numbers[i - 1])
			{
				localCount += 1;
			}
			else if (count < localCount)
			{
				count = localCount;
				numb = numbers[i - 1];
				localCount = 1;
			}
			else
			{
				localCount = 1;
			}
		}
		if (numb == 0)
		{
			std::cout << numbers[0] << " " << count << "\n";
			outFile << numbers[0] << " " << count;
		}
		else
		{
			std::cout << numb << " " << count << "\n";
			outFile << numb << " " << count;
		}
	}
	else
	{
		std::cout << numb << " " << count << "\n";
		outFile << numb  <<  " " << count;
	}
	std::cout << numbers[0];
	system("pause");
	return 0;
}