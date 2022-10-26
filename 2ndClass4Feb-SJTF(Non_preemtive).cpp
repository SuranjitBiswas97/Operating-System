#include<bits/stdc++.h>
using namespace std;
struct SJTF
{
    int pid;
    int at;
    int bt;
    int ct;
    int rt;
    int wt;
    int tt;
};
SJTF pr[100];
int n,m;
bool compare(SJTF a,SJTF b)
{
    return(a.at<b.at);
}
bool compareb(SJTF a,SJTF b)
{
    if(a.at==b.bt)
        return(a.bt<b.bt);
    return(a.at<b.at);
}
void waitingtime(SJTF proc[],int n,int wt[])
{
    wt[0]=0;
    int i=0;
    for(i=0; i<n; i++)
        wt[i]=proc[i-1].bt+wt[i-1];
}
void turnaround_time(SJTF proc[],int n,int wt[],int tt[])
{
    int i;
    for(i=1; i<n; i++)
        tt[i]=proc[i].bt+wt[i];
}

int main()
{
    int i,j,k,t,p,cas=1;
    printf("Shortest Job Time First\n");
    printf("Number of processes: ");
    while(scanf("%d",&n)==1)
    {
        printf("input of process num,Arrive time,BrustTime:\n");
        for(i=0; i<n; i++)
        {
            scanf("%d %d %d",&pr[i].pid,&pr[i].at,&pr[i].bt);
        }
        sort (pr,pr+n,compare);
        printf("process time\tArrive Time\tBurst Time\tC.T\tR.T\tW.T\tT.T\n");
        pr[0].ct=pr[0].at+pr[0].bt;
        pr[0].rt=0;
        pr[0].tt= pr[0].ct-pr[0].at;
        pr[0].wt=pr[0].tt-pr[0].bt;
        for(i=1; i<n; i++)

        {
            {
                m=pr[i-1].ct;
                sort(pr+i,pr+n,compareb);
                t=pr[i-1].ct+pr[i].bt;
                pr[i].ct=t;
            }
            pr[i].ct=pr[i-1].ct+pr[i].bt;
            pr[i].rt=pr[i-1].ct-pr[i].at;
            pr[i].tt=pr[i].ct-pr[i].at;
            pr[i].wt=pr[i].tt-pr[i].bt;

        }
        for(i=0; i<n; i++)
            printf("%d\t\t%d\t\t%d \t\t%d \t%d \t%d \t%d\n",pr[i].pid,pr[i].at,pr[i].bt,pr[i].ct,pr[i].rt,pr[i].wt,pr[i].tt);

    }
    return 0;
}
