#include <iostream>
#include <vector>
/*
Дана действительная квадратная матрица порядка n. 
Найти наименьшее из значений элементов, расположенных в заштрихованной части матрицы.
- верхний и нижний треугольник*
- левый треугольник*
*/

int matrix[6][6] = {
	{ 2,  2,  3,  4,  6, 6 },
	{ 4,  5,  6,  7,  7, 6 },
	{ 8,  9,  10, 11, 5, 7 },
	{ 12, 13, 14, 15, 6, 8 },
	{ 12, 13, 14, 15, 6, 8 },
	{ 12, 13, 14, 15, 6, 8 }
};


std::vector<int> topRectangle(int matrixSize) {

	int right = matrixSize;
	int left = 0;
	std::vector<int> numbers;

	for (int i = 0; i < matrixSize; i++) {
		if (i > 0) {
			left = i;
		if (i == matrixSize / 2) {
			break;
		}
		}
		for (left; left != right;left++) {
			numbers.push_back(matrix[i][left]);
		}
		left = 0;
		right--;
	}
	return numbers;
}

std::vector<int> lowRectangle(int matrixSize) {

	int right = matrixSize;
	int left = 0;
	std::vector<int> numbers;

	for (int i = matrixSize - 1; i > -1; i--) {
		if (i < matrixSize - 1) {
			left = matrixSize - 1 - i;
			if (i == (matrixSize - 1) / 2) {
				break;
			}
		}
		for (left; left != right; left++) {
			numbers.push_back(matrix[i][left]);
		}
		left = 0;
		right--;
	}
	return numbers;
}

std::vector<int> vectorsMerge(std::vector<int> firstVector, std::vector<int> secondVector) {
	std::vector<int> newVector; 
	newVector.reserve(firstVector.size() + secondVector.size());
	newVector.insert(newVector.end(), firstVector.begin(), firstVector.end());
	newVector.insert(newVector.end(), secondVector.begin(), secondVector.end());
	return newVector;

}


int getMinValue(std::vector<int> numbers) {

	int min = numbers[0];

	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] < min) {
			min = numbers[i];
		}
	}
	return min;

}


std::vector<int> leftRectangle(int matrixSize) {


	std::vector<int> numbers;
	
	int right = 1;
	for (int i = 0; i < matrixSize; i++) {
		for (int left = 0; left < right; left++) {
			numbers.push_back(matrix[i][left]);
		}
		if (i < (matrixSize / 2) - 1) {
			right++;
		} else if(i > (matrixSize / 2) - 1) {
			right--;
		}
	}
	return numbers;
}

int main() {
	std::cout << getMinValue(vectorsMerge(topRectangle(6), lowRectangle(6)));
	std:: cout << getMinValue(leftRectangle(6));

	system("pause");
	return 0;
}