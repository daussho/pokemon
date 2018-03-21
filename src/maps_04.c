/* Nomor Kelompok	: 04*/
/* Nama file 		: maps_04.c*/
/* Deskripsi 		: ADT Body Implementasi peta dalam representasi matriks*/

#ifndef MAPS_H
#define MAPS_H

#include "point_04.h"
#include "maps_04.h"
#include "tipe_04.h"

Character Player;
Map Maps;


//*** Kelompok Cetak Map ***
void SwitchDot(char*tempPos)
//I.S letak poin sembarang dan terdefinisi
//F.S. Letak poin bertukar
{
	//kamus lokal
	char temp;
	//Algoritma
	temp= *tempPos;
	*tempPos= Maps[getMap(Player.posisi)][getAbsis(Player.posisi)][getOrdinat(Player.posisi)];
	Maps[getMap(Player.posisi)][getAbsis(Player.posisi)][getOrdinat(Player.posisi)]= temp;
}

bool IsSwitchMap(char newLoc)
//mengirimkan true jika NewLoc sama dengan 1/2/3/atau 4
{
	//kamus lokal
	int i;
	//Algoritma
	i= newLoc-'0';
	if((i<=5)&&(i>0)){
		return true;
	}
	else{
		return false;
	}
}
Point SearchInMap(char newLoc)
//Mengirimkan lokasi dar char tersebut dalam map
{
	//Kamus lokal
	int nextMap;
	int i=1;
	int j=1;
	bool found=false;
	//Algoritma
	//mencari peta baru
	switch(newLoc){
		case '1':{
					if ((Player.posisi.pos)== 1){
						nextMap=3;
					} else{
						nextMap=1;
					}
		}break;
		case '2':{
					if ((Player.posisi.pos)== 1){
						nextMap=2;
					} else{
						nextMap=1;
					}

		}break;
		case '3':{
					if ((Player.posisi.pos)== 4){
						nextMap=2;
					} else{
						nextMap=4;
					}
		}break;
		case '4':{
					if ((Player.posisi.pos)== 2){
						nextMap=4;
					} else{
						nextMap=2;
					}

		}break;
		case '5':{
			if ((Player.posisi.pos)== 4){
						nextMap=3;
					} else{
						nextMap=4;
					}
		}
	}
	//Peta baru sudah ditemukan, mencari dot tempat player akan ditempatkan
	while((!found)&&(j<11)){
		i=1;
		while(i<=10){
			if((Maps[nextMap][i][j])==newLoc){
				Point temp;
				temp.pos=nextMap;
				temp.x=i;
				temp.y=j;
				return temp;
				}
			else{
				i++;
			}
		}
		j++;
	}
}
void SwitchMap(char c)
//I.S Is Switch Map true
//F.S  Map ditukar
{
	Player.posisi=SearchInMap(c);
}

#endif