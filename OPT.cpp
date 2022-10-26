#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a[100],n,i,j,k,f1=-1,f2=-1,f3=-1,p=0,pf=0,ph=0,c1,c2,c3,t1=0,t2=0,t3=0;
    printf("Optimal Page Replacement:\n");
    printf("ENTER THE NUMBER OF PAGES:\n");
    cin>>n;
    printf("ENTER THE PAGE NUMBER:\n");
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(i=0; i<n; i++)
    {
        if(f1==-1 && p==0)
        {
            f1=a[i];
            pf++;
            p=1;
        }
        else if(f2==-1 && p==1)
        {
            f2=a[i];
            pf++;
            p=2;
        }
        else if(f3==-1 && p==2)
        {
            f3=a[i];
            pf++;
            p=0;
        }
        else if(f1==a[i] || f2==a[i] || f3==a[i])
        {
            ph++;
        }
        else
        {
            c1=0;
            c2=0;
            c3=0;
            t1=0;
            t2=0;
            t3=0;
            for(j=i; j<n; j++)
            {
                if(f1==a[j] && t1==0)
                {
                    c1=j;
                    t1=1;
                }
                else if(f2==a[j] && t2==0)
                {
                    c2=j;
                    t2=1;
                }
                else if(f3==a[j] && t3==0)
                {
                    c3=j;
                    t3=1;
                }
            }
            if(c1>c2 && c1>c3 && t1==1 && t2==1 && t3==1)
            {
                f1=a[i];
                pf++;
            }
            else if(c2>c1 && c2>c3 && t1==1 && t2==1 && t3==1)
            {
                f2=a[i];
                pf++;
            }
            else if(c3>c2 && c3>c1 && t1==1 && t2==1 && t3==1)
            {
                f3=a[i];
                pf++;
            }
            else if(t1==0 && t2==1 && t3==1)
            {
                f1=a[i];
                pf++;
            }
            else if(t1==1 && t2==0 && t3==1)
            {
                f2=a[i];
                pf++;
            }
            else if(t1==1 && t2==1 && t3==0)
            {
                f3=a[i];
                pf++;
            }
        }
    }
    cout<<" Page Faults = "<<pf+1<<" Page Hits = "<<ph<<endl;
    return 0;
}
/*
3 Frame Page
15
7 0 1 2 0 3 0 4 2 3 0 3 2 1 2
*/
