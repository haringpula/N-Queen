#include<stdio.h>
#include<math.h>
 
int board[20],term;
 
int main()
{
 int n,i,j;
 void qplace(int row,int n);
 printf("N Queens Problem Using Backtracking");
 printf("\nEnter number of queens:");
 scanf("%d",&n);
 qplace(1,n);
 return 0;
}
void print(int n)
{
 int i,j;
 {
  printf("\nSolution: %d\n", term+1);
 
  for(i=1;i<=n;++i)
   printf("\t%d",i);
 
  for(i=1;i<=n;++i)
  {
   printf("\n%d",i);
   for(j=1;j<=n;++j) //for nxn board
   {
    if(board[i]==j)
     printf("\tQ");
    else
     printf("\t-");
   }
  }
 }
++term;
}
/*funtion to check conflicts
If no conflict for desired postion returns 1 otherwise returns 0*/
int qcheck(int row,int col)
{
 int i;
 for(i=1;i<=row-1;++i)
 {
  //checking col and diag conflicts
  if(board[i]==col)
   return 0;
  else
   if(abs(board[i]-col)==abs(i-row))
    return 0;
 }
 return 1; //no conflicts
}
 
//function to check for proper positioning of queen
int qplace(int row,int n)
{
 int col;
 for(col=1;col<=n;++col)
 {
  if(qcheck(row,col))
  {
   board[row]=col; //no conflicts
   if(row==n)
   {
   	print(n);
   	return(0);
   }
   else //try with next row
    qplace(row+1,n);
  }
 }
}
