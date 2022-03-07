#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int N = 3;

struct supplier
{
	int num_sec;
	string company_name;
	string product_name;
	double cost;
	int count;
};

void add(supplier* suppliers)
{
	char name[20];
	char name_pro[20];
	int i, j,count_pro,num_sect,a=0;
	double cost_pro;
	string name_pro_cpy;
	string name_com_cpy;
	for (i = 0; i < N; i++)
	{
		a = 0;
		cout << "Введите название фирмы" << endl;
		cin >> name;
		cout << "Введите название товара" << endl;
		cin >> name_pro;
		for (j = 0; j < N; j++)
		{
			name_pro_cpy = suppliers[j].product_name;
			name_com_cpy = suppliers[j].company_name;
			if(name_com_cpy.find(name)==0)
				if (name_pro_cpy.find(name_pro) == 0)			
				{
					cout << "Введите кол-во товара" << endl;
					cin >> count_pro;
					suppliers[j].count += count_pro;
					a++;

					cout << setw(4) << suppliers[j].num_sec;
					cout << setw(12) << suppliers[j].company_name;
					cout << setw(12) << suppliers[j].product_name;
					cout << setw(4) << suppliers[j].cost;
					cout << setw(4) << suppliers[j].count << endl;

					break;
				}
			
		}
		if (a != 0)
			continue;
		cout << "Введите кол-во товара" << endl;
		cin >> count_pro;
		cout << "Введите цену товара" << endl;
		cin >> cost_pro;
		cout << "Введите номер секции" << endl;
		cin >> num_sect;
		suppliers[i].num_sec = num_sect;
		suppliers[i].company_name = name;
		suppliers[i].product_name = name_pro;
		suppliers[i].cost = cost_pro;
		suppliers[i].count = count_pro;

		cout << setw(4) << suppliers[i].num_sec;
		cout << setw(12) << suppliers[i].company_name;
		cout << setw(12) << suppliers[i].product_name;
		cout << setw(4) << suppliers[i].cost;
		cout << setw(4) << suppliers[i].count << endl;
	}

}

void print(supplier* suppliers)
{
	char name[20];
	char name_pro[20];
	int i;
	string name_pro_cpy;
	string name_com_cpy;
	cout << "Введите название нужной фирмы" << endl;
	cin >> name;
	cout << "Введите название нужного товара" << endl;
	cin >> name_pro;
	for (i = 0; i < N; i++)
	{
		name_pro_cpy = suppliers[i].product_name;
		name_com_cpy = suppliers[i].company_name;
		if (name_com_cpy.find(name) == 0)
			if (name_pro_cpy.find(name_pro) == 0)
			{
				cout << setw(4) << suppliers[i].num_sec;
				cout << setw(12) << suppliers[i].company_name;
				cout << setw(12) << suppliers[i].product_name;
				cout << setw(4) << suppliers[i].cost;
				cout << setw(4) << suppliers[i].count << endl;
			}
	}
}

void found(supplier* suppliers)
{
	int i,a=0;
	supplier* mas;
	int num_sect;
	cout << "Введите номер нужной секции" << endl;
	cin >> num_sect;
	for (i = 0; i < N; i++)
		if (suppliers[i].num_sec == num_sect)
			a++;
	mas = new supplier[a];

	for (i = 0; i < N; i++)
		if (suppliers[i].num_sec == num_sect)
		{
			mas[i] = suppliers[i];
		}
	
	for (int i = 0; i < a; i++) 
	{
		for (int j = i + 1; j < a; j++) 
		{
			char name_pro_1[20], name_pro_2[20];
			strcpy(name_pro_1, mas[i].product_name.c_str());
			strcpy(name_pro_2, mas[j].product_name.c_str());
			if (strcmp(name_pro_1, name_pro_2) > 0)
			{
				supplier tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;
			}
		}
	}
	for (i = 0; i < a; i++)
	{
		cout << setw(4) << mas[i].num_sec;
		cout << setw(12) << mas[i].company_name;
		cout << setw(12) << mas[i].product_name;
		cout << setw(4) << mas[i].cost;
		cout << setw(4) << mas[i].count << endl;
	}

}

int main()
{
	setlocale(LC_ALL, "RUS");
	supplier* suppliers;
	suppliers = new supplier[N];
	
	int var;
	char var_1;
	int min_count, i;
	do
	{
		cout << "Добавить новый товар               1" << endl;
		cout << "Распечатать информацию о товаре    2" << endl;
		cout << "Найти товар выбранной секции       3" << endl;
		cout << "Выход из программы                 4" << endl;
		cout << "Введите номер функции" << endl;
		cin >> var;

		switch (var)
		{
		case 1: {add(suppliers); break; }
		case 2: {print(suppliers); break; }
		case 3: {found(suppliers); break; }
		case 4: {return 0; }
		}
		cout << "Введите мин кол-во товара" << endl;
		cin >> min_count;
		for (i = 0; i < N; i++)
		{
			if (suppliers[i].count < min_count) 
			{
				cout << setw(4) << suppliers[i].num_sec;
				cout << setw(12) << suppliers[i].company_name;
				cout << setw(12) << suppliers[i].product_name;
				cout << setw(4) << suppliers[i].cost;
				cout << setw(4) << suppliers[i].count << endl;
			}
		}
		cout << "продолжить работу y/n" << endl;
		cin >> var_1;
	} while (var_1 != 'n');
}
