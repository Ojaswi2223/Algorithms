#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) 
{
	int c = *a;
	*a = *b;
	*b = c;
}

void bubblesort(int *arr, int n) 
{
	int i, j;
	int flag=0;
	int opcount=0;
	for (i = 0; i < n-1; ++i) 
	{
		for (j = 0; j < n - 1 - i; ++j) 
		{
			opcount++;
			if (*(arr + j) > *(arr + j + 1))
			{
				flag++;
				swap(arr + j, arr + j + 1);
			}
		}
		if(flag==0)
		break;
	}
	printf("Basic operation count = %d\n",opcount );
}
	

int main()
{
	int n,i;
	int a[50];
	printf("Enter the number of elements in the array :\n ");
	scanf("%d",&n);
	printf("Enter the elements of the array : \n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	bubblesort(a,n);
	printf("The elements in the sorted array : \n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",a[i]);
	}
	return 0;
}
