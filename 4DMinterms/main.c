#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 12

// 4-D Array
int a[N][N][N][N];

//16 States
int S0[4]={0,0,0,0};
int S1[4]={0,0,0,1};
int S2[4]={0,0,1,0};
int S3[4]={0,0,1,1};
int S4[4]={0,1,0,0};
int S5[4]={0,1,0,1};
int S6[4]={0,1,1,0};
int S7[4]={0,1,1,1};
int S8[4]={1,0,0,0};
int S9[4]={1,0,0,1};
int S10[4]={1,0,1,0};
int S11[4]={1,0,1,1};
int S12[4]={1,1,0,0};
int S13[4]={1,1,0,1};
int S14[4]={1,1,1,0};
int S15[4]={1,1,1,1};

//Non-Allowed States {S0,S8,S11,S14}

//Pointers
int i1,i2,i3,i4;

//Count Cells in the Array
int countCells=0;

//Functions
int fa[4];  //{xa,ya,za,ka}
int fb[4];  //{xb,yb,zb,kb}
int fc[4];  //{xc,yc,zc,kc}
int fd[4];  //{xd,yd,zc,kc}

//Functions
void CalculateMinElements();
void maxElement();
void minElement();
int determineDa();
int determineDb();
int determineDc();
int determineDd();

// Da, Db, Dc, Dd
int Da,Db,Dc,Dd;

int main(int argc, char *argv[])
{
    for(i1=0;i1<N;i1++) //S0
    {
                   
                        
          if(i1==0)   {fa[0]=0;fa[1]=0;fa[2]=0;fa[3]=1; }          
           else if (i1==1)  {fa[0]=0;fa[1]=0;fa[2]=1;fa[3]=0;}          
            else if (i1==2)  {fa[0]=0;fa[1]=0;fa[2]=1;fa[3]=1;}          
             else if (i1==3)  {fa[0]=0;fa[1]=1;fa[2]=0;fa[3]=0;}           
              else if (i1==4)  { fa[0]=0;fa[1]=1;fa[2]=0;fa[3]=1;}        
               else if (i1==5)  {fa[0]=0;fa[1]=1;fa[2]=1;fa[3]=0;}             
                else if (i1==6)  {fa[0]=0;fa[1]=1;fa[2]=1;fa[3]=1;}             
                 else if (i1==7)   {fa[0]=1;fa[1]=0;fa[2]=0;fa[3]=1;}             
                  else if (i1==8)   {fa[0]=1;fa[1]=0;fa[2]=1;fa[3]=0;}              
                   else if (i1==9)   {fa[0]=1;fa[1]=1;fa[2]=0;fa[3]=0;}             
                    else if (i1==10)   {fa[0]=1;fa[1]=1;fa[2]=0;fa[3]=1;}        
                     else if (i1==11)   {fa[0]=1;fa[1]=1;fa[2]=1;fa[3]=1;}
                     
                        
                        
                        
                       
                        
                        
         for(i2=0;i2<N;i2++)  //S8
         {
         if(i2==0)  {fb[0]=0;fb[1]=0;fb[2]=0;fb[3]=1;}         
           else if (i2==1)   {fb[0]=0;fb[1]=0;fb[2]=1;fb[3]=0;}         
             else if (i2==2)   {fb[0]=0;fb[1]=0;fb[2]=1;fb[3]=1;}         
                else if (i2==3)    {fb[0]=0;fb[1]=1;fb[2]=0;fb[3]=0;}          
                 else if (i2==4)    { fb[0]=0;fb[1]=1;fb[2]=0;fb[3]=1;}         
                  else if (i2==5)    {fb[0]=0;fb[1]=1;fb[2]=1;fb[3]=0;}          
                   else if (i2==6)     {fb[0]=0;fb[1]=1;fb[2]=1;fb[3]=1;}         
                     else if (i2==7)    {fb[0]=1;fb[1]=0;fb[2]=0;fb[3]=1;}           
                      else if (i2==8)     {fb[0]=1;fb[1]=0;fb[2]=1;fb[3]=0;}            
                       else if (i2==9)     {fb[0]=1;fb[1]=1;fb[2]=0;fb[3]=0;}           
                        else if (i2==10)     {fb[0]=1;fb[1]=1;fb[2]=0;fb[3]=1;}        
                         else if (i2==11)     {fb[0]=1;fb[1]=1;fb[2]=1;fb[3]=1;}
                              
                              
                              
                              
                              
              for(i3=0;i3<N;i3++)  //S11
              {
                      if(i3==0) {fc[0]=0;fc[1]=0;fc[2]=0;fc[3]=1;}         
                      else if (i3==1)  {fc[0]=0;fc[1]=0;fc[2]=1;fc[3]=0;}         
                       else if (i3==2)   {fc[0]=0;fc[1]=0;fc[2]=1;fc[3]=1;}        
                         else if (i3==3)   {fc[0]=0;fc[1]=1;fc[2]=0;fc[3]=0;}        
                           else if (i3==4)    {fc[0]=0;fc[1]=1;fc[2]=0;fc[3]=1;}        
                              else if (i3==5)    {fc[0]=0;fc[1]=1;fc[2]=1;fc[3]=0;}           
                                 else if (i3==6)     {fc[0]=0;fc[1]=1;fc[2]=1;fc[3]=1;}         
                                   else if (i3==7)     {fc[0]=1;fc[1]=0;fc[2]=0;fc[3]=1;}         
                                     else if (i3==8)    {fc[0]=1;fc[1]=0;fc[2]=1;fc[3]=0;}          
                                       else if (i3==9)    {fc[0]=1;fc[1]=1;fc[2]=0;fc[3]=0;}        
                                         else if (i3==10)    {fc[0]=1;fc[1]=1;fc[2]=0;fc[3]=1;}       
                                          else if (i3==11)    {fc[0]=1;fc[1]=1;fc[2]=1;fc[3]=1;}
               
                       
                                   
                                   
                                   
                                   
                   for(i4=0;i4<N;i4++)   //S14
                   {
                           if(i4==0)   {fd[0]=0;fd[1]=0;fd[2]=0;fd[3]=1;}           
                              else if (i4==1)   {fd[0]=0;fd[1]=0;fd[2]=1;fd[3]=0;}       
                               else if (i4==2)   {fd[0]=0;fd[1]=0;fd[2]=1;fd[3]=1;}        
                                else if (i4==3)   {fd[0]=0;fd[1]=1;fd[2]=0;fd[3]=0;}        
                                 else if (i4==4)    {fd[0]=0;fd[1]=1;fd[2]=0;fd[3]=1;}         
                                  else if (i4==5)    {fd[0]=0;fd[1]=1;fd[2]=1;fd[3]=0;}          
                                    else if (i4==6)    {fd[0]=0;fd[1]=1;fd[2]=1;fd[3]=1;}          
                                       else if (i4==7)     { fd[0]=1;fd[1]=0;fd[2]=0;fd[3]=1;}         
                                         else if (i4==8)     { fd[0]=1;fd[1]=0;fd[2]=1;fd[3]=0;}         
                                           else if (i4==9)      {fd[0]=1;fd[1]=1;fd[2]=0;fd[3]=0;}         
                                            else if (i4==10)     {fd[0]=1;fd[1]=1;fd[2]=0;fd[3]=1;}          
                                             else if (i4==11)     {fd[0]=1;fd[1]=1;fd[2]=1;fd[3]=1;}
                           
                                           
                                           
                   Da=determineDa();
                   Db=determineDb();
                   Dc=determineDc();
                   Dd=determineDd();
                   
                   a[i1][i2][i3][i4]=Da+Db+Dc+Dd;
                   
                   
                   countCells++;
            
                   }
            
               }
            
         }
            
     }
     
     printf("\n\t\tThe 4-D Array Calculator");
     
     printf("\n\n\n\n\tThe Array has %d cells.",countCells);
     printf("\n\tand that because of the 4-D=12^4= %d Solutions\n",countCells);
    printf("\n----------------------------------------------------------------------------- \n");
    
     minElement();
     maxElement();
     CalculateMinElements();
     
     
  system("PAUSE");	
  return 0;
}

void CalculateMinElements()
{
     
     int m=13;  //i know that the minimum sum is 13 from the other function
     int countMin=0;
     int xi=1;
     printf("\nThese are the best Solutions:\n");
     for(i1=0;i1<N;i1++) //S0
    {
         for(i2=0;i2<N;i2++)  //S8
         {         
              for(i3=0;i3<N;i3++)  //S11
              {                  
                   for(i4=0;i4<N;i4++)   //S14
                   {           
                                         
                    if(a[i1][i2][i3][i4]==13)
                    {
                        countMin++;
                        
                        
                        printf("\n%d. a[%d][%d][%d][%d]= %d",xi,i1,i2,i3,i4,a[i1][i2][i3][i4]);
                        xi++;       
                    }
                        
                                              
                   }
            
               }
            
         }
            
     }
     printf("\nThe above %d cells are those with the minimum Sum of Minterms\n",countMin);
      printf("So there are %d Best Solutions.\n",countMin);
 }

void minElement()
{
     int k1=0,k2=0,k3=0,k4=0;
     
     int min=a[0][0][0][0];
     for(i1=0;i1<N;i1++) //S0
    {
         for(i2=0;i2<N;i2++)  //S8
         {         
              for(i3=0;i3<N;i3++)  //S11
              {                  
                   for(i4=0;i4<N;i4++)   //S14
                   {                     
                   if(min>a[i1][i2][i3][i4])
                   {
                        min=a[i1][i2][i3][i4];
                        k1=i1;
                        k2=i2;
                        k3=i3;
                        k4=i4;
                        }
                                              
                   }
            
               }
            
         }
            
     }
     printf("\nMinimum Element : a[%d][%d][%d][%d] = %d\n"
     ,k1,k2,k3,k4,a[k1][k2][k3][k4]);
 }
 
 
 void maxElement()
{
     int k1=0,k2=0,k3=0,k4=0;
     
     int max=a[0][0][0][0];
     for(i1=0;i1<N;i1++) //S0
    {
         for(i2=0;i2<N;i2++)  //S8
         {         
              for(i3=0;i3<N;i3++)  //S11
              {                  
                   for(i4=0;i4<N;i4++)   //S14
                   {                     
                   if(max<a[i1][i2][i3][i4])
                   {
                        max=a[i1][i2][i3][i4];
                        k1=i1;
                        k2=i2;
                        k3=i3;
                        k4=i4;
                        }
                                              
                   }
            
               }
            
         }
            
     }
     printf("\nMaximum Element : a[%d][%d][%d][%d] = %d\n"
     ,k1,k2,k3,k4,a[k1][k2][k3][k4]);
 }
 
 
int determineDa()    //Need of the fa[0], fa[1], fa[2], fa[3]
{      
       int i=0;
       
       if(((fa[i]==S1[i])&&(fa[i+1]==S1[i+1]) && 
       (fa[i+2]==S1[i+2])&&(fa[i+3]==S1[i+3])) ||
       ((fa[i]==S2[i])&&(fa[i+1]==S2[i+1]) && 
       (fa[i+2]==S2[i+2])&&(fa[i+3]==S2[i+3])) ||
       ((fa[i]==S4[i])&&(fa[i+1]==S4[i+1]) && 
       (fa[i+2]==S4[i+2])&&(fa[i+3]==S4[i+3])) ||
       ((fa[i]==S13[i])&&(fa[i+1]==S13[i+1]) && 
       (fa[i+2]==S13[i+2])&&(fa[i+3]==S13[i+3])))
                 return 4;
       else if (((fa[i]==S3[i])&&(fa[i+1]==S3[i+1]) && 
       (fa[i+2]==S3[i+2])&&(fa[i+3]==S3[i+3])) || 
       ((fa[i]==S5[i])&&(fa[i+1]==S5[i+1]) && 
       (fa[i+2]==S5[i+2])&&(fa[i+3]==S5[i+3])) ||
       ((fa[i]==S6[i])&&(fa[i+1]==S6[i+1]) && 
       (fa[i+2]==S6[i+2])&&(fa[i+3]==S6[i+3])) ||
       ((fa[i]==S15[i])&&(fa[i+1]==S15[i+1]) && 
       (fa[i+2]==S15[i+2])&&(fa[i+3]==S15[i+3])))
                 return 5;
       else if(((fa[i]==S7[i])&&(fa[i+1]==S7[i+1]) && 
       (fa[i+2]==S7[i+2])&&(fa[i+3]==S7[i+3])))
                 return 6;
       else if(((fa[i]==S9[i])&&(fa[i+1]==S9[i+1]) && 
       (fa[i+2]==S9[i+2])&&(fa[i+3]==S9[i+3]))||
       ((fa[i]==S10[i])&&(fa[i+1]==S10[i+1]) && 
       (fa[i+2]==S10[i+2])&&(fa[i+3]==S10[i+3])) ||
       ((fa[i]==S12[i])&&(fa[i+1]==S12[i+1]) && 
       (fa[i+2]==S12[i+2])&&(fa[i+3]==S12[i+3])))
                 return 3;
                             
 
}

int determineDb()      //Need of the fb[0], fb[1], fb[2], fb[3]
{      
       int i=0;
       
       if(((fb[i]==S1[i])&&(fb[i+1]==S1[i+1]) && 
       (fb[i+2]==S1[i+2])&&(fb[i+3]==S1[i+3])) ||
       ((fb[i]==S2[i])&&(fb[i+1]==S2[i+1]) && 
       (fb[i+2]==S2[i+2])&&(fb[i+3]==S2[i+3])) ||
       ((fb[i]==S5[i])&&(fb[i+1]==S5[i+1]) && 
       (fb[i+2]==S5[i+2])&&(fb[i+3]==S5[i+3])) ||
       ((fb[i]==S6[i])&&(fb[i+1]==S6[i+1]) && 
       (fb[i+2]==S6[i+2])&&(fb[i+3]==S6[i+3])) ||
       ((fb[i]==S9[i])&&(fb[i+1]==S9[i+1]) && 
       (fb[i+2]==S9[i+2])&&(fb[i+3]==S9[i+3])) ||
       ((fb[i]==S13[i])&&(fb[i+1]==S13[i+1]) && 
       (fb[i+2]==S13[i+2])&&(fb[i+3]==S13[i+3])))
                 return 4;
       else if (((fb[i]==S4[i])&&(fb[i+1]==S4[i+1]) && 
       (fb[i+2]==S4[i+2])&&(fb[i+3]==S4[i+3])) || 
       ((fb[i]==S10[i])&&(fb[i+1]==S10[i+1]) && 
       (fb[i+2]==S10[i+2])&&(fb[i+3]==S10[i+3])) ||
       ((fb[i]==S12[i])&&(fb[i+1]==S12[i+1]) && 
       (fb[i+2]==S12[i+2])&&(fb[i+3]==S12[i+3])) )
                 return 5;
       else if(((fb[i]==S3[i])&&(fb[i+1]==S3[i+1]) && 
       (fb[i+2]==S3[i+2])&&(fb[i+3]==S3[i+3])) ||
       ((fb[i]==S7[i])&&(fb[i+1]==S7[i+1]) && 
       (fb[i+2]==S7[i+2])&&(fb[i+3]==S7[i+3])) ||
       ((fb[i]==S15[i])&&(fb[i+1]==S15[i+1]) && 
       (fb[i+2]==S15[i+2])&&(fb[i+3]==S15[i+3])))
                 return 3;
}

int determineDc()            //Need of the fc[0], fc[1], fc[2], fc[3]
{      
       int i=0;
       
       if(((fc[i]==S1[i])&&(fc[i+1]==S1[i+1]) && 
       (fc[i+2]==S1[i+2])&&(fc[i+3]==S1[i+3])) ||
       ((fc[i]==S3[i])&&(fc[i+1]==S3[i+1]) && 
       (fc[i+2]==S3[i+2])&&(fc[i+3]==S3[i+3])) ||
       ((fc[i]==S4[i])&&(fc[i+1]==S4[i+1]) && 
       (fc[i+2]==S4[i+2])&&(fc[i+3]==S4[i+3])) ||
       ((fc[i]==S6[i])&&(fc[i+1]==S6[i+1]) && 
       (fc[i+2]==S6[i+2])&&(fc[i+3]==S6[i+3])) ||
       ((fc[i]==S15[i])&&(fc[i+1]==S15[i+1]) && 
       (fc[i+2]==S15[i+2])&&(fc[i+3]==S15[i+3])) ||
       ((fc[i]==S13[i])&&(fc[i+1]==S13[i+1]) && 
       (fc[i+2]==S13[i+2])&&(fc[i+3]==S13[i+3])) ||
       ((fc[i]==S10[i])&&(fc[i+1]==S10[i+1]) && 
       (fc[i+2]==S10[i+2])&&(fc[i+3]==S10[i+3])))
                 return 4;
       else if (((fc[i]==S5[i])&&(fc[i+1]==S5[i+1]) && 
       (fc[i+2]==S5[i+2])&&(fc[i+3]==S5[i+3])) || 
       ((fc[i]==S7[i])&&(fc[i+1]==S7[i+1]) && 
       (fc[i+2]==S7[i+2])&&(fc[i+3]==S7[i+3])) ||
       ((fc[i]==S9[i])&&(fc[i+1]==S9[i+1]) && 
       (fc[i+2]==S9[i+2])&&(fc[i+3]==S9[i+3])) )
                 return 5;
       else if(((fc[i]==S2[i])&&(fc[i+1]==S2[i+1]) && 
       (fc[i+2]==S2[i+2])&&(fc[i+3]==S2[i+3])) ||
       ((fc[i]==S12[i])&&(fc[i+1]==S12[i+1]) && 
       (fc[i+2]==S12[i+2])&&(fc[i+3]==S12[i+3])))
                 return 3;
}

int determineDd()              //Need of the fd[0], fd[1], fd[2], fd[3]
{      
       int i=0;
       
       if(((fd[i]==S2[i])&&(fd[i+1]==S2[i+1]) && 
       (fd[i+2]==S2[i+2])&&(fd[i+3]==S2[i+3])) ||
       ((fd[i]==S3[i])&&(fd[i+1]==S3[i+1]) && 
       (fd[i+2]==S3[i+2])&&(fd[i+3]==S3[i+3])) ||
       ((fd[i]==S4[i])&&(fd[i+1]==S4[i+1]) && 
       (fd[i+2]==S4[i+2])&&(fd[i+3]==S4[i+3])) ||
       ((fd[i]==S5[i])&&(fd[i+1]==S5[i+1]) && 
       (fd[i+2]==S5[i+2])&&(fd[i+3]==S5[i+3])) ||
       ((fd[i]==S9[i])&&(fd[i+1]==S9[i+1]) && 
       (fd[i+2]==S9[i+2])&&(fd[i+3]==S9[i+3])) ||
       ((fd[i]==S10[i])&&(fd[i+1]==S10[i+1]) && 
       (fd[i+2]==S10[i+2])&&(fd[i+3]==S10[i+3])) ||
       ((fd[i]==S13[i])&&(fd[i+1]==S13[i+1]) && 
       (fd[i+2]==S13[i+2])&&(fd[i+3]==S13[i+3])))
                 return 5;
       else if (((fd[i]==S6[i])&&(fd[i+1]==S6[i+1]) && 
       (fd[i+2]==S6[i+2])&&(fd[i+3]==S6[i+3])) || 
       ((fd[i]==S7[i])&&(fd[i+1]==S7[i+1]) && 
       (fd[i+2]==S7[i+2])&&(fd[i+3]==S7[i+3])) ||
       ((fd[i]==S15[i])&&(fd[i+1]==S15[i+1]) && 
       (fd[i+2]==S15[i+2])&&(fd[i+3]==S15[i+3])) )
                 return 6;
       else if(((fd[i]==S1[i])&&(fd[i+1]==S1[i+1]) && 
       (fd[i+2]==S1[i+2])&&(fd[i+3]==S1[i+3])) ||
       ((fd[i]==S12[i])&&(fd[i+1]==S12[i+1]) && 
       (fd[i+2]==S12[i+2])&&(fd[i+3]==S12[i+3])))
                 return 4;
}


