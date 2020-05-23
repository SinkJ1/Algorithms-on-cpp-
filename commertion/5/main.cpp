#include <iostream>

/*
Двумерный массив, содержащий равное число строк и столбцов,
называется магическим квадратом, если суммы чисел,
записанных в каждой строке,
каждом столбце и каждой из двух больших диагоналей,
равны одному и тому же числу. Определить,
является ли данный массив А из n строк и n столбцов магическим квадратом.
*/

const int matrix[4][4] = {
	{ 16, 3, 2, 13 },
	{ 5, 10, 11, 8 },
	{ 9, 6, 7, 12 },
	{ 4, 15, 14, 1 }
};

struct row {
	int value;
	bool status = false;
};

struct row rowValue;

struct column {
	int value;
	bool status = false;
};

struct column columnValue;

struct firstDiagonale {
	int value;
};

struct firstDiagonale firstDiagonaleValue;

struct twoDiagonale {
	int value;
};

struct twoDiagonale twoDiagonaleValue;

void matrixDisplay() {

	std::cout << "matrix" << "\n";

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << "\t";
		}
		std::cout << "\n";
	}
}


void rowsSum() {

	int rowSum = 0;
	int sum[4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			rowSum += matrix[i][j];
		}
		sum[i] = rowSum;
		rowSum = 0;
	}

	rowValue.value = sum[0];
	rowValue.status = true;

	for (int i = 0; i < 4; i++) {
		if (sum[0] != sum[i]) {
			rowValue.status = false;
		}
	}

}

void columnSum() {

	int columnSum = 0;
	int sum[4];

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			columnSum += matrix[j][i];
		}
		sum[i] = columnSum;
		columnSum = 0;
	}

	columnValue.value = sum[0];
	columnValue.status = true;

	for (int i = 0; i < 4; i++) {
		if (sum[0] != sum[i]) {
			columnValue.status = false;
		}
	}

}

void firstDiagonaleSum() {

	int diagonaleSum = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) {
				diagonaleSum += matrix[i][j];
			}
		}
	}

	firstDiagonaleValue.value = diagonaleSum;

}

void twoDiagonaleSum() {

	int diagonaleSum = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (4 == j + i + 1) {
				diagonaleSum += matrix[i][j];
			}
		}
	}

	twoDiagonaleValue.value = diagonaleSum;

}

bool getResult() {

	rowsSum();
	columnSum();
	firstDiagonaleSum();
	twoDiagonaleSum();

	if (rowValue.status && columnValue.status) {
		if (rowValue.value == columnValue.value && columnValue.value == firstDiagonaleValue.value && columnValue.value == twoDiagonaleValue.value) {
			return true;
		}
	}
	return false;
}

int main() {
	matrixDisplay();
	std::cout << getResult();

	system("pause");
	return 0;
}