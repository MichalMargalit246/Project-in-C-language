#include "declaration.h"


/*1 register*/
int register1(char line[],int j)
{
      int flag=FALSE;
      if(line[j]=='r' && line[j+1]>='0' && line[j+1]<='7') /*The first operand is register*/
          flag=TRUE;
      return flag;
}

/*2 register*/
int register2(char line[],int j)
{
      int flag=FALSE;
      while(line[j]!=' ' && line[j]!='\t' && line[j]!=',')
          j++;
      while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
          j++;
      if(line[j]=='r' && line[j+1] >='0' && line[j+1]<='7')/*the second operand is register too*/
          flag=TRUE;
     return flag;
}

/*number1*/
int number1(char line[],int j)
{
    int flag=FALSE;
    if(line[j]=='#')
        flag=TRUE;
    return flag;
}

/*number2*/
int number2(char line[],int j)
{
    int flag=FALSE;
    while(line[j]!=' ' && line[j]!='\t'&&line[j]!=',')
        j++;
    while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
        j++;
    if(line[j]=='#')
        flag=TRUE;
    return flag;
}

/*variable1*/
int variable1(char line[],int j)
{
    int flag=FALSE, w=ZERO;
    char help[MAX_INPUT];
    while(line[j]!=' ' && line[j]!='\t' && line[j]!=','&& line[j]!='\n')
    {
        help[w]=line[j];
        j=j+1;
        w=w+1;
    }
    j=j+1;
    help[w]='\0';
    for(w=ZERO; w<MAX_MEMORY; w++)
    {
       if(strcmp(pass1[w].name,help)==0)
       {
            return pass1[w].num;
       }
       if(strcmp(pass1_var[w].name,help)==0)
       {
            return pass1_var[w].num;
       }
    }
    return flag;
}

/*variable2*/
int variable2(char line[],int j)
{
    int flag=FALSE, w=ZERO;
    char help[MAX_INPUT];
    while(line[j]!=' ' && line[j]!='\t' && line[j]!=','&& line[j]!='\n')
        j++;
    while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
        j++;
    while(line[j]!=' '&&line[j]!='\t'&&line[j]!=')'&& line[j]!='\n')
    {
        help[w]=line[j];
        w++;
        j++;
    }
    help[w]='\0';
    for(w=ZERO; w<MAX_MEMORY; w++)
    {
       if(strcmp(pass1[w].name,help)==0)
       {
            return pass1[w].num;
       }
       if(strcmp(pass1_var[w].name,help)==0)
       {
            return pass1_var[w].num;
       }
    }
    return flag;
}

/*number of register*/
int num_of_reg(char line[],int j)
{
    if(line[j+1]=='0')
       return 0;
    if(line[j+1]=='1')
       return 1;
    if(line[j+1]=='2')
       return 2;
    if(line[j+1]=='3')
       return 3;
    if(line[j+1]=='4')
       return 4;
    if(line[j+1]=='5')
       return 5;
    if(line[j+1]=='6')
       return 6;
    if(line[j+1]=='7')
       return 7;    
    return -1;
}

/*lookfor the address of label from pass1*/
int add_of_label(char line[],int j)
{
   int w=ZERO;
   char help[MAX_INPUT];
   while(line[j]!=' '&&line[j]!='\t'&&line[j]!=','&&line[j]!='\n') 
   {
      help[w]=line[j];
      w++;
      j++;
   }    
   for(w=ZERO; w<MAX_MEMORY; w++)
   {
       if(strcmp(pass1[w].name,help)==0)
       {
            return pass1[w].num;
       }
       if(strcmp(pass1_var[w].name,help)==0)
       {
            return pass1_var[w].num;
       }
   }
   return -1;
}

/*The function counts commas*/
int commas_sum(char line[],int j)
{
    int sum=ZERO;
    while(line[j]!='\n')
    {
       if(line[j]==',')
            sum++;
       j++;  
    }
    return sum+1;
} 

/*return the action number*/
int num_of_act(char* act)
{ 
  if(strcmp(act,"mov")==0)
     return 0;
  if(strcmp(act,"cmp")==0)
     return 1;
  if(strcmp(act,"add")==0)
     return 2;
  if(strcmp(act,"sub")==0)
     return 3;
  if(strcmp(act,"not")==0)
     return 4;
  if(strcmp(act,"clr")==0)
     return 5;
  if(strcmp(act,"lea")==0)
     return 6;
  if(strcmp(act,"inc")==0)
     return 7;
  if(strcmp(act,"dec")==0)
     return 8;
  if(strcmp(act,"jmp")==0)
     return 9;
  if(strcmp(act,"bne")==0)
     return 10;
  if(strcmp(act,"red")==0)
     return 11;
  if(strcmp(act,"prn")==0)
     return 12;
  if(strcmp(act,"jsr")==0)
     return 13;
  if(strcmp(act,"rts")==0)
     return 14;
  if(strcmp(act,"stop")==0)
     return 15;
  return -1;
}
/*Returns the position of the label in the array pass1*/
int place_of_label(char line[],int j)
{
   int w=ZERO;
   char help[MAX_INPUT];
   while(line[j]!=' '&&line[j]!='\t'&&line[j]!=','&&line[j]!='\n') 
   {
      help[w]=line[j];
      w++;
      j++;
   }    
   for(w=ZERO; w<MAX_MEMORY; w++)
   {
       if(strcmp(pass1[w].name,help)==0)
       {
            return w;
       }
   }
   return -1;
}
/*Returns the position of the label in the array pass1_var*/
int place_of_label_var(char line[],int j)
{
   int w=ZERO;
   char help[MAX_INPUT];
   while(line[j]!=' '&&line[j]!='\t'&&line[j]!=','&&line[j]!='\n') 
   {
      help[w]=line[j];
      w++;
      j++;
   }    
   for(w=ZERO; w<MAX_MEMORY; w++)
   {
       if(strcmp(pass1_var[w].name,help)==0)
       {
            return w;
       }
   }
   return -1;
}





