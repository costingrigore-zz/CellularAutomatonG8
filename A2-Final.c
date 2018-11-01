#include <stdio.h>
#include <stdlib.h>
/*
	This project is by Ross Maider, Costin Grigore and Ryan Crampton
	This is group 8
*/

/*
	We based this method on this reference: https://www.sanfoundry.com/c-program-binary-number-into-decimal/
	This method asks the user for an input and converts it for the users
*/
int convert()
{	
	int num;
	int x = 0;
	//This asks the user for the input
	printf("Please enter the binary code (Maximum of 8) \n");
	scanf("%d", &x);
	num =  x;	
	int decimal_val = 0, base = 1, rem;
 	int original = num;
	
	//This is the conversion method 
	while (num > 0)
	{
		rem = num % 10;
		decimal_val = decimal_val + rem * base;
		num = num / 10 ;
		base = base * 2;
	}
	
	//This displays the user input and then shows the decimal value
	printf("The Binary number is = %d \n", original);
	printf("Its decimal equivalent is = %d \n", decimal_val);
	original=0;
	return 0;
}

/*
	This is the method that creates the rules, this method is inspired by https://natureofcode.com/book/chapter-7-cellular-automata/
	This method creates the rules from the list the user has created, this is used in the customRule method
*/
int rules(int left, int middle, int right, int ruleArray[])
{
	int rule;
    	//This method goes through each possible situation, and inputs the value to the child as needed
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
/*
	This method allows the user to create a method of their own rule, this allows any input up to 256
*/
void customRule()
{
	//This sets up the boundaries before implimenting them
	int height;
	int length = 0;
	int rule;

	//This asks the user for all the infomation it needs to start and create the automaton
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

	//This automatically creates the parent
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

	//Print the parent
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
	
	//This creates the nodes for the user, it takes each node and its neighbors, and gives it to the rules method
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
		//Print the child to console    
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
		
		//Set the new parent as the child
		for(int i = 0; i<length; i++)
		{
			parent[i] = child[i];
		}
		  
	}
	fclose(f);
}

/*
	This method allows the user to create a method of rule 30
*/
void custom30()
{
	//This sets up the info for the system
	int height;
	int length;
	
	//This asks the user for all the infomation it needs to start and create the automaton
	printf("Please select a width across the page: \n");
	scanf("%d", &length);
	printf("Please select the depth down the page: \n");
	scanf("%d", &height);
    
	int parent[length];
	int child[length];
    	//This sets up the parent for the user
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

	//This prints the parent to the command line
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

	//Because this is done for rule 30, the user doesnt get the choice here, it is done for them and fed in
	int ruleMade[8] = {0,0,0,1,1,1,1,0};

	//This creates the nodes for the user, it takes each node and its neighbors, and gives it to the rules method
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
		//Prints the child for the user to command line	
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
		
		//Set the new parent as the child	
		for(int i = 0; i<length; i++)
		{
			parent[i] = child[i];
		}
	}   
	fclose(f);
}
/*
	This is the method that has the menu, it allows access to all other methods
*/
int menu()
{
	int n;
	//This is the method that runs until the user exits the programme, this also allows the users to step through each method until quitting
	do
	{
		//This repeates each time the user enters
		printf("Welcome to the menu!, please use on of the options below \n");
		printf("1: Rule 30 Automatom \n");
		printf("2: Custom rule automatom (up to 128)\n");
		printf("3: Convert from Binary to decimal\n");
		printf("4: Exit\n");
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
			//This is the option that appears if another input is entered
			default:
			printf("This isn't a valid option, please try again");
			break;
		}
	}
	while(n!=4);
	return 0;
}
/*
	This is the main method, this is what runs the programme
*/
int main ()
{
	menu();
	return 0;
}
