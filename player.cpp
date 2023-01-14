#include "player.h"

void createListPlayer(listPlayer &LP)
{
    /*Membuat list player kosong*/
    firstPlayer(LP) = nil;
};

infotypePlayer createPlayer()
{
    /*Meminta input data player dan mengembalikan dalam tipe data infotypePlayer*/
    infotypePlayer newPlayer;
    int idPlayer;
    string usernamePlayer;
    int levelPlayer;

    cout << "Player ID          : ";
    cin >> idPlayer;
    cout << "Player Username    : ";
    cin >> usernamePlayer;
    cout << "Player Level       : ";
    cin >> levelPlayer;

    newPlayer.idPlayer = idPlayer;
    newPlayer.usernamePlayer = usernamePlayer;
    newPlayer.levelPlayer = levelPlayer;

    return newPlayer;
};

adrPlayer createElemenPlayer(infotypePlayer dataPlayer)
{
    /*Mengalokasi data player dengan tipe infotypePlayer menjadi adrPlayer*/
    adrPlayer newPlayer;
    newPlayer = new elmPlayer;
    infoPlayer(newPlayer) = dataPlayer;
    nextPlayer(newPlayer) = nil;
    playerGuild(newPlayer) = nil;
    return newPlayer;
};

void addFirstPlayer(listPlayer &LP, adrPlayer dataPlayer)
{
    /*Menambahkan Player di awal list player*/
    /*Jika list Player nil*/
    if (firstPlayer(LP) == nil)
    {
        firstPlayer(LP) = dataPlayer;
    }
    /*Jika list Player sudah memiliki 1 atau lebih elemen*/
    else
    {
        nextPlayer(dataPlayer) = firstPlayer(LP);
        firstPlayer(LP) = dataPlayer;
    }
};

void addLastPlayer(listPlayer &LP, adrPlayer dataPlayer)
{
    /*Menambahkan Player di akhir list Player*/
    /*Jika list Player nil*/
    if (firstPlayer(LP) == nil)
    {
        firstPlayer(LP) = dataPlayer;
    }
    /*Jika list Player sudah memiliki 1 atau lebih elemen*/
    else
    {
        adrPlayer Q = firstPlayer(LP);
        while (nextPlayer(Q) != nil)
        {
            Q = nextPlayer(Q);
        }
        nextPlayer(Q) = dataPlayer;
    }
};

adrPlayer findPlayerY(listPlayer LP, string usernamePlayer)
{
    /*Mencari Player Y pada list Player berdasarkan usernamePlayer*/
    adrPlayer Q = firstPlayer(LP);
    /*Melakukan iterasi hingga elemen pada saat itu bernilai nil*/
    /*Jika selama melakukan iterasi username player Q sama dengan username player yang dicari akan direturn adrPlayer dari player Q, apabila hingga akhir iterasi tidak ditemukan akan mengreturn nilai nil*/
    while (Q != nil)
    {
        if (infoPlayer(Q).usernamePlayer == usernamePlayer)
        {
            return Q;
        }
        Q = nextPlayer(Q);
    }
    return nil;
};

void showAllPlayer(listPlayer LP)
{
    /*Menampilkan data seluruh player dari list palyer*/
    adrPlayer Q = firstPlayer(LP);
    /*Jika list player kosong*/
    if (firstPlayer(LP) == nil)
    {
        cout << "List Player Kosong" << endl;
        cout << ">>======================================================<<" << endl;
    }
    /*Jika list player memiliki 1 atau lebih elemen player*/
    /*Akan dilakukan iterasi hingga nilai pada saat itu adalah nil dan akan mengeprint setiap data pada saat itu*/
    else
    {
        while (Q != nil)
        {
            cout << "Player ID          :" << infoPlayer(Q).idPlayer << endl;
            cout << "Player Username    :" << infoPlayer(Q).usernamePlayer << endl;
            cout << "Player Level       :" << infoPlayer(Q).levelPlayer << endl;
            cout << ">>======================================================<<" << endl;
            Q = nextPlayer(Q);
        }
    }
};

void deleteFirstPlayer(listPlayer &LP, adrPlayer &P)
{
    /*Menghapus data player pertama dari list player dan data player yang dihapus di simpan pada P*/
    /*Jika list player kosong*/
    if (firstPlayer(LP) == nil)
    {
        cout << "List Player Kosong, Tidak Dapat Melakukan Delete" << endl;
        cout << ">>======================================================<<" << endl;
    }
    /*Jika list player hanya memiliki 1 elemen player*/
    else if (nextPlayer(firstPlayer(LP)) == nil)
    {
        P = firstPlayer(LP);
        firstPlayer(LP) = nil;
    }
    /*Jika list player memiliki lebih dari 1 elemen*/
    else
    {
        P = firstPlayer(LP);
        firstPlayer(LP) = nextPlayer(P);
        nextPlayer(P) = nil;
    }
};

void deletelastPlayer(listPlayer &LP, adrPlayer &P)
{
    /*Menghapus data terakhir palyer dari list player dan data player yang dihapus di simpan pada P*/
    /*Jika list player kosong*/
    if (firstPlayer(LP) == nil)
    {
        cout << "List Player Kosong, Tidak Dapat Melakukan Delete" << endl;
        cout << ">>======================================================<<" << endl;
    }
    /*Jika list player hanya memiliki 1 elemen saja*/
    else if (nextPlayer(firstPlayer(LP)) == nil)
    {
        P = firstPlayer(LP);
        firstPlayer(LP) = nil;
    }
    /*Jika list player memiliki lebih dari 1 elemen*/
    else
    {
        adrPlayer Q = firstPlayer(LP);
        P = firstPlayer(LP);
        while (nextPlayer(P) != nil)
        {
            Q = P;
            P = nextPlayer(Q);
        }
        nextPlayer(Q) = nil;
    }
};

void deleteAfterPlayer(listPlayer &LP, adrPlayer prec, adrPlayer &P)
{
    /*Menghapus data player setelah data player prec dari list dan data player yang dihapus di simpan pada P*/
    P = nextPlayer(prec);
    nextPlayer(prec) = nextPlayer(P);
    nextPlayer(P) = nil;
};
void deleteGuildX(listGuild &LG,listPlayer &LP, adrGuild &P, string namaGuild)
{
    /* Menghapus Guild dari listGuild */
    adrGuild target = findGuildX(LG, namaGuild);
    adrGuild terakhir = firstGuild(LG);
    adrPlayer player = firstPlayer(LP);
    /*Memutus / meremove player dari guild yang ingin di hapus terlebih dahulu*/
    while (player != nil){
        if (playerGuild(player) != nil){
            if (infoGuild(playerGuild(player)).namaGuild == namaGuild){
                playerGuild(player) = nil;
            }
        }
        player = nextPlayer(player);
    }



    while (nextGuild(terakhir) != firstGuild(LG))
        {
            terakhir = nextGuild(terakhir);
        }
        /* Jika Guild yang ingin dihapus terdapat pada listGuild */
        if (target != nil)
        {

            /* Jika Guild yang ingin dihapus adalah elemen pertama */
            if (target == firstGuild(LG))
            {
                deleteFirstGuild(LG, P);
                cout << "Delete Guild " << infoGuild(P).namaGuild << " Sukses" << endl;
            }
            /* Jika Guild yang ingin dihapus adalah elemen terakhir */
            else if (target == terakhir)
            {
                deleteLastGuild(LG, P);
                cout << "Delete Guild " << infoGuild(P).namaGuild << " Sukses" << endl;
            }
            /* Jika Guild yang ingin dihapus bukan elemen pertama maupun terakhir (ditengah) */
            else
            {
                adrGuild prec = firstGuild(LG);
                while (nextGuild(prec) != target)
                {
                    prec = nextGuild(prec);
                }
                deleteAfterGuild(LG, P, prec);
                cout << "Delete Guild " << infoGuild(P).namaGuild << " Sukses" << endl;
            }
            cout << ">>======================================================<<" << endl;
        }
        /* Jika Guild yang ingin dihapus tidak terdapat pada litGuild */
        else
        {
            cout << "Nama Guild yang Ingin Dihapus Tidak Ditemukan" << endl;
            cout << ">>======================================================<<" << endl;
        }
}



void addPlayerToGuildX(listPlayer &LP, listGuild &LG, infotypePlayer dataPlayer, string namaGuild)
{
    /*Menambahkan player ke list player dan menambahkan guild untuk player tersebut*/
    /*Mengalokasi data player*/
    adrPlayer elemenPlayer = createElemenPlayer(dataPlayer);
    addLastPlayer(LP, elemenPlayer);

    /*Mencari guild yang ingin dimasuki oleh player tersebyt dan mengecek apakah guild tersebut ada atau tidak*/
    adrGuild foundGuild = findGuildX(LG, namaGuild);
    /*Jika guild tidak ditemukan*/
    if (foundGuild == nil)
    {
        cout << "Guild " << namaGuild << " Tidak Ditemukan Dalam List Guild" << endl;
    }
    /*Jika guild ditemukan, player akan ditambahkan ke guild tersebut*/
    else
    {
        playerGuild(elemenPlayer) = foundGuild;
        infoGuild(playerGuild(elemenPlayer)).jumlahPlayer++;
        cout << "Player Sukses Ditambahkan ke Guild " << infoGuild(playerGuild(elemenPlayer)).namaGuild << endl;
    }
    cout << ">>======================================================<<" << endl;
};

void deletePlayerFromGuildX(listPlayer &LP, adrPlayer &P, string usernamePlayer, string namaGuild)
{
    /*Menghapus player Y dari guild X sehingga player y juga terhapus dari list player*/
    /*Mencari palyer*/
    adrPlayer foundPlayer = findPlayerY(LP, usernamePlayer);
    if ((foundPlayer != nil) && (infoGuild(playerGuild(foundPlayer)).namaGuild == namaGuild))
    {
        if (foundPlayer == firstPlayer(LP))
        {
            deleteFirstPlayer(LP, P);
            infoGuild(playerGuild(foundPlayer)).jumlahPlayer--;
            cout << ">>======================================================<<" << endl;
            cout << "Delete Player Sukses" << endl;
            cout << ">>======================================================<<" << endl;
        }
        else if (nextPlayer(foundPlayer) == nil)
        {
            deletelastPlayer(LP, P);
            infoGuild(playerGuild(foundPlayer)).jumlahPlayer--;
            cout << ">>======================================================<<" << endl;
            cout << "Delete Player Sukses" << endl;
            cout << ">>======================================================<<" << endl;
        }
        else
        {
            adrPlayer prec = firstPlayer(LP);
            while (infoPlayer(nextPlayer(prec)).usernamePlayer != usernamePlayer || prec == nil)
            {
                prec = nextPlayer(prec);
            }

            if (prec == nil)
            {
                cout << ">>======================================================<<" << endl;
                cout << "Data Tidak Ditemukan" << endl;
                cout << ">>======================================================<<" << endl;
            }
            else
            {
                deleteAfterPlayer(LP, prec, P);
                infoGuild(playerGuild(foundPlayer)).jumlahPlayer--;
                cout << ">>======================================================<<" << endl;
                cout << "Delete Player Sukses" << endl;
                cout << ">>======================================================<<" << endl;
            }
        }
    }
    else
    {
        cout << ">>======================================================<<" << endl;
        cout << "Tidak Ada Player Dengan Username " << usernamePlayer << " di Guild " << namaGuild << endl;
        cout << ">>======================================================<<" << endl;
    }
}
void showAllPlayerFromGuildX(listPlayer LP, string namaGuild)
{
    /*Menampilkan semua player dari guild X*/
    adrPlayer P = firstPlayer(LP);
    /*Akan dilakukan iterasi nilai dari P bernilai nil dan akan ditampilkan data dari player dari guild X*/
    while (P != nil)
    {
        if (playerGuild(P) != nil)
        {
            if (infoGuild(playerGuild(P)).namaGuild == namaGuild)
            {
                cout << "Player ID          : " << infoPlayer(P).idPlayer << endl;
                cout << "Player Username    : " << infoPlayer(P).usernamePlayer << endl;
                cout << "Player Level       : " << infoPlayer(P).levelPlayer << endl;
                cout << ">>======================================================<<" << endl;
            }
        }
        P = nextPlayer(P);
    }
};

adrPlayer findPlayerYInGuildX(listPlayer LP, string usernamePlayer, string namaGuild)
{
    /*Mencari Player Y dalam Guild X*/
    adrPlayer foundPlayer = findPlayerY(LP, usernamePlayer);

    /*Dicek apakah player Y ada dalam list player dan apakah player Y memiliki guild jika tidak maka return nil*/
    if ((foundPlayer != nil) && (playerGuild(foundPlayer) != nil))
    {
        /*Dicek apakah guild dari player Y sama dengan guild yang dicari, jika ya return alamat dari player Y*/
        if (infoGuild(playerGuild(foundPlayer)).namaGuild == namaGuild)
        {
            return foundPlayer;
        }
    }
    else
    {
        return nil;
    }

};
void invitePlayerToGuildX(listPlayer &LP, listGuild &LG, string usernamePlayer, string namaGuild)
{
    /*Menambahan guild dari player Y yang belum memiliki guild atau memindahkan player Y dari guild 1 ke guild lain jika diingikan*/
    adrPlayer foundPlayer = findPlayerY(LP, usernamePlayer);
    adrGuild foundGuild = findGuildX(LG, namaGuild);
    char yesOrNo;
    /*Dicek apakah player ada dalam list player*/
    if (foundPlayer != nil)
    {
        /*Dicek apakah player tergabung dalam guild*/
        if (playerGuild(foundPlayer) != nil)
        {
            cout << "Player Masih Tergabung dalam Guild " << infoGuild(playerGuild(foundPlayer)).namaGuild << endl;
            cout << "Ingin Pindahkan Player " << usernamePlayer << " ke Guild " << namaGuild << "? (Y/N) :";
            cin >> yesOrNo;
            cout << ">>======================================================<<" << endl;
            if ((yesOrNo == 'y') || (yesOrNo == 'Y'))
            {
                infoGuild(playerGuild(foundPlayer)).jumlahPlayer--;
                playerGuild(foundPlayer) = foundGuild;
                infoGuild(foundGuild).jumlahPlayer++;
                cout << "Sukses" << endl;
                cout << ">>======================================================<<" << endl;
            }
            else
            {
                cout << "Player Tidak Jadi Dipindahkan" << endl;
                cout << ">>======================================================<<" << endl;
            }
        }
        else
        {
            if (foundGuild != nil)
            {
                playerGuild(foundPlayer) = foundGuild;
                infoGuild(foundGuild).jumlahPlayer++;
                cout << ">>======================================================<<" << endl;
                cout << "Sukses" << endl;
                cout << ">>======================================================<<" << endl;
            }
            else
            {
                cout << "Guild Tidak Ada Dalam List Guild" << endl;
                cout << ">>======================================================<<" << endl;
            }
        }
    }
    else
    {
        cout << "Player Tidak Ada Dalam List Player" << endl;
        cout << ">>======================================================<<" << endl;
    }
};

void removePlayerYFromGuildX(listPlayer &LP, listGuild &LG, string usernamePlayer, string namaGuild)
{
    /*Menghapus player Y dari Guild X, sehingga player Y tidak tergabung dalam guild apa pun*/
    adrPlayer foundPlayer = findPlayerYInGuildX(LP, usernamePlayer, namaGuild);
    adrGuild foundGuild = findGuildX(LG, namaGuild);
    if (foundPlayer != nil)
    {
        if (playerGuild(foundPlayer) != nil)
        {
            infoGuild(foundGuild).jumlahPlayer--;
            playerGuild(foundPlayer) = nil;
            cout << ">>======================================================<<" << endl;
            cout << "Remove Player Sukes" << endl;
            cout << ">>======================================================<<" << endl;
        }
        else
        {
            cout << "Player Tidak Tergabug Dalam Guild Apa Pun" << endl;
            cout << ">>======================================================<<" << endl;
        }
    }
    else
    {
        cout << "Player Tidak Tergabung Dalam Guild " << namaGuild << endl;
        cout << ">>======================================================<<" << endl;
    }
};
void showGuildWithMostPlayer(listGuild LG, listPlayer LP)
{
    if (firstGuild(LG) != nil){
        adrGuild guild = firstGuild(LG);
        int maxx = infoGuild(guild).jumlahPlayer;
        string guildWithMostPlayerName = infoGuild(guild).namaGuild;
        while (nextGuild(guild) != firstGuild(LG))
        {
            if (infoGuild(nextGuild(guild)).jumlahPlayer > maxx)
            {
                maxx = infoGuild(nextGuild(guild)).jumlahPlayer;
                guildWithMostPlayerName = infoGuild(nextGuild(guild)).namaGuild;

            }
            cout << infoGuild(nextGuild(guild)).namaGuild << endl;
            guild = nextGuild(guild);
        }
        showGuildXData(LG, guildWithMostPlayerName);
        showAllPlayerFromGuildX(LP, guildWithMostPlayerName);
    }
    else {
        cout << "List Guild Kosong" << endl;
        cout << ">>======================================================<<" << endl;
    }
};

adrGuild findPlayerYGuild(listPlayer LP, string usernamePlayer)
{
    adrPlayer foundPlayer = findPlayerY(LP, usernamePlayer);
    if (foundPlayer != nil)
    {
        return playerGuild(foundPlayer);
    }
    else
    {
        return nil;
    }
};
