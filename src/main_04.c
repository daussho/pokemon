/* Nomor Kelompok	: 04*/
/* Nama file 		: main_04.h*/
/* Deskripsi 		: main driver pokemon*/

#include "tipe_04.h"
#include "point_04.h"
#include "console_04.h"
#include "loadfile_04.h"
#include "maps_04.h"
#include "list_04.h"
#include "battle_04.h"
#include "support_04.h"
#include "stack_04.h"
#include <stdio.h>
#include <windows.h>
#include <conio.h>

Character Player;
Map Maps;
Queue WildPokemon;

int main(){
	// KAMUS
	str s, c[6];
	char tempPos;
	int ch1, ch2, i, k, ch;
	// ALGORITMA
	system("title Pokemon Moonstone v2.3");
	LoadShop();
	LoadAbility();
	LoadLevel();
	LoadPokemon();
	LoadHighScore();
	strcpy(c[0], "New game");
	strcpy(c[1], "Continue");
	strcpy(c[2], "Guide");
	strcpy(c[3], "High Score");
	strcpy(c[4], "About");
	strcpy(c[5], "Exit");
	system("COLOR 70");
	system("cls");
	FWelcome();//Mencetak welcome screen dengan delay
	delay(50);
	do{
		k = 666;
		do{
			ch1 = 0;
			system("cls");
			Welcome();//Mencetak welcome Screen tanpa delay
			printf("\n");
			for (i=0; i<=5; i++){
					RataTengah(10);
					if(i == (k % 6)){
					printf("> ");
				}
				printf("%s\n", c[i]);
			}
			ch1 = getch();
			if(ch1 == 0xE0){
				ch2 = 0;
				ch2 = getch(); // determine what it was
				switch(ch2){
					case RIGHTARROW : k++; break;
					case LEFTARROW : k--; break;
					case UPARROW : k--; break;
					case DOWNARROW : k++; break;
					default : break;
				}
			}
		}while(ch1 != ENTER);
		if((k % 6) == 0 || (k % 6) == 1 ){ //Player memilih New Game atau Continue
			if ((k % 6) == 0){
				tempPos= 'R';
				CreatePlayer();
				system("cls"); 
				PrintStory();
				SelectPokemon();
			}else {
				LoadGame(&tempPos);
				Maps[Player.posisi.pos][Player.posisi.x][Player.posisi.y] = 'P';
				Maps[1][6][6] = 'R';
			}
			
			while(!IsGameOver()){
				system("COLOR 70");
				PrintMap();
				ch = getch();
				if (ch == 'S' || ch == 's'){//Melakukan save
					system("cls");
					SaveGame(tempPos);
					printf("\n\n");
					PrintC("Save success!\n", 15);
					getch();
				} else if (ch == 'C' || ch == 'c'){//Mencetak informasi Character
					system("cls");
					printf("\n\n");
					PrintPlayer();
					getch();
				} else if (ch == 'I' || ch == 'i'){//Mencetak informasi bag
					system("cls");
					printf("\n\n");
					Printinfo(Player.bag);
					getch();
				} else if (ch == 'Z' || ch == 'z'){//Mencetak list pokemon player
					system("cls");
					printf("\n\n");
					PrintInfoStack(Player.pokemon_list);
					getch();
				} else if (ch == 0xE0){
					SwitchDot(&tempPos);
					move(&(Player.posisi), ch);
					SwitchDot(&tempPos);
					if(IsGrass(tempPos)){
						//inisialisasi pertarungan 
						RandWildPoke();
					} else if(IsShop(tempPos)){
						Shopping();
					} else if(IsSwitchMap(tempPos)){
						SwitchDot(&tempPos);
						SwitchMap(Maps[getMap(Player.posisi)][getAbsis(Player.posisi)][getOrdinat(Player.posisi)]);
						SwitchDot(&tempPos);
					}
				} 
			}
			system("cls");
			printf("\n\n");
			GameOver();
			SaveHighScore();//Memperbaharui High Score saat player game over
			getch();
		} else if((k % 6) == 2){//Player memilih menu Guide
			system("cls");
			//print guide//
			PrintGuide();
			RataTengah(1);
			getch();
		} else if((k % 6) == 3){//Player memilih menu High Score
			system("cls");
			LoadHighScore(); 
			//show highscore from txt//
			PrintHighScore();
			RataTengah(1);
			getch();
		} else if((k % 6) == 4){//Player memilih menu About
			system("cls");
			//print about from txt//
			PrintAbout();
			RataTengah(1);
			getch();
		}
	}while((k % 6) != 5);//Game keluar saat player memilih menu exit
	return 0;
}
