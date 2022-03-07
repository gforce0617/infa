#include "pch.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct supplier
{
	int num_sec;
	char* company_name;
	char* product_name;
	double cost;
	int count;
};


void print(vector<supplier>& suppliers, int count_pro)
{
	char name[20];
	string name_str;
	cout << "Введите название нужного товара" << endl;
	/*do {
		getline(cin, name_str);
	} while (name_str != " ");
	strcpy(name, name_str.c_str());*/
	cin >> name;
	int i, j;
	char buf[20];
	//buf = new char[20 + 1];
	for (i = 0; i < count_pro; i++)
	{
		/*strcpy(buf, suppliers[i].product_name);
		int length= strlen(suppliers[i].product_name);
		int a;
		a = 0;
		for (j = 0; j < 20; j++)
			if (buf[j] == name[j])
			{
				a++;
				continue;
			}
			else break;
		if(a==length)
			for (i = 0; i < count_pro; i++)
			{
				cout << setw(4) << suppliers[i].num_sec << endl;
				cout << setw(12) << suppliers[i].company_name << endl;
				cout << setw(12) << suppliers[i].product_name << endl;
				cout << setw(4) << suppliers[i].cost << endl;
				cout << setw(4) << suppliers[i].count << endl;
			}
		else
		break;*/
		if (strcmp(name, suppliers[i].product_name) == -1)
			for (i = 0; i < count_pro; i++)
			{
				cout << setw(4) << suppliers[i].num_sec << endl;
				cout << setw(12) << suppliers[i].company_name << endl;
				cout << setw(12) << suppliers[i].product_name << endl;
				cout << setw(4) << suppliers[i].cost << endl;
				cout << setw(4) << suppliers[i].count << endl;
			}
		else
			break;
	}
}

int add(vector<supplier>& suppliers, int count_pro)
{
	//int num_sect;
	char name[20];
	string name_str;
	/*cout << "Введите номер секции" << endl;
	cin >> num_sect;*/
	cout << "Введите название фирмы" << endl;
	/*do {
		getline(cin, name_str);
	} while (name_str != " ");
	strcpy(name, name_str.c_str());*/
	cin >> name;
	supplier buf;
	int a;
	int length;
	if (strlen(name) > 0)
	{
		char name_pro[20];
		a = 0;
		cout << "Введите название товара" << endl;
		cin >> name_pro;
		int i, j;
		int count_prod;
		double cost_prod;
		int num_sect;
		/*for (i = 0; i < count_pro[1]; i++)
		{

			a = 0;
			for (j = 0; j < 20; j++)
				if (name_cpy == suppliers[i].product_name)
				{
					a++;
					continue;
				}
				else break;
			if (a == length)
			{

				cout << "Введите кол-во товара" << endl;
				cin >> count_prod;


			}
		}*/
		if(count_pro>0)
			for (i = 0; i < count_pro; i++)
			{
				if (strcmp(name_pro, suppliers[i].product_name) == -1)
				{
					cout << "Введите кол-во товара" << endl;
					cin >> count_prod;
					suppliers[i].count += count_prod;
					a++;
				}
			}
		if (a == 0)
		{
			cout << "Введите кол-во товара" << endl;
			cin >> count_prod;
			cout << "Введите цену товара" << endl;
			cin >> cost_prod;
			cout << "Введите номер секции" << endl;
			cin >> num_sect;
			buf.company_name = name;
			buf.product_name = name_pro;
			buf.cost = cost_prod;
			buf.count = count_prod;
			buf.num_sec = num_sect;
			count_pro++;
			suppliers.push_back(buf);
		}
	}
	 	cout << setw(4) << suppliers[i].num_sec;
		cout << setw(12) << suppliers[i].company_name ;
		cout << setw(12) << suppliers[i].product_name;
		cout << setw(4) << suppliers[i].cost;
		cout << setw(4) << suppliers[i].count << endl;
	
	return count_pro;
}

void found(vector<supplier>& suppliers, int count_pro)
{
	int num_sect;
	int i,a=0,j;
	cout << "Введите номер нужной секции" << endl;
	cin >> num_sect;
	for (i = 0; i < count_pro; i++)
	{
		if (suppliers[i].num_sec == num_sect)
			a++;
	}
	supplier* buf;
	supplier x;
	buf = new supplier[a];
	int k = 0;
	for (i = 0; i < count_pro; i++)
	{
		if (suppliers[i].num_sec == num_sect)
		{
			buf[k] = suppliers[i];
			k++;
		}
	}
	/*char str_1[20],str_2[20],str_buf[20];*/
	for (i = 0; i < count_pro; i++)
	{
		for (j = count_pro; j > i; j--)
		{
			for (a = 0; a < 20; a++)
			{
				if (buf[j - 1].product_name[k] > buf[j].product_name[k])
				{
					x = buf[j - 1];
					buf[j - 1] = buf[j];
					buf[j] = x;
				}
			}
				
		}
	}
	for (i = 0; i < k; i++)
	{
		cout << setw(4) << buf[i].num_sec << endl;
		cout << setw(12) << buf[i].company_name << endl;
		cout << setw(12) << buf[i].product_name << endl;
		cout << setw(4) << buf[i].cost << endl;
		cout << setw(4) << buf[i].count << endl;
	}

}

int main()
{
	setlocale(LC_ALL, "RUS");
	int var;
	int count_pro=0;
	char var_1;
	vector<supplier> suppliers;
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
		case 1: {count_pro=add(suppliers, count_pro); break; }
		case 2: {print(suppliers, count_pro); break; }
		case 3: {found(suppliers, count_pro); break; }
		case 4: {return 0; }
		}
		cout << "продолжить работу y/n" << endl;
		cin >> var_1;
	} while (var_1 != 'n');

}
