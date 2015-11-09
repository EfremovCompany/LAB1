// Solve.cpp : Defines the entry point for the console application.
// Нужны тесты!

#include "stdafx.h"

using namespace std;

bool DigitCheck(char letter)
{
	if (letter == '1')
		return true;
	if (letter == '2')
		return true;
	if (letter == '3')
		return true;
	if (letter == '4')
		return true;
	if (letter == '5')
		return true;
	if (letter == '6')
		return true;
	if (letter == '7')
		return true;
	if (letter == '8')
		return true;
	if (letter == '9')
		return true;
	if (letter == '0')
		return true;
	if (letter == '-')
		return true;
	if (letter == '.')
		return true;
	return false;
}

int main(int argc, char *argv[])
{
	//Read args and check
	if (argc > 4 || argc < 2) {
		cout << "Error! Params must be Solve.exe a b c" << endl;
		return 1;
	}
	//Проверка на некорректные значения
	bool dotCheck;
	string argNumber;
	for (int i = 1; i < argc; i++)
	{
		argNumber = argv[i];
		dotCheck = true;
		for (int j = 0; j < argNumber.size(); j++)
		{
			if (argNumber[j] == '-' && j != 0)
			{
				cout << "Error in " << argNumber << endl;
				return 1;
			}
			if (argNumber[j] == '.' && j == 0 && j == argNumber.size() - 1)
			{
				cout << "Error in " << argNumber << endl;
				return 1;
			}
			if (argNumber[j] == '.' && !dotCheck)
			{
				cout << "Error in " << argNumber << endl;
				return 1;
			}
			if (argNumber[j] == '.')
				dotCheck = false;
			if (!DigitCheck(argNumber[j]))
			{
				cout << "Error in " << argNumber << endl;
				return 1;
			}
		}
	}
		//------
		float a = atof(argv[1]);
		float b;
		float c;
		if (argc == 2) {
			b = 0;
			c = 0;
		}
		else if (argc == 3) {
			b = atof(argv[2]);
			c = 0;
		}
		else {
			b = atof(argv[2]);
			c = atof(argv[3]);
		}

		if (a == 0) {
			cout << "a can't = 0!" << endl;
			return 1;
		}
		//-----

		// Find discriminant
		float D = sqrt((b * b) - (4 * a * c));
		//----

		//Find x
		if (D > 0) {
			float x1, x2;
			if (b == 0)
			{
				x1 = D / (2 * a);
				x2 = -D / (2 * a);
			}
			else
			{
				x1 = (-b + D) / 2 * a;
				x2 = (-b - D) / 2 * a;
			}
			printf("x1 = %.4f\n", x1);
			printf("x2 = %.4f\n", x2);
		}
		else if (D == 0) {
			float x;
			if (b == 0)
			{
				x = 0;
			}
			else
			{
				x = (-b / (2 * a));
			}
			//float x = (-b / 2 * a);
			printf("x = %.4f\n", x);
		}
		else {
			cout << "No real roots" << endl;
		}
		return 0;
}

