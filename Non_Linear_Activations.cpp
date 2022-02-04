#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
using namespace std;

float relu(float x){
  if(x>= 0 ){
    return x;
  }else{
    return 0;
  }
}
float Tanh(float x){
  float y = exp(2*x);
  return (y-1)/(y+1);
}

vector<vector<float>> acti_relu(vector<vector<float>> input){
  vector<vector<float>> output;
  vector<float> line;
  int M = input.size();
  int N = input[0].size();
  for(int i = 0; i < M; ++i){
    for(int j = 0 ; j < N ; ++j){
      line.push_back(relu(input[i][j]));
    }output.push_back(line);
    line.clear();
  }return output;
}

vector<vector<float>> acti_tanh(vector<vector<float>> input){
  vector<vector<float>> output;
  vector<float> line;
  int M = input.size();
  int N = input[0].size();
  for(int i = 0; i < M; ++i){
    for(int j = 0 ; j < N ; ++j){
      line.push_back(Tanh(input[i][j]));
    }output.push_back(line);
    line.clear();
  }return output;
}

int main(){
  vector<vector<float>> input = matrix_reader("a2a.inputmatrix.txt");
  input = acti_relu(input);
  matrix_writer("a2a.outputmatrix.txt", input);
  input = acti_tanh(input);
  input = matrix_reader("a2b.inputmatrix.txt");
  matrix_writer("a2b.outputmatrix.txt", input);
  return 0;
}