#include <stdio.h>
#include <stdlib.h>
#define linha 178


void creditar();
void rkreutz(char c[15],int *i);

int main()
{
  int i;
  srand(time(NULL));
  printf("Digite seu usuario: ");
  char usuario[15];
  gets(usuario);
  rkreutz(usuario,&i);
  if(i==0) creditar();
  return 0;
}

void creditar()
{
  FILE *pfile;
  int x,y;
  char a[50],b[6];
  printf("Quantos creditos devem ser adicionados?\n");
  scanf("%d",&x);
  for(y=0;y<50;y++)
  {
      if (y%linha==0&&y!=0) a[y]='\n';
      else a[y]=rand()%26+32;
  }
  sprintf(b,"%5d",x);
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
}

void rkreutz(char c[15],int *i)
{
  if(strcmp(c,"rkreutz")==0)
  {
     system("cls");
     printf("Digite sua senha: ");
     gets(c);
     if(strcmp(c,"9378 26278")==0)
     {
        system("cls");
        *i=0;
     }
     else
     {
         system("cls");
         printf("Senha incorreta.");
         *i=1;
         _sleep(3000);
     }
  }
  else
  {
      printf("\nUsuariao nao cadastrado.");
      _sleep(3000);
      *i=1;
  }
}
