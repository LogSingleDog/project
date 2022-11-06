#include<stdio.h>
#include<math.h>
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
    int max=0,min=110;
    int flag;
    int i;
    int b[26]={0};
    int c[25]={2,3,5,7,11,13,17,19,23,29,
    31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    scanf("%s",a);
    for(i=0;i<len(a);i++)
        b[a[i]-'a']++;
    for(i=0;i<26;i++)
    {
        if(max<b[i]) max=b[i];
        if(min>b[i]) min=b[i];
    }
    int d;
    d=max-min;
    for(i=0;i<=25;i++)
    {
        if(c[i]==d)
        {
            flag=1;
            printf("Lucky Word\n%d",d);
            break;
        }
    }
    if(flag==0)
        printf("No Answer\n0");
    return 0;
}