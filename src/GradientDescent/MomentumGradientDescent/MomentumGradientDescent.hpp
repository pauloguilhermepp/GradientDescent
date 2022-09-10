#include "../VanillaGradientDescent/VanillaGradientDescent.hpp"

#ifndef MOMENTUM__GRADIENT_DESCENT_HPP
#define MOMENTUM__GRADIENT_DESCENT_HPP
class MomentumGradientDescent: public VanillaGradientDescent{
    public:
        MomentumGradientDescent(int numVar, int numIt, long double alpha,
                        long double beta, long double dx,
                        long double minValue, long double maxValue,
                        long double (*evaluationFunc)(std::vector<long double>));
        void run();
    
    protected:
        long double beta;
};

#endif