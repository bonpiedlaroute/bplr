#include <stdio.h>

static char daytab[2][13] =
{
    {0,31,28,31,30,31,30,31,31,30,31,30,31},
    {0,31,29,31,30,31,30,31,31,30,31,30,31}
};

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
            if(leap && (day > 29 || day <= 0 ) )
                return -1;
            
            if(!leap && (day > 28 || day <= 0 ) )
                return -1;

            break;
        }
        default:
        {
            return -1;
        }

    }
    
    for( i = 1; i < month; i++)
        day += *(*(daytab + leap) + i );
    
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
        yearday -= *(*(daytab + leap) + i );

    *pmonth = i;
    *pda = yearday;
}

int main(int argc, char * argv[])
{
    int nbday = 0, day = 0, month = 0 ;
    nbday = day_of_year(2013, 05, 12 );
    
    month_day(2013, nbday, &month, &day);

    printf("month : %d, day : %d, nbday : %d\n",month, day, nbday);

    return 0;
}
