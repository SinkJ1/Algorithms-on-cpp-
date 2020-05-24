#include <iostream>
#include <vector>
/*
ƒана целочисленна€ пр€моугольна€ матрица. ќпределить:
- количество строк, не содержащих ни одного нулевого элемента; +
- максимальное из чисел, встречающихс€ в заданной матрице более одного раза
*/

int matrix[6][4] = {
	{ 1, 2, 3, 4 },
	{ 4, 0, 6, 7 },
	{ 8, 16, 0, 11 },
	{ 12, 0, 14, 15 },
	{ 11, 13, 0, 15 },
	{ 4, 5, 6, 7 }
};

void matrixDisplay() {

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
}

int getNotNulElInRow() {
	int counter = 6;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (matrix[i][j] == 0) {
				counter--;
				break;
			}
		}
	}
	return counter;
}


std::vector<int> getDoublesNumbers() {

	std::vector<int> numbers;

	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			for (int a = i; a < 6; a++) {
				int b = 0;
				if (j == 3) {
					a++;
				}
				else {
					b = j + 1;
				}
				for (; b < 4; b++) {
					int m1 = matrix[i][j];
					int m2 = matrix[a][b];
					if (matrix[i][j] == matrix[a][b]) {
						numbers.push_back(matrix[i][j]);
						break;
					}
				}
			}
		}
	}
	return numbers;
}

int getMaxEl(std::vector<int> arr) {

	int max = arr[0];
	for (int i = 1; i < arr.size(); i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	return max;
}


int main() {

	matrixDisplay();

	std::cout << getMaxEl(getDoublesNumbers());

	system("pause");
	return 0;
}