
#include <stdio.h>

int parent[10] = {0,1,0,0,1,0,0,0};
int child[1];

int checkValues(int row){
	int node1;
	int node2;
	int node3;
	for (int i = 0, i < 10, i = i++)
	{

		node1=parent[i-1];
		node2=parent[i];
		node3=parent[i+1];
		if (node2==parent[0]){
			if (node2==0 && node3==0)
			{
				child[i]=0;
			}
			else if (node2==0 && node3==1)
			{
				child[i]=1;
			}
		}
		if(node2=!parent[0])
		{
			if (node1==1 && node2==1 && node3==1){
				child[i]=0;
			}
		}

	}

}

int main ()
{

 checkValues(parent);
 printf("%d\n",child[0]);
 printf("%d\n",child[1]);
}
