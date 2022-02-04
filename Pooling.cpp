#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;

vector<vector<float>> max_pool( vector<vector<float>> M ,int n, int stride){
    vector<vector<float>> output;
    vector<float> row;
    for (int x = 0; x < (n/stride); ++x) {
        row.push_back(0.0);
    }
    for (int y = 0; y < (n/stride); ++y) {
        output.push_back(row);
    }

    float max = 0;
    for(int i = 0 ; i < n; i+= stride){
        for(int j = 0 ; j < n ; j+= stride){
            for(int p = i ; p < (i+stride) ; ++p){
                for(int q = j ; q < (j+stride) ; ++q){
                    if(M[p][q] > max){
                        max = M[p][q];
                    }
                }
            }output[i/stride][j/stride] = max;
            max = 0;
        }
    }return output;
}

vector<vector<float>> avg_pool( vector<vector<float>> M ,int n, int stride){
    vector<vector<float>> out;
    vector<float> row;
    for (int x = 0; x < (n/stride); ++x) {
        row.push_back(0.0);
    }
    for (int y = 0; y < (n/stride); ++y) {
        out.push_back(row);
    }

    float max = 0.0;
    for(int i = 0 ; i < n; i+= stride){
        for(int j = 0 ; j < n ; j+= stride){
            for(int p = i ; p < (i+stride) ; ++p){
                for(int q = j ; q < (j+stride) ; ++q){
                    max += M[p][q];
                }
            }max = max/(stride*stride);
            out[i/stride][j/stride] = max;
            max = 0.0;
        }
    }return out;
}

int main(){
    vector<vector<float>> input = matrix_reader("a3a.inputmatrix.txt");
    fstream fio;
    fio.open("a3a.typeStride.txt");
    int str ;
    fio >> str;
    int n = input.size();
    input = max_pool(input,n,str);
    matrix_writer("a3a.outputmatrix.txt", input);
    input = matrix_reader("a3b.inputmatrix.txt");
    fio >> str;
    n = input.size();
    input = avg_pool(input,n,str);
    matrix_writer("a3b.outputmatrix.txt", input);
    return 0;
    fio.close();
}
