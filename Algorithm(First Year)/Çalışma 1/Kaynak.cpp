#define _CRT_SECURE_NO_WARNINGS		
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<process.h>
                                                               // ------------------  STRUCT YAPILAR  ------------------- //
typedef struct
{
	char *author;
	char *title;
	char *puplication;
	int year;
	char isbn[15];
		
}RECORD;


int main(void)
{
	RECORD  *ptr;
	
	int i,nbook;

	printf("how many books : ");
	scanf("%d",&nbook);
	while (getchar() != '\n');

	ptr = (RECORD*)calloc(nbook ,  sizeof(RECORD));
	for ( i = 0; i < nbook; i++)
	{
		printf("ekitap %d", i + 1);
		printf("________-\n");


		printf("author :\n");
		scanf("%s", &ptr->author);
		while (getchar() != '\n');

		printf("title : \n");
		scanf("%s", &ptr->title);
		while (getchar() != '\n');

		printf("puplication : \n");
		scanf("%s", &ptr->puplication);
		while (getchar() != '\n');

		printf("year : \n");
		scanf("%d", &ptr->year);
		while (getchar() != '\n');

		printf("isbn : \n");
		fgets(ptr->isbn, 16 * sizeof(char), stdin);

		ptr++;
	}
	//ptr = ptr - nbook;
	

	for (i = 0; i < nbook; i++)
	{
		printf("%s %s %d %s %s\n", ptr[i].author, ptr[i].title, ptr[i].year,ptr[i].puplication, ptr[i].isbn);
	}


	free(ptr);
}


                                                                       //  LINKED LIST
/*
typedef struct LIST
{
	char *title;
	char *puplication;
	char *author;
	int  year;
	char isbn[13];
	
	struct LIST *next;

}LIST;

LIST  *first = NULL, *last = NULL;

void insert(LIST *rcd)
{
	LIST *temp = first, *prev = NULL;
	while (temp != NULL)
	{
		if (temp->year != rcd->year)
		{                                    // WHÝLE DÖNGÜSÜ ÝÇÝNDE ELEMANIN YERÝNÝ BULDUK !!!
			prev = temp;
			temp = temp->next;
		}
		else
			break;
	}		
	if (first == NULL)         // BOÞ LÝSTEYE ÝLK ELEMANI EKLEME !!!
	{
		first = rcd;
		last = rcd;
		last->next = NULL;
	}
	else if(prev == last )    // SONA ELEMAN EKLEME !!!
	{
		last->next = rcd;
		rcd->next = NULL;
		last = rcd;
	}
	else if (prev = NULL)    // BAÞA ELEMAN EKLEME  !!! 
	{
		rcd->next = first;
		first = rcd;
	}
	else
	{                           // ARAYA ELEMAN EKLEME  !!! 
		rcd->next = prev->next;
		prev->next = rcd;
	}

}

void list()
{
	LIST *temp = first;

	if (temp == NULL)
	{
		printf("list is empty \n");
	}
	while (temp != NULL)
	{
		printf("%s %s %s %d %s\n", temp->title, temp->puplication, temp->author, temp->year, temp->isbn);
		
		temp = temp->next;
	}
}

void search(char isbn[])
{
	LIST *temp = first;
	while (temp != NULL)
	{
		if (strcmp(temp->isbn, isbn) == 0)
		{
			printf("%s %s %s %d %s\n", temp->title, temp->puplication, temp->author, temp->year, temp->isbn);
			temp = temp->next;
		}
		else if(strcmp(temp->isbn , isbn) != 0)
		{
			printf("It is wrong isbn , this is not here \n");
			break;
		}
	}
}

void delet (char isbn[])
{
	LIST *temp = first, *prev = NULL;
	while (temp != NULL)
	{
		if (strcmp(temp->isbn , isbn) != 0)
		{
			prev = temp;
			temp = temp->next;
		}
		else
		{
			break;
		}
	}		
	if(first == temp)   // BULUNAN ELMAN VARSA BURASI DEVREYE GÝRER .. 
	{
		if (first == last) // LÝSTEDEKÝ TEK ELEMANI SÝLER !!!
		{
			first = NULL;
			last = NULL;
		}
		else
		{
			first = temp->next;   // ÝLK ELEMANI SÝLER !!!
		}	
	}
	else
	{
		prev->next = temp->next; // ORTADAKÝ ELEMANI SÝLER ..

			if (last == temp) // SONDAKÝ ELEMANI SÝLER .. 
			{
				last = prev;
			}
	}
	free(temp);
}                                                             

int main()
{
	LIST *record , *next;	
	char sisbn[20];
	int i , nchar;

	while (1)
	{
		printf("1 = RECORD , 2 = LISTING , 3 = SEARCHING , 4 = DELETING , 5 = EXIT\n");
		scanf("%d", &i);
		switch (i)
		{
		case 1: record = (LIST*)malloc(sizeof(LIST));
			printf(" how many characters for title : \n");
			scanf("%d", &nchar);
			record->title = (char*)malloc((nchar + 1) * sizeof(char));
			scanf("%s", record->title);
			
			printf(" how many characters for puplication : \n");
			scanf("%d", &nchar);
			record->puplication = (char*)malloc((nchar + 1) * sizeof(char));
			scanf("%s", record->puplication);

			printf(" how many characters for author : \n");
			scanf("%d", &nchar);
			record->author = (char*)malloc((nchar + 1) * sizeof(char));
			scanf("%s", record->author);
			
			printf(" enter the year : \n");
			scanf("%d", &record->year);

			printf("enter the isbn : ");
			scanf("%s", record->isbn);
			insert(record);
			break;

		case 2: list(); break;

		case 3:
			printf("aramak istediginiz isbn i yaziznizz : \n ");
			scanf("%s", &sisbn);
			search(sisbn);
			break;

		case 4:
			printf("silmek istediginiz isbn i giriniz : \n");
			scanf("%s", &sisbn);
			delet(sisbn);
			break;

		case 5:
			record = first;
			while (record != NULL)
			{
				next = record->next;
				free(record);
				next = first;
				exit(0);
			}			
		}				
	}

	system("pause");
	return 0; 
}
*/


                                                                   // ---------------  DOSYA ÝÞLEMLERÝ -------------- // 


/*                          // ______________________________ÖÐRENCÝ BÝLGÝLERÝ VE NOT ORT. HESAPLAMA KODU ÖNEMLÝ !!!!!! _________________________//
          
struct Ogrenci
{                                 
	int yas;
	char isim[20];
	char vize, final;
};

float ortalama(struct Ogrenci *student)
{
	float sonuc;
	sonuc = student->vize*0.4 + student->final*0.6;
	return sonuc;
}



void dosyaya_yazdýr(struct Ogrenci *student)
{
	int i;
	FILE *hedef_dosya;
	hedef_dosya = fopen("ogrenci.txt", "w+");

	for ( i = 0; i < 5; i++)
	{
		if (student->yas == -1)
		{
			break;
		}

		fprintf(hedef_dosya,"%d.Ögrencinin bilgileri : \n", i + 1);
		fprintf(hedef_dosya, "------------------------------\n");
		fprintf(hedef_dosya, "isim %s\n", student->isim);
		fprintf(hedef_dosya, "yas : %d\n", student->yas);
		fprintf(hedef_dosya, "not ortalamasý : %.2f\n\n\n", ortalama(student));

		student++;
	}
	fclose(hedef_dosya);

	FILE *sonuc_dosyasý;
	sonuc_dosyasý = fopen("output.txt", "r+");
	if (sonuc_dosyasý == NULL)
	{
		printf("dosya acýlamdi");
	}


	fclose(sonuc_dosyasý);
}
int main()
{
	struct 	Ogrenci ögr[5];

	int i;

	
	printf("cikmak icin -1 e basiniz \n");

	for (i = 0; i < 5; i++)
	{		

		printf("ogrencinin yasi : ");
		scanf("%d", &(ögr[i].yas));
		
		if (ögr[i].yas == -1)
		{
			break;
		}

		printf("isim : ");
		scanf("%s", ögr[i].isim);

		printf("vize notu : ");
		scanf("%d", &(ögr[i].vize));

		printf("final notu : ");
		scanf("%d", &(ögr[i].final));
	}
	dosyaya_yazdýr(ögr);
	
	system("pause");
	return 0;
}
*/

                                                //----------------------------------- REHBERE KAYIT EKLEME KODU ÖNEMLÝ !!!!-----------------------//
/*
struct Kisi
{
	char ad[25];
	char soyad[25];
	int yas;
	char telno[12];

};
void menu();
void print_rehber(Kisi *rehber);
void kisi_ekle(Kisi *rehber);
void dosyaya_yaz(Kisi *rehber);

int main()
{
	Kisi rehber[50];
	int secim, flag = 0;
	char ch;

	rehber[0].yas == -1; // BU DURUM BU REHBERDE BU BÖLÜMÜN BOS OLDUGUNU GÖSTERÝYOR !!
	
	while (flag == 0)
	{
		menu();
		scanf("%d", &secim);

		switch (secim)
		{
		case 1:
			print_rehber(rehber);
			break;

		case 2:
			kisi_ekle(rehber);
			break;

			
		case 9: 
			flag == 1;
			dosyaya_yaz(rehber);

			printf("CIKMAK ICIN Q TUSUNA BASINIZ\n");
			scanf("%c", &ch);
			break;

		default:
			printf("YANLIS TUSA BASTINIZ\n");
			
		}
	}
	
	system("pause");
	return 0;
}

void menu()
{
	system("cls");
	printf("TELEFON REHBERÝ MENUSU\n");
	printf("-------------------------\n");
	printf("1 - TUM KISILERI YAZDIR\n");
	printf("2 - REHBERE KISI EKLE \n");
	printf("9 - PROGRAMI SONLANDIR\n");
	printf("\nSECIM YAPINIZ\n");

}

void print_rehber(Kisi *rehber)
{
	int i;
	for ( i = 0; i < 50; i++)
	{
		if (rehber[i].yas == -1) {
			break;
		}
		printf("%12s %12s %3d %s", rehber[i].ad, rehber[i].soyad, rehber[i].yas, rehber[i].telno);
	}
}

void kisi_ekle(Kisi *rehber)
{
	int i;
	for ( i = 0; i < 50; i++)
	{
		if (rehber[i].yas == -1)
		{
			break;
		}

		printf("kisini adi : ");
		scanf("%s", rehber[i].ad);

		printf("kisini soyadi : ");
		scanf("%s", rehber[i].soyad);

		printf("kisinin yasi : ");
		scanf("%d", &(rehber[i].yas));

		printf("kisinin telno : ");
		scanf("%s", rehber[i].telno);
				
	}	
	rehber[i + 1].yas == -1;

	printf("kisi basarýyla eklendi\n");
}

void dosyaya_yaz(Kisi *rehber)
{
	FILE *hedef_dosya = fopen("verigirisi.txt", "w+");
	int i;
	for (i = 0; i < 50; i++)
	{
		if (rehber[i].yas == -1)
		{
			break;
		}
		fprintf(hedef_dosya, "%s %s %d %s", rehber[i].ad, rehber[i].soyad, rehber[i].yas, rehber[i].telno);
	}
	fclose(hedef_dosya);
}
*/ 





 
