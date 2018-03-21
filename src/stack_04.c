/* Nomor Kelompok : 04*/
/* Nama file      : stack_04.c*/
/* Deskripsi      : ADT Stack body Implementasi  ListPokemon Player  dalam Stack*/

#include "stack_04.h"
#include "tipe_04.h"
#include <stdio.h>
/* ********* Prototype ********* */
/* *** Konstruktor/Kreator *** */
void CreateEmpty(Stack*S)
/* I.S. Sembarang */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1..MaxEl */
/* Ciri stack kosong : TOP bernilai Nil */
{
	((*S).TOP)= NilQ;
}	
/* ********* Predikat Untuk test keadaan KOLEKSI ********* */
bool IsStackEmpty(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
	if ((S.TOP)==(NilQ)){
		return true;
	}
	else{
		return false;
	}
}
bool IsStackFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
	if ((S.TOP)==(MaxStack-1)){
		return true;
	}
	else{
		return false;
	}

}
/* ********** Operator Dasar Stack ********* */
void Push(Stack*S, infotype X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru, TOP bertambah 1 */
{
	((*S).TOP)++;
	((*S).T[(*S).TOP])=X;
}
void Pop(Stack *S,infotype*X)
/* Menghapus X dari Stack S. */
/* I.S. S tidak kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
	*X = (*S).T[(*S).TOP];
	(*S).TOP--;
}

void PrintInfoStack(Stack S)
// I.S : S terdefinisi
// F.S : mencetak isi S
{
	// KAMUS
	int i;
	int width = 168;
	int length = 34;
	int pad = (length >= width) ? 0 : (width - length) / 2;
	// ALGORITMA
	printf("%*.*s%s", pad, pad, " ", "");
	printf("%-10s %-10s %-5s %-6s\n", "Name", "Type", "HP", "Attack");
	for (i=S.TOP; i>=1; i--){
		printf("%*.*s%s", pad, pad, " ", "");
		printf("%-10s %-10s %-5d %d-%d\n", PokeName(Player.pokemon_list.T[i]), PokeType(Player.pokemon_list.T[i]), PokeHPNow(Player.pokemon_list.T[i]), PokeAtkMin(Player.pokemon_list.T[i]), PokeAtkMax(Player.pokemon_list.T[i]));
	}
}