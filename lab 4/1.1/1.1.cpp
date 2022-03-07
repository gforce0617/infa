#include "pch.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


using namespace std;
void format(char *p, int n, int r)
{
	int i, k = 0;
	cout << "Отформатированный текст:" << endl;
	cout << " ";
	for (i = 0; i < n; i++, p++)
	{
		if (isspace(*p) || iscntrl(*p))
		{
			k++;
			if (k == r)
			{
				cout << *p << endl;
				k = 0;
			}
			cout << *p;
		}
		else cout << *p;
	}
	cout << endl;
}
int main()
{
	char str[50], text[1000], *p, ans;
	bool q = true;
	int i, len = 0, comlen = 0, k, c;
	setlocale(LC_ALL, "Russian");
	do
	{
		cout << "Введите текст (параметр окончания ввода - строка, содержащая одно слово end):" << endl;
		for (p = text, k = 0; q = true; p = p + len + 1, k++)
		{
			gets(str);
			if (str[0] == 'e' && str[1] == 'n' && str[2] == 'd' && strlen(str) == 3) break;
			strcpy(p, str);
			len = strlen(str);
			comlen += len + 1;
		}
		cout << endl;
		cout << "Введите количество слов в строке: ";
		cin >> c;
		format(text, comlen, c);
		cout << "Повторить? (y/n) : ";
		cin >> ans;
		cout << "_____________________________________________________________________________________________________" << endl;
		if (ans == 'y') continue;
		else break;
	} while (true);
}
