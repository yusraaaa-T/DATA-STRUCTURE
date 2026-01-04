#include <stdio.h>

#define MAX 100   

int main() {
    int arr[MAX];
    int n = 5;   
    
    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;
    arr[3] = 40;
    arr[4] = 50;

    int i;

    printf("Ilk dizi: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int yeniEleman = 60;
    arr[n] = yeniEleman;
    n++;

    printf("Sona ekleme sonrasi: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int index = 2;
    int eklenecek = 25;

    for(i = n; i > index; i--) {
        arr[i] = arr[i - 1];
    }
    arr[index] = eklenecek;
    n++;

    printf("Indekse ekleme sonrasi: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int silIndex = 3;

    for(i = silIndex; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Silme sonrasi: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}

