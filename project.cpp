#include <iostream>
#include <string>
#include <string.h>
#include <conio.h>
#define MAX 150
#define MAX2 15
#define MAX3 10
using namespace std;
void gorevli_menu();
void ana_menu();
class ogrenci {
public:
	string ad, soyad;
	int numara, vize, final;
	double ort;
	ogrenci() {};		//temel yapici fonksiyon.
	void yeni_kayit(string, string, int);
}ogrenciler[MAX], ogrenciler1[MAX3];
void ogrenci::yeni_kayit(string a, string s, int n) {
	ad = a; soyad = s; numara = n;
}
class ogretmen {
public:
	string ogretmen_ad, ogretmen_soyad, ogretmen_sifre;
	string ders;
	int ogretnmen_no;
	void yeni_kayit1(int, string, string, string, string);
	void ogretmen_menu();
}ogretmen[MAX2];
void ogretmen::yeni_kayit1(int a, string b, string c, string d, string e) {
	ogretmen_ad = b; ogretmen_soyad = c; ogretmen_sifre = d; ogretnmen_no = a; ders = e;
}
void ogretmen::ogretmen_menu() {
	int secim, n;
	static double toplam;		//indis olarak kullan�lacagi icin static olarak tan�mland�
	static int d = -1;			//fonksiyon her �a��r�l�d���nda de�erini korur.
	system("cls");							//yani e�er 1 artarsa atamalarda yeni de�eri 1 artm�� halidir gibi. !!!
	cout << "Ogretmen Not Sistemi" << endl;
	cout << "--------------------" << endl;
	cout << "1.Not girisi" << endl;
	cout << "2.Sinif ortalama hesaplamasi" << endl;
	cout << "3.Ogrenci listesi" << endl;
	cout << "4.Ana menu" << endl;
	secim = _getch();
	switch (secim)
	{
	case '1':
		system("cls");
		cout << "Notunu gireceginiz ogrencinin numarasini girin : " << endl;
		cin >> n;
		for (int k = 0; k < 150; k++) {
			if (n == ogrenciler[k].numara) {
				system("cls");
				cout << "Vize girin : ";
				cin >> ogrenciler[k].vize;
				cout << "Final girin : ";
				cin >> ogrenciler[k].final;
				cout << "Islem basarili." << endl;
				d++;
				ogrenciler[k].ort = double(ogrenciler[k].vize * 0.3 + ogrenciler[k].final * 0.7);
				ogrenciler1[d] = ogrenciler[k];
				system("pause");
				ogretmen_menu();
			}
		}
		cout << "Ogrenci bulunamadi." << endl;
		system("pause");
		ogretmen_menu();
	case '2':
		system("cls");
		if (d < 0) {
			cout << "Bu dersi alan ogrenci yok." << endl;
			system("pause");
			system("cls");
			ogretmen_menu();
		}
		else {
			for (int q = 0; q <= d; q++) {
				toplam += ogrenciler[q].ort;
			}
			cout << "Sinif ortalamasi : " << toplam / (d + 1) << endl;
			toplam *= 0;		//s�f�rlasinki tekrar tekrar �a��r�ld���nda sorun olmas�n
			system("pause");
			ogretmen_menu();
		}
	case '3':
		system("cls");
		for (int o = 0; o <= d; o++) {
			cout << "Ad : " << ogrenciler1[o].ad << "\tSoyad : " << ogrenciler1[o].soyad << "\tNumara : " << ogrenciler1[o].numara << "\tOrtalama : " << ogrenciler1[o].ort << endl;
		}
		if (d < 0) {
			cout << "Bu dersi alan ogrenci bulunamadi." << endl;
		}
		system("pause");
		system("cls");
		ogretmen_menu();
	case '4':
		system("cls");
		ana_menu();
	default:
		cout << "Hatali secim !" << endl;
		system("pause");
		system("cls");
		ogretmen_menu();
		break;
	}
}
int main() {
	ana_menu();
	system("pause");
}
void ana_menu() {
	system("cls");
	int secimm, b, num;
	string sifre;
	string k_id, k_sifre;
	cout << "OKUL OTOMASYONU" << endl;
	cout << "---------------" << endl;
	cout << "1.Gorevli Girisi" << endl;
	cout << "2.Ogretmen Girisi" << endl;
	cout << "3.Cikis" << endl;
	secimm = _getch();
	switch (secimm)
	{
	case '1':
		system("cls");
		cout << "Kullanici adi : ";
		cin >> k_id;
		if (k_id == "1") {
			cout << "Sifre:";
			cin >> k_sifre;
			if (k_sifre == "1") {
				gorevli_menu();
			}
			else {
				cout << "Sifre yanlis !" << endl;
				system("pause");
				system("cls");
				ana_menu();
			}
		}
		else {
			cout << "Hatali giris !" << endl;
			system("pause");
			system("cls");
			ana_menu();
		}
	case '2':
		system("cls");
		cout << "Numara girin : " << endl;
		cin >> num;
		for (int u = 0; u < 15; u++) {
			if (ogretmen[u].ogretnmen_no == num) {
				cout << "Sifre Girin :";
				cin >> sifre;
				if (ogretmen[u].ogretmen_sifre == sifre) {
					cout << "Sifre dogru.Yonlendiriliyorsunuz." << endl;
					system("pause");
					ogretmen[u].ogretmen_menu();
				}
				else {
					cout << "Sifre yanlis !" << endl;
					system("pause");
					system("cls");
					ana_menu();
				}
			}
		}
		cout << "Numara sistemde bulunmamakta ! " << endl;
		system("pause");
		system("cls");
		ana_menu();
	case '3':
		exit(1);
	default:
		cout << "Hatali secim " << endl;
		system("pause");
		system("cls");
		ana_menu();
	}
}
void gorevli_menu() {
	int secimmm, no, aranan;
	static int numara = 0, i = -1, a = -1;
	string ad, soyad, ders, s;
	system("cls");
	cout << "Okul Otomasyonu" << endl;
	cout << "---------------" << endl;
	cout << "1.Yeni ogrenci kayit" << endl;
	cout << "2.ogrenci kaydi sil" << endl;
	cout << "3.Ogrenci kayit lislele" << endl;
	cout << "4.Yeni ogretmen kaydi" << endl;
	cout << "5.Ogretmen kayit sil" << endl;
	cout << "6.Ogretmen listele" << endl;
	cout << "7.Ana menu" << endl;
	secimmm = _getch();
	switch (secimmm)
	{
	case '1':
		system("cls");
		cout << "Ad girin : ";
		cin >> ad;
		cout << "Soyad girin : ";
		cin >> soyad;
		cout << "Numara girin : ";
		cin >> no;
		i++;		//indis 1 artt�r�ld�.
		ogrenciler[i].yeni_kayit(ad, soyad, no);
		cout << i << ".ogrenci kaydi tamam." << endl;
		system("pause");
		gorevli_menu();
	case '2':
		system("cls");
		cout << "Numara girin : ";
		cin >> aranan;
		for (int op = 0; op <= i; op++) {
			if (ogrenciler[op].numara == aranan) {
				for (int k = op; k < i; op++) {
					ogrenciler[k] = ogrenciler[k + 1];		//index bo�alt�ld�
				}
				cout << "Kayit silindi" << endl;
				i--;		//index 1 azalt�ld�
				system("pause");
				gorevli_menu();
			}
		}
		cout << "Kayit bulunamadi !" << endl;
		system("pause");
		gorevli_menu();
	case '3':
		system("cls");
		for (int j = 0; j <= i; j++) {
			cout << "Ad : " << ogrenciler[j].ad << "\tSoyad : " << ogrenciler[j].soyad << "\tNumara : " << ogrenciler[j].numara << endl;
		}
		system("pause");
		gorevli_menu();
	case '4':
		system("cls");
		cout << "Ad girin : ";
		cin >> ad;
		cout << "Soyad girin : ";
		cin >> soyad;
		cout << "Bransi : ";
		cin >> ders;
		cout << "Ogretmen girisinde kullanilacak sifre : ";
		cin >> s;			//ogretmen numarasi her giriste otomatik 1 art�yor.
		a++;				//indis 1 artt�r�ld�.
		ogretmen[a].yeni_kayit1(numara, ad, soyad, s, ders);
		numara++;
		gorevli_menu();
	case '5':
		system("cls");
		cout << "Numara giriniz : ";
		cin >> aranan;
		for (int j = 0; j <= a; j++) {
			if (ogretmen[j].ogretnmen_no == aranan) {
				for (int k = j; k < a; k++) {			//en son de�er neyse s�rekli e�itlik yapa yapa bo� de�ere 
					ogretmen[k] = ogretmen[k + 1];		//e�itliyor yani s�f�rl�yor...
				}
				cout << "Kayit silindi." << endl;
				a--;
				system("pause");
				gorevli_menu();
			}
		}
		cout << "Kayit bulunamadi." << endl;
		gorevli_menu();
	case '6':
		system("cls");
		for (int j = 0; j <= a; j++) {
			cout << "No : " << ogretmen[j].ogretnmen_no << "\tAd : " << ogretmen[j].ogretmen_ad << "\tSoyad : " << ogretmen[j].ogretmen_soyad << "\tBrans : " << ogretmen[j].ders << endl;
		}
		system("pause");
		gorevli_menu();
	case '7':
		ana_menu();
	default:
		cout << "Hata !!" << endl;
		system("cls");
		gorevli_menu();
	}
}