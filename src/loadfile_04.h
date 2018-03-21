/* Nomor Kelompok	: 04*/
/* Nama file 		: loadfile_04.h*/
/* Deskripsi 		: Berisi fungsi dan prosedur yang berkaitan dengan write & load 
					data dari file eksternal dan memindahkannya ke dalam variabel*/

#ifndef loadfile_h
#define loadfile_h

void LoadAbility();
// I.S : Ability tidak terdefinisi
// F.S : Ability berisi data dari ability.txt

void LoadLevel();
// I.S : L tidak terdefinisi
// F.S : L berisi data pemetaan-level.txt

void LoadMap();
// I.S : M tidak terdefinisi
// F.S : M berisi data dari file peta.txt

void LoadPokemon();
// I.S : Poke tidak terdefinisi
// F.S : Poke berisi data dari pokemon.txt dan pokemon-permainan-baru.txt

void LoadPokeNew();
// I.S : Poke tidak terdefinisi
// F.S : Poke berisi data dari pokemon-permainan-baru.txt

void LoadShop();
// I.S : Item tidak terdefinisi
// F.S : Item berisi data dari toko.txt

void LoadStory();
// I.S : Story tidak terdefinisi
// F.S : Story berisi data dari story.txt

void LoadAbout();
// I.S : S sembarang
// F.S : S berisi data dari about.txt

void LoadGuide();
// I.S : S sembarang
// F.S : S berisi data dari guide.txt

void SaveGame(char c);
//I.S.	Sembarang//
//F.S.	Menyimpan data Player, MyPokemon, IsiTas, WildPokemon ke file eksternal//

void LoadGame(char *c);
//I.S.	Sembarang//
//F.S.	Mengembalikan kondisi Pemain, MyPokemon, IsiTas, PokemonLiar ke file eksternal dan membuka map// 
//dengan koordinat point terakhir pemain berada//

void SaveHighScore();
//I.S : Player terdefinisi
//F.S : High score urut berdasarkan EXP

void LoadHighScore();
//I.S : Sembarang
//F.S : HS berisi data dari highscore.txt

#endif