#include <stdio.h>
#include<string.h>
#include <ctype.h>
#include <stdlib.h>
struct matrix
{
    float** mat;
    int rows;
    int col;
};

struct matrix alloc(int nrows, int ncol) //a struct to create a matrix and allocate space for it
{
    struct matrix m;
    m.mat = malloc(nrows * sizeof(float *));
    if (m.mat == NULL) 
    {
        printf("Out of memory\n");
	exit(1);
    }
    for(int i = 0; i < nrows; i++)
    {
        *(m.mat+i) = malloc(ncol * sizeof(float));
	if(m.mat == NULL) 
	{
	    printf("Out of memory\n");
	    exit(1);
	}
    }
    m.rows = nrows;
    m.col = ncol;
    return m;
}


int main()
{
    char x;
    int nrows,ncol;
    printf("Enter the dimensions of the first matrix: ");
    scanf("%d%c%d",&nrows,&x,&ncol);
    struct matrix matrix1 = alloc(nrows,ncol);
    printf("Enter the dimensions of the second matrix: ");
    scanf("%d%c%d",&nrows,&x,&ncol);
    struct matrix matrix2 = alloc(nrows,ncol);
    printf("Enter the elements of matrix (1): ");
    float userval;
    for (int i = 0; i < matrix1.rows; i++) 
    {
        for (int j = 0; j < matrix1.col; j++) {
             scanf("%f",&userval);
            *(*(matrix1.mat+i)+j) = userval;
        }
    }
    printf("Enter the elements of matrix (2): ");
    for (int i= 0; i < matrix2.rows; i++) 
    {
        for (int j = 0; j < matrix2.col; j++) {
            scanf("%f", &userval);
            *(*(matrix2.mat+i)+j) = userval;
        }
    }

    printf("\nMatrix 1:\n");
    printf("Rows: %d\n",matrix1.rows);
    printf("Col: %d\n",matrix1.col);
    for (int i = 0; i < matrix1.rows; i++) 
    {
        printf("\n");
        for(int j = 0; j < matrix1.col; j++) 
            
            printf("%.2f ",*(*(matrix1.mat+i)+j));
    }
    printf("\n");
    printf("\nMatrix 2:\n");
    printf("Rows: %d\n",matrix2.rows);
    printf("Col: %d\n",matrix2.col);
    for (int i = 0; i < matrix2.rows; i++) 
    {
        printf("\n");
        for(int j = 0; j < matrix2.col; j++) 
            
            printf("%.2f ",*(*(matrix2.mat+i)+j));
    }
    printf("\n");

    //condition for matrix multiplication
    if (matrix1.col != matrix2.rows) 
    {
        printf("Error unable to create matrix, first matrix's column does not equal second matrix's row\n");
        exit(1);
    }
    //creating the multiplication matrix
    struct matrix matrix3 = alloc(matrix1.rows,matrix2.col);
    for (int i= 0; i < matrix1.rows; i++) 
    {
        for (int j = 0; j < matrix2.col; j++) 
        {
            matrix3.mat[i][j] = 0;
            for(int h = 0; h < matrix1.col; h++) 
	    {
                matrix3.mat[i][j] += matrix1.mat[i][h] * matrix2.mat[h][j];
            }
        }
    }
    //dispaying the new matrix 
    printf("\nMuliplication Matrix:\n");
    printf("Rows: %d\n",matrix3.rows);
    printf("Col: %d\n",matrix3.col);
    for (int i = 0; i < matrix1.rows; i++) 
    {
        printf("\n");
        for(int j = 0; j < matrix2.col; j++) 
            
            printf("%.2f ",matrix3.mat[i][j]);
    }
    printf("\n");
    
    //freeing up allocated memory
    for (int i = 0; i < matrix1.rows; i++)
        free(matrix1.mat[i]);
    free(matrix1.mat);
    for (int i = 0; i < matrix2.rows; i++)
         free(matrix2.mat[i]);
    free(matrix2.mat);
    for (int i = 0; i < matrix3.rows; i++)
         free(matrix3.mat[i]);
    free(matrix3.mat);

    return 0;
}
