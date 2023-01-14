#include "guild.h"

void createListGuild(listGuild &LG)
{
    /*Membuat sebuah list kosong guild*/
    firstGuild(LG) = nil;
}

infotypeGuild createGuild()
{
    /*Meminta input data Guild dan mengembalikan dalam tipe data infotypeGuild*/
    infotypeGuild dataGuild;
    cout << ">>======================================================<<" << endl;
    cout << "Masukkan ID Guild        : ";
    cin >> dataGuild.idGuild;
    cout << "Masukkan Nama Guild      : ";
    cin >> dataGuild.namaGuild;
    cout << "Masukkan Level Guild     : ";
    cin >> dataGuild.levelGuild;
    dataGuild.jumlahPlayer = 0;
    cout << ">>======================================================<<" << endl;
    return dataGuild;
}

adrGuild createElemenGuild(infotypeGuild dataGuild)
{
    /*Mengalokasi data Guild dengan tipe infotypeGuild menjadi adrGuild*/
    adrGuild newGuild = new elmGuild;
    infoGuild(newGuild) = dataGuild;
    nextGuild(newGuild) = nil;
    return newGuild;
}

void addFirstGuild(listGuild &LG, adrGuild dataGuild)
{
    /* Menambahkan elemen dataGuild ke listGuild diurutan pertama listGuild */
    /* Jika listGuild kosong */
    if (firstGuild(LG) == nil)
    {
        firstGuild(LG) = dataGuild;
        nextGuild(dataGuild) = firstGuild(LG);
    }
    /* Jika listGuild terdiri dari 1 atau lebih elemen Guild*/
    else
    {
        nextGuild(dataGuild) = firstGuild(LG);
        adrGuild terakhir = firstGuild(LG);
        while (nextGuild(terakhir) != firstGuild(LG))
        {
            terakhir = nextGuild(terakhir);
        }
        nextGuild(terakhir) = dataGuild;
        firstGuild(LG) = dataGuild;
    }
}
void addLastGuild(listGuild &LG, adrGuild dataGuild)
{
    /* Menambahkan elemen dataGuild ke listGuild diurutan terakhir listGuild */
    /* Jika listGuild kosong */
    if (firstGuild(LG) == nil)
    {
        firstGuild(LG) = dataGuild;
        nextGuild(dataGuild) = firstGuild(LG);
    }
    /* Jika listGuild terdiri 1 atau lebih elemen Guild */
    else
    {
        nextGuild(dataGuild) = firstGuild(LG);
        adrGuild terakhir = firstGuild(LG);
        while (nextGuild(terakhir) != firstGuild(LG))
        {
            terakhir = nextGuild(terakhir);
        }
        nextGuild(terakhir) = dataGuild;
    }
}

void showGuildXData(listGuild LG, string namaGuild)
{
    /* Menampilkan data yang dimiliki elemen Guild */
    adrGuild guildX = findGuildX(LG, namaGuild);
    /* Jika Guild yang ingin ditampilkan datanya tidak ada didalam listGuild */
    if (guildX == nil)
    {
        cout << "Guild " << namaGuild << " Tidak Ada Dalam List Guild" << endl;
        cout << ">>======================================================<<" << endl;
    }
    /* Jika Guild yang ingin ditampilkan datanya ada didalam listGuild */
    else
    {
        cout << "ID Guild      : " << infoGuild(guildX).idGuild << endl;
        cout << "Nama Guild    : " << infoGuild(guildX).namaGuild << endl;
        cout << "Jumlah Player : " << infoGuild(guildX).jumlahPlayer << endl;
        cout << "Level Guild   : " << infoGuild(guildX).levelGuild << endl;
        cout << ">>======================================================<<" << endl;
    }
};


adrGuild findGuildX(listGuild LG, string namaGuild)
{
    /* Mencari elemen Guild berdasarkan string namaGuild */
    adrGuild guildX = firstGuild(LG);
    /* Jika listGuild kosong */
    if (guildX == nil)
    {
        return nil;
    }
    /* Jika listGuild tidak kosong */
    do
    {
        guildX = nextGuild(guildX);
    } while (guildX != firstGuild(LG) && infoGuild(guildX).namaGuild != namaGuild);
    /* Jika setelah dilakukan perulangan namaGuild tidak ada didalam listGuild */
    if (infoGuild(guildX).namaGuild != namaGuild)
    {
        return nil;
    }
    /* Jika setelah dilakukan perulangan namaGuild ada didalam listGuild */
    else
    {
        return guildX;
    }
}

void deleteFirstGuild(listGuild &LG, adrGuild &P)
{
    /* Menghapus elemen Guild pertama pada listGuild */
    /* Jika listGuild kosong*/
    if (firstGuild(LG) == nil)
    {
        cout << "List Guild Kosong" << endl;
    }
    /* Jika listGuild hanya memiliki 1 element Guild*/
    else if (nextGuild(firstGuild(LG)) == firstGuild(LG))
    {
        P = firstGuild(LG);
        nextGuild(P) = nil;
        firstGuild(LG) = nil;
    }
    /* Jika listGuild memiliki lebih dari 1 element guild */
    else
    {
        adrGuild terakhir = firstGuild(LG);
        while (nextGuild(terakhir) != firstGuild(LG))
        {
            terakhir = nextGuild(terakhir);
        }
        P = firstGuild(LG);
        firstGuild(LG) = nextGuild(firstGuild(LG));
        nextGuild(terakhir) = firstGuild(LG);
        nextGuild(P) = nil;
    }
}
void deleteLastGuild(listGuild &LG, adrGuild &P)
{
    /* Menghapus elemen Guild terakhir pada listGuild */
    /* Jika listGuild kosong*/
    if (firstGuild(LG) == nil)
    {
        cout << "List Guild Kosong" << endl;
    }
    /* Jika listGuild hanya memiliki 1 element Guild*/
    else if (nextGuild(firstGuild(LG)) == firstGuild(LG))
    {
        P = firstGuild(LG);
        nextGuild(P) = nil;
        firstGuild(LG) = nil;
    }
    /* Jika listGuild memiliki lebih dari 1 element guild */
    else
    {
        adrGuild sebelumTerakhir = firstGuild(LG);
        while (nextGuild(nextGuild(sebelumTerakhir)) != firstGuild(LG))
        {
            sebelumTerakhir = nextGuild(sebelumTerakhir);
        }
        P = nextGuild(sebelumTerakhir);
        nextGuild(sebelumTerakhir) = firstGuild(LG);
        nextGuild(P) = nil;
    }
}
void deleteAfterGuild(listGuild &LG, adrGuild &P, adrGuild prec)
{
    /* Menghapus elemen Guild yang berada ditengah listGuild */
    P = nextGuild(prec);
    nextGuild(prec) = nextGuild(P);
    nextGuild(P) = nil;
}

void showAllGuild(listGuild LG)
{
    /* Menampilkan seluruh data dari seluruh elemen Guild yang ada pada listGuild */
    adrGuild p = firstGuild(LG);
    /* Jika listGuild kosong */
    if (firstGuild(LG) == nil)
    {
        cout << "List Guild Kosong" << endl;
        cout << ">>======================================================<<" << endl;
    }
    /* Jika listGuild tidak kosong*/
    else
    {
        cout << ">>======================================================<<" << endl;
        do
        {
            showGuildXData(LG, infoGuild(p).namaGuild);
            p = nextGuild(p);
        } while (p != firstGuild(LG));
    }
}
int selectMenu()
{
    int input;
    cout << ">>======================>> MENU <<======================<<" << endl;
    cout << "01. Menambahkan Guild Baru." << endl;
    cout << "02. Menampilkan Data Guild X." << endl;
    cout << "03. Menghapus Guild Tertentu." << endl;
    cout << "04. Mencari Guild X." << endl;
    cout << "05. Menambahkan Player Y ke Guild X." << endl;
    cout << "06. Menghapus Player Y dari Guild X." << endl;
    cout << "07. Menampilkan Semua Player dari Guild X." << endl;
    cout << "08. Mencari Player Y dari Guild X." << endl;
    cout << "09. Menghubungkan Player Y dengan Guild X." << endl;
    cout << "10. Memutus Hubungan Player Y dengan Guild X." << endl;
    cout << "11. Menampilkan Guild dengan Jumlah Player Terbanyak dan Data Player dari Guild Tersebut." << endl;
    cout << "12. Mencari Nama Guild dari Player Y." << endl;
    cout << "00. Exit Menu." << endl;

    // cout << "111. Show All Guild" << endl;
    // cout << "222. Show All Player" << endl;
    cout << ">>======================================================<<" << endl;
    cout << "Masukkan Menu : ";
    cin >> input;
    cout << ">>======================================================<<" << endl;
    return input;
}
