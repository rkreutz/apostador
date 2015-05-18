#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  
  FILE *pfile,*ofile,*mfile;
  pfile=fopen("jogador.exe","w");
  fclose(pfile);
  ofile=fopen("Cadastrador.exe","w");
  fclose(ofile);	
  mfile=fopen("Tabela.exe","w");
  fclose(mfile);
  return 0;
}
