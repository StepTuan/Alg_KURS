#include "Header.h"
#include <iomanip>
#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
const int KEY_ESC = 27;

using namespace std;

void main()
{
	while (_getch() != KEY_ESC)
	{
		expres in;
		string Enter;
		cout << "Input = ";
		getline(cin, Enter);
		in.set_Exp(Enter);
		in.Get_prefix(); cout << endl;
		in.string_print();
		cout << " = "; cout << in.Calculate(); cout << endl; cout << endl;
	}
}
