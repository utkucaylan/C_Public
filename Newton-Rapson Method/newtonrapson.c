/*
@author: utkucaylan
=============================================================================================
Numberical Methods 
    --> Roots of Equations (i. Bracketing ii. Open iii. Roots of Polynomials)
        --> Open Methods: Only a single starting value of x is required
                          i.   Simple Fixed-Point Iteration
                          ii.  Newton Rapson Method
                          iii. Secant Method
                          iv.  Brent`s Method 
                          v.   Multiple Roots
                          vi.  Systems of Nonlinear Equations
                          
            --> Newton-Rapson Method
Perhaps the most widely used of all root-locating formulas is the Newton-Raphson equation. 
If the initial guess at the root is xi, a tangent can be extended from the point[xi, f (xi)].
The point where this tangent crosses the x axis usually represents an improved estimate of
the root.
P.S. See the figures for more details.
=============================================================================================

Problem: Use Newton-Raphson method to estimtate the root of f(x) = e^{−x} − x, 
employing an initial guess of x_0 = 0.
*/

#include <stdio.h>
#include <math.h>

int main() {
  double x_i = 1e-10;
  int counter = 0;
  while (counter < 100) {
    counter++;
    // compute the main function
    double x_ii = exp(-x_i); 

    // percentage error
    double delta_x = fabs((x_ii - x_i)/x_i*100);
    x_i = x_ii;
  
    printf("The percentage error %.8f\n", delta_x);
    if (delta_x < 1e-6) {
      printf("The total number of iterations is %d\n", counter);
      printf("The root of the given function is %.4f\n", x_i);
      break;
    }
  }
  return 0;
}