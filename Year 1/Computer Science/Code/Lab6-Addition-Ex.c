#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

EX 1
void Ex1();
void InputArray(int*, int);
void PrintArray(int*, int);
//---------------------------
// EX 2
void Ex2();
void InputArray(int*, int);
void PrintArray(int*, int);
//---------------------------
void Ex1()
{
	int arr[SIZE];
	InputArray(arr, SIZE);
}
void InputArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enter %d's values:", i);
		scanf("%d", &arr[i]);
	}
	PrintArray(arr, n);
}
void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d", arr[i]);
}
void Ex2()
{
	int arr[SIZE];
	InputArray(arr, SIZE);
}
int main()
{
	Ex1();
	Ex2();
}
