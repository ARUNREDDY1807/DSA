#include<stdio.h>

void library(char,int);

 int main()
 {
   char type;
   int days;
   printf("Enter the char\n");
   scanf("%c",&type);
   printf("Enter the days\n");
   scanf("%d",&days);
   library(type,days);
   return 0;
 }
 void library(char type,int days)
 {
     float fine;
     switch(type)
     {
         case'C':if(days>0 && days<=5)
                 {
                     fine=0.5*days;
                     printf("%f",fine);
                 }
                 else if(days>5 && days<=10)
                 {
                     fine=2.5+(days-5)*1;
                     printf("%f",fine);
                 }
                 else if(days>10 && days<=15)
                 {
                     fine=2.5+5+(days-10)*5;
                     printf("%f",fine);
                 }
                 else
                 {
                     printf("membership cancelled");
                 }
                 break;
        case'M':if(days>0 && days<=5)
                 {
                     fine=1*days;
                     printf("%f",fine);
                 }
                 else if(days>5 && days<=10)
                 {
                     fine=5+(days-5)*2;
                     printf("%f",fine);
                 }
                 else if(days>10 && days<=15)
                 {
                     fine=15+(days-10)*10;
                     printf("%f",fine);
                 }
                 else
                 {
                     printf("membership cancelled");
                 }
                 break;
                 default:printf("Invalid input");
                 break;
     }
 }
