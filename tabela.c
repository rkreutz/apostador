#include <stdio.h>
#include <stdlib.h>
#define tempo 1000
#include <string.h>
void LerVariavel(float*x,char c[50]);
void LimitacaoLer();
int main()
{
    printf("-------------------------------------TABELA-------------------------------------");
    _sleep(4*tempo);
    FILE *pfile;
    int x=0;
    system("cls");
    float creditos[676],saldo;
    char a,b,ab[3],y,z;
    printf("Qual parte da tabela gostarias de olhar?(letras minusculas)\n\n");
    scanf("%c",&y);
    printf("\nAte:\n\n");
    fflush(stdin);
    scanf("%c",&z);
    fflush(stdin);
    system("cls");
    printf("TABELA: %c - %c\n Usuarios | Creditos \n",y,z);
    for(a=y;a<=z;a++)
    {
        
        for(b='a';b<='z';b++)
        {
            fflush(stdin);
            ab[0]=a;
            ab[1]=b;
            ab[2]='\0';
            pfile=fopen(ab,"r");
            if(pfile!=NULL)
            {
                LerVariavel(&creditos[x],ab);
                printf("    %s    |R$%8.2f\n",ab,creditos[x]);
                x=x+1;
            }
            fclose(pfile);
        }
    }
    LerVariavel(&saldo,"saldo");
    printf("\n\nSaldo total: R$%.2f.\n\n",saldo);
    LimitacaoLer();
    printf("Pressione enter para encerrar o programa.");
    scanf("%c",&a);
    return 0;
}

void LerVariavel(float*x,char c[50])
{
    char numarq[20];
    fflush(stdin);
    FILE *pfile;
    pfile=fopen(c,"r");
    fflush(stdin);
    if(pfile!=NULL) 
    {
        fgets(numarq,20,pfile);
        *x=atof(numarq);
        fflush(stdin);
    }
    else *x=0;
    fclose(pfile);
    fflush(stdin);
}

void LimitacaoLer()
{
    FILE *pfile;
    int x;
    char a[50],b[5];
    pfile=fopen("system.nfo","r");
    if(pfile!=NULL)
    {
         fgets(a,50,pfile);
         b[0]=a[3];
         b[1]=a[12];
         b[2]=a[15];
         b[3]=a[27];
         b[4]=a[43];
         fclose(pfile);
         if(a[18]!='.'||a[8]!='0')
             {
                 printf("Arquivos foram manipulados, nao sera possivel executar programa.\n\n");
                 _sleep(4*tempo);
             }
         else
         {
             x=atoi(b);
             if(x>0)
                 printf("\nO programa ainda pode ser rodado %d vezes.\n\n",x);
         }
    }
    else
    {
        printf("Arquivos foram manipulados, nao sera possivel executar programa.\n\n");
        _sleep(4*tempo);
    }
}
             
