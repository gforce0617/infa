#include "pch.h"
#include <iostream>
#include <iomanip>


using namespace std;

int** fun(int** mas, int** ind,int M, int N,int size)
{
	int i, j;
	
	for (i = 0; i < 4; i++)
		for (j = 0; j < size; j++)
			ind[i][j] = -1;
	int a = 0;
	for (j = 0; j < (M/2 + M % 2); j++)
	{
		for (i = 0; i < N; i++)
		{
			if (mas[i][j] > 0)
			{
				ind[0][a] = i;
				ind[1][a] = j;
				a++;
			}
		}
	}
	a= 0;
	for (j = (M / 2 + M % 2); j < M; j++)
	{
		for (i = 0; i < N; i++)
		{
			if (mas[i][j] < 0)
			{
				ind[2][a] = i;
				ind[3][a] = j;
				a++;
			}
		}
	}
	
	
	return ind;

}

int main()
{
	int N, M;
	int size;
	cin >> N>>M;
	int a = 0;
	int i, j;
	srand(time(NULL));
	int **ind = (int **)malloc(4 * sizeof(int *));
	size = N * M;
	for (i = 0; i < 4; i++)
	{
		ind[i] = (int *)malloc(N*M * sizeof(int));
	}

	int **mas = (int **)malloc(size * sizeof(int *));
	for (i = 0; i < size; i++)
	{
		mas[i] = (int *)malloc(size * sizeof(int));
	}
	for (i = 0; i < N; i++)
	{
		cout << endl;
		for (j = 0; j < M; j++)
		{
			mas[i][j] = rand() % 100-50;
			cout << setw(5) << mas[i][j];
		}
	}
	fun(mas, ind,M,N,size);
	for (i = 0; i < 4; i++)
	{
		cout << endl;
		for (j = 0; j < size; j++)
		{
			if (ind[i][j] != -1)
				cout << ind[i][j] << " ";
		}
	}

}
