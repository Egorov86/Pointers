//DynamicMemory
#include<iostream>
using namespace std;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(int arr[], const int n, int value = 0);

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "������� ������ �������: "; cin >> n;
	int* arr = new int[n];
	FillRand(arr, n);
	Print(arr, n);
	int value;
	cout << "������� ����������� ��������: "; cin >> value;
	int* add_arr = new int[n + 1];   // ������ ����� ������ � ���� ������� ������ ������,
	for (int i = 0; i < n; i++)      // ������ ������. � ����� ������ � ������� ������� �������
	{                                // �������� ��������� ������� � ����������.
		add_arr[i] = arr[i];
	}
	delete[] arr;
	arr = add_arr;
	n++;
	arr[n - 1] = value;
	Print(add_arr, n, value);
	delete[] add_arr;
}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ��������� ������� ����� ����������
		// ���������� � �������� �������������:
		*(arr + i) = rand() % 100;
	}
}
/*void AddFillRand(int add_arr[], int arr[], int n, int value)
{
	for (int i = 0, j = 0; i < n; i++)
	{
		add_arr[i] = arr[i];
	}
	delete[] arr;
	arr = add_arr;
	n++;
	arr[n - 1] = value;
}*/
void Print(int arr[], const int n, int value) //����� �������� �� �����
{
	for (int i = 0; i < n; i++)
	{
		//��������� � ��������� ������� ����� ������� �������������� - []:
		cout << arr[i] << tab;
	}
	cout << endl;
}