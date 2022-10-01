#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

//Задача 19.1
  int NOD(int A, int B) {
	if (A == B)
		return A;
	if (A < B)
		return NOD(A, B - A);
	else
		return NOD(A - B, B);

}

//Задача 19.2
   int mirror_number(int num1) {
	  int length = 1;

	  if (num1 % 100000 <= 99999 && num1 % 100000 > 9999)
		  length = -1;
	  else
		  if (num1 % 10000 <= 9999 && num1 % 10000 > 999)
			  length = 4;
		  else
			  if (num1 % 1000 <= 999 && num1 % 1000 > 99)
				  length = 3;
			  else
				  if (num1 % 100 <= 99 && num1 % 100 > 9)
					  length = 2;
				  else
					  if (num1 % 10 <= 9 && num1 % 10 > 0)
						  length = 1;



	  if (length == -1)
		  return -1;


	  std::cout << "Длина числа: " << length << "\n";

	  if (length == 4) {
		  for (int i = 0; i < 1; i++) {
			  int arr[4]{};
			  arr[0] = num1 / 1000 % 10;
			  arr[1] = num1 / 100 % 10;
			  arr[2] = num1 / 10 % 10;
			  arr[3] = num1 % 10;
			  num1 = arr[3] * 1000 + arr[2] * 100 + arr[1] * 10 + arr[0];
		  }
	  }
	  else
		  if (length == 3) {
			  for (int i = 0; i < 1; i++) {
				  int arr[3]{};
				  arr[0] = num1 / 100 % 10;
				  arr[1] = num1 / 10 % 10;
				  arr[2] = num1 % 10;
				  num1 = arr[2] * 100 + arr[1] * 10 + arr[0];
			  }
		  }
		  else
			  if (length == 2) {
				  for (int i = 0; i < 1; i++) {
					  int arr[2]{};
					  arr[0] = num1 / 10 % 10;
					  arr[1] = num1 % 10;
					  num1 = arr[1] * 10 + arr[0];
				  }
			  }
			  else
				  if (length == 1) {
					  int arr[1]{};
					  arr[0] = num1 % 10;
					  num1 = arr[0];
				  }


	  return num1;
  }

  //Задача 19.3
  template <typename T>
  T fill_arr(T arr[], const int length, int N) {
	 int start = 0;
	for (int i = 0; i < length; i++) {
		if (N == arr[i])
			start = i;
	}

	if (start == 0) {

		for (int i = 0; i < length; i++) {
			for (int j = start + 1; j < length - start - 1; j++) {

				if (arr[j] > arr[j + 1]) {
					int tmp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = tmp;
				}
			}
		}
	}
	else
		if (start == 1)
			for (int i = 0; i < length; i++) {
				for (int j = start + 1; j < length - start; j++) {
					if (arr[j] > arr[j + 1]) {
						int tmp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = tmp;
					}
				}
			}
		else 
			if (start == 2)
				for (int i = 0; i < length; i++) {
					for (int j = start + 1; j < length - start + 1; j++) {
						if (arr[j] > arr[j + 1]) {
							int tmp = arr[j];
							arr[j] = arr[j + 1];
							arr[j + 1] = tmp;
						}
					}
				}
			else
				if (start == 3)
					for (int i = 0; i < length; i++) {
						for (int j = start + 1; j < length - start; j++) {
							if (arr[j] > arr[j + 1]) {
								int tmp = arr[j];
								arr[j] = arr[j + 1];
								arr[j + 1] = tmp;
							}
						}
					}
				else
					if (start == 4)
						for (int i = 0; i < length; i++) {
							for (int j = start + 1; j < length - start + 1; j++) {
								if (arr[j] > arr[j + 1]) {
									int tmp = arr[j];
									arr[j] = arr[j + 1];
									arr[j + 1] = tmp;
								}
							}
						}
					else
						if (start == 5)
							for (int i = 0; i < length; i++) {
								for (int j = start + 1; j < length - start; j++) {
									if (arr[j] > arr[j + 1]) {
										int tmp = arr[j];
										arr[j] = arr[j + 1];
										arr[j + 1] = tmp;
									}
								}
							}
	return start;
}

  template <typename T>
  void show_arr(T arr[], const int length) {
	  std::cout << '[';
	  for (int i = 0; i < length; i++)
		  std::cout << arr[i] << ", ";
	  std::cout << "\b\b]\n";
  }
  
  template <typename T>
  int search_index(T arr[], const int length, T value, int begin = 0) {
	  for (int i = begin; i < length; i++)
		  if (arr[i])
			  return arr[value - 1];
	  return -1;
}


  
  //Задача 19.4
  template <typename T>
  void fill_arr2(T arr[], int length, int begin, int end) {
	  srand(time(NULL));
	  for (int i = 0; i < length; i++)
		  arr[i] = rand() % (end - begin) + begin;
  }

  template <typename T>
  void show_arr2(T arr[], int length) {
	  std::cout << '[';
	  for (int i = 0; i < length; i++)
		  std::cout << arr[i] << ", ";
	  std::cout << "\b\b]\n";
  }

int main() {
	setlocale(LC_ALL, "Russian");
	int n, m;
	

	//Задача 19.1
	std::cout << "Задача 19.1. Наибольший общий делитель двух чисел.\n";
	std::cout << "Введите первое число: ";
	std::cin >> n;
	std::cout << "Введите второе число: ";
	std::cin >> m;
	std::cout << "Наибольший общий делитель двух чисел = " << NOD(n, m);
	std::cout << "\n\n";

	//Задача 19.2
	std::cout << "Задача 19.2. Число в отражённом виде.\n";
	std::cout << "Введите число: ";
	std::cin >> n;
	std::cout << "Число " << n << " в отражённом виде: " << mirror_number(n) <<"\n";
	std::cout << "\n\n";
	

	//Задача 19.3
	int N;
	int arr3[8]{ 9, 37, 10, 25, 3, 14, 5, 16 };

	std::cout << "Задача 19.3. Сортировка элементов массива.\n";
	std::cout << "Изначальный массив: ";
	show_arr(arr3, 8);
	std::cout << "Введите число N: ";
	std::cin >> N;
	std::cout << "Позиция, которая соответствует числу " << N << " в массиве = " << search_index(arr3, 8, N);
	fill_arr(arr3, 8, N);
	std::cout << "\n";
	std::cout << "Итоговый отсортированный массив: ";
	show_arr(arr3, 8);
	std::cout << "\n";

	//Задача 19.4
	int A, B;
	const int size4 = 15;
	int arr4[size4];
	
	std::cout << "Введите начало диапазона: ";
	std::cin >> A;
	std::cout << "Введите конец диапазона: ";
	std::cin >> B;

	std::cout << "Итоговый массив: ";
	fill_arr2(arr4, size4, A, B);
	show_arr2(arr4, size4);
	std::cout << "\n";

	return 0;
}
