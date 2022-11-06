#include<stdio.h>
	int n,m;
	int i,j;
	int a[55][8];
	double b[55],c[8];
	int s;
	int flag;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(i=1;i<=n;i++)
		{
			for(j=1;j<=m;j++)
				b[i]+=a[i][j];
			b[i]=b[i]/m;
		}
	for(j=1;j<=m;j++)
	{
		for(i=1;i<=n;i++)
			c[j]+=a[i][j];
		c[j]/=n;	
	}
	for(i=1;i<=n;i++)
	{
		flag=0;
		for(j=1;j<=m;j++)
		{
			if(a[i][j]<c[j])
				flag=1;
		}
		if(flag==0)
			s++;
	}
	for(i=1;i<=n;i++)
		printf("%.2f ",b[i]);
	printf("\n");
	for(j=1;j<=m;j++)
		printf("%.2f ",c[j]);
	printf("\n");
	printf("%d",s);
	return 0;
}