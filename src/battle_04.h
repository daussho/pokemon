/* Nomor Kelompok	: 04*/
/* Nama file 		: battle_04.h*/
/* Deskripsi 		: Header battle pokemon*/


#include "tipe_04.h"

#ifndef BATTLE_H
#define BATTLE_H

bool IsDead(Pokemon P1);
//Mengirim true jika  HP Pokemon sudah 0

bool IsBattleOver(Character Player, Pokemon enemy);
//Mengirimkan hasil true apabila player kehabisan pokemon atau enemy mati

bool IsFlee();
//Mengrimkan true jika hasil random adaalh 1

int TypePoke(Pokemon P1);
//Mengirimkan Nomor dari tipe pokemon

float AttackFactor(Pokemon P1,Pokemon P2);
//Mengirimkan Faktor multiplier berdasarkan Tipe Pokemon


int RandomAttack(Range RangeAttack, float Multiplier);
//Mengirimkan nilai serangan yang random

void PokeAttack(Pokemon P1, Pokemon *P2);
//I.S Dua buah Pokemon dengan HP Bar bukan 0
//F.S HP berkurang
//Proses Pokemon 1 menyerang pokemon 2 dengan randomized algoritm yang mempengaruhi current HP Pokemon yang diserang

bool IsPokeCatch(Item itm, Pokemon P );
//mengirimkan hasil dari catch rate ditamvah pokeball

void UseItem(Item itm,Pokemon *P);
//I.S Sudah berdasarkan apaakh itu potion atau pokeball
//f.s akan digunakan item yang berpengaruh pada pokemon inputan

void Battle(Pokemon enemy);
//I.S. Pemain Bisa mengeluarkan Pokemon dari stack yang terkait dan lawan cuma satu dan itu dari queue
//F.S. Pemain kalah (Stack kosong dan HP current Pokemon 0 atau kurang) atau Pemain Menang(kalau P)
//Proses: Terjadi battle dengan pilihan 3 menu yaitu serang flee dan pakai Item

#endif