#include<stdio.h>

int main()
{
	int k=4, code[7];
	int data[k];
	
	for(int i=0;i<k;i++)
	{
		printf("Enter bits in dataword:");
		scanf("%d",&data[i]);
		code[i]=data[i];
	}

	int r0,r1,r2,n;
	//calc redundant bits
	
	code[6] = data[1]^data[2]^data[3];
	code[5] = data[0]^data[1]^data[2];
	code[4] = data[2]^data[3]^data[0];
	
	printf("The Code Word after adding parity is:\n ");	

	for(int i=0;i<7;i++)
	{
		printf("%d",code[i]);
	}
	
	int s0,s1,s2;
	
	s0 = code[1]^code[2]^code[3]^code[6];
	s1 = code[0]^code[1]^code[2]^code[5];
	s2 = code[2]^code[3]^code[0]^code[4];

	printf("The syndrome bits are: s2 =% d , s1 = %d , s0 = %d\n ",s2,s1,s0);

int syn=s2*100+s1*10+s0;

switch(syn)
{
	
    case 0:
	printf("No Error");
	break;

    case 1:
	printf(" Error in q0");
	break;
	
    case 10:
	printf(" Error in q1");
	break;

    case 100:
	printf(" Error in q2");
	break;

    case 101:
	printf(" Error in b0");
        if(code[3] == 1)
            code[3] = 0;
        else
            code[3] = 1;
        break;

    case 111:
        printf(" Error in b1");
        if(code[2] == 1)
            code[2] = 0;
        else
            code[2] = 1;
        break;

    case 011:
	printf(" Error in b2");
        if(code[1] == 1)
            code[1] = 0;
        else
            code[1] = 1;
        break;

    case 110:
	printf(" Error in b3");
        if(code[0] == 1)
            code[0] = 0;
        else
            code[0] = 1;
        break;
}

printf("\nFinal Codeword:");
for (int i=0;i<4;i++)

{
	
	printf("%d",code[i]);

}	


return 0;
}