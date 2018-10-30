#include <stdio.h>
#include <stdlib.h>




void checkValues()
{
	int parent[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int child[30];

    	for(int i = 0; i < 30; i++)
    	{
    	    printf("%d",parent[i]);
    	}
    	printf("\n");
	
	for(int i = 0; i<14; i++)
	{	    
		for(int i = 0; i < 30; i++)
		{
			int left = parent[i-1];
			int middle = parent[i];
			int right = parent[i+1];
			int newstate = rules(left,middle,right);
			child[i] = newstate;
		}
		    
		for(int i = 0; i < 30; i++)
		{
			printf("%d",child[i]);
		}
		printf("\n"); 
		for(int i = 0; i<30; i++)
		{
			parent[i] = child[i];
		}
			  
	}
	
	
}
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
		else if (left == 1 && middle == 1 && right == 1)
		{
		    return 0;
		}
}
int main ()
{
    checkValues();
}
