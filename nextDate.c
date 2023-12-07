
#include <stdio.h>
int monthCheck(int dateDay, int dateMonth, int dateYear)
{
    int maxMonthDay;
    if(dateMonth<=12 && dateMonth>= 1){
        
        if(dateMonth == 1 || dateMonth == 3 || dateMonth == 5 || dateMonth == 7 || dateMonth ==8 || dateMonth == 10 || dateMonth == 12)
        {
            maxMonthDay = 31;
        }
        else if(dateMonth == 2 && dateYear % 4 == 0)
        {
            maxMonthDay = 29;
        }
        else if(dateMonth == 2 && dateYear % 4 != 0)
        {
            maxMonthDay = 28;
        }
        else
        {
            maxMonthDay = 30;
        }
        return maxMonthDay;
    }
    else
    {
        if(dateDay != 0 || dateMonth != 0 || dateYear != 0)
        {
         printf("This is not a valid date! \n");
         return 0;
        }
    }
    
}

int dayCheck(int maxMonthDay, int dateDay, int dateMonth, int dateYear)
{
    if(dateDay>maxMonthDay || dateDay == 0)
    {
        if(dateDay != 0 || dateMonth != 0 || dateYear != 0)
        {
          printf("This is not a valid date! \n");
          return 0;
        }
    }
}

int calculateMonth(int dateDay,int dateMonth,int maxMonthDay)
{
    if(dateDay>maxMonthDay)
    {
        dateMonth++;
        dateDay = 1;
    }
    
    return dateMonth;
}

int main()
{
 int dateDay,dateMonth,dateYear,maxMonthDay,dayCheckResult;
 do{
     printf("Enter a date (0 0 0 to quit): ");
     scanf("%d",&dateDay);
     scanf("%d",&dateMonth);
     scanf("%d",&dateYear);
     maxMonthDay = monthCheck(dateDay,dateMonth,dateYear);
     if(maxMonthDay != 0)
     {
        dayCheckResult = dayCheck(maxMonthDay,dateDay,dateMonth,dateYear);
        if (dayCheckResult != 0)
            {
                int previousDateday = dateDay;
                int previousMonthday = dateMonth;
                int previousYearday = dateYear;
                
                dateDay++;
                if(dateDay>maxMonthDay)
                {
                    dateMonth++;
                    dateDay = 1;
                }
                if(dateMonth>12)
                {
                    dateYear++;
                    dateMonth = 1;
                }
                printf("The next day of %02d %02d %d is: %02d %02d %d \n",previousDateday,previousMonthday,previousYearday,dateDay,dateMonth,dateYear);
            }
     }
 }
 while(dateDay != 0 || dateMonth != 0 || dateYear != 0);
 printf("Thanks for using our calendar!");
}



