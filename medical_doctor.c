#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct doctor
{
  char name[20],spec[20],hospital[20];
  int in_hr,in_min,out_hr,out_min;
  int res_hr,res_min;
}DOCTOR;

void read_details (DOCTOR *dptr,int n)
{
    int i;
    printf("enter doctor details\n");
    printf("Name,specialisation<hospital,in_time,out_time\n");
    for(i=0;i<n;i++)
    {
        scanf("%s%s%s%d%d%d",dptr->name,dptr->spec,dptr->hospital,&dptr->in_hr,&dptr->in_min,&dptr->out_hr,&dptr->out_min);
        dptr++;
    }
}

void compute_duration(DOCTOR *dptr,int n)
{
        int i;
        for (i=0;i<n;i++)
        {
            (dptr+i)->res_hr=(dptr+i)->out_hr-(dptr)->in_hr;
            (dptr+i)->res_min=(dptr+i)->out_min-(dptr)->in_min;
            if((dptr+i)->res_min<0)
            {
                (dptr+i)->res_hr--;
                (dptr+i)->res_min=60+(dptr+i)->res_min;
            }
        }
}

void search (DOCTOR *dptr,int n,char sname[20])
{
        int i, status=0, index=0;
        for (i=0;i<n;i++)
        {
            if(strcmp((dptr+i)->name,sname)==0)
            {
                status=1;
                index=i;
                break;
            }
        }
        if(status==1)
        {
            printf("%s%s%s%d%d%d\n"),(dptr+index)->name,(dptr+index)->spec,(dptr+index)->hospital,(dptr+index)->in_hr,(dptr+index)->in_min,(dptr+index)->out_hr,(dptr+index)->out_min;
        }
        else
            printf("no doctor found");
}
int main()
{
    int n;
    DOCTOR *dptr;
    char sname[20];
    printf("Enter the number of doctorr details to store\n");
    scanf("%d",&n);
    dptr=(DOCTOR*)malloc(n*sizeof(DOCTOR));
    if(dptr==0)
    {
        printf("Memory not allocated\n");
    }
    else
    {
        read(dptr,n);
        compute_duration(dptr,n);
        dsiplay(dptr,n);
        printf("Enter the doctor name to search\n");
        scanf("%s",sname);
        search(dptr,n,sname);
    }
    free(dptr);
}
