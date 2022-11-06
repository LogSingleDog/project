#include<stdio.h>
	int a[110][110],b[110];
	int n;
	int i,j;
int main()
{
	while(1)
	{
		n++;
		scanf("%d",&a[n][0]);
		for(i=1;i<=a[n][0];i++) 
			scanf("%d",&a[n][i]);
		b[n]=1;
		for(i=1;i<=a[n][0];i++) 
		{
			if(a[n][i]%2==1)
				b[n]*=a[n][i];	
		}
		printf("%d\n",b[n]);
	}
}