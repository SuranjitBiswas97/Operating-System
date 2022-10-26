#include<bits/stdc++.h>
using namespace std;
struct PS{
    int pr,at,bt,p,rt,wt,tt,ft;
};
bool compeare(PS x,PS y)
{
    if(x.at==y.at)
        return x.p>y.p;
    return x.at<y.at;
}
bool compeare1(PS x,PS y)
{
    if(x.p==y.p)
        return x.at<y.at;
    return x.p>y.p;
}
bool compeare2(PS x,PS y)
{
    return x.pr<y.pr;
}
int main()
{
    struct PS p[100];
    int n,i,j,k,s1,s2,s3,avrt,avwt,avtt;
    float av1,av2,av3;
    cout<<"Enter number of process :";
    cin>>n;
    cout<<"Enteer Arrive-Time,Burst-Time & Priority "<<endl;
    for(i=0; i<n;  i++)
    {
        p[i].pr=i+1;
        cin>>p[i].at>>p[i].bt>>p[i].p;
    }
    sort(p,p+n,compeare);
    p[0].ft=p[0].bt;
    p[0].rt=0;
    s1=p[0].rt;
    p[0].wt=0;
    s2=p[0].wt;
    p[0].tt=p[0].bt;
    s3=p[0].tt;
    for(i=1; i<n; i++)
    {
        for(j=i; j<n; j++)
        {
            if(p[j].at<=p[i-1].ft)
                k=j+1;
        }
        sort(p+i,p+k,compeare1);
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
    av1=(float)s1/(float)n;
    av2=(float)s2/(float)n;
    av3=(float)s3/(float)n;
    if(av1-avrt>=0.5)
        avrt++;
    if(av2-avwt>=0.5)
        avwt++;
    if(av3-avtt>=0.5)
        avtt++;
    sort(p,p+n,compeare2);
    cout<<"Process\t Arrive-Time\t Burst-Time\t Priority\t Response-Time\t Wating-Time\t Turn around-Time\t"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<p[i].pr<<"\t\t"<<p[i].at<<"\t\t"<<p[i].bt<<"\t\t"<<p[i].p<<"\t\t"<<p[i].rt<<"\t\t"<<p[i].wt<<"\t\t"<<p[i].tt<<endl;
    }
    cout<<"Average of R.T. = "<<avrt<<endl;
    cout<<"Average of W.T. = "<<avwt<<endl;
    cout<<"Average of T.T. = "<<avtt<<endl;
    return 0;
}
