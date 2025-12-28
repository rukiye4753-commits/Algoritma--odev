#include <stdio.h>
#include <stdlib.h>
#include <time.h>  

#define BOYUT 5

// Çok boyutlu diziler global olarak tanımlandı
int labirent[BOYUT][BOYUT];
int cozumYolu[BOYUT][BOYUT] = {0};

// Fonksiyon prototipleri
void labirentOlustur();
void haritayiYazdir(int matris[BOYUT][BOYUT]);
int yoluBul(int x, int y);
void LabirentOyununuBaslat();

int main() {
    // Main sadece başlatıcı fonksiyonu çağırır
    LabirentOyununuBaslat();
    return 0;
}

// Tüm süreci yöneten ana fonksiyon
void LabirentOyununuBaslat() {
    srand(time(NULL));
    
    // Labirent oluşturuluyor
    labirentOlustur();

    printf("--- Labirent Kacis Oyunu ---\n\n");
    printf("Rastgele Olusturulan Labirent (1: Yol, 0: Duvar):\n");
    haritayiYazdir(labirent);

    // (0,0) noktasından yol aramaya başla
    if (yoluBul(0, 0) == 1) {
        printf("\n--- Cikis Yolu Bulundu! ---\n");
        printf("Iste izlenen rota:\n");
        haritayiYazdir(cozumYolu);
    } else {
        printf("\nMaalesef bu haritada bir cikis yolu yok (sansina kuss).\n");
    }
}

// Labirenti rastgele değerlerle dolduran fonksiyon
void labirentOlustur() {
    int i, j;
    for (i = 0; i < BOYUT; i++) {
        for (j = 0; j < BOYUT; j++) {
            // %70 ihtimalle yol (1), %30 ihtimalle duvar (0)
            if ((rand() % 10) < 7) {
                labirent[i][j] = 1;
            } else {
                labirent[i][j] = 0;
            }
        }
    }
    // Giriş ve çıkış noktaları garantiye alınır
    labirent[0][0] = 1;
    labirent[BOYUT - 1][BOYUT - 1] = 1;
}

// Rekürsif yol bulma fonksiyonu
int yoluBul(int x, int y) {
    // Sınır kontrolü
    if (x < 0 || x >= BOYUT || y < 0 || y >= BOYUT) return 0;
    
    // Duvar mı veya daha önce geçildi mi kontrolü
    if (labirent[x][y] == 0 || cozumYolu[x][y] == 1) return 0;

    // Çıkış noktasına ulaşıldı mı? (4,4)
    if (x == BOYUT - 1 && y == BOYUT - 1) {
        cozumYolu[x][y] = 1;
        return 1;
    }

    // Mevcut konumu çözüm yoluna ekle
    cozumYolu[x][y] = 1;

    // 4 yönü kontrol eder (Aşağı, Sağ, Yukarı, Sol)
    if (yoluBul(x + 1, y) == 1) return 1; // Aşağı
    if (yoluBul(x, y + 1) == 1) return 1; // Sağ
    if (yoluBul(x - 1, y) == 1) return 1; // Yukarı
    if (yoluBul(x, y - 1) == 1) return 1; // Sol

    // Eğer bu yoldan çıkış yoksa geri al (Backtracking)
    cozumYolu[x][y] = 0;
    return 0;
}

// Çok boyutlu diziyi ekrana yazdıran fonksiyon
void haritayiYazdir(int matris[BOYUT][BOYUT]) {
    int i, j;
    for (i = 0; i < BOYUT; i++) {
        for (j = 0; j < BOYUT; j++) {
            printf("%d ", matris[i][j]);
        }
        printf("\n");
    }
}