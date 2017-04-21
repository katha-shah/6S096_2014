/*This program coverts the inputted decimal number to its equivalent binary number*/
#include<stdio.h>
int main()
{
	int i,n,a[32];
	printf("Enter the decimal number to be converted to binary : ");
	scanf("%d",&n);
	for(i=0;n>0;i++)
	{
		a[i]=n%2;
		n=n/2;
	}
	printf("The Binary equivalent is : ");
	for(i=i-1;i>=0;i--)
	{
		printf("%d",a[i]);
	}
return 0;
}

