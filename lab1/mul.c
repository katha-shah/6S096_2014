#include<stdio.h>

int main()
{
	int m,n,c,d,p,q,i,sum=0,a[10][10],b[10][10],z[10][10];
	printf("Enter the number of rows and columns of first matrix: \n");
	scanf("%d %d",&m,&n);
	printf("Enter the elements of first matrix\n");
	for(c=0;c<m;c++)
		for(d=0;d<n;d++)
		scanf("%d",&a[c][d]);


	printf("Enter the no of elements of the second matrix:\n");
	scanf("%d %d",&p,&q);
	if( n!=p)
	{	
		printf("Matrix multipliaction is not possible\n");
	}
	else 
	{
		printf("Elements of the second matrix\n");
		for(c=0;c<p;c++)
		for(d=0;d<q;d++)
		{
			scanf("%d",&b[c][d]);
		}
	}

	for(c=0;c<m;c++)
	{
	  for(d=0;d<q;d++)
	  {
		for(i=0;i<p;i++)
		{	
		  sum=sum+(a[c][i]*b[i][d]);
		}
	    z[c][d]=sum;
	    sum=0;
	  }
        }
	printf("Product of the matrices is :\n");
	for(c=0;c<m;c++)
	{
	 for(d=0;d<q;d++)
	 {
	  printf("%d \t ",z[c][d]);
		
	 }
	printf("\n");
	}	
return 0;
}
