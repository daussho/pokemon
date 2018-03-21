/* Nomor Kelompok : 04*/
/* Nama file      : point_04.c*/
/* Deskripsi      : ADT Point header posisi dalam representasi Point*/


#ifndef POINT_H
#define POINT_H

#include "tipe_04.h"
//Definisi ABSTRACT DATA TYPE POINT 

Point makePOINT (int x, int y, int pos) ;
//Membentuk sebuah POINT dari komponen-komponennya 
int getAbsis(Point P); 
//Mengirimkan komponen Absis dari POINT 
int getOrdinat(Point P); 
//Mengirimkan komponen Ordinat dari POINT P
int getMap(Point P);
//Mengirimkan peta ke berapa dari koordinat P
bool isInMap(Point P);
//Mengirimkan true jika P1 > P2. Definisi lebih besar: lebih //“kananatas”dalam bidang kartesian
void move(Point *P, int ch1);
//Menghasilkan operasi pengurangan vector P1-P2
void ChangePos(Point*P, int x, int y, int pos);
//I.S P sembarang
//F.S nilai P ditukar dengan nilai x,y dan pos terbentuk posisi baru.

#endif