#include <stdio.h>
#include <stdlib.h>

// Deklarasi struct data
typedef struct
{
    char nama[50];
    char NPM[15];
    char fak[20];
    float saldo, pinjaman, bulan;
    int idpinjam;
} data;
// Deklarasi struct riwayat
typedef struct
{
    float saldoawal, saldoakhir, jumlah;
    int id, jenis;
} riwayat;
// Prototype function
void welcome();
void input(data *mahasiswa, int jmlmhs);
void display(data *mahasiswa, int jmlmhs);
void transaksi(data *mahasiswa, int i, riwayat *history, int *counter);
void displayriwayat(data *mahasiswa, int *counter, riwayat *history);
void help();
void keluar();
// Main Function
int main(void)
{
    // Deklarasi variabel,pointer serta array
    int choice = 0, jmlmhs = 0, counter, sentinel;
    int *pcounter = &counter;
    data mahasiswa[10];
    riwayat *history;
    *pcounter = 0;
    history = (riwayat *)calloc(1, sizeof(riwayat)); // define memory allocation
    untuk history
    welcome();          // memanggil function welcome
    system("color b0"); // mengubah background display menjadi B0= Latar belakang
    biru tulisan hitam while (choice != 6)
    { // loop menu dan akan exit apabila
        system("color b0");
        // display menu utama
        printf("======================================\n"
               "| |\n"
               "| Aplikasi Koperasi Mahasiswa |\n"
               "| |\n"
               "======================================\n"
               "======================================\n"
               "| Menu Utama: |\n"
               "| |\n"
               "| 1. Tambah Akun |\n"
               "| 2. Transaksi |\n"
               "| 3. Display |\n"
               "| 4. History |\n"
               "| 5. Help |\n"
               "| 6. Exit |\n"
               "======================================\n");
        do
        { // perulangan jika choice < 1 || choice > 6
            printf(" Masukkan Nomor Pada Menu Yang di Pilih : ");
            scanf("%d", &choice); // input choice
            switch (choice)
            {       // pengkondisian choice
            case 1: // pengkondisian jika choice = 1
                do
                { // perulangan sentinel == 1
                    if (jmlmhs >= 10)
                    {                  // pengkondisian jika i (banyak akun) >= 10
                        system("CLS"); // membersihkan layar

                        printf("\a");       // memberikan bunyi warning
                        system("color 40"); // mengubah background display menjadi 40=
                        Latar belakang merah tulisan hitam
                            printf("================================================\n"
                                   "| ERROR |\n"
                                   "| Maksimal Hanya 10 Mahasiswa |\n"
                                   "================================================\n\n");
                        system("pause"); // memberikan delay selama 5 detik

                        break; // keluar dari perulangan
                    }
                    system("CLS");                     // membersihkan layar
                    input(&mahasiswa[jmlmhs], jmlmhs); // memanggil function input
                    jmlmhs++;                          // increment i
                    printf("\n=====================================\n"
                           "| Pilihan : |\n"
                           "| 1. Tambah Akun |\n"
                           "| 0. Kembali Ke Menu |\n"
                           "=====================================\n\n");
                    do
                    { // Perulangan sentinel > 1 || sentinel < 0
                        printf(" Masukkan Pilihan : ");
                        scanf("%d", &sentinel); // Input sentinel

                        if (sentinel > 1 || sentinel < 0)
                        { // pengkondisian sentinel >

                            1 || sentinel < 0 printf("\a"); // memberikan bunyi warning
                            system("color 40");             // mengubah background display menjadi 40= Latar
belakang merah tulisan hitam
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan
masukkan pilihan yang benar ---!\n\n");
Sleep(1000); //memberikan delay selama 1 detik
system("color b0"); //mengubah background display menjadi B0=
Latar belakang biru tulisan hitam
                        }
                    } while (sentinel > 1 || sentinel < 0); // Parameter perulangan
                } while (sentinel == 1);                    // Parameter perulangan
                system("CLS");                              // membersihkan layar display
                break;                                      // keluar dari pengkondisian
            case 2:                                         // pengkondisian jika choice = 2
                if (jmlmhs == 0)
                {                       // pengkondisian jika i = 0 atau tidak ada pengguna
                    system("CLS");      // membersihkan layar display
                    printf("\a");       // memberikan bunyi warning
                    system("color 40"); // mengubah background display menjadi 40= Latar
                    belakang merah tulisan hitam
                        printf("================================================\n"
                               "| Tidak ada pengguna untuk melakukan transaksi |\n"
                               "| Silakan lakukan TAMBAH AKUN terlebih dahulu |\n"
                               "================================================\n\n");
                    system("pause"); // menjeda program sampai ada input apa aja boleh
                    system("CLS");   // membersihkan layar display
                    break;           // keluar dari perulangan
                }
                else
                {
                    transaksi(&mahasiswa[0], jmlmhs, history, pcounter); // memanggil function
                    transaksi dengan mengirim berbagai parameter
                        system("CLS"); // membersihkan layar display
                    break;             // keluar dari perulangan
                }
            case 3:                                               // pengkondisian jika choice = 3
                display(&mahasiswa[0], jmlmhs);                   // memanggil fungsi display
                system("pause");                                  // menjeda program sampai ada input
                system("CLS");                                    // membersihkan layar display
                break;                                            // keluar dari pengkondisian
            case 4:                                               // pengkondisian jika choice = 4
                displayriwayat(&mahasiswa[0], pcounter, history); // memanggil function
                display riwayat
                    system("CLS"); // membersihkan layar display
                break;             // keluar dari pengkondisian
            case 5:                // pengkondisian jika choice = 5
                help();            // memanggil fungsi help
                system("CLS");     // menjeda program sampai ada input dari user
                break;             // keluar dari pengkondisian

            case 6:            // pengkondisian jika choice = 6
                free(history); // membersihkan memory
                keluar();      // memanggil function keluar
                break;         // keluar dari pengkondisian
            default:
                printf("\a");       // memberikan bunyi warning
                system("color 40"); // mengubah background display menjadi 40= Latar
belakang merah tulisan hitam
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan masukkan
pilihan yang benar ---!\n");
Sleep(1000);//menjeda program selama 1 detik
system("color b0");//mengubah background display menjadi B0= Latar
belakang biru tulisan hitam
break;//keluar dari pengkondisian
            }
        } while (choice < 1 || choice > 6); // Parameter perulangan line 60-146
    }
    return 0; // membalikkan nilai 0
}
// function input
void input(data *mahasiswa, int jmlmhs)
{ // membalikkan nilai data *mahasiswa,int i
    printf("============================================\n");
    printf("| Menu Tambah Akun |\n");
    printf("============================================\n\n");
    printf(" Masukkan Nama Mahasiswa Ke-%d : ", jmlmhs + 1);
    scanf(" %49[^\n]s ", &mahasiswa->nama); // input string &mahasiswa->nama dengan
    spasi
        fflush(stdin); // membersihkan buffer
    printf(" Masukkan NPM Mahasiswa Ke-%d : ", jmlmhs + 1);
    scanf(" %14[^\n]s ", &mahasiswa->NPM); // input string &mahasiswa->NPM dengan
    spasi
        fflush(stdin); // membersihkan buffer
    printf(" Masukkan Fakultas Mahasiswa Ke-%d : ", jmlmhs + 1);
    scanf(" %14[^\n]s ", &mahasiswa->fak); // input string &mahasiswa->fak dengan
    spasi
        fflush(stdin); // membersihkan buffer
    printf(" Masukkan Uang Awal Mahasiswa Ke-%d : Rp ", jmlmhs + 1);
    scanf("%f", &mahasiswa->saldo); // input angka float &mahasiswa->saldo
    mahasiswa->idpinjam = 0;        // inisialisasi mahasiswa->idpinjam = 0
}
// Function display
void display(data *mahasiswa, int jmlmhs)
{                            // membalikkan nilai data
    *mahasiswa, int i int j; // Deklarasi Variabel
    system("CLS");           // Membersihkan layar
    printf("=========================\n");
    printf("| Saldo Tersisa |\n");
    printf("=========================\n\n");
    // menampilkan output saldo tersisa dengan tabel
printf ("\n %-5s\t %-30s\tNPM\t\t\tFakultas\t%8s \n", "No", "Nama", "Total
Saldo");
for (j=0; j<jmlmhs ;j++){
        printf("\n %-5d\t %-30s\t%s\t\t%s\t\tRp%8.2f\n", j + 1,
               mahasiswa[j].nama, mahasiswa[j].NPM, mahasiswa[j].fak, mahasiswa[j].saldo);
}
printf("\n");//memberikan enter terhadap line selanjutnya
}
// Function Transaksi
void transaksi(data *mahasiswa, int jmlmhs, riwayat *history, int *counter)
{                                                 // membalikkan nilai data *mahasiswa, int i, riwayat *history, int
    *counter int j, choice, trans, transfer, sen; // deklarasi variabel integer
    float bunga, angsur, transaksi;               // deklarasi variabel float
    system("CLS");                                // membersihkan layar
    printf("============================================\n");
    printf("| Menu Transaksi |\n");
    printf("============================================\n");

    printf("\n Pilih Mahasiswa yang melakukan transaksi \n");
    for (j = 0; j < jmlmhs; j++)
    { // menampilkan mahasiswa sesuai urutan
        printf("\n %d. %s", j + 1, mahasiswa[j].nama);
    }
    do
    { // kondisi perulangan line 198-207
        printf("\n\n Masukkan Nomor Mahasiswa Yang Dipilih : ");
        scanf("%d", &choice); // meminta inputan choice
        if (choice < 1 || choice > jmlmhs)
        { // pengkondisian choice bila choice < 1
            atau choice > jmlmhs
                              system("color 40"); // mengubah background display menjadi 40= Latar
belakang merah tulisan hitam
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan masukkan
pilihan yang benar ---!");
Sleep(1000);//menjeda program selama 1 detik
system("color b0");//mengubah background display menjadi B0= Latar
belakang biru tulisan hitam
        }
    } while (choice < 1 || choice > jmlmhs);                        // parameter perulangan line
    system("CLS");                                                  // membersihkan layar
    printf(" \n| Transaksi oleh %s |", mahasiswa[choice - 1].nama); // output berupa
    nama mahasiswa
        printf("\n\n==========================================\n"
               "| Pilihan Transaksi |\n"
               "| |\n"
               "| 1. Setoran Tunai |\n"
               "| 2. Penarikan Tunai |\n"
               "| 3. Transfer |\n"
               "| 4. Peminjaman Kredit |\n"
               "| 5. Pembayaran Kredit |\n"
               "==========================================\n");
    do
    { // kondisi perulangan jika trans < 1 atau trans > 5
        printf("\n Masukkan Pilihan Nomor Transaksi : ");
        scanf("%d", &trans); // meminta input trans
        switch (trans)
        {       // penkondisian input trans
        case 1: // jika trans = 1
            printf("\n Masukkan Nominal Saldo yang akan disetorkan : Rp ");
            scanf("%f", &transaksi);              // meminta inputan transaksi
            history[*counter].jumlah = transaksi; // memasukkan jumlah transaksi ke
            history
                history[*counter]
                    .id = choice; // memasukkan nilai choice ke dalam
            variabel id dalam struct history
                history[*counter]
                    .saldoawal = mahasiswa[choice - 1].saldo; // Memasukkan
            saldo awal dari saldo mahasiswa
                mahasiswa[choice - 1]
                    .saldo += transaksi; // melakukan penambahan nilai
            transaksi ke saldo
                history[*counter]
                    .saldoakhir = mahasiswa[choice - 1].saldo; // Memasukkan
            saldo akhir dari saldo mahasiswa
                history[*counter]
                    .jenis = 0; // memasukkan nilai 0 pada history.jenis
            artinya transaksi tambah saldo
                *counter = *counter + 1; // menambah nilai counter untuk mengganti slot
            history
                history = (riwayat *)realloc(history, sizeof(riwayat) * (*counter +
                                                                         1)); // menambah 1 tempat memori untuk history selanjutnya
            break;                                                            // keluar dari pengkondisian
        case 2:                                                               // jika trans = 2
            printf("\n Masukkan Nominal Saldo yang akan ditarik : Rp ");
            scanf("%f", &transaksi); // meminta input nilai transaksi
            if (transaksi > mahasiswa[choice - 1].saldo)
            {
                system("color 40");
                printf("\a");
printf("\n ! ! ! Saldo Anda tidak mencukupi, Saldo Anda Sebesar Rp
%0.0f ! ! !\n\n",mahasiswa[choice-1].saldo);
system("pause");//menjeda program sampai ada input
break;//keluar dari pengkondisian
            }
            history[*counter].jumlah = transaksi; // memasukkan jumlah transaksi ke
            history
                history[*counter]
                    .id = choice; // memasukkan nilai choice ke dalam
            variabel id dalam struct history
                history[*counter]
                    .saldoawal = mahasiswa[choice - 1].saldo; // Memasukkan
            saldo awal dari saldo mahasiswa

                mahasiswa[choice - 1]
                    .saldo -= transaksi; // mengurangi saldo sesuai nilai
            transaksi
                history[*counter]
                    .saldoakhir = mahasiswa[choice - 1].saldo; // Memasukkan
            saldo akhir dari saldo mahasiswa
                history[*counter]
                    .jenis = 1; // memasukkan nilai 1 pada history.jenis
            artinya transaksi mengurangi saldo
                *counter = *counter + 1; // menambah nilai counter untuk mengganti slot
            history
                history = (riwayat *)realloc(history, sizeof(riwayat) * (*counter +
                                                                         1)); // menambah 1 tempat memori untuk history selanjutnya
            break;                                                            // keluar dari pengkondisian
        case 3:                                                               // jika trans = 3
            if (jmlmhs == 1)
            {
                printf("\a");
                system("color 40");
                printf("\n====================================================\n"
                       "| Tidak ada pengguna lain untuk melakukan transfer |\n"
                       "| Silakan lakukan TAMBAH AKUN terlebih dahulu |\n"
                       "====================================================\n\n");
                system("pause"); // menjeda program sampai ada input
                system("CLS");   // Membersihkan layar
                break;           // keluar dari pengkondisian
            }
            else
            {
                printf("\n Pilih Mahasiswa yang akan di transfer\n\n");
                for (j = 0; j < jmlmhs; j++)
                { // for loop untuk print nama mahasiswa yg
                    terdaftar if (j == choice - 1)
                    {
                        continue;
                    }
                    else
                    {
                        printf(" %d. %s\n", j + 1, mahasiswa[j].nama);
                    }
                }
                do
                {
                    printf("\n Masukkan Nomor Mahasiswa Yang Dipilih : ");
                    scanf("%d", &transfer); // Memilih mahasiswa yang akan ditransfer
                    if (transfer <= 0 || transfer > jmlmhs || transfer == choice)
                    { //
                        Error correction apabila salah memilih mahasiswa
                            printf("\a");
                        system("color 40");
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan
masukkan pilihan yang benar ---!\n");
Sleep(1000);
system("color b0");
                    }
                } while (transfer <= 0 || transfer > jmlmhs || transfer == choice);
                printf("\n Masukkan nominal saldo yang akan ditransfer : Rp ");
                scanf("%f", &transaksi); // memasukkan nominal transfer
                if (transaksi > mahasiswa[choice - 1].saldo)
                {
                    system("color 40");
                    printf("\a");
printf("\n ! ! ! Saldo Anda tidak mencukupi, Saldo Anda Sebesar Rp
%f ! ! !\n\n",mahasiswa[choice-1].saldo);
system("pause");//menjeda program sampai ada input
break;//keluar dari perulangan
                }
                history[*counter].jumlah = transaksi; // memasukkan jumlah transaksi ke
                history
                    history[*counter]
                        .id = choice; // memasukkan nilai choice ke dalam
                variabel id dalam struct history
                    history[*counter]
                        .saldoawal = mahasiswa[choice - 1].saldo; // Memasukkan
                saldo awal dari saldo mahasiswa
                    mahasiswa[choice - 1]
                        .saldo -= transaksi;
                history[*counter].saldoakhir = mahasiswa[choice - 1].saldo; // Memasukkan
                saldo akhir dari saldo mahasiswa
                    history[*counter]
                        .jenis = 2; // memasukkan nilai 2 pada history.jenis
                artinya transaksi transfer
                    *counter = *counter + 1; // menambah nilai counter untuk mengganti slot
                history

                    history = (riwayat *)realloc(history, sizeof(riwayat) * (*counter +
                                                                             1)); // menambah 1 tempat memori untuk history selanjutnya
                history[*counter].jumlah = transaksi;                             // memasukkan jumlah transaksi ke
                history
                    history[*counter]
                        .id = transfer; // Memasukkan nilai transfer pada
                history yang akan ditransfer
                    history[*counter]
                        .saldoawal = mahasiswa[transfer - 1].saldo; // Memasukkan
                saldo awal dari saldo mahasiswa
                    mahasiswa[transfer - 1]
                        .saldo += transaksi; // Menambah saldo dari
                mahasiswa yang di transfer

                    history[*counter]
                        .saldoakhir = mahasiswa[transfer -
                                                1]
                                          .saldo; // Memasukkan saldo akhir dari saldo mahasiswa

                history[*counter].jenis = 5; // memasukkan nilai 0 pada history.jenis
                artinya transaksi menambah saldo
                    *counter = *counter + 1; // menambah nilai counter untuk mengganti slot
                history
                    history = (riwayat *)realloc(history, sizeof(riwayat) * (*counter +
                                                                             1)); // menambah 1 tempat memori untuk history selanjutnya
                break;                                                            // keluar dari pengkondisian
            }
        case 4:            // jika trans = 4
            system("CLS"); // Membersihkan layar
            if (mahasiswa[choice - 1].idpinjam > 0)
            {
                printf("Anda Telah melakukan pinjaman belum lunas sebelumnya !!\n");
                system("pause");
                break;
            }
            system("CLS"); // Membersihkan layar
            printf("============================================\n");
            printf("| Menu Peminjaman |\n");
            printf("============================================\n\n");
            printf(" Masukkan Jumlah yang akan dipinjam : Rp ");
            scanf("%f", &mahasiswa[choice - 1].pinjaman); // input jumlah yang akan
            dipinjam do
            { // input lama angsuran dengan error correction
                printf(" Masukkan Lama Angsuran (Bulan) maximal 24 bulan : ");
                scanf("%f", &mahasiswa[choice - 1].bulan);
            }
            while (mahasiswa[choice - 1].bulan < 1 || mahasiswa[choice - 1].bulan > 24)
                ;

            bunga = mahasiswa[choice - 1].pinjaman * 0.075 * (mahasiswa[choice - 1].bulan / 12); // penghitungan bunga transaksi

            angsur = (bunga + mahasiswa[choice - 1].pinjaman) / mahasiswa[choice -
                                                                          1]
                                                                    .bulan; // perhitungan jumlah angsuran per bulan

            system("CLS"); // Membersihkan layar
            // display untuk konfirmasi pinjaman
            printf("============================================\n");
            printf("| Konfirmasi Peminjaman |\n");
            printf("============================================\n\n");
printf(" Anda akan meminjam sejumlah : Rp %0.2f
\n",mahasiswa[choice-1].pinjaman);
printf(" Pembayaran akan diangsur selama : %0.0f
bulan\n",mahasiswa[choice-1].bulan);
printf(" Bunga Peminjaman sebesar 7,5%% : Rp %0.2f\n",bunga);
printf(" Angsuran Perbulan Peminjaman sebesar : Rp %0.2f\n\n",angsur);
do{//loop untuk konfirmasi pinjaman dengan error correction
printf("\n 0. No\n 1. Yes\n Apakah Anda Yakin melakukan peminjaman
ini? : ");
scanf("%d",&sen);
if (sen < 0 || sen > 1){
                    printf("\a");
                    system("color 40");
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan
masukkan pilihan yang benar ---!\n");
Sleep(1000);//menjeda program selama 1 detik
system("color b0");
}
}while(sen < 0 || sen > 1);
if (sen == 0){//apabila user tidak jadi meminjam mereset nilai dan
                keluar dari loop
                    mahasiswa[choice - 1]
                        .bulan = 0;
                mahasiswa[choice - 1].pinjaman = 0;
                break; // keluar dari perulangan

}
history[*counter].jumlah = mahasiswa[choice-1].pinjaman; // memasukkan
jumlah pinjaman ke history
history[*counter].saldoawal = mahasiswa[choice-1].saldo; // memasukkan
nilai saldo awal
history[*counter].id = choice; // memasukkan nilai id sesuai hcoice
mahasiswa[choice-1].saldo += mahasiswa[choice-1].pinjaman; // menambah
saldo seusai dengan jumlah pinjaman
history[*counter].saldoakhir = mahasiswa[choice-1].saldo; // memasukkan
niai saldo akhir
history[*counter].jenis = 3;// memasukkan nilai 3 pada history.jenis
artinya transaksi peminjaman
mahasiswa[choice-1].idpinjam = 1; // mengubah id pinjam menjadi 1 yg
artinya mahasiswa melakukan pinjaman
mahasiswa[choice-1].pinjaman += bunga; // menambah pinjaman dengan bunga
*counter = *counter + 1 ;//menambah nilai counter untuk mengganti slot
history
history = (riwayat*) realloc (history , sizeof(riwayat) * (*counter +
1));//menambah 1 tempat memori untuk history selanjutnya
break;//keluar dari pengkondisian
case 5 : //jika trans = 5
system("CLS");//Membersihkan layar
printf("============================================\n");
printf("| Menu Pembayaran |\n");
printf("============================================\n\n");
if(mahasiswa[choice-1].idpinjam == 0){//apabila id mahasiswa tidak
                meminjam maka akan muncul peringatan
                    printf("\nAnda tidak memiliki pinjaman untuk dibayar");
                system("pause"); // menjeda program
                break;           // keluar dari perulangan
}
printf("Anda memiliki sisa Pinjaman Total + Bunga 7,5%% Sebesar :Rp
%0.2f\n",mahasiswa[choice-1].pinjaman);//display jumlah pinjaman
printf("Telah dibayarkan sebesar :Rp

%0.2f\n", (mahasiswa[choice-1].idpinjam-1)*(mahasiswa[choice-
1].pinjaman/mahasiswa[choice-1].bulan)); // display jumlah yang telah dibayar

printf("Pembayaran angsuran pada bulan ke %d sebesar Rp

%0.2f\n",mahasiswa[choice-1].idpinjam,mahasiswa[choice-
1].pinjaman/mahasiswa[choice-1].bulan); // display angsuran perbulan

do{// loop untuk konfirmasi pembayaran beserta error correction
printf("\n 0. No\n 1. Yes\n Apakah Anda Yakin melakukan pembayaran
ini? : ");
scanf("%d",&sen);
if (sen < 0 || sen > 1){
                    printf("\a");
                    system("color 40");
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan
masukkan pilihan yang benar ---!\n");
Sleep(1000);//menjeda program selama 1 detik
system("color b0");
}
}while(sen < 0 || sen > 1);
if(sen == 0){//apabila memilih no maka akan langsung keluar dari loop
                break; // keluar dari perulangan
}
if(mahasiswa[choice-1].pinjaman/mahasiswa[choice-1].bulan >
mahasiswa[choice-1].saldo){//Apabila saldo kurang tdk mencukupi maka keluar
                peringatan
                    printf("\a");
                system("color 40");
                printf("\n Saldo Anda Sebesar Rp %.2f", mahasiswa[choice - 1].saldo);
printf("\n Anda tidak Memiliki Saldo yang cukup untuk melakukan
pembayaran!!!");
Sleep(1000);//menjeda program selama 1 detik
system("color b0");
system("pause");//menjeda program sampai ada input
break;//keluar dari perulangan
}
history[*counter].id = choice; // memasukkan nilai choice ke history.id

history[*counter].jumlah = mahasiswa[choice-
1].pinjaman/mahasiswa[choice-1].bulan; // memasukkan jumlah transaksi yang

terjadi
history[*counter].saldoawal = mahasiswa[choice-1].saldo; // memasukkan
saldo awal sesuai dengan saldo sebelum dikurangi

mahasiswa[choice-1].saldo -= mahasiswa[choice-
1].pinjaman/mahasiswa[choice-1].bulan; // mengurangi saldo sesuai jumlah

angsuran
history[*counter].saldoakhir = mahasiswa[choice-1].saldo;// memasukkan
saldo akhir sesuai saldo terbaru
history[*counter].jenis = 4; // mema
*counter = *counter + 1;//menambah nilai counter untuk mengganti slot
history
history = (riwayat*) realloc (history , sizeof(riwayat) * (*counter +
1));//menambah 1 tempat memori untuk history selanjutnya
mahasiswa[choice-1].idpinjam ++; // menambah id pinjam untuk
dibandingkan dengan jumlah bulan angsuran
if(mahasiswa[choice-1].idpinjam-1 == mahasiswa[choice-1].bulan){ //
                apabila jumlah pembayaran sudah sama dengan jumlah bulan pinjam maka peminjaman
                    dinyatakan selesai
                        printf("Pembayaran anda telah selesai ");
                mahasiswa[choice - 1].idpinjam = 0; // id 0 aritnya mahasiswa sudah
                tidak meminjam lagi
                    system("pause");
}
break;//keluar dari pengkondisian
default:
printf("\a");
system("color 40");
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan masukkan
pilihan yang benar ---!\n");
Sleep(1000);//menjeda program selama 1 detik
system("color b0");
break;//keluar dari pengkondisian
        }
    } while (trans < 1 || trans > 5);
}
// function menu riwayat
void displayriwayat(data *mahasiswa, int *counter, riwayat *history)
{
    int i, j;      // deklarasi variabel integer
    system("CLS"); // Membersihkan layar
    printf("============================================\n");
    printf("| Riwayat Transaksi |\n");
    printf("============================================\n\n");
    char type[6][20] = {"Setoran Tunai", "Penarikan Tunai",
                        "Transfer", "Peminjaman", "Pembayaran Angsuran", "Saldo Masuk"};
    for (i = 0; i < *counter; i++)
    {
        printf("\n Jenis transaksi : %s\n", type[history[*counter - i - 1].jenis]); //
        display jenis transaksi
            printf(" Nama mahasiswa : %s\n", mahasiswa[history[*counter - 1 - i].id - 1]); //
        display nama yg melakukan transaksi
            printf(" Jumlah Transaksi : Rp %0.2f\n", history[*counter - 1 - i].jumlah); //
        display jumlah transaksi yg dilakukan
            printf(" Saldo Awal : Rp %0.2f\n", history[*counter - i - 1].saldoawal); //
        display saldo awal
            printf(" Saldo Akhir : Rp %0.2f\n\n", history[*counter - 1 - i].saldoakhir);
        // display saldo akhir
        for (j = 1; j <= 172; j++)
        {
            printf("-");
        }
    }
    printf("\n");
    system("pause"); // menjeda program sampai ada input
}
// function menu help
void help()
{
    int pedoman = 0, pilTrans = 0; // deklarasi variabel integer
    system("CLS");                 // Membersihkan layar
    printf("============================================\n");
    printf("| Pedoman Dalam Menggunakan Aplikasi |\n");

    printf("============================================\n\n");
    printf(" 1. Pedoman Melakukan Tambah Akun\n"
           " 2. Pedoman Melakukan Transaksi\n"
           " 3. Pedoman Menampilkan Display \n"
           " 4. Pedoman Menampilkan Histori/Riwayat\n"
           " 5. Pedoman Exit Dari Aplikasi\n\n");
    do
    {
        printf(" Masukkan Nomor Pilihan: ");
        scanf("%d", &pedoman);
        system("CLS"); // Membersihkan layar
        switch (pedoman)
        {
        case 1: // jika pedoman = 1
            printf("============================================\n"
                   "| Pedoman Melakukan Tambah Akun |\n"
                   "============================================\n\n"
                   " 1. Masukkan angka 1 pada nomor menu yang di pilih \n"
                   " 2. Lalu Anda akan diminta untuk memasukkan Nama, NPM, Fakultas,
                   Jurusan,
                   dan Saldo Awal.\n "
                                     " 3. Setelah itu Anda akan diminta untuk memasukan pilihan yaitu
                   menambah akun pengguna baru atau kembali ke menu\n "
                                                                      " 4. Untuk menambah akun pengguna baru masukkan angka 1\n"
                                                                      " 5. Untuk kembali ke menu masukkan angka 0 \n\n");
            system("pause");
            break; // keluar dari pengkondisian
        case 2:    // jika pedoman = 2
            printf("============================================\n"
                   "| Pedoman Melakukan Transaksi |\n"
                   "============================================\n\n"
                   " Pilih jenis pedoman transaksi:\n"
                   " 1. Setoran Tunai\n"
                   " 2. Penarikan Tunai\n"
                   " 3. Transfer\n"
                   " 4. Peminjaman Kredit\n"
                   " 5. Pembayaran Kredit\n\n");
            do
            {
                printf(" Masukkan Nomor Pilihan : ");
                scanf("%d", &pilTrans);
                switch (pilTrans)
                {
                case 1:            // jika pilTrans = 1
                    system("CLS"); // Membersihkan layar
                    printf("============================================\n"
                           "| Pedoman Melakukan Setoran Tunai |\n"
                           "============================================\n\n"
                           " 1. Masukkan angka 2 pada nomor menu yang di pilih \n"
                           " 2. Lalu Anda akan diminta untuk memilih mahasiswa yang akan
                           melakukan transaksi dengan memasukkan nomor mahasiswa yang dipilih.\n "
                                                                                                 " 3. Setelah itu Anda akan diminta untuk memasukan nomor
                           pilihan Transaksi yaitu Setoran Tunai,
                           Penarikan Tunai, Transfer, Peminjaman Kredit, dan Pembayaran Kredit\n "
                                                                                                 " 4. Untuk melakukan Setoran Tunai masukkan angka 1\n"
                                                                                                 " 5. Selanjutnya masukkan jumlah saldo yang akan disetorkan.\n"
                                                                                                 " 6. Transaksi Setoran Tunai berhasil dilakukan dan akan kembali
                           ke menu utama\n\n "
                                             " ");
                    system("pause"); // menjeda program sampai ada input
                    break;           // keluar dari pengkondisian
                case 2:              // jika pilTrans = 1
                    system("CLS");   // Membersihkan layar
printf("=============================================\n"
"| Pedoman Melakukan Penarikan Tunai |\n"
"=============================================\n\n"
" 1. Masukkan angka 2 pada nomor menu yang di pilih \n"
" 2. Lalu Anda akan diminta untuk memilih mahasiswa yang akan
melakukan transaksi dengan memasukkan nomor mahasiswa yang dipilih.\n"
" 3. Setelah itu Anda akan diminta untuk memasukan nomor
pilihan Transaksi yaitu Setoran Tunai, Penarikan Tunai, Transfer, Peminjaman
Kredit, dan Pembayaran Kredit\n"
" 4. Untuk melakukan Penarikan Tunai masukkan angka 2\n"
" 5. Selanjutnya masukkan jumlah saldo yang akan ditarik.\n"
" 6. Transaksi Penarikan Tunai berhasil dilakukan dan akan
kembali ke menu utama\n\n");
system ("pause");//menjeda program sampai ada input

break;//keluar dari pengkondisian
case 3: //jika pilTrans = 1
system ("CLS");//Membersihkan layar
printf("===========================================\n"
"| Pedoman Melakukan Transfer |\n"
"===========================================\n\n"
" 1. Masukkan angka 2 pada nomor menu yang di pilih \n"
" 2. Lalu Anda akan diminta untuk memilih mahasiswa yang akan
melakukan transaksi dengan memasukkan nomor mahasiswa yang dipilih.\n"
" 3. Setelah itu Anda akan diminta untuk memasukan nomor
pilihan Transaksi yaitu Setoran Tunai, Penarikan Tunai, Transfer, Peminjaman
Kredit, dan Pembayaran Kredit\n"
" 4. Untuk melakukan Transfer masukkan angka 3\n"
" 5. Pilihlah mahasiswa yang akan menjadi tujuan Transfer
Dengan memasukkan nomor mahasiswa yang dipilih.\n"
" 6. Selanjutnya masukkan jumlah saldo yang akan
ditransfer.\n"
" 7. Transaksi Transfer berhasil dilakukan dan akan kembali
ke menu utama\n\n");
system ("pause");//menjeda program sampai ada input
break;//keluar dari pengkondisian
case 4: //jika pilTrans = 1
system ("CLS");//Membersihkan layar
printf("==============================================\n"
"| Pedoman Melakukan Peminjaman Kredit |\n"
"==============================================\n\n"
" 1. Masukkan angka 2 pada nomor menu yang di pilih \n"
" 2. Lalu Anda akan diminta untuk memilih mahasiswa yang akan
melakukan transaksi dengan memasukkan nomor mahasiswa yang dipilih.\n"
" 3. Setelah itu Anda akan diminta untuk memasukan nomor
pilihan Transaksi yaitu Setoran Tunai, Penarikan Tunai, Transfer, Peminjaman
Kredit, dan Pembayaran Kredit\n"
" 4. Untuk melakukan Peminjaman Kredit masukkan angka 4\n"
" 5. Masukkan jumlah nominal yang ingin dipinjam.\n"
" 6. Selanjutnya masukkan Durasi Angsuran yang diinginkan.\n"
" 7. Lalu akan tampil informasi mengenai peminjaman berupa
Jumlah peminjaman, Durasi Angsuran, Bunga Pinjaman, dan Angsuran Per Bulan.\n"
" 8. Kemudian Anda diminta untuk mengkonfirmasi peminjaman,
jika setuju masukkan angka 1 dan tidak setuju masukkan angka 0\n"
" 9. Transaksi selesai dilakukan dan akan kembali ke menu
utama");
system ("pause");//menjeda program sampai ada input
break;//keluar dari pengkondisian
case 5: //jika pilTrans = 1
system ("CLS");//Membersihkan layar
printf("==============================================\n"
"| Pedoman Melakukan Pembayaran Kredit |\n"
"==============================================\n\n"
" 1. Masukkan angka 2 pada nomor menu yang di pilih \n"
" 2. Lalu Anda akan diminta untuk memilih mahasiswa yang akan
melakukan transaksi dengan memasukkan nomor mahasiswa yang dipilih.\n"
" 3. Setelah itu Anda akan diminta untuk memasukan nomor
pilihan Transaksi yaitu Setoran Tunai, Penarikan Tunai, Transfer, Peminjaman
Kredit, dan Pembayaran Kredit\n"
" 4. Untuk melakukan Pembayaran Kredit masukkan angka 5\n"
" 5. Jika Anda tidak memiliki Angsuran maka pemberitahuan Anda
tidak memiliki Angsuran akan ditampilkan dan langsung kembali ke menu utama\n"
" 6. Jika Anda memiliki Angsuran maka akan di tampilkan
informasi mengenai Angsuran Anda\n"
" 7. Selanjutnya Anda akan diminta untuk konfirmasi
pembayaran, masukkan angka 1 jika setuju dan angka 0 jika tidak setuju.\n"
" 8. Transaksi selesai dilakukan dan akan kembali ke menu
utama");
system ("pause");//menjeda program sampai ada input
break;//keluar dari pengkondisian
default:
printf("\a");
system("color 40");
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan masukkan
pilihan yang benar ---!\n\n");
Sleep(1000);//menjeda program selama 1 detik
system("color b0");

break;//keluar dari pengkondisian
                }
            } while (pilTrans < 1 || pilTrans > 5);
            break;
        case 3: // jika pedoman = 3
printf("==============================================\n"
"| Pedoman Dalam Menampilkan Display |\n"
"==============================================\n\n"
" 1. Masukkan angka 3 pada nomor menu yang dipilih\n"
" 2. Lalu tampilan display akan muncul dengan Nama dan Sisa saldo
terbaru.\n\n");
system ("pause");//menjeda program sampai ada input
break;//keluar dari pengkondisian
case 4: //jika pedoman = 4
printf("==============================================\n"
"| Pedoman Dalam Menampilkan History/Riwayat |\n"
"==============================================\n\n"
" 1. Masukkan angka 4 pada nomor menu yang dipilih\n"
" 2. Lalu daftar riwayat transaksi akan ditampilkan dengan Nama dan
Transaksi yang terjadi secara urut.\n\n");
system ("pause");//menjeda program sampai ada input
break;//keluar dari pengkondisian
case 5: //jika pedoman = 5
printf("==============================================\n"
"| Pedoman Untuk Keluar Dari Aplikasi |\n"
"==============================================\n\n"
" 1. Masukkan angka 5 pada nomor menu yang di pilih, lalu Anda akan
keluar dari aplikasi \n\n");
system ("pause");//menjeda program sampai ada input
break;//keluar dari pengkondisian
default:
printf("\a");
system("color 40");
printf("\n !---- Pilihan yang Anda masukkan salah, Silakan masukkan
pilihan yang benar ---!\n\n");
Sleep(1000);//menjeda program selama 1 detik
system("color b0");
        }
    } while (pedoman < 1 || pedoman > 5);
}
// function tampilan depan
void welcome()
{
    int i; // deklarasi variabel integer
    printf("!--- Harap Fullscreen lalu tekan ENTER untuk memulai aplikasi ---!");
    getchar();     // memanggil function getchar
    system("CLS"); // Membersihkan layar
    Sleep(800);    // menjeda program selama 0.8 detik
    system("color B0");
    printf("\n\n\n\n\n\n\n");
    char a[] = {"\t\t\t\t\t\t\t\t======================================\n"
                "\t\t\t\t\t\t\t\t|---- Selamat Datang Di Aplikasi ----|\n"
                "\t\t\t\t\t\t\t\t|-------- Koperasi Mahasiswa --------|\n"
                "\t\t\t\t\t\t\t\t|------------ Kelompok 1 ------------|\n"
                "\t\t\t\t\t\t\t\t|------- Pemrograman Dasar 02 -------|\n"
                "\t\t\t\t\t\t\t\t======================================\n\n"};
    for (i = 0; a[i] != a[283]; i++)
    {
        printf("%c", a[i]);
        Sleep(5);
    }
    printf("\t\t\t\t\t\t\t\t\t\tLoading... \n\n");
    Beep(659, 400);
    Sleep(1000); // menjeda program selama 1 detik
    for (i = 1; i <= 172; i++)
    {
        printf("%c", 223); // 233 adalah kode KARAKTER beta di dalam ASCII2
        if (i == 60 || i == 100)
            Sleep(500); // menjeda program selama 0.5 detik
        Sleep(12);
    }
    Sleep(1600);   // menjeda program selama 1.6 detik
    system("CLS"); // Membersihkan layar
}
// function tampilan keluar
void keluar()
{

    system("CLS"); // Membersihkan layar
    Sleep(500);    // menjeda program selama 0.5 detik
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t======================================\n");
    printf("\t\t\t\t\t\t\t\t|~ ~ ~ ~ ~ ~ ~ ~ EXIT ~ ~ ~ ~ ~ ~ ~ ~|\n");
    printf("\t\t\t\t\t\t\t\t======================================\n\n");
    Sleep(1600);   // menjeda program selama 1.6 detik
    system("CLS"); // Membersihkan layar
}