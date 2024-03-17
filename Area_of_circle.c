#include<stdio.h>
int main()
{
    float R,AC,VC;
    printf("enter the value of R");
    scanf("%f",&R);
    AC=3.142*R*R;
    VC=(4/3)*3.142*R*R*R;
    printf("AC=%f and VC=%f",AC,VC);
}
