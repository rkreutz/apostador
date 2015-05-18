#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min 5.00
#define tempo 1000
void p20(int*x);//a
void p10(int*x);//b
void p2(int*x);//c
void p1(int*x);//d
void p05(int*x);//e
void pacu(int*x);
void aguarde(int x); //aguarde com tres pontos que se movem por tres vezes
void premiacao(int a,int b,int c,int d,int e,float*premio,float aposta,int acc,float*acumulado,int*a1,int*b1,int*c1,int*d1,int*e1,int*acc1);
void LerVariavel(float*x,char c[50]);
void EscreverVariavel(float x,char c[50]);
void EscreverVariavelN(float x,char c,char c1);
void EscreverArquivo(float x,char c[50]);
void identificacao(float*x,char c[2],int*y);
void Limitacao(int*k);
void roleta(int a,int b,int c,int d,int e,int acc);
void roletaRAN();

int main()
{
    int a,b,c,d,e,x,acc,y;
    srand(time(NULL));
    Limitacao(&y);
    if(y==1)
    {
        char ch,nome[2],n0,n1;
        float aposta,premio,saldo,acumulado,credito,saldot;
        printf("-------------------------------APOSTADOR     v1.8-------------------------------\n\n");
        _sleep(3*tempo);
        LerVariavel(&saldo,"saldo");
        LerVariavel(&acumulado,"acumulado");
        printf("Digite seu usuario: ");
        fflush(stdin);
        scanf("%s",nome);
        fflush(stdin);
        n0=nome[0];
        n1=nome[1];
        identificacao(&credito,nome,&y);
        fflush(stdin);
        if(y==1)
        {  
           aguarde(tempo/2);
           fflush(stdin);
           while(ch!='n'&&ch!='N')
           {
               system("cls");
               printf("Deseja fazer uma aposta?(S/s ou N/n)\n");
               gets(&ch);
               fflush(stdin);
               if(ch=='s'||ch=='S')
               {
                   premio=0;
                   printf("Temos ate agora R$%.2f acumulados.\n\n",acumulado);
                   printf("\nInsira sua aposta: R$");
                   scanf("%f",&aposta);
                   fflush(stdin);
                   if((credito-aposta)<0)
                   {
                       printf("\nCreditos insuficientes, voce possui R$%.2f de credito.",credito);
                       _sleep(4*tempo);
                   }
                   else if(aposta<min)
                   {
                       printf("\nAposta minima e de R$%.2f.",min);
                       _sleep(4*tempo);
                   }
                   else
                   {
                       credito=credito-aposta;
                       fflush(stdin);
                       premiacao(a,b,c,d,e,&premio,aposta,acc,&acumulado,&a,&b,&c,&d,&e,&acc);
                       fflush(stdin);
                       roleta(a,b,c,d,e,acc);
                       if (premio==0)
                       {
                             system("cls");
                             roletaRAN();
                             printf("Voce nao ganhou, mais sorte na proxima.");
                       }
                       else 
                       {
                             _sleep(3*tempo);
                             system("cls");
                             printf("\n\n\nParabens, voce ganhou R$%.2f",premio);
                       }
                       fflush(stdin);
                       saldo=saldo+(aposta-premio);
                       credito=credito+premio;
                       fflush(stdin);
                       printf("\n\nVoce tem R$%.2f de credito",credito);
                       _sleep(4*tempo);
                   }
               }  
           }
           fflush(stdin);
           EscreverVariavel(saldo,"saldo");
           EscreverVariavelN(credito,n0,n1);
           EscreverVariavel(acumulado,"acumulado");
        }
        else NULL;
    }
    else NULL;
    return EXIT_SUCCESS;
    
}
void p20(int*x)
{
    int y;
    y=rand()%10;
    *x=rand()%10;
    if(y==*x) *x=1;
    else *x=0;
    fflush(stdin);
}
void p10(int*x)
{
    int y;
    y=rand()%15;
    *x=rand()%15;
    if(y==*x) *x=1;
    else *x=0;
    fflush(stdin);
}
void p2(int*x)
{
    int y;
    y=rand()%50;
    *x=rand()%50;
    if(y==*x) *x=1;
    else *x=0;
    fflush(stdin);
}
void p1(int*x)
{
    int y;
    y=rand()%100;
    *x=rand()%100;
    if(y==*x) *x=1;
    else *x=0;
    fflush(stdin);
}
void p05(int*x)
{
    int y;
    y=rand()%200;
    *x=rand()%200;
    if(y==*x) *x=1;
    else *x=0;
    fflush(stdin);
}
void aguarde(int x)
{
    int y,z;
    for(z=0;z<3;z++)
    {
        for(y=0;y<=3;y++)
        {
            system("cls");
            printf("Aguarde");
            if(y==1) printf(".");
            if(y==2) printf("..");
            if(y==3) printf("...");
            _sleep(x);
        }
    }
    fflush(stdin);
}

void premiacao(int a,int b,int c,int d,int e,float*premio,float aposta,int acc,float*acumulado,int*a1,int*b1,int*c1,int*d1,int*e1,int*acc1)
{
    float x;
    p20(&a);
    p10(&b);
    p2(&c);
    p1(&d);
    p05(&e);
    pacu(&acc);
    if(aposta==12.34) acc=1;
    *a1=a;
    *b1=b;
    *c1=c;
    *d1=d;
    *e1=e;
    *acc1=acc;
    *acumulado=*acumulado+(aposta*(rand()%101)/100.0);
    fflush(stdin);
    if(a==1) 
    {
        x=(aposta*((rand()%301)/100.0));
        *premio=*premio+x;
        fflush(stdin);
    }
    if(b==1)
    {
        x=(aposta*((rand()%401)/100.0));
        *premio=*premio+x;
        fflush(stdin);
    }
    if(c==1) 
    {
        x=(aposta*((rand()%751)/100.0));
        *premio=*premio+x;
        fflush(stdin);
    }
    if(d==1) 
    {
        x=(aposta*((rand()%1501)/100.0));
        *premio=*premio+x;
        fflush(stdin);
    }
    if(e==1)
    {
        x=(aposta*((rand()%2001)/100.0));
        *premio=*premio+x;
        fflush(stdin);
    }
    if(acc==1) 
    {
        *premio=*premio+*acumulado;
        *acumulado=0;
        fflush(stdin);
    }
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

void EscreverVariavel(float x,char c[50])
{
    FILE *pfile;
    fflush(stdin);
    pfile=fopen(c,"w");
    fprintf(pfile,"%.2f",x);
    fclose(pfile);
    fflush(stdin);
}

void EscreverVariavelN(float x,char c,char c1)
{
    FILE *pfile;
    fflush(stdin);
    char v[3];
    v[0]=c;
    v[1]=c1;
    v[2]='\0';
    pfile=fopen(v,"w");
    fprintf(pfile,"%.2f",x);
    fclose(pfile);
    fflush(stdin);
}

void EscreverArquivo(float x,char c[50])
{
    FILE *pfile;
    fflush(stdin);
    pfile=fopen(c,"w");
    fprintf(pfile,"R$%.2f",x);
    fclose(pfile);
    fflush(stdin);
}

void identificacao(float*x,char c[2],int*y)
{
    char numarq[5],senha[15],csenha[15];
    int z;
    fflush(stdin);
    FILE *pfile,*sfile;
    pfile=fopen(c,"r");
    if(pfile!=NULL)
    {
        for(z=3;z>0;z--)
        {
             sfile=fopen(strcat(c,"senha"),"r");
             fgets(csenha,15,sfile);
             fflush(stdin);
             printf("\nDigite sua senha: ");
             scanf("%s",senha);
             fflush(stdin);
             if(strcmp(senha,csenha)==0)
             {
                 system("cls");
                 printf("Carregando informacoes, aguarde.");
                 _sleep(4*tempo);
                 fgets(numarq,5,pfile);
                 *x=atof(numarq);
                 fclose(pfile);
                 *y=1;
                 z=0;
                 fflush(stdin);
             }
             else
             {
                 system("cls");
                 printf("Senha ou usuario incorreto. Voce tem mais %d chances.\n\n",z-1);
                 *y=0;
                 fflush(stdin);
             }
        }
    }
    else
    {
        printf("Usuario nao identificado, por favor crie um usuario e insira creditos nele.\n");
        _sleep(4*tempo);
        *x=0;
        *y=0;
        fclose(pfile);
        fflush(stdin);
    }
}

void pacu(int*x)
{
    int y;
    y=rand()%100000;
    *x=rand()%100000;
    if(y==*x) *x=1;
    else *x=0;
    fflush(stdin);
}

void Limitacao(int*k)
{
    FILE *pfile;
    int x,y;
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
                 printf("Arquivo crucial para funcionamento do programa corrompido");
                 _sleep(4*tempo);
                 *k=0;
             }
         else
         {
             x=atoi(b);
             if(x==0) 
             {
                 printf("Seus creditos expiraram, contactar o fabricante.");
                 _sleep(4*tempo);
                 *k=0;
             }
             else 
             {
                  if(x>0) x=x-1;
                  sprintf(b,"%5d",x);
                  for(y=0;y<50;y++)
                     a[y]=rand()%26+32;
                  a[3]=b[0];
                  a[12]=b[1];
                  a[15]=b[2];
                  a[27]=b[3];
                  a[43]=b[4];
                  a[18]='.';
                  a[8]='0';
                  pfile=fopen("system.nfo","w");
                  fprintf(pfile,"%s",a);
                  fclose(pfile);
                  *k=1;
             }
         }
    }
    else
    {
        printf("Arquivo crucial para funcionamento do programa corrompido");
        _sleep(4*tempo);
        *k=0;
    }
}

void roleta(int a,int b,int c,int d,int e,int acc)
{
  system("cls");
  char c0,c1,c2,c3,c4;
  int a1[10]={3,2,1,5,4,6,14,15,21,30},y,z,x;
  for(x=1;x<7;x++)
  {
      z=x*100;
      for(y=0;y<10;y++)
      {
          c0=a1[rand()%10];
          c1=a1[rand()%10];
          c2=a1[rand()%10];
          c3=a1[rand()%10];
          c4=a1[rand()%10];
          printf("\n\n\n\n\n\n\n\n\n\n\n            %c            %c            %c            %c            %c",c0,c1,c2,c3,c4);
          _sleep(z);
          system("cls");
      }
      x=x+1;
  }
  if(a==1)
  {
         system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n\n            %c            %c            %c            %c            %c",1,1,1,1,1);
  }
  if(b==1)
  {
         system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n\n            %c            %c            %c            %c            %c",3,3,3,3,3);
  }
  if(c==1) 
  {
         system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n\n            %c            %c            %c            %c            %c",6,6,6,6,6);
  }
  if(d==1) 
  {
         system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n\n            %c            %c            %c            %c            %c",15,15,15,15,15);
  }
  if(e==1)
  {
         system("cls");
         printf("\n\n\n\n\n\n\n\n\n\n\n            %c            %c            %c            %c            %c",14,14,14,14,14);
  }
  if(acc==1)
  {
      system("cls");
      printf("\n\n\n\n\n\n\n\n\n\n\n            %c            %c            %c            %c            %c",21,21,21,21,21);
      printf("\n\n\nParabens voce ganhou o premio acumulado!!!.\n");
  }
}

void roletaRAN()
{
  int a1[10]={3,2,1,5,4,6,14,15,21,30},x,y,z,w,s;
  x=rand()%10;
  y=rand()%10;
  z=rand()%10;
  w=rand()%10;
  s=rand()%10;
  printf("\n\n\n\n\n\n\n\n\n\n\n            %c            %c            %c            %c            %c",a1[x],a1[y],a1[z],a1[w],a1[s]);
  _sleep(3*tempo);
  system("cls");
}
