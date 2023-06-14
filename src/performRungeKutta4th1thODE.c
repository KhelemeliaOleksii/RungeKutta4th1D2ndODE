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

int calculateNext(const double x_prev, const double t, const double dt,
                  int function(const double x_temp, const double t_temp, double *result_temp),
                  double *x_next)
{
    double coeff1, coeff2, coeff3, coeff4;

    calculateCoeff1(x_prev, t, dt, function, &coeff1);
    calculateCoeff2(x_prev, t, dt, function, coeff1, &coeff2);
    calculateCoeff3(x_prev, t, dt, function, coeff2, &coeff3);
    calculateCoeff4(x_prev, t, dt, function, coeff3, &coeff4);

    *x_next = x_prev + (coeff1 + (2 * coeff2) + (2 * coeff3) + coeff4) / 6.;
    return 0;
}

int writeResults(const double x, const double t)
{
    fprintf(stdout, "%e\t%e\n", x, t);
    return 0;
};

int writeHeaderForResults()
{
    fprintf(stdout, "t\tvalue\n");
    return 0;
};

int performRungeKutta4th1thODE(const double initArgue, const double initValue,
                               const double finalArgue, const int numberStep,
                               int function(const double x_temp, const double t_temp, double *result_temp))
{

    double tempValue = initValue;
    double tempArgue = initArgue;
    double step = (finalArgue - initArgue) / (1. * numberStep);

    writeHeaderForResults();
    writeResults(tempArgue, tempValue);

    for (; tempArgue < finalArgue; )
    {
        calculateNext(tempValue, tempArgue, step, function, &tempValue);
        tempArgue += step;

        writeResults(tempArgue, tempValue);
    }

    return 0;
}
