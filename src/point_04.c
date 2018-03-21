/* Nomor Kelompok : 04*/
/* Nama file      : point_04.c*/
/* Deskripsi      : ADT Point body Implementasi posisi dalam representasi Point*/

#include "point_04.h"
#include <stdio.h>
#include "tipe_04.h"
#include <conio.h>
#include "console_04.h"
#include <Windows.h>


Point makePOINT (int x, int y, int pos) 
//Membentuk sebuah POINT dari komponen-komponennya 
{
	//Kamus Lokal
	Point P;
	//Algoritma
	P.x= x;
	P.y= y;
	P.pos= pos;
	return P;
	}

int getAbsis(Point P) 
//Mengirimkan komponen Absis dari POINT 
{
	return P.x;
	}
int getOrdinat(Point P) 
//Mengirimkan komponen Ordinat dari POINT P
{
	return P.y;
	}

int getMap(Point P)
//Mengirimkan peta ke berapa dari koordinat P
{
	return P.pos;
}


bool isInMap(Point P)
//Mengirimkan true jika didalam jangakauan map dan false ketika keluar map
{
	//Kamus Lokal

	//ALgoritma
	if((getAbsis(P)<1)||(getAbsis(P)>10)||(getOrdinat(P)<1)||(getOrdinat(P)>10)){
		return false;
	}else{
		return true;
	}
}
void move(Point *P, int ch1)
//I.S. Posisi berada disalah satu koordinat dimap
//F.S. Posisi berpindah 1 petak
//Proses: Terjadi penambahan atau pengurangan disalah
{
	//Kamus Lokal
	int ch2 = 0;
	Point temp;
	//Algoritma Utama
	//ch1 = getch();
	if (ch1 == 0xE0) { // a scroll key was pressed 
            ch2 = getch(); // determine what it was 
            switch(ch2)   { 
                  case LEFTARROW: 
                  	{//Bergerak kearah kiri
                  		(temp)=makePOINT(getAbsis(*P)-1,getOrdinat(*P),getMap(*P));
                  		if (isInMap(temp)){
                  			(*P)= temp;
                  		}
                  		else{
                  			char stringConsole[]="Can't move! Try Another direction!\n";
                  			printf("\n");
                                    PrintC(stringConsole, strlen(stringConsole));
                                    getch();
                  		}
                  	}
                  break; 
                  case RIGHTARROW: 
                  	{ //bergerak ke kanan
                  		temp=makePOINT(getAbsis(*P)+1,getOrdinat(*P),getMap(*P));
                  		if (isInMap(temp)){
                  			(*P)= temp;
                  		}
                  		else{
                  			char stringConsole[]="Can't move! Try Another direction!\n";
                  			printf("\n");
                                    PrintC(stringConsole, strlen(stringConsole));
                                    getch();
                  			}
                  	}
                  	break; 
                  case DOWNARROW: 
                  	{//bergerak ke bawah
                  		(temp)=makePOINT(getAbsis(*P),getOrdinat(*P)-1,getMap(*P));
                  		if (isInMap(temp)){
                  			(*P)= temp;
                  		}
                  		else{
                  			char stringConsole[]="Can't move! Try Another direction!\n";
                  			printf("\n");
                                    PrintC(stringConsole, strlen(stringConsole));
                                    getch();
                  		}
                  	}
                  break; 
                  case UPARROW: 
                        {//bergerak ke atas
                  		(temp)=makePOINT(getAbsis(*P),getOrdinat(*P)+1,getMap(*P));
                              if (isInMap(temp)){
                  			(*P)= temp;
                              }
                              else{
                  			char stringConsole[]="Can't move! Try Another direction!\n";
                  			printf("\n");
                                    PrintC(stringConsole, strlen(stringConsole));
                                    getch();
                              }
                        } 
                  break; 
                  default: {
                              char stringConsole[]="Wrong input! Use arrow!\n"; 
                              printf("\n");
                              PrintC(stringConsole, strlen(stringConsole));
                              getch();
                        }
                  	break; 
            } 
      } 
}

void ChangePos(Point*P, int x, int y, int pos)
//I.S P sembarang
//F.S nilai P ditukar dengan nilai x,y dan pos terbentuk posisi baru.
{
	//Kamuslokal
      //algoritma
      (*P).x=x;
	(*P).y=y;
	(*P).pos= pos;		
}