#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
void parr(int **arr);
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** updateMatrix(int** matrix, int matrixRowSize, int matrixColSize, int** columnSizes, int* returnSize) {
    int **rlt;
    *returnSize = matrixRowSize;
    *columnSizes = malloc(matrixRowSize * sizeof(int));
    rlt = malloc(matrixRowSize * sizeof(int*));

    // init columnSize arr and copy 0 into rlt
    for(int i=0;i<matrixRowSize; i++){
        (*columnSizes)[i] = matrixColSize;
        rlt[i] = malloc(matrixColSize * sizeof(int));
        for(int j=0; j<matrixColSize; j++){
            if(matrix[i][j] == 0){
                rlt[i][j] = 0;
            }else if(matrix[i][j] == 1){
                rlt[i][j] = INT_MAX;
            }
        }
    }

    for(int i=0; i<matrixRowSize; i++){
        for(int j=0; j< matrixColSize; j++){
            int in = i - 1;
            int jn = j - 1;
            int inbj = (jn > -1 && jn < matrixColSize); // in_bounce?
            int inbi = (in > -1 && in < matrixRowSize);
            int l = (inbj)? rlt[i][jn]:INT_MAX; // need to plus 1, but will overflow
            int t = (inbi)? rlt[in][j]: INT_MAX;
            int o = rlt[i][j] - 1;
            // find min between l,t
            int ltmin = (l < t)? l : t;
            if(ltmin < o){
                rlt[i][j] = ltmin + 1;
            }
        }
    }

    for(int i=matrixRowSize-1; i>-1; i--){
        for(int j=matrixColSize-1;j>-1; j--){
            int in = i + 1;
            int jn = j + 1;
            int inbj = (jn > -1 && jn < matrixColSize); // in_bounce?
            int inbi = (in > -1 && in < matrixRowSize);
            int r = (inbj)? rlt[i][jn]: INT_MAX; // need to plus 1, but will overflow
            int b = (inbi)? rlt[in][j]: INT_MAX;
            int o = rlt[i][j] - 1;
            // find min between l,t
            int rbmin = (r < b)? r : b;
            if(rbmin < o){
                rlt[i][j] = rbmin + 1;
            }

        }
    }
return rlt;
}


int main(){
    int ex2[][3] = {
        {0,0,0},
        {0,1,0},
        {1,1,1}
    };
   /*
    //printf("%d", ex2[0] == *(ex2));
    //printf("x:%d\n", arr[2][2]);
    printf("eq:%d\n", *ex2 == &ex2[0]);
    printf("1:%d\n", &(ex2[1][2]));
    printf("w:%d\n", (int) ex2 + (5 * sizeof(int)));
    printf("w:%d\n", **ex2);
    printf("1:%d\n", *(*ex2 + 1) + 2);
    printf("2:%d\n", &(ele[1][2]));
    printf("2:%d\n", *(*ele + 1) + 2);
    printf("eq1:%d\n", ele == ex2);
    printf("ele_addr:%d\n", ele);
    printf("ex2_addr:%d\n", ex2);
    printf("ele+2:%d\n",  (ele + 2));
    printf("ex2+2:%d\n",  (ex2 + 2));
    printf("x:%d\n", &(ex2[0]));
    printf("22p:%d\n", *( *(ex2 + 2) + 2 ));
    printf("22i:%d\n", ex2[2][2]);
    printf("22ep:%d\n", *( *(ele + 2) + 2 ));
    printf("22ei:%d\n", ele[2][2]);
*/
    //printf("s:%d\n", (int)ele + (2*3*sizeof(int)));
    // printf("s:%d\n", ele[8]);
    // printf("s:%d\n", *(ex2[2]+2) );
    int **mtx;
    mtx = malloc(3 * sizeof(int *));
    for(int i=0; i<3; i++){
        mtx[i] = malloc(3 * sizeof(int));
        for(int j=0; j < 3; j++){
            mtx[i][j] = ex2[i][j];
        }
    }
    int ** colsize;
    int * retsize;
    int ** rlt = updateMatrix(mtx, 3, 3, colsize, retsize);
    return 0;
}
void parr(int **arr){
    for(int i=0; i<3; i++){
        for(int j=0; j < 3; j++){
           printf("%d,", arr[i][j]);
        }
       printf("\n");
    }
}
