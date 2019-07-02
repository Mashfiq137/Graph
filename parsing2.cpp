#include<bits/stdc++.h>
int k=0,z=0,i=0,j=0,c=0;
char a[16],ac[20],stk[15],act[10];

void check();
int main()
   {
      puts("GRAMMAR is:\n S->S+S \n S->S-S \n S->(S) \n S->a");
      strcpy(a,"a1-(a2+a3)");
      c=strlen(a);
      strcpy(act,"SHIFT->");
      puts("stack       input       action");
      printf("\n$  \ta1-(a2+a3)$    ");
      for(k=0,i=0; j<c; k++,i++,j++)
       {
         if(a[j]=='a' && a[j+1]=='1'||(a[j]=='a'&&a[j+1]=='2')||(a[j]=='a' && a[j+1]=='3'))
           {
              char p=a[j];char q=a[j+1];
              a[j]='a';
              a[j+1]=q;
              stk[i]=a[j];
              stk[i+1]=a[j+1];
              stk[i+2]='\0';
              a[j]=' ';
              a[j+1]=' ';
              printf("\n$%s\t%s$\t%s%c%c",stk,a,act,p,q);
              check();
           }
         else
           {
              char x = a[j];
              stk[i]=a[j];
              stk[i+1]='\0';
              a[j]=' ';
              printf("\n$%s\t%s$\t%s%c",stk,a,act,x);
              check();
           }
       }
       printf("\n$S\t          $\taccepted");
   }
void check()
   {
     strcpy(ac,"REDUCE by S-->");
     for(z=0; z<c; z++)
       if(stk[z]=='a' && stk[z+1]=='1'||(stk[z]=='a' && stk[z+1]=='2')||(stk[z]=='a' &&stk[z+1]=='3'))
         {

           stk[z]='S';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%sa",stk,a,ac);
           j++;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='S' && stk[z+1]=='+' && stk[z+2]=='S')
         {
           stk[z]='S';
           stk[z+1]='\0';
           stk[z+2]='\0';
           printf("\n$%s\t%s$\t%sS+S",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='S' && stk[z+1]=='-' && stk[z+2]=='S')
         {
           stk[z]='S';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%sS-S",stk,a,ac);
           i=i-2;
         }
     for(z=0; z<c; z++)
       if(stk[z]=='(' && stk[z+1]=='S' && stk[z+2]==')')
         {
           stk[z]='S';
           stk[z+1]='\0';
           stk[z+1]='\0';
           printf("\n$%s\t%s$\t%s(S-S)",stk,a,ac);
           i=i-2;
         }
   }
