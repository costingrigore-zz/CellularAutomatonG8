#include <stdio.h>
#include <stdlib.h>

/*
int decimalConvert(int n) 
{ 
   	// array to store binary number 
   	int a[8]; 
  	int passOnArray[8];
   	// counter for binary array 
    	int i = 0;     
    	for(i=0;n>0;i++)    
    	{    
    		a[i]=n%2;    
    		n=n/2;    
    	} 
	int y = 7 - i ;
	i = 0;  
  	for(int x = 0; x < 8; x++)
	{
		if(y == 0)
		{
			passOnArray[x] = a[i];
			i++;	
		}
		else
		{
			passOnArray[x] = 0;
			y--;
		}
	}
	return passOnArray[8];	
} 
*/
int rules(int left, int middle, int right, int ruleArray[])
{
	 if( left == 0 && middle == 0 && right == 0)
	        {
	            return ruleArray[0];
	        }
		else if (left == 0 && middle == 0 && right == 1)
		{
		    return ruleArray[1];
		}
		else if (left == 0 && middle == 1 && right == 0)
		{
		    return ruleArray[2];
		    
		}
		else if (left == 0 && middle == 1 && right == 1)
		{
		    return ruleArray[3];
		}
		else if (left == 1 && middle == 0 && right == 0)
		{
		    return ruleArray[4];
		}
		else if (left == 1 && middle == 0 && right == 1)
		{
		    return ruleArray[5];
		    
		}
		else if (left == 1 && middle == 1 && right == 0)
		{
		    return ruleArray[6];
		}
		else
		{
		    return ruleArray[7];
		}
}
/*
void customRule()
{
	int height;
	int length = 0;
	int rule;
	int parent[length];
	int child[length];
	int *ruleMade;
	printf("Please select the rule you wish to create: \n");
	scanf("%d", &rule);
	printf("Please select a width across the page: \n");
	scanf("%d", &length);
	printf("Please select the depth down the page: \n");
	scanf("%d", &height);
	ruleMade = decimalConvert(rule);	
	int rulesMade[8] = {0,0,1,0,0,0,1,1};
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
			int newstate = rules(left,middle,right,rulesMade);
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
*/
void custom30()
{
	int height;
	int length = 0;
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
	int ruleMade[8] = {0,0,0,1,1,1,1,0};
	for(int i = 0; i<height; i++)
	{	    
		for(int i = 0; i < length; i++)
		{
			int left = parent[i-1];
			int middle = parent[i];
			int right = parent[i+1];
			int newstate = rules(left,middle,right,ruleMade);
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

/*
int menu()
{
		int n;
		printf("Welcome to the menu!, please use on of the options below \n");
		printf("1: Rule 30 Automatom \n");
		printf("2: Custom size rule 30 Automatom \n");
		printf("2: Exit");
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
			printf("Exiting");
			break;
	    		default:
			printf("This isn't a valid option, please try again");
		}
}
*/
int main ()
{
    custom30();
	return 1;
}
