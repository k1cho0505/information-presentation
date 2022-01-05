#include <iostream>
#include <list>
using namespace std;
std::list<char> l;
list<char>::iterator p;
char na[3]= {},ns[1000000]= {},d[2]= {},pri[1000000]= {};
int j=1,k=0,m=0;
int main()
{
    printf("핵산의 종류를 입력하세요.\n");
    for(int i=0; i<3; i++)
        scanf("%c",&na[i]);
    printf("\n번역하고자 하는 염기서열을 입력하세요.(입력 후에는 1을 눌러주세요.)\n");
    for(;ns[j-1]!='1';j++)
    {
        scanf("%c",&ns[j]);
    }
    printf("\n염기 서열의 방향을 적어주세요.(ex.3말단 에서 5말단 방향: 35)\n");
    for(int i=0;i<2;i++)
        scanf("%c",&d[i]);
    if(d[1]=='3')
    {
        if(na[0]=='r'||na[0]=='R')
        {
            for(int i=1; i<=j-2; i++)
            {
                if(ns[i]=='A'||ns[i]=='a')
                    ns[i]='A';
                else if(ns[i]=='U'||ns[i]=='u')
                    ns[i]='U';
                else if(ns[i]=='C'||ns[i]=='c')
                    ns[i]='C';
                else if(ns[i]=='G'||ns[i]=='g')
                    ns[i]='G';
            }
            for(int i=1; i<=j-2; i++)
            {
                l.push_front(ns[i]);
            }
            for(p=l.begin(); p!=l.end(); p++)
            {
                pri[k]=*p;
                k++;
            }
        }
        if(na[0]=='d'||na[0]=='D')
        {
            for(int i=1; i<j-2; i++)
            {
                if(ns[i]=='A'||ns[i]=='a')
                    ns[i]='U';
                else if(ns[i]=='T'||ns[i]=='t')
                    ns[i]='A';
                else if(ns[i]=='C'||ns[i]=='c')
                    ns[i]='G';
                else if(ns[i]=='G'||ns[i]=='g')
                    ns[i]='C';
            }
            for(int i=1; i<j-2; i++)
            {
                l.push_back(ns[i]);
            }
            for(p=l.begin(); p!=l.end(); p++)
            {
                pri[k]=*p;
                k++;
            }
        }
    }
    if(d[1]=='5')
    {
        if(na[0]=='r'||na[0]=='R')
        {
            for(int i=1; i<j-2; i++)
            {
                if(ns[i]=='A'||ns[i]=='a')
                    ns[i]='A';
                else if(ns[i]=='U'||ns[i]=='u')
                    ns[i]='U';
                else if(ns[i]=='C'||ns[i]=='c')
                    ns[i]='C';
                else if(ns[i]=='G'||ns[i]=='g')
                    ns[i]='G';
            }
            for(int i=1; i<j-2; i++)
            {
                l.push_back(ns[i]);
            }
            for(p=l.begin(); p!=l.end(); p++)
            {
                pri[k]=*p;
                k++;
            }
        }
        if(na[0]=='d'||na[0]=='D')
        {
            for(int i=1; i<j-2; i++)
            {
                if(ns[i]=='A'||ns[i]=='a')
                    ns[i]='U';
                else if(ns[i]=='T'||ns[i]=='t')
                    ns[i]='A';
                else if(ns[i]=='C'||ns[i]=='c')
                    ns[i]='G';
                else if(ns[i]=='G'||ns[i]=='g')
                    ns[i]='C';
            }
            for(int i=1; i<j-2; i++)
            {
                l.push_front(ns[i]);
            }
            for(p=l.begin(); p!=l.end(); p++)
            {
                pri[k]=*p;
                k++;
            }
        }
    }
    for(int i=0;i<j-2;i++)
    {
        if(pri[i]=='A')
        {
            if(pri[i+1]=='U')
            {
                if(pri[i+2]=='G')
                {
                    m=i;
                    break;
                }
            }
        }
    }
    for(;m<j-1;m+=3)
    {
        if(pri[m]=='A')
        {
            if(pri[m+1]=='A')
            {
                if(pri[m+2]=='A'||pri[m+2]=='G')
                    printf("라이신 ");
                else
                    printf("아스파라진 ");
            }
            else if(pri[m+1]=='U')
            {
                if(pri[m+2]=='G')
                    printf("메싸이오닌 ");
                else
                    printf("아이소류신 ");
            }
            else if(pri[m+1]=='C')
                printf("트레오닌 ");
            else if(pri[m+1]=='G')
            {
                if(pri[m+2]=='A'||pri[m+2]=='G')
                    printf("아르지닌 ");
                else if(pri[m+2]=='U'||pri[m+2]=='C')
                    printf("세린 ");
            }
        }
        else if(pri[m]=='U')
        {
            if(pri[m+1]=='A')
            {
                if(pri[m+2]=='A'||pri[m+2]=='G')
                    break;
                else if(pri[m+2]=='U'||pri[m+2]=='G')
                    printf("타이로신 ");
            }
            else if(pri[m+1]=='U')
            {
                if(pri[m+2]=='A'||pri[m+2]=='G')
                    printf("류신 ");
                else if(pri[m+2]=='U'||pri[m+2]=='C')
                    printf("페닐알라닌 ");
            }
            else if(pri[m+1]=='C')
                printf("세린 ");
            if(pri[m+1]=='G')
            {
                if(pri[m+2]=='A')
                    break;
                else if(pri[m+2]=='U'||pri[m+2]=='C')
                    printf("시스테인 ");
                else if(pri[m+2]=='A'||pri[m+2]=='G')
                    printf("트립토판 ");
            }
        }
        if(pri[m]=='C')
        {
            if(pri[m+1]=='A')
            {
                if(pri[m+2]=='A'||pri[m+2]=='G')
                    printf("글루타민 ");
                else if(pri[m+2]=='U'||pri[m+2]=='C')
                    printf("히스티딘 ");
            }
            if(pri[m+1]=='U')
                printf("류신 ");
            else if(pri[m+1]=='C')
                printf("프롤린 ");
        }
        if(pri[m]=='C')
        {
            if(pri[m+1]=='G')
                printf("아르지닌 ");
        }
        if(pri[m]=='G')
        {
            if(pri[m+1]=='A')
            {
                if(pri[m+2]=='A'||pri[m+2]=='G')
                    printf("글루탐산 ");
                else if(pri[m+2]=='U'||pri[m+2]=='C')
                    printf("아스파트산 ");
            }
            if(pri[m+1]=='U')
                printf("발린 ");
            if(pri[m+1]=='C')
                printf("알라닌 ");
            if(pri[m+1]=='G')
                printf("글라이신 ");
        }
    }
}