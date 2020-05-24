/*
ƒана последовательность целых чисел x[1],..., x[n]. Ќайти максимальную длину ее возрастающей подпоследовательности.
*/

#include <iostream>
#include <vector>

int getMaxLength(std::vector<int> arr) {
	int counter = 0;
	int bufferCounter = 0;

	for (int i = 0; i < arr.size() - 1; i++) {
		bufferCounter ++;
		if (arr[i] > arr[i + 1]) {
			if (counter < bufferCounter) {
				counter = bufferCounter;
			}
			bufferCounter = 0;
		}
		
	}

	return bufferCounter > counter ? bufferCounter + 1 : counter;
}

int main() {

	std::vector<int> arr1 = { 4, 5, 6, 1, 2, 3, 4, 5, 6, 7, 8 };
	std::vector<int> arr2 = { 1,2,3,4,5,1,2,3 };
	std::vector<int> arr3 = { 1,2,1,2,1,2,3,4 };
	std::vector<int> arr4 = { 6,5,4,3,2,1 };

	std::cout << getMaxLength(arr1) << std::endl;
	std::cout << getMaxLength(arr2) << std::endl;
	std::cout << getMaxLength(arr3) << std::endl;
	std::cout << getMaxLength(arr4) << std:: endl;

	system("pause");

	return 0;
}