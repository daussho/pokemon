/* Nomor Kelompok	: 04*/
/* Nama file 		: mesinkar_04.h*/
/* Deskripsi 		: ADT Mesin Karakter*/

#ifndef mesinkar_h
#define mesinkar_h

#include "tipe_04.h"

/*******Mesin Karakter dengan asersi dan primitif read*******/

void START(char file[30]);
/* I.S. : sembarang */
/* F.S. : CC adalah karakter pertama pita */
/* Jika CC==MARK, EOP menyala (true) */
/* Jika CC!=MARK, EOP padam (false) */

void ADV();
/* I.S. : CC!=MARK */
/* F.S. : CC adalah karakter berikutnya dari CC pada I.S. */
/* Jika CC==MARK, EOP menyala (true) */

bool EOP();
/* true jika CC == MARK */ 

#endif