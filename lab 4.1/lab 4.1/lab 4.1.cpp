#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void format(vector<string>& str, int vec_size)
{
	string word;
	vector<string> format_str;
	int i,j;
	int a=0, wrd_size;
	char *copy_str;
	int *ind=new int[vec_size];
	int max_size=0;

	cout << endl << "Введите Искомое слово" << endl;
	cin >> word;
	cout << endl << "Искомое слово"<< endl << word << endl;

	wrd_size = word.size();

	for (i = 0; i < vec_size; i++)
	{
		ind[i] = -1;
		if (max_size < str.size())
			max_size = str.size();
	}
	copy_str = new char[max_size + 1];
	
	int num = -1;
	int num_i;

	for (i = 0; i < vec_size; i++)
	{
		num_i = str[i].find(word);
		/*cout << "vec_size" << endl << str[i].find(word) << endl;*/
		if ( num_i > num && num_i < 1000)
		{
			ind[a] = i;
			//cout << ind[a] << "   a" << a;
			a++;
			
		}
	}
	
	a = 0;
	//cout << endl << "ind  " << ind[a] << endl;
	if (ind[a] == -1)
		cout << "Слово отсутствует";
	else
	{
		while (ind[a] != -1)
		{
			strcpy(copy_str, str[ind[a]].c_str());
			cout << endl << copy_str << endl;
			num_i = str[ind[a]].find(word);
			for (i = num_i; i < num_i + wrd_size; i++)
			{
				copy_str[i] -= 'a' - 'A';
			}
			/*cout << "copy  " << copy_str << endl;*/
			
			str[ind[a]] = string(copy_str);

			a++;
		}

		cout << "строки" << endl;

		for (int i = 0; i < vec_size; i++) {
			cout << str[i] << endl;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "RUS");
	vector<string> str;
	string buffer = "";

	cout << "Вводите слова. "
		<< "По окончание ввода введите пустую строку" << endl;

	do {
		getline(cin, buffer);
		if (buffer.size() > 0) {
			str.push_back(buffer);
		}
	} while (buffer != "");
	
	unsigned int vector_size = str.size();

	for (int i = 0; i < vector_size; i++) {
		cout << str[i] << endl;
	}

	format(str,vector_size);

	return 0;
}

