#include <stdio.h>
#include <stdlib.h>

/*Declare variables and data types*/

#define ROWS 8
#define COLUMNS 8


int array[ROWS][COLUMNS];
int Da,Db,Dc;
int za,zb,zc,ya,yb,yc;
int z,y;
int counter=0;
int sum=0;
/*Declare Functions*/
void determineMinterms();
void printDMinterms();
void printArray();

/*Main*/

int main(int argc, char *argv[])
{
   // printDMinterms();
    int i,j;
    for(i=0;i<ROWS;i++)
    {
            for(j=0;j<COLUMNS;j++)
            {
                                   sum=0; 
                    for (za=0;za<2;za++)
                    {
                        for(ya=0;ya<2;ya++)
                        
                        {
                         for(zb=0;zb<2;zb++)
                             {     
                                           
                                  for(yb=0;yb<2;yb++)
                                    { 
                                    for(zc=0;zc<2;zc++)
                                      { 
                                         for(yc=0;yc<2;yc++)
                                           {  
                                             determineMinterms();
                                             sum=Da+Db+Dc;                     
                                           }
                                        }
                                    }
                             }
                          }
                    }  
                                      array[i][j]=sum;
                                      counter++;
                                      printf("[%d]\n",array[i][j]);
                                
                        
                        
                }
               
            } 
     
     printf("Counter : %d \n",counter);
     //printArray();
     
     
  system("PAUSE");	
  return 0;
}

void determineMinterms()
{
     if(za==0 && ya==0)
       Da=3;
      else if(za==0 && ya==1)
      Da=2;
      else if(za==1 && ya==0)
      Da=4;
      else if(za==1 && ya==1)
      Da=3;
      
      if(zb==0 && yb==0)
       Db=3;
      else if(zb==0 && yb==1)
      Db=4;
      else if(zb==1 && yb==0)
      Db=2;
      else if(zb==1 && yb==1)
      Db=3;
      
      if(zc==0 && yc==0)
       Dc=3;
      else if(zc==0 && yc==1)
      Dc=2;
      else if(zc==1 && yc==0)
      Dc=4;
      else if(zc==1 && yc==1)
      Dc=3;
   
 }

void printDMinterms()
{
     for(za=0;za<2;za++)
    {
         for(ya=0;ya<2;ya++)
         {
          determineMinterms();
           printf("if za=%d and ya=%d then Da=%d\n",za,ya,Da);
          }
    }
    printf("\n");
    for(zb=0;zb<2;zb++)
    {
         for(yb=0;yb<2;yb++)
         {
          determineMinterms();
           printf("if zb=%d and yb=%d then Db=%d\n",zb,yb,Db);
          }
    }
    printf("\n");
     for(zc=0;zc<2;zc++)
    {
         for(yc=0;yc<2;yc++)
         {
          determineMinterms();
           printf("if zc=%d and yc=%d then Dc=%d\n",zc,yc,Dc);
          }
    }
    printf("\n");
 }


void printArray()
{
     int i,j;
     for(i=0;i<ROWS;i++)
    {
            for(j=0;j<COLUMNS;j++)
            {
                    printf("[%d]",array[i][j]);
            }
            printf("\n");
    }
    printf("\n");
}

