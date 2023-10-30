//BY DROOD OP
#include <stdio.h>

struct matrix
{
    int row;
    int col;
    int value;
} mat1[100], mat2[100], res[100], trans[100];

void input(int mat[10][10], int r, int c)
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

int conversion(int mat[10][10], int r, int c, struct matrix arr[])
{
    int k = 1;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (mat[i][j] != 0)
            {
                arr[k].row = i;
                arr[k].col = j;
                arr[k].value = mat[i][j];
                k++;
            }
            else
                continue;
        }
    }
    arr[0].row = r;
    arr[0].col = c;
    arr[0].value = (k - 1);
    return k;
}

void display(struct matrix arr[], int n)
{ 
    for (int i = 0; i < n; i++)
    { if(arr[i].value!=0)
       { printf("< %d, %d, %d >\n", arr[i].row, arr[i].col, arr[i].value);
    }
    }
    printf("\n");
}

int add(struct matrix mat1[], struct matrix mat2[], struct matrix result[], int l, int m) {
    int i = 1, j = 1, k = 1;

    if (mat1[0].row == mat2[0].row && mat1[0].col == mat2[0].col) {
        result[0].row = mat1[0].row;
        result[0].col = mat1[0].col;

        while (i <= l && j <= m) {
            if (mat1[i].row < mat2[j].row) {
                result[k].col = mat1[i].col;
                result[k].row = mat1[i].row;
                result[k].value = mat1[i].value;
                k++;
                i++;
            } else if (mat1[i].row > mat2[j].row) {
                result[k].col = mat2[j].col;
                result[k].row = mat2[j].row;
                result[k].value = mat2[j].value;
                k++;
                j++;
            } else if (mat1[i].col < mat2[j].col) {
                result[k].col = mat1[i].col;
                result[k].row = mat1[i].row;
                result[k].value = mat1[i].value;
                k++;
                i++;
            } else if (mat1[i].col > mat2[j].col) {
                result[k].col = mat2[j].col;
                result[k].row = mat2[j].row;
                result[k].value = mat2[j].value;
                k++;
                j++;
            } else {
                int sum = mat1[i].value + mat2[j].value;
                result[k].col = mat1[i].col;
                result[k].row = mat1[i].row;
                result[k].value = sum;
                k++;
                i++;
                j++;
            }
        }

        while (i <= l) {
            result[k].col = mat1[i].col;
            result[k].row = mat1[i].row;
            result[k].value = mat1[i].value;
            k++;
            i++;
        }

        while (j <= m) {
            result[k].col = mat2[j].col;
            result[k].row = mat2[j].row;
            result[k].value = mat2[j].value;
            k++;
            j++;
        }

        result[0].value = k - 1;
    } else {
        printf("Addition not possible\n");
    }

    return k;
}

void transpose(struct matrix mat[], struct matrix trans[], int n)
{
    int temp;
    trans[0].col = mat[0].row;
    trans[0].row = mat[0].col;
    trans[0].value = mat[0].value;
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < n - i; j++)
        {
            if (mat[i].col > mat[i + 1].col)
            {
                temp = mat[i + 1].col;
                mat[i + 1].col = mat[i].col;
                mat[i].col = temp;

                temp = mat[i + 1].row;
                mat[i + 1].row = mat[i].row;
                mat[i].row = temp;

                temp = mat[i + 1].value;
                mat[i + 1].value = mat[i].value;
                mat[i].value = temp;
            }
        }
    }

    for (int i = 1; i < n; i++)
    {
        trans[i].row = mat[i].col;
        trans[i].col = mat[i].row;
        trans[i].value = mat[i].value;
    }
}

int main()
{
    int r1, c1, r2, c2, v, choice;
    int matA[10][10];
    int matB[10][10];

    printf("Enter the number of rows and columns in the first matrix\n");
    scanf("%d %d", &r1, &c1);
    printf("Enter the matrix\n");
    input(matA, r1, c1);

    printf("Enter the number of rows and columns in the second matrix\n");
    scanf("%d %d", &r2, &c2);
    printf("Enter the matrix\n");
    input(matB, r2, c2);

    printf("First matrix\n");
    int k = conversion(matA, r1, c1, mat1);
    display(mat1, k);

    printf("Second matrix\n");
    int d = conversion(matB, r2, c2, mat2);
    display(mat2, d);

    printf("The transpose matrix are\nmatrix 1\n");
    transpose(mat1, trans, k);
    display(trans, k);

    printf("matrix 2\n");
    transpose(mat2, trans, d);
    display(trans, d);

    printf("The sum matrix is\n");
   
    v = add(mat1, mat2, res, k, d);
  res[0].value=mat1[0].value+mat2[0].value;
    display(res, v);

    return 0;
}

