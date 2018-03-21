/* Nomor Kelompok	: 04*/
/* Nama file 		: support_04.h*/
/* Deskripsi 		: Berisi header fungsi dan prosedur yang mendukung proses battle maupun game keseluruhan*/

#include <stdlib.h>
#include "tipe_04.h"

#ifndef SUPPORT_H
#define SUPPORT_H

bool IsLevelUp();
//Mengirimkan true jika dalam range level berikutnya

void RandWildPoke();
//I.S.	Queue pokemon liar terdefinisi dan tidak kosong. Player ada di area bush/tall grass//
//F.S.	Persentase pokemon liar muncul 50%, dengan urutan muncul urut sesuai Queue Pokemon liar. Load menu battle dengan pokemon liar//

int GetRandEXP(Range Exp);
//I.S.	EXP Range pokemon liar yang dikalahkan terdefinisi. Current EXP pemain terdefinisi.//
//F.S.	Exp pemain bertambah sebesar nilai random dalam EXP range pokemon yang//
//dikalahkan setelah menang //

int GetRandMoney(Range Money);
//I.S.	Money Range pokemon liar yang dikalahkan terdefinisi. Current money pemain (PlayerMoney) terdefinisi//
//F.S.	Money pemain bertambah sebesar nilai random dalam money range pokemon yang//
//dikalahkan setelah menang //

#endif