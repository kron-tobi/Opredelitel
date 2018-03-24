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
		{ 7, 8, 9, 0, 123 },
		{ 3, 4, 5, 0, 9 }
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
		delim2(matr, s, saveDel);
		printMatrix(matr);
		for (int k = s + 1; k < n; k++)
		{
			vichitaem(matr, s, k);
		}			
	}
	printMatrix(matr);
	cout << "\n" << setprecision(5) << opredelitel(matr, saveDel, step) << endl;	
	
	system("pause");
	return 0;
}
// �������, ������, ��������(� ������ �������� �������� ������ ����.)
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
// �������, ������, ����� ������ ������, �������� �������� l(line) � �(column)
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
// ����� ������� �������� 
void perestanovka(float matr[n][m], int whatColumn1, int whatColumn2, int whatLine, int &step)
{
	float valuePerenos = 0;
	cout << "\nPerestanovka" << endl;
	// ���� 1-�� ����� � 1-�� ������� ������ ��� � �������
	if (matr[whatLine][whatColumn1] < matr[whatLine][whatColumn2]) 
	{
		step *= (-1);
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				//���� ����� ������� ������, �� ���������� ���� ������� 
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
	cout << "______________________" << endl;
	cout << "\n\tPrint" << endl;
	cout << "----------------------" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setprecision(2) << matr[i][j] << "\t";
		}
		cout << endl;
	}
}
// �������, ����� ������ �����, �� ����� ������ �������
void vichitaem(float matr[n][m], int line, int whatLine)
{	
	float saveValue;
	
	saveValue = matr[whatLine][0];
	if (saveValue != 0)
	{
		for (int i = 0; i < n; i++)
		{
			matr[whatLine][i] = matr[whatLine][i] - (matr[line][i] * saveValue);			
		}
		return;
	}
	// ���� ����� �� whatLine == 0, �� ���� ����� �� 0 � ����� ��������
	else if (saveValue == 0)
	{
		for (int j = 0; j < m; j++)
		{
			if (matr[line][j] != 0)
			{
				saveValue = matr[whatLine][j];
				cout << "\nVichitaem iz stroki " << whatLine << ", " << saveValue << "(" << line  << ")" << endl;
				for (int k = 0; k < m; k++)
				{
					matr[whatLine][k] -= (matr[line][k] * saveValue);
				}
				return;
			}
		}
	}	
}
void delim2(float matr[n][m], int line, float &saveDel)
{
	float saveValue = 0;	
	// ���� ������ �������� ���� ( [0] 0 3)
	if (matr[line][0] == 0 && line > 0)
	{
		// ������ ��������� �������� �� ������ ���� ( 0 0 [3])
		for (int j = 0; j < m; j++)
		{
			if (matr[line][j] != 0)
			{
				saveValue = matr[line][j];
				cout << "\nDelim na "  << saveValue << " v " << line << "-ei stroke " << endl;
				saveDel = saveValue * saveDel;
				// ����� ����� �����
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
		cout << "\nDelim na " << saveValue << " v " << line << "-ei stroke " << endl;
		// ����� ������ �������� �� ������ �����, ����� ������ ����� ���� ����� 1
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