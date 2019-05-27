// Lab6PlusPLus.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
using namespace::std;

struct Student {

	string FIO, numberGroup;
	int salary = 0;
	int successNumber[3];

	int m = 3;
};

int main()
{
	
	Student s;
	const char* FileName = "C:\\Users\\Иванов\\Desktop\\Программирование\\textFileLab6";

	int finalRes = 0;
	ofstream out(FileName, ios::binary);

	for (int m = 0; m < 2; m++) {
		cout << endl << "Enter FIO, number group: ";
		for (int i = 0; i < 3; i++) {
			
			cin >> s.FIO; 
			out.write((char*)& s.FIO, sizeof(s.FIO));

			cin >> s.numberGroup;
			out.write((char*)& s.salary, sizeof(s.salary));

			s.successNumber[0] = rand() % 5;
			s.successNumber[1] = rand() % 5;
			s.successNumber[2] = rand() % 5;

			out.write((char*)& s.successNumber[0], sizeof(s.successNumber[0]));
			out.write((char*)& s.successNumber[1], sizeof(s.successNumber[1]));
			out.write((char*)& s.successNumber[2], sizeof(s.successNumber[2]));

			cout << "Number succes " << s.successNumber[0] << " " << s.successNumber[1] << " " << s.successNumber[2] << endl;

			finalRes = finalRes + s.successNumber[i];
			if (finalRes == 15) {
				s.salary = s.salary * 1.5;
				cout << "New salary: " << s.salary;
			}	
			cout << "--------------------------------" << endl;
		}
		finalRes = 0;
	}

	out.close();
	return 0;
}

