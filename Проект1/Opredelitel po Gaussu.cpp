#include <iostream>
using namespace std;

int max(int matr[3][3], int line, int beginCount);
void indexElement(int elem, int matr[3][3], int index, int &l, int &c);
void perestanovka(int matr[3][3], int whatColumn1, int whatColumn2, int whatLine);
void printMatrix(int matr[3][3]);
void withoutRemnant(int matr[3][3], int line, int column);

int main()
{
	int matr[3][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 }
	};	
	int maxEl(0), indexMaxEl(0), l(0), c(0);

	maxEl = max(matr, 0, 0);
	cout << "Max[0][]: " << maxEl << endl;
	indexElement(maxEl, matr, 0, l, c);
	cout << "Index Max Element: " << l  << " " << c << endl;
	perestanovka(matr, 0, c, l);
	printMatrix(matr);
	//metodGaussa(matr);
	
	withoutRemnant(matr, 1, 0);
	withoutRemnant(matr, 2, 0);
	printMatrix(matr);

	maxEl = max(matr, 1, 1);
	cout << "Max[1][]: " << maxEl << endl;
	indexElement(maxEl, matr, 1, l, c);
	cout << "Index Max Element: " << l << " " << c << endl;
	perestanovka(matr, 1, c, l);
	printMatrix(matr);

	withoutRemnant(matr, 2, 1);
	printMatrix(matr);

	system("pause");
	return 0;
}
// матрица, строка, перескок(с какого элемента начинать искать макс.)
int max(int matr[3][3], int line, int beginCount)
{
	int maxValue = 0;
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
void indexElement(int maxEl, int matr[3][3], int line, int &l, int &c)
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
void perestanovka(int matr[3][3], int whatColumn1, int whatColumn2, int whatLine)
{
	int valuePerenos;
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
void printMatrix(int matr[3][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cout << matr[i][j] << " ";
		}
		cout << endl;
	}
}
void withoutRemnant(int matr[3][3], int line, int column)
{	
	int delitel;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			// если элемент матрицы делится без остатка. + Пропускаем элемент который передали в ф-ю, + пропускаем ненужные стобцы
			if (matr[line][column] % matr[i][j] == 0 && i != line && j == column)
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
// написать метод по поиску нулей