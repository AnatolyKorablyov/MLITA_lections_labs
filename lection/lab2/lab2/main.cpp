#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int CalculateGryadka(std::vector<std::string> matrix)
{
	int countGryadka = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[i].length(); j++)
		{
			if (matrix[i][j] == '#')
			{
				if (i > 0)
				{
					if (matrix[i - 1][j] != '#')
					{
						if (j > 0)
						{
							if (matrix[i][j - 1] != '#' && matrix[i - 1][j - 1] != '#')
							{
								if (j < matrix[i].length() - 1)
								{
									if (matrix[i - 1][j + 1] != '#')
									{
										if (i < matrix[i].size() - 1)
										{
											if (matrix[i + 1][j - 1] != '#')
											{
												countGryadka += 1;
											}
										}
										else
										{
											countGryadka += 1;
										}
									}
								}
								else
								{
									countGryadka += 1;
								}
							}
						}
						else
						{
							if (j < matrix[i].length() - 1)
							{
								if (matrix[i - 1][j + 1] != '#')
								{
									countGryadka += 1;
								}
							}
							else
							{
								countGryadka += 1;
							}
						}
					}
				}
				else
				{
					if (j > 0) 
					{
						if (matrix[i][j - 1] != '#')
						{
							if (i < matrix[i].size() - 1)
							{
								if (matrix[i + 1][j - 1] != '#')
								{
									countGryadka += 1;
								}
							}
							else
							{
								countGryadka += 1;
							}
						}

					}
					else
						countGryadka += 1;
				}
			}
		}
	}
	return countGryadka;
}

void Application(const std::string & inputFileName, const std::string & outputFileName)
{
	std::ifstream inpFile(inputFileName);
	if (!inpFile.is_open()) 
	{
		std::cout << "Error open file\n";
		system("pause");
		exit(1);
	}
	std::string string;
	std::ofstream outFile(outputFileName);
	bool firstStr = true;
	int lengthWidth = 0;
	int lengthDepth = 0;
	int countGRYADKA = 0;
	std::vector<std::string> matrix;

	while (!inpFile.eof())
	{
		int num = 0;
		std::getline(inpFile, string);
		int  len = string.length();
		if (firstStr) 
		{
			int m_number = 0;
			while (string[num] >= '0' && string[num] <= '9' && num <= len) {
				m_number = m_number * 10 + (string[num] - '0');
				num++;
			}
			lengthWidth = m_number;
			m_number = 0;
			num++;

			while (string[num] >= '0' && string[num] <= '9' && num <= len) {
				m_number = m_number * 10 + (string[num] - '0');
				num++;
			}
			lengthDepth = m_number;
			firstStr = false;
		}
		else
		{
			matrix.push_back(string);
		}
	}
	countGRYADKA = CalculateGryadka(matrix);
	outFile << countGRYADKA;
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