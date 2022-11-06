#include<stdio.h>
	long long n;
	long long i;
	long long m;
	long long a[50];
long long f(long n)
{
	if(n==1||n==2) return 1;
	if(a[n]!=0) return a[n];
	else return a[n]=f(n-1)+f(n-2);
}
int main()
{
	scanf("%lld",&n);
	if(n==0)
	{
		printf("0.00");
		return 0;
	}
	printf("%lld.00",f(n));
	return 0;
}