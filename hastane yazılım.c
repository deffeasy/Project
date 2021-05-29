#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct hastalar
{
    char hastaAdSoyad[MAX];
    int yas;
    char durum[MAX];
    char bekledigiSure[MAX];
    char hastaSikayeti[MAX];
    char tani[MAX];
    char hastahaneBolum[MAX];
    char uygulananTedavi[MAX];
    char onerilenTedavi[MAX];
    char tedaviSuresi[MAX];
    char ilaclar[MAX];

};


struct doktorlar
{
    char doktorAd[MAX];
    char doktorSoyad[MAX];
};


void doktorlariGoster(struct doktorlar x,int i){
    printf("%d. Doktorun adi ve soyadi: %s %s\n",i,x.doktorAd,x.doktorSoyad);
}

void hastalariGoster(struct hastalar x,int i){
    printf("%d. Hastanin adi ve soyadi: %s\n",i,x.hastaAdSoyad);
}

void spesifikHasta(struct hastalar x,int a)
{
    printf("%d numarali hastayi tusladiniz.Hastanin ;\nAdi ve Soyadi : %s\nYasi : %d\nDurumu : %s\nHastanade Bekledigi Sure: %s\nHasta Sikayeti : %s\nTani : %s\n",a,x.hastaAdSoyad,x.yas,x.durum,x.bekledigiSure,x.hastaSikayeti,x.tani);
    printf("Bolumu : %s\nUygulanan Tedavi : %s\nOnerilen Tedavi : %s\nTedavi Suresi : %s\nIlaclar : %s",x.hastahaneBolum,x.uygulananTedavi,x.onerilenTedavi,x.tedaviSuresi,x.ilaclar);
}


int main()
{
    int keys,choice,i=0,j=0;
    int hastaSayisi=3,finish=0;
    
    printf("Kac adet hasta bilgisi kaydetmek istediginizi giriniz: ");
    scanf("%d",&hastaSayisi);    
    
    struct doktorlar dizi[5];
    struct hastalar hastaDizi[hastaSayisi];
    
    system("CLS");
    
    
    for( i=0; i < hastaSayisi ; i++){
        
        printf("%d. Hastanin Bilgilerini Giriniz\n",i+1);

        printf("Hastanin Adi ve Soyadi: ");
        scanf("%s",hastaDizi[i].hastaAdSoyad);
        
        fflush(stdin);
        
        printf("Hastanin Yasi : ");
        scanf("%d",&hastaDizi[i].yas);
        
        fflush(stdin);
        
        printf("Hastanin Durumu : ");
        scanf("%s",hastaDizi[i].durum);
        
        fflush(stdin);
        
        printf("Hastanin Hastahanede Bekledigi Sure : ");
        scanf("%s",hastaDizi[i].bekledigiSure);
        
        fflush(stdin);
        
        printf("Hastanin Sikayeti : ");
        scanf("%s",hastaDizi[i].hastaSikayeti);
        
        fflush(stdin);
        
        printf("Hastanin Tanisi : ");
        scanf("%s",hastaDizi[i].tani);
        
        fflush(stdin);
       
        printf("Hastanin Hastahanedeki Bolumu : ");
        scanf("%s",hastaDizi[i].hastahaneBolum);
        
        fflush(stdin);
       
        printf("Hastaya Uygulanan Tedavi : ");
        scanf("%s",hastaDizi[i].uygulananTedavi);
       
        fflush(stdin);
        printf("Hastaya Onerilen Tedavi : ");
        scanf("%s",hastaDizi[i].onerilenTedavi);
       
        fflush(stdin);
       
        printf("Hastanin Tedavi Suresi : ");
        scanf("%s",hastaDizi[i].tedaviSuresi);
       
        fflush(stdin);
        
        printf("Hastanin Ilaclari : ");
        scanf("%s",hastaDizi[i].ilaclar);

        system("CLS");
    }
    
    strcpy(dizi[0].doktorAd,"Jesus");
    strcpy(dizi[0].doktorSoyad,"Christ");

    strcpy(dizi[1].doktorAd,"Faruk");
    strcpy(dizi[1].doktorSoyad,"Gumus");

    strcpy(dizi[2].doktorAd,"Hifai");
    strcpy(dizi[2].doktorSoyad,"Nazli");

    strcpy(dizi[3].doktorAd,"Sefa");
    strcpy(dizi[3].doktorSoyad,"Duran");

    strcpy(dizi[4].doktorAd,"Sude");
    strcpy(dizi[4].doktorSoyad,"Celik");



while(finish == 0){
    a:
    getch();
    system("CLS");
    printf("Hasta bilgilendirme paneline hosgeldiniz...\nLutfen Doktor bilgilendirmesi Icin  1'i\nHasta Yakini Bilgilendirmesi Icin 2yi\nCikmak icin ise baska bir sey tuslayiniz!\n");
    scanf("%d",&keys);
    
    switch(keys){

    case 1: 
        
        system("CLS");
        printf("Doktor bilgilendirme panelini tusladiniz lutfen doktor numaranizi giriniz(1 - 5 arasi)\n");
        
        for(i = 0; i<5 ;i++){
            doktorlariGoster(dizi[i],i+1);
        }
        
        scanf("%d",&choice);
        system("CLS");
        printf("Doktor %s tekrardan hosgeldiniz bilgi almak istediginiz hastanin numarasini giriniz.(1-%d arasi bi sayi giriniz)\n",dizi[choice-1].doktorAd,hastaSayisi);
        
        for(i=0 ; i<hastaSayisi ; i++){
            hastalariGoster(hastaDizi[i],i+1);
        }
        
        scanf("%d",&choice);
        system("CLS");  
        spesifikHasta(hastaDizi[choice-1],choice);
        
        break;
        
    case 2: 
        printf("Hasta Yakini Bilgilendirme Panelini Tusladiniz:Lutfen Hasta sira no giriniz (1 - %d):",hastaSayisi);
        scanf("%d",&choice);
        
        system("CLS");
        
        if(  (choice < 1)   || (choice > hastaSayisi)   ){
            printf("Hatali Sira No girdiniz.\a");
            goto a;
        }
        
        spesifikHasta(hastaDizi[choice-1],choice);
        break;
    
    default:
        system("CLS");
        printf("Programdan cikis yaptiniz.\nHazirlayan ..........");
        finish = 1;
        break;
    }

}
    
return 0;
}