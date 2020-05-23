/*
Переставить строки матрицы по убываю значения суммы элементов строки.
*/
#include <iostream>

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

void swap(int *a1, int *a2, int M)

}

void rowSort() {

	int *notSortingArray = rowsSum();
	int firstRow[4];
	int secondRow[4];


	for (int n = 4 - 1; n > 0; n--) {
		for (int i = 0; i < 3; i++) {
			if (notSortingArray[i] < notSortingArray[i + 1]) {
				
			} 
		}
	}
}

int main() {
	matrixDisplay();
	rowSort();
	matrixDisplay();

	system("pause");
	return 0;
}