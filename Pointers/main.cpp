//Pointers
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

//#define POINTERS_BASICS
void main()
{
	setlocale(LC_ALL, "");
#ifdef POINTERS_BASICS
	int a = 2;
	int* pa = &a;
	cout << a << endl; // вывод значени€ переменной 'a' на экран
	cout << &a << endl; // вз€ти€ адреса переменной "а" пр€мо при выводе
	cout << pa << endl; // вывод адреса 'a' хран€щегос€ в указателе "pa"
	cout << *pa << endl; // –азыменование указател€ "pa" вывод значени€ переменной "a"


	int* pb;
	int b = 3;
	pb = &b; // int тип
	cout << *pb << endl;
#endif // POINTERS_BASICS
	const int n = 5;
	short arr[n] = { 3, 5, 8, 13, 21 };
	cout << arr << endl;
	cout << *arr << endl;
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}

}
/*
_____________________________
& - ќператор вз€ти€ адреса (Address-of operator)
* - ќператор –азыменовани€ (Dereference operator)
_____________________________
*/