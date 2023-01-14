/*PLAYER AS PARENT*/
/*PLAYER USING SINGLE LINKED LIST*/
#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "guild.h"
using namespace std;

#define infoPlayer(P) (P)->infoPlayer
#define nextPlayer(P) (P)->nextPlayer
#define playerGuild(P) (P)->playerGuild
#define firstPlayer(L) (L).firstPlayer
#define nil NULL

struct player
{
    int idPlayer;
    string usernamePlayer;
    int levelPlayer;
};

typedef player infotypePlayer;
typedef struct elmPlayer *adrPlayer;

struct elmPlayer
{
    infotypePlayer infoPlayer;
    adrPlayer nextPlayer;
    adrGuild playerGuild;
};

struct listPlayer
{
    adrPlayer firstPlayer;
};

void createListPlayer(listPlayer &LP);                                /*Membuat list kosong player*/
infotypePlayer createPlayer();                                        /*Meminta inputan data player*/
adrPlayer createElemenPlayer(infotypePlayer dataPlayer);              /*Mengalokasi data player*/
void addFirstPlayer(listPlayer &LP, adrPlayer dataPlayer);            /*Menambahkan data player pada awal list*/
void addLastPlayer(listPlayer &LP, adrPlayer dataPlayer);             /*Menambhkan data player pada akhir list*/
void showAllPlayer(listPlayer LP);                                    /*Menampilkan data semua player yang ada pada list*/
void deleteFirstPlayer(listPlayer &LP, adrPlayer &P);                 /*Menghapus data player pada awal list*/
void deleteLastPlayer(listPlayer &LP, adrPlayer &P);                  /*Menghapus data player pada akhir list*/
void deleteAfterPlayer(listPlayer &LP, adrPlayer prec, adrPlayer &P); /*Menghapus data player setelah player Y*/
adrPlayer findPlayerY(listPlayer LP, string usernamePlayer);          /*Mencari player Y pada list*/

void deleteGuildX(listGuild &LG, listPlayer &LP, adrGuild &P, string namaGuild);                    /*Menghapus guild X*/
void addPlayerToGuildX(listPlayer &LP, listGuild &LG, infotypePlayer dataPlayer, string namaGuild); // 5 menambahkan player yang belum ada di listPlayer ke guild X
void deletePlayerFromGuildX(listPlayer &LP, adrPlayer &P, string usernamaPlayer, string namaGuild); /*Menghapus player Y dari guild X - (6)*/
void showAllPlayerFromGuildX(listPlayer LP, string namaGuild);                                      /*Menampilkan semua player dari guild X - (7)*/
adrPlayer findPlayerYInGuildX(listPlayer LP, string usernamePlayer, string namaGuild);              /*Mencari player Y dalam guild X - (8)*/
void invitePlayerToGuildX(listPlayer &LP, listGuild &LG, string usernamePlayer, string namaGuild);  /*Menghubungkan player Y pada list yang belum memiliki guild dengan guild X - (9)*/
void removePlayerYFromGuildX(listPlayer &LP, listGuild &LG, string usernamePlayer, string namaGuild);              /*Memutus hubungan player Y pada guild X menjadi tidak memiliki guild - (10)*/
void showGuildWithMostPlayer(listGuild LG, listPlayer LP);                                          /*Menampilkan guild dengan jumlah player terbanyak dan menampilkan semua player dalam guild tersebut - (11)*/
adrGuild findPlayerYGuild(listPlayer LP, string usernamePlayer);                                    /*Mencari nama guild dari player Y - (12)*/

#endif // PLAYER_H_INCLUDED
