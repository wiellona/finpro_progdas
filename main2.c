#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>

struct roomLighting
{
    float panjang, lebar; // panjang dan lebar ruangan
    float penerangan;     // Pencahayaan yang diinginkan (dalam lux)
    float UF;             // utilization factor
    float N;              // Banyak lampu yang dibutuhkan
};


void hitungLampu(struct roomLighting *ruangan, float *watt);
void hitungN(struct roomLighting *ruangan, float *watt);
void masuk();
void penjelasanProgram();
void keluar();
void menu();
void dataRuang();

// Tabel utilization factor sebagai salah satu variabel yang diperlukan dalam perhitungan
void utilizationFactor()
{
    printf("\n\n");
    printf("Cara membaca tabel\n");
    printf("Pertama-tama, Anda perlu mengetahui nilai reflektansi atap, reflektansi dinding, dan room index (RI) ruangan Anda.\n"); 
    printf("Contoh: Reflektansi atap ruangan A adalah 0.7, reflektansi dindingnya 0.1, dan room indexnya 1.25, maka nilai utilization Factornya adalah 0.50\n\n");
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
}

int main(void)
{
    struct roomLighting *ruangan = (struct roomLighting *)malloc(sizeof(struct roomLighting));
    int choice;
    float watt;
    masuk();

    do
    {
        menu();

        printf(" Masukkan nomor menu pilihan Anda : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            penjelasanProgram();
            break;
        case 2:
            hitungLampu(ruangan, &watt);
            hitungN(ruangan, &watt);
            break;
        case 3:
            dataRuang();
            break;
        case 4:
            utilizationFactor();
            break;
        case 5:
            keluar();
            break;
        default:
            printf("Input yang Anda masukkan tidak valid. Silahkan masukkan angka 1-4");
            break;
        }
    } while (choice != 5);
}

// Display menu utama
void menu()
{
    printf("\n\n");
    printf("=========================================\n"
           "|                                       |\n"
           "|       Lamp Efficiency Calculator      |\n"
           "|                                       |\n"
           "=========================================\n"
           "=========================================\n"
           "|              Menu utama               |\n"
           "|                                       |\n"
           "|  1. Penjelasan program                |\n"
           "|  2. Hitung jumlah lampu yang          |\n"
           "|     dibutuhkan                        |\n"
           "|  3. Data kebutuhan lampu tiap ruang   |\n"
           "|  4. Utilization Factor Table          |\n"
           "|  5. Keluar                            |\n"
           "=========================================\n");
}

// Function untuk meminta pengguna memasukkan variabel yang dibutuhkan dalam perhitungan
void hitungLampu(struct roomLighting *ruangan, float *watt)
{
    printf("\n\n");
    printf("===========================================\n");
    printf("| Menghitung Banyak Lampu yang Dibutuhkan |\n");
    printf("|           dan Komparasi Lampu           |\n");
    printf("===========================================\n");
    printf(" Masukkan panjang ruangan (dalam meter): ");
    scanf("%f", &ruangan->panjang);
    printf(" Masukkan lebar ruangan (dalam meter): ");
    scanf("%f", &ruangan->lebar);
    printf(" Pencahayaan yang dibutuhkan (dalam lux) : ");
    scanf("%f", &ruangan->penerangan);
    printf(" Utilization Factor ruangan : ");
    scanf("%f", &ruangan->UF);
    printf(" Masukkan besar daya lampu (dalam watt) : ");
    scanf("%f", watt);
}

// Funtion untuk menghitung banyaknya lampu yang perlu dibeli untuk memenuhi kebutuhan pencahayaan
void hitungN(struct roomLighting *ruangan, float *watt)
{
    ruangan->N = (ruangan->penerangan * ruangan->panjang * ruangan->lebar) / (*watt * 10 * ruangan->UF * 0.75);
    roundf(ruangan->N); // lampu->watt * 10 untuk mengoversi terang lampu dari lumen ke watt

    printf(" Banyak lampu yang perlu Anda beli adalah sebanyak %.2f buah.\n", roundf(ruangan->N));

    if (ruangan->N > 10.00) {
        printf(" Kami menyarankan Anda untuk membeli lampu dengan daya yang lebih besar agar pencahayaan dan penempatan pemasangan lampu yang lebih efisien");
        printf(" Anda bisa menggunakan lampu dengan watt sebesar %f", *watt * roundf(ruangan->N) / 10);
    }
}

// Tabel data kebutuhan penerangan suatu ruangan secara umum
void dataRuang()
{
    printf("\n\n");
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
}

// Penjelasan program
void penjelasanProgram() {
    printf("\n\n");
    printf("\nProgram ini berfungsi untuk membantu Anda menentukan berapa banyak bohlam lampu yang perlu Anda beli untuk keperluan penerangan ruangan Anda.\n");
    printf("Program akan meminta beberapa input dari Anda, seperti panjang dan lebar ruangan,tingkat pencahayaan yang dibutuhkan (dalam lux), \n");
    printf("besar daya lampu yang hendak Anda beli, dan Utilization Factor. Anda dapat melihat perkiraan tingkat pencahayaan yang dibutuhkan pada menu 3 dan Utilization Factor pada menu 4.");
    printf("\n\n");
}

// Function tampilan awal layar
void masuk()
{
    printf("\n\n");
    printf("======================================\n"
           "|     Selamat Datang Di Aplikasi     |\n"
           "|     Lamp Efficiency Calculator     |\n"
           "|             Kelompok 9             |\n"
           "|        Pemrograman Dasar 01        |\n"
           "======================================\n");
    printf("!--- Tekan ENTER untuk memulai aplikasi ---!");
    getchar();
    Sleep(1);
    system("CLS"); // Membersihkan layar
}

// Function tampilan program selesai
void keluar()
{
    system("CLS"); // Membersihkan layar
    Sleep(1);
    printf("\n\n\n\n\n\n\n");
    printf("\t\t\t\t\t\t\t\t======================================\n");
    printf("\t\t\t\t\t\t\t\t|~ ~ ~ ~ ~ ~ ~ ~ Keluar ~ ~ ~ ~ ~ ~ ~ ~|\n");
    printf("\t\t\t\t\t\t\t\t======================================\n\n");
    Sleep(1);      // menjeda program selama 1.6 detik
    system("CLS"); // Membersihkan layar
}