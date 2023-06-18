#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"
#include<stdlib.h>
using namespace std;
int chek(int c, string s)//Функция для проверки коректности введеного числа
{
	int flag = 1;
	for (int i = 0; i < c; i++)//перебираются все смиволы в файле и если хоть один из них не равен цифре то происходит измение переменной flag
	{
		if ((s[i]<48) || (s[i]>57))
			flag = 0;
	}
	return(flag);
}
void string_so_int(int c, int* mas, string s)//функция для перевода из типа string в массив
{
	int i, j;
	for ( i = 0,j = s.length()-1; i < s.length() , j >= 0;  )//каждое символ переводится в тип int записывается в массив
	{
		mas[i] = s[j] - 48;
		j -= 1;
		i += 1;
	}
}
int digital_root(int* mas, int c)//функция для вычисления суммы всех элеменетов массива и предствления её в виде длинного числа
{
	int s=0,j=0;
	for (int i = c; i >= 0; i--)//каждый элемент массива сумируется в переменую s
	{
		s += mas[i];
	}
	while (s != 0)// каждый разряд числа переноситья в массив
	{
		mas[j] = s % 10;
		s = s / 10;
		j++;
	}
	return(j-1);
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "rus");
	int flag, method;
	string s;//переменная для ввода длинного числа
	ifstream f("input.txt");//Введите путь к файлу с числом для вычисление цифрового корня
	cout << "Прогамма для вычисления цифрового корня.\n1)Ввод числа с клавиатуры\n2)Ввод числа из файла\nВвыбериет способ ввода числа: ";
	cin >> method;
	system("Cls");
	switch (method)//определение способа ввода числа с помощью switch
	{
		case(1) :
		{
			cout << "Введите число: ";
			cin >> s;
			break;
		}
		case(2):
		{
			
			f >> s;
			break;
		}
	default:
	{
		cout << "Нет такого варианта!";
		return(0);
	}
		break;
	}
	int  c = s.length() - 1, mas[10000];
	flag=chek(c,s);//Функция для проверки коректности введеного числа
	if (flag == 1)//если данные коректны то алгоритм начианает работать с введеными данными
	{
		string_so_int(c, mas, s);//функция для перевода из типа string в массив
		while (c != 0)
		{
			c = digital_root(mas, c);//функция для вычисления суммы всех элеменетов массива и предствления её в виде длинного числа
		}
		cout << "Цифровой корень числа: " << mas[0] << endl;
	}
	else//если же в веденых данных содержятся лишние символы то программа выведет ошибку
	{
		cout << "Данные введены не коректно!";
	}
	return(0);
}