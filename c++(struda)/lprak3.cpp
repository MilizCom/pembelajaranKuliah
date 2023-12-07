#include <iostream>
#include <string.h>
using namespace std;

char nim[100][7];
char nama[100][31];
char matkul[100][20];
char dosen [100][31];
int na[100];
int cek =0;

char NimMin[7], NimMax[7];
char namamin[31], namamax[31];
char matkulmax[31], matkulmin[31];
char dosenmax[31],dosenmin[31];
int i, j, nilaiMin, nilaiMax,jumlah;
float rata2;
void carirentang(){
    int minim,maxim;
    cout << "masukkan nilai minimal" << endl;
    cin >> minim;
    cout << "masukkan nilai maximal" << endl;
    cin >> maxim;
    cout << "data anda yang sesuai : " << endl;
    for(int i=0;i<100;i++){
        if (na[i]>=minim&&na[i]<=maxim){
            cout<<"\nnama: " << nama[i];
            cout<<"\nnim: " << nim[i];
            cout<<"\nmatkul: " << matkul[i];
            cout<<"\ndosen: " << dosen[i];
            cout<<"\nnilai: " << na[i];
        }
    }

}
int nilaiMaximal(){
	
    for (j = 1; j < i; j++) {
        if (na[j] > nilaiMax) {
            nilaiMax = na[j];
            strcpy(NimMax, nim[j]);
            strcpy(namamax, nama[j]);
            strcpy(matkulmax, matkul[j]);
            strcpy(dosenmax, dosen[j]);
        }
    }
}
int nilaiMinimal(){
    for (j = 1; j < i; j++) {
        if (na[j] < nilaiMin) {
            nilaiMin = na[j];
            strcpy(NimMin, nim[j]);
            strcpy(namamin, nama[j]);
            strcpy(matkulmin, matkul[j]);
            strcpy(dosenmin, dosen[j]);
        }
    }
}
int nilaiRata2(){
    rata2 = jumlah / i;
    nilaiMin = na[0];
    nilaiMax = na[0];

    strcpy(namamax, nama[0]);
    strcpy(NimMax, nim[0]);
    strcpy(matkulmax, matkul[0]);
    strcpy(dosenmax,dosen[0]);
    strcpy(namamin, nama[0]);
    strcpy(NimMin, nim[0]);
    strcpy(matkulmin, matkul[0]);
    strcpy(dosenmin, dosen[0]);

}
int carinama(){
    string namac;
    cin >> namac;
    for (int i =0;i<100;i++){
        if (namac==nama[i]){
            cout<<"data anda : \nnama: " << nama[i];
            cout<<"\nnim: " << nim[i];
            cout<<"\nmatkul: " << matkul[i];
            cout<<"\ndosen: " << dosen[i];
            cout<<"\nnilai: " << na[i];
        }
    }
}
int carimatkul(){
    string matkulc;
    cin >> matkulc;
    for (int i =0;i<100;i++){
        if (matkulc==matkul[i]){
            cout<<"data anda : \nnama: " << nama[i];
            cout<<"\nnim: " << nim[i];
            cout<<"\nmatkul: " << matkul[i];
            cout<<"\ndosen: " << dosen[i];
            cout<<"\nnilai: " << na[i];
        }
    }
}
int semuadata(){
    cout<<"semua data anda: \n";
    for (int i =0;i<cek;i++){
        cout<<"\ndata anda : \nnama: " << nama[i];
        cout<<"\nnim: " << nim[i];
        cout<<"\nmatkul: " << matkul[i];
        cout<<"\ndosen: " << dosen[i];
        cout<<"\nnilai: " << na[i] << endl;
    }
}
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
        cek++;

        cout << "Input Nama: ";
        cin >> nama[i];

        cout << "Input Nilai Akhir: ";
        cin >> na[i];

        cout << "Input Mata kuliah: ";
        cin >> matkul[i];

        cout << "Input nama Dosen: ";
        cin>>  dosen[i];

        jumlah += na[i];
        i++;

    } while (true);

	nilaiRata2();
	nilaiMaximal();
    nilaiMinimal();
    int pil;
    ulang:
    cout << "masukkan pilihan \n1.cari data berdasar nama.\n2.cari data berdasar kelas.\n3.tampilkan semua data\n4. tampilkan data berdasar range nilai\n";
    cin >> pil;
    switch (pil){
        case 1 : 
        carinama();
        break;
        case 2:
        carimatkul();
        break;
        case 3: 
        semuadata();
        break;
        case 4:
        carirentang();
        break;
        default :
        goto ulang;
    } 
    char pih;
    cout << "\nlanjut?y/t;" << endl;
    cin >> pih;
    if (pih=='y'){
        goto ulang;
    }


    cout << "\n\nRata-rata nilai akhir = " << rata2 << endl;
    cout << "Mahasiswa dengan nilai akhir tertinggi : \n";
    cout << "NIM: " << NimMax << " dengan Nama : " << namamax << "\nmata kuliah: " << matkulmax << " dosen: " << dosenmax <<" dan Nilai Akhir: " << nilaiMax << endl;
    cout << "Mahasiswa dengan nilai akhir terendah : \n";
    cout << "NIM: " << NimMin << " dengan Nama : " << namamin << "\nmata kuliah: " << matkulmin << " dosen: " << dosenmin << " dan Nilai Akhir: " << nilaiMin;

    return 0;
}

