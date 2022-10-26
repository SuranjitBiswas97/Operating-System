#include<bits/stdc++.h>
using namespace std;
int main()
{
    int c1,d,f,i,j,n,r,t,q[20],p[50],k=0,c=0,b[20],c2[20];
    printf("Least Frequency Used:\n");
    printf("ENTER THE NUMBER OF PAGES:\n");
    scanf("%d",&n);
    printf("ENTER THE PAGE NUMBER:\n");
    for(i=0; i<n; i++)
        scanf("%d",&p[i]);
    printf("ENTER THE NUMBER OF FRAMES :");
    scanf("%d",&f);
    q[k]=p[k];
    printf("\n\t%d\n",q[k]);
    c++;
    k++;
    for(i=1; i<n; i++)
    {
        c1=0;
        for(j=0; j<f; j++)
        {
            if(p[i]!=q[j])
                c1++;
        }
        if(c1==f)
        {
            c++;
            if(k<f)
            {
                q[k]=p[i];
                k++;
                for(j=0; j<k; j++)
                    printf("\t%d",q[j]);
                printf("\n");
            }
            else
            {
                for(r=0; r<f; r++)
                {
                    c2[r]=0;
                    for(j=i-1; j<n; j++)
                    {
                        if(q[r]!=p[j])
                            c2[r]++;
                        else
                            break;
                    }
                }
                for(r=0; r<f; r++)
                    b[r]=c2[r];
                for(r=0; r<f; r++)
                {
                    for(j=r; j<f; j++)
                    {
                        if(b[r]<b[j])
                        {
                            t=b[r];
                            b[r]=b[j];
                            b[j]=t;
                        }
                    }
                }
                for(r=0; r<f; r++)
                {
                    if(c2[r]==b[0])
                        q[r]=p[i];
                    printf("\t%d",q[r]);
                }
                printf("\n");
            }
        }
    }
    printf("Page Fault Is %d",c);
}
