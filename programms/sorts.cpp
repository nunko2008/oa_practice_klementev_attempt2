#include <iostream>
#include <vector>
#include <algorithm> // для std::swap

void my_sort(int *arr, const int size);

int main() {
	setlocale(LC_ALL, "Russian"); // для корректного вывода русских букв в консоли Windows
	
	int n;
	std::cout << "Введите размер массива: ";
	std::cin >> n;
	
	if (!std::cin || n <= 0) {
		std::cerr << "Ошибка: размер массива должен быть положительным числом.\n";
		return 1;
	}
	
	std::vector<int> arr(n);
	
	std::cout << "Введите " << n << " элементов массива:\n";
	for (int i = 0; i < n; ++i) {
		std::cout << "Элемент " << i + 1 << ": ";
		std::cin >> arr[i];
	}
	
	std::cout << "\nИсходный массив: ";
	for (int x : arr) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	
	my_sort(arr.data(), n);
	
	std::cout << "Отсортированный массив: ";
	for (int x : arr) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	
	return 0;
}


void my_sort(int *arr, const int size) {
	// Сортировка пузырьком по возрастанию
	for (int i = 0; i < size - 1; ++i) {
		bool swapped = false;
		
		for (int j = 0; j < size - 1 - i; ++j) {
			if (arr[j] > arr[j + 1]) {
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}
		
		// Если за проход не было обменов, массив уже отсортирован
		if (!swapped) {
			break;
		}
	}
}


