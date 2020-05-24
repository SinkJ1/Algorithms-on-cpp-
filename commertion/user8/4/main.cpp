/*
В одномерном массиве, состоящем из п целых элементов, 
вычислить: 
- номер максимального элемента массива; кратного 3 
- произведение элементов массива, 
	расположенных между первым и вторым по значению максимальными элементами.
*/

#include <iostream>
#include <vector>

int maxElAliquot3(std::vector<int> numbers,int startValue) {

	int max = startValue;
	int index = 0;
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] > max && numbers[i] % 3 == 0) {
			max = numbers[i];
			index = i;
		}
	}

	return index;
}

std::vector<int> getElAliquot3(std::vector<int> numbers) {

	std::vector<int> newNumbers;

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] % 3 == 0) {
			newNumbers.push_back(numbers[i]);
		}
	}
	return newNumbers;
}

int getMaxEl(std::vector<int> numbers) {
	int max = numbers[0];
	int index;
	for (int i = 0; i < numbers.size(); i++) {
		if (max < numbers[i]) {
			max = numbers[i];
			index = i;
		}
	}
	return index;
}

int getMinEl(std::vector<int> numbers, int staratVal) {
	int min = numbers[staratVal];
	int index;
	for (int i = 0; i < numbers.size(); i++) {
		if (min > numbers[i]) {
			min = numbers[i];
			index = i;
		}
	}
	return index;
}

int getSecondMax(std::vector<int> numbers, int minVal, int maxVal) {
	int max = numbers[minVal];
	int index;
	for (int i = 0; i < numbers.size(); i++) {
		if (max < numbers[i] && maxVal != i) {
			max = numbers[i];
			index = i;
		}
	}
	return index;
}

std::vector<int> getNumbersBetweenMaxAndSecondMaxEl(std::vector<int> numbers, int maxIndex, int secondMaxIndex) {
	std::vector<int> newNumbers;

	int startVal = 0;
	int endVal = 0;

	if (maxIndex > secondMaxIndex) {
		startVal = secondMaxIndex;
		endVal = maxIndex;
	}

	for (int i = startVal + 1; i < endVal; i++) {
		newNumbers.push_back(numbers[i]);
	}

	return newNumbers;
}

int getMultiplication(std::vector<int> numbers) {
	if (numbers.size() > 0) {
		int val = numbers[0];

		for (int i = 1; i < numbers.size(); i++) {
			val *= numbers[i];
		}
			return val;
		}
	else {
		return 0;
	}
}


int main() {
	setlocale(LC_ALL, "rus");
	std::vector<int> numbers = { 4,3,4,1,9,3, 3,10  };

	if(getElAliquot3(numbers).size() > 0){
		std::cout << "номер max элемента кратного трём - " << maxElAliquot3(numbers, getElAliquot3(numbers)[0]) << std::endl;
	}

	int maxElIndex = getMaxEl(numbers);
	int minElIndex = getMinEl(numbers, maxElIndex);
	int secondMaxElIndex = getSecondMax(numbers, minElIndex, maxElIndex);
	int multiplie = getMultiplication(getNumbersBetweenMaxAndSecondMaxEl(numbers, maxElIndex, secondMaxElIndex));

	std::cout << "произведение элементов находящихся между " << maxElIndex << " : " << secondMaxElIndex << " - " << multiplie << std::endl;
	
	system("pause");
	return 0;
}