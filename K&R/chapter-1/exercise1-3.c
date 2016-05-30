#include <stdio.h>


int main(int argc, char* argv[])
{
    float fahr, celsuis;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    
    printf("Fahrenheit to Celsius conversion table \n");
    printf("---------------------------------------\n\n");
    printf("Fahrenheit\tCelsius \n");
    while( fahr <= upper )
    {
        celsuis = ( 5.0 / 9.0) * ( fahr - 32.0 );
        printf("%5.0f\t%13.1f\n", fahr, celsuis);
        fahr = fahr + step;
    }
    return 0;
}
