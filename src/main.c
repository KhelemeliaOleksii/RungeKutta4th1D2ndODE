//  /////////////
//  After   https://www.compadre.org/PICUP/resources/Numerical-Integration/
//          https://www.engr.colostate.edu/~thompson/hPage/CourseMat/Tutorials/CompMethods/Rungekutta.pdf
// relativistic motion - http://kfe.fjfi.cvut.cz/~vachal/edu/nme/cviceni/09_ODE/DOCS/relativistic_motion.pdf

//  ////////////

#include <stdio.h>
#include <math.h>
#include <conio.h>

#include "../include/configureParams.h"
#include "../include/performRungeKutta4th1thODE.h"

struct ElectricFieldCartesian
{
    double Ex;
    double Ey;
    double Ez;
};

struct MagneticFieldCartesian
{
    double Bx;
    double By;
    double Bz;
};

struct FieldsCartesian
{
    struct ElectricFieldCartesian eleFldCart;
    struct MagneticFieldCartesian magFldCart;
};

struct PositionParticleCartesian
{
    double x;
    double y;
    double z;
};

struct MomentumParticleCartesian 
{
    double px;
    double py;
    double pz;
};

struct CoordsCartesian
{
    struct PositionParticleCartesian posPrtclCart;
    struct MomentumParticleCartesian momPrtclCart;
};



int testFunction(const double value, const double argue, double *result)
{
    *result = argue*argue*argue;
    return 0;
}

int testFunction1(const double value, const double argue, double *result)
{
    *result = (value * value - argue * argue) / (value * value + argue * argue);
    return 0;
}

int testFunction2(const double value, const double argue, double *result)
{
    *result = exp(argue);
    return 0;
}

int testFunction3(const double value, const double argue, double *result)
{
    *result = sin(argue);
    return 0;
}

int calculateFunction(const double x, const double t, double *value)
{
    return 0;
};

int main()
{
    double timeInitial, coordInitial, timeFinal;
    int numberStep;

    configureParams1D1thODE(&timeInitial, &coordInitial, &timeFinal, &numberStep);

    // printf("intial time %f\n", timeInitial);
    // printf("Initial coord %f\n", coordInitial);
    // printf("Initial velocity %f\n", velocityInitial);
    // printf("Time final %f\n", timeFinal);
    // printf("NUmber of steps %d\n", numberStep);
    
    performRungeKutta4th1thODE(timeInitial, coordInitial, timeFinal, numberStep, testFunction);


    printf("Press any key to exit...\n");
    getch();

    return 0;
}