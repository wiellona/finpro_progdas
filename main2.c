#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct roomLighting
{
    float panjang, lebar; // panjang dan lebar ruangan
    float penerangan;   // Pencahayaan yang diinginkan (dalam lux)
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

void utilizationFactor()
{
    printf("===========================================================================================\n");
    printf("|                                Utilization Factor Table                                 |\n");
    printf("===========================================================================================\n");
    printf("|     |                              Reflektansi Atap                                     |\n");
    printf("===========================================================================================\n");
    printf("|     |       0.8       ||       0.7       ||       0.5       ||       0.3       ||   0   |\n");
    printf("===========================================================================================\n");
    printf("|     |                                Reflektansi Dinding                                |\n");
    printf("===========================================================================================\n");
    printf("|  RI | 0.5 | 0.3 | 0.1 || 0.5 | 0.3 | 0.1 || 0.5 | 0.3 | 0.1 ||   0.5  |   0.3  ||   0   |\n");
    printf("===========================================================================================\n");
    printf("| 0.6 | 0.39| 0.35| 0.32|| 0.38| 0.34| 0.32|| 0.38| 0.34| 0.31||   0.33 |   0.31 ||   0.30|\n");
    printf("| 0.8 | 0.48| 0.43| 0.40|| 0.47| 0.42| 0.40|| 0.46| 0.42| 0.39||   0.41 |   0.38 ||   0.37|\n");
    printf("| 1.0 | 0.53| 0.49| 0.46|| 0.52| 0.48| 0.45|| 0.51| 0.47| 0.45||   0.46 |   0.44 ||   0.41|\n");
    printf("| 1.25| 0.58| 0.54| 0.51|| 0.57| 0.53| 0.50|| 0.55| 0.51| 0.49||   0.50 |   0.48 ||   0.45|\n");
    printf("| 1.5 | 0.62| 0.58| 0.54|| 0.61| 0.57| 0.54|| 0.58| 0.55| 0.52||   0.53 |   0.51 ||   0.48|\n");
    printf("| 2.0 | 0.66| 0.62| 0.59|| 0.64| 0.61| 0.58|| 0.61| 0.59| 0.57||   0.56 |   0.55 ||   0.52|\n");
    printf("| 2.5 | 0.68| 0.65| 0.63|| 0.67| 0.64| 0.62|| 0.64| 0.61| 0.60||   0.59 |   0.57 ||   0.54|\n");
    printf("| 3.0 | 0.70| 0.67| 0.65|| 0.69| 0.66| 0.64|| 0.65| 0.63| 0.61||   0.60 |   0.59 ||   0.56|\n");
    printf("| 4.0 | 0.72| 0.70| 0.68|| 0.70| 0.69| 0.67|| 0.67| 0.66| 0.64||   0.63 |   0.61 ||   0.58|\n");
    printf("| 5.0 | 0.73| 0.71| 0.70|| 0.71| 0.70| 0.68|| 0.68| 0.67| 0.66||   0.64 |   0.63 ||   0.59|\n");
    printf("===========================================================================================\n");
    printf("!--- Tekan ENTER untuk kembali ke menu utamaa ---!");
    getchar();
    system("CLS");
    menu();
}

int main () {
    struct roomLighting *ruangan = (struct roomLighting *)malloc(sizeof(struct roomLighting));
    int choice, n = 1;
    float watt;
    masuk();
    menu();

    printf(" Masukkan nomor menu pilihan Anda : ");
    scanf("%d", &choice);

    switch (choice)
    {
        case 1:
            hitungLampu(ruangan, &watt);
            hitungN(ruangan, &watt);
            break;
        case 2:
            dataRuang();
            break;
        case 3:
            keluar();
        default:
            break;
    }
}

// Display menu utama
void menu()
{
    printf("=========================================\n"
           "|                                       |\n"
           "|       Lamp Efficiency Calculator      |\n"
           "|                                       |\n"
           "=========================================\n"
           "=========================================\n"
           "|              Menu utama               |\n"
           "|                                       |\n"
           "|  1. Hitung jumlah lampu yang          |\n"
           "|     dibutuhkan                        |\n"
           "|  2. Data kebutuhan lampu tiap ruang   |\n"
           "|  3. Utilization Factor Table          |\n"
           "|  3. Keluar                            |\n"
           "=========================================\n");
    printf("!--- Tekan ENTER untuk kembali ke menu utamaa ---!");
    getchar();
    system("CLS");
    menu();
}

void hitungLampu(struct roomLighting *ruangan, float *watt) 
{
    int n, i;
    printf("===========================================\n");
    printf("| Menghitung Banyak Lampu yang Dibutuhkan |\n");
    printf("|           dan Komparasi Lampu           |\n");
    printf("===========================================\n");
    printf(" Masukkan panjang ruangan (dalam meter): ");
    scanf("%f\n", &ruangan->panjang);
    printf(" Masukkan lebar ruangan : ");
    scanf("%f\n", &ruangan->lebar);
    printf(" Masukkan tinggi ruangan : ");
    scanf("%f\n", &ruangan->rH);
    printf(" Masukkan tinggi area kerja : ");
    scanf("%f\n", &ruangan->wH);
    printf(" Pencahayaan yang dibutuhkan : ");
    scanf("%f\n", &ruangan->penerangan);

    do
    {
        printf(" Reflektansi dinding ruangan (Pilih salah satu : 0.1 / 0.3 / 0.5) : ");
        scanf("%f\n", &ruangan->rW);
    } while (ruangan->rW != 0.1 || ruangan->rW != 0.1 || ruangan->rW != 0.1);

    printf(" Masukkan besar daya lampu : ");
    scanf("%f\n", watt);
}

void hitungN(struct roomLighting *ruangan, float *watt) 
{
    ruangan->N = (ruangan->penerangan * ruangan->panjang * ruangan->lebar) / (*watt * 10 * ruangan->UF * 0.75);
    roundf(ruangan->N); // lampu->watt * 10 untuk mengoversi terang lampu dari lumen ke watt

    printf(" Banyak lampu yang perlu Anda beli adalah sebanyak %.2f buah.\n", roundf(ruangan->N));
    printf("!--- Tekan ENTER untuk kembali ke menu utamaa ---!");
    getchar();
    system("CLS");
    menu();
}

void dataRuang() {
    printf("===========================================\n");
    printf("|    Data Kebutuhan Lampu Tiap Ruangan    |\n");
    printf("===========================================\n");
    printf("|      Ruang tamu       |       150 lux   |\n");
    printf("|      Ruang baca       |       150 lux   |\n");
    printf("|      Ruang kerja      |       150 lux   |\n");
    printf("|      Kamar tidur      |       150 lux   |\n");
    printf("|      Dapur            |       200 lux   |\n");
    printf("|      Kamar mandi      |       200 lux   |\n");
    printf("|      Ruang keluarga   |       150 lux   |\n");
    printf("===========================================\n");
    printf("!--- Tekan ENTER untuk kembali ke menu utamaa ---!");
    getchar();
    system("CLS");
    menu();
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