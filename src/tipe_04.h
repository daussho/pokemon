/* Nomor Kelompok	: 04*/
/* Nama file 		: tipe_04.h*/
/* Deskripsi 		: Berisi tipe bentukan dan konstanta */

#ifndef TIPE_BENTUKAN
#define TIPE_BENTUKAN

// boolean
#ifndef BOOLEAN_H
#define BOOLEAN_H
#define true 1 
#define false 0 
#define bool char 
#endif


// KONSTANTA
#define MARK '.' // Akhir dari sebuah file
#define Nil  NULL  // Nil adalah kosong 
#define MaxCol 10//jumlah kolom dalam Peta
#define MaxRow 10//Maksimal baris dalam peta
#define MaxKata 256 /* jumlah maksimum karakter suatu kata */
#define MaxStack 100 // Nilai maksimum banyaknya elemen stack
#define MaxQueue 7 // Nilai maksimum banyaknya elemen queue
#define MaxLevel 10 // Nilai maksimum level yang bisa dicapai player

// WARNA
#define GREY 7
#define DARKGREY 100
#define WHITE 107
#define DARKWHITE 47
#define RED 101
#define DARKRED 41
#define YELLOW 103
#define BROWN 43
#define BLUE 104
#define DARKBLUE 44
#define GREEN 102
#define DARKGREEN 42
#define PURPLE 105
#define DARKPURPLE 45
#define BLACK 1

// KEYS
#define UPARROW 77
#define DOWNARROW 75
#define LEFTARROW 72
#define RIGHTARROW 80
#define ENTER 13

// ABILITY
#define FIRE 3
#define GRASS 4
#define WATER 7
#define ELECTRIC 2
#define PSYCHIC 6
#define BUG 1
#define POISON 5

// SELEKTOR
#define PokeName(P) (P).name
#define PokeType(P) (P).type
#define PokeHPNow(P) (P).hp.min
#define PokeHPMax(P) (P).hp.max
#define PokeAtkMin(P) (P).attack.min
#define PokeAtkMax(P) (P).attack.max
#define PokeEXPMin(P) (P).exp.min
#define PokeEXPMax(P) (P).exp.max
#define PokeMoneyMin(P) (P).money.min
#define PokeMoneyMax(P) (P).money.max
#define PokeCatch(P) (P).catch

#define HEAD(Q) (Q).HEAD
#define TAIL(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

#define Info(P) (P)->InfoItem
#define Next(P) (P)->NextItem
#define First(L) (L).First
#define NilQ 0
// TIPE BENTUKAN
typedef char str[256];
typedef int address; /* indeks tabel */
typedef int Map[5][MaxRow+1][MaxCol+1];
typedef float Ability[8][8];


typedef struct {
	str TabKata; // Tempat menyimpan kata
	int Length; // Panjang dari TabKata
	}Kata;

typedef struct{
	int pos; // posisi player pada map mana
	int x; // absis player pada map
	int y; // ordinat player pada map
	}Point;

typedef struct{
	long int min; // nilai minimum
	long int max; // nilai maksimum
	}Range;

typedef struct{
	char name[25]; // nama pokemon
	char type[25]; // tipe pokemon
	Range hp; // hp max dan hp saat ini
	Range attack; // range attack pokemon
	Range exp; // exp drop rate pokemon
	Range money; // money drop rate pokemon
	int catch; // catch rate pokemon
	}Pokemon;

typedef struct{
	Pokemon T[MaxStack+1]; /* tabel penyimpan elemen */
	address TOP; /* alamat TOP : elemen puncak */ 
	}Stack;

typedef struct{
	char name[25]; // nama item
	char type[25]; // tipe item
	int effect; // efek item
	int amount; // jumlah item
	}Item;

// Representasi list linear
typedef struct tElmtList *addressItem;
typedef struct tElmtList {
	Item InfoItem;
	addressItem NextItem;
	}ElmtList;
typedef struct{
	addressItem First;
	}ListItem;

typedef struct{
	char name[25]; // nama player
	Pokemon pokemon_now; // pokemon player yang sedang dipakai 
	Stack pokemon_list; // pokemon player
	ListItem bag; // isi tas player
	long int money; // jumlah uang player
	long int exp; // jumlah exp player
	int level; //	 level player
	Point posisi; // posisi player
	}Character;

typedef struct { 
	Pokemon T[MaxQueue+1]; /* tabel penyimpan elemen, tergantung bahasa */
	address HEAD; /* alamat penghapusan */
	address TAIL; /* alamat penambahan */
	}Queue;

typedef struct{
	char type[25]; // tipe item
	char name[25]; // nama item
	int price; // harga item
	int effect; // efek item
	}Shop_Item;

typedef struct{
	int level; // informasi level
	long int min; // min exp untuk level tersebut
	long int max; // max exp untuk level tersebut
	}Level;

typedef Pokemon infotype;

typedef struct{
	char name[25];
	long int score;
	} HighScore;

// VARIABEL GLOBAL
extern Queue WildPokemon;
extern Character Player;
extern Map Maps;
extern Level lvl[MaxLevel+1];
extern Ability Element;
extern Pokemon NewPokemon[4];
extern char CC;
extern Kata CKata; /* kata yang sudah diakuisisi dan akan diproses */
extern bool EndKata; /* penanda akhir akuisisi kata */
extern Shop_Item Shop[10];
extern str stringKonsole;
extern str Story[20];
extern str About[15];
extern str Guide[50];
extern HighScore HS[12];

#endif
