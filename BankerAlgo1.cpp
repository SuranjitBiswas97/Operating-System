#include<bits/stdc++.h>
using namespace std;
struct BA{
    int p,al,mx,ned;
};
int main()
{
    BA a[100];
    int n,i,j,tot_al=0,max_re,avai_re,fl[100],ssq[100],k=0,l;
    cout<<"Enter number of process : ";
    cin>>n;
    cout<<"Enter allocation and max aloocation for eatch proocess :"<<endl;
    for(i=0; i<n; i++)
    {
        a[i].p=i+1;
        cin>>a[i].al>>a[i].mx;
        a[i].ned=a[i].mx-a[i].al;
        if(a[i].ned<0)
            a[i].ned=0;
        tot_al+=a[i].al;
        fl[i]=0;
    }
    cout<<"Enter Max Resorse : ";
    cin>>max_re;
    avai_re=max_re-tot_al;
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            if(a[j].ned<=avai_re&&fl[j]==0)
            {
                avai_re+=a[j].al;
                fl[j]=1;
                ssq[k]=j+1;
                k++;
            }
            else if(a[j].ned>avai_re&&fl[j]==0)
                l=j+1;
        }
    }
    cout<<"Need : "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<a[i].ned<<endl;
    }
    if(k==n)
    {
        cout<<"Safe Sequence is : < ";
        for(i=0; i<n; i++)
            cout<<ssq[i]<<" ";
        cout<<">"<<endl;
    }
    else
        cout<<"Process is dead lock in process "<<l<<endl;
    return 0;
}
/*
3
5 5
2 23
2 9
12
*/
