#include <iostream>
#include <string>

using namespace std;

// Struktur untuk merepresentasikan node di dalam linked list
struct Mahasiswa {
    string nama;
    string nim;
    float nilaiAbsensi;
    float nilaiTugas;
    float nilaiMid;
    float nilaiFinal;
    float nilaiAkhir;
    Mahasiswa* next;
};

// Fungsi untuk menambahkan data mahasiswa baru
void tambahMahasiswa(Mahasiswa*& head, string nama, string nim, float absensi, float tugas, float mid, float final) {
    Mahasiswa* newMahasiswa = new Mahasiswa;
    newMahasiswa->nama = nama;
    newMahasiswa->nim = nim;
    newMahasiswa->nilaiAbsensi = absensi;
    newMahasiswa->nilaiTugas = tugas;
    newMahasiswa->nilaiMid = mid;
    newMahasiswa->nilaiFinal = final;
    newMahasiswa->nilaiAkhir = (absensi * 0.1) + (tugas * 0.25) + (mid * 0.25) + (final * 0.4);

    newMahasiswa->next = head;
    head = newMahasiswa;
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(Mahasiswa* head) {
    Mahasiswa* current = head;
    while (current != NULL) {
        cout << "Nama: " << current->nama << endl;
        cout << "NIM: " << current->nim << endl;
        cout << "Nilai Absensi: " << current->nilaiAbsensi << endl;
        cout << "Nilai Tugas: " << current->nilaiTugas << endl;
        cout << "Nilai Mid: " << current->nilaiMid << endl;
        cout << "Nilai Final: " << current->nilaiFinal << endl;
        cout << "Nilai Akhir: " << current->nilaiAkhir << endl << endl;

        current = current->next;
    }
}

// Fungsi untuk mencari data mahasiswa berdasarkan NIM
Mahasiswa* cariMahasiswaByNIM(Mahasiswa* head, string nim) {
    Mahasiswa* current = head;
    while (current != NULL) {
        if (current->nim == nim) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Mahasiswa tidak ditemukan
}

// Fungsi untuk mencari data mahasiswa berdasarkan nilai akhir minimum
Mahasiswa* cariMahasiswaByMinNilaiAkhir(Mahasiswa* head, float minNilaiAkhir) {
    Mahasiswa* current = head;
    while (current != NULL) {
        if (current->nilaiAkhir >= minNilaiAkhir) {
            return current;
        }
        current = current->next;
    }
    return NULL; // Mahasiswa tidak ditemukan
}

int main() {
    Mahasiswa* daftarMahasiswa = NULL;

    // Menambahkan data mahasiswa
    tambahMahasiswa(daftarMahasiswa, "John Doe", "123456", 90, 85, 75, 85);
    tambahMahasiswa(daftarMahasiswa, "Jane Doe", "789012", 80, 75, 80, 90);
    tambahMahasiswa(daftarMahasiswa, "Bob Smith", "345678", 95, 90, 85, 80);

    // Menampilkan data mahasiswa
    cout << "Data Mahasiswa:\n";
    tampilkanDataMahasiswa(daftarMahasiswa);

    // Mencari data mahasiswa berdasarkan NIM
    string nimCari = "789012";
    Mahasiswa* mahasiswaByNIM = cariMahasiswaByNIM(daftarMahasiswa, nimCari);
    if (mahasiswaByNIM != NULL) {
        cout << "Data Mahasiswa dengan NIM " << nimCari << " ditemukan:\n";
        cout << "Nama: " << mahasiswaByNIM->nama << endl;
        cout << "Nilai Akhir: " << mahasiswaByNIM->nilaiAkhir << endl;
    } else {
        cout << "Data Mahasiswa dengan NIM " << nimCari << " tidak ditemukan.\n";
    }

    // Mencari data mahasiswa berdasarkan nilai akhir minimum
    float minNilaiAkhir = 80;
    Mahasiswa* mahasiswaByMinNilaiAkhir = cariMahasiswaByMinNilaiAkhir(daftarMahasiswa, minNilaiAkhir);
    if (mahasiswaByMinNilaiAkhir != NULL) {
        cout << "\nData Mahasiswa dengan nilai akhir minimal " << minNilaiAkhir << " ditemukan:\n";
        cout << "Nama: " << mahasiswaByMinNilaiAkhir->nama << endl;
        cout << "NIM: " << mahasiswaByMinNilaiAkhir->nim << endl;
        cout << "Nilai Akhir: " << mahasiswaByMinNilaiAkhir->nilaiAkhir << endl;
    } else {
        cout << "\nTidak ada mahasiswa dengan nilai akhir minimal " << minNilaiAkhir << " ditemukan.\n";
    }

    return 0;
}
