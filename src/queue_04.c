/* Nomor Kelompok : 04*/
/* Nama file      : queue_04.c*/
/* Deskripsi      : ADT queue body Implementasi WildPokemon List Pokemon dalam Queue*/


#include "tipe_04.h"
#include "queue_04.h"
#include <stdlib.h>
#include <stdio.h>


/********** Prototype **********/
bool IsQueueEmpty (Queue Q)
/* Mengirim true jika Q kosong: lihat definisi di atas */
{
	return ((HEAD(Q)==NilQ)&& (TAIL(Q)==NilQ));
}
bool IsQueueFull(Queue Q)
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung 8 elemen */
{
	return ((HEAD(Q)==1)&& (TAIL(Q)==7)); 
}
int NBElmt(Queue Q)
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
{
	return(TAIL(Q)-HEAD(Q)+1);
}


/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X)
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika TAIL(Q)=8+1 maka TAIL(Q) diset =1 */
{
	//Kamus Lokal
	address i,j;
	//Algoritma
	if(IsQueueEmpty(*Q)){
		HEAD(*Q)=1;
	} else{
		if(TAIL(*Q)==7){
			i= HEAD(*Q); j=1;
			do{
				*((*Q).T+j)= *((*Q).T+i);
				i++; j++;
			}while(i<=TAIL(*Q));
		}
		TAIL(*Q)= NBElmt(*Q);
		HEAD(*Q)=1;
	}
	TAIL(*Q)++;
	InfoTail(*Q)=X;
}
void Del(Queue * Q, infotype* X)
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = NilQai elemen HEAD pd I.S.,Jika HEAD(Q)=8+1, */
/* HEAD(Q) diset=1; Q mungkin kosong */
{
	*X= InfoHead(*Q);
	if(HEAD(*Q)==TAIL(*Q)){
		HEAD(*Q)= NilQ;
		TAIL(*Q)=NilQ;
	}else{
		HEAD(*Q)++;
	}
}
//Tambahan
