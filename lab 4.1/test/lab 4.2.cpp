#include "pch.h"
#include <iostream>
#include <iomanip>

using namespace std;

int* fun(int* mas,int size)
{
	int *ind = new int[size];
	int i,a=0;
	for (i = 0; i < size; i++)
		ind[i] = -1;

	cout << endl << "out ind,k,l" <<endl;
	int ind1, k, l;
	cin >> ind1 >> k >> l;

	for (i = 0; i < ind1; i++)
	{
		if (mas[i] % k == 0)
		{
			ind[a] = i;
			a++;
		}
	}
	for(i=ind1+1;i<size;i++)
		if (mas[i] % l == 0)
		{
			ind[a] = i;
			a++;
		}
	return ind;
}

int main()
{
	int size;
	cin >> size;
	int a = 0;
	
	int *ind = new int[size];

	int *mas=new int[size];
	int i;
	srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		mas[i] = rand() % 90+10;
		cout << setw(3) << mas[i];
	}
	ind=fun(mas,size);
	while (ind[a] != -1)
	{
		cout << ind[a]<<"  ";
		a++;
	}


}
