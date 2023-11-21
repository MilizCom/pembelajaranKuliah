#include <iostream>
#include <climits>
using namespace std;

struct Alamat {
    char jalan[50];
    char kelurahan[30];
    char kecamatan[30];
};

struct dtMhs {
    char nim[15];
    char nama[30];
    Alamat *alamat; // Pointer ke struct Alamat
    int nilai;
};

int main() {
    int jumlah;
    dtMhs *ptrMhs;
    cout << "masukkan jumlah mahasiswa : "; cin >> jumlah;
    ptrMhs = new dtMhs[jumlah];

    for (int i = 0; i < jumlah; i++) {
        ptrMhs[i].alamat = new Alamat; // Alamat dialokasikan untuk setiap mahasiswa
        cout << "masukkan nim mahasiswa : "; cin >> ptrMhs[i].nim;
        cout << "masukkan nama mahasiswa : "; cin >> ptrMhs[i].nama;

        // Input alamat
        cout << "masukkan jalan mahasiswa : "; cin >> ptrMhs[i].alamat->jalan;
        cout << "masukkan kelurahan mahasiswa : "; cin >> ptrMhs[i].alamat->kelurahan;
        cout << "masukkan kecamatan mahasiswa : "; cin >> ptrMhs[i].alamat->kecamatan;

        cout << "masukkan nilai mahasiswa : "; cin >> ptrMhs[i].nilai;
        cout << endl;
    }

            for(int i = 0; i < jumlah; i++) {
                cout << "daftarMhs :\n";
                cout << "nim : " << ptrMhs[i].nim << endl;
                cout << "nama : " << ptrMhs[i].nama << endl;
                cout << "alamat :\n";
                cout << "  Jalan: " << ptrMhs[i].alamat->jalan << endl;
                cout << "  Kelurahan: " << ptrMhs[i].alamat->kelurahan << endl;
                cout << "  Kecamatan: " << ptrMhs[i].alamat->kecamatan << endl;
                cout << "nilai : " << ptrMhs[i].nilai << endl;
                cout << endl;
            }

    delete[] ptrMhs;

    return 0;
}
