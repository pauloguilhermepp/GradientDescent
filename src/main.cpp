#include "GradientDescent/MomentumGradientDescent/MomentumGradientDescent.cpp"
#include "GradientDescent/VanillaGradientDescent/VanillaGradientDescent.cpp"

long double evaluationFunction(std::vector<long double> vector) {
  long double sum = 0;

  for (int i = 0; i < vector.size(); i++)
    sum += vector[i];

  return sum;
}

long double alternativeEvaluationFunction(std::vector<long double> vector) {
  long double sum = 0;

  for (int i = 0; i < vector.size(); i++)
    sum += vector[i] * vector[i];

  return sum;
}

int main() {

  VanillaGradientDescent vgd(10, 7, 0.1, 0.1, 0, 1, &evaluationFunction);
  vgd.run();

  std::cout << std::endl;

  MomentumGradientDescent mgd(10, 7, 0.1, 0.1, 0.1, 0, 1, &evaluationFunction);
  mgd.run();

  return 0;
}
