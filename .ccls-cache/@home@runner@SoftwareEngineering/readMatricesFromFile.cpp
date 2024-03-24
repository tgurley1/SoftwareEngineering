#include <fstream>
#include <iostream>
#include <string>
#include <tuple>
using namespace std;


tuple<int **, int **> readMatricesFromFile(string fileName) {
  ifstream infile(fileName);
  if (infile.is_open()) {
    int N_size;
    infile >> N_size;
    int matrix1[N_size][N_size];
    int matrix2[N_size][N_size];
    for (int i = 0; i < N_size; i++) {
      for (int j = 0; j < N_size; j++) {
        infile >> matrix1[i][j];
      }
    }
    for (int i = 0; i < N_size; i++) {
      for (int j = 0; j < N_size; j++) {
        infile >> matrix2[i][j];
      }
    }
    infile.close();
    return make_tuple((int **)matrix1, (int **)matrix2);
  }
  return make_tuple(nullptr, nullptr);
}