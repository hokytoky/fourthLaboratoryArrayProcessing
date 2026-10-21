/****************************************************
 * Автор:   Сабитов Ильнур                          *
 * Задание: Обработка массивов                      *
 * Вариант: 28                                      *
 ****************************************************/

#include <iostream>
#include <math.h>

using namespace std;

int main() {
  const int maxSize = 20;
  const int maxMagnitude = 1000;

  int matrix[maxSize][maxSize];
  int rowsSumList[maxSize];
  bool isOddOnlyList[maxSize]; 

  int rowsCount;
  int columnsCount;
  int rowIndex;
  int columnIndex;
  int oddRowsCount = 0;
  int maxSum;
  int maxRowIndex;

  cout << "Enter number of rows (1-20): ";
  cin >> rowsCount;

  cout << "Enter number of columns (1-20): ";
  cin >> columnsCount;

  if (rowsCount < 1 || columnsCount < 1 || rowsCount > maxSize || columnsCount > maxSize) {
    cout << "INVALID\n";
    return 1;
  }

  for (rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
    for (columnIndex = 0; columnIndex < columnsCount; ++columnIndex) {
      cout << "Enter element [" << rowIndex + 1 << "][" << columnIndex + 1 << "]: ";
      cin >> matrix[rowIndex][columnIndex];

      if (matrix[rowIndex][columnIndex] < -maxMagnitude || matrix[rowIndex][columnIndex] > maxMagnitude) {
        cout << "INVALID\n";
        return 1;
      }
    }
  }

  // search odd rows and sum of absolute values
  for (rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
    rowsSumList[rowIndex] = 0;
    isOddOnlyList[rowIndex] = true;

    for (columnIndex = 0; columnIndex < columnsCount; ++columnIndex) {
      rowsSumList[rowIndex] = rowsSumList[rowIndex] + abs(matrix[rowIndex][columnIndex]);

      if (matrix[rowIndex][columnIndex] % 2 == 0) {
        isOddOnlyList[rowIndex] = false;
      }
    }

    if (isOddOnlyList[rowIndex]) {
      ++oddRowsCount;
    }
  }

  // search max sum of absolute values
  maxSum = rowsSumList[0];
  maxRowIndex = 0;

  for (rowIndex = 1; rowIndex < rowsCount; ++rowIndex) {
    if (rowsSumList[rowIndex] > maxSum) {
      maxSum = rowsSumList[rowIndex];
      maxRowIndex = rowIndex;
    }
  }

  cout << "\nMatrix:\n";
  for (rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
    for (columnIndex = 0; columnIndex < columnsCount; ++columnIndex) {
      cout << matrix[rowIndex][columnIndex] << " ";
    }
    cout << "\n";
  }

  cout << "\nRows with only odd elements:\n";
  if (oddRowsCount == 0) {
    cout << "EMPTY\n";
  } else {
    for (rowIndex = 0; rowIndex < rowsCount; ++rowIndex) {
      if (isOddOnlyList[rowIndex]) {
        cout << "Row " << rowIndex + 1 << ", sum of absolute values: " << rowsSumList[rowIndex] << "\n";
      }
    }
  }

  cout << "Row with the maximum sum of absolute values: " << maxRowIndex + 1 << ", sum: " << maxSum << "\n";

  return 0;
}