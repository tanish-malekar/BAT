#include<stdio.h>
#include<conio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d", &n);
    char name[30];
    char ans[30];
    int tot = 0;
    int age, s1,s2,s3,s4,s5;
    for(int i=0; i<n; i++)
    {
        scanf("%s", name);
        scanf("%d", &age);
        scanf("%d", &s1);
        scanf("%d", &s2);
        scanf("%d", &s3);
        scanf("%d", &s4);
        scanf("%d", &s5);
        if((s1+s2+s3+s4+s4+s5)>tot)
        {
            strcpy(ans, name);
            tot = s1+s2+s3+s4+s5;
        }

    }
    printf("%s", ans);
    return 0;
}

