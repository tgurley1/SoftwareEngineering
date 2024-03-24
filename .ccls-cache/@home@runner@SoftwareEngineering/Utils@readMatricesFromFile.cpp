#include "Utils.h"
using namespace std;

/**int* readMatricesFromFile(string fileName, int matricesSize) {
  int matrix1[matricesSize][matricesSize];
  ifstream infile(fileName);
  if (infile.is_open()) {
    int temp;
    infile >> temp;
    for (int i = 0; i < matricesSize; i++) {
      for (int j = 0; j < matricesSize; j++) {
        infile >> matrix1[i][j];
      }
    }
    for (int i = matricesSize; i < 2*matricesSize; i++) {
      for (int j = matricesSize; j < 2*matricesSize; j++) {
        infile >> matrix1[i][j];
      }
    }
    infile.close();
  }
  return *matrix1;
}**/