#include <stdio.h>
#include <stdlib.h>

int convert( int[] num)
{

    int decimal_val = 0, base = 1, rem;

 	int original = num;

    while (num > 0)

    {

        rem = num % 10;

        decimal_val = decimal_val + rem * base;

        num = num / 10 ;

        base = base * 2;

    }

    printf("The Binary number is = %d \n", original);

    printf("Its decimal equivalent is = %d \n", decimal_val);

    original=0;
}

int rules(int left, int middle, int right, int ruleArray[])
{
    int rule;
    
    if( left == 0 && middle == 0 && right == 0)
    {
        rule = ruleArray[0];
        return rule;
    }
    else if (left == 0 && middle == 0 && right == 1)
    {
        rule = ruleArray[1];
        return rule;
    }
    else if (left == 0 && middle == 1 && right == 0)
    {
        rule = ruleArray[2];
        return rule;
    }
    else if (left == 0 && middle == 1 && right == 1)
    {
        rule = ruleArray[3];
        return rule;
    }
    else if (left == 1 && middle == 0 && right == 0)
    {
        rule = ruleArray[4];
        return rule;
    }
    else if (left == 1 && middle == 0 && right == 1)
    {
        rule = ruleArray[5];
        return rule;
    }
    else if (left == 1 && middle == 1 && right == 0)
    {
        rule = ruleArray[6];
        return rule;
    }
    else
    {
        rule = ruleArray[7];
        return rule;
    }
}

void customRule()
{
	int height;
	int length = 0;
	int rule;

	printf("Please select the rule you wish to create: \n");
	scanf("%d", &rule);
	printf("Please select a width across the page: \n");
	scanf("%d", &length);
	printf("Please select the depth down the page: \n");
	scanf("%d", &height);
//I based this method on this reference: https://www.sanfoundry.com/c-program-binary-number-into-decimal/
//This has been adapted to suit our needs
	int c;
	int k;
	int array[8]; 
   	for (c = 0; c <= 8; c++)
	{
		k = rule >> c;
		
		if (k & 1)
		{
			array[c] = 1;
		}
		else
		{
			array[c] = 0;
		}
	}
//End of reference
	int parent[length];
	int child[length];
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
	//Pointer for opening the file
    FILE *f = fopen("output.txt", "a");
    
    //Check it has opended
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    //Print the parent line
    for(int i = 0; i < length; i++)
    {
        fprintf(f, "%d", parent[i]);
    }
    
fprintf(f, "\n");
	for(int i = 0; i<height; i++)
	{	    
		for(int i = 0; i < length; i++)
		{
			int left = parent[i-1];
			int middle = parent[i];
			int right = parent[i+1];
			int newstate = rules(left,middle,right,array);
			child[i] = newstate;
		}
		    
		for(int i = 0; i < length; i++)
		{
			printf("%d",child[i]);
		}
		printf("\n"); 
		//Print the child
        for(int i = 0; i < length; i++)
        {
            fprintf(f, "%d", child[i]);
        }
        
	fprintf(f, "\n");
		for(int i = 0; i<length; i++)
		{
			parent[i] = child[i];
		}
			  
	}
	fclose(f);
}

void custom30()
{
    int height;
    int length;

    printf("Please select a width across the page: \n");
    scanf("%d", &length);
    printf("Please select the depth down the page: \n");
    scanf("%d", &height);
    
    int parent[length];
    int child[length];
    
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
//Pointer for opening the file
    FILE *f = fopen("output.txt", "a");
    
    //Check it has opended
    if (f == NULL)
    {
        printf("Error opening file!\n");
        exit(1);
    }
    
    //Print the parent line
    for(int i = 0; i < length; i++)
    {
        fprintf(f, "%d", parent[i]);
    }
    
fprintf(f, "\n");
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
	//Print the child
        for(int i = 0; i < length; i++)
        {
            fprintf(f, "%d", child[i]);
        }
        
	fprintf(f, "\n");
	
        for(int i = 0; i<length; i++)
        {
            parent[i] = child[i];
        }
        
    }
    fclose(f);
}

int menu()
{
	int n;
	do
	{
		printf("Welcome to the menu!, please use on of the options below \n");
		printf("1: Rule 30 Automatom \n");
		printf("2: Custom rule automatom (up to 128)\n");
		printf("3: Convert from Binary to decimal\n");
		printf("4: Exit")
		scanf("%d", &n);
					
		switch (n)
		{
			case 1:
			custom30();
			break;
			case 2:
			customRule();
			break;
			case 3:
			convert();
			break;
			case 4:
			printf("Exiting");
			break;
			default:
			printf("This isn't a valid option, please try again");
			break;
		}
	}
	while(n!=4);
}

int main ()
{
	menu();
	return 0;
}
