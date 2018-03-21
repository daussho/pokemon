/* Nomor Kelompok	: 04*/
/* Nama file 		: console_04.c*/
/* Deskripsi 		: Body Implementasi dari perintah console*/

#include "tipe_04.h"
#include "mesinkar_04.h"
#include "mesinkata_04.h"
#include "loadfile_04.h"
#include "list_04.h"
#include "stack_04.h"
#include "console_04.h"
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

char CC;
Kata CKata;
Character Player;
Map Maps;
str Story[20];
Shop_Item Shop[10];
str About[15];
str Guide[50];
Pokemon NewPokemon[4];

void delay(unsigned int mseconds)
//I.S : msecond delay yang akan diberikan dalam mili second
//F.S : diberikan delay
{
	//Kamsu Lokal
	clock_t goal = mseconds + clock();
	//Algoritma
	while (goal > clock());
}

void PrintC(str s, int length)
// I.s : s mungkin kosong
// F.S : printf s dengan rata tengah
{
	// KAMUS
	int pad;
	int width = 168;
	// ALGORITMA
	pad = (length >= width) ? 0 : (width - length) / 2;
	printf("\033[;%dm ", GREY);
	printf("%*.*s%s", pad, pad, " ", s);
}

void RataTengah(int length)
// I.s : x terdefinisi
// F.S : memberikan spasi sebanyak length
{
	// KAMUS
	int width = 168;
	int pad = (length >= width) ? 0 : (width - length) / 2;
	// ALGORITMA
	printf("\033[;%dm ", GREY);
	printf("%*.*s%s", pad, pad, " ", "");
}

void FWelcome()
// I.s : sembarang
// F.S : welcome screen tercetak dengan delay
{
	// KAMUS
	// ALGORITMA
	STARTKATA("include/welcome.txt", '\n', '.');
	while(!EOP()){
		ADVKATA('\n', '.');
		PrintC(CKata.TabKata, CKata.Length);
		printf("\n");
		delay(50);
	}
	LoadMap();
}

void Welcome()
// I.s : sembarang
// F.S : welcome screen tercetak dengan delay
{
	// KAMUS
	// ALGORITMA
	STARTKATA("include/welcome.txt", '\n', '.');
	while(!EOP()){
		ADVKATA('\n', '.');
		PrintC(CKata.TabKata, CKata.Length);
		printf("\n");
	}
	LoadMap();
}

void GameOver()
// I.s : sembarang
// F.S : game over screen tercetak
{
	// KAMUS
	// ALGORITMA
	STARTKATA("include/gameover.txt", '\n', '.');
	while(!EOP()){
		ADVKATA('\n', '.');
		PrintC(CKata.TabKata, CKata.Length);
		printf("\n");
		delay(50);
	}
}
void PrintProf()
//I.S : Sembarang
//F.S : Mencetak gambar profesor
{
	// KAMUS
	int length = 38;
	int width = 168;
	int c;
	// ALGORITMA
	START("sprite/prof.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case '~' : printf("\033[;%dm ", WHITE); break;
			case 'M' : printf("\033[;%dm ", BLACK); break;
			case 'O' : printf("\033[;%dm ", RED); break;
			case '7' : printf("\033[;%dm ", DARKGREY); break;
			case ' ' : printf("\033[;%dm ", GREY); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}

void CreatePlayer()
//I.S : Sembarang
//F.S : membuat character dengan setting default
{
	// KAMUS
	// ALGORITMA
	strcpy(Player.name, "Deden");
	CreateList(&(Player.bag));
	CreateEmpty(&(Player.pokemon_list));
	Player.money = 1000;
	Player.exp = 0;
	Player.level = 1;
	Player.posisi.pos = 1;
	Player.posisi.x = 6;
	Player.posisi.y = 6;
}

void PrintStory()
//I.S : Sembarang
//F.S : Mencetak cerita dengan lebar 70
{
	// KAMUS
	int i, j, k, l;
	int length = 70;
	int c, ch1, ch2;
	int pil;
	char s[2][5];
	// ALGORITMA
	LoadStory();
	PrintProf();
	printf("\n");
	RataTengah(length);
	for(i=1; i<=18; i++){
		j = 0;
		while(Story[i][j] != '\0'){
			if (i == 5 && j == 0){
				for (k=0; k<=strlen(Player.name)-1; k++){
					printf("%c", Player.name[k]);
					delay(10);
				}
			}
			printf("%c", Story[i][j]);
			delay(10);
			j++;
			if (j >= length && j % length == 0){
				printf("\n");
				RataTengah(length);
			}
			if (i == 4 && j == 28){
				printf(" ");
				for (k=0; k<=strlen(Player.name)-1; k++){
					printf("%c", Player.name[k]);
					delay(10);
				}
			}
		}
		getch();
		system("cls");
		PrintProf();
		printf("\n");
		RataTengah(length);
		strcpy(s[0], "Yes");
		strcpy(s[1], "No");
		if (i == 3){
			do{
				ch1 = 0;
				pil = 888;
				system("cls");
				PrintProf();
				printf("\n");
				RataTengah(length);
				printf("> "); scanf(" %[^\n]%*c", Player.name);
				do{
					system("cls");
					PrintProf();
					printf("\n");
					RataTengah(length);
					printf("Are you sure your name is %s?\n", Player.name);
					for(l=0; l<=1; l++){
						RataTengah(length);
						if (l == (pil % 2)){
							printf("> ");
						}
						printf("%s\n", s[l]);
					}
					ch1 = getch();
					if(ch1 == 0xE0){
						ch2 = 0;
						ch2 = getch(); // determine what it was
							switch(ch2){
							case RIGHTARROW : pil++; break;
							case LEFTARROW : pil--; break;
							case UPARROW : pil--; break;
							case DOWNARROW : pil++; break;
							default : break;
						}
					}	
				}while(ch1 != ENTER);
			} while ((pil % 2) != 0);
			system("cls");
			PrintProf();
			printf("\n");
			RataTengah(length);
		}
	}
}

void PrintMap()
//I.S : sembarang
//F.S : Map dicetak sesuai kode warna
{
	// KAMUS
	int length = 60;
	int i ,j, k, m, col, pad;
    char dot;
    // ALGORITMA
    system("cls");
    printf("\n");
	RataTengah(length);
	for(i=1; i<=10; i++){
		for(m=0; m<3;m++){
			for (j = 1; j <=10; j++){ 
				dot=Maps[Player.posisi.pos][i][j];
				for (k = 0; k < 6; k++){	
					switch(dot){
						case 'J':{//Dot bewarna jalan coklat aneh
							col=103;
							
							printf("\033[;%dm ",col);
						
						}break;
						case 'R':{//dot berwarna Rumput hijau muda
							col=102;
							
							printf("\033[;%dm ",col);
												
						}break;
						case 'P':{//dot bewarma merah posisi player
							col=101;
							
							printf("\033[;%dm ",col);
							
						}break;
						case 'S':{//dot bewarna hijau tua semak-semak
							col=42;
							printf("\033[;%dm ",col);
							
						}break;
						case 'M':{//dot bewarna biru tua toko
							col=104;
							printf("\033[;%dm ",col);
							
						}break;
						default:{//dot yang lainnya yang menandakan pindah peta
							col=106;
							printf("\033[;%dm ",col);
							
						}break;
					}
				}
			}
			//printf("\033[0;m ");
			printf("\n");
			RataTengah(length);
		}
		
	}
}

bool IsGameOver()
//I.S : sembarang
//I.S : menghasilkan true jika semua pokemon player mati
{
	// KAMUS
	// ALGORITMA
	return IsStackEmpty(Player.pokemon_list);
}

bool IsGrass(char c)
//I.S : c terdefinisi
//I.S : menghasilkan true c = S
{
	// KAMUS
	// ALGORITMA
	return(c == 'S');
}

bool IsShop(char c)
//I.S : c terdefinisi
//I.S : menghasilkan true c = T
{
	// KAMUS
	// ALGORITMA
	return(c == 'M');
}

void PrintShopKeeper()
//I.S : Sembarang
//F.S : Mencetak sprite shopkeeper
{
	// KAMUS
	int length = 28;
	int c;
	// ALGORITMA
	START("sprite/shop_keeper.txt");
	printf("%c\n", CC);
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'r' : printf("\033[;%dm ", RED); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}

void Shopping()
//I.S : Sembarang
//F.S : Player membeli barang sesuai pilihan
{
	// KAMUS
	int i, n, ch1, ch2;
	int width = 168;
	int length = 33;
	char c = 'Y';
	bool found;
	str itm, brg[20];
	Item I;
	str border = "+--------+-----------+------+------+\n";
	// ALGORITMA
	do{
		system("cls");
		PrintShopKeeper();
		printf("\n");
		RataTengah(40);
		printf("Do you want to buy something? (Y/N) ", 40); scanf(" %c", &c);
		if (c=='Y' || c=='y'){
			system("cls");
			PrintShopKeeper();
			printf("\n");
			//Cetak pilihan barang
			RataTengah(length);
			printf("Money : $%d\n", Player.money);
			RataTengah(length);
			printf("%s", border);
			RataTengah(length);
			printf("|%-8s|%-11s|%-6s|%-6s|\n", "Type", "Name", "Price", "Effect");
			RataTengah(length);
			printf("%s", border);
			RataTengah(length);
			for(i=1; i<=5; i++){
				printf("|%-8s|%-11s|%-6d|%-6d|\n", Shop[i].type, Shop[i].name, Shop[i].price, Shop[i].effect);
				RataTengah(length);
			}
			printf("%s", border);
			RataTengah(40);
			printf("What do you want to buy?\n");

			// Proses beli barang
			i = 1;
			printf("\n");
			RataTengah(40);
			printf("> "); scanf("%s", itm);
			found = false;
			while(!found && i<=5){
				if(strcmp(itm, Shop[i].name) == 0){
					found = true;
					printf("\n");
					RataTengah(40);
					printf("How many %s do you want to buy?\n", itm);
					printf("\n");
					RataTengah(40);
					printf("> "); scanf("%d", &n);
					if(Player.money-(Shop[i].price*n)<0){
						printf("\n");
						RataTengah(40);
						printf("Not enough money\n");
						getch();
					} else{
						Player.money -= Shop[i].price*n;
						if (SearchNama(Player.bag, itm) != Nil){
							(Info(First(Player.bag))).amount += n;
						} else {
							strcpy(I.name, Shop[i].name);
							strcpy(I.type, Shop[i].type);
							I.effect = Shop[i].effect;
							I.amount = n;
							AddAlfabetis(&(Player.bag), Alokasi(I));
						}
					}
				} else {
					i++;
				}
			}
		}
	}while(c != 'N' || c != 'N');
}

void PrintAbout()
//I.S : Sembarang
//F.S : mencetak isi dari about.txt ke layar
{
	//KAMUS
	int i = 0;
	//ALGORITMA
	LoadAbout();
	printf("\n\n");
	do{
		i++;
		RataTengah(strlen(About[i]));
		printf("%s\n", About[i]);
		delay(100);
	}while(i<15);
}

void PrintGuide()
//I.S : Sembarang
//F.S : mencetak isi dari guide.txt ke layar
{
	//KAMUS
	int i = 0;
	//ALGORITMA
	LoadGuide();
	printf("\n\n");
	do{
		if(strlen(Guide[i]) == 1){
			RataTengah(1);
			getch();
			system("cls");
			printf("\n\n");
		}
		i++;
		if (Guide[i][0] == '-'){
			RataTengah(140);
			printf("%s\n", Guide[i]);
			delay(100);
		} else {
			RataTengah(strlen(Guide[i]));
			printf("%s\n", Guide[i]);
			delay(100);
		}
	}while(i<35);
}

void PrintTorchic()
//I.S : Sembarang
//F.S : mencetak sprite torchic
{
	// KAMUS
	int length = 26;
	// ALGORITMA
	START("sprite/torchic.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'r' : printf("\033[;%dm ", RED); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case 'R' : printf("\033[;%dm ", DARKRED); break;
			case 'Y' : printf("\033[;%dm ", YELLOW); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}
void PrintTreecko()
//I.S : Sembarang
//F.S : mencetak sprite trecko
{
	// KAMUS
	int length = 38;
	// ALGORITMA
	START("sprite/treecko.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'g' : printf("\033[;%dm ", GREEN); break;
			case 'G' : printf("\033[;%dm ", DARKGREEN); break;
			case 'Y' : printf("\033[;%dm ", YELLOW); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}
void PrintMudkip()
//I.S : Sembarang
//F.S : mencetak sprite mudkip
{
	// KAMUS
	int length = 38;
	// ALGORITMA
	START("sprite/mudkip.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case 'L' : printf("\033[;%dm ", DARKBLUE); break;
			case 'l' : printf("\033[;%dm ", BLUE); break;
			case 'N' : printf("\033[;%dm ", BROWN); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}

void PrintAlakazam()
//I.S : Sembarang
//F.S : mencetak sprite alakzam
{
	// KAMUS
	int length = 48;
	// ALGORITMA
	START("sprite/alakazam.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case 'N' : printf("\033[;%dm ", BROWN); break;
			case 'Y' : printf("\033[;%dm ", YELLOW); break;
			case 'a' : printf("\033[;%dm ", GREY); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}

void PrintNidoran()
//I.S : Sembarang
//F.S : mencetak sprite nidoran
{
	// KAMUS
	int length = 34;
	// ALGORITMA
	START("sprite/nidoran.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case 'U' : printf("\033[;%dm ", DARKPURPLE); break;
			case 'u' : printf("\033[;%dm ", PURPLE); break;
			case 'L' : printf("\033[;%dm ", DARKBLUE); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}

void PrintPikachu()
//I.S : Sembarang
//F.S : mencetak sprite pikachu
{
	// KAMUS
	int length = 38;
	// ALGORITMA
	START("sprite/pikachu.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case 'A' : printf("\033[;%dm ", DARKGREY); break;
			case 'r' : printf("\033[;%dm ", RED); break;
			case 'Y' : printf("\033[;%dm ", YELLOW); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}

void PrintPinsir()
//I.S : Sembarang
//F.S : mencetak sprite pinsir
{
	// KAMUS
	int length = 40;
	// ALGORITMA
	START("sprite/pinsir.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case 'A' : printf("\033[;%dm ", DARKGREY); break;
			case 'N' : printf("\033[;%dm ", BROWN); break;
			case 'a' : printf("\033[;%dm ", GREY); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}

void PrintHPBar(Range HP)
//I.S : Sembarang
//F.S : HP terdefinisi
{
	//KAMUS
	int length = 22;
	int i, j;
	str border = "+----------------------+";
	//ALGORITMA
	printf("\n");
	RataTengah(length);
	printf("%s\n", border);
	RataTengah(length);
	printf("| ");
	for(i=1; i<=((HP.min*10)/HP.max)*2; i++){
		printf("\033[;%dm ", GREEN);
	}
	for(i; i<=20; i++){
		printf("\033[;%dm ", RED);	
	}
	printf("\033[0;m");
	printf("\033[;%dm ", GREY);
	printf("|\n");
	RataTengah(length);
	printf("%s\n", border);
	RataTengah(length);
	printf("HP : %d\n", HP.min);
}

void PrintPokeBall()
//I.S : Sembarang
//F.S : mencetak sprite pokeball
{
	// KAMUS
	int length = 24;
	// ALGORITMA
	START("sprite/pokeball.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case 'r' : printf("\033[;%dm ", RED); break;
			case 'a' : printf("\033[;%dm ", GREY); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
}

void PrintPlayer()
//I.S : Sembarang
//F.S : mencetak sprite player
{
	// KAMUS
	int length = 28;
	// ALGORITMA
	START("sprite/player.txt");
	printf("\n");
	RataTengah(length);
	while(!EOP()){
		switch (CC){
			case 'W' : printf("\033[;%dm ", GREY); break;
			case 'B' : printf("\033[;%dm ", BLACK); break;
			case 'w' : printf("\033[;%dm ", WHITE); break;
			case 'r' : printf("\033[;%dm ", RED); break;
			case 'Y' : printf("\033[;%dm ", YELLOW); break;
			case 'n' : printf("\033[;%dm ", DARKWHITE); break;
			case 'A' : printf("\033[;%dm ", DARKGREY); break;
			case ' ' : printf(" "); break;
			case '\n' : printf("\n"); RataTengah(length); break;
		}
		ADV();
	}
	printf("\033[0;m");
	printf("\n");
	RataTengah(40);
	printf("Name  : %s\n", Player.name);
	RataTengah(40);
	printf("Money : $%li\n", Player.money);
	RataTengah(40);
	printf("EXP   : %li\n", Player.exp);
	RataTengah(40);
	printf("Level : %d\n", Player.level);
}

void PrintPokemon(str name)
//I.S : name terdefinisi
//F.S : mencetak sprite tergantung name
{
	//KAMUS
	//ALGORITMA
	if(strcmp(name, "Torchic")==0){
		PrintTorchic();
	} else if(strcmp(name, "Treecko")==0){
		PrintTreecko();
	} else if(strcmp(name, "Mudkip")==0){
		PrintMudkip();
	} else if(strcmp(name, "Pikachu")==0){
		PrintPikachu();
	} else if(strcmp(name, "Alakazam")==0){
		PrintAlakazam();
	} else if(strcmp(name, "Pinsir")==0){
		PrintPinsir();
	} else if(strcmp(name, "Nidoran")==0){
		PrintNidoran();
	}
}
void SelectPokemon()
//I.S : Sembarang
//F.S : mencetak sprite pokemon awal dan memilihnya
{
	//KAMUS
	int i = 999;
	int ch1, ch2;
	//ALGORITMA
	LoadPokeNew();
	do{
		system("COLOR 70");
		system("cls");
		if((i % 3)+1 == 1){
			PrintTorchic();
			printf("\n");
			RataTengah(20);
			printf("Name   : %s\n", PokeName(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("Type   : %s\n", PokeType(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("HP     : %d\n", PokeHPMax(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("Attack : %d-%d\n", PokeAtkMin(NewPokemon[(i % 3)+1]), PokeAtkMax(NewPokemon[(i % 3)+1]));
		} else if((i % 3)+1 == 2){
			PrintTreecko();
			printf("\n");
			RataTengah(20);
			printf("Name   : %s\n", PokeName(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("Type   : %s\n", PokeType(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("HP     : %d\n", PokeHPMax(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("Attack : %d-%d\n", PokeAtkMin(NewPokemon[(i % 3)+1]), PokeAtkMax(NewPokemon[(i % 3)+1]));
		} else if((i % 3)+1 == 3){
			PrintMudkip();
			printf("\n");
			RataTengah(20);
			printf("Name   : %s\n", PokeName(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("Type   : %s\n", PokeType(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("HP     : %d\n", PokeHPMax(NewPokemon[(i % 3)+1]));
			RataTengah(20);
			printf("Attack : %d-%d\n", PokeAtkMin(NewPokemon[(i % 3)+1]), PokeAtkMax(NewPokemon[(i % 3)+1]));
		}
		printf("\n");
		
		RataTengah(34);
		printf("Press ENTER to choose this Pokemon.\n");
		RataTengah(40);
		printf("Press any arrow button to change the pokemon.");
		ch1 = getch();
		if (ch1 == ENTER){
			Push(&Player.pokemon_list,NewPokemon[(i % 3)+1]);
		}else if (ch1 == 0xE0){
			ch2 = 0;
			ch2 = getch(); // determine what it was
			switch(ch2){
				case RIGHTARROW : i++; break;
				case LEFTARROW : i--; break;
				case UPARROW : i++; break;
				case DOWNARROW : i--; break;
				default : break;
			}
		}
	} while(ch1!=ENTER);
}

void PrintHighScore()
//I.S : HS terdefinisi
//F.S : Mencetak High score
{
	//KAMUS
	int i;
	//ALGORITMA
	printf("\n\n");
	PrintC("High Score\n\n\n", 10);
	RataTengah(35);
	printf("%-25s %-10s\n", "Name", "Score");
	for (i=1; i<=10; i++){
		RataTengah(35);
		printf("%-25s %-10li\n", HS[i].name, HS[i].score);
	}
}