#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//COMMON
void PrintArray(int*, int);
//---------------------------
// EX 1
void Ex1();
int* Lucas(int);
//---------------------------
// EX 2
void Ex2();
int* ArrayChange(int*, int, int, int*);
//---------------------------
// EX 3
void Ex3();
int* Vectors(int*, int*, int);
//---------------------------
// EX 4
void Ex4();
void ArrayMultip(int*, int);
//---------------------------
// EX 5
void Ex5();
int*  MissingVariables(int*, int, int*);
//---------------------------
// EX 6
void Ex6();
int  BigVar(int*, int);
//---------------------------
int main()
{
    //Ex1();
    //Ex2();
    //Ex3();
    //Ex4();
    //Ex5();
    Ex6();
    return 0;
}
void Ex1()
{
    int size = 9;
    int* arr = Lucas(size);
}
int* Lucas(int size)
{
    int* arr = (int*)malloc((size + 1) * sizeof(int));
    for (int i = 0; i <= size; i++)
    {
        if (i == 0) arr[i] = 2;
        else if (i == 1) arr[i] = 1;
        else arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr;
}
void PrintArray(int* arr, int n)
{
    for (int i = 0; i < n; i++) printf("{%d}", arr[i]);
}
void Ex2()
{
    int arr[5] = { 1,8,3,6,11 };
    int isEven = 1;
    int size = 0;
    int* newArr = ArrayChange(arr, 5, isEven, &size);
    PrintArray(newArr, size);
    printf("\nSize - %d", size);
}
int* ArrayChange(int* arr, int n, int isEven, int* size)
{
    int* newArr = (int*)malloc((*size) * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        if (isEven == 1 && arr[i] % 2 == 0)
        {
            newArr[*size] = arr[i];
            *size = *size + 1;
        }
        else if (isEven != 1 && arr[i] % 2 != 0)
        {
            newArr[*size] = arr[i];
            *size = *size + 1;
        }
    }
    return newArr;
}
void Ex3()
{
    int arrA[3] = { 1,2,1 };
    int arrB[3] = { 3,3,3 };
    int* result = Vectors(arrA, arrB, 3);
    PrintArray(result, 3);
}
int* Vectors(int* arrA, int* arrB, int size)
{
    int* result = (int*)malloc(size * sizeof(int));
    result[0] = arrA[1] * arrB[2] - arrA[2] * arrB[1];
    result[1] = arrA[2] * arrB[0] - arrA[0] * arrB[2];
    result[2] = arrA[0] * arrB[1] - arrA[1] * arrB[0];
    return result;
}
void Ex4()
{
    int arr[5] = { 1,2,2,4,1 };
    ArrayMultip(arr, 5);
    PrintArray(arr, 5);
}
void ArrayMultip(int* arr, int size)
{
    int* tmpArr = (int*)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
    {
        tmpArr[i] = 1;
        for (int j = 0; j < size; j++)
        {
            if (i == j) continue;
            tmpArr[i] *= arr[j];
        }
    }
    for (int i = 0; i < size; i++)
        arr[i] = tmpArr[i];
    free(tmpArr);
    tmpArr = NULL;
}
void Ex5()
{
    int arr[6] = { 0,1,1,0,3,5 };
    int size = 0;
    int *newArr = MissingVariables(arr, 6, &size);
    PrintArray(newArr, size);
}
int* MissingVariables(int* arr, int n, int* size)
{
    int* tmp = (int*)calloc(n + 1, sizeof(int));
    int* newArr = (int*)malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) tmp[arr[i]]++;
    for (int i = 0, * size = 0; i < n + 1; i++)
        if (!tmp[i]) newArr[(*size)++] = i;
    newArr = (int*)realloc(newArr, (*size) * sizeof(int));

    free(tmp);
    return newArr;
}
void Ex6()
{
    int arr[6] = { 1,1,1,1,3,5 };
    int result = BigVar(arr, 6);
    printf("Result is: %d", result);
}
int  BigVar(int* arr, int n)
{
    int* newArr = (int*)calloc((n+1), sizeof(int));
    for(int i = 0; i < n; i++)
        newArr[arr[i]]++;
    for (int i = 0; i <=n; i++)
        if (newArr[i] > n/2) return 1;
    return -1;
}