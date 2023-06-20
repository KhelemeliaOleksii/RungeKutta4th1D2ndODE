#include <math.h>
#include <stdio.h>

int calculateCoeff1(const double x, const double t, const double dt,
                    int function(const double x_temp, const double t_temp, double *result_temp),
                    double *result)
{
    function(x, t, result);
    *result *= dt;

    return 0;
};

int calculateCoeff2(const double x, const double t, const double dt,
                    int function(const double x_temp, const double t_temp, double *result_temp),
                    const double coeffPrev,
                    double *result)
{
    function(x + coeffPrev / 2., t + dt / 2., result);
    *result *= dt;
    return 0;
};

int calculateCoeff3(const double x, const double t, const double dt,
                    int function(const double x_temp, const double t_temp, double *result_temp),
                    const double coeffPrev,
                    double *result)
{
    function(x + coeffPrev / 2., t + dt / 2., result);
    *result *= dt;
    return 0;
};

int calculateCoeff4(const double x, const double t, const double dt,
                    int function(const double x_temp, const double t_temp, double *result_temp),
                    const double coeffPrev,
                    double *result)
{
    function(x + coeffPrev, t + dt, result);
    *result *= dt;
    return 0;
}

int calculateNext(const double t, const double xPrev, const double dt,
                  int function(const double tTemp, const double xTemp, double *resultTemp),
                  double *x_next)
{
    double coeff1, coeff2, coeff3, coeff4;

    calculateCoeff1(xPrev, t, dt, function, &coeff1);
    calculateCoeff2(xPrev, t, dt, function, coeff1, &coeff2);
    calculateCoeff3(xPrev, t, dt, function, coeff2, &coeff3);
    calculateCoeff4(xPrev, t, dt, function, coeff3, &coeff4);

    *x_next = x_prev + (coeff1 + (2 * coeff2) + (2 * coeff3) + coeff4) / 6.;
    return 0;
}

int writeResults(const double t, const double x)
{
    fprintf(stdout, "%e\t%e\n", t, x);
    return 0;
};

int writeHeaderForResults()
{
    fprintf(stdout, "t\tvalue\n");
    return 0;
};

int performRungeKutta4th1thODE(const double tInit, const double xInit,
                               const double tFinal, const int numberStep,
                               int function(const double x_temp, const double t_temp, double *result_temp))
{

    double xTemp = xInit;
    double tTemp = tInit;
    double tStep = (tFinal - tInit) / (1. * numberStep);

    writeHeaderForResults();
    writeResults(tTemp, xTemp);

    for (; tTemp < tFinal; )
    {
        calculateNext(tTemp, xTemp, tStep, function, &tTemp);
        tTemp += tStep;

        writeResults(tTemp, xTemp);
    }

    return 0;
}
