/*
Переставить строки матрицы по убываю значения суммы элементов строки.
*/
#include <iostream>
#include <vector>

int matrix[4][4] = {
	{ 16, 3, 2, 13 },
	{ 5, 10, 11, 82 },
	{ 9, 6, 7, 121 },
	{ 43, 15, 14, 1 }
};

void matrixDisplay() {

	std::cout << "matrix" << "\n";

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
}


int *rowsSum() {

	int row = 0;
	int sum[4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			row += matrix[i][j];
		}
		sum[i] = row;
		row = 0;
	}

	return sum;
}

void rowSwap(int firstRowIndex, int secondRowIndex) {
	std::vector<int> firstRow;
	std::vector<int> secondRow;

	for (int j = 0; j < 4; j++) {
		firstRow.push_back(matrix[firstRowIndex][j]);
		secondRow.push_back(matrix[secondRowIndex][j]);
	}

	for (int j = 0; j < 4; j++) {
		matrix[firstRowIndex][j] = secondRow[j];
		matrix[secondRowIndex][j] = firstRow[j];
	}

}

void rowSort() {

	for (int n = 4 - 1; n > 0; n--) {
		for (int i = 0; i < 3; i++) {
			if (rowsSum()[i] < rowsSum()[i + 1]) {
				rowSwap(i, i + 1);
			} 
		}
	}
}

int main() {
	matrixDisplay();
	std::cout << "\n";
	for (int i = 0; i < 4; i++) {
		std::cout << rowsSum()[i] << "\t" << std:: endl;
	}

	rowSort();
	matrixDisplay();

	std::cout << "\n";
	for (int i = 0; i < 4; i++) {
		std::cout << rowsSum()[i] << "\t" << std::endl;
	}
	system("pause");
	return 0;
}