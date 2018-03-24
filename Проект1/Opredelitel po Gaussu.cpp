#include <iostream>
#include <iomanip> 
using namespace std;

const int n = 5;
const int m = 5;
float max(float matr[n][m], int line, int beginCount);
void indexElement(float maxEl, float matr[n][m], int line, int beginCount, int &l, int &c);
void perestanovka(float matr[n][m], int whatColumn1, int whatColumn2, int whatLine, int &step);
void printMatrix(float matr[n][m]);
//void withoutRemnant(float matr[3][3], int line, int column);
//void delim(float matr[n][m], int line, float &saveDel);
void vichitaem(float matr[n][m], int line, int whatLine);
void delim2(float matr[n][m], int line, float &saveDel);
float opredelitel(float matr[n][m], float &saveDel, int &step);

int main()
{
	float matr[n][m] = {
		{ 1, 2, 3, 4, 5 },
		{ 6, 7, 8, 9, 1 },
		{ 2, 3, 4, 5, 6 },
		{ 7, 8, 9, 1, 2 },
		{ 3, 4, 5, 6, 7 }
	};	
	float maxEl(0), saveDel(0);
	int indexMaxEl(0), l(0), c(0), step(1);

	for (int s = 0; s < n - 1; s++)
	{
		printMatrix(matr);
		maxEl = max(matr, s, s);
		cout << "\nMax[" << s << "][]: " << maxEl << endl;
		indexElement(maxEl, matr, s, s, l, c);
		cout << "\nIndex Max Element: " << l << " " << c << endl;
		if (maxEl == 0)
		{
			break;
		}
		perestanovka(matr, s, c, l, step);
		printMatrix(matr);
		/*if (i == 0)
			delim(matr, i, saveDel);
		if (i == 1)
			delim2(matr, 1, saveDel);*/
		delim2(matr, s, saveDel);
		printMatrix(matr);
		for (int k = s + 1; k < n; k++)
		{
			vichitaem(matr, s, k);
		}			
	}
	printMatrix(matr);
	cout << "\n" << setprecision(3) << opredelitel(matr, saveDel, step) << endl;
	//printMatrix(matr);
	//maxEl = max(matr, 0, 0);
	//cout << "\nMax[0][]: " << maxEl << endl;
	//indexElement(maxEl, matr, 0, l, c);
	//cout << "\nIndex Max Element: " << l  << " " << c << endl;
	//perestanovka(matr, 0, c, l, step);
	//printMatrix(matr);
	//delim(matr, 0, saveDel);
	//printMatrix(matr);
	//vichitaem(matr, 0, 1);
	//vichitaem(matr, 0, 2);
	//printMatrix(matr);

	/*maxEl = max(matr, 1, 1);
	cout << "\nMax[1][]: " << maxEl << endl;
	indexElement(maxEl, matr, 1, l, c);
	cout << "\nIndex Max Element: " << l << " " << c << endl;
	perestanovka(matr, 1, c, l, step);
	printMatrix(matr);
	delim2(matr, 1, saveDel);
	printMatrix(matr);
	vichitaem(matr, 1, 2);
	printMatrix(matr);
	cout << "\n" << setprecision(4) << opredelitel(matr, saveDel, step) << endl;
	*/
	
	system("pause");
	return 0;
}
// матрица, строка, перескок(с какого элемента начинать искать макс.)
float max(float matr[n][m], int line, int beginCount)
{
	float maxValue = matr[line][beginCount];
	for (int i = 0; i < n; i++)
	{
		for (int j = beginCount; j < m; j++)
		{
			if (i == line && maxValue < matr[i][j])
			{
				maxValue = matr[i][j];
			}
		}
	}
	return maxValue;
}
// элемент, массив, номер строки поиска, изменяем значение l(line) и с(column)
void indexElement(float maxEl, float matr[n][m], int line, int beginCount, int &l, int &c)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = beginCount; j < m; j++)
		{
			if (i == line && maxEl == matr[i][j])
			{		
				l = i;
				c = j;	
				return;
			}
		}
	}	
}
// какие столбцы поменять 
void perestanovka(float matr[n][m], int whatColumn1, int whatColumn2, int whatLine, int &step)
{
	float valuePerenos = 0;
	cout << "\nPerestanovka" << endl;
	// если 1-ое число в 1-ом столбце меньше чем у другого
	if (matr[whatLine][whatColumn1] < matr[whatLine][whatColumn2]) 
	{
		step *= (-1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//если номер столбца совпал, то перемещаем этот столбец 
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
void printMatrix(float matr[n][m])
{
	cout << "\nPrint" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setprecision(2) << matr[i][j] << "\t";
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
/*void delim(float matr[n][m], int line, float &saveDel)
{
// делим чтобы в первый раз

	float saveValue = 0;
	
	for (int i = 0; i < n; i++)
	{
		// если мы в нужной строке
		if (i == line)
		{
			// если первое значение в строке не ноль
			if (matr[line][0] != 0)
			{
				saveValue = matr[line][0];
				saveDel = saveValue;
				// делим каждое значение на первое число
				for (int j = 0; j < m; j++)
				{
					matr[line][j] = matr[line][j] / saveValue;
				}
			}			
		}		
	}
}*/
// матрица, какую строку взять, из какой строки вычесть
void vichitaem(float matr[n][m], int line, int whatLine)
{	
	float saveValue = 0;
	cout << "\nVichitaem" << endl;
	saveValue = matr[whatLine][0];
	if (saveValue != 0)
	{
		for (int i = 0; i < n; i++)
		{
			matr[whatLine][i] = matr[whatLine][i] - (matr[line][i] * saveValue);			
		}
		return;
	}
	// если число из whatLine == 0, то надо найти не 0 и потом вычитать
	else if (saveValue == 0)
	{
		for (int j = 0; j < m; j++)
		{
			if (matr[line][j] != 0)
			{
				saveValue = matr[whatLine][j];
				//cout << "\nsaveValue = " << saveValue << endl;
				for (int k = 0; k < m; k++)
				{
					matr[whatLine][k] = matr[whatLine][k] - (matr[line][k] * saveValue);
				}
				return;
			}
		}
	}	
}
void delim2(float matr[n][m], int line, float &saveDel)
{
	float saveValue = 0;
	cout << "\nDelim" << endl;
	// если первое значение ноль ( [0] 0 3)
	if (matr[line][0] == 0 && line > 0)
	{
		// найдем следующее значение не равное нулю ( 0 0 [3])
		for (int j = 0; j < m; j++)
		{
			if (matr[line][j] != 0)
			{
				saveValue = matr[line][j];
				saveDel = saveValue * saveDel;
				// когда нашли делим
				for (int k = 0; k < m; k++)
				{
					matr[line][k] = matr[line][k] / saveValue;
				}
				return;
			}
			
		}
	}
	if (line == 0)
	{
		saveValue = matr[line][0];
		saveDel = saveValue;
		// делим каждое значение на первое число, чтобы первое число было равно 1
		for (int j = 0; j < m; j++)
		{
			matr[line][j] = matr[line][j] / saveValue;
		}		
	}
}
float opredelitel(float matr[n][m], float &saveDel, int &step)
{
	float res = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				res *= matr[i][j];
			}
		}
	}
	return res * saveDel * step;
}