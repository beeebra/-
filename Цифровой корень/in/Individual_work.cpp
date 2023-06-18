#include <iostream>
#include <string>
#include <fstream>
#include "windows.h"
#include<stdlib.h>
using namespace std;
int chek(int c, string s)//������� ��� �������� ����������� ��������� �����
{
	int flag = 1;
	for (int i = 0; i < c; i++)//������������ ��� ������� � ����� � ���� ���� ���� �� ��� �� ����� ����� �� ���������� ������� ���������� flag
	{
		if ((s[i]<48) || (s[i]>57))
			flag = 0;
	}
	return(flag);
}
void string_so_int(int c, int* mas, string s)//������� ��� �������� �� ���� string � ������
{
	int i, j;
	for ( i = 0,j = s.length()-1; i < s.length() , j >= 0;  )//������ ������ ����������� � ��� int ������������ � ������
	{
		mas[i] = s[j] - 48;
		j -= 1;
		i += 1;
	}
}
int digital_root(int* mas, int c)//������� ��� ���������� ����� ���� ���������� ������� � ������������ � � ���� �������� �����
{
	int s=0,j=0;
	for (int i = c; i >= 0; i--)//������ ������� ������� ���������� � ��������� s
	{
		s += mas[i];
	}
	while (s != 0)// ������ ������ ����� ����������� � ������
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
	string s;//���������� ��� ����� �������� �����
	ifstream f("input.txt");//������� ���� � ����� � ������ ��� ���������� ��������� �����
	cout << "�������� ��� ���������� ��������� �����.\n1)���� ����� � ����������\n2)���� ����� �� �����\n��������� ������ ����� �����: ";
	cin >> method;
	system("Cls");
	switch (method)//����������� ������� ����� ����� � ������� switch
	{
		case(1) :
		{
			cout << "������� �����: ";
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
		cout << "��� ������ ��������!";
		return(0);
	}
		break;
	}
	int  c = s.length() - 1, mas[10000];
	flag=chek(c,s);//������� ��� �������� ����������� ��������� �����
	if (flag == 1)//���� ������ �������� �� �������� ��������� �������� � ��������� �������
	{
		string_so_int(c, mas, s);//������� ��� �������� �� ���� string � ������
		while (c != 0)
		{
			c = digital_root(mas, c);//������� ��� ���������� ����� ���� ���������� ������� � ������������ � � ���� �������� �����
		}
		cout << "�������� ������ �����: " << mas[0] << endl;
	}
	else//���� �� � ������� ������ ���������� ������ ������� �� ��������� ������� ������
	{
		cout << "������ ������� �� ��������!";
	}
	return(0);
}