#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define AY 12
void veriUret(int dizi[]);
int maxBul(int dizi[]);
void yatayGrafik(int dizi[]);
void dikeyGrafik(int dizi[]);

int main() {
    int ciro[AY];

    srand(time(NULL));  // Rastgele sayı üretimi için 
    veriUret(ciro);

    printf("Yatay Bar Grafiği\n");
    yatayGrafik(ciro);

    printf("\nDikey Bar Grafiği\n");
    dikeyGrafik(ciro);

    return 0;
}

 //Diziye 1 ile 10 arasında rastgele değerler atar 
void veriUret(int dizi[]) {
    for (int i = 0; i < AY; i++) {
        dizi[i] = rand() % 10 + 1;
    }
}

//Dizideki en büyük değeri bulur
int maxBul(int dizi[]) {
    int max = dizi[0];
    for (int i = 1; i < AY; i++) {
        if (dizi[i] > max) {
            max = dizi[i];
        }
    }
    return max;
}

// Yatay bar grafik çizer 
void yatayGrafik(int dizi[]) {
    for (int i = 0; i < AY; i++) {
        printf("%2d: ", i + 1);
        for (int j = 0; j < dizi[i]; j++) {
            printf(" *");
        }
        printf("\n");
    }
}

// Dikey bar grafik çizer
void dikeyGrafik(int dizi[]) {
    int max = maxBul(dizi);

    for (int i = max; i > 0; i--) {
        for (int j = 0; j < AY; j++) {
            if (dizi[j] >= i)
                printf("* ");
            else
                printf("  ");
        }
        printf("\n");
    }

    for (int i = 1; i <= AY; i++) {
        printf("%d ", i);
    }
    printf("\n");
}