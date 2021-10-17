#define _CRT_SECURE_NO_WARNINGS
#include <ctime> // ���������� �������
#include <cmath>
#include <locale.h>
#include <iostream> // ���������� �����,������
#include <conio.h>
//int matrix[20][20]; // �������
int p, i, n;
int** matrix = new int* [n];
bool* visited = new bool[100];
using namespace std;
/*int matrix[6][6] = {
		{0,1,1,0,0,1},
		{1,0,0,1,0,0},
		{1,0,0,0,1,0},
		{0,1,0,0,0,0},
		{0,0,1,0,0,0},
		{1,0,0,0,0,0}
};
*/

void DFS(int st)
{
	int r;
	cout << st + 1 << " ";
	visited[st] = true;
	for (r = 0; r < (n - 1); r++)
		if ((matrix[st][r] != 0) && (!visited[r]))
			DFS(r);
}

void main()
{
	setlocale(LC_ALL, "Russian"); // ����������� ��������
	srand(time(NULL)); // ����� ������ �������



	int start;
	cout << "n="; // ������� ������
	cin >> n; // �������� ������
	//cout << "n=";
	//cin >> n;
	cout << "�������: \n";
	int z;
	for (i = 0; i < n; i++)
	{
		matrix[i] = new int[n];
	}



	for (i = 0; i < n; i++)
	{
		for (p = 0; p < n; p++)
		{
			matrix[i][p] = rand() % 2;
		}
	}


	/*for (int i = 0; i < 10; i++)
		for (j = 0; j < 10; j++)
			matrix[i][j] = rand() % 2;*/



	for (int i = 0; i < n; i++)
	{
		for (p = 0; p < n; p++)
		{

			if (p == i)
			{
				matrix[i][p] = 0;
			}
			else
			{
				matrix[i][p] = matrix[p][i];
			}
		}

	}


	/*for (int i = 0; i < 10; i++)
		for (p = 0; p < 10; p++)
			matrix[i][p] = matrix[p][i];*/

	for (int i = 0; i < 6; i++)
	{
		cout << "\n";
		cout << "{";
		for (p = 0; p < 6; p++)

			if (matrix[i][p] == 1)
			{
				cout << p << " ";

			}
		cout << "}" << "   �������" << i;
	}

	cout << "\n";
	cout << "\n";
	for (i = 0; i < n; i++)
	{
		visited[i] = false;
		for (p = 0; p < n; p++)
			cout << matrix[i][p] << " "; // ������� �������
		cout << endl;
	}

	cout << "��������� ������� � "; cin >> start;
	bool* vis = new bool[n];
	cout << "������� ������: ";
	DFS(start - 1);
	delete[]visited;
	system("pause�void");
	_getch();
}
