#include "declaration.h"

char line[MAX_LINE]; 
arr pass1[MAX_MEMORY];
arr pass1_var[MAX_MEMORY];

void transfer(FILE *f1)
{
  int sum=-1;
  int sum_var=-1;
  int i=ZERO, j=ZERO, help=ZERO;
  char x=fgetc(f1);
  char act[NAME_OF_ACT];
  int flag=TRUE;
  int action;
  IC=FIRST_MEMORY;
  DC=ZERO;
  for(i=ZERO;i<MAX_MEMORY;i++)
  {
     pass1_var[i].num=0;
     pass1[i].num=0;
  }
  i=ZERO;
  for(i=ZERO;i<MAX_LINE;i++)
  {
     line[i]='\0';
  }
  i=ZERO;
  printf("pass 1:\n");
  pass1[0].num=FIRST_MEMORY;
  while(x!=EOF) /*while the file is not finished*/
  {
        j=0;
        for(i=ZERO;i<MAX_LINE;i++)/*Initializing the array line*/
        {
           line[i]='\0';
        }
        for(i=ZERO;i<NAME_OF_ACT;i++)/*Initializing the array act*/
        {
           act[i]='\0';
        }
        i=ZERO;
   	while(i<MAX_LINE && x!='\n' && x!=EOF)/*Copy a line from the file into a defined array*/ 
        { 
	   line[i]=x;
           i++;
	   x=fgetc(f1);   
	}
        line[i]='\n';
        i=ZERO;
        while(line[j]==' ' || line[j]=='\t')/*Go ahead while there are spaces or tabs*/
        {
            j++;
        }
        if(line[j] == '.' || line[j] == ';' || line[j]=='\n' || line[j]=='\0')/*if the line start with ';' or '.' */
        {
            /*if(line[j] == '.')
            {
              j+=2;
              if(line[j]=='n')
                 pass1[sum+1].ent=TRUE;
              else 
              {
                 if(line[j]=='x')
                    pass1[sum+1].ext=TRUE;
                 else
                 {
                    fprintf(stderr, "\nERROR, The act is not legal\n");
                    return;
                 }
              } 
                 
              while(line[j]!=' '&&line[j]!='\t')
                 j++;
              while(line[j]==' '||line[j]=='\t')Go ahead while there are spaces or tabs
                 j++;
              for(j;j<MAX_LINE&&line[j]!=' '&&line[j]!='\t'&&line[j]!='\n';j++)
              {
                  pass1[sum].name[j]=line[j];
              }
            }*/
        }
        else  /*if line start with name of variable name)*/
        {
         pass1[sum+1].ent=FALSE;
         pass1[sum+1].ext=FALSE;
         for(i=j;i<MAX_LINE && line[i]!='\0'&&flag==TRUE; i++)/*Copies the label name to an array pass1*/
         {
           if(line[i] == ':')
           {
              flag=FALSE;
              i++;
              while(line[i]==' ' || line[i]=='\t')/*Go ahead while there are spaces or tabs*/
                   i++;
              if(line[i]=='.')
              {
                sum_var++;
                while(line[j] != ':')
                {
                  pass1_var[sum_var].name[j] = line[j];
                  j++;
                }
                /*if(sum_var==0)
                {
                   for(i=0;i<sum;i++)
                   {
                      if(strcmp((pass1_var[sum_var].name),(pass1[i].name))==0)
                      {
                           fprintf(stderr, "ERROR, there is variable with same name 1\n");
                           return 0;
                      }
                   }
                }
                else if sum_var > 0
                {
                   for(i=0;i<sum_var;i++)
                   {
                      if(strcmp(pass1_var[sum_var].name,pass1_var[i].name)==0)
                      {
                           fprintf(stderr, "ERROR, there is variable with same name 2\n");
                           exit(0);
                      }
                   }
                   for(i=0;i<sum;i++)
                   {
                      if(strcmp(pass1_var[sum_var].name,pass1[i].name)==0)
                      {
                           fprintf(stderr, "ERROR, there is variable with same name 3\n");
                           exit(0);
                      }
                   }
                }*/
              }
              else /*1*/
              {
                sum++;
                i=0;
                while(line[j]!=':')
                {
                  pass1[sum].name[i] = line[j];
                  j++;
                  i++;
                }
              }/*else1*/
              j++;
           }/*if*/
          }/*for*/
        i=help=ZERO;
        while(line[j]==' ' || line[j]=='\t')/*Go ahead while there are spaces or tabs*/
            j++;
        while(line[j]!=' ' && line[j]!='\t' && line[j]!='\n') /*Copying the action name*/
        { 
           act[i] = line[j];
           i++;
           j++;
        }
        act[i]='\0';
        action=num_of_act(act);
        i=ZERO;
        while(line[j]==' ' || line[j]=='\t')/*Go ahead while there are spaces or tabs*/
            j++;
        switch(action) {
          case MOV:
               if(register1(line,j)) /*The first operand is r*/
               {
                  j+=2;
                  while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
                      j++;
                  if(register1(line,j))/*the second operand is r too*/
                  {
                       IC+=2;
                       pass1[sum+1].num = IC; 
                       break;
                  }
               }
               IC+=3;
               pass1[sum+1].num = IC;/*one from the operands is a number or variable*/
               break;
          case CMP:
               if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*The first operand is r*/
               {
                 j+=2;
                 while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
                      j++;
                 if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7')/*the second operand is r too*/
                 {
                      IC+=2;
                      pass1[sum+1].num = IC;
                      break;
                 }
               }
               IC+=3;
               pass1[sum+1].num = IC;/*one from the operands is a number or variable*/
         
               break;
          case ADD:
               if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*The first operand is r*/
               {
                  j+=2;
                  while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
                      j++;
                  if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7')/*the second operand is r too*/
                  {
                       IC+=2;
                       pass1[sum+1].num = IC;
                       break;
                  }
               }
               IC+=3;
               pass1[sum+1].num = IC;/*one from the operands is a number or variable*/
               break;
          case SUB:
               if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*The first operand is r*/
               {
                  j+=2;
                  while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
                      j++;
                  if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7')/*the second operand is r too*/
                  {
                       IC+=2;
                       pass1[sum+1].num = IC; 
                       break;
                  }
               }
               IC+=3;
               pass1[sum+1].num = IC;/*one from the operands is a number or variable*/
               break;
          case NOT:
               IC+=2;
               pass1[sum+1].num = IC;
               break;
          case CLR:
               IC+=2;
               pass1[sum+1].num = IC;
               break;
          case LEA:
               if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*The first operand is r*/
               {
                  j+=2;
                  while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
                      j++;
                  if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7')/*the second operand is r too*/
                  {
                       IC+=2;
                       pass1[sum+1].num = IC; 
                       break;
                  }
               }
               IC+=3;
               pass1[sum+1].num = IC;/*one from the operands is a number or variable*/
               break;
          case INC:
               IC+=2;
               pass1[sum+1].num = IC;
               break;
          case DEC:
               IC+=2;
               pass1[sum+1].num = IC;
               break;
          case JMP:
               while(line[j]!='\0')/*While it's not the end of the line*/
               {
                 if(line[j]=='(')  /*If there are brackets*/
                 {
                    help=j;
                    j++;
                    if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*The first operand is r*/
                    {
                      j+=2;
                      while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
                         j++;
                      if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*the second operand is r too*/
                      {
                        IC+=3;
                        pass1[sum+1].num = IC;
                        break;
                      }
                    }
                    IC+=4;
                    pass1[sum+1].num = IC; /*one from the operands is a number or variable*/
                    break;
                 }          
                 j++;
               }
               if(line[help]!='(')
               {
                  IC+=2;
                  pass1[sum+1].num = IC;/*Variable without operands*/
               }
               break;
          case BNE:             
               while(line[j]!='\0')/*While it's not the end of the line*/
               {
                 if(line[j]=='(')  /*If there are brackets*/
                 {
                    help=j;
                    j++;
                    if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*The first operand is r*/
                    {
                      j+=2;
                      while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
                         j++;
                      if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*the second operand is r too*/
                      {
                        IC+=3;
                        pass1[sum+1].num = IC;
                        break;
                      }
                    }
                    IC+=4;
                    pass1[sum+1].num = IC; /*one from the operands is a number or variable*/
                    break;
                 }          
                 j++;
               }
               if(line[help]!='(')
               {
                  IC+=2;
                  pass1[sum+1].num = IC;/*Variable without operands*/
               }
               break;
          case RED:
               IC+=2;
               pass1[sum+1].num = IC;
               break;
          case PRN:
               IC+=2;
               pass1[sum+1].num = IC;
               break;
          case JSR:
               while(line[j]!='\0')/*While it's not the end of the line*/
               {
                 if(line[j]=='(')  /*If there are brackets*/
                 {
                    help=j;
                    j++;
                    if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*The first operand is r*/
                    {
                      j+=2;
                      while(line[j]==' ' || line[j]=='\t' || line[j]==',')/*Go ahead while there are spaces or tabs or commas*/
                         j++;
                      if(line[j] == 'r' && line[j+1] >='0' && line[j+1]<='7') /*the second operand is r too*/
                      {
                        IC+=3;
                        pass1[sum+1].num = IC;
                        break;
                      }
                    }
                    IC+=4;
                    pass1[sum+1].num = IC; /*one from the operands is a number or variable*/
                    break;
                 }          
                 j++;
               }
               if(line[help]!='(')
               {
                  IC+=2;
                  pass1[sum+1].num = IC;/*Variable without operands*/
               }
               break;
          case RTS:
               IC+=1;
               pass1[sum+1].num = IC;
               break;
          case STOP:
               IC+=1;
               pass1[sum+1].num = IC;
               break;
          default:
               if(strcmp(act,".data")==0)
               {
                 i=ZERO;
                 while(line[j]!='\0')
                 {
                   if(line[j]==',') /*Count the amount of variables*/
                      i=i+1;
                   j++;
                 }
                 i++;
                 DC= DC+i;
                 pass1_var[sum_var+1].num=DC;
                 break;
               }
               else
               {
                 if(strcmp(act,".string")==0)
                 {
                   j++;
                   i=ZERO; 
                   while(line[j]!= '\"')/*Count the amount of characters*/
                   {
                      i=i+1;
                      j++;
                   }
                   i++;
                   DC= DC+i;
                   pass1_var[sum_var+1].num=DC;
                   break;
                 }
                 else
                     fprintf(stderr, "ERROR.\n no entered a correct action \n"); /*If no correct action is taken*/
               }
            } /*switch*/
        }/*else*/
    flag=TRUE;
    x=fgetc(f1);
  } /*while*/
  for(i=ZERO;i<=sum_var;i++)
  {
     pass1_var[i].num = IC+pass1_var[i].num;
  }
  rewind(f1);
  x=fgetc(f1);
  for(i=ZERO;i<MAX_LINE;i++)/*Initializing the array line*/
  {
       line[i]='\0';
  }
  while(x!=EOF) /*while the file is not finished*/
  {
        char x_or_n='\0';
        int k=0;
        i=ZERO;
        for(i=ZERO;i<MAX_LINE;i++)/*Initializing the array line*/
        {
           line[i]='\0';
        }
        i=ZERO;
   	while(i<MAX_LINE && x!='\n' && x!=EOF)/*Copy a line from the file into a defined array*/ 
        { 
	   line[i]=x;
           i++;
	   x=fgetc(f1);   
	}
        line[i]='\n';
        i=ZERO;
        while(line[i]==' ' || line[i]=='\t')/*Go ahead while there are spaces or tabs*/
            i++;
        if(line[i] == '.' )/*if the line start with ';' or '.' */
        {
              i=i+2;
              if(line[i]=='n')
                 x_or_n='n';
              else 
              {
                 if(line[i]=='x')
                    x_or_n='x';
                 else
                 {
                    fprintf(stderr, "\nERROR, The act is not legal\n");
                    exit(0);
                 }
              }
              while(line[i]!=' '&&line[i]!='\t')
                 i++;
              while(line[i]==' '||line[i]=='\t')/*Go ahead while there are spaces or tabs*/
                 i++;
              k=place_of_label(line,i);
              if(k!=-1)
              {
                 if(x_or_n=='n')
                   pass1[k].ent=TRUE;
                 else
                 {
                   if(x_or_n=='x')
                     pass1[k].ext=TRUE;
                 }
              }
              else
              {
                 k=place_of_label_var(line,i);
                 if(k!=-1)
                 {
                   if(x_or_n=='n')
                     pass1_var[k].ent=TRUE;
                   else
                   {
                     if(x_or_n=='x')
                       pass1[k].ext=TRUE;
                   }
                 }
              } 
        }  
     x=fgetc(f1);
  }
   rewind(f1);
   transfer2(f1);
}/*transfer*/

