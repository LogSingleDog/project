#include<stdio.h>
int main()
{
    float a[114];
    int m,n;
    float b[114];
    int i,j;
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&n);
        for(j=1;j<=n;j++)
        {
            scanf("%f",&a[j]);
            if(b[i]<a[j]) b[i]=a[j];
        }
    }
    for(i=1;i<=m;i++)
        printf("%.2f\n",b[i]);
    return 0;
}