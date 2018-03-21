/* Nomor Kelompok	: 04*/
/* Nama file 		: list_04.c*/
/* Deskripsi 		: ADT Header bag LIST LINIER*/

#ifndef LISTLINIER_H
#define LISTLINIER_H

#include "tipe_04.h"

/* *******TEST ListItem KOSONG******** */
bool IsListEmpty (ListItem L);
/* Mengirim true jika ListItem kosong */

/* *******PEMBUATAN ListItem KOSONG***** */
void CreateList (ListItem *L);
/* I.S. sembarang */
/* F.S. Terbentuk list kosong */

/* *****Manajemen Memori******** */
addressItem Alokasi (Item X);
/* mengirimkan addressItem hasil alokasi sebuah elemen */
/* jika alokasi berhasil maka addressItem tidak Nil, dan misalnya */
/* menghasilkan P, maka infoItem(P)=X, nextItem(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */

void Dealokasi (addressItem *P);
/*I.S : P terdefinisi */
/*F.S : P dikembalikan ke sistem, melakukan dealokasi/pengembalian address Item P */

/* *********PENCARIAN SEBUAH ELEMEN ListItem********* */
addressItem SearchNama(ListItem L, char X[25]);
/* mencari apakah ada elemen ListItem nama dengan InfoItem(P).Nama=X */
/* jika ada, mengirimkan addressItem record elemen tersebut */
/* jika tidak ada mengirimkan Nil */

/* ***************** PRIMITIF BERDASARKAN ALAMAT ***************** */
/* *** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT *** */
void InsertFirst (ListItem *L, addressItem P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. Menambahkan elemen ber-addressItem P sebagai elemen pertama */

void InsertAfter (ListItem *L, addressItem P, addressItem Prec);
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/* P sudah dialokasi */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */

void InsertLast (ListItem *L, addressItem P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */

void AddAlfabetis (ListItem *L, addressItem P);
/* I.S. Sembarang, P sudah dialokasi */
/* F.S. P dimasukkan ke dalam list sesuai alfabetis na ma barang. List mungkin
kosong */

/* *** PENGHAPUSAN SEBUAH ELEMEN *** */
void DeleteItem (ListItem *L, char X[25]);
/* I.S. Sembarang */
/* F.S. Jika ada elemen list dengan info(P).Nama= X */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P) = X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

/* *** FUNGSI/PROSEDUR TAMBAHAN *** */
void UsingItem(ListItem* L,char x[25],Item * itm, addressItem *P);
//I.S Itm sembarang, LIst Item bisa kosong dan tidak ada barang yang dicari didalamnya.
//F.S menghasilkan Item yang bisa digunakan efeknya~
void Printinfo(ListItem L);
/* I.S. ListItem mungkin kosong */
/* F.S. jika ListItem tidak kosong, */
/* semua infoItem yang disimpan pada elemen ListItem diprint */
/* jika ListItem kosong, hanya menulisan "ListItem kosong" */

#endif
