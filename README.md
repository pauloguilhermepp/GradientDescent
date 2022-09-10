# Gradient Descent

This repository contains an implementation of the Gradient Descent algorithm using the C++ language. There is also an implementation that inherits this one and uses the momentum optimization. An example of how to use them can be found in the Main.cpp file. Some of the parameters that can be modified for each execution of the algorithm are:

* **NumVar**: Number of variables.
* **NumIt**: Number of iterations.
* **Alpha**: Learning rate.
* **Dx**: Differential value used to calculate the derivative of the *EvaluationFunc*.
* **MinValue**: Minimum value of a variable in the solution.
* **MaxValue**: Maximum value of a variable in the solution.
* **EvaluationFunc**: Function used to evaluate solutions.

And in the class with the momentum optimization, there is also the **beta** parameter, which represents the amount of momentum that will remain from one iteraction to another.