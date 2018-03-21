/* Nomor Kelompok	: 04*/
/* Nama file 		: support_04.c*/
/* Deskripsi 		: Berisi implementasi fungsi dan prosedur yang mendukung proses battle maupun game keseluruhan*/
#include "tipe_04.h"
#include "queue_04.h"
#include "support_04.h"
#include "stack_04.h"
#include "battle_04.h"
#include <stdio.h>
#include <time.h>

 Character Player;
 Queue WildPokemon;
 Level lvl[MaxLevel+1];

bool IsLevelUp(){
	if (Player.level>=10){
		return false;
	} else if(Player.level==9){
		Level RangeLevel;
		RangeLevel = lvl[Player.level+1];
		if(Player.exp >= RangeLevel.min) {
			return true;
		} else{
			return false;
		}
	}else{
		Level RangeLevel;
		RangeLevel = lvl[Player.level+1];
		if((Player.exp >= RangeLevel.min) && (Player.exp <= RangeLevel.max)){
			return true;
		}else{
			return false;
		}	
	}

}

void RandWildPoke()
//I.S.	Queue pokemon liar terdefinisi dan tidak kosong. Player ada di area bush/tall grass//
//F.S.	Persentase pokemon liar muncul 50%, dengan urutan muncul urut sesuai Queue Pokemon liar. Load menu battle dengan pokemon liar//
{
	//kamus//
	Pokemon enemy;
	int r;
	//algoritma//
	srand(time(NULL));
	r = rand() % 2 + 0;   //random int between 0 and 1
	if (r==1){       //if 1 then load battle scene vs wild pokemon (head) in the queue
		system("cls");
		Pop(&Player.pokemon_list,&Player.pokemon_now);
		Del(&WildPokemon, &enemy);
		Battle(enemy);
		Add(&WildPokemon, enemy);
	}
	if(IsLevelUp()){
		Player.level++;
	} 
}	
int GetRandEXP(Range Exp)
//I.S.	EXP Range pokemon liar yang dikalahkan terdefinisi. Current EXP pemain terdefinisi.//
//F.S.	Exp pemain bertambah sebesar nilai random dalam EXP range pokemon yang//
//dikalahkan setelah menang //
{ 
	//kamus lokal//
	int expget;
	//algoritma//
	srand(time(NULL));
	expget =  rand() % (Exp.max-Exp.min+1) + Exp.min; //dapat min exp range+angka random selisih dari max&min
	return expget;
	
}
int GetRandMoney(Range Money)
//I.S.	Money Range pokemon liar yang dikalahkan terdefinisi. Current money pemain (PlayerMoney) terdefinisi//
//F.S.	Money pemain bertambah sebesar nilai random dalam money range pokemon yang//
//dikalahkan setelah menang //
{ 
	//kamus lokal//
	int moneyget;
	//algoritma//
	srand(time(NULL));
	moneyget = rand() % (Money.max-Money.min+1) + Money.min;  //dapat min money range+angka random selisih dari max&min
	return moneyget;
}