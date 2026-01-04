#include <stdio.h>

int hamleSayisi = 0;

void hanoi(int n, char kaynak, char hedef, char yardimci)
{
    if (n == 1)
    {
        hamleSayisi++;
        printf("%2d. hamle: Disk 1 %c -> %c\n", hamleSayisi, kaynak, hedef);
        return;
    }

    hanoi(n - 1, kaynak, yardimci, hedef);

    hamleSayisi++;
    printf("%2d. hamle: Disk %d %c -> %c\n", hamleSayisi, n, kaynak, hedef);

    hanoi(n - 1, yardimci, hedef, kaynak);
}

int main()
{
    int diskSayisi = 4;

    printf("Tower of Hanoi - %d Disk\n\n", diskSayisi);

    hanoi(diskSayisi, 'A', 'C', 'B');

    printf("\nToplam hamle sayisi: %d\n", hamleSayisi);

    return 0;
}

