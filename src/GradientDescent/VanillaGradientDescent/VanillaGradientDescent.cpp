#include "VanillaGradientDescent.hpp"

VanillaGradientDescent::VanillaGradientDescent(int NumVar, int NumIt,
                        long double Alpha, long double Dx,
                        long double MinValue, long double MaxValue,
                        long double (*EvaluationFunc)(std::vector<long double>)){
                            numVar = NumVar;
                            numIt = NumIt;
                            alpha = Alpha;
                            dx = Dx;
                            minValue = MinValue;
                            maxValue = MaxValue;
                            evaluationFunc = EvaluationFunc;
}

std::vector<long double> VanillaGradientDescent::gradient(){
    long double newValue;
    std::vector<long double> gradient, tempSolution;
    tempSolution = solution;
 
    for(int i = 0; i < numVar; i++){
        tempSolution[i] = solution[i] + dx;
        newValue = (evaluationFunc(tempSolution) - evaluationFunc(solution)) / dx;
        gradient.push_back(newValue);
        tempSolution[i] = solution[i];
    }

    return gradient;
}

long double VanillaGradientDescent::checkNewValue(long double newValue){
    if(newValue > maxValue){
        newValue = maxValue;
    }else if(newValue < minValue){
        newValue = minValue;
    }

    return newValue;
}

void VanillaGradientDescent::showSolution(){
    std::cout << "Solution: ";
    for(int i = 0; i < numVar; i++){
        std::cout << solution[i] << " ";
    }

    std::cout << std::endl;
    std::cout << "EvaluationFunctionValue: " << evaluationFunc(solution) << std::endl;
}

void VanillaGradientDescent::run(){
    long double newValue;
    std::vector<long double> dSolution;

    solution.reserve(numVar);
    solution = uniformVectorRandomNum(numVar);

    for(int i = 0; i < numIt; i++){
        dSolution = gradient();

        for(int j = 0; j < numVar; j++){
            newValue = solution[j] - alpha * dSolution[j];

            newValue = checkNewValue(newValue);

            solution[j] = newValue;
        }

    }

    showSolution();
}

long double VanillaGradientDescent::uniformRandomNum(long double MinValue, long double MaxValue){
    double f = (double)rand() / RAND_MAX;
    return (long double)(MinValue + f * (MaxValue - MinValue));
}

std::vector<long double> VanillaGradientDescent::uniformVectorRandomNum(int size){
    std::vector<long double> randomNums;

    for(int i = 0; i < size; i++){
        randomNums.push_back(uniformRandomNum(minValue, maxValue));
    }

    return randomNums;
}
