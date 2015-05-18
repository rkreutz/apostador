#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tempo 1000
void EscreverVariavel(float x,char c[50]);
void LerVariavel(float*x,char c[50]);
int main()
{
  FILE *pfile;
  int x=1;
  float credito,conta,saldo;
  char nome[2],numarq[20],senha[15],csenha[15];
  printf("----------------------------------CADASTRAMENTO---------------------------------");
  _sleep(3*tempo);
  while(x!=0)
  {
      system("cls");
      printf("\nDigite:\n1 - Para creditar um usuario.\n2 - Para criar um usuariao e credita-lo.\n0 - Para encerrar programa.\n");
      scanf("%d",&x);
      if(x==1)
      {
           	system("cls");
            printf("Digite seu usuario: ");
            scanf("%s",nome);
            pfile=fopen(nome,"r");
            if(pfile!=NULL)
            {
                fgets(numarq,20,pfile);
                conta=atof(numarq);
                printf("\nValor a ser creditado: R$");
                scanf("%f",&credito);
                printf("\nFoi creditado em sua conta R$%.2f, ficando com um saldo total de R$%.2f.\n",credito,(credito+conta));
                credito=credito+conta;
                fclose(pfile);
                pfile=fopen(nome,"w");
                fprintf(pfile,"%.2f",credito);
                fclose(pfile);
            }
            else printf("\nDesculpe usuario nao cadastrado.");
            _sleep(3*tempo);
      }
      else if(x==2)
      {
            system("cls");
            int y=1;
            while(y!=0)
            {
                 printf("Digite duas iniciais de seu nome para ser seu usuario: ");
                 scanf("%s",nome);
                 pfile=fopen(nome,"r");
                 if(pfile!=NULL)
                 {
                     printf("\nUsuario ja cadastrado digite outro.\n\n");
                     y=1;
                 }
                 else
                 {
                     fclose(pfile);                     
                     system("cls");
                     printf("\nUsuario criado com sucesso.\n\n");
                     while(strcmp(senha,csenha)!=0)
                     {
                          fflush(stdin);            //para resetar a memoria do gets ou scanf, fazer qndo tiver atribuindo sozinho
                          printf("Digite sua senha( ate 15 caracteres ): ");
                          gets(senha);
                          system("cls");
                          printf("Confirme a senha: ");
                          gets(csenha);
                          system("cls");
                          if(strcmp(senha,csenha)!=0) printf("Senhas nao conferem.\n\n");
                     }                     
                     printf("Digite quanto deve ser creditado: R$");
                     scanf("%f",&credito);
                     pfile=fopen(nome,"w");
                     fprintf(pfile,"%.2f",credito);
                     fclose(pfile);
                     pfile=fopen(strcat(nome,"senha"),"w");
                     fprintf(pfile,"%s",senha);
                     fclose(pfile);
                     printf("\nFoi creditado R$%.2f em seu usuario.",credito);
                     _sleep(3*tempo);
                     y=0;
                 }
            }
      }
  }            
  return 0;
}
