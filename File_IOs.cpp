#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

vector<vector<float>> zero_matrix(int c, int r){
  vector<float> line;
  vector<vector<float>> out;
  for(int i = 0; i < r ;++i){
    line.push_back(0.0);
  }for(int j = 0; j < c ;++j){
    out.push_back(line);
  }return out;
}

vector<vector<float>> matrix_reader(string filename){
  ifstream infile(filename);
  int column;
  int row;
  float x;
  string s;
  infile >> column;
  infile >> row;
  
  vector<vector<float>>  M = zero_matrix(row,column);
  int i = 0;
  while(infile>>x){
    M[i%row][i/row] = x;
    ++i;
  }infile.clear();
  infile.close();
  return M;
}

void matrix_writer(string filename , vector<vector<float>> M){
  ofstream outfile(filename);
  int row = M.size();
  int column = M[0].size();
  string s;
  float x;
  s = to_string(column);
  outfile << s << endl;
  s = to_string(row);
  outfile << s << endl;
  for(int i = 0 ; i < column ; ++i){
    for(int j = 0 ; j < row ; ++j){
        x = M[j][i];
        s = to_string(x);
        outfile << s << endl;
    }
  }outfile.close();
  outfile.clear();
}

vector<float> vector_reader(string filename){
  ifstream infile;
  infile.open(filename);
  vector<float> out;
  int l;
  float x;
  std::string s;
  getline(infile, s);
  l = std::stoi(s);
  while(infile>>x){
    out.push_back(x);
  }infile.clear();
  infile.close();
  return out;
}

void vector_writer(string filename , vector<float> v){
  ofstream outfile(filename);
  int l = v.size();
  float x;
  string s = to_string(l);
  for(int i = 0 ; i< l ; ++i){
    x = v[i];
    s = to_string(x);
    outfile << s << endl;
  }outfile.clear();
  outfile.close();
}


string type_reader(string filename){
  ifstream infile;
  string s;
  infile >> s;
  return s;
}










