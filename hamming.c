#include<stdio.h>

int main()
{
int n,d=0;

printf("Enter Number of bits to be in Codeword:");
scanf("%d",&n);

int c1[n];
int c2[n];

for(int i=0;i<=n;i++)
{
	printf("Enter bits in 1st Codeword:");
	scanf("%d",&c1[i]);
}
for(int i=0;i<=n;i++)
{
	printf("Enter bits in 2nd Codeword:");
	scanf("%d",&c2[i]);
}
for(int i=0;i<n;i++)
{
	if(c1[i]!=c2[i])
	{
		d=d+1;
	}
}
if(d==0)
{
	printf("Code word is Valid \n");
}
else
{
	printf("Code word is InValid");
}
printf("\n %d is the hamming distance btw two code words",d);
return 0;
}