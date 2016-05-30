#include <stdio.h>


int day_of_year(int year, int month, int day)
{
    int i, leap;
    
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0 ;    

    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
        {
            if( day > 31 || day <= 0 )
                return -1;

            break;                    
        }
        case 4:
        case 6:
        case 9:
        case 11:
        {
            if( day > 30 || day <= 0 )
                return -1;
            break;
        }
        case 2:
        {
            if(leap && (day > 29 || day <= 0 )
                return -1;
            
            if(!leap && (day > 28 || day <= 0 )
                return -1;

            break;
        }

        default:
        {
            return -1;
        }

    }
    
    for( i = 1; i < month; i++)
        day += daytab[leap][i];
    
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pda)
{
    int i, leap;

    leap = year%4 == 0 && year%100 != 0 || year%400 == 0 ;

    if(leap && yearday > 366)
        return;
    
    if(!leap && yearday > 365)
        return;

    for(i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];

    *pmonth = i;
    *pday = yearday;
}


int main(int argc, char *argv[])
{


    return 0;
}
