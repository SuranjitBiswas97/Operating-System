#include<bits\stdc++.h>
using namespace std;
struct FCFS
{
    int pid;
    int at;
    int bt;

};
FCFS pr[100];
int i,n,m,rt[100],tt[100],wt[100];

bool compare(FCFS a, FCFS b)
{
    return a.at<b.at;
}
void response_time()
{
    m=0;
    rt[0]=0;
    for(int i=1; i<n;i++)
    {
        m=m+pr[i-1].bt;
        rt[i]=m-pr[i].at;
    }
    for(int i=1;i<n;i++)
    {
        printf("%d\n",rt[i]);
    }
    printf("\n");

}
void turnaround_time()
{
    m=pr[0].bt;
    tt[0]=pr[0].bt;
    for(int i=1; i<n;i++)
    {
        m=m+pr[i].bt;
        tt[i]=m-pr[i].at;
    }
    for(int i=1;i<n;i++)
    {
        printf("%d\n",tt[i]);
    }
    printf("\n");


}
void waiting_time()
{
    for(int i=1; i<n; i++)
    {
        wt[i]=tt[i]-pr[i].bt;

    }
    for(int i=1; i<n; i++)
    {
        printf("%d\n",wt[i]);

    }
    printf("\n");
}
int main()
{
    int i,j,k;
    printf("Number of Process:\n");
    scanf("%d\n",&n);
    for(int i=0; i<n; i++)
    {
        scanf("%d %d %d\n",&pr[i].pid,&pr[i].at,&pr[i].bt);
    }
    sort(pr,pr+n,compare);
    void response_time();
    void turnaround_time();
    void waiting_time();


}
