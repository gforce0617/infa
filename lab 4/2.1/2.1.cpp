#include<iostream> 
#include<locale> 
#include<cstdlib> 
#include<ctime> 
#include<iomanip> 

using namespace std;

#define N 10 
#define M 15 

void init_array(int *, int);
void replac_elements(int *, int, int **);
int **pointers_array(int *, int, int *[]);

int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "Rusian");

	int x[N], y[M], *z[M + 1];
	int *ptr_x = x, *ptr_y = y, **ptr_z = nullptr;

	cout << "Массив X:" << endl;
	init_array(ptr_x, N);
	cout << "Массив Y:" << endl;
	init_array(ptr_y, M);

	cout << "Массив X с заменёнными элементами: " << endl;
	ptr_z = pointers_array(ptr_x, N, z);
	replac_elements(ptr_x, N, ptr_z);

	cout << "Массив Y с заменёнными элементами: " << endl;
	ptr_z = pointers_array(ptr_y, M, z);
	replac_elements(ptr_y, M, ptr_z);

	system("pause");
	return 0;
}
void init_array(int *ptr, int size)
{

	for (int i = 0; i < size; i++)
	{
		*ptr = rand() % 900 + 100;
		cout << setw(5) << *ptr;
		ptr++;
	}
	cout << endl;
}
void replac_elements(int *ptr, int size, int **ptr_z)
{
	while (*ptr_z)
	{
		for (int i = 0; i < size; i++)
		{
			if ((ptr + i) == *ptr_z)
			{
				*(ptr + i) = i + 1;
				break;
			}
		}
		ptr_z++;
	}
	for (int i = 0; i < size; i++)
		cout << setw(5) << *(ptr + i);
	cout << endl;
}
int **pointers_array(int *ptr, int size, int *ptr_z[])
{
	int count = 0, i;

	for (i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if ((*(ptr + i) == *(ptr + j)) && ((ptr + i) != (ptr + j)))
			{
				*(ptr_z + count) = ptr + i;
				count++;
				break;
			}
		}


	}
	*(ptr_z + count) = nullptr;

	return ptr_z;
}
