#include <stdio.h>
#include <stdlib.h>

int parent[30] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

int child[30];


void checkValues(int *parent, int *child)
{
    
    for(int i = 0; i < 30; i++)
    {
        printf("%d",parent[i]);
    }
    printf("\n");
    
    for(int i = 0; i < 30; i++)
    {
        int left = parent[i-1];
        int middle = parent[i];
        int right = parent[i+1];
        
        if( left == 0 && middle == 0 && right == 0)
        {
            child[i] = 0;
        }
        else if (left == 0 && middle == 0 && right == 1)
        {
            child[i] = 1;
        }
        else if (left == 0 && middle == 1 && right == 0)
        {
            child[i] = 1;
            
        }
        else if (left == 0 && middle == 1 && right == 1)
        {
            child[i] = 1;
        }
        else if (left == 1 && middle == 0 && right == 0)
        {
            child[i] = 1;
        }
        else if (left == 1 && middle == 0 && right == 1)
        {
            child[i] = 0;
            
        }
        else if (left == 1 && middle == 1 && right == 0)
        {
            child[i] = 0;
        }
        else if (left == 1 && middle == 1 && right == 1)
        {
            child[i] = 0;
        }
    }
    
    for(int i = 0; i < 30; i++)
    {
        printf("%d",child[i]);
    }
    printf("\n");

    parent = child;
    
    int newChild [30];
    
    child = newChild;
    
}

int main ()
{
    checkValues(parent, child);
}
