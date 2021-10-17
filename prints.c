#include "declaration.h"

void object(FILE* fd)
{
  char file_name[MAX_LINE];
  int binary;
  char code[BITS];
  int i=ZERO;
  int j=ZERO;
  int k=FIRST_MEMORY;
  int mask=1;
  FILE *fd1;
  char x=fgetc(fd);
  while(x==' '|| x=='\t' || x==';')/*Go ahead while there are spaces or tabs*/
     x=fgetc(fd);
  while(x!=' '&& x!='\t')/*Go ahead while there are not spaces or tabs*/
     x=fgetc(fd);
  while(x==' '|| x=='\t')/*Go ahead while there are spaces or tabs*/
     x=fgetc(fd);
  while(x!='.')/*if it's .entry or .extern*/
  {
     file_name[i] = x;
     x = fgetc(fd);
     i++;
  }
  file_name[i]='\0';
  i=ZERO; 
  strcat(file_name,".ob");
  fd1=fopen(file_name,"w+");
  if(fd1==NULL)
     fprintf(stderr, "ERROR, the file did not open");
  for(i=ZERO; i<MAX_MEMORY &&k<IC+DC; i++,k++)
  {
     fprintf(fd1," %d%d    ",0,k);
     binary=pass2[i].b.bit_14;
     for(j=ZERO;j<BITS;j++)
     {
        if((binary&mask)==1)
           code[j]='/';
        else
           code[j]='.';
        mask<<=1;
     }
     fprintf(fd1,"%s",code);
     fprintf(fd1,"\n");
  }
  for(i=ZERO; i<MAX_MEMORY && pass1_var[i].num!=0; i++)
  {
     fprintf(fd1," %d%d    ",0,pass1[i].num);
     binary=pass2[i].b.bit_14;
     for(j=0;j<BITS;j++)
     {
        if((binary&mask)==1)
           code[j]='/';
        else
           code[j]='.';
        mask<<=1;
     }
     fprintf(fd1,"%s",code);
     fprintf(fd1,"\n");
  }
  rewind(fd1);
  ent(fd1);
  fclose(fd1);
}

void ent(FILE* fd)
{
  char file_name[MAX_LINE];
  int i=ZERO;
  FILE *fd2;
  char x=fgetc(fd);
  while(x==' '|| x=='\t' || x==';')/*Go ahead while there are spaces or tabs*/
     x=fgetc(fd);
  while(x!=' '&& x!='\t')/*Go ahead while there are not spaces or tabs*/
     x=fgetc(fd);
  while(x==' '|| x=='\t')/*Go ahead while there are spaces or tabs*/
     x=fgetc(fd);
  while(x!='.')/*if it's .entry or .extern*/
  {
     file_name[i] = x;
     x = fgetc(fd);
     i++;
  }
  file_name[i]='\0';
  i=ZERO; 
  strcat(file_name,".ent");
  for(i=ZERO; i<MAX_MEMORY ;i++)
  {
       if(pass1[i].ent==TRUE || pass1[i].ent==TRUE)
       { 
          fd2=fopen(file_name,"w+");
          if(fd2==NULL)
          {
              fprintf(stderr, "ERROR\n, the file did not open\n");
              exit(0);
          }
          return;
       }
  }
  for(i=ZERO; i<MAX_MEMORY && pass1[i].num!='\0';i++)
  {
      if(pass1[i].ent==TRUE)
      {
         fprintf(fd2, "%s     %d \n",pass1[i].name,pass1[i].num);
      }
  } 
  for(i=ZERO; i<MAX_MEMORY && pass1_var[i].num!='\0';i++)
  {
      if(pass1[i].ent==TRUE)
      {
         fprintf(fd2, "%s     %d \n" ,pass1_var[i].name,pass1_var [i].num);
      }
  } 
  fclose(fd2);
}


void ext(FILE* fd)
{
  char file_name[MAX_LINE];
  int i=ZERO;
  FILE *fd1;
  char x=fgetc(fd);
  while(x==' '|| x=='\t' || x==';')
     x=fgetc(fd);
  while(x!=' '&& x!='\t')
     x=fgetc(fd);
  while(x==' '|| x=='\t')
     x=fgetc(fd);
  while(x!='.')/*if it's .entry or .extern*/
  {
     file_name[i] = x;
     x = fgetc(fd);
     i++;
  }
  file_name[i]='\0';
  i=ZERO; 
  strcat(file_name,".ext");
  fd1=fopen(file_name,"w+");
  if(fd1==NULL)
     fprintf(stderr, "ERROR, the file did not open");
  
  fprintf(fd1,"\nW     110\nL3     115\nW     121\n");
  fclose(fd1);
}









