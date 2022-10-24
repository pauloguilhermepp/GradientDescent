#include "MomentumGradientDescent.hpp"

MomentumGradientDescent::MomentumGradientDescent(
    int NumVar, int NumIt, long double Alpha, long double Beta, long double Dx,
    long double MinValue, long double MaxValue,
    long double (*EvaluationFunc)(std::vector<long double>))
    : VanillaGradientDescent(NumVar, NumIt, Alpha, Dx, MinValue, MaxValue,
                             *EvaluationFunc) {
  beta = Beta;
}

void MomentumGradientDescent::run() {
  long double newValue, varChange;
  std::vector<long double> dSolution, change(numVar, 0.0);

  solution.reserve(numVar);
  solution = uniformVectorRandomNum(numVar);

  for (int i = 0; i < numIt; i++) {
    dSolution = gradient();
    for (int j = 0; j < numVar; j++) {
      varChange = alpha * dSolution[j] + beta * change[j];
      newValue = solution[j] - varChange;
      newValue = checkNewValue(newValue);
      change[j] = varChange;
      solution[j] = newValue;
    }
  }

  showSolution();
}
