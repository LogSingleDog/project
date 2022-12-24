#include<stdio.h>
#include<math.h>
	int a[110][110];
	int n;
	int flag;
	int i,j;
	int t;
int main()
{	
	while(flag==0)
	{
		n++;
		scanf("%d",&a[n][0]);
		if(a[n][0]==0)	flag=1;
		for(i=1;i<=a[n][0];i++) 
			scanf("%d",&a[n][i]);
		for(i=a[n][0];i>=1;i--)
			for(j=1;j<=i;j++)
			{
				if(abs(a[n][j])<abs(a[n][i]))
					{
						t=a[n][j];
						a[n][j]=a[n][i];
						a[n][i]=t;
					}	
			}
	}		
	for(i=1;i<n;i++)
	{
		for(j=1;j<=a[i][0];j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}	
}