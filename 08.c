#include<stdio.h>
	int a[110][110];
	double b[110];
	int n;
	int i,j;
	int x;
int main()
{
	int y;
	while(1)
	{
		y=101;
		n++;
		scanf("%d",&a[n][0]);
		for(i=1;i<=a[n][0];i++) 
			scanf("%d",&a[n][i]);
		for(i=1;i<=a[n][0];i++) 
		{
			if(y>a[n][i])
				y=a[n][i];
			if(x<a[n][i])
				x=a[n][i];
		}
		for(i=1;i<=a[n][0];i++) 
			b[n]+=a[n][i];
		b[n]=b[n]-x-y;
		b[n]=b[n]/(a[n][0]-2);
		printf("%.2f\n",b[n]);
	}
}