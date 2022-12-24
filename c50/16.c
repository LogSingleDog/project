#include<stdio.h>
int len(const char a[])
{
    int l = 0;
    while(a[l])
        l++;
    return l;
}
int main()
{
    int n;
    int i,j;
    int yuan[114514][5];
    scanf("%d",&n);
    int c;
    while((c=getchar())!='\n'&&c!=EOF);
    for(i=1;i<=n;i++)
    {
        char a[114];
        gets(a);
        for(j=0;j<len(a);j++)
        {
            switch(a[j])
            {
                case 'a':yuan[i][0]++;break;
                case 'e':yuan[i][1]++;break;
                case 'i':yuan[i][2]++;break;
                case 'o':yuan[i][3]++;break;
                case 'u':yuan[i][4]++;break;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("a:%d\n",yuan[i][0]);
        printf("e:%d\n",yuan[i][1]);
        printf("i:%d\n",yuan[i][2]);
        printf("o:%d\n",yuan[i][3]);
        printf("u:%d\n\n",yuan[i][4]);
    }
    return 0;
}