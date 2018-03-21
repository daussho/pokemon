/* Nomor Kelompok	: 04*/
/* Nama file 		: mesinkar_04.h*/
/* Deskripsi 		: ADT Mesin Kata*/

#include "tipe_04.h"
#include "mesinkar_04.h"
#include "mesinkata_04.h"
#include <stdio.h>
#include <string.h>

Kata CKata;
bool EndKata = false;
int CountKata = 0;
int CountKataPjg = 0;
char CC;

/* ***** Primitif-Primitif Mesin Kata ***** */
void Ignore_Blank(char a, char b)
/* Mengabaikan satu atau beberapa BLANK */
/* I.S. : CC sembarang */
/* F.S. : CC ≠ BLANK atau CC = MARK */
{
	//KAMUS
	//ALGORITMA
	while(!(EOP()) && (CC==a || CC==b)){
		ADV();
	}
}

void STARTKATA(char file[30], char a, char b)
/* I.S. : CC sembarang */
/* F.S. : EndKata = true, dan CC = Mark; */
/* atau EndKata = false, CKata adalah kata yang sudah diakuisisi, CC karakter pertama sesudah karakter terakhir kata */
{
	//KAMUS
	//ALGORITMA
	START(file);
	Ignore_Blank(a,b);
}

void ADVKATA(char a, char b)
/* I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir dari kata yg sudah diakuisisi */
/* F.S. : Jika CC = MARK, maka EndKata = true atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi; 
 * CC karakter pertama sesudah karakter terakhir kata */
{
	//KAMUS
	//ALGORITMA
	SalinKata(a, b);
	//printf("-%s-\n", CKata.TabKata);
	Ignore_Blank(a, b);
	if (EOP()){
		EndKata = true;
	}
}

void SalinKata(char a, char b)
/* Mengakuisisi kata, menyimpan dalam CKata */
/* I.S. : CC adalah karakter pertama dari kata */
/* F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi NMax, sisa "kata" dibuang; 
 * CC = BLANK atau CC = MARK; CC adalah karakter sesudah karakter terakhir yang diakuisisi */
{
	//KAMUS
	int i = 0;
	//ALGORITMA
	memset(CKata.TabKata, 0, 256);
	do{
		CKata.TabKata[i] = CC;
		ADV();
		if (!EOP() && CC!=a && CC!=b){
			i++;
		}
	}while(!EOP() && CC!=a && CC!=b);
	CKata.Length = i+1;
}