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
    int i,j;
    int b[114514][3];
    char a[114];
    int s;
    while(1)
    {
        scanf("%s",a);
        if(a[0]=='E') break;
        s++;
        for(i=0;i<len(a);i++)
        {
            switch(a[i])
            {
                case 'Z':b[s][0]++;break;
                case 'O':b[s][1]++;break;
                case 'J':b[s][2]++;break;
            }
        }
    }
    for(i=1;i<=s;i++)
    {
        while((b[i][0]+b[i][1]+b[i][2]))
        {
            if(b[i][0]!=0) printf("Z"),b[i][0]--;
            if(b[i][1]!=0) printf("O"),b[i][1]--;
            if(b[i][2]!=0) printf("J"),b[i][2]--;
        }
        printf("\n");
    }
    return 0;
}