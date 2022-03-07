#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;


struct date
{
	int num;
	int month;
	int year;
}dat;

struct supplier
{
	int num_sec;
	string company_name;
	string product_name;
	double cost;
	int count;
	struct date dat;
};



void add(supplier* suppliers,int &N)
{
	char name[20];
	char name_pro[20];
	int i, j, count_pro, num_sect, a = 0;
	double cost_pro;
	string name_pro_cpy;
	string name_com_cpy;
	date date;
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
			if (name_com_cpy.find(name) == 0)
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
					cout << setw(4) << suppliers[j].count;
					cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;

					break;
				}

		}
		if (a != 0)
			continue;
		int num_d, num_y, moun;
		cout << "Введите кол-во товара" << endl;
		cin >> count_pro;
		cout << "Введите цену товара" << endl;
		cin >> cost_pro;
		cout << "Введите номер секции" << endl;
		cin >> num_sect;
		cout << "Введите дату поставки" << endl;
		cin >> num_d;
		cin >> moun;
		cin >> num_y;
		date.num = num_d;
		date.month = moun;
		date.year = num_y;
		suppliers[i].num_sec = num_sect;
		suppliers[i].company_name = name;
		suppliers[i].product_name = name_pro;
		suppliers[i].cost = cost_pro;
		suppliers[i].count = count_pro;
		suppliers[i].dat = date;

		cout << setw(4) << suppliers[i].num_sec;
		cout << setw(12) << suppliers[i].company_name;
		cout << setw(12) << suppliers[i].product_name;
		cout << setw(4) << suppliers[i].cost;
		cout << setw(4) << suppliers[i].count;
		cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
	}
}

void print(supplier* suppliers, int &N)
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
				cout << setw(4) << suppliers[i].count;
				cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
			}
	}
}

void found(supplier* suppliers, int &N)
{
	int i, a = 0;
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
		cout << setw(4) << mas[i].count;
		cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;

	}

}

void found_pro(supplier* suppliers, int &N)
{
	int i;
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	/*cout << setw(3) << tim->tm_mday << setw(3) << tim->tm_mon+1 << setw(5) << tim->tm_year+1900;*/
	for (i = 0; i < N; i++)
	{
		if (suppliers[i].dat.year < tim->tm_year + 1900)
		{
			if (suppliers[i].dat.month == tim->tm_mon + 1)
			
				if (suppliers[i].dat.num < tim->tm_mday)
				{
					cout << setw(4) << suppliers[i].num_sec;
					cout << setw(12) << suppliers[i].company_name;
					cout << setw(12) << suppliers[i].product_name;
					cout << setw(4) << suppliers[i].cost;
					cout << setw(4) << suppliers[i].count;
					cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
				}
			if (suppliers[i].dat.month < tim->tm_mon + 1)
			{
				cout << setw(4) << suppliers[i].num_sec;
				cout << setw(12) << suppliers[i].company_name;
				cout << setw(12) << suppliers[i].product_name;
				cout << setw(4) << suppliers[i].cost;
				cout << setw(4) << suppliers[i].count;
				cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
			}
		}

	}
}

void fileRead()
{
	ifstream fin;
	fin.open("1.txt");
	char ch;
	while ((ch = fin.get()) != EOF)
		cout << ch;

}

int main()
{
	setlocale(LC_ALL, "RUS");
	int var, N = 3;
	supplier* suppliers;
	suppliers = new supplier[N];

	//FILE *in/*, *out*/;
	//in = fopen("1.txt", "a+");
	/*out = fopen("2.txt", "w");*/

	
	char var_1;
	int min_count, i;
	int count=0;
	do
	{
		
		cout << "Добавить новый товар               1" << endl;
		cout << "Распечатать информацию о товаре    2" << endl;
		cout << "Найти товар выбранной секции       3" << endl;
		cout << "Найти просроченный товар           4" << endl;
		cout << "Чтение из файла                    5" << endl;
		cout << "Выход из программы                 6" << endl;
		cout << "Введите номер функции" << endl;
		cin >> var;

		switch (var)
		{
		case 1: {add(suppliers, N); break; }
		case 2: {print(suppliers, N); break; }
		case 3: {found(suppliers, N); break; }
		case 4: {found_pro(suppliers, N); break; }
		case 5: {fileRead; break; }
		case 6: {return 0; }
		}

		ofstream fout;
		fout.open("1.txt", ios::out | ios::app);
		for (int i = 0; i < N; i++)
		{
			fout << suppliers[i].num_sec << ' ' << suppliers[i].company_name << ' ' << suppliers[i].product_name << ' ' << suppliers[i].cost << ' ' << suppliers[i].count << ' ' << suppliers[i].dat.num << ' ' << suppliers[i].dat.month << ' ' << suppliers[i].dat.year << endl;

		}
		fout.close();
		if (count == 0)
		{
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
					cout << setw(4) << suppliers[i].count;
					cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
				}
			}
		}
	
		
		count++;
		cout << "продолжить работу y/n" << endl;
		cin >> var_1;
	}while (var_1 != 'n');
}
