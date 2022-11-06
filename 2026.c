#include<stdio.h>
int len(const char a[])
{
    int l=0;
    while(a[l])
        l++;
    return l;
}
int main()
{
    char a[114];
    gets(a);
    int i,j;
    a[0]=a[0]-32;
    for(i=1;i<len(a);i++)
    {
        if(a[i]==' ')
        {
            j=i;
            a[j+1]=a[j+1]-32;
        }
    }
    printf("%s",a);
}