#include "pch.h"
#include <iostream>
#include <iomanip>


using namespace std;

int** fun(int** mas,int ** ind,int size)
{	
	int i, j;
	for (i = 0; i < 4; i++)
		for (j = 0; j < (size*size); j++)
			ind[i][j] = -1;
	int max = -1, min = 101;
	
	for (j = 0; j < (size / 2 + size % 2); j++)
	{
		for (i = 0; i < size; i++)
		{
			if (mas[i][j] > max)
				max = mas[i][j];
		}
	}
	for (j = (size / 2 + size % 2); j < size; j++)
	{
		for (i = 0; i < size; i++)
		{
			if (mas[i][j] < min)
				min = mas[i][j];
		}
	}
	int a = 0;
	for (j = 0; j < (size / 2 + size % 2); j++)
	{
		for (i = 0; i < size; i++)
			if (mas[i][j] == max)
			{
				ind[0][a] = i;
				ind[1][a] = j;
				a++;
			}
	}
	a = 0;
	for (j = (size / 2 + size % 2); j < size; j++)
	{
		for (i = 0; i < size; i++)
			if (mas[i][j] == min)
			{
				ind[2][a] = i;
				ind[3][a] = j;
				a++;
			}
	}
	return ind;

}

int main()
{
	int size;
	cin >> size;
	int a = 0;
	int i,j;
	srand(time(NULL));
	int size_2 = size * size;
	int **ind = (int **)malloc(4 * sizeof(int *));
	for (i = 0; i < 4; i++)
	{
		ind[i] = (int *)malloc(size_2 * sizeof(int));
	}
	
	int **mas = (int **)malloc(size * sizeof(int *));
	for (i = 0; i < size; i++)
	{
		mas[i] = (int *)malloc(size * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		cout << endl;
		for (j = 0; j < size; j++)
		{
			mas[i][j] = rand()%100;
			cout << setw(5) << mas[i][j];
		}
	}
	fun(mas, ind,size);
	for (i = 0; i < 4; i++)
	{
		cout << endl;
		for (j = 0; j < size_2; j++)
		{
			if (ind[i][j] != -1)
				cout << ind[i][j]<<" ";
		}
	}

}
