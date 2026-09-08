#include<stdio.h>
int main()
{
int data[4],codeWord[7],ctr=0,i=3,r_0,r_1,r_2;
printf("Enter a data word accordingly : \n");
while(i>=0)
{
printf("Enter a%d : ",i);
scanf("%d",&data[ctr]);
ctr++;
i--;
}
r_0=data[1]^data[2]^data[3];
r_1=data[0]^data[1]^data[2];
r_2=data[2]^data[3]^data[0];

codeWord[0]=data[0];
codeWord[1]=data[1];
codeWord[2]=data[2];
codeWord[3]=data[3];
codeWord[4]=r_2;
codeWord[5]=r_1;
codeWord[6]=r_0;

printf("Codeword for given data word is : ");
for(int i =0;i<7;i++)
{
printf("%d ",codeWord[i]);
}


}
