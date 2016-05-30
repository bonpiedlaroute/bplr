#include <stdio.h>
#include <math.h>


int main(int argc, char* argv[])
{
    float fahr, celsuis;
    float lower, upper, step;

    lower = -17.8;
    upper = 148.9;
    step = fabsf( ( 5.0 / 9.0) * ( 20.0 - 32.0 ) );

    celsuis = lower;
    
    printf("Celsuis to Fahrenheit conversion table \n");
    printf("---------------------------------------\n\n");
    printf("Celsius\tFahrenheit \n");
    while( celsuis <= upper )
    {
        fahr = ((celsuis * 9.0) / 5.0) + 32.0 ;
        printf("%5.1f\t%5.0f\n",celsuis,fahr);
        celsuis = celsuis + step;
    }
    return 0;
}
