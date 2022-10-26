#include<bits/stdc++.h>
using namespace std;
struct SJTF{
    int pr,at,bt,rt,wt,tt,ft;
};
bool compare(SJTF x,SJTF y)
{
    if(x.at==y.at)
        return x.bt<y.bt;
    return x.at<y.at;
}
bool compare1(SJTF x,SJTF y)
{
    if(x.bt==y.bt)
        return x.at<y.at;
    return x.bt<y.bt;
}
bool compare2(SJTF x,SJTF y)
{
    return x.pr<y.pr;
}
int main()
{
    int n,i,j,k,s1,s2,s3,avrt,avwt,avtt;
    float f1,f2,f3;
    struct SJTF p[100];
    cout<<"Enter Number of process :";
    cin>>n;
    cout<<"Enter Arrive-Time and Burst-Time for each process"<<endl;
    for(i=0; i<n; i++)
    {
        p[i].pr=i+1;
        cin>>p[i].at>>p[i].bt;
    }
    sort(p,p+n,compare);
    p[0].ft=p[0].bt;
    p[0].rt=0;
    p[0].tt=p[0].bt;
    p[0].wt=0;
    s1=p[0].rt;
    s2=p[0].wt;
    s3=p[0].tt;
    for(i=1; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            if(p[j].at<=p[i-1].ft)
            {
                k=j+1;
            }
        }
        sort(p+i,p+k,compare1);
        p[i].ft=p[i-1].ft+p[i].bt;
        p[i].rt=p[i-1].ft-p[i].at;
        s1+=p[i].rt;
        p[i].tt=p[i].ft-p[i].at;
        s3+=p[i].tt;
        p[i].wt=p[i].tt-p[i].bt;
        s2+=p[i].wt;
    }
    avrt=s1/n;
    avwt=s2/n;
    avtt=s3/n;
    f1=(float)s1/(float)n;
    f2=(float)s2/(float)n;
    f3=(float)s3/(float)n;
    if(f1-avrt>=0.5)
        avrt++;
    if(f2-avwt>=0.5)
        avwt++;
    if(f3-avtt>=0.5)
        avtt++;
    sort(p,p+n,compare2);
    cout<<"Process\t Arrive-Time\t Burst-Time\t Response-Time\t Wating-Time\t Turn around-Time\t"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<p[i].pr<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].rt<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tt<<endl;
    }
    cout<<"Average of R.T. = "<<avrt<<endl;
    cout<<"Average of W.T. = "<<avwt<<endl;
    cout<<"Average of T.T. = "<<avtt<<endl;
    return 0;
}
