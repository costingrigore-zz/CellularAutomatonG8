#include <stdio.h>
#include <stdlib.h>


int rules(int left, int middle, int right, int ruleArray)
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
int main ()
{
    custom30();
	return 1;
}
