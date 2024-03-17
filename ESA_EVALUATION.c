#include<stdio.h>
int main()
{
  int days,kms,T;
  printf("Enter the no. of days\n");
  scanf("%d",&days);
  printf("Enter the kilometres travelled\n");
  scanf("%d",&kms);
  T=travel(days,kms);
  return 0;
}
int travel(int days,int kms)
{
    int charges,driver_allowance,Amount;
    if(days>=1 && days<=3)
    {
        charges=9.5*days*kms;
        driver_allowance=350*days;
        Amount=charges+driver_allowance;
        printf("The amt to be paid:%d",Amount);
    }
    else if(days>=4 && days<=6)
    {
        charges=9.0*days*kms;
        driver_allowance=300*days;
        Amount=charges+driver_allowance;
        printf("The amt to be paid:%d",Amount);
    }
    else if(days>=7 && days<=9)
    {
        charges=8.0*days*kms;
        driver_allowance=250*days;
        Amount=charges+driver_allowance;
        printf("The amt to be paid:%d",Amount);
    }
    else if(days>9)
    {
        printf("Company won't allow to travel");
    }
    else
    {
        printf("Invalid Input");
    }
}
