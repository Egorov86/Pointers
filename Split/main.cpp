//Split
#include<iostream>
using namespace std;

#define tab "\t"

void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	int* arr = new int[n];
	cout << "�������� ������ �� 10 ��������� ���������: " << endl;
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
	for (int i = 0; i < 10; i++) // �������� ������ �� ��� ����� ������ 
	{                            //� �� ������ ������ ������� �� ������� �� ���
		arr[i] % 2 == 0 ? even_count++ : odd_count++;
	}
	cout << "������ ����� " << even_count << endl; // ����� ���������� ������
	cout << "�������� ����� " << odd_count << endl; // ����� ���������� ��������

	int* even = new int[even_count]; // c ������� ���������� ������ ��� ������� ��� 
	int* odd = new int[odd_count];   // ������ � �������� �����

	int* even_ptr = even;
	int* odd_ptr = odd;
	for (int i = 0; i < 10; i++) // ��������� ������� 
	{
		arr[i] % 2 == 0 ? *even_ptr++ = arr[i] : *odd_ptr++ = arr[i];    //���� ������ ����� ��� � even ��������� � �������� ����� � odd.
	}
	cout << "������ ����� �������:   "; // ����� ����� �������� �� �����
	for (int i = 0; i < even_count; i++)
	{
		cout << even[i] << tab;
	}
	cout << endl;
	cout << "�������� ����� �������: ";
	for (int i = 0; i < odd_count; i++)
	{
		cout << odd[i] << tab;
	}
	cout << endl;
	delete[] arr; // �������� ������
	delete[] even;
	delete[] odd;
}