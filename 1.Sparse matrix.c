#include <stdio.h>
#include <stdlib.h>

struct sparsematrix{
	int row;
	int column;
	int value;
};

int main() {
	int m,n;
	int i,j;
	struct sparsematrix sparse[50];
	printf("Please enter row and coulmn number:");
	scanf("%d%d",&m,&n);
	int array[m][n];
	printf("please enter the elements of matrix:");    	//matrisin elemanlarýný al
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			scanf("%d",&array[i][j]);
		}
	}
    int count=0;
	// Sparse matris oluþtur
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (array[i][j] != 0) { // sadece sýfýr olmayanlarý kaydet
                sparse[count].row = i;
                sparse[count].column = j;
                sparse[count].value = array[i][j];
                count++;
            }
        }
    }
	
	 // Sparse matris ekrana yazdýrma
    printf("Sparse Matrix Representation:");
    printf("\nRow\tColumn\tValue\n");
    for (i = 0; i < count; i++) {
        printf("%d\t%d\t%d\n", sparse[i].row, sparse[i].column, sparse[i].value);
    }

    printf("Total non-zero elements: %d", count);
	
	return 0;
}
