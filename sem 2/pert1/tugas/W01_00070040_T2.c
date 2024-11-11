#include <stdio.h>
#include<stdlib.h>

void printMatriks(int matrix [][3]){            //function menampilkan matriks
    int baris, col;
    for(baris=0; baris<3; baris++){
        for(col=0; col<3; col++){
            printf("%d ", matrix[baris][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void getMatriks(int matrix[][3]){              //function ambil matriks
    int baris, col;
    for(baris=0; baris<3;baris++){
        printf("Kolom %d\n", baris+1);
        for(col=0;col<3;col++){
            scanf("%d", &matrix[baris][col]);
            fflush(stdin);
        } printf("\n");
    }      
}

void multiplyMatrices(int mat1[][3], int mat2[][3], int result[][3], int rows, int cols) {  //function perkalian matriks
    int i, j, k;
    for (i = 0; i < rows; i++) {                //rows menunjukan panjang baris matriksnya yaitu 3
        for (j = 0; j < cols; j++) {            //cols menunjukan panjang kolom matriksnya yaitu 3
            result[i][j] = 0;
            for (k = 0; k < cols; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void addMatrices(int mat1[][3], int mat2[][3], int result[][3], int rows, int cols) {           //function penjumlahan matriks
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void transposeMatrix(int mat[][3], int transposed[][3], int rows, int cols) {               //function transpose matriks
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            transposed[j][i] = mat[i][j];
        }
    }
}

int main(){
    int matriks1[3][3];
    int matriks2[3][3];
    int result[3][3];
    int opt;
    printf("Matriks Pertama 3x3\n");
    getMatriks(matriks1);
    printMatriks(matriks1);

    printf("Matriks Kedua 3x3\n");
    getMatriks(matriks2);
    printMatriks(matriks2);

    system("cls");
    printf("Matriks Pertama\n");
    printMatriks(matriks1);
    printf("Matriks Kedua\n");
    printMatriks(matriks2);

    printf("1.Perkalian Dua Buah Matrix\n2.Penjumlahan Dua Buah Matrix\n3.Transpose Dua Buah Matrix\n4.Keluar\nPilihlah: ");
    scanf("%d",&opt);
    switch(opt)
    {
    case 1: //perkalian
        multiplyMatrices(matriks1, matriks2, result, 3, 3);
        printMatriks(result);
        break;
    
    case 2: //penjumlahan
        addMatrices(matriks1,matriks2,result,3,3);
        printMatriks(result);
        break;

    case 3://transpose
        printf("Transpose Matriks Pertama\n");
        transposeMatrix(matriks1,result,3,3);
        printMatriks(result);
        printf("Transpose Matriks Kedua\n");
        transposeMatrix(matriks2,result,3,3);
        printMatriks(result);
        break;
        
    case 4: //keluar
        break;
    
    default:
        break;
    }

    return 0;
}