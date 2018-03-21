/* Nomor Kelompok : 04*/
/* Nama file      : stack_04.c*/
/* Deskripsi      : ADT Stack header  ListPokemon Player  dalam Stack*/


#include "tipe_04.h"

void CreateEmpty(Stack*S);
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1..MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */

/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsStackEmpty(Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */


bool IsStackFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ********** Operator Dasar Stack ********* */
void Push(Stack*S, infotype X);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, TOP bertambah 1 */

void Pop(Stack *S,infotype*X);
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void PrintInfoStack(Stack S);
// I.S : S terdefinisi
// F.S : mencetak isi S