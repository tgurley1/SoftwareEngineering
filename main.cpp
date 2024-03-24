/**
Author: Tanner Gurley
Date: 03/24/2024
KUid: 3118883
Assignment: Lab #6
Purpose: This program contains a number of functions that manipulate matrices
read in from a .txt file.
**/

// Import our libraries from the standard library
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Initialize our function headers
void readMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2,
                  string fileName);
void printMatrix(vector<vector<int>> &matrix, string matrixName);
void addMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2,
                 vector<vector<int>> &result);
void multiplyMatrices(vector<vector<int>> &matrix1,
                      vector<vector<int>> &matrix2,
                      vector<vector<int>> &result);
void subtractMatrices(vector<vector<int>> &matrix1,
                      vector<vector<int>> &matrix2,
                      vector<vector<int>> &result);
void updateMatrix(vector<vector<int>> &matrix, int row, int column,
                  int updateValue);
void matrixMaxValue(vector<vector<int>> &matrix, string matrixName);
void transposeMatrix(vector<vector<int>> &matrix, vector<vector<int>> &result,
                     string originalMatrixName);

int main() {
  // Get the name of the file to read in from the user
  string fileName;
  cout << "Enter the name of the file of matrices: ";
  cin >> fileName;

  // Instantiate our matrices using vectors
  vector<vector<int>> matrix1;
  vector<vector<int>> matrix2;
  vector<vector<int>> additionResult;
  vector<vector<int>> multiplicationResult;
  vector<vector<int>> subtractionResult;
  vector<vector<int>> transposedMatrix;

  // Read in and print the matrices from the file
  readMatrices(matrix1, matrix2, fileName);
  // Add the matrices together
  addMatrices(matrix1, matrix2, additionResult);
  // Multiply the matrices together
  multiplyMatrices(matrix1, matrix2, multiplicationResult);
  // Subtract the matrices
  subtractMatrices(matrix1, matrix2, subtractionResult);
  // Update a value within a matrix
  updateMatrix(matrix1, 2, 3, 13);
  // Find and print the max value inside of a matrix
  matrixMaxValue(matrix1, "Matrix 1");
  // Transpose a matrix
  transposeMatrix(matrix1, transposedMatrix, "Matrix 1");

  return 0;
}

void readMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2,
                  string fileName) {
  /*Function that reads in two matrices from a file and stores them in the
   * passed vectors*/
  ifstream infile(fileName);
  int N_size;
  infile >> N_size;
  int temp;

  for (int i = 0; i < N_size; i++) {
    matrix1.push_back(vector<int>());
    for (int j = 0; j < N_size; j++) {
      infile >> temp;
      matrix1[i].push_back(temp);
    }
  }
  for (int i = 0; i < N_size; i++) {
    matrix2.push_back(vector<int>());
    for (int j = 0; j < N_size; j++) {
      infile >> temp;
      matrix2[i].push_back(temp);
    }
  }
  infile.close();
  printMatrix(matrix1, "Matrix 1");
  printMatrix(matrix2, "Matrix 2");
}

void printMatrix(vector<vector<int>> &matrix, string matrixName) {
  /*Function that prints a formatted(width:3 justified:right) matrix*/
  cout << matrixName << ": " << endl;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      cout << setw(3) << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void addMatrices(vector<vector<int>> &matrix1, vector<vector<int>> &matrix2,
                 vector<vector<int>> &result) {
  /*Function adds two matrices together and stores the result in another
   * matrix*/
  for (int i = 0; i < matrix1.size(); i++) {
    result.push_back(vector<int>());
    for (int j = 0; j < matrix1.size(); j++) {
      result[i].push_back(matrix1[i][j] + matrix2[i][j]);
    }
  }
  printMatrix(result, "Addition Result");
}

void multiplyMatrices(vector<vector<int>> &matrix1,
                      vector<vector<int>> &matrix2,
                      vector<vector<int>> &result) {
  /*Funtion multiplies two matrices together and stores the result in another
   * matrix*/
  for (int i = 0; i < matrix1.size(); i++) {
    result.push_back(vector<int>());
    for (int j = 0; j < matrix1.size(); j++) {
      int num = 0;
      for (int k = 0; k < matrix1.size(); k++) {
        num = num + (matrix1[i][k] * matrix2[k][j]);
      }
      result[i].push_back(num);
    }
  }
  printMatrix(result, "Multiplication Result");
}

void subtractMatrices(vector<vector<int>> &matrix1,
                      vector<vector<int>> &matrix2,
                      vector<vector<int>> &result) {
  /*Function subtracts two matrices and stores the result in another matrix*/
  for (int i = 0; i < matrix1.size(); i++) {
    result.push_back(vector<int>());
    for (int j = 0; j < matrix1.size(); j++) {
      result[i].push_back(matrix1[i][j] - matrix2[i][j]);
    }
  }
  printMatrix(result, "Subtraction Result");
}

void updateMatrix(vector<vector<int>> &matrix, int row, int column,
                  int updateValue) {
  /*Function accesses a value inside of a matrix and replaces it, then prints
   * the updated matrix*/
  if (row < 0 or row > matrix.size() or column < 0 or column > matrix.size()) {
    throw range_error("Error: row or column index out of range.");
  } else {
    matrix[row - 1][column - 1] = updateValue;
  }
  printMatrix(matrix, "Updated Matrix");
}

void matrixMaxValue(vector<vector<int>> &matrix, string matrixName) {
  /*Function sweeps through values in a matrix to find the maximum value*/
  int max = 0;
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix.size(); j++) {
      if (matrix[i][j] > max) {
        max = matrix[i][j];
      }
    }
  }
  cout << matrixName << " Max Value: " << max << endl;
  cout << endl;
}

void transposeMatrix(vector<vector<int>> &matrix, vector<vector<int>> &result,
                     string originalMatrixName) {
  /*Function transposes a matrix and stores the result in another matrix*/
  for (int i = 0; i < matrix.size(); i++) {
    result.push_back(vector<int>());
    for (int j = 0; j < matrix.size(); j++) {
      result[i].push_back(matrix[j][i]);
    }
  }
  printMatrix(result, originalMatrixName + ' ' + "Transposed");
}
