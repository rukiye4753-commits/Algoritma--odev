#include <stdio.h>


int sayi = 1; 


void boslukBas(int adet);
void ucgenCizmeDongusu(int satir, int sutun, int n);
void UcgenUygulamasiniBaslat();

int main() {
    //Maini boş bırak
    UcgenUygulamasiniBaslat();
    return 0;
}

//Uygulamayi baslatan ana fonksiyon
void UcgenUygulamasiniBaslat() {
    int n;
    printf("Ucgenin satir sayisini girin: ");
    scanf("%d", &n);

    printf("\nMerkezi Ucgen Gorunumu:\n\n");
    ucgenCizmeDongusu(1, 1, n);
}

// Sayilarin soluna bosluk basan yardımcı recursive fonksiyon 
void boslukBas(int adet) {
    if (adet <= 0) return;
    printf("  "); 
    boslukBas(adet - 1);
}

//Ucgeni merkezi sekilde cizen ana recursive fonksiyon
void ucgenCizmeDongusu(int satir, int sutun, int n) {
    /* Tum satirlar bittiyse dur */
    if (satir > n) return;

    //Her satirin basinda gereken boslugu hesapla ve bas 
    if (sutun == 1) {
        boslukBas(n - satir);
    }
    printf("%3d ", sayi);
    sayi++;

    //Satir bittiyse alt satira geç
    if (sutun >= satir) {
        printf("\n");
        ucgenCizmeDongusu(satir + 1, 1, n);
        return;
    }
    ucgenCizmeDongusu(satir, sutun + 1, n);
}