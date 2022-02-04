
#include <iostream>
#include <vector>
#include "File_IOs.cpp"
using namespace std;


vector<vector<float> > inner_product(vector<vector<float>> &input_matrix,
                                  vector<vector<float>> &weight_matrix) {
  int a ; int b; int c;
  a = input_matrix.size();
  b = input_matrix[0].size();
  c = weight_matrix[0].size();                                  
  vector<vector<float>> output;
  vector<float> row;
  for (int x = 0; x < c; ++x) {
    row.push_back(0.0);
  }
  for (int y = 0; y < a; ++y) {
    output.push_back(row);
  }

  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < c; ++j) {
      for (int k = 0; k < b; ++k) {
        output[i][j] += input_matrix[i][k] * weight_matrix[k][j];
      }
    }
  }
  return output;
}

vector<vector<float> > addition(vector<vector<float>> &output_matrix,
                             vector<vector<float>> bias_matrix) {
  int a ; int c;
  a = bias_matrix.size();
  c = bias_matrix[0].size();
  vector<vector<float>> final_output;
  vector<float> line;
  for (int i = 0; i < a; ++i) {
    for (int j = 0; j < c; ++j) {
      line.push_back(output_matrix[i][j] + bias_matrix[i][j]);
    }
    final_output.push_back(line);
    line.clear();
  }return final_output;
}

int main(){
  vector<vector<float>> inputmatrix = matrix_reader("a1ainputmatrix.txt");
  vector<vector<float>> weightmatrix = matrix_reader("a1aweightmatrix.txt");
  vector<vector<float>> biasmatrix  = matrix_reader("a1abiasmatrix.txt");
  vector<vector<float>> out = addition(biasmatrix,inner_product(inputmatrix,weightmatrix));
  matrix_writer("a1aoutputmatrix.txt" , out);
  return 0;
}