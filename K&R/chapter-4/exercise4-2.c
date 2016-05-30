#include <stdio.h>
#include <ctype.h>



int i = 0;

double m_atof_without_e(char s[])
{
    double val;
    int sign;
    double power = 0.0;

    for(i = 0; isspace(s[i]); i++) ;

    sign = (s[i] == '-') ? -1 : 1;

    if( s[i] == '+' || s[i] == '-' )
        i++;

    for( val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    if( s[i] == '.' )
        i++;

    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '-');
        power *= 10.0;
    }

    return sign * val / power ;

}

double m_atof_with_e(char s[])
{
    double val, power = 1.0;
    int exp = 0;
    int sign = 1, j = 0;

    val = m_atof_without_e(s);

    if( s[i] == 'e' )
    {
        i++;

        sign = (s[i] == '-') ? -1 : 1;

        if( s[i] == '+' || s[i] == '-' )
            i++;

        for( exp = 0; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');

        for( j = 0; j < exp; j++)
            power = power * 10.0;

    }

    if(sign > 0)
        val = val * power;
    else
        val = val / power;

    return val ;
}

int main(int argc, char *argv[])
{
    double val= 0.0;

    val = m_atof_with_e("123.45e-6");

    printf("Value : %f \n",val);

    return 0;
}
