#include <iostream>
using namespace std;

float max(float matr[3][3], int line, int beginCount);
void indexElement(float maxEl, float matr[3][3], int index, int &l, int &c);
void perestanovka(float matr[3][3], int whatColumn1, int whatColumn2, int whatLine);
void printMatrix(float matr[3][3]);
//void withoutRemnant(float matr[3][3], int line, int column);
void delim(float matr[3][3], int line);
void vichitaem(float matr[3][3], int line, int whatLine);
void delim2(float matr[3][3], int line);
float opredelitel(float matr[3][3]);

int main()
{
	float matr[3][3] = {
		{ 4, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};	
	float maxEl(0);
	int indexMaxEl(0), l(0), c(0);

	maxEl = max(matr, 0, 0);
	cout << "Max[0][]: " << maxEl << endl;
	indexElement(maxEl, matr, 0, l, c);
	cout << "Index Max Element: " << l  << " " << c << endl;
	perestanovka(matr, 0, c, l);
	printMatrix(matr);
	delim(matr, 0);
	printMatrix(matr);
	vichitaem(matr, 0, 1);
	vichitaem(matr, 0, 2);
	printMatrix(matr);
	maxEl = max(matr, 1, 1);
	cout << "Max[1][]: " << maxEl << endl;
	indexElement(maxEl, matr, 1, l, c);
	cout << "Index Max Element: " << l << " " << c << endl;
	perestanovka(matr, 1, c, l);
	printMatrix(matr);
	delim2(matr, 1);
	printMatrix(matr);
	vichitaem(matr, 1, 2);
	printMatrix(matr);
	cout << "\n" << opredelitel(matr) << endl;
	/*withoutRemnant(matr, 1, 0);
	withoutRemnant(matr, 2, 0);
	printMatrix(matr);

	maxEl = max(matr, 1, 1);
	cout << "Max[1][]: " << maxEl << endl;
	indexElement(maxEl, matr, 1, l, c);
	cout << "Index Max Element: " << l << " " << c << endl;
	perestanovka(matr, 1, c, l);
	printMatrix(matr);

	withoutRemnant(matr, 2, 1);
	printMatrix(matr);*/
	
	system("pause");
	return 0;
}
// матрица, строка, перескок(с какого элемента начинать искать макс.)
float max(float matr[3][3], int line, int beginCount)
{
	float maxValue = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = beginCount; j < 3; j++)
		{
			if (maxValue < matr[i][j] && i == line)
			{
				maxValue = matr[i][j];
			}
		}
	}
	return maxValue;
}
// элемент, массив, номер строки поиска, изменяем значение l(line) и с(column)
void indexElement(float maxEl, float matr[3][3], int line, int &l, int &c)
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (maxEl == matr[i][j] && i == line)
			{		
				l = i;
				c = j;	
				return;
			}
		}
	}	
}
// какие столбцы поменять 
void perestanovka(float matr[3][3], int whatColumn1, int whatColumn2, int whatLine)
{
	float valuePerenos = 0;
	// если 1-ое число в 1-ом столбце меньше чем у другого
	if (matr[whatLine][whatColumn1] < matr[whatLine][whatColumn2]) 
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				//если номер столбца совпал, 
				if (j == whatColumn1)
				{
					valuePerenos = matr[i][j];
					matr[i][j] = matr[i][whatColumn2];
					matr[i][whatColumn2] = valuePerenos;
				}
			}
		}
	}	
}
void printMatrix(float matr[3][3])
{
	cout << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matr[i][j] << "\t";
		}
		cout << endl;
	}
}
/*void withoutRemnant(float matr[3][3], int line, int column)
{	
	int delitel;

	for (int i = 2; i > -1; i--)
	{
		for (int j = 0; j < 3; j++)
		{		
			// чтобы исключить деление на 0
			if (matr[i][j] == 0)
			{
				j++;
			}
			// если элемент матрицы делится без остатка. + Пропускаем элемент который передали в ф-ю, + пропускаем ненужные стобцы
			if (matr[line][column] % matr[i][j] == 0)
			{
				if (i != line && j == column)
				{
					delitel = matr[line][column] / matr[i][j];
					cout << "Znach. na kot. mogno delit bez ostatka: " << matr[i][j] << endl;
					cout << "Index znach.: " << i << endl;
					for (int k = 0; k < 3; k++)
					{
						matr[line][k] -= (matr[i][k] * delitel);
					}
					return;
				}
			}
		}

	}
		
}*/
void delim(float matr[3][3], int line)
{
	float saveValue = 0;
	for (int i = 0; i < 3; i++)
	{
		// если мы в нужной строке
		if (i == line)
		{
			// если первое значение в строке не ноль
			if (matr[line][0] != 0)
			{
				saveValue = matr[line][0];
				// делим каждое значение на первое число
				for (int j = 0; j < 3; j++)
				{
					matr[line][j] = matr[line][j] / saveValue;
				}
			}			
		}		
	}
}
// матрица, какую строку взять, из какой строки вычесть
void vichitaem(float matr[3][3], int line, int whatLine)
{
	//тут ошибка!!! коро
	float saveValue = 0;
	saveValue = matr[whatLine][0];
	if (saveValue != 0)
	{
		for (int i = 0; i < 3; i++)
		{
			matr[whatLine][i] = matr[whatLine][i] - (matr[line][i] * saveValue);			
		}
		return;
	}
	// если число из whatLine == 0, то надо найти не 0 и потом вычитать
	else if (saveValue == 0)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matr[line][j] != 0)
			{
				saveValue = matr[whatLine][j];
				cout << "\nsaveValue = " << saveValue << endl;
				for (int i = 0; i < 3; i++)
				{
					matr[whatLine][i] = matr[whatLine][i] - (matr[line][i] * saveValue);
				}
				return;
			}
		}
	}
	/*
	for (int i = 0; i < 3; i++)
	{
		// исключаем
		if (i != line)
		{
			saveValue = matr[i][0];
			for (int j = 0; j < 3; j++)
			{
				matr[i][j] = matr[i][j] - (matr[line][j] * saveValue);
			}
			// вычитаем во 2-ой, n 1-ых строк 

		}
	}*/
}
void delim2(float matr[3][3], int line)
{
	float saveValue = 0;
	// если первое значение ноль
	if (matr[line][0] == 0)
	{
		// найдем следующее значение не равное нулю
		for (int i = 0; i < 3; i++)
		{
			if (matr[line][i] != 0)
			{
				saveValue = matr[line][i];
				// когда нашли делим
				for (int j = 0; j < 3; j++)
				{
					matr[line][j] = matr[line][j] / saveValue;
				}
				return;
			}
		}
	}
}
float opredelitel(float matr[3][3])
{
	float res = 1;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (i == j)
			{
				res *= matr[i][j];
			}
		}
	}
	return res;
}