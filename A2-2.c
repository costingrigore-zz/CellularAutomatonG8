#include <stdio.h>
#include <stdlib.h>

int rules(int left, int middle, int right)
{
	 if( left == 0 && middle == 0 && right == 0)
	        {
	            return 0;
	        }
		else if (left == 0 && middle == 0 && right == 1)
		{
		    return 1;
		}
		else if (left == 0 && middle == 1 && right == 0)
		{
		    return 1;
		    
		}
		else if (left == 0 && middle == 1 && right == 1)
		{
		    return 1;
		}
		else if (left == 1 && middle == 0 && right == 0)
		{
		    return 1;
		}
		else if (left == 1 && middle == 0 && right == 1)
		{
		    return 0;
		    
		}
		else if (left == 1 && middle == 1 && right == 0)
		{
		    return 0;
		}
		else
		{
		    return 0;
		}
}

void custom30()
{
	int height;
	int length;
	int parent[length];
	int child[length];
	printf("Please select a width across the page: \n");
	scanf("%d", &length);
	printf("Please select the depth down the page: \n");
	scanf("%d", &height);

	for(int i = 0; i < length; i++)
    	{
    		if(length/2 == i)
		{
			parent[i] = 1;
		}
		else
		{
			parent[i] = 0;
		}
    	}
    	printf("\n");
	for(int i = 0; i < length; i++)
	{
		printf("%d",parent[i]);
	}
	printf("\n");
	for(int i = 0; i<height; i++)
	{	    
		for(int i = 0; i < length; i++)
		{
			int left = parent[i-1];
			int middle = parent[i];
			int right = parent[i+1];
			int newstate = rules(left,middle,right);
			child[i] = newstate;
		}
		    
		for(int i = 0; i < length; i++)
		{
			printf("%d",child[i]);
		}
		printf("\n"); 
		for(int i = 0; i<length; i++)
		{
			parent[i] = child[i];
		}
			  
	}
	
}

//I based this method on this reference: https://www.quora.com/How-do-you-convert-a-binary-number-to-decimal-in-C-programming
int convert()
{

    long int binaryNumber,decimalNumber=0,j=1,remainder;
    
    printf("Enter a binary number of your choice: ");
    scanf("%ld",&binaryNumber);
    
    while(binaryNumber!=0){
    
        remainder=binaryNumber%10;
        decimalNumber=decimalNumber+remainder*j;
        j=j*2;
        binaryNumber=binaryNumber/10;
    }
    
    printf("Equivalent decimal value: %ld \n",decimalNumber);
    
    return 0;
}

/*
int menu()
{
		int n;
		printf("Welcome to the menu!, please use on of the options below \n");
		printf("1: Rule 30 Automatom \n");
		printf("2: Custom size rule 30 Automatom \n");
		printf("3: Convert a binary number to a decimal number \n");
		printf("4: Exit");
		scanf("%d", &n);
		switch (n)
	​	{
			case 1:
				auto30();
			break;
	    	case 2:
				custom30();
			break;
			case 3:
				convert();
			break;
			case 4:
				printf("Exiting");
			break;
	    	default:
			printf("This isn't a valid option, please try again");
		}
}
*/
int main()
{
    custom30();
	return 1;
}
