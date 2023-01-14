#include "guild.h"
#include "player.h"

int main()
{
    /*Deklarasi variabel untuk list player dan membuat list kosong player*/
    listPlayer LP;
    createListPlayer(LP);

    /*Deklarasi variabel untuk list guild dan membuat list kosong guild*/
    listGuild LG;
    adrGuild wadahHapusGuild;
    createListGuild(LG);

    int n, inputMenu;
    char yesOrNo;

    infotypeGuild dataGuild;
    adrGuild dataGuildElm;
    string modeAdd;

    infotypePlayer dataPlayer;
    string namaGuild;

    string namaGuildYangInginDitampilkan;
    string namaGuildYangInginDihapus;
    string namaGuildYangInginDicari;

    adrGuild findGuildResult;
    adrGuild findGuildXResult;
    adrPlayer foundResult;
    string usernamePlayer;
    adrPlayer tempPlayer;

    adrPlayer P;

    inputMenu = selectMenu();
    while (inputMenu != 0)
    {

        switch (inputMenu)
        {
        case 1:
            cout << "Masukkan Jumlah Guild yang Ingin Ditambah : ";
            cin >> n;
            for (int i=0;i<n;i++)
            {
                dataGuild = createGuild();
                dataGuildElm = createElemenGuild(dataGuild);

                cout << "Masukkan Mode Inputan (first/last) : ";
                cin >> modeAdd;
                if (modeAdd == "first")
                {
                    addFirstGuild(LG, dataGuildElm);
                }
                else if (modeAdd == "last")
                {
                    addLastGuild(LG, dataGuildElm);
                }
            }
            cout << ">>======================================================<<" << endl;
            break;
        case 2:
            if (firstGuild(LG) != nil){
                cout << "Masukkan Nama Guild yang Ingin Ditampilkan : ";
                cin >> namaGuildYangInginDitampilkan;
                cout << ">>======================================================<<" << endl;
                showGuildXData(LG, namaGuildYangInginDitampilkan);
            }
            else {
                cout << "List Guild Kosong" << endl;
                cout << ">>======================================================<<" << endl;
            }
            break;
        case 3:
            if (firstGuild(LG) != nil){
                cout << "Masukkan Nama Guild yang Ingin Dihapus : ";
                cin >> namaGuildYangInginDihapus;
                cout << ">>======================================================<<" << endl;
                deleteGuildX(LG, LP, wadahHapusGuild, namaGuildYangInginDihapus);
            }
            else {
                cout << "List Guild Kosong" << endl;
                cout << ">>======================================================<<" << endl;
            }
            break;
        case 4:
            if (firstGuild(LG) != nil){
                cout << "Masukkan Nama Guild yang Ingin Dicari : ";
                cin >> namaGuildYangInginDicari;
                cout << ">>======================================================<<" << endl;
                findGuildXResult = findGuildX(LG, namaGuildYangInginDicari);
                if (findGuildXResult != nil)
                {
                    cout << "Guild " << namaGuildYangInginDicari << " Ada di Dalam List Guild (DITEMUKAN)" << endl;
                }
                else
                {
                    cout << "Guild " << namaGuildYangInginDicari << " Tidak Ada di Dalam List Guild (TIDAK DITEMUKAN)" << endl;
                }
            }
            else {
                cout << "List Guild Kosong" << endl;
            }
            cout << ">>======================================================<<" << endl;
            break;
        case 5:
            dataPlayer = createPlayer();
            cout << ">>======================================================<<" << endl;
            cout << "Masukan Nama Guild yang Ingin Ditambahkan ke Player : ";
            cin >> namaGuild;
            cout << ">>======================================================<<" << endl;
            addPlayerToGuildX(LP, LG, dataPlayer, namaGuild);
            break;
        case 6:
            if (firstPlayer(LP) != nil){
                cout << "Masukkan Username Player yang Ingin Dihapus  : ";
                cin >> usernamePlayer;
                foundResult = findPlayerY(LP, usernamePlayer);
                if (foundResult != nil){
                    if (playerGuild(foundResult) != nil){
                        cout << "Masukkan Nama Guild dari Player              : ";
                        cin >> namaGuild;
                        cout << ">>======================================================<<" << endl;
                        findGuildResult = findGuildX(LG, namaGuild);
                        if (findGuildResult != nil){
                            deletePlayerFromGuildX(LP, tempPlayer, usernamePlayer, namaGuild);
                        }
                        else {
                            cout << ">>======================================================<<" << endl;
                            cout << "Guild " << namaGuild << " Tidak Ada Dalam List Guild" << endl;
                            cout << ">>======================================================<<" << endl;
                        }
                    }else
                    {
                        cout << ">>======================================================<<" << endl;
                        cout << "Player Tidak Tergabung Dalam Guild Apa Pun" << endl;
                        cout << ">>======================================================<<" << endl;
                    }
                }
                else {
                    cout << ">>======================================================<<" << endl;
                    cout << "Player Tidak Ada Dalam List Player" << endl;
                    cout << ">>======================================================<<" << endl;
                }

            }
            else {
                cout << "List Player Kosong" << endl;
                cout << ">>======================================================<<" << endl;
            }
            break;
        case 7:
            if (firstGuild(LG) != nil){
                cout << "Masukan Nama Guild : ";
                cin >> namaGuild;
                cout << ">>======================================================<<" << endl;
                findGuildXResult = findGuildX(LG, namaGuild);
                if (findGuildXResult != nil){
                    if (infoGuild(findGuildXResult).jumlahPlayer != 0){
                        showAllPlayerFromGuildX(LP, namaGuild);
                    }
                    else {
                        cout << "Guild " << namaGuild << " Tidak Memiliki Player" << endl;
                        cout << ">>======================================================<<" << endl;
                    }
                }
                else {
                    cout << "Guild " << namaGuild << " Tidak Ada Dalam List Guild" << endl;
                    cout << ">>======================================================<<" << endl;
                }

            }
            else {
                cout << "List Guild Kosong" << endl;
                cout << ">>======================================================<<" << endl;
            }

            break;
        case 8:
            if (firstPlayer(LP) != nil){
                if (firstGuild(LG) != nil){
                    cout << "Masukan Username Player : ";
                    cin >> usernamePlayer;
                    foundResult = findPlayerY(LP, usernamePlayer);
                    if (foundResult != nil){
                        cout << "Masukan Nama Guild : ";
                        cin >> namaGuild;
                        cout << ">>======================================================<<" << endl;
                        foundResult = findPlayerYInGuildX(LP ,usernamePlayer, namaGuild);
                        if (foundResult == nil)
                        {
                            cout << "Player Tidak Tergabung dalam Guild " << namaGuild << endl;
                            cout << ">>======================================================<<" << endl;
                        }
                        else
                        {
                            cout << "Player " << usernamePlayer << " Ditemukan di Guild" << namaGuild << endl;
                            cout << ">>======================================================<<" << endl;
                        }
                    }
                    else {
                        cout << ">>======================================================<<" << endl;
                        cout << "Player " << usernamePlayer << " Tidak Ada dalam List Player" << endl;
                        cout << ">>======================================================<<" << endl;
                    }
                }
                else {
                    cout << "List Guild Kosong" << endl;
                    cout << ">>======================================================<<" << endl;
                }
            }
            else {
                cout << "List Player Kosong" << endl;
                cout << ">>======================================================<<" << endl;
            }
            break;
        case 9:
            if (firstPlayer(LP) != nil){
                cout << "Masukan Username Player : ";
                cin >> usernamePlayer;
                if (firstGuild(LG) != nil){
                    cout << "Masukan Nama Guild : ";
                    cin >> namaGuild;
                    invitePlayerToGuildX(LP, LG, usernamePlayer, namaGuild);
                }
                else {
                    cout << ">>======================================================<<" << endl;
                    cout << "List Guild Kosong" << endl;
                    cout << ">>======================================================<<" << endl;
                }
            }
            else {
                cout << "List Player Kosong" << endl;
                cout << ">>======================================================<<" << endl;
            }
            break;
        case 10:
            if (firstPlayer(LP) != nil){
                cout << "Masukan Username Player : ";
                cin >> usernamePlayer;
                foundResult = findPlayerY(LP, usernamePlayer);
                if (foundResult != nil){
                    if (playerGuild(foundResult) != nil){
                        cout << "Masukan Nama Guild : ";
                        cin >> namaGuild;
                        removePlayerYFromGuildX(LP, LG, usernamePlayer, namaGuild);
                    }
                    else {
                        cout << ">>======================================================<<" << endl;
                        cout << "Player Tidak Tergabung Dalam Guild Apa Pun" << endl;
                        cout << ">>======================================================<<" << endl;
                    }
                }
                else {
                    cout << "Player Tidak Ada Dalam List Player" << endl;
                    cout << ">>======================================================<<" << endl;
                }
            }
            else {
                cout << "List Player Kosong" << endl;
                cout << ">>======================================================<<" << endl;
            }
            break;
        case 11:
            showGuildWithMostPlayer(LG, LP);
            break;
        case 12:
            cout << "Masukan Username Player : ";
            cin >> usernamePlayer;
            findGuildResult = findPlayerYGuild(LP, usernamePlayer);
            if (findGuildResult == nil)
            {
                cout << "Player Tidak Tergabung Dalam Guild Apa Pun" << endl;
                cout << ">>======================================================<<" << endl;
            }
            else
            {
                cout << "Guild Player " << usernamePlayer<< "adalah" << infoGuild(findGuildResult).namaGuild << endl;
                cout << ">>======================================================<<" << endl;
            }
            break;
        case 111:
            showAllGuild(LG);
            break;
        case 222:
            showAllPlayer(LP);
            break;
        }
        cout << "Kembali ke Menu Utama? (Y/N) : ";
        cin >> yesOrNo;
        system("cls");
        if (yesOrNo == 'y' || yesOrNo == 'Y')
        {
            inputMenu = selectMenu();
        }
        else
        {
            inputMenu = 0;
        }
    }
    cout << ">>=========>> ANDA TELAH KELUAR DARI PROGRAM <<=========<<" << endl;
    cout << ">>======================================================<<" << endl;
    return 0;
}
