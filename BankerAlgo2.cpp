#include<bits/stdc++.h>
using namespace std;
struct BA {
    int p,alA,alB,alC,alD,maxA,maxB,maxC,maxD,nedA,nedB,nedC,nedD;
};
int main()
{
    BA a[100];
    int n,i,j,avai[4],fl[100],m=0,ssq[100];
    cout<<"Enter Number Of Process :";
    cin>>n;
    cout<<"Enter Allocation of A B C D and Max of A B C D"<<endl;
    for(i=0; i<n; i++)
    {
        a[i].p=i+1;
        cin>>a[i].alA>>a[i].alB>>a[i].alC>>a[i].alD>>a[i].maxA>>a[i].maxB>>a[i].maxC>>a[i].maxD;
        fl[i]=0;
        a[i].nedA=a[i].maxA-a[i].alA;
        if(a[i].nedA<0)
            a[i].nedA=0;
        a[i].nedB=a[i].maxB-a[i].alB;
        if(a[i].nedB<0)
            a[i].nedB=0;
        a[i].nedC=a[i].maxC-a[i].alC;
        if(a[i].nedC<0)
            a[i].nedC=0;
        a[i].nedD=a[i].maxD-a[i].alD;
        if(a[i].nedD<0)
            a[i].nedD=0;
        fl[i]=0;
    }
    cout<<"Enter First Available of A B C D :";
    cin>>avai[0]>>avai[1]>>avai[2]>>avai[3];
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
           if(a[j].nedA<=avai[0]&&a[j].nedB<=avai[1]&&a[j].nedC<=avai[2]&&a[j].nedD<=avai[3]&&fl[j]==0)
           {
               ssq[m]=j+1;
               fl[j]=1;
               avai[0]+=a[j].alA;
               avai[1]+=a[j].alB;
               avai[2]+=a[j].alC;
               avai[3]+=a[j].alD;
               m++;
           }
        }
    }
    cout<<"Need :"<<endl;
    for(i=0; i<n; i++)
    {
        cout<<i+1<<"-->"<<a[i].nedA<<" "<<a[i].nedB<<" "<<a[i].nedC<<" "<<a[i].nedD<<endl;
    }
    if(m==n)
    {
        cout<<"Safe sequence is : < ";
        for(i=0; i<n; i++)
            cout<<"P-"<<ssq[i]<<" , ";
        cout<<">";
    }
    else
        cout<<"Process is dead lock";

    return 0;
}
/*
5
1 0 2 0 3 2 4 2
0 3 1 2 3 5 1 2
2 4 5 1 2 7 7 5
3 0 0 6 5 5 0 8
4 2 1 3 6 2 1 4
3 4 0 1
*/
