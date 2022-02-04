#include <vector>
#include <fstream>
#include <iostream>
#include "FullyConnected.cpp"
#include "Non_Linear_Activations.cpp"
#include "Pooling.cpp"
#include "Vec_Prob_conversion.cpp"
#include "File_IOs.cpp"
using namespace std;


void print_2d_vector(const vector< vector<float> > & matrix)
{
    for(auto row_obj : matrix)
    {
        for (auto elem: row_obj)
        {
            cout<<elem<<", ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main(){
    vector<vector<float>> one  =  {{1.0,1.0}, {0.0,0.0}, {0.0,0.0}};
    vector<vector<float>> inputmatrix = {{-1.8426,-2.0166,0.3445}, {-1.788,0.2498,0.3445}};
    vector<vector<float>> weightmatrix = {{0.6454,0.947}, {-0.8947,-0.0609}, {1.7787,0.3749}};
    vector<vector<float>> biasmatrix = {{-1.209,-0.1295}, {-0.0177,-0.1295}};
    vector<vector<float>> o1 = inner_product(inputmatrix,weightmatrix);
    vector<vector<float>> o2 = addition(o1,biasmatrix);
    vector<vector<float>> o3 = inner_product(inputmatrix,one);
    vector<vector<float>> o4 = acti_relu(inputmatrix);
    vector<vector<float>> inp2 = {{-0.1018,2.6751,0.9281,2.0348},{-2.9818,0.0098,-0.3384,0.3641},{0.9161,0.902,-1.6095,2.0845}};
    vector<vector<float>> o5 = acti_tanh(inp2);
    vector<vector<float>> inp3 = { {1.4476,-1.2755,-3.1691,1.7107,1.1051,0.7087},
                                    {1.5065,2.3554,-2.0748,-2.0545,-0.1646,-1.9425},
                                    {0.4149,-0.4816,0.3547,-0.1946,-0.152,0.3112},
                                    {1.766,-1.1165,0.2165,1.5386,0.7693,1.3299},
                                    {0.6693,0.1484,1.5351,-1.5037,-0.7505,-0.4784},
                                    {-2.6765,-1.7713,-1.729,-1.125,2.8936,1.9811}

    };
    vector<float> x = {-1.7752,0.684,0.0784,-0.0483,-0.1209,0.0852};
    matrix_writer("OOOOO.txt", inp3);
 
    







    return 0;
}
