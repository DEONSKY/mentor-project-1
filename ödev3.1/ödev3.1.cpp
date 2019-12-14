/****************************************************************************
**
**				ÖĞRENCİ ADI...........................:Mert Can Yılmaz
**				ÖĞRENCİ NUMARASI.............:g191210018
**				DERS GRUBU…………………:2A
****************************************************************************/


#include <iostream>//Kullanılan Kütüphaneler
#include<time.h>//Atanan random sayıların değişmesi için gerekli

using namespace std;

const int a = 25;//const int tanımlanmış
int matris[a][a];//Ana matrisimiz
int gecici1b[a];//Ana matrisin değerlerinin işleme göre geçici olarak tutulacağı dizi

void matrisyaz(int boyut)
{
	cout << "    ";//Başa gerekli sabit boşluğu bırakır
	for (int j = 1; j <= boyut; j++)//1 den boyuta kadar sayı yazdırır
	{
		for (int z = j; z < 1000; z = z * 10)// Yazdırılan sayılarda basamak arttıkça olan kaymanın önünegeçer.Yani ne kadar az basamak varsa o kadar çok boşluk yazdırır.
		{
			cout << " ";
		}
		cout << j;
	}
	cout << endl;//Aşağı geçir
	cout << "    ";//Başa gerekli sabit boşluğu bırakır
	for (int j = 0; j < boyut; j++)//boyutun değeri kadar çizgi kümesi yazdırır
	{
		cout << "____";
	}
	cout << endl;
	cout << endl;

	for (int i = 0; i < boyut; i++)//satır numaralandırma ve matris değer yazdırma kısmı
	{
		for (int z = i + 1; z < 100; z = z * 10)//numaralandırma sayılarının basamak farklarından dolayı oluşacak kaymayı engeller
		{
			cout << " ";
		}

		cout << i + 1 << "|";//satır numarası yazdırır

		for (int j = 0; j < boyut; j++)//matrisi yazdırır
		{
			if (matris[i][j] != 0)//0 döngüdeki işlemi sonsuza götürür.İf else 0 değerini döngüye sokmaz, olması gerektiği sayıda boşluk yazdırır
			{
				for (int z = matris[i][j]; z < 1000; z = z * 10)//matris'e uygulanacak işlemler sonucu basamak değeri artabliceği için olabilecek kaymaların önüne geçer.
				{
					cout << " ";
				}
			}
			else
				cout << "   ";

			cout << matris[i][j];//matrisin o indisteki değerini yazar
		}
		cout << endl << endl;
	}
}
int main()
{
	srand(time(NULL));//rand fonksiyonun farklı değerler ataması için gerekli
	while (1) {//içerideki sonsuz döngüyü yaratır

		int h = 0;//ilk do while döngüsüne girdiğinde if'in içindeki yazdırılmasın diye oluşturulan değişken
		int boyut;//matris boyutu değişken tipi tanımlanıyor
		do {

			if (h != 0)//ilk girdiğinde yazdırmaz
				cout << "boyut 25'ten kucuk yada esit ve 5'den buyuk yada esit olmalidir." << endl;
			cout << "matris boyutu: ";
			cin >> boyut;//boyut değerini kullanıcıdan alır
			h++;
		} while (boyut < 5 || boyut > 25);//boyut değeri olmaması gereken kriterlerdeyse geri döndürür.

		for (int i = 0; i < boyut; i++)//2 boyutlu matrisin 1. indisini değiştiren döngü
		{
			for (int j = 0; j < boyut; j++)//2 boyutlu matrisin 2. indisini değiştiren döngü
			{
				matris[i][j] = rand() % 9 + 1;//random sayı atama
			}
		}

		while (1)// sonsuz döngü. programın return 0 girilene kadar tekrarlamasını sağlar
		{
			matrisyaz(boyut);//ilgili fonksiyonu çağırma

			cout << "1 / Sutun Satir Degistir" << endl;//menu kısmı
			cout << "2 / Tekleri Basa Al (Satir)" << endl;
			cout << "3 / Ters Cevir (Sutun)" << endl;
			cout << "4 / Toplamlari yazdir" << endl;
			cout << "0 / Programi kapat" << endl;
			int secim;
			cin >> secim;//menu den seçilen işlevi yapan fonksiyonu etkinleştirecek sayı değerinin girilmesi


			if (secim == 1)//secim==1 de yapılacaklar
			{
				int hr, vr;
				cout << "satir ve sutun giriniz:";
				cin >> hr;//hr(horizonal)yani satır değerini kullanıcıdan alır
				cin >> vr;//vr(vertical)yani sutun değerini kullanıcıdan alır

				if (hr > boyut || vr > boyut)// değerlerin boyuttan büyük olup olmadığını sorgular.Büyükse ekrana mesajı yazar
				{
					cout << "satir ve sutun matris boyutundan buyuk olamaz" << endl;
					system("pause");
				}
				else {
					hr = hr - 1;//hr değerini indisler 0 dan numaralandırılmaya başlandığı için 1 azaltır
					vr = vr - 1;//vr değerini indisler 0 dan numaralandırılmaya başlandığı için 1 azaltır

					for (int j = 0; j < boyut; j++)//seçilen satırı geçici diziye atar
					{
						gecici1b[j] = matris[hr][j];
					}

					for (int i = 0; i < boyut; i++)//seçilen sütunu seçilen satıra atar
					{
						matris[hr][i] = matris[i][vr];
					}
					for (int i = 0; i < boyut; i++)
					{
						if (i == hr)
							matris[i][vr] = gecici1b[i] + matris[i][vr];//eğer satır ve sutun un indisleri seçilen satır ve sutun değerindeyse toplar(Çakıştıkları indis)
						else
							matris[i][vr] = gecici1b[i];// geçici diziyi sutuna atar
					}
					system("pause");//sistemi başka bir emre kadar duraklatır
				}
			}
			else if (secim == 2)
			{
				int hr;
				cout << "satir seciniz: ";
				cin >> hr;//işlem yapılacak satır değeri girilir
				if (hr > boyut)//satır matrisin boyutundan büyükse uyarı yazdırır
				{
					cout << "satir matris boyutundan buyuk olamaz" << endl;
					system("pause");
				}
				else// aksi halde alttaki işlemleri yapar
				{
					hr = hr - 1;// seçilen satır değerini doğru indis karşılığına çevirir
					int s = 0;//artacak değişken
					int ts = boyut - 1;//azalacak değişken
					for (int j = 0; j < boyut; j++)//satır eleman sayısı kadar tekrarlar
					{
						if (matris[hr][j] % 2 == 1)//tekse geçiciye baştan sona doğru matrisin ilgili değerini atar
						{
							gecici1b[s] = matris[hr][j];
							s++;
						}
						else//çiftse geçiciye sondan başa doğru matrisin ilgili değerini atar
						{
							gecici1b[ts] = matris[hr][j];
							ts--;
						}
					}
					for (int j = 0; j < boyut; j++)// geçiciyi matrisin ilgili satırına atar
					{
						matris[hr][j] = gecici1b[j];
					}
					system("pause");
				}
			}
			else if (secim == 3)
			{
				int vr;
				cout << "sutun seciniz: ";
				cin >> vr;//sutun değeri girilir
				if (vr > boyut)//girilen değer boyuttan büyükse hata mesajı
				{
					cout << "sutun matris boyutundan buyuk olamaz" << endl;
					system("pause");
				}
				else
				{
					vr = vr - 1;// seçilen sutunun değerini doğru indis karşılığına çevirir
					int ts = boyut - 1;//azalacak değişken
					for (int i = 0; i < boyut; i++)
					{
						gecici1b[ts] = matris[i][vr];//geçicinın indis değeri 0'doğru azalırken, matrisin indis değeri 0 dan başlayarak artar. geçicide sutuun ters çevrilmiş hali oluşur
						ts--;
					}
					for (int i = 0; i < boyut; i++)
					{
						matris[i][vr] = gecici1b[i];//geçiyi matrisin ilgili sutununa atar.
					}
					system("pause");
				}
			}
			else if (secim == 4)
			{
				int toplam = matris[0][0];//toplamı 0 dan başlatır

				for (int i = 0; i < boyut; i++)
				{
					for (int j = 0; j < boyut; j++)
					{
						toplam = matris[i][j] + toplam;//döngülerinde yardımıyla matristeki her değeri sırayla birbiryle toplar. Önce satırı toplar. Satır bitince alt satıra geçer
					}
				}
				//cout << toplam << endl;
				for (int i = 0; i < boyut; i++)
				{
					for (int j = 0; j < boyut; j++)
					{
						toplam = toplam - matris[i][j];//toplam değerinden matrisin o indisteki değerini çıkarır ve sonra kendisinin yeni değeri olark atar
						matris[i][j] = toplam;//toplam değerini matrisin ilgili indisine değer olarak atar
					}
				}
				system("pause");
			}
			else if (secim == 0)//programdan çıkmayı sağlar
			{
				cout << "Programi kullandiginiz icin tesekkurler" << endl;
				return 0;
			}
			else// olmaya bir işlem değeri yazdırılda uyarı mesajı yazdırır
			{
				cout << "Sadece menudeki islemler yapilabilir. Lutfen tekrar secin. " << endl;
				system("pause");
			}
		}
	}
}

// Programı çalıştır: Ctrl + F5 veya Hata Ayıkla > Hata Ayıklamadan Başlat menüsü
// Programda hata ayıkla: F5 veya Hata Ayıkla > Hata Ayıklamayı Başlat menüsü

// Kullanmaya Başlama İpuçları: 
//   1. Dosyaları eklemek/yönetmek için Çözüm Gezgini penceresini kullanın
//   2. Kaynak denetimine bağlanmak için Takım Gezgini penceresini kullanın
//   3. Derleme çıktısını ve diğer iletileri görmek için Çıktı penceresini kullanın
//   4. Hataları görüntülemek için Hata Listesi penceresini kullanın
//   5. Yeni kod dosyaları oluşturmak için Projeye Git > Yeni Öğe ekle veya varolan kod dosyalarını projeye eklemek için Proje > Var Olan Öğeyi Ekle adımlarını izleyin
//   6. Bu projeyi daha sonra yeniden açmak için Dosya > Aç > Proje'ye gidip .sln uzantılı dosyayı seçin
