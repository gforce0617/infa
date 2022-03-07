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

int main()
{
	int AmountStr, AmountSym;
	char ***str = { 0 };
	int i, j, l;
	cout << "AmountStr=" << endl;;
	cin >> AmountStr;
	str = (char ***)malloc(AmountStr * sizeof(char **));
	for (i = 0; i < AmountStr; i++)
	{
		str[i]= (char **)malloc(AmountStr * sizeof(char *));
	}
	char buf[15];//80-AmountSym
	cout << endl <<"str=";
	for (i = 0; i < AmountStr; i++)
	{
		for (j = 0; j < AmountStr; j++)
		{
			fgets(buf, 13,stdin);
			l = strlen(buf);
			buf[--l] = '\0'; 
			str[i][j] = (char *)malloc(l * sizeof(char)); 
			//strncpy(str[i][j], buf, 80);
			strcpy_s(str[i][j], 15, buf);
		}
	}
	for (i = 0; i < AmountStr; i++) {
		fputs("\n", stdout);
		for (j = 0; j < AmountStr; j++) {
			fputs(str[i][j], stdout);
			fputs("\t", stdout);
		}
	}

	system("pause");
	return 0;	
}