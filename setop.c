#include<stdio.h>
void input();
void output();
void setunion();
void intersection();
void difference();
int a[]={0,0,0,0,0,0,0,0},b[]={0,0,0,0,0,0,0,0};
void main()
{
  int ch,wish;
  do
  {
     printf("\n_MENU\n");
     printf("1.input\n 2.union \n 3.intersection\n 4.difference\n");
     printf("Enter choice: \n");
     scanf("%d",&ch);
     switch(ch)
     {
        case 1:input();
               break;
        case 2:setunion();
               break;
        case 3:intersection();
               break;
        case 4:difference();
              break;
     }
     printf("\n do you wish to continue?(1/0):\n");
     scanf("%d",&wish);
   }
   while(wish==1);
}
void input()
{
   int n,x,i;
   printf("Enter the size of the first set: ");
   scanf("%d",&n);
   printf("Enter the elements:  \n");
   for(i=0;i<n;i++)
   {
      scanf("%d",&x);
      a[x-1]=1;
    }
   printf("enter the size of the second set: ");
   scanf("%d",&n);
   printf("enter the elements: \n");
     	  for(i=0;i<n;i++)
   	  {
	     scanf("%d",&x);
	     b[x-1]=1;
	  }
   printf("\nfirst set: \n");
	    for(i=0;i<9;i++)
	   {
	      printf("%d",a[i]);
 		}
	   printf("%d",b[i]);
	}

void output(int c[])
{
   int i;
   printf("\nset is: ");
   for(i=0;i<9;i++)
   {
        if(c[i]!=0)
        printf("%d",i+1);
    }
}
void setunion()
{
    int i,c[10];
    for(i=0;i<9;i++)
    {
      if(a[i]!=b[i])
      c[i]=1;
      else c[i]=a[i];
    }
    for(i=0;i<9;i++)
    {
       printf("%d",c[i]);
    }
    output(c);
}
void intersection()
{
   int i,c[10];
   for(i=0;i<9;i++)
   {
      if(a[i]==b[i])
        c[i]=a[i];
      else c[i]=0;
   }
   for(i=0;i<9;i++)
   {
      printf("%d",c[i]);
   }
   output(c);
}
void difference()
{
  int i,c[10];
  for(i=0;i<9;i++)
  {
     if(a[i]==1 && b[i]==0)
        c[1]=1;
     else c[i]=0;
  }
  for(i=0;i<9;i++)
  {
    printf("%d",c[i]);
  }
  output(c);
}












