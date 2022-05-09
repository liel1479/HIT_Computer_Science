// Course: Advanced C programming
// exercise 2, question 1
// file name: ex2_q1.c

// --------------------------- //
// DO NOT CHANGE anything in the following macro:
#ifdef FUNC_DECLARE
#include "ex2_q1.h"
#else
// --------------------------------------- //
// Include and definition package section:
// --------------------------------------- //
#define FUNC_DECLARE
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define scanf_s scanf
#define ROWS 4
#define COLS 4
// --------------------------------------- //
// Types declration section:
// --------------------------------------- //
typedef struct fraction
{
	int num, numerator, denominator;
} fraction;
// --------------------------------------- //
// Functions declration section:
// --------------------------------------- //
unsigned long student_id();
fraction ** createMatrix(int rows, int cols);
fraction ** matrixAverageNeighbor(int A[][COLS], int rows, int cols);
fraction neighborFractionAverage(int A[][COLS], int i, int j, int rows, int cols);
void printMatrix(fraction** B, int rows, int cols);
void freeMatrix(fraction** B, int rows);
int findGCD(int numerator);
/** DECLARE HERE ONE FUNCTION ACCORDING TO YOUR NEEDS **/
// --------------------------------------- //
// Main section:
// --------------------------------------- //
int main()
{
	unsigned long id_num;
	fraction** B;
	int A[ROWS][COLS] = {
		{5, 12, 6, 8},
		{4, 7, 0, 9},
		{13, 20, 8, 2},
		{18, 0, 2, 6}
	};
	
	// call functions:
	id_num = student_id();
	printf("[id: %lu] start main\n", id_num);

	B = matrixAverageNeighbor(A, ROWS, COLS);

	// write output:
	printf("Output:\n");
	//printMatrix(B, ROWS, COLS);

	// free matrix:
	//freeMatrix(B, ROWS);

	return 0;
}
#endif
// --------------------------- //


// --------------------------- //
// function implementation section:
unsigned long student_id()
{
	// return your id number,
	// for example if your id is 595207432
	// return 595207432;
	// your code:
    return 326856432;
}
// --------------------------- //


/// <summary>
/// This code required one extra important function.
/// Think hard about what it should be.
/// </summary>
/// <params>int numerator - numerator of the number</params>
/// <returns>GCD of two int numbers</returns>
// your code:
int findGCD(int numerator)
{
    for (int i = numerator; i >= 1; i--)
        if (numerator % i == 0 && 100 % i == 0) return i;
    return 0;
}
// --------------------------- //

/// <summary>
/// This function allocate a dynamic matrix from type fraction.
/// </summary>
/// <param>int rows - the number of rows in the matrix</param>
/// <param>int cols - the number of colums in the matrix</param>
/// <returns>allocated empty matrix B from type fraction</returns>
fraction** createMatrix(int rows, int cols)
{
	// your code:
    fraction** B;
    return B;
}
// --------------------------- //

/// <summary>
/// The function receives a static matrix 
/// and for each cell in the matrix calculates 
/// the average of its neighbors.  
/// </summary>
/// <param>int A[][COLS] - the static matrix</param>
/// <param>int rows - the number of rows in the matrix</param>
/// <param>int cols - the number of colums in the matrix</param>
/// <returns>matrix B from type fraction</returns>
fraction** matrixAverageNeighbor(int A[][COLS], int rows, int cols)
{
	// your code:
    fraction ** B = malloc(rows * cols * sizeof(fraction));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            B[i][j] = neighborFractionAverage(A, i, j, rows, cols);
    return B;
}
// --------------------------- //

/// <summary>
/// The function receives a static matrix, and a cell value,
/// and calculates the average of its neighbors.  
/// </summary>
/// <param>int A[][COLS] - the static matrix</param>
/// <param>int i - the cell row number in matrix</param>
/// <param>int j - the cell colum number in the matrix</param>
/// <param>int rows - the number of rows in the matrix</param>
/// <param>int cols - the number of colums in the matrix</param>
/// <returns>value from type fraction</returns>
fraction neighborFractionAverage(int A[][COLS], int i, int j, int rows, int cols)
{
	// your code:
    fraction val;
    double sum = 0.0;
    int count = 0;
    if (i - 1 > 0)
    {
        if (j - 1 > 0)
        {
            sum += (double)A[i-1][j-1];
            count++;
        }
        if (j + 1 < cols)
        {
            sum += (double)A[i-1][j+1];
            count++;
        }
        sum += (double)A[i-1][j];
        count++;
    }
    if (i + 1 < rows)
    {
        if (j - 1 > 0)
        {
            sum += (double)A[i+1][j-1];
            count++;
        }
        if (j + 1 < cols)
        {
            sum += (double)A[i+1][j+1];
            count++;
        }
        sum += (double)A[i+1][j];
        count++;
    }
    if (j - 1 > 0)
    {
        sum += (double)A[i][j-1];
        count++;
    }
    if (j + 1 < cols)
    {
        sum += (double)A[i][j+1];
        count++;
    }
    sum = sum / count;
    int fraction = (sum - (int)sum) * 10;
    int gcd = findGCD(fraction);
    val.num = (int)sum;
    val.numerator = fraction / gcd;
    val.denominator = 10 / gcd;
    return val;
}
// --------------------------- //


/// <summary>
/// The function receives a dynamic matrix from type fraction,
/// and print the matrix as double varibles.  
/// </summary>
/// <param>fraction** B - the dynamic matrix</param>
/// <param>int rows - the number of rows in the matrix</param>
/// <param>int cols - the number of colums in the matrix</param>
/// <returns>None</returns>
void printMatrix(fraction** B, int rows, int cols)
{
	// your code:
}
// --------------------------- //


/// <summary>
/// The function receives a dynamic matrix from type fraction,
/// and free all allocated memory.  
/// </summary>
/// <param>fraction** B - the dynamic matrix</param>
/// <param>int rows - the number of rows in the matrix</param>
/// <returns>None</returns>
void freeMatrix(fraction** B, int rows)
{
	// your code:
}
// --------------------------- //
