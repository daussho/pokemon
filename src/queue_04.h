/* Nomor Kelompok : 04*/
/* Nama file      : queue_04.c*/
/* Deskripsi      : ADT queue header WildPokemon List Pokemon dalam Queue*/


/* File :queues.h */
/* Deklarasi Queue yang diimplementasi dengan tabel kontigu */
/* HEAD dan TAIL adalah alamat elemen pertama dan terakhir */
/* Kapasitas Queue=MaxEl buah elemen, dan indeks dibuat “sirkuler” */
#ifndef queues_H
#define queues_H
#include "tipe_04.h"

/* Definisi elemen dan address */
typedef int address; /* indeks tabel */
/* Contoh deklarasi variabel bertype Queue : */


/********** Prototype **********/
bool IsQueueEmpty (Queue Q);
/* Mengirim true jika Q kosong: lihat definisi di atas */
bool IsQueueFull(Queue Q);
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung MaxEl elemen */
int NBElmt(Queue Q);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong */
/*** Kreator ***/
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
/*** Primitif Add/Delete ***/
void Add (Queue * Q, infotype X);
/* Proses: Menambahkan X pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" */
/* Jika Tail(Q)=MaxEl+1 maka Tail(Q) diset =1 */
void Del(Queue * Q, infotype* X);
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S.,Jika Head(Q)=MaxEl+1, */
/* Head(Q) diset=1; Q mungkin kosong */

#endif