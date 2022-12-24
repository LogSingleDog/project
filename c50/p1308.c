#include<stdio.h>
int len(char a[])
{
    int l=0;
    while(a[l])
        l++;
    return l;
}
char small(char a)
{
    if(a>='A'&&a<='Z')
        a=a+32;
    return a;
}
int main()
{
    char a[11];
    char b[1145141];
    int i,j;
    int flag,flag2=1;
    int s=0;
    int x=0;
    scanf("%s",a);
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
    gets(b);
    for(i=0;i<len(a);i++)
        a[i]=small(a[i]);
    for(i=0;i<len(b);i++)
        b[i]=small(b[i]);
    for(i=0;i<len(b);i++)
    {
        flag=0;
        if(i==0||b[i-1]==' ')
        {
            if(b[i]==a[0])
            {
                if(flag2) x=i,flag2=0;
                flag=1;
                for(j=1;j<len(a);j++)
                {
                    if(b[i+j]!=a[j]) flag=0;
                }
            }
        }
        
        if(flag==1) s++;
    }
    if(s==0) printf("-1");
    else printf("%d %d",s,x);
}