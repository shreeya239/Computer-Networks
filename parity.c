#include<stdio.h>

int main()
{
int r=0,k;
printf("Enter Number of bits to be in dataword:");
scanf("%d",&k);
int data[k];

for(int i=0;i<k;i++)
{
	printf("Enter bits in dataword:");
	scanf("%d",&data[i]);
}
for(int i=0;i<k;i++)
{
	if(data[i]==1)
	{
		r=r+1;
	}
}
if(r%2==0)
{
	data[k]=0;
	printf("The Code Word after adding parity is:\n ");	

	for(int i=0;i<k+1;i++)
	{
		printf("%d",data[i]);
	}
}
else if(r%2!=0)
{
	data[k]=1;	
	printf("The Code Word after adding parity is:\n ");	
	
	for(int i=0;i<k+1;i++)
	{
		printf("%d",data[i]);
	}
	
}

return 0;
}