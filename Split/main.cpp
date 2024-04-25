//Split
#include<iostream>
using namespace std;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	int* arr = new int[n];
	cout << "»сходный массив на 10 рандомных элементов: " << endl;
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;;
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	int even_count = 0;
	int odd_count = 0;
	for (int i = 0; i < 10; i++) // раздел€ю массив на две части четные 
	{                            //и не четные пустем остатка от делени€ на два
		arr[i] % 2 == 0 ? even_count++ : odd_count++;
	}
	cout << "четных чисел " << even_count << endl; // вывод количества четных
	cout << "нечетные чисел " << odd_count << endl; // вывод количества нечетных

	int* even = new int[even_count]; // c помощью указателей создаЄм два массива дл€ 
	int* odd = new int[odd_count];   // четных и нечетных чисел

	int* even_ptr = even;
	int* odd_ptr = odd;
	for (int i = 0; i < 10; i++) // «аполн€ем массивы 
	{
		arr[i] % 2 == 0 ? *even_ptr++ = arr[i] : *odd_ptr++ = arr[i];    //если четное ложим его в even остальные в нечетное ложим в odd.
	}
	cout << "„етные числа массива:   "; // ¬ывод обоих массивов на экран
	for (int i = 0; i < even_count; i++)
	{
		cout << even[i] << tab;
	}
	cout << endl;
	cout << "Ќечетные числа массива: ";
	for (int i = 0; i < odd_count; i++)
	{
		cout << odd[i] << tab;
	}
	cout << endl;
	delete[] arr; // отчищаем пам€ть
	delete[] even;
	delete[] odd;
}