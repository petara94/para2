#include "pch.h"
#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

/*
struct Tabel {
	int count;
	int *predmests = new int[count];
};
*/

struct BornDate {
	char day[2];
	char mounth[2];
	char year[4];
};

struct Student {
	string FirstName;
	string LastName;
	int age;
	BornDate Borndate;
	int mark;
};

void Append(Student *Arr, Student elem, int* N) {
	Student* R_Array = new Student[*N + 1];
	for (int i = 0; i < *N; i++)
		R_Array[i] = Arr[i];
	R_Array[*N] = elem;
	Arr = R_Array;
	*N++;
	delete[] R_Array;
}

int main()
{
	//SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");

	int N = 0;
	Student* Students = new Student[N];
	char flag = 'y';

	while (flag == 'y' || flag == 'н')
	{

		string Fname, Lname;
		int age, mark;
		BornDate Date;
		cout << "Имя: "; cin >> Fname;
		cout << "Фамилия: "; cin >> Lname;
		cout << "Возраст: "; cin >> age;
		cout << "Дата Рождения (дд мм гггг): "; cin >> Date.day >> Date.mounth >> Date.year;
		cout << "Оценка: "; cin >> mark;
		Student FictStudent = {
			Fname,
			Lname,
			age,
			Date,
			mark
		};
		Append(Students, FictStudent, &N);

		cout << "Продолжить?(y/n)  "; cin >> flag;
		delete &Date;
		delete &Fname, &Lname;
		delete &age, &mark;

	}

	return 0;
}