/* Nomor Kelompok	: 04*/
/* Nama file 		: list_04.c*/
/* Deskripsi 		: ADT Body implementasi bag LIST LINIER*/

#include "tipe_04.h"
#include "list_04.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <conio.h>

/* *******TEST ListItem KOSONG******** */
bool IsListEmpty(ListItem L)
/* Mengirim true jika ListItem kosong */
{
	// KAMUS
	// ALGORITMA
	return(First(L) == Nil);
}

/* *******PEMBUATAN ListItem KOSONG***** */
void CreateList(ListItem *L)
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */
{
	// KAMUS
	// ALGORITMA
	First(*L) = Nil;
}

/* *****Manajemen Memori******** */
addressItem Alokasi(Item X)
/* mengirimkan addressItem hasil alokasi sebuah elemen */
/* jika alokasi berhasil maka addressItem tidak Nil, dan misalnya */
/* menghasilkan P, maka infoItem(P)=X, nextItem(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
	// KAMUS
	addressItem P;
	//ALGORITMA
	P = (addressItem) malloc (sizeof(ElmtList));
	if(P!=Nil){
		Info(P) = X;
		Next(P) = Nil;
	} else{
		return Nil;
	}
}

void Dealokasi(addressItem *P)
/*I.S : P terdefinisi */
/*F.S : P dikembalikan ke sistem, melakukan dealokasi/pengembalian address Item P */
{
	// KAMUS
	// ALGORITMA
	free(*P);
}

/* *********PENCARIAN SEBUAH ELEMEN ListItem********* */
addressItem SearchNama(ListItem L, char X[25])
/* mencari apakah ada elemen ListItem nama dengan InfoItem(P).name=X */
/* jika ada, mengirimkan addressItem record elemen tersebut */
/* jika tidak ada mengirimkan Nil */
{
	// KAMUS
	addressItem P;
	//ALGORITMA
	P = First(L);
	if(IsListEmpty(L)){
		return Nil;
	} else {
		while(Next(P) != Nil && strcmp(Info(P).name, X) != 0){
			P = Next(P);
		}
		if (strcmp(Info(P).name, X) == 0){
			return P;
		} else {
			return Nil;
		}
	}
}

/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */
/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst(ListItem *L, addressItem P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-addressItem P sebagai elemen pertama */
{
	// KAMUS
	// ALGORITMA
	Next(P) = First(*L);
	First(*L) = P;
}

void InsertAfter(ListItem *L, addressItem P, addressItem Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
	// KAMUS
	// ALGORITMA
	Next(P) = Next(Prec);
	Next(Prec) = P;
}

void InsertLast(ListItem *L, addressItem P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
	// KAMUS
	addressItem Last;
	//ALGORITMA
	Last = First(*L);
	if(IsListEmpty(*L)){
		InsertFirst(L, P);
	} else {
		while(Next(Last) != Nil){
			Last = Next(Last);
		}
		Next(P) = Nil;
		Next(Last) = P;
	}
}

void AddAlfabetis (ListItem *L, addressItem P)
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P dimasukkan ke dalam list sesuai alfabetis nama barang. List mungkin kosong */
{
	// KAMUS
	addressItem Q, Prec;
	// ALGORITMA
	Q = First(*L);
	if(!IsListEmpty(*L)){
		while((strcmp(Info(P).name, Info(Q).name) > 0) && (Next(Q) != Nil)){
			Prec = Q;
			Q = Next(Q);
		}
		if ((strcmp(Info(P).name, Info(Q).name) > 0) && (Next(Q) == Nil)){
			InsertLast(L, P);
		}else if(Q == First(*L)){
			InsertFirst(L, P);
		} else{
			InsertAfter(L, P, Prec);
		}
	} else {
		InsertFirst(L, P);
	}
}

/* *** PENGHAPUSAN SEBUAH ELEMEN *** */
void DeleteItem (ListItem *L, char X[25])
/* I.S. Sembarang */
/* F.S. Jika ada elemen list dengan info(P).name= X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
	// KAMUS
	addressItem P, Q, Prec;
	//ALGORITMA
	P = First(*L);
	Prec = P;
	Q = SearchNama(*L, X);
	if(P == Q){
		First(*L) = Next(P);
	} else{
		while(P != Q){
			Prec = P;
			P = Next(P);
		}
		Next(Prec) = Next(Q);
	}
	Dealokasi(&Q);
}

/* *** FUNGSI/PROSEDUR TAMBAHAN *** */
void UsingItem(ListItem* L,char x[25], Item * itm, addressItem *P)
//I.S Itm sembarang, LIst Item bisa kosong dan tidak ada barang yang dicari didalamnya.
//F.S menghasilkan Item yang bisa digunakan efeknya~
{
	// KAMUS
	int pad;
	int width = 168;
	int length = 15;
	// ALGORITMA
	*P=SearchNama((*L),x);
	if (*P==Nil){
		pad = (length >= width) ? 0 : (width - length) / 2;
		printf("\033[;%dm ", GREY);
		printf("%*.*s%s", pad, pad, " ", "");
		printf("Item not found!\n");
		getch();
	} else {
		if (Info(*P).amount>1){
			Info(*P).amount--;
			*itm = Info(*P);
		}else{
			DeleteItem(L, x);
			*itm = Info(*P);
		}
	}
}


void Printinfo(ListItem L)
/* I.S. ListItem mungkin kosong */
/* F.S. jika ListItem tidak kosong, */
/* semua infoItem yang disimpan pada elemen ListItem diprint */
/* jika ListItem kosong, hanya menulisan "ListItem kosong" */
{
	// KAMUS
	addressItem P;
	int width = 168;
	int length = 60;
	int pad = (length >= width) ? 0 : (width - length) / 2;
	// ALGORITMA
	P = First(L);
	//printf("\033[;%dm ", GREY);
	printf("%*.*s%s", pad, pad, " ", "");
	printf("%-15s %-15s %-15s %-15s\n", "Item Name", "Item Type", "Effect", "Amount");
	if(!IsListEmpty(L)){
		while(P != Nil){
			printf("%*.*s%s", pad, pad, " ", "");
			printf("%-15s %-15s %-15d %-15d\n", Info(P).name, Info(P).type, Info(P).effect, Info(P).amount);
			P = Next(P);
		}
	}
}
