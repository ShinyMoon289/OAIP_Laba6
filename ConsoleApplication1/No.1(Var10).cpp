#include <iostream>
#include<stdio.h>
#include<conio.h>
int main()
{
	int* ukz, n=0;
	do {
		printf("Enter the size of the array <20\n");
		scanf_s("%d", &n);
	} while (n >= 20);
	if (!(ukz = (int*)calloc(n, sizeof(int))))   //Checking memory
	{
		puts("Not enough memory!");                                         
		return 0;
	}
	for (int i = 0; i < n; i++)		//Filling the array
	{
		printf("Enter %d element: \n", i);
		scanf_s("%d", ukz + i);
	}
	printf("The array is:\n");		//Displaying the array
	for (int i = 0; i < n; i++)
	{
		printf("%d ",*(ukz+i));
	}
	printf("\n");
	int min = *ukz, minnum = 0;		//Finding the smallest element
	for (int i = 0; i < n; i++)
	{
		if (*(ukz + i) < min)
		{
			min = *(ukz + i);
			minnum = i;
		}
	}
	printf("The number of the smallest element is %d\n", minnum);
	int sum = 0, n1 = -1, n2 = -1;	//Sum of elements between		
	for (int i = 0; i < n; i++)		//two negatives
	{
		if (*(ukz + i) < 0)
		{
			n1 = i;
			break;
		}
	}
	if (n1 == -1)
	{
		printf("There are no negative numbers.\n");
		return 0;
	}
	if (n1 == n-1)
	{
		printf("The negative number is the last!");
		return 0;
	}
	for (int i = n1+1; i < n; i++)
	{
		if (*(ukz + i) < 0)
		{
			n2 = i;
			break;
		}
	}
	if (n2 == -1)
	{
		printf("There isn't a second negative number.\n");
		return 0;
	}
	else
	{
		for (int i = n1 + 1; i < n2; i++)
		{
			sum = sum + *(ukz + i);
		}
		printf("The sum is %d", sum);
	}
	

    free(ukz);
    return 0;
}
