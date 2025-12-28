#include <stdio.h>
int asalKontrol(int n);
int unluMu(char harf);
void isimleriListele();

int main() {
    isimleriListele();
    
    return 0;
}

// Verilen sayının asal olup olmadığını kontrol eden fonksiyon
int asalKontrol(int n) {
    int i;
    // 2'den kucuk sayilar asal degildir
    if (n < 2) return 0;

    // Bolenleri kontrol et
    for (i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

// Bir harfin ünlü olup olmadığını kontrol eden fonksiyon
int unluMu(char harf) {
    if (harf == 'a' || harf == 'e' || harf == 'i' || harf == 'o' || harf == 'u') {
        return 1; // Unlu
    }
    return 0; // Unsuz
}

// Isim listeleme mantigini yürüten ana fonksiyon
void isimleriListele() {
    int sayac = 0;
    char karakter1, karakter2, karakter3;
    int toplamAscii;

    printf("--- Gecerli Isimler Listeleniyor ---\n\n");

    // Karakter donguleri baslar
    for (karakter1 = 'a'; karakter1 <= 'z' && sayac < 47; karakter1++) {
        for (karakter2 = 'a'; karakter2 <= 'z' && sayac < 47; karakter2++) {
            
            // Ucuncu harf birinci harfe esitlenir
            karakter3 = karakter1;

            // Harflerden biri unlu, digeri unsuz ise kosul saglanir
            if ((unluMu(karakter1) && !unluMu(karakter2)) || (!unluMu(karakter1) && unluMu(karakter2))) {
                
                // ASCII degerleri toplami hesaplanir
                toplamAscii = karakter1 + karakter2 + karakter3;

                // Asallik kontrolu fonksiyonla yapilir
                if (asalKontrol(toplamAscii)) {
                    sayac++;
                    printf("%2d. %c%c%c (ASCII: %d)\n", sayac, karakter1, karakter2, karakter3, toplamAscii);
                }
            }
        }
    }
}