#include <vector>
#include <iostream>
#include <algorithm>

#ifndef GRADIENT_DESCENT_HPP
#define GRADIENT_DESCENT_HPP
class GradientDescent{
    public:
        GradientDescent(int numVar, int numIt, long double alpha, long double dx,
                        long double minValue, long double maxValue,
                        long double (*evaluationFunc)(std::vector<long double>));
        void run();

    private:
        int numVar, numIt;
        std::vector<long double> solution;
        long double alpha, dx, minValue, maxValue;
        long double (*evaluationFunc)(std::vector<long double>);

        std::vector<long double> gradient();
        long double checkNewValue(long double newValue);
        void showSolution();

        long double uniformRandomNum(long double MinValue, long double MaxValue);
        std::vector<long double> uniformVectorRandomNum(int size);
};
#endif
