int diagonalSum(int** mat, int matSize, int* matColSize){
    int sum = 0;
    for (int i = 0; i < matSize; i++) {
        sum += mat[i][i];
        sum += mat[i][matSize - i - 1];
        if (matSize % 2 == 1 && i == matSize / 2) { 
            sum -= mat[i][i];
        }
    }
    return sum;
}