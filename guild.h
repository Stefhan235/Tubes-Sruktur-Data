/*GUILD AS CHILD*/
/*GUILD USING CIRCULAR SINGLE LINKED LIST*/
#ifndef GUILD_H_INCLUDED
#define GUILD_H_INCLUDED

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

#define nextGuild(P) (P)->nextGuild
#define infoGuild(P) (P)->infoGuild
#define firstGuild(L) (L).firstGuild
#define nil NULL

struct guild
{
    int idGuild;
    string namaGuild;
    int jumlahPlayer;
    int levelGuild;
};

typedef guild infotypeGuild;
typedef struct elmGuild *adrGuild;

struct elmGuild
{
    infotypeGuild infoGuild;
    adrGuild nextGuild;
};

struct listGuild
{
    adrGuild firstGuild;
};

void createListGuild(listGuild &LG);                              /*Membuat list kosong guild*/
infotypeGuild createGuild();                                      /*Meminta inputan data guild*/
adrGuild createElemenGuild(infotypeGuild dataGuild);              /*Mengalokasi data guild*/
void addFirstGuild(listGuild &LG, adrGuild dataGuild);            /*Menambahkan guild pada awal list*/
void addLastGuild(listGuild &LG, adrGuild dataGuild);             /*Menambahkan guild pada akhir list*/
void showGuildXData(listGuild LG, string namaGuild);              /*Menampilkan data guild X*/

adrGuild findGuildX(listGuild LG, string namaGuild);              /*Mencari guild X dengan mengembalikan alamat dari guild X*/
void deleteFirstGuild(listGuild &LG, adrGuild &P);                /*Menghapus guild pada awal list*/
void deleteLastGuild(listGuild &LG, adrGuild &P);                 /*Menghapus guild pada akhir list*/
void deleteAfterGuild(listGuild &LG, adrGuild &P, adrGuild prec); /*Menghapus guild setelah guild X*/
void showAllGuild(listGuild LG);                                  /*Menampilkan seluruh guild yang ada dalam list*/
int selectMenu();

#endif // GUILD_H_INCLUDED
