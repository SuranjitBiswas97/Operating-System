#include<bits/stdc++.h>
using namespace std;
struct PRIORITY
{
    int pid;
    int at;
    int bt;
    int ct;    //completion time
    int rt;
    int wt;
    int tt;
    int prt;
    int pri;

};
int m;
bool compare(PRIORITY a, PRIORITY b)
{

    if(a.at==b.at)
        return a.pri >b.pri;
    return a.at <b.at;

}
bool compareb(PRIORITY a, PRIORITY b)
{

    if(a.pri == b.pri)
    {
        return a.at<b.at && a.at<=m;
    }
    return a.pri>b.pri && a.at<=m;

}
PRIORITY sj[100];
int main()
{
    int i,j,k,t[100],p=0,cas=1,n;

    printf("Priority Scheduling\n");
    printf("Number of processes:");
    while(scanf("%d", &n)==1)
    {
        int avg_rt=0, avg_wt=0, avg_tt=0;

        for(i=0; i<n; i++)
        {

            sj[i].pid=i+1;
        }
        printf("Arrive Time:\n");
        for(i=0; i<n; i++)
        {
            scanf("%d", &m);
            sj[i].at=m;
        }
        printf("Burst Time:\n");
        for(i=0; i<n; i++)
        {
            scanf("%d", &m);
            sj[i].bt=m;
        }
        printf("Priority:\n");
        for(i=0; i<n; i++)
        {
            scanf("%d",&m);
            sj[i].pri = m;
        }
        sort(sj, sj+n, compare);
        printf("R.T\tW.T\tT.T\n");
        sj[0].ct = sj[0].bt;
        sj[0].rt =0;
        sj[0].tt = sj[0].ct;
        sj[0].wt=sj[0].tt-sj[0].bt;
        for(i=0; i<n; i++)
        {

            m= sj[i-1].ct;
            sort(sj+i, sj+n, compareb);
            sj[i].ct = sj[i-1].ct+sj[i].bt;
            sj[i].rt = sj[i-1].ct- sj[i].at;
            sj[i].tt = sj[i].ct -sj[i].at;
            sj[i].wt = sj[i].tt-sj[i].bt;

            printf("%d\t%d\t%d\n",sj[i].rt,sj[i].wt,sj[i].tt);

            avg_rt=avg_rt+sj[i].rt;
            avg_wt=avg_wt+sj[i].wt;
            avg_tt=avg_tt+sj[i].tt;
        }

        int art, awt, att;
        art=avg_rt;
        awt=avg_wt;
        att=avg_tt;

        avg_rt=avg_rt/n;
        if((art-(avg_rt*n))>= n-(art-(avg_rt*n)))
            avg_rt=avg_rt+1;
        avg_wt=avg_wt/n;
        if((awt-(avg_wt*n))>= n-(awt-(avg_wt*n)))
            avg_wt=avg_wt+1;
        avg_tt=avg_tt/n;
        if((att-(avg_tt*n))>= n-(att-(avg_tt*n)))
            avg_tt=avg_tt+1;
        printf("Avg. R.T. = %d\tAvg. W.T. = %d\tAvg. T.T. = %d\n", avg_rt, avg_wt, avg_tt);

    }
}
