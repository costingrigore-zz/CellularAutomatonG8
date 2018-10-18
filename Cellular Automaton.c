

typedef struct row
{
	int array[10];
} Row;

int parent[10] = {0,0,0,0,1,0,0,0};
int child[1];

int checkValues(int row){
	if (parent[0]==0)
	{
		child[0]=0;
	}

}

int main ()
{

 checkValues(parent);
 printf("%d\n",child[0]);
}
