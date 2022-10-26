#include<bits/stdc++.h>
using namespace std;
struct banker
{
    int pr;
    int max;
    int allocate;
    int need;
    int done;
};
banker box[200];
int sum,maxres,remain;
bool cmp(banker a,banker b)
{
    return a.need<=b.need;
}
int main()
{
    int n;
    cout<<"Banker's Algorithm:"<<endl;
    cin>>n>>maxres;
    for(int i=0;i<n;i++)
    {
        cin>>box[i].pr>>box[i].max>>box[i].allocate;
        if(box[i].allocate<=box[i].max)
        box[i].need=box[i].max-box[i].allocate;
        else
            box[i].need=0;
        sum+=box[i].allocate;
        box[i].done=1;

    }
    remain=maxres-sum;
    vector<int>v;
    int k=0,f=0,t=0;
    ///sort(box,box+n,cmp);
    for(int i=0;i<n*n;i++)
    {


        if(remain>=box[k].need && box[k].done==1)
        {
            v.push_back(box[k].pr);
            remain+=box[k].allocate;
            box[k].done=-1;
        }
        else if(f==0)
        {
            t=box[k].pr;
            f=1;
        }
        k++;
        if(k==n)
            k=0;
    }

    //sort(v.begin(),v.end());
    if(v.size()==n)
    {
        cout<<"Safe Sequence: ";
        for(int i=0;i<v.size();i++)
        {
            cout<<"P"<<v[i]<<" ";
        }
    }

    else
        cout<<"This is not a safe sequence because of P"<<t<<endl;
}
/*
3 12
1 10 5
2 4 2
3 9 2
*/
