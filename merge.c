#include <stdio.h>
void main()
{
int array1[50],array2[50],array3[100],m,n,i,j,s,a,k=0;
printf("\n enter the size of the 1st array:");
scanf("%d",&m);
printf("\n enter the sorted elements of 1st array:\n");
for(i=0;i<m;i++)
{
scanf("%d",&array1[i]);
}
printf("\n enter the size of 2nd array:");
scanf("%d",&n);
printf("\n enter the sorted elements of 2nd array:\n");
for(i=0;i<n;i++)
{
scanf("%d",&array2[i]);
}
i=0;
j=0;
while(i<n&&j<n)
{
if (array1[i]<array2[i])
  {
   array3[k]=array1[i];
   i++;
  }
else
{
array3[k]=array2[j];
j++;
}
k++;
}
if (i>=m)
{
while (j<n)
{
array3[k]=array2[j];
j++;
k++;
}
}
if( j>=n)
{
while (i<m)
{
array3[k]=array1[i];
i++;
k++;
}
}
printf("\n after merging and sorting:\n");
for(i=0;i<m+n;i++)
{
printf("\n%d",array3[i]);
printf("\n");
}
}


