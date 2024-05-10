//DynamicMemory
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void FillRand(int** arr, const int ROWS, const int COLS);
void Print(int arr[], const int n);
void Print(int** arr, const int ROWS, const int COLS);
void Clear(int**& arr, int& ROWS, int& COLS);

int* push_back(int arr[], int& n, int value);
int* push_front(int arr[], int& n, int value);
int* pop_back(int arr[], int& n);
int* pop_front(int arr[], int& n);
int* insert(int arr[], int& n, int index, int value);
int* erase(int arr[], int& n, int index);

int** Allocate(int**& arr, int& ROWS, int& COLS);
int** Push_row_front(int**& arr, int& ROWS, int& COLS);
int** Insert_row(int**& arr, int& ROWS, int& COLS, int& index);
int** Pop_row_back(int**& arr, int& ROWS, int& COLS);
int** Pop_row_front(int**& arr, int& ROWS, int& COLS);
int** Erase_row(int**& arr, int& ROWS, int& COLS, int& index);
int** Push_col_back(int**& arr, int& ROWS, int& COLS);
int** Push_col_front(int**& arr, int& ROWS, int& COLS);
int** Insert_col(int**& arr, int& ROWS, int& COLS, int& index);
int** Pop_col_back(int**& arr, int& ROWS, int& COLS);
int** Pop_col_front(int**& arr, int& ROWS, int& COLS);
int** Erase_col(int**& arr, int& ROWS, int& COLS, int& index);



//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n = 0;
	cout << "Введите размер массива: "; cin >> n;
	int* arr = new int[n];

	FillRand(arr, n);
	Print(arr, n);

	int value;
	int index;
	cout << "Введите добавляемое значение в конец массива: "; cin >> value;
	arr = push_back(arr, n, value);
	Print(arr, n);
	cout << "Введите добавляемое значение в начало массива: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);
	cout << "Удаление последнего элемента: "<< endl;
	arr = pop_back(arr, n);
	Print(arr, n);
	cout << "Удаление нулевого элемента: " << endl;
	arr = pop_front(arr, n);
	Print(arr, n);
	do
	{
		cout << "Введите индекс элемента для замены от 0  до  " << n << endl; cin >> index ;
		if (index < 0 || index >= n)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index >= n);
	cout << endl;
	cout << "Введите добавляемое значение: "; cin >> value;
	arr = insert(arr, n, index, value);
	Print(arr, n);
	do
	{
		cout << "Введите индекс элемента для удаления от 0  до  " << n << endl; cin >> index;
		if (index < 0 || index >= n)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index >= n);
	arr = erase(arr, n, index);
	Print(arr, n);


	delete[] arr;

#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2
	int ROWS;
	int COLS;
	cout << "Введите количество строк: "; cin >> ROWS;
	cout << "Введите количество элементов строк: "; cin >> COLS;
	int index;
	int** arr = Allocate(arr, ROWS, COLS);
	FillRand(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "добавление нулевой стороки в массив: " << endl;
	Push_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "Введите индекс элемента строки для вставки строки от 0  до  " << ROWS << endl; cin >> index;
		if (index < 0 || index > ROWS)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index > ROWS);
	Insert_row(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	cout << "Удаление последней строки в массиве: " << endl;
	Pop_row_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "Удаление нулевой строки в массиве: " << endl;
	Pop_row_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "Введите индекс элемента строки для удаления от 0  до  " << ROWS << endl; cin >> index;
		if (index < 0 || index > ROWS)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index > ROWS);
	Erase_row(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	cout << "добавление столбика в конец массива: " << endl;
	Push_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "добавление столбика в начало массива: " << endl;
	Push_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "Введите индекс элемента столбца для добавлеия от 0  до  " << COLS << endl; cin >> index;
		if (index < 0 || index > COLS)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index > COLS);
	Insert_col(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	cout << "Удаление столбика в конце массива: " << endl;
	Pop_col_back(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	cout << "Удаление столбика в начале массива: " << endl;
	Pop_col_front(arr, ROWS, COLS);
	Print(arr, ROWS, COLS);
	do
	{
		cout << "Введите индекс элемента столбца для удаления от 0  до  " << COLS << endl; cin >> index;
		if (index < 0 || index > COLS)cout << "Такого индекса не существует" << endl;

	} while (index < 0 || index > COLS);
	Erase_col(arr, ROWS, COLS, index);
	Print(arr, ROWS, COLS);
	Clear(arr, ROWS, COLS);
#endif // DYNAMIC_MEMORY_2


}

void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100;
	}
}
void FillRand(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int arr[], const int n) //Вывод массивов на экран
{
	for (int i = 0; i < n; i++)
	{
		//Обращение к элементам массива через опертор индексирования - []:
		cout << arr[i] << tab;
	}
	cout << endl;
}
void Print(int** arr, const int ROWS, const int COLS)
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COLS; j++)
		{
			cout << arr[i][j] << tab;
		}
		cout << endl;
	}
	cout << endl;
}
int* push_back(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[n] = value;
	n++;
	//Print(arr, n);
	return arr;
}
int* push_front(int arr[], int& n, int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i + 1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	arr[0] = value;
	n++;
	return arr;
}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	return arr;
}
int* insert(int arr[], int& n, int index,  int value)
{
	int* buffer = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	for (int i = n; i > index; --i)
	{
		arr[i] = arr[i-1];
	}
	arr[index] = value;
	n++;
	return arr;
}
int* erase(int arr[], int& n, int index)
{
	int* buffer = new int[n];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index+1; i < n; i++)
	{
		buffer[i-1] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	n--;
	return arr;
}
int** Allocate(int**& arr, int& ROWS, int& COLS)
{
	arr = new int* [ROWS];
	//2) Выделяем память под строки:
	for (int i = 0; i < ROWS; i++)
	{
		arr[i] = new int[COLS];
	}
	return arr;
}
void Clear(int**& arr, int& ROWS, int& COLS)
{
	//1) Cначала удаляем строки:
	for (int i = 0; i < ROWS; i++)
	{
		delete[] arr[i];
	}
	//2) Удаляем массив указателей, обнуляем указатель и сбрасываем строки и элмен.строк.
	delete[] arr;
	arr = nullptr;
	ROWS = 0;
	COLS = 0;
	cout << "Массив удалён, память отчищена!!!" << endl;
}

int** Push_row_front(int**& arr, int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS + 1];
	//int buffer;
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i + 1] = arr[i];
		buffer[0] = new int[COLS];
		for (int j = 0; j < COLS; j++)
		{
			buffer[0][j] = rand() % 10;
		}
	}
	delete[] arr;
	arr = buffer;
	ROWS++;
	return arr;
}
int** Insert_row(int**& arr, int& ROWS, int& COLS, int& index)
{
	int** buffer = new int* [ROWS + 1];
	for (int i = 0; i <= index; i++)
	{
		buffer[i] = arr[i];
		buffer[index] = new int[COLS];
		for (int j = 0; j < COLS; j++)
		{
			buffer[index][j] = rand() % 20;
		}
	}
	for (int i = ROWS; i > index; i--)
	{
		buffer[i] = arr[i-1];
	}
	delete[] arr;
	arr = buffer;
	ROWS++;
	return arr;
}
int** Pop_row_back(int**& arr, int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS - 1];
	for (int i = 0; i < ROWS - 1; i++)
	{
		buffer[i] = arr[i];
	}
	delete[] arr;
	arr = buffer;
	ROWS--;
	return arr;
}
int** Pop_row_front(int**& arr, int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS - 1];
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	arr = buffer;
	ROWS--;
	return arr;
}
int** Erase_row(int**& arr, int& ROWS, int& COLS, int& index)
{
	int** buffer = new int* [ROWS - 1];
	for (int i = 0; i < index; i++)
	{
		buffer[i] = arr[i];
	}
	for (int i = index; i < ROWS; i++)
	{
		buffer[i] = arr[i+1];
	}
	delete[] arr;
	arr = buffer;
	ROWS--;
	return arr;
}
int** Push_col_back(int**& arr, int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i] = arr[i];
		buffer[i] = new int[COLS + 1];
		for (int j = 0; j < COLS; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = COLS; j < COLS + 1; j++)
		{
			buffer[i][j] = rand() % 40;
		}
	}
	delete[] arr;
	arr = buffer;
	COLS++;
	return arr;
}
int** Push_col_front(int**& arr, int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i] = arr[i];
		buffer[i] = new int[COLS + 1];
		for (int j = 1; j < COLS + 1; j++)
		{
			buffer[i][j] = arr[i][j - 1];
		}
		for (int j = 0; j < 1; j++)
		{
			buffer[i][j] = rand() % 40;
		}
	}
	delete[] arr;
	arr = buffer;
	COLS++;
	return arr;
}
int** Insert_col(int**& arr, int& ROWS, int& COLS, int& index)
{
	int** buffer = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i] = arr[i];
		buffer[i] = new int[COLS + 1];
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j <= index; j++)
		{
			buffer[i][index] = rand() % 40;
		}
		for (int j = index + 1; j < COLS + 1; j++)
		{
			buffer[i][j] = arr[i][j - 1];
		}
	}
	delete[] arr;
	arr = buffer;
	COLS++;
	return arr;
}
int** Pop_col_back(int**& arr, int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i] = arr[i];
		buffer[i] = new int[COLS - 1];
		for (int j = 0; j < COLS-1; j++)
		{
			buffer[i][j] = arr[i][j];
		}
	}
	delete[] arr;
	arr = buffer;
	COLS--;
	return arr;
}
int** Pop_col_front(int**& arr, int& ROWS, int& COLS)
{
	int** buffer = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i] = arr[i];
		buffer[i] = new int[COLS - 1];
		for (int j = 1; j <= COLS; j++)
		{
			buffer[i][j - 1] = arr[i][j];
		}
	}
	delete[] arr;
	arr = buffer;
	COLS--;
	return arr;
}
int** Erase_col(int**& arr, int& ROWS, int& COLS, int& index)
{
	int** buffer = new int* [ROWS];
	for (int i = 0; i < ROWS; i++)
	{
		buffer[i] = arr[i];
		buffer[i] = new int[COLS - 1];
		for (int j = 0; j < index; j++)
		{
			buffer[i][j] = arr[i][j];
		}
		for (int j = index; j < COLS; j++)
		{
			buffer[i][j] = arr[i][j+1];
		}
	}
	delete[] arr;
	arr = buffer;
	COLS--;
	return arr;
}
