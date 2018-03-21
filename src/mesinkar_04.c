/* Nomor Kelompok	: 04*/
/* Nama file 		: mesinkar_04.c*/
/* Deskripsi 		: ADT Mesin Karakter*/

#include <stdio.h>
#include "tipe_04.h"
#include "mesinkar_04.h"

char CC;

static FILE *FILEKU;
static int retval;

void START(char file[30])
/* I.S. : sembarang */
/* F.S. : CC adalah karakter pertama pita */
/* Jika CC==MARK, EOP menyala (true) */
/* Jika CC!=MARK, EOP padam (false) */
{
	// KAMUS
	// ALGORITMA
	FILEKU = fopen(file, "r");
	retval = fscanf(FILEKU, "%c", &CC);
	//printf("%c", CC);
}

void ADV()
/* I.S. : CC!=MARK */
/* F.S. : CC adalah karakter berikutnya dari CC pada I.S. */
/* Jika CC==MARK, EOP menyala (true) */
{
	// KAMUS
	// ALGORITMA
	retval = fscanf(FILEKU, "%c", &CC);
	if (EOP()){
		fclose(FILEKU);
	}
}

bool EOP()
/* true jika CC == MARK */ 
{
	// KAMUS
	// ALGORITMA
	return(CC == MARK);
}