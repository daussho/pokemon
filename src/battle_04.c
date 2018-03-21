/* Nomor Kelompok	: 04*/
/* Nama file 		: battle_04.c*/
/* Deskripsi 		: Body implementasi battle pokemon*/


#include "tipe_04.h"
#include "battle_04.h"
#include "stack_04.h"
#include "console_04.h"
#include "list_04.h"
#include "support_04.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

//Global Variable
Character Player;
Ability Element;
bool battleOver;
bool playerTurn;

bool IsDead(Pokemon P1)
//Mengirim true jika HP Pokemon sudah 0
{
	return (PokeHPNow(P1) ==0);
}

bool IsBattleOver(Character Player, Pokemon enemy)
//Mengirimkan hasil true apabila player kehabisan pokemon atau enemy mati
{
	if((IsDead(enemy))||((IsStackEmpty(Player.pokemon_list) && IsDead(Player.pokemon_now)))){
		return true;
	}else{
		return false;
	}
}

bool IsFlee()
//Mengrimkan true jika hasil random mengeluarkan 1
{
	int r;
	r = rand() % 2 + 0;
	if(r==1){//kondisi true
		return true;
	}else{
		return false;
	}
}


int TypePoke(Pokemon P1)
//Mengirimkan Nomor dari tipe pokemon
{
	if(strcmp(PokeType(P1),"BUG")==0) 
		return 1;
	else if(strcmp(PokeType(P1),"ELECTRIC")==0)
		return 2;
	else if(strcmp(PokeType(P1),"FIRE")==0) 
		return 3;
	else if(strcmp(PokeType(P1),"GRASS")==0)
		return 4;
	else if(strcmp(PokeType(P1),"POISON")==0) 
		return 5;
	else if(strcmp(PokeType(P1),"PSYCHIC")==0) 
		return 6;
	else if(strcmp(PokeType(P1),"WATER")==0) 
		return 7;
	else return 0;
}

float AttackFactor(Pokemon P1,Pokemon P2)
//Mengirimkan Faktor multiplier berdasarkan Tipe Pokemon
{
	//kamus lokal
	//algoritma
	return Element[TypePoke(P2)][TypePoke(P1)];
}

int RandomAttack(Range RangeAttack, float Multiplier)
//Mengirimkan nilai serangan yang random
{
	//kamus lokal
	int attack;
	int attackmin= round(RangeAttack.min*Multiplier);
	int attackmax= round(RangeAttack.max*Multiplier);
	//algoritma
	attack= (rand() % (attackmax+ 1 - attackmin)) + attackmin;
	return attack;  
}
void PokeAttack(Pokemon P1, Pokemon *P2)
//I.S Dua buah Pokemon dengan HP Bar bukan 0
//F.S HP berkurang
//Proses Pokemon 1 menyerang pokemon 2 dengan randomized algoritm yang mempengaruhi current HP Pokemon yang diserang
{	//kamus lokal
	int attacking;
	//algoritma
	attacking=RandomAttack(P1.attack,AttackFactor(P1,(*P2)));
	printf("\n");
	RataTengah(40);
	if (playerTurn){
		printf("Your ");
	}
	printf("%s attacks %s!\n",PokeName(P1),PokeName(*P2));
	if(AttackFactor(P1,(*P2))==2) {
		RataTengah(40);
		printf("It's super effective!\n");
	} else if(AttackFactor(P1,(*P2))== 0.5){
		RataTengah(40);
		printf("It's not very effective!\n");
	}
	if((PokeHPNow(*P2)-attacking)<=0){//Totalnya kurang dari 0
		PokeHPNow(*P2)=0;
		RataTengah(40);
		printf("It deals %d damage!\n",(attacking-PokeHPNow(*P2)));
		RataTengah(40);
		printf("%s has fainted!\n",PokeName(*P2));
	}else{//kurang dari HP MAX
		PokeHPNow(*P2)= (PokeHPNow(*P2)-attacking);
		RataTengah(40);
		printf("It deals %d damage!\n",attacking);		
	}
}

bool IsPokeCatch(Item itm, Pokemon P )
//mengirimkan hasil dari catch rate ditambah pokeball
{
	//kamus lokal
	int r;
	//Algoritma
	if (IsStackFull(Player.pokemon_list)){
		return false;
	}else{
		if((itm.effect+ PokeCatch(P))>100){
			return true;
		}else{
			r= (rand() % 100 + 0) + 1;
			if (r<= (itm.effect+ PokeCatch(P))){
				return true;
			}else{
				return false;
			}
		}
	}
}


void UseItem(Item itm,Pokemon *P)
//I.S Sudah berdasarkan apaakh itu potion atau pokeball
//f.s akan digunakan item yang berpengaruh pada pokemon inputan
{
	//kamus lokal
	int heal;
	//algoritma
	if(strcmp(itm.type,"potion")==0){//Item Potion 
		system("cls");
		if((PokeHPNow(*P)+(itm.effect))>(PokeHPMax(*P))){//Totalnya lebih dari HP MAX
			heal=(PokeHPMax(*P)-PokeHPNow(*P));
			PokeHPNow(*P)=PokeHPMax(*P);
		}else{//kurang dari HP MAX
			PokeHPNow(*P)= (PokeHPNow(*P)+(itm.effect));
			heal=itm.effect;
		}
		printf("\n");
		RataTengah(22);
		printf("%s", PokeName(Player.pokemon_now));
		PrintHPBar(Player.pokemon_now.hp);
		PrintPokemon(PokeName(Player.pokemon_now));
		printf("\n");	
		RataTengah(14);		
		printf("Restored %d HP",heal);
		getch();
	}else if(strcmp(itm.type,"pokeball")==0){//Item PokeBall
		system("cls");
		PrintPokeBall();
		delay(1000);
		if(IsPokeCatch(itm,*P)){//Jika berhasil
			PokeHPNow(*P)=PokeHPMax(*P);
			Push(&Player.pokemon_list,(*P));
			printf("\n");
			PrintC("Catch Success!\n", 14);
			getch();
			battleOver=true;
		}
		else{//JIka Gagal
			system("COLOR 70");
			system("cls");
			PrintPokemon((*P).name);
			printf("\n");
			PrintC("Catch Failed!\n", 12);
			getch();
		}
	}
}

void Battle(Pokemon enemy)
//I.S. Pemain Bisa mengeluarkan Pokemon dari stack yang terkait dan lawan cuma satu dan itu dari queue
//F.S. Pemain kalah (Stack kosong dan HP current Pokemon 0 atau kurang) atau Pemain Menang(kalau P)
//Proses: Terjadi battle dengan pilihan 3 menu yaitu serang flee dan pakai Item
{
	//Kamus Lokal
	int pil, j, k, ch;
	int expget, moneyget;
	str s, I, c[3];
	Item itm;
	addressItem P;
	// ALGORITMA
	playerTurn = true;
	strcpy(c[0], "Attack");
	strcpy(c[1], "Use Item");
	strcpy(c[2], "Flee");
	battleOver = false;
	PrintPokemon(PokeName(enemy));
	printf("\n");
	RataTengah(30);
	printf("A wild %s appear!",PokeName(enemy));	//Algoritma utama
	getch();
	while(!battleOver){
		system("COLOR 70");
		if (playerTurn){//Giliran pemain
			//Player Turn Cetak Pokemon Player
			battleOver = false;
			if(IsDead(Player.pokemon_now)&&(!IsStackEmpty(Player.pokemon_list))){//ganti pokemon kalau pokemonnya player mati :(
				Pop(&(Player.pokemon_list),&(Player.pokemon_now));
			}
			k = 999;
			do{
				system("cls");
				printf("\n");
				RataTengah(22);
				printf("%s", PokeName(Player.pokemon_now));
				PrintHPBar(Player.pokemon_now.hp);
				PrintPokemon(PokeName(Player.pokemon_now));
				printf("\n");
				for (j=0; j<=2; j++){
					RataTengah(8);
					if(j == (k % 3)){
						printf("> ");
					}
					printf("%s\n", c[j]);
				}
				pil = getch();
				if(pil == 0xE0){
					ch = 0;
					ch = getch(); // determine what it was
						switch(ch){
						case RIGHTARROW : k++; break;
						case LEFTARROW : k--; break;
						case UPARROW : k--; break;
						case DOWNARROW : k++; break;
						default : break;
					}
				}
			}while(pil!=ENTER);

			if((k % 3)==0){//Melakukan serangan 
				PokeAttack(Player.pokemon_now,&enemy);
				playerTurn= !playerTurn;
				getch();
				battleOver=IsBattleOver(Player, enemy);
			}else if((k % 3)==1){//Menggunakan ITem
				//Membaca Inputan
				Printinfo(Player.bag);
				printf("\n");
				PrintC("> ", 20);
				scanf(" %[^\n]%*c", I);
				UsingItem(&Player.bag,I,&itm, &P);
				//mengeluarkan inputan
				if (P!=Nil){
					if(strcmp(itm.type,"potion")==0){ 
						UseItem(itm,&Player.pokemon_now);
					}else if(strcmp(itm.type,"pokeball")==0){
						UseItem(itm,&enemy);
					}
					playerTurn= !playerTurn;
				}
			}else if((k % 3)==2){//Kabur
				battleOver = IsFlee();
				if(!battleOver){
					PrintC("Failed!\n", 8);
					getch();
				}
				playerTurn = !playerTurn;
			}
		}else{//Lawan turn
			battleOver = false;
			system("cls");
			printf("\n");
			RataTengah(22);
			printf("%s", PokeName(enemy));
			PrintHPBar(enemy.hp);
			PrintPokemon(PokeName(enemy));
			PokeAttack(enemy,&Player.pokemon_now);
			playerTurn= !playerTurn;
			battleOver=IsBattleOver(Player, enemy);
			getch();
		}
	}
	if(!IsDead(Player.pokemon_now)){
		Push(&Player.pokemon_list,Player.pokemon_now);
	}
	if(PokeHPNow(enemy)==0){//Menang
		expget = GetRandEXP(enemy.exp);
		moneyget = GetRandMoney(enemy.money);
		Player.exp += expget;
		Player.money += moneyget;
		RataTengah(40);
		printf("Get $%d and %dEXP\n", moneyget, expget);
		getch();
	}
}
