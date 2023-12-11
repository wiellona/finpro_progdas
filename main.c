#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void masuk();
void menu();
void setData(struct roomLighting *ruangan);
void hitungRI(struct roomLighting *ruangan);
void hitungN(struct roomLighting *ruangan);

struct dataLampu
{
    char tipeLampu[20];
    float watt;
    int count;
};

struct roomLighting
{
    float panjang, lebar; // panjang dan lebar ruangan
    float penerangan;   // Pencahayaan yang diinginkan (dalam lux)
    float wattLampu;  // tingkat kecerahan yang dihasilkan lampu (dalam lumen)
    float rW;   // reflektansi dinding ruangan
    float rH;   // tinggi ruangan
    float wH;   // tinggi area kerja
    float RI;   // room index
    float UF;   // utilization factor
    float N;    // Banyak lampu yang dibutuhkan
    void (*setData)(struct roomLighting *ruangan);
    void (*hitungRI)(struct roomLighting *ruangan);
    void (*hitungN)(struct roomLighting *ruangan);
};

int main(void)
{
    // Deklarasi variabel
    int pilihan; // Untuk memilih fitur pada menu
    masuk();     // memanggil function masuk
    struct dataLampu *lampu = (struct dataLampu*)malloc(sizeof(struct dataLampu));
    struct roomLighting *ruangan = (struct roomLighting*)malloc(sizeof(struct roomLighting));

    if (lampu == NULL || ruangan == NULL)
    {
        printf("Gagal mengalokasikan memori.\n");
        return 1;
    }
    menu();
    printf(" Masukkan nomor menu pilihan Anda : ");
    scanf("%d", &pilihan);

    switch (pilihan)
    {
    case 1:
        setData(ruangan);
        hitungRI(&ruangan);
        hitungN(&ruangan);
        break;
    case 2:
        break;
    case 3:
        break; 
    case 4:
        keluar();
    default:
        break;
    }
}

// Display menu utama
void menu() {
        printf("==============================\n"
               "|                            |\n"
               "| Lamp Efficiency Calculator |\n"
               "|                            |\n"
               "==============================\n"
               "==============================\n"
               "|         Menu utama         |\n"
               "|                            |\n"
               "|   1. Hitung jumlah lampu   |\n"
               "|   2. Tampilkan data        |\n"
               "|   3. Bandingkan lampu      |\n"
               "|   4. Keluar                |\n"
               "==============================\n");
}

// Function untuk menambah data
void setData(struct roomLighting *ruangan)
{
    printf("===========================================\n");
    printf("| Menghitung Banyak Lampu yang Dibutuhkan |\n");
    printf("===========================================\n");
    printf(" Masukkan panjang ruangan : ");
    scanf("%f\n", &ruangan->panjang);
    printf(" Masukkan lebar ruangan : ");
    scanf("%f\n", &ruangan->lebar);
    printf(" Masukkan tinggi ruangan : ");
    scanf("%f\n", &ruangan->rH);
    printf(" Masukkan tinggi area kerja : ");
    scanf("%f\n", &ruangan->wH);
    printf(" Pencahayaan yang dibutuhkan : ");
    scanf("%f\n", &ruangan->penerangan);
    printf(" Watt lampu : ");
    scanf("%f\n", &ruangan->wattLampu);

    do {
        printf(" Reflektansi dinding ruangan (Pilih salah satu : 0.1 / 0.3 / 0.5) : ");
        scanf("%f\n", &ruangan->rW);
    } while (ruangan->rW != 0.1 || ruangan->rW != 0.1 || ruangan->rW != 0.1);

}

// Function untuk menghitung Room Index
void hitungRI (struct roomLighting *ruangan) 
{
    ruangan->RI = (ruangan->panjang * ruangan->lebar) / ((ruangan->rH - ruangan->wH) * (ruangan->panjang * ruangan->lebar));
    roundf(ruangan->RI, 1); // memperoleh 1 digit desimal
}

// Function untuk menentukan utilization factor
void hitungUF (struct roomLighting *ruangan) 
{

    if (ruangan->RI < 0.75 || ruangan->RI > 5.00) {
        printf("Tidak dapat diaplikasikan"); // perhitungan tidak dapat dilakukan karena tidak memenuhi tabel utilization factor
    } else if (ruangan->RI = 0.75) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.64;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.59;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.55;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    } else if (ruangan->RI = 1.00) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.68;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.63;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.59;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    } else if (ruangan->RI = 1.25) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.71;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.66;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.62;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    } else if (ruangan->RI = 1.50) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.74;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.68;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.64;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    } else if (ruangan->RI = 2.00) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.77;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.72;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.68;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    } else if (ruangan->RI = 2.50) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.79;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.74;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.7;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    } else if (ruangan->RI = 3.00) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.80;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.76;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.72;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    } else if (ruangan->RI = 4.00) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.83;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.79;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.75;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    } else if (ruangan->RI = 5.00) {
        if (ruangan->rW = 0.5) {
            ruangan->UF = 0.85;
        } else if (ruangan->rW = 0.3) {
            ruangan->UF = 0.81;
        } else if (ruangan->rW = 0.1) {
            ruangan->UF = 0.77;
        } else {
            printf("Tidak dapat ditentukan.");
            menu();
        }
    }
}

void hitungN(struct roomLighting *ruangan)
{
    ruangan->N = (ruangan->penerangan * ruangan->panjang * ruangan->lebar) / (ruangan->wattLampu * ruangan->UF * 0.75);
    roundf(ruangan->N);
}

void masuk()
{
    int i;
    printf("!--- Harap Fullscreen lalu tekan ENTER untuk memulai aplikasi ---!");
    getchar();
    system("CLS"); // Membersihkan layar
    sleep(1);      // Menjeda program selama 1 detik
    printf("\n\n\n\n\n\n\n");
    char a[] = {"\t\t\t\t\t\t\t\t======================================\n"
                "\t\t\t\t\t\t\t\t|---- Selamat Datang Di Aplikasi ----|\n"
                "\t\t\t\t\t\t\t\t|---- Lamp Efficiency Calculator ----|\n"
                "\t\t\t\t\t\t\t\t|------------ Kelompok 9 ------------|\n"
                "\t\t\t\t\t\t\t\t|------- Pemrograman Dasar 01 -------|\n"
                "\t\t\t\t\t\t\t\t======================================\n\n"};
    for (i = 0; i < strlen(a); i++)
    {
        printf("%c", a[i]);
        sleep(1);
    }
    printf("\t\t\t\t\t\t\t\t\t\tLoading... \n\n");
    sleep(1);
    for (i = 1; i <= 172; i++)
    {
        printf("%c", 223);
        if (i == 60 || i == 100)
            sleep(1);
        sleep(0.1);
    }
    sleep(1.6);
    system("CLS"); // Membersihkan layar
}

void keluar()
{
    system("CLS"); // Membersihkan layar
    sleep(0.1);
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t======================================\n");
    printf("\t\t\t\t\t\t\t\t|~ ~ ~ ~ ~ ~ ~ ~ Keluar ~ ~ ~ ~ ~ ~ ~ ~|\n");
    printf("\t\t\t\t\t\t\t\t======================================\n\n");
    sleep(1600);   // menjeda program selama 1.6 detik
    system("CLS"); // Membersihkan layar
}
