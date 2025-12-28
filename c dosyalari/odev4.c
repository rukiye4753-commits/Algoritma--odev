#include <stdio.h>
void sezarSifrele(char mesaj[], int anahtar);
void sezarCoz(char mesaj[], int anahtar);

int main()
 {
    char mesaj[100];
    int anahtar;

    printf("--- Sezar Sifreleme Programi ---\n");

    printf("Sifrelemek istediginiz mesaji girin: ");
    // boşlukları da alması için fgets kullanıdm.
    fgets(mesaj, 100, stdin);

    printf("Kaydirma miktarini (Anahtar) girin: ");
    scanf("%d", &anahtar);

    sezarSifrele(mesaj, anahtar);
    printf("\nSifrelenmis Hali: %s", mesaj);

    printf("\n--- Sifre Cozme Islemi ---\n");
    printf("Ayni mesaji eski haline ceviriyoruz...\n");
    // mesaj ve anahtarı gönderip şifreyi çözüyoruz.
    sezarCoz(mesaj, anahtar);
    printf("Cozulmus Hali: %s", mesaj);

    return 0;
}
// mesajı sifreliyen fonksiyon.
void sezarSifrele(char mesaj[], int anahtar) {
    int i = 0;
    char karakter;
    int harfSirasi;
    int yeniSira;

    while(mesaj[i] != '\0') {
        karakter = mesaj[i];
        // Büyük harf kontrolü yapar.
        if(karakter >= 'A' && karakter <= 'Z') 
        {
            // harfleri 0 25 arasına düşürüyoruz.
            harfSirasi = karakter - 'A';
            // 26 harften fazlaysa mod alarak başa döner.
            yeniSira = (harfSirasi + anahtar) % 26;
            // A ile Z arasında ascıı kodlarını tutmak için bu işlem yapılır
            mesaj[i] = yeniSira + 'A';
        }
        // küçük harf kontrolü yapar.
        else if(karakter >= 'a' && karakter <= 'z') 
        {
            // harfleri 0 25 arasına düşürüyoruz.
            harfSirasi = karakter - 'a';
             // 26 harften fazlaysa mod alarak başa döner.
            yeniSira = (harfSirasi + anahtar) % 26;
            // a ile z arasında ascıı kodlarını tutmak için bu işlem yapılır
            mesaj[i] = yeniSira + 'a';
        }        
        i++; 
    }
}

void sezarCoz(char mesaj[], int anahtar) {
    int i = 0;
    char karakter;
    int harfSirasi;
    int yeniSira;

    while(mesaj[i] != '\0') {
        karakter = mesaj[i];

        // büyük harf cözer.
        if(karakter >= 'A' && karakter <= 'Z') {
            harfSirasi = karakter - 'A';
            // şifrede verdiğimiz anahtar çıkarılır .
            yeniSira = harfSirasi - anahtar;
            // sonuc negatif olursa pozitif olana kadar 26 ekler.
            while(yeniSira < 0) 
            {
                yeniSira = yeniSira + 26;
            }
            mesaj[i] = (yeniSira % 26) + 'A';
        }
        // küçük harf çözer.
        else if(karakter >= 'a' && karakter <= 'z') {
            harfSirasi = karakter - 'a';
            yeniSira = harfSirasi - anahtar;
            // sonuc negatif olursa pozitif olana kadar 26 ekler.
            while(yeniSira < 0) {
                yeniSira = yeniSira + 26;
            }
            mesaj[i] = (yeniSira % 26) + 'a';
        }
        i++;
    }
}
