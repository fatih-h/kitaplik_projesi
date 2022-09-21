#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char kitapYazar[20];
    char kitapAdi[20];
    char yayinEvi[20];
    int sayfaSayisi;
}kitapBilgileri;

void kitapEkle(kitapBilgileri *kitapDizisi, int kitapSayisi){
    int i=0;
    while(1){
        if(i>kitapSayisi){
            puts("Uzgunum. Daha fazla kitap eklenemez, kitaplik tamamen dolu\n");
            return;
        }
        if(kitapDizisi[i].sayfaSayisi == 0){
            //kitapligin bos olup olmadigini sayfa sayisiyla kontrol ediyoruz.
            printf("Kitap Ismini Giriniz:");
            scanf("%s", &kitapDizisi[i].kitapAdi);
            printf("Kitap Yazarini Giriniz:");
            scanf("%s", &kitapDizisi[i].kitapYazar);
            printf("Kitap Yayinevini Giriniz:");
            scanf("%s", &kitapDizisi[i].yayinEvi);
            printf("Kitap Sayfa Sayisini Giriniz:");
            scanf("%d", &kitapDizisi[i].sayfaSayisi);

            return;
        }
        i++;
    }
}

void kitapGoruntule(kitapBilgileri *kitapDizisi, int kitapSayisi){
    int i;
    for(i=0; i< kitapSayisi; i++){
        printf("Kitap Adi:%s\n",kitapDizisi[i].kitapAdi);
        printf("Kitap Yazari:%s\n", kitapDizisi[i].kitapYazar);
        printf("Kitap Yayinevi:%s\n", kitapDizisi[i].yayinEvi);
        printf("Kitap Sayfa Sayisi:%d\n",kitapDizisi[i].sayfaSayisi);
        printf("------------------------------------------------\n");
    }
}

int kitapAra(kitapBilgileri *kitapDizisi, char *kitapAdi, int kitapSayisi){
    int i;
    for(i=0; i<kitapSayisi;i++){
        if(strcmp(kitapDizisi[i].kitapAdi,kitapAdi) == 0){
            return i;
        }
    }
    return -1;
}

int main() {
    int kitapSayisi;
    kitapBilgileri *kitaplik; //dinamik şekilde oluşturulan kitapBilgileri dizim.
    char kullaniciIstegi, kitapAdi[20];

    puts("Lutfen kac adet kitap eklemek istediginizi giriniz:");
    scanf("%d",&kitapSayisi);
    kitaplik = (kitapBilgileri *)calloc(kitapSayisi,sizeof(kitapBilgileri));

    do{
        fflush(stdin);
        puts("Kitap Eklemek istiyorsaniz 'E', tum kitaplari goruntulemek istiyorsaniz 'G', arama yapmak istiyorsaniz 'A', cikis icin 'Q' tuslayiniz.");
        kullaniciIstegi= getchar();
        switch(kullaniciIstegi){
            case 'E':
                kitapEkle(kitaplik,kitapSayisi);
                break;
            case 'A':
                puts("Aramak istediginiz kitabin adini giriniz:");
                scanf("%s",&kitapAdi);
                int kitapIndex = kitapAra(kitaplik,kitapAdi,kitapSayisi);
                if(kitapIndex == -1){
                    printf("Aradiginiz kitap kutuphanede bulunamadi.");
                }else{
                    printf("Aradginiz kitap kitapligimizin %c-%d kisminda bulundu.",kitapAdi[0], kitapIndex+1);
                }
                break;
            case 'G':
                kitapGoruntule(kitaplik,kitapSayisi);
                break;
            case 'Q':
                puts("Cikis yapiliyor... Tesekkur Ederiz\n");
                break;
            default:
                puts("Hatali tuslama yaptiniz.");
                break;
        }

    }while(kullaniciIstegi != 'Q');




    return 0;
}
