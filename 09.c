#include<stdio.h>
	int y,m,d;
	int s;
	int i;
int main()
{
	
	while(1)
	{
		s=0;
		int a[13]={0,31,28,31,30,31,30,
				31,31,30,31,30,31};
		scanf("%d/%d/%d",&y,&m,&d);
		if(y%400==0||(y%4==0&&y%100!=0))
			a[2]++;
		for(i=1;i<m;i++)
			s+=a[i];
		s+=d;
		printf("%d\n",s);
	}
}