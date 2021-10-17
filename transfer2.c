#include "declaration.h"

char line[MAX_LINE];
arr pass1[MAX_MEMORY];
arr pass1_var[MAX_MEMORY];
line_type pass2[MAX_MEMORY];

void transfer2(FILE *file)
{
  char y=fgetc(file);
  int not_act=TRUE;
  int action;
  int flag=TRUE;
  char act[NAME_OF_ACT];
  int i=ZERO,j=ZERO,k=ZERO,x=ZERO,p=ZERO;
  int size=IC+DC-FIRST_MEMORY;
  printf("\npass 2:\n");
  for(p=ZERO;p<size && y!=EOF;p++)
  {
    i=ZERO;
    k=ZERO;
    for(i=ZERO;i<MAX_LINE;i++)/*Initializing the array line*/
       line[i]='\0';
    for(i=ZERO;i<NAME_OF_ACT;i++)/*Initializing the array act*/
        act[i]='\0';
    i=ZERO;
    while(i<MAX_LINE && y!='\n' && y!=EOF)/*Copy a line from the file into a defined array*/ 
    { 
       line[i]=y;
       i++;
       y=fgetc(file);   
    }
    line[i]='\n';
    i=ZERO;
    while(line[i]==' ' || line[i]=='\t')/*Go ahead while there are spaces or tabs*/
            i++;    
   if(line[i]!='.'&&line[i]!=';'&&line[i]!='\n')
   {
    for(i=ZERO;i<MAX_LINE && line[i]!='\0' && flag; i++)/*If the line starts with a variable name*/
    {
           if(line[i] == ':')
              flag=FALSE;
    }
    flag=TRUE;
    if(line[i] == '\0')
        i=ZERO;
    while(line[i]==' ' || line[i]=='\t')/*Go ahead while there are spaces or tabs*/
            i++;
    while(line[i]!=' ' && line[i]!='\t' && line[i]!='\n') /*Copying the action name*/
    { 
           act[k] = line[i];
           i++;
           k++;
    }
    k=0;
    while(line[i]==' ' || line[i]=='\t')/*Go ahead while there are spaces or tabs*/
            i++;
    action=num_of_act(act);
    j=0;
    /*line 1*/   
    switch(action){
        case MOV:
             pass2[x].w.opcode=0;
             pass2[x].w.parm1=0;
             pass2[x].w.parm2=0;
             pass2[x].w.era=0;
             if(register1(line,i)==TRUE)
             {
                 pass2[x].w.sour_operand=3;
             }
             else
             {
                if(number1(line,i)==TRUE)
                    pass2[x].w.sour_operand=0;
                else
                    pass2[x].w.sour_operand=1;
             }
             j=i;
             while(line[j]!=' '&&line[j]!='\t'&&line[j]!=',')
                  j++;
             while(line[j]==' '||line[j]=='\t'||line[j]==',')
                  j++;
             if(register1(line,j)==TRUE)
             {
                 pass2[x].w.des_operand=3;
                 break;
             }
             else
                 pass2[x].w.des_operand=1;
             break;
        case CMP:
             pass2[x].w.opcode = 1;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             if(register1(line,i)==TRUE)
                 pass2[x].w.sour_operand=3;
             if(register2(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(number1(line,i)==TRUE)
                 pass2[x].w.sour_operand=00;
             if(number1(line,i)==TRUE)
                 pass2[x].w.des_operand=00; 
             if(variable1(line,i)==TRUE)
                  pass2[x].w.sour_operand=01;
             if(variable2(line,i)==TRUE)
                 pass2[x].w.des_operand=01;  
             break;
        case ADD:
             pass2[x].w.opcode = 2;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             if(register1(line,i)==TRUE)
                 pass2[x].w.sour_operand=3;
             if(register2(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(number1(line,i)==TRUE)
                 pass2[x].w.sour_operand=00; 
             if(variable1(line,i)==TRUE)
                  pass2[x].w.sour_operand=01;
             if(variable2(line,i)==TRUE)
                 pass2[x].w.des_operand=01; 
             break;
        case SUB:
             pass2[x].w.opcode = 3;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             if(register1(line,i)==TRUE)
                 pass2[x].w.sour_operand=3;
             if(register2(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(number1(line,i)==TRUE)
                 pass2[x].w.sour_operand=00; 
             if(variable1(line,i)==TRUE)
                  pass2[x].w.sour_operand=01;
             if(variable2(line,i)==TRUE)
                 pass2[x].w.des_operand=01;
             break;
        case NOT:
             pass2[x].w.opcode = 4;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00; 
             if(register1(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(variable1(line,i)==TRUE)
                 pass2[x].w.des_operand=01;
             break;
        case CLR:
             pass2[x].w.opcode = 5;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00; 
             if(register2(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(variable2(line,i)==TRUE)
                 pass2[x].w.des_operand=01;
             break;
        case LEA:
             pass2[x].w.opcode = 6;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=01;
             if(register1(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(variable1(line,i)==TRUE)
                 pass2[x].w.des_operand=01;
             break;
        case INC:
             pass2[x].w.opcode = 7;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00;
             if(register1(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(variable1(line,i)==TRUE)
                 pass2[x].w.des_operand=01;
             break;
        case DEC:
             pass2[x].w.opcode = 8;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00; 
             if(register1(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(variable1(line,i)==TRUE)
                 pass2[x].w.des_operand=01;
             break;
        case JMP:
             pass2[x].w.opcode = 9;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00;
             if(register1(line,i))
             {
               pass2[x].w.des_operand=3;  
               pass2[x].w.parm1= 0 ;
               pass2[x].w.parm2= 0 ;
               break;
             }
             else
             {
               while(i!='\n')
               {
                 if(line[i]=='(')
                 {
                    j=1;
                    i++;
                    pass2[x].w.des_operand=2; 
                    if(register1(line,i)==TRUE)
                       pass2[x].w.parm1=3;
                    if(register2(line,i)==TRUE)
                       pass2[x].w.parm2=3;
                    if(number1(line,i)==TRUE)
                       pass2[x].w.parm1=0;
                    if(number2(line,i)==TRUE)
                       pass2[x].w.parm2=0;  
                    if(variable1(line,i)==TRUE)
                       pass2[x].w.parm1=01;
                    if(variable2(line,i)==TRUE)
                       pass2[x].w.parm2=01;
                    break;
                 }
                i++;  
               }
             }
             if(j==0)
             {
               pass2[x].w.des_operand=1;  
               pass2[x].w.parm1= 0 ;
               pass2[x].w.parm2= 0 ;
             }
             break;
        case BNE:
             pass2[x].w.opcode = 10;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00;
             if(register1(line,i))
             {
               pass2[x].w.des_operand=3;  
               pass2[x].w.parm1= 0 ;
               pass2[x].w.parm2= 0 ;
               break;
             }
             else
             {
               k=i;
               while(k!='\n')
               {
                 if(line[k]=='(')
                 {
                    j=1;
                    k++;
                    pass2[x].w.des_operand=2; 
                    if(register1(line,k)==TRUE)
                       pass2[x].w.parm1=3;
                    if(register2(line,k)==TRUE)
                       pass2[x].w.parm2=3;
                    if(number1(line,k)==TRUE)
                       pass2[x].w.parm1=0;
                    if(number2(line,k)==TRUE)
                       pass2[x].w.parm2=0;  
                    if(variable1(line,k)==TRUE)
                       pass2[x].w.parm1=01;
                    if(variable2(line,k)==TRUE)
                       pass2[x].w.parm2=01;
                    break;
                 }
                k++;  
               }
             }
             if(j==0)
             {
               pass2[x].w.des_operand=1;  
               pass2[x].w.parm1= 0 ;
               pass2[x].w.parm2= 0 ;
             }
             break;
        case RED:
             pass2[x].w.opcode = 11;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00; 
             if(register1(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(variable1(line,i)==TRUE)
                 pass2[x].w.des_operand=01;
             break;
        case PRN:
             pass2[x].w.opcode = 12;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00;
             if(register1(line,i)==TRUE)
                 pass2[x].w.des_operand=3;
             if(variable1(line,i)==TRUE)
                 pass2[x].w.des_operand=01;
             if(number1(line,i)==TRUE)
                 pass2[x].w.des_operand=00;
             break;
        case JSR:
             pass2[x].w.opcode = 13;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00;
             if(register1(line,i))
             {
               pass2[x].w.des_operand=3;  
               pass2[x].w.parm1= 0 ;
               pass2[x].w.parm2= 0 ;
               break;
             }
             else
             {
               while(i!='\n')
               {
                 if(line[i]=='(')
                 {
                    j=1;
                    i++;
                    pass2[x].w.des_operand=2; 
                    if(register1(line,i)==TRUE)
                       pass2[x].w.parm1=3;
                    if(register2(line,i)==TRUE)
                       pass2[x].w.parm2=3;
                    if(number1(line,i)==TRUE)
                       pass2[x].w.parm1=0;
                    if(number2(line,i)==TRUE)
                       pass2[x].w.parm2=0;  
                    if(variable1(line,i)==TRUE)
                       pass2[x].w.parm1=01;
                    if(variable2(line,i)==TRUE)
                       pass2[x].w.parm2=01;
                    break;
                 }
                i++;  
               }
             }
             if(j==0)
             {
               pass2[x].w.des_operand=1;  
               pass2[x].w.parm1= 0 ;
               pass2[x].w.parm2= 0 ;
             }
             break;
        case RTS:
             pass2[x].w.opcode = 14;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00;
             pass2[x].w.des_operand=00;
             break;
        case STOP:
             pass2[x].w.opcode = 15;
             pass2[x].w.parm1=00;
             pass2[x].w.parm2=00;
             pass2[x].w.era=00;
             pass2[x].w.sour_operand=00;
             pass2[x].w.des_operand=00;
             break;
        default:
             not_act=FALSE;
             if(strcmp(act,".data")==0)
             {
                int d=commas_sum(line,i),sum=ZERO;
                for(sum=0;sum<d;sum++)
                {
                  while(line[i]==',' ||line[i]==' ' || line[i]== '\t')
                     i++;
                  pass2[x].b.bit_14=line[i];
                  x++;
                  i++;
                }
             }
             if(strcmp(act,".string")==0)
             {
                while(line[i]=='\"' || line[i]==' ' || line[i]== '\t')
                     i++;
                while(line[i]!='\"')
                {
                   pass2[x].b.bit_14=line[i];
                   i++;
                   x++;
                }
             }
             break;   
     }/*switch*/
     x++;
     /* line2*/
    if(not_act)
    {
     if(pass2[x-1].w.opcode==9 || pass2[x-1].w.opcode==10 || pass2[x-1].w.opcode==13) /*If there is no addressing method 2*/
     {
        pass2[x].a.place=add_of_label(line,i);
        pass2[x].r.era=2;
        x++;
     }
     while(line[i]==' ' || line[i]=='\t' || line[i]==',' || line[i]=='(')
          i++; 
     if(register1(line,i) && register2(line,i))/*r-r*/     
     {
        pass2[x].r.source_r=num_of_reg(line,i);
        while(line[i]==' ' || line[i]=='\t' || line[i]==',')
        {
          i++;
        }
        pass2[x].r.destination_r=num_of_reg(line,i);
        pass2[x].r.era=00;
        x++;
     }
     else
     {
       if(register1(line,i))  /*r---*/
       {
           pass2[x].r.source_r=num_of_reg(line,i);
           pass2[x].r.destination_r=0;
           pass2[x].r.era=00;
       }
       else
       {
           if(number1(line,i)) /*----n*/
           {
               char number[NUM_IN_12_BITS];
               i++;
               j=0;
               while(line[i]!=' '&&line[i]!='\t'&&line[i]!=','&&line[i]!='\n')
               {
                    number[j]=line[i];
                    j++;
                    i++;
               }
               number[j]='\0';
               pass2[x].a.place=atoi(number);
               pass2[x].a.era=00;
           }
           else   /*v----*/
           {
               pass2[x].a.place=add_of_label(line,i);
               pass2[x].a.era=2;
           }
       }
       while(line[i]!=' '&&line[i]!='\t'&&line[i]!=','&&line[i]!='\n')
           i++;
       if(line[i]!='\n')
           x++;
       while(line[i]==' '||line[i]=='\t'||line[i]==',')
           i++;     
       /*-----r//v//n  */
       if(register1(line,i))  /*---r*/
       {
           pass2[x].r.destination_r=num_of_reg(line,i);
           pass2[x].r.source_r=0;
           pass2[x].r.era=00;
       }
       else
       {
           if(number1(line,i)) /*----n*/
           {
               char number[NUM_IN_12_BITS];
               i++;
               j=0;
               while(line[i]!=' '&&line[i]!='\t'&&line[i]!=','&&line[i]!='\n')
               {
                    number[j]=line[i];
                    j++;
                    i++;
               }
               number[j]='\0';
               pass2[x].a.place=atoi(number);
               pass2[x].a.era=00;
           }
           else   /*----v*/
           {
               if(variable1(line,i))
               {
                  pass2[x].a.place=add_of_label(line,i);
                  pass2[x].a.era=2;
               }
           }
       }
       x++;
     }/*else*/
    }/*if(not_act)*/
   }/*if*/
   y=fgetc(file);
  }/*for*/

   rewind(file);
   object(file);
   rewind(file);
   ent(file);
   rewind(file);
   ext(file);
}/*transfer2*/
