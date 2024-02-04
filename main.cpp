#include <iostream>
#include <string>
#include <cctype>
using namespace std;
class bankaHesabi{
private:
    string isimSoyisim;
    double bakiye;
protected:
    string sifreBelirleme;
    string kullaniciSifre;
public:
    bankaHesabi(string kullanici, double hesapBakiyesi):isimSoyisim(kullanici), bakiye(hesapBakiyesi)
    {};
void paraYatir(double paraMiktari){
    if (paraMiktari>0){
        bakiye+=paraMiktari;
        cout<<paraMiktari<<" basariyla hesabiniza yatirildi."<<endl;
        cout<<"Guncel Hesap Bakiyesi: "<<bakiye<<endl;
    }
}
void paraCek(double paraMiktari){
    if (paraMiktari<=bakiye){
        bakiye-=paraMiktari;
        cout<<paraMiktari<<" basariyla hesabinizdan cekildi."<<endl;
        cout<<"Guncel Hesap Bakiyesi: "<<bakiye<<endl;
    } else{
    cout<<"Yetersiz bakiye!"<<endl;
    }
}
void bakiyeGoster(){
    cout<<"Guncel Hesap Bakiyesi: "<<bakiye<<endl;
}
};
int main(){
    string isimSoyisim;
    string sifreBelirleme;
    string kullaniciSifre;
    for(int cizgi = 0; cizgi < 50; cizgi++){
        cout << "-";
    }
    cout << endl;
    cout << "C++ Bankasina Hos Geldiniz\nLutfen isminizi, soyisminizi yazdiktan sonra sifrenizi belirleyiniz."<<endl;
    for(int cizgi = 0; cizgi < 50; cizgi++){
        cout << "-";
    }
    cout << endl;
    cout<<"Isim & Soyisim: ";
    getline(cin,isimSoyisim);
        cout << endl;
        cout << "Sifrenizi belirleyin: ";
        cin >> sifreBelirleme;
        cout << endl;
        if (sifreBelirleme.length() != 4) {
            cout << "Lutfen 4 haneli bir sifre belirleyin."<<endl;
        } else {
            cout << "Sifreniz basariyla belirlendi.";
            cout << endl;
        }
    for(int cizgi = 0; cizgi < 50; cizgi++){
        cout << "-";
    }
    cout << endl;
    int denemeHakki = 0;
    const int denemeHakkiMaks=3;
    while (denemeHakki<denemeHakkiMaks){
        cout<<"Belirlediginiz sifreyi giriniz: ";
        cin>>kullaniciSifre;
        if (kullaniciSifre==sifreBelirleme){
            cout << endl;
            cout<<"Basariyla giris yaptiniz.";
            cout << endl;
            cout << endl;
            for(int cizgi = 0; cizgi < 50; cizgi++){
                cout << "*";
            }
            for (char &buyukHarf : isimSoyisim) {
                buyukHarf = toupper(buyukHarf);
            }
            cout << endl;
            cout <<"Hos geldiniz "<<isimSoyisim<<endl;
            for(int cizgi = 0; cizgi < 50; cizgi++){
                cout << "*";
            }
            cout << endl;
            break;
        } else {
            cout<<"Hatali giris yaptiniz. Kalan sifre deneme hakki: "<<denemeHakkiMaks-denemeHakki-1<<endl;
            denemeHakki++;
        }
    }
    if (denemeHakki==denemeHakkiMaks){
        for(int cizgi = 0; cizgi < 50; cizgi++){
            cout << "-";
        }
        cout << endl;
        cout << "3 hatali giris yaptiniz.\nSistem bloke edildi."<<endl;
        for(int cizgi = 0; cizgi < 50; cizgi++){
            cout << "-";
        }
        return 0;
    }
    int secim;
    double paraMiktari;
    double bakiye;
    bankaHesabi hesap(isimSoyisim,bakiye);
    do {
        for(int cizgi = 0; cizgi < 50; cizgi++){
            cout << "*";
        }
        cout << endl;
        cout<<"1- Para Yatir"<<endl;
        cout<<"2- Para Cek"<<endl;
        cout<<"3- Bakiyeyi Goster"<<endl;
        cout<<"4- Cikis Yap"<<endl;
        for(int cizgi = 0; cizgi < 50; cizgi++){
            cout << "*";
        }
        cout << endl;
        cout<<"Yapacaginiz islemi seciniz: ";
        cin>>secim;
        switch (secim) {
            case 1:
                cout << endl;
                cout<<"Yatirilacak para miktari: ";
                cin>>paraMiktari;
                hesap.paraYatir(paraMiktari);
                break;
            case 2:
                cout << endl;
                cout<<"Cekilecek para miktari: ";
                cin>>paraMiktari;
                hesap.paraCek(paraMiktari);
                break;
            case 3:
                hesap.bakiyeGoster();
                break;
            case 4:
                break;
            default:
                cout << endl;
                cout<<"Gecersiz secim!"<<endl;
                break;
        }
    } while (secim!=4);
    return 0;
}
