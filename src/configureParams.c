#include <stdio.h>

int configureParams1D1thODE(double *initArgue, double *initValue, double *finalArgue, int *numberStep)
{
    // clrscr();
    printf("Enter Initial Condition\n");
    float ia, iv, fa;
    int ns;
    printf("x0 = ");
    scanf("%f", &ia);
    *initArgue = ia;
    // fprintf(stdout, "Initial argue %e\n", ia);

    printf("y0 = ");
    scanf("%f", &iv);
    *initValue = iv;
    // fprintf(stdout, "Initial value %e\n", iv);

    printf("Enter calculation point xn = ");
    scanf("%f", &fa);
    *finalArgue = fa;
    // fprintf(stdout, "Calculation point %e\n", fa);

    printf("Enter number of steps: ");
    scanf("%d", &ns);
    *numberStep = ns;
    // fprintf(stdout, "Initial value %e\n", ns);
    return 0;
}

int configureParams3D2thODE(double *massParticle, double *chargeParticle, double *timeInitial, double *positionInitial[], double *momentumInitial[], double *timeFinal, int *numberStep)
{
    // clrscr();
    // float ti, rxi, ryi, rzi, pxi, pyi, pzi, tf;
    // int ns;

    // // printf("Input initial time t0 = ");
    // // scanf("%f", &ti);
    // *timeInitial = ti;
    // ti = 0;
    // // // fprintf(stdout, "Initial argue %e\n", ia);


    // // Initial position
    // // printf("Input initial velocity v(t=0) = ");
    // rxi = 0;
    // ryi = 0;
    // rzi = 0;
    // // positionInitial[0] = rxi;
    // // positionInitial[1] = ryi;
    // // positionInitial[2] = rzi;

    // // printf("Input initial velocity v(t=0) = ");
    // // scanf("%f", &vi);
    // // *velocityInitial = vi;

    // // printf("Enter calculation final timepoint t = ");
    // // scanf("%f", &tf);
    // // *timeFinal = tf;
    // // // fprintf(stdout, "Calculation point %e\n", fa);

    // // printf("Enter number of steps: ");
    // // scanf("%d", &ns);
    // // *numberStep = ns;
    // // fprintf(stdout, "Initial value %e\n", ns);
    return 0;
}