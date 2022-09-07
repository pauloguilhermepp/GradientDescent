#include "GradientDescent/VanillaGradientDescent/VanillaGradientDescent.cpp"

long double evaluationFunction(std::vector<long double> vector){
    long double sum = 0;

    for(int i = 0; i < vector.size(); i++){
        sum += vector[i];
    }

    return sum;
}

int main(){
    VanillaGradientDescent gd(10, 100, 0.1, 0.1, 0,1, &evaluationFunction);
    gd.run();

    return 0;
}
