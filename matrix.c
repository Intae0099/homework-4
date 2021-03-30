#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Method Declaration */
int** create_matrix(int row, int col);
void print_matrix(int** matrix, int row, int col);
int free_matrix(int** matrix, int row, int col);
int fill_data(int** matrix, int row, int col);
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col);
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col);
int transpose_matrix(int** matrix, int** matrix_t, int row, int col);
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col);

int main()
{

    char command;
    printf("[----- [김태인]  [2018038033] -----]\n");

    int row, col;
    srand(time(NULL));

    printf("Input row and col : ");
    scanf("%d %d", &row, &col);
    int** matrix_a = create_matrix(row, col);
    int** matrix_b = create_matrix(row, col);
    int** matrix_a_t = create_matrix(col, row);

    printf("Matrix Created.\n");

    if (matrix_a == NULL || matrix_b == NULL) {return -1;}

    do{
        printf("----------------------------------------------------------------\n");
        printf("                     Matrix Manipulation                        \n");
        printf("----------------------------------------------------------------\n");
        printf(" Initialize Matrix   = z           Print Matrix        = p \n");
        printf(" Add Matrix          = a           Subtract Matrix     = s \n");
        printf(" Transpose matrix_a  = t           Multiply Matrix     = m \n");
        printf(" Quit                = q \n");
        printf("----------------------------------------------------------------\n");

        printf("Command = ");
        scanf(" %c", &command);

        switch(command) {
        case 'z': case 'Z':
            printf("Matrix Initialized\n");
            fill_data(matrix_a, row, col);
            fill_data(matrix_b, row, col);
            break;
        case 'p': case 'P':
            printf("Print matrix\n");
            printf("matrix_a\n");
            print_matrix(matrix_a, row, col);
            printf("matrix_b\n");
            print_matrix(matrix_b, row, col);
            break;
        case 'a': case 'A':
            printf("Add two matrices\n");
            addition_matrix(matrix_a, matrix_b, row, col);
            break;
        case 's': case 'S':
            printf("Subtract two matrices \n");
            subtraction_matrix(matrix_a, matrix_b, row, col);
            break;
        case 't': case 'T':
            printf("Transpose matrix_a \n");
            printf("matrix_a\n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            print_matrix(matrix_a_t, col, row);
            break;
        case 'm': case 'M':
            printf("Multiply matrix_a with transposed matrix_a \n");
            transpose_matrix(matrix_a, matrix_a_t, col, row);
            multiply_matrix(matrix_a, matrix_a_t, row, col);
            break;
        case 'q': case 'Q':
            printf("Free all matrices..\n");
            free_matrix(matrix_a_t, col, row);
            free_matrix(matrix_a, row, col);
            free_matrix(matrix_b, row, col);
            break;
        default:
            printf("\n       >>>>>   Concentration!!   <<<<<     \n");
            break;
        }

    }while(command != 'q' && command != 'Q');

    return 1;
}

/* create a 2d array whose size is row x col using malloc() */
int** create_matrix(int row, int col)
{
    int k;
    int **matrix_temp;
    matrix_temp = (int **)malloc(sizeof(int *) * row); //행에 있는 배열들을 동적할당

    for(k = 0 ; k < row ; k++)
    {
        matrix_temp[k] = (int *)malloc(sizeof(int) * col); //각 행의 열들에 있는 것들을 동적할당
    }

    return matrix_temp; //matrix_temp를 리턴함으로서 각 행렬을 저장한다
}

/* print matrix whose size is row x col */
void print_matrix(int** matrix, int row, int col)
{
    int i, j;
    for(i = 0 ; i < row; i++) //행들만큼 반복
    {
        for(j = 0 ; j < col ; j++) //열들만큼 반복
        {
            printf("%d\t", matrix[i][j]); //각각의 배열들을 출력한다.
        }
        printf("\n");
    }
    printf("\n");
}


/* free memory allocated by create_matrix() */
int free_matrix(int** matrix, int row, int col)
{
    int i;
    for(i = 0 ; i < row ; i++) //각 행의 열들에 있는 것들을 동적할당 해제한다
    {
        free(matrix[i]);
    }
    free(matrix); //각 행들의 동적할당을 해제한다
}


/* assign random values to the given matrix */
int fill_data(int** matrix, int row, int col)
{
    int i, j;
    for(i=0; i< row; i++) //행들만큼 반복
    {
        for(j = 0; j<col; j++) //열들만큼 반복
        {
            matrix[i][j] = rand() % 20; //각각의 배열들에 0~19숫자중 랜덤으로 저장한다
        }
    }
    return **matrix; //matrix를 리턴함으로서 각 행렬을 저장한다
}

/* matrix_sum = matrix_a + matrix_b */
int addition_matrix(int** matrix_a, int** matrix_b, int row, int col)
{

    int i, j;

    for(i = 0; i < row ; i++) //행들만큼 반복
    {
        for(j = 0 ; j < col ; j++) //열들만큼 반복
        {
            printf("%d\t", matrix_a[i][j] + matrix_b[i][j]); //matrix_a와 matrix_b의 합을 출력한다.
        }
        printf("\n");
    }
    return 0;
}

/* matrix_sub = matrix_a - matrix_b */
int subtraction_matrix(int** matrix_a, int** matrix_b, int row, int col)
{

    int i, j;

    for(i = 0; i < row ; i++) //행들만큼 반복
    {
        for(j = 0 ; j < col ; j++) //열들만큼 반복
        {
            printf("%d\t",  matrix_a[i][j] - matrix_b[i][j]); //matrix_a와 matrix_b의 차를 출력한다.
        }
        printf("\n");
    }
    return 0;
}

/* transpose the matrix to matrix_t */
int transpose_matrix(int** matrix, int** matrix_t, int row, int col)
{
    int i, j ;
    for(i = 0 ; i < col; i++) //열들만큼 반복
    {
        for(j = 0 ; j < row ; j++) //행들만큼 반복
        {
            matrix_t[j][i] = matrix[i][j]; //matrix_t에 matrix의 전치행렬을 저장한다.
        }
    }
    return 0;
}

/* matrix_axt - matrix_a x matrix_t */
int multiply_matrix(int** matrix_a, int** matrix_t, int row, int col)
{
    int i, j, k;
    int temp[row][row]; //곱셈값을 넣을 임시 배열 선언

    for(i = 0; i < row ; i++) //matrix_a의 행들만큼 반복
    {
        for(j = 0 ; j < row ; j++) //matrix_t의 열들만큼 반복
        {   
            temp[i][j] = 0;
            for(k = 0 ; k < col ; k++)
            {
                temp[i][j] += matrix_a[i][k] * matrix_t[k][i]; //temp에 matrix_a행과 matrix_t의 열의 곱셈을 더한값을 저장
            }
            printf("%d\t", temp[i][j]); //두 행렬의 곱셈값 출력
        }
        printf("\n");
    }
    return 0;
}

