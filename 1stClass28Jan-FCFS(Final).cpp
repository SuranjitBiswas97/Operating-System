#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
struct FCFS
{
    int pid;
    int at;
    int bt;
};
FCFS pr[100];
int n, m, rt[100], wt[100], tt[100];
bool comp(FCFS a, FCFS b)
{
    return a.at<b.at;
}
void response_time()
{
    m=0;
    rt[0]=0;
    for( int i=1; i<n; i++)
    {
        m=m+pr[i-1].bt;//cumulative sum of burst time
        rt[i]=m-pr[i].at;//subtract the arrive time of current process
    }
}
void turnaround_time()
{
    m=pr[0].bt;
    tt[0]=pr[0].bt-pr[0].at;// first process turn around time
    for( int i=1; i<n; i++)
    {
        m=m+pr[i].bt;//cumulative sum of burst time
        tt[i]=m-pr[i].at;//subtract the arrive time of the current process
    }
}
void waiting_time()
{
    for( int i=0; i<n; i++)
    {
        wt[i]=tt[i]-pr[i].bt;//subtract the current process turn around time to it's burst time

    }
}
void average_time()
{
    int rt_, wt_, tt_, avg_rt, avg_wt, avg_tt;
    double a, b, c;
    rt_=wt_=tt_=0;
    for( int i=0; i<n; i++)
    {
        rt_+=rt[i];
        wt_+=wt[i];
        tt_+=tt[i];
    }
    avg_rt=rt_/n;
    a=(double)rt_ / (double)n;
    if(a-avg_rt>=0.5) avg_rt++;

    avg_wt=wt_/n;
    b=(double)wt_ / (double)n;
    if(b-avg_wt>=0.5) avg_wt++;

    avg_tt=tt_/n;
    c=(double)tt_ / (double)n;
    if(c-avg_tt>=0.5) avg_tt++;

    for( int i=0; i<n; i++)
    {
        printf("Process Id Arrive Time Burst time Response Time Waiting Time TurnAround Time\n");
        printf("%d\t %d\t %d\t %d\t %d\t %d\t \n", pr[i].pid, pr[i].at, pr[i].bt, rt[i], wt[i], tt[i]);
    }
    printf("%d\t %d\t %d\t \n", avg_rt, avg_wt, avg_tt);
}
int main()
{
    int i, j, k, t, p, cas=1;
    //freopen("in.txt", "r", stdin);
    printf("First Come First Serve\n");
    printf("Number of Processes: ");
    while(scanf("%d", &n)==1)
    {
        printf("Process id:\n");
        for( i=0; i<n; i++)
        {
            scanf("%d", &m);
            pr[i].pid=m;
        }
        printf("Arrive Time:\n");
        for( i=0; i<n; i++)
        {
            scanf("%d", &m);
            pr[i].at=m;
        }
        printf("Burst Time:\n");
        for( i=0; i<n; i++)
        {
            scanf("%d", &m);
            pr[i].bt=m;
        }
        sort( pr, pr+n, comp);
        response_time();
        turnaround_time();
        waiting_time();
        average_time();
    }
    return 0;
}
