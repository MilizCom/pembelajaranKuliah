#include <iostream>
#include <string.h>
using namespace std;

char nim[100][7];
char nama[100][31];
int na[100];

char NimMin[7], NimMax[7];
char namamin[31], namamax[31];
int i, j, nilaiMin, nilaiMax,jumlah;
float rata2;

int main() {
    i = 0;
    jumlah = 0;

    cout << "Masukkan data mahasiswa : \n";

    do {
        cout << "Input Nomor Induk Mahasiswa masukkan x jika ingin berhenti:  ";
        cin >> nim[i];

        if (strcmp(nim[i], "x") == 0) {
            break;
        }

        cout << "Input Nama: ";
        cin >> nama[i];

        cout << "Input Nilai Akhir: ";
        cin >> na[i];

        jumlah += na[i];
        i++;

    } while (true);

    rata2 = jumlah / i;
    nilaiMin = na[0];
    nilaiMax = na[0];

    strcpy(namamax, nama[0]);
    strcpy(NimMax, nim[0]);
    strcpy(namamin, nama[0]);
    strcpy(NimMin, nim[0]);

    for (j = 1; j < i; j++) {
        if (na[j] < nilaiMin) {
            nilaiMin = na[j];
            strcpy(NimMin, nim[j]);
            strcpy(namamin, nama[j]);
        }

        if (na[j] > nilaiMax) {
            nilaiMax = na[j];
            strcpy(NimMax, nim[j]);
            strcpy(namamax, nama[j]);
        }
    }

    cout << "Rata-rata nilai akhir = " << rata2 << endl;
    cout << "Mahasiswa dengan nilai akhir tertinggi : \n";
    cout << "NIM: " << NimMax << " dengan Nama : " << namamax << " dan Nilai Akhir: " << nilaiMax << endl;
    cout << "Mahasiswa dengan nilai akhir terendah : \n";
    cout << "NIM: " << NimMin << " dengan Nama : " << namamin << " dan Nilai Akhir: " << nilaiMin;

    return 0;
}

