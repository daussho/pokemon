/* Nomor Kelompok	: 04*/
/* Nama file 		: maps_04.c*/
/* Deskripsi 		: ADT header peta dalam representasi matriks*/


#ifndef MAPS_H
#define MAPS_H

#include "tipe_04.h"

void SwitchDot(char*tempPos);
//I.S letak poin sembarang dan terdefinisi
//F.S. Letak poin bertukar

bool IsSwitchMap(char newLoc);
//mengirimkan true NewLoc sama dengan 1/2/3/4 atau 5

Point SearchInMap(char newLoc);
//Mengirimkan lokasi dar char tersebut dalam map

void SwitchMap(char c);
//I.S Is Switch Map true
//F.S  Map ditukar

#endif