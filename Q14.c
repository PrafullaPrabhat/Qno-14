#include<stdio.h>
 

int main()

{

int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat,x;
  
printf("Enter Total Number of Process:");

scanf("%d",&n);
 
  
printf("\nEnter Burst Time and Priority\n");
    
for(x=0;x<n;x++)
 
{
        
printf("\nP[%d]\n",x+1);
      
printf("Burst Time:");
   
scanf("%d",&bt[x]);
  
printf("Priority:");
   
scanf("%d",&pr[x]);
        
p[x]=x+1;           
    
}
 
    
for(x=0;x<n;x++)
    
{
        
pos=x;
        
for(j=x+1;j<n;j++)

{
            
if(pr[j]<pr[pos])
                
pos=j;
        
}
 
        
temp=pr[x];
        
pr[x]=pr[pos];
        
pr[pos]=temp;
 
        
temp=bt[x];
        
bt[x]=bt[pos];
        
bt[pos]=temp;
 
        
temp=p[x];
        
p[x]=p[pos];
        
p[pos]=temp;
    
}
 
    
wt[0]=0;    
    
for(x=1;x<n;x++)
    
{
        
wt[x]=0;
        
for(j=0;j<x;j++)
            
wt[x]+=bt[j];
 
        
total+=wt[x];
    
}


avg_wt=total/n;      
    
total=0;
 
    
printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    
for(x=0;x<n;i++)
 
{
        
tat[x]=bt[x]+wt[x];   
        
total+=tat[x];
        
printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[x],bt[x],wt[x],tat[x]);
    
}

avg_tat=total/n;  
    
printf("\n\nAverage Waiting Time=%d",avg_wt);
    
printf("\nAverage Turnaround Time=%d\n",avg_tat);
 
    
return 0;

}
