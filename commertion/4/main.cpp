/*
В одномерном массиве, состоящем из n вещественных элементов, 
вычислить: - максимальный элемент массива; - сумму элементов массива, 
расположенных ьежду первым и последним четными элементами.
*/

#include <iostream>
#include <vector>


int getMaxEl(std::vector<int> arr) {

	int max = arr[0];

	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}

int firstEvenEl(std::vector<int> arr) {

	int even = 0;

	for (int i = 0; i < arr.size(); i++) {
		if (arr[i] % 2 == 0) {
			even = i;
			break;
		}
	}
	return even;
}

int secondEvenEl(std::vector<int> arr) {

	int even = 0;

	for (int i = arr.size() - 1; i > -1; i--) {
		if (arr[i] % 2 == 0) {
			even = i;
			break;
		}
	}
	return even;
}

int sumBetweenEvensEl(std::vector<int> arr, int firstEvenEl, int secondEvenEL) {
	int sum = 0;
	for (int i = firstEvenEl + 1; i < secondEvenEL; i++) {
		sum += arr[i];
	}
	return sum;
}

int main() {

	std::vector<int> arr = { 4, 3, 5, 3, 1, 1, 12, 17 };
	std::cout << "\n" << "max el - " << getMaxEl(arr);
	std::cout << "\n" << "sum - " << sumBetweenEvensEl(arr, firstEvenEl(arr), secondEvenEl(arr)) << "\n";



	system("pause");
	return 0;
}