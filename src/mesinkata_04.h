/* Nomor Kelompok	: 04*/
/* Nama file 		: mesinkar_04.h*/
/* Deskripsi 		: ADT Mesin Kata*/

#ifndef mesinkata_h
#define mesinkata_h

#include "tipe_04.h"
#include "mesinkar_04.h"

/* ***** Mesin lain yang dipakai ***** */
/* ***** Konstanta ***** */


/* ***** Primitif-Primitif Mesin Kata ***** */
void Ignore_Blank(char a, char b);
/* Mengabaikan satu atau beberapa BLANK */
/* I.S. : CC sembarang */
/* F.S. : CC ≠ BLANK atau CC = MARK */
void STARTKATA(char file[30], char a, char b);
/* I.S. : CC sembarang */
/* F.S. : EndKata = true, dan CC = Mark; */
/* atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
CC karakter pertama sesudah karakter terakhir kata */
void ADVKATA(char a, char b);
/* I.S. : EndKata = false; CC adalah karakter sesudah karakter terakhir
dari kata yg sudah diakuisisi */
/* F.S. : Jika CC = MARK, maka EndKata = true
atau EndKata = false, CKata adalah kata terakhir yang sudah diakuisisi;
CC karakter pertama sesudah karakter terakhir kata */
void SalinKata(char a, char b);
/* Mengakuisisi kata, menyimpan dalam CKata */
/* I.S. : CC adalah karakter pertama dari kata */
/* F.S. : CKata berisi kata yang sudah diakuisisi, jika karakternya melebihi
NMax, sisa "kata" dibuang; CC = BLANK atau CC = MARK; CC adalah
karakter sesudah karakter terakhir yang diakuisisi */

#endif
