/* Nomor Kelompok	: 04*/
/* Nama file 		: console_04.h*/
/* Deskripsi 		: Header dari perintah console*/

#ifndef CONSOLE_H
#define CONSOLE_H

#include "tipe_04.h"

void delay(unsigned int mseconds);
//I.S : msecond delay yang akan diberikan dalam mili second
//F.S : diberikan delay
void PrintC(str s, int length);
// I.s : s mungkin kosong
// F.S : printf s dengan rata tengah

void RataTengah(int length);
// I.s : x terdefinisi
// F.S : memberikan spasi sebanyak length

void FWelcome();
// I.s : sembarang
// F.S : welcome screen tercetak dengan delay

void Welcome();
// I.s : sembarang
// F.S : welcome screen tercetak tanpa delay

void GameOver();
// I.s : sembarang
// F.S : game over screen tercetak

void PrintProf();
//I.S : Sembarang
//F.S : Mencetak gambar profesor

void CreatePlayer();
//I.S : Sembarang
//F.S : membuat character dengan setting default

void PrintStory();
//I.S : Sembarang
//F.S : Mencetak cerita dengan lebar 70

void PrintGuide();
//I.S : Sembarang
//F.S : Mencetak guide dengan lebar 70

void PrintAbout();
//I.S : Sembarang
//F.S : Mencetak about dengan lebar 70

void PrintMap();
//I.S : sembarang
//F.S : Map dicetak sesuai kode warna

bool IsGameOver();
//I.S : sembarang
//I.S : menghasilkan true jika semua pokemon player mati

bool IsGrass(char c);
//I.S : c terdefinisi
//I.S : menghasilkan true c = S

bool IsShop(char c);
//I.S : c terdefinisi
//I.S : menghasilkan true c = T

void Shopping();
//I.S : Sembarang
//F.S : Player membeli barang sesuai pilihan

void PrintAbout();
//I.S : Sembarang
//F.S : mencetak isi dari about.txt ke layar

void PrintGuide();
//I.S : Sembarang
//F.S : mencetak isi dari guide.txt ke layar

void PrintTorchic();
//I.S : Sembarang
//F.S : mencetak sprite torchic

void PrintTreecko();
//I.S : Sembarang
//F.S : mencetak sprite trecko

void PrintMudkip();
//I.S : Sembarang
//F.S : mencetak sprite mudkip

void PrintAlakazam();
//I.S : Sembarang
//F.S : mencetak sprite alakzam

void PrintNidoran();
//I.S : Sembarang
//F.S : mencetak sprite nidoran

void PrintPikachu();
//I.S : Sembarang
//F.S : mencetak sprite pikachu

void PrintPinsir();
//I.S : Sembarang
//F.S : mencetak sprite pinsir

void PrintHPBar(Range HP);
//I.S : HP terdefinisi
//F.S : mencetak HP bar dari pokemon

void PrintPokeBall();
//I.S : Sembarang
//F.S : mencetak sprite pokeball

void PrintPlayer();
//I.S : Sembarang
//F.S : mencetak sprite player

void PrintPokemon(str name);
//I.S : name terdefinisi
//F.S : mencetak sprite tergantung name

void SelectPokemon();
//I.S : Sembarang
//F.S : mencetak sprite pokemon awal dan memilihnya

void PrintHighScore();
//I.S : HS terdefinisi
//F.S : Mencetak High score

#endif