#include <vector>
#include <stdio.h>
#include <cmath>
using namespace std;

float sigmoid_(float x){
    return 1/(1+exp(-1.0*x));
}
vector<float> sigmoid(vector<float> x){
    int l = x.size();
    vector<float> y;
    for(int i = 0; i < l; ++i){
        y.push_back(sigmoid_(x[i]));
    }return y;
}

vector<float> softmax(vector<float> x){
    float sum = 0.0;
    int l = x.size();
    vector<float> y;
    for(int i = 0 ; i<l ; ++i){
        sum += exp(x[i]);
        y.push_back(exp(x[i]));
    }for(int j = 0; j < l ; ++j){
        y[j] = y[j]/sum;
    }return y;
}


int main(){
    vector<float> input;
    input = vector_reader("a4a.inputvector.txt");
    vector_writer("a4a.outputvector.txt", softmax(input));
    input = vector_reader("a4b.inputvector.txt");
    vector_writer("a4b.outputvector.txt",sigmoid(input));
    return 0;
}
