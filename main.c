#include<stdio.h>
int x[33][33],ans,N;
void fun1(int n)
{
    int i,j,lin=0,aa,bb;
    for(j=0;j<N;j++)
        lin+=x[n-1][j];
    for(i=0;i<n-1;i++)
    {
        aa=-1000000000;
        bb=x[i][n-1]+x[i+n][n-1];
        for(j=0;j<n-1;j++)
            bb+=abs(x[i][j]+x[i+n][j]+x[i][j+n]+x[i+n][j+n]);
        aa=aa>bb?aa:bb;
        bb=-x[i][n-1]-x[i+n][n-1];
        for(j=0;j<n-1;j++)
            bb+=abs(-x[i][j]-x[i+n][j]+x[i][j+n]+x[i+n][j+n]);
        aa=aa>bb?aa:bb;
        lin+=aa;
    }
    ans=ans>lin?ans:lin;
}
void fun(int n)
{
    int i,j,k;
    for(k=0;k<(1<<n-1);k++)
    {
        for(i=0;i<n-1;i++)
            if((k&(1<<i))!=0)
                for(j=0;j<n;j++)
                {
                    x[j][i]*=-1;
                    x[j][i+n]*=-1;
                }
        fun1(n);
        for(i=0;i<n-1;i++)
            if((k&(1<<i))!=0)
                for(j=0;j<n;j++)
                {
                    x[j][i]*=-1;
                    x[j][i+n]*=-1;
                }
    }
}
int main(void)
{
    int i,j,k;
    scanf("%d",&N);
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            scanf("%d",&x[i][j]);
    k=(N+1)/2;
    ans=-1000000000;
    fun(k);
    for(i=0;i<k;i++)
        for(j=0;j<k;j++)
            x[i][j]=-x[i][j];
    fun(k);
    printf("%d\n",ans);
    return 0;
}
