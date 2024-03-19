#include<stdio.h>
int main()
{
   char designation;
   float salary,increment,total_salary;
   printf("Enter designation\n");
   scanf("%c",&designation);
   printf("Enter the salary\n");
   scanf("%f",&salary);
   switch(designation)
{
       case'S':if(salary>=100000&&salary<=200000)
            {
             increment=salary*0.05;
             total_salary=salary+increment;
             printf("Total_salary is %.2f\n",total_salary);
             }
             else if(salary>=70000&&salary<100000)
             {
                 increment=salary*0.03;
                 total_salary=salary+increment;
                 printf("Total salary is %.2f\n",total_salary);
             }
              else if(salary>=40000&&salary<70000)
              {
                  increment=salary*0.03;
                  total_salary=salary+increment;
                  printf("Total salary is %.2f\n",total_salary);
              }
                    break;
        case'A':if(salary>=80000&&salary<=160000)
        {
            increment=salary*0.04;
            total_salary=salary+increment;
            printf("Total salary is %.2f\n",total_salary);
        }
                else if(salary>=50000&&salary<80000)
                {
                    increment=salary*0.05;
                    total_salary=salary+increment;
                    printf("Total salary is %.2f\n",total_salary);
                }
                 break;
        case'P':if(salary>=100000&&salary<=200000)
        {
            increment=salary*0.09;
            total_salary=salary+increment;
            printf("Total salary is %.2f\n",total_salary);
        }
                else if(salary>=60000&&salary<=80000)
                {
                    increment=salary*0.07;
                    total_salary=salary+increment;
                    printf("Total salary is % .2f\n",total_salary);
                }

                else if(salary>=40000&&salary<60000)
                {
                    increment=salary*0.05;
                    total_salary=salary+increment;
                    printf("Total salary is % .2f\n",total_salary);
                }
                break;
                default:printf("invalid input");
}
            return 0;
}




