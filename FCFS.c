#include<stdio.h>
int main()
{
    int  p[100],at[100],bt[100],ct[100],tat[100],wt[100],vis[100]= {0},ser[100],i,j,temp=0,n;
    float awt=0,atat=0;
    printf("enter no of proccess you want:");
    scanf("%d",&n);
    printf("enter %d arrival time and burst time:\n",n);
    for(i=0; i<n; i++)
    {
        p[i]=i+1;
        scanf("%d %d",&at[i],&bt[i]);
    }
    int ans=0;
    for(j=0; j<n;)
    {
        int mn=1000000000,idx=1000000000;
        for(i=0; i<n; i++)
        {
            if(vis[i]==0)
            {
                if(ans>=at[i] && mn>at[i])
                {
                    mn=at[i];
                    idx=i;
                }
            }
        }
        if(idx==1000000000)
        {
            ans++;
        }
        else
        {
            ans+=bt[idx];
            vis[idx]=1;
            ct[idx]=ans;
            ser[j]=p[idx];
            j++;
        }
    }
    printf("\np\t A.T\t B.T\t C.T\t TAT\t WT");
    for(i=0; i<n; i++)
    {
        tat[i]=ct[i]-at[i];
        wt[i]=tat[i]-bt[i];
        atat+=tat[i];
        awt+=wt[i];
    }
    atat=atat/n;
    awt=awt/n;
    for(i=0; i<n; i++)
    {
        printf("\nP%d\t %d\t %d\t %d \t %d \t %d",ser[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }
    printf("\naverage turnaround time is %f",atat);

    printf("\naverage wating timme is %f",awt);
    return 0;
}
