#include "pch.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct supplier
{
	int num_sec;
	string company_name;
	string product_name;
	double cost;
	int quantity;
	struct date
	{
		int num;
		string month;
		int year;
	}dat;
};

void mainMenu(supplier* suppliers, int &N);
void create_new_sup(supplier* suppliers,int &N);
void saveData(supplier* suppliers, supplier new_suppliers, int check, int &N);
void loadData(supplier* suppliers, int &N);
void push_back(supplier* suppliers,int &N,supplier new_suppliers,int check);
int check_coincidence(supplier new_suppliers, supplier* suppliers, int &N);
void print(supplier* suppliers, int &N);
void found(supplier* suppliers, int &N);
void found_pro(supplier* suppliers, int &N);
int convert_month(supplier* suppliers, int &N,int i);
void fount_min_quintity(supplier* suppliers,int &N);

int main()
{
	setlocale(LC_ALL, "RUS");
	int N = 0;
	supplier* suppliers;
	suppliers = new supplier[N];
	loadData(suppliers,N);
	mainMenu(suppliers, N);

}

void mainMenu(supplier* suppliers, int &N)
{
	int var,i;
	while (true)
	{
		cout << "Добавить новый товар                     1" << endl;
		cout << "Распечатать информацию о товаре          2" << endl;
		cout << "Найти товар выбранной секции             3" << endl;
		cout << "Найти просроченный товар                 4" << endl;
		cout << "Найти товары больше мин кол-ва           5" << endl;
		cout << "Выход из программы                       6" << endl;
		 
		cout << "Введите номер функции" << endl;
		cin >> var;

		switch (var)
		{
		case 1: {create_new_sup(suppliers, N); break; }
		case 2: {print(suppliers, N); break; }
		case 3: {found(suppliers, N); break; }
		case 4: {found_pro(suppliers, N); break; }
		case 5: {fount_min_quintity(suppliers, N); break; }
		case 6: { exit(0); }
		}
		
	}
}

void create_new_sup(supplier* suppliers, int &N)
{
	supplier new_suppliers;
	int check;

	cout << "Введите название фирмы" << endl;
	cin >> new_suppliers.company_name;
	
	cout << "Введите название товара" << endl;
	cin >> new_suppliers.product_name;

	cout << "Введите кол-во товара" << endl;
	cin >> new_suppliers.quantity;

	cout << "Введите цену товара" << endl;
	cin >> new_suppliers.cost;

	cout << "Введите номер секции" << endl;
	cin >> new_suppliers.num_sec;

	cout << "Введите дату поставки. в месяце первые 3 буквы" << endl;
	cin >> new_suppliers.dat.num;
	cin >> new_suppliers.dat.month;
	cin >> new_suppliers.dat.year;

	check=check_coincidence(new_suppliers,suppliers,N);

	saveData(suppliers,new_suppliers,check,N);

	push_back(suppliers, N, new_suppliers,check);
}

int check_coincidence(supplier new_suppliers,supplier* suppliers, int &N)
{
	int i,check=-1;
	string name_pro_cpy, name_com_cpy;
	for (i = 0; i < N; i++)
	{	
		name_pro_cpy = suppliers[i].product_name;
		name_com_cpy = suppliers[i].company_name;
		if (name_com_cpy.find(new_suppliers.company_name) == 0)
			if (name_pro_cpy.find(new_suppliers.product_name) == 0)
				check = i;
	}
	return check;
}

void push_back(supplier* suppliers, int &N, supplier new_suppliers, int check)
{
	if (check == -1)
	{
		supplier *newArray = new supplier[N + 1];
		for (int i = 0; i < N; i++)
		{
			newArray[i] = suppliers[i];
		}

		newArray[N++] = new_suppliers;

		delete[] suppliers;

		suppliers = newArray;
		N++;
	}
	if (check >= 0)
	{
		suppliers[check].quantity += new_suppliers.quantity;
	}
}


void print(supplier* suppliers, int &N)
{
	
	string name_com,name_pro;
	int i;
	/*cout << "Введите название нужной фирмы" << endl;
	cin >> name_com;
	cout << "Введите название нужного товара" << endl;
	cin >> name_pro;*/
	for (i = 0; i < N; i++)
	{
		/*if (suppliers[i].company_name.find(name_com) == 0)
			if (suppliers[i].product_name.find(name_pro) == 0)
			{
				cout << setw(4) << suppliers[i].num_sec;
				cout << setw(12) << suppliers[i].company_name;
				cout << setw(12) << suppliers[i].product_name;
				cout << setw(4) << suppliers[i].cost;
				cout << setw(4) << suppliers[i].quantity;
				cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
			}*/
		cout << setw(4) << suppliers[i].num_sec;
		cout << setw(12) << suppliers[i].company_name;
		cout << setw(12) << suppliers[i].product_name;
		cout << setw(4) << suppliers[i].cost;
		cout << setw(4) << suppliers[i].quantity;
		cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
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
		cout << setw(4) << mas[i].quantity;
		cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;

	}

}

void found_pro(supplier* suppliers, int &N)
{
	int i,month;
	struct tm *tim;
	time_t tt = time(NULL);
	tim = localtime(&tt);
	for (i = 0; i < N; i++)
	{
		if (suppliers[i].dat.year < tim->tm_year + 1900)
		{
			month = convert_month(suppliers, N, i);
			if (month == tim->tm_mon + 1)
			{
				if (suppliers[i].dat.num < tim->tm_mday)
				{
					cout << setw(4) << suppliers[i].num_sec;
					cout << setw(12) << suppliers[i].company_name;
					cout << setw(12) << suppliers[i].product_name;
					cout << setw(4) << suppliers[i].cost;
					cout << setw(4) << suppliers[i].quantity;
					cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
				}
			}
			if (month < tim->tm_mon + 1)
			{
				cout << setw(4) << suppliers[i].num_sec;
				cout << setw(12) << suppliers[i].company_name;
				cout << setw(12) << suppliers[i].product_name;
				cout << setw(4) << suppliers[i].cost;
				cout << setw(4) << suppliers[i].quantity;
				cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
			}
		}

	}
}

int convert_month(supplier* suppliers, int &N,int i)
{
	int month=0;

	if (suppliers[i].dat.month == "jan")
		month == 1;
	if (suppliers[i].dat.month == "feb")
		month == 2;
	if (suppliers[i].dat.month == "mar")
		month == 3;
	if (suppliers[i].dat.month == "apr")
		month == 4;
	if (suppliers[i].dat.month == "may")
		month == 5;
	if (suppliers[i].dat.month == "jun")
		month == 6;
	if (suppliers[i].dat.month == "jul")
		month == 7;
	if (suppliers[i].dat.month == "aug")
		month == 8;
	if (suppliers[i].dat.month == "sep")
		month == 9;
	if (suppliers[i].dat.month == "oct")
		month == 10;
	if (suppliers[i].dat.month == "nov")
		month == 11;
	if (suppliers[i].dat.month == "dec")
		month == 12;
	return month;
}

void saveData(supplier* suppliers,supplier new_suppliers, int check, int &N)
{
	ofstream fout;

	fout.open("database.txt", ofstream::app);

	if (!fout.is_open())
	{
		cout << "Error opening file" << endl;
		fout.open("database.txt");
	}

	if (!fout.is_open())
	{
		cout << "Error opening file" << endl;
	}
	else
	{
		if (check == -1)
		{
			fout << new_suppliers.num_sec << endl;
			fout << new_suppliers.company_name << endl;
			fout << new_suppliers.product_name << endl;
			fout << new_suppliers.cost << endl;
			fout << new_suppliers.quantity << endl;
			fout << new_suppliers.dat.num << endl;
			fout << new_suppliers.dat.month << endl;
			fout << new_suppliers.dat.year << endl;
			cout << "data was written" << endl;
		}
		if (check >= 0)
		{
			fout << suppliers[check].quantity << endl;
		}
	}

	fout.close();
}
void loadData(supplier* suppliers, int &N)
{
	ifstream fin;
	fin.open("database.txt");

	if (!fin.is_open())
	{
		cout << "Can't download database!" << endl;
	}
	else
	{
		cout << "Database is opened!" << endl;
		int buffSize = 0,
			intBuff = 0,
			num = 0;
		char buff[100];
		string buff1;
		while (!fin.eof())
		{
			supplier new_suppliers;

			fin.getline(buff, 100);
			if (strlen(buff) == 0)
			{
				break;
			}

			fin.getline(buff, 100);
			num = atoi(buff);
			new_suppliers.num_sec = num;

			getline(fin, buff1);
			new_suppliers.company_name = buff1;


			getline(fin, buff1);
			new_suppliers.product_name= buff1; 


			fin.getline(buff, 100);
			num = atoi(buff);
			new_suppliers.cost = num;

			fin.getline(buff, 100);
			num = atoi(buff);
			new_suppliers.quantity = num;

			fin.getline(buff, 100);
			num = atoi(buff);
			new_suppliers.dat.num = num;

			getline(fin, buff1);
			new_suppliers.dat.month = buff;

			fin.getline(buff, 100);
			num = atoi(buff);
			new_suppliers.dat.year = num;

			int check = -1;

			push_back(suppliers, N, new_suppliers,check);

		}
	}
}

void fount_min_quintity(supplier* suppliers, int &N)
{
	int i, min_quan;
	cout << "Введите мин кол-во товара" << endl;
	cin >> min_quan;

	for (i = 0; i < N; i++)
	{
		if (suppliers[i].quantity < min_quan)
		{
			cout << setw(4) << suppliers[i].num_sec;
			cout << setw(12) << suppliers[i].company_name;
			cout << setw(12) << suppliers[i].product_name;
			cout << setw(4) << suppliers[i].cost;
			cout << setw(4) << suppliers[i].quantity;
			cout << setw(3) << suppliers[i].dat.num << setw(3) << suppliers[i].dat.month << setw(5) << suppliers[i].dat.year << endl;
		}
	}
}