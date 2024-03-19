#include<stdio.h>

float cricket(char type,int runs)
{
    switch(type)
    {
    case'A':if(runs>0&&runs<=30)
            printf("The payment is 20 lakhs");
            else if(runs>=31&&runs<=35)
            printf("The payment is 50 lakhs");
            else if(runs>=36&&runs<=40)
            printf("The payment is 1 crore");
            else if(runs>=41&&runs<=45)
            printf("The payment is 2 crore");
            else
            printf("The payment is 5 crore");
            break;
    case'B':if(runs>0&&runs<=30)
            printf("The payment is 10 lakhs");
            else if(runs>=31&&runs<=35)
            printf("The payment is 40 lakhs");
            else if(runs>=36&&runs<=40)
            printf("The payment is 80 lakhs");
            else if(runs>=41&&runs<=45)
            printf("The payment is 1 crore");
            else
            printf("The payment is 2 crore");
            break;
    case'C':if(runs>0&&runs<=30)
            printf("The payment is 5 lakhs");
            else if(runs>=31&&runs<=35)
            printf("The payment is 30 lakhs");
            else if(runs>=36&&runs<=40)
            printf("The payment is 60 lakhs");
            else if(runs>=41&&runs<=45)
            printf("The payment is 80 lakhs");
            else
            printf("The payment is 1 crore");
            break;
            default:printf("invalid input");
    }


}
int main()
{
     char type;
     int runs;
     float C;
     printf("Enter the character type(A OR B OR C)\n");
     scanf("%c",&type);
     printf("\n Enter the runs\n");
     scanf("%d",&runs);
     C=cricket(type,runs);
     return 0;

}
