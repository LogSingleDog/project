#include<stdio.h>
#include<math.h>
int main()
{
    int i,j;
    int k=0;
    for(i=2;i<=100;i++)
    {
        int flag=0;
        for(j=2;j<=sqrt(i);j++)
        {
            if(i%j==0)
                flag=1;
        }
        if(flag==0)
        {
            printf("%d ",i);
            k++;
            if(k%5==0)
            {
                printf("\n");
                k=0;
            }
        }
    }
    return 0;
}