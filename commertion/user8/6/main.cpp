/*
Для заданной матрицы размером 8 на 8 найти такие к, что k-я строка матрицы совпадает с k-м столбцом.
Найти сумму элементов в тех строках, которые содержат хотя бы один отрицательный элемент.
*/

#include <iostream>
#include <vector>

const int matrix[8][8] = {
	{ 16, 5, 9, 43, 16, 5, 9, 43 },
	{ 5, 10, 11, 82 , 16, 3, 2, 13 },
	{ 9, 6, 7, 121, 16, 3, 2, 13 },
	{ 43, 15, 14, -1, 16, 3, 2, 13 },
	{ 16, 3, 2, 13, 16, 3, 2, 13 },
	{ 5, 10, 11, 82 , 16, 3, 2, 13 },
	{ 9, 6, 7, -121, 16, 3, 2, 13 },
	{ 43, 15, 14, 1, 16, 3, 2, 13 }
};

std::vector<int> indexesOfEqualsRowAndColumn;

void equalCheck(int index, std::vector<int> row) {

	std::vector<int> values;
	int size = row.size();
	for (int i = 0; i < size; i++) {
		if (row[i] == matrix[i][index]) {
			values.push_back(matrix[i][index]);
		}
	}

	if (row.size() == values.size()) {
		indexesOfEqualsRowAndColumn.push_back(index);
	}
}


void rowSum(std::vector<int> row, int index) {
	int sum = 0;

	for (int i = 0; i < row.size(); i++) {
		sum += row[i];
	}

	std::cout << "sum in " << index << " row = " << sum << std::endl;
}

void rowCheck(std::vector<int> row, int index) {

	for (int i = 0; i < row.size(); i++) {
		if (row[i] < 0) {
			rowSum(row, index);
			break;
		}
	}

}

void matrixWork(int matrixSise) {

	std::vector<int> row;

	for (int i = 0; i < matrixSise; i++) {
		for (int j = 0; j < matrixSise; j++) {
			row.push_back(matrix[i][j]);
		}
		equalCheck(i, row);
		rowCheck(row, i);
		row.clear();
	}

}


int main() {
	matrixWork(8);
	std::cout << indexesOfEqualsRowAndColumn.size();

	system("pause");
	return 0;
}