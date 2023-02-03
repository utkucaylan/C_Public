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
                          
            --> Brent`s Method
            
TO BE DEBUGGED!!!

P.S. See the figures for more details.
=============================================================================================

Problem: Use secant method to locate the root of f(x) = e^{−x} − x. Start
with initial estimates of x_{-1} = 0 and x_{0} = 1
*/
#include<stdio.h>
#include<math.h>

#define MAX_ITER 100000
#define TOL 0.000001

double f(double x)
{
    return (x + 7) * (x - 1) * (x - 1);
}

double brentsmethod(double xl, double xu)
{
    double a = xl;
    double b = xu;
    double fa = f(a);
    double fb = f(b);
    double c = a;
    double fc = fa;
    double d = b - c;
    double e = d;
    int counter = 0;

    while (1)
    {
        counter++;
        if (counter > MAX_ITER)
        {
            printf("Maximum number of iterations is reached\n");
            break;
        }
        if (fb == 0)
        {
            break;
        }
        if (fa * fb > 0)
        {
            a = c;
            fa = fc;
            d = b - c;
            e = d;
        }
        if (fabs(fa) < fabs(fb))
        {
            c = b;
            b = a;
            a = c;
            fc = fb;
            fb = fa;
            fa = fc;
        }
        double m = 0.5 * (a + b);
        if (fabs(m) <= TOL || fb == 0)
        {
            break;
        }
        if (fabs(e) > TOL && fabs(fc) > fabs(fb))
        {
            double s = fb / fc;
            double p, q;
            if (a == c)
            {
                p = 2 * m * s;
                q = 1 - s;
            }
            else
            {
                q = fc / fa;
                double r = fb / fa;
                p = s * (2 * m * q * (q - r) - (b - c) * (r - 1));
                q = (q - 1) * (r - 1) * (s - 1);
            }
            if (p > 0)
            {
                q = -q;
            }
            else
            {
                p = -p;
            }
            if (2 * p < 3 * m * q - fabs(TOL * q) && p < 0.5 * e * q)
            {
                e = d;
                d = p / q;
            }
            else
            {
                d = m;
                e = m;
            }
        }
        else
        {
            d = m;
            e = m;
        }
        c = b;
        fc = fb;
        if (fabs(d) > TOL)
        {
            b = b + d;
        }
        else
        {
            b = b - TOL;
        }
        fb = f(b);
    }
    return b;
}


int main()
{
    double xl = -10.0;
    double xu = 0.0;
    double root = brentsmethod(xl, xu);
    printf("The root of the function is %.10lf\n", root);
    return 0;
}
