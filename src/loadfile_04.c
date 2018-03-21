/* Nomor Kelompok	: 04*/
/* Nama file 		: loadfile_04.c*/
/* Deskripsi 		: Berisi fungsi dan prosedur yang berkaitan dengan write & load 
					data dari file eksternal dan memindahkannya ke dalam variabel*/

#include "tipe_04.h"
#include "loadfile_04.h"
#include "mesinkar_04.h"
#include "mesinkata_04.h"
#include "queue_04.h"
#include "stack_04.h"
#include "list_04.h"
#include <stdio.h>
#include <string.h>

// VARIABEL GLOBAL
char CC;
Kata CKata;
Queue WildPokemon;
Character Player;
Map Maps;
Level lvl[MaxLevel+1];
Ability Element;
Pokemon NewPokemon[4];
Shop_Item Shop[10];
str Story[20];
Ability Element;
str About[15];
str Guide[50];
HighScore HS[12];

long int Pangkat(long int x, int y)
// I.S : x dan y terdefinisi
// F.S : menghasilkan x^y
{
	// KAMUS
	int hasil = 1;
	int i;
	// ALGORITMA
	if(x==0){
		return x;
	} else {
		if(y==0){
			return hasil;
		} else {
			for(i=1; i<=y; i++){
				hasil = hasil * x;
			}
			return hasil;
		}
	}
}

long int StrToInt(Kata S)
// I.S : S bertipe string tidak negatif
// F.S : fungsi bernilai integer dari S
{
	// KAMUS
	int i;
	int x;
	long int hasil = 0;
	// ALGORITMA
	for(i=0; i<=S.Length-1; i++){
		x = S.TabKata[i] - '0';
		hasil += x * Pangkat(10, S.Length-(i+1));
	}
	return hasil;

}

float StrToFloat(str S)
// I.S : S bertipe string tidak negatif
// F.S : fungsi bernilai integer dari S
{
	// KAMUS
	int i = 0;
	int x;
	float y;
	int j = 0;
	float hasil = 0;
	// ALGORITMA
	do{
		j++;
	} while(S[j] != ',' && S[j] != '\0');

	do{
		x = S[i] - '0';
		hasil += x * Pangkat(10, j-(i+1));
		i++;
	}while(S[i] != ',' && S[i] != '\0');

	if(S[i] != '\0'){
		i++;
		j = 1;
		do{
			x = S[i] - '0';
			y = x;
			hasil += y/Pangkat(10, j);
			i++;
			j++;
		}while(S[i] != '\0');		
	}
	return hasil;
}

void LoadAbility()
// I.S : 
// F.S : 
{
	// KAMUS
	int i, j;
	// ALGORITMA
	STARTKATA("include/ability.txt", ' ', '\n');
	for(i=1; i<=7; i++){
		for(j=1; j<=7; j++){
			ADVKATA(' ', '\n');
			Element[i][j] = StrToFloat(CKata.TabKata);
		}
		printf("\n");
	}
}

void LoadLevel()
// I.S : Lvl tidak terdefinisi
// F.S : Lvl berisi data pemetaan-level.txt
{
	// KAMUS
	Kata min, max;
	int i = 1;
	// ALGORITMA
	STARTKATA("include/pemetaan-level.txt", ' ', '\n');
	while(i<=9){
		ADVKATA(' ', '\n');
		lvl[i].level = StrToInt(CKata);
		ADVKATA(' ', '-');
		lvl[i].min = StrToInt(CKata);
		ADVKATA('\n', '-');
		lvl[i].max = StrToInt(CKata);
		i++;
	}
	while (!EOP()){
		ADVKATA(' ', '>');
		lvl[i].level = StrToInt(CKata);
		ADVKATA('>', '\n');
		lvl[i].min = StrToInt(CKata);
		lvl[i].max = 0;
	}
}

void LoadMap()
// I.S : Maps tidak terdefinisi
// F.S : Maps berisi data dari file peta.txt
{
	// KAMUS
	int i;
	int j;
	// ALGORITMA
	STARTKATA("include/peta1.txt", ' ', '\n');
	for(i=1; i<=10; i++){
		for(j=1; j<=10; j++){
			Maps[1][i][j] = CC;
			ADV();
			Ignore_Blank(' ', '\n');
		}
	}

	STARTKATA("include/peta2.txt", ' ', '\n');
	for(i=1; i<=10; i++){
		for(j=1; j<=10; j++){
			Maps[2][i][j] = CC;
			ADV();
			Ignore_Blank(' ', '\n');
		}
	}

	STARTKATA("include/peta3.txt", ' ', '\n');
	for(i=1; i<=10; i++){
		for(j=1; j<=10; j++){
			Maps[3][i][j] = CC;
			ADV();
			Ignore_Blank(' ', '\n');
		}
	}

	STARTKATA("include/peta4.txt", ' ', '\n');
	for(i=1; i<=10; i++){
		for(j=1; j<=10; j++){
			Maps[4][i][j] = CC;
			ADV();
			Ignore_Blank(' ', '\n');
		}
	}
}

void LoadPokemon()
// I.S : Poke tidak terdefinisi
// F.S : Poke berisi data dari pokemon.txt dan pokemon-permainan-baru.txt
{
	// KAMUS
	int i = 1;
	Pokemon P;
	// ALGORITMA
	STARTKATA("include/pokemon.txt", ' ', '\n');
	do{		
		// Mengisi nama pokemon
		ADVKATA(' ', '\n');
		strcpy(PokeName(P), CKata.TabKata);
		// Mengisi tipe pokemon
		ADVKATA(' ', '\n');
		strcpy(PokeType(P), CKata.TabKata);
		// Mengisi max hp dan hp pokemon
		ADVKATA(' ', '\n');
		PokeHPMax(P) = StrToInt(CKata);
		PokeHPNow(P) = PokeHPMax(P);
		// Mengisi range attack pokemon
		ADVKATA(' ', '-');
		PokeAtkMin(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeAtkMax(P) = StrToInt(CKata);
		// Mengisi range EXP drop pokemon
		ADVKATA(' ', '-');
		PokeEXPMin(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeEXPMax(P) = StrToInt(CKata);
		// Mengisi range money drop pokemon
		ADVKATA(' ', '-');
		PokeMoneyMin(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeMoneyMax(P) = StrToInt(CKata);
		// Mengisi range catch rate pokemon
		ADVKATA(' ', '\n');
		PokeCatch(P) = StrToInt(CKata);
		i++;
		Add(&WildPokemon, P);
	}while(!EOP());

	STARTKATA("include/pokemon-permainan-baru.txt", ' ', '\n');
	do{		
		// Mengisi nama pokemon
		ADVKATA(' ', '\n');
		strcpy(PokeName(P), CKata.TabKata);
		// Mengisi tipe pokemon
		ADVKATA(' ', '\n');
		strcpy(PokeType(P), CKata.TabKata);
		// Mengisi max hp dan hp pokemon
		ADVKATA(' ', '\n');
		PokeHPMax(P) = StrToInt(CKata);
		PokeHPNow(P) = PokeHPMax(P);
		// Mengisi range attack pokemon
		ADVKATA(' ', '-');
		PokeAtkMin(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeAtkMax(P) = StrToInt(CKata);
		// Mengisi range EXP drop pokemon
		ADVKATA(' ', '-');
		PokeEXPMin(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeEXPMax(P) = StrToInt(CKata);
		// Mengisi range money drop pokemon
		ADVKATA(' ', '-');
		PokeMoneyMin(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeMoneyMax(P) = StrToInt(CKata);
		// Mengisi range catch rate pokemon
		ADVKATA(' ', '\n');
		PokeCatch(P) = StrToInt(CKata);
		i++;
		Add(&WildPokemon, P);
	}while(!EOP());
	HEAD(WildPokemon)=1;
	TAIL(WildPokemon)=7;
}

void LoadPokeNew()
// I.S : Poke tidak terdefinisi
// F.S : Poke berisi data dari pokemon-permainan-baru.txt
{
	// KAMUS
	int i = 1;
	// ALGORITMA
	STARTKATA("include/pokemon-permainan-baru.txt", ' ', '\n');
	do{		
		// Mengisi nama pokemon
		ADVKATA(' ', '\n');
		strcpy(PokeName(NewPokemon[i]), CKata.TabKata);
		// Mengisi tipe pokemon
		ADVKATA(' ', '\n');
		strcpy(PokeType(NewPokemon[i]), CKata.TabKata);
		// Mengisi max hp dan hp pokemon
		ADVKATA(' ', '\n');
		PokeHPMax(NewPokemon[i]) = StrToInt(CKata);
		PokeHPNow(NewPokemon[i]) = PokeHPMax(NewPokemon[i]);
		// Mengisi range attack pokemon
		ADVKATA(' ', '-');
		PokeAtkMin(NewPokemon[i]) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeAtkMax(NewPokemon[i]) = StrToInt(CKata);
		// Mengisi range EXP drop pokemon
		ADVKATA(' ', '-');
		PokeEXPMin(NewPokemon[i]) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeEXPMax(NewPokemon[i]) = StrToInt(CKata);
		// Mengisi range money drop pokemon
		ADVKATA(' ', '-');
		PokeMoneyMin(NewPokemon[i]) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeMoneyMax(NewPokemon[i]) = StrToInt(CKata);
		// Mengisi range catch rate pokemon
		ADVKATA(' ', '\n');
		PokeCatch(NewPokemon[i]) = StrToInt(CKata);
		i++;
	}while(!EOP());
}

void LoadShop()
// I.S : Item tidak terdefinisi
// F.S : Item berisi data dari toko.txt
{
	// KAMUS
	int i;
	// ALGORITMA
	STARTKATA("include/toko.txt", ' ', '\n');
	for(i=1; i<=5; i++){
		// Mengisi tipe item
		ADVKATA(' ', '\n');
		strcpy(Shop[i].type, CKata.TabKata);
		// Mengisi nama item
		ADVKATA(' ', '\n');
		strcpy(Shop[i].name, CKata.TabKata);
		// Mengisi harga item
		ADVKATA(' ', '\n');
		Shop[i].price = StrToInt(CKata);
		// Mengisi efek item
		ADVKATA(' ', '\n');
		Shop[i].effect = StrToInt(CKata);
	}
}

void LoadStory()
// I.S : Story tidak terdefinisi
// F.S : Story berisi data dari story.txt
{
	// KAMUS
	int i = 0;
	// ALGORITMA
	STARTKATA("include/story.txt", '\n', '.');
	do{
		i++;
		ADVKATA('\n', '.');
		strcpy(Story[i], CKata.TabKata);
	}while(!EOP());
}

void LoadAbout()
// I.S : S sembarang
// F.S : S berisi data dari about.txt
{
	// KAMUS
	int i = 0;
	// ALGORITMA
	STARTKATA("include/about.txt", '\n', '.');
	do{
		i++;
		ADVKATA('\n', '.');
		strcpy(About[i], CKata.TabKata);
	}while(!EOP());
}

void LoadGuide()
// I.S : S sembarang
// F.S : S berisi data dari guide.txt
{
	//KAMUS
	int i = 0;
	//ALGORITMA
	STARTKATA("include/guide.txt", '\n', '.');
	do{
		i++;
		ADVKATA('\n', '.');
		strcpy(Guide[i], CKata.TabKata);
	}while(!EOP());	
}

void SaveGame(char c)
//I.S.	Sembarang//
//F.S.	Menyimpan data Player, MyPokemon, IsiTas, WildPokemon ke file eksternal//
{
	//KAMUS
	FILE *FILEKU;
	Pokemon P;
	Stack S, S2;
	addressItem Q;
	int i;
	//ALGORITMA
	// SAVE DATA PLAYER
	FILEKU = fopen("player/player.txt", "w");
	fprintf(FILEKU, "%s\n", Player.name);
	fprintf(FILEKU, "%li\n", Player.money);
	fprintf(FILEKU, "%li\n", Player.exp);
	fprintf(FILEKU, "%d\n", Player.level);
	fprintf(FILEKU, "%d\n", Player.posisi.pos);
	fprintf(FILEKU, "%d\n", Player.posisi.x);
	fprintf(FILEKU, "%d\n", Player.posisi.y);
	fprintf(FILEKU, "%c\n", c);
	fprintf(FILEKU, ".");
	fclose(FILEKU);
		
	// SAVE DATA POKEMON STACK
	FILEKU = fopen("player/pokemon.txt", "w");
	for(i=1; i<=Player.pokemon_list.TOP; i++){
		fprintf(FILEKU, "%s\n", PokeName(Player.pokemon_list.T[i]));
		fprintf(FILEKU, "%s\n", PokeType(Player.pokemon_list.T[i]));
		fprintf(FILEKU, "%d\n", PokeHPMax(Player.pokemon_list.T[i]));
		fprintf(FILEKU, "%d\n", PokeHPNow(Player.pokemon_list.T[i]));
		fprintf(FILEKU, "%d\n", PokeAtkMax(Player.pokemon_list.T[i]));
		fprintf(FILEKU, "%d\n\n", PokeAtkMin(Player.pokemon_list.T[i]));
	}
	fprintf(FILEKU, ".");
	fclose(FILEKU);
	
	// SAVE DATA ITEM PLAYER
	FILEKU = fopen("player/item.txt", "w");
	Q = First(Player.bag);
	while(Q != Nil){
		fprintf(FILEKU, "%s\n", Info(Q).name);
		fprintf(FILEKU, "%s\n", Info(Q).type);
		fprintf(FILEKU, "%d\n", Info(Q).effect);
		fprintf(FILEKU, "%d\n\n", Info(Q).amount);
		Q = Next(Q);
	}
	fprintf(FILEKU, ".");
	fclose(FILEKU);
	
}

void LoadGame(char *c)
//I.S.	Sembarang//
//F.S.	Mengembalikan kondisi Pemain, MyPokemon, IsiTas, PokemonLiar ke file eksternal dan membuka map// 
//dengan koordinat point terakhir pemain berada//
{
	//KAMUS
	Pokemon P;
	Item I;
	//ALGORITMA
	//LOAD DATA PLAYER
	STARTKATA("player/player.txt", '.', '\n');
	ADVKATA('.', '\n');
	strcpy(Player.name, CKata.TabKata);
	ADVKATA('.', '\n');
	Player.money = StrToInt(CKata);
	ADVKATA('.', '\n');
	Player.exp = StrToInt(CKata);
	ADVKATA('.', '\n');
	Player.level = StrToInt(CKata);
	ADVKATA('.', '\n');
	Player.posisi.pos = StrToInt(CKata);
	ADVKATA('.', '\n');
	Player.posisi.x = StrToInt(CKata);
	ADVKATA('.', '\n');
	Player.posisi.y = StrToInt(CKata);
	ADVKATA('.', '\n');
	*c = CKata.TabKata[0];
	ADVKATA('.', '\n');

	// LOAD DATA POKEMON LIST PLAYER
	STARTKATA("player/pokemon.txt", ' ', '\n');
	while(!EOP()){
		ADVKATA(' ', '\n');
		strcpy(PokeName(P), CKata.TabKata);
		ADVKATA(' ', '\n');
		strcpy(PokeType(P), CKata.TabKata);
		ADVKATA(' ', '\n');
		PokeHPMax(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeHPNow(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeAtkMax(P) = StrToInt(CKata);
		ADVKATA(' ', '\n');
		PokeAtkMin(P) = StrToInt(CKata);
		Push(&Player.pokemon_list, P);
	}

	//LOAD DATA ITEM PLAYER
	STARTKATA("player/item.txt", ' ', '\n');
	while(!EOP()){
		ADVKATA(' ', '\n');
		strcpy(I.name, CKata.TabKata);
		ADVKATA(' ', '\n');
		strcpy(I.type, CKata.TabKata);
		ADVKATA(' ', '\n');
		I.effect = StrToInt(CKata);
		ADVKATA(' ', '\n');
		I.amount = StrToInt(CKata);
		InsertLast(&(Player.bag), Alokasi(I));
	}
}

void SaveHighScore()
//I.S : Player terdefinisi
//F.S : High score urut berdasarkan EXP
{
	// Kamus
	int i, j;
	HighScore temp;
	FILE *FILEKU;
	// Algoritma
	strcpy(HS[11].name, Player.name);
	HS[11].score = Player.exp;
	for(i=1; i<=11; i++){
		for(j=i; j<=11; j++){
			if (HS[i].score < HS[j].score){
				strcpy(temp.name, HS[i].name);
				temp.score = HS[i].score;

				strcpy(HS[i].name, HS[j].name);
				HS[i].score = HS[j].score;

				strcpy(HS[j].name, temp.name);
				HS[j].score = temp.score;
			}
		}		
	}
	FILEKU = fopen("include/highscore.txt", "w");
	for(i=1; i<=10; i++){
		fprintf(FILEKU, "%s\n", HS[i].name);
		fprintf(FILEKU, "%li\n\n", HS[i].score);
	}
	fprintf(FILEKU, ".");
	fclose(FILEKU);
}

void LoadHighScore()
//I.S : Sembarang
//F.S : HS berisi data dari highscore.txt
{
	// KAMUS
	int i = 0;
	// ALGORITMA
	STARTKATA("include/highscore.txt", '.', '\n');
	while(!EOP()){
		i++;
		ADVKATA('.', '\n');
		strcpy(HS[i].name, CKata.TabKata);
		ADVKATA('.', '\n');
		HS[i].score = StrToInt(CKata);
	}
}