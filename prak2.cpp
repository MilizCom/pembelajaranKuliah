#include <iostream> 
#include <conio.h>
using namespace std;
struct nilai
{
	int nt, nm, nf, ab; 
	float na;
};
struct alamat
{
	string jalan;
	string kelDes;
	string kecamatan;
	string kabupaten;
};

struct asisten
{
	string nama;
	string matkul;
	alamat Alamat;
	
};
struct DataMhs
{ 
char nim[10]; 
char nama [30]; 
nilai Nilai;
asisten Asisten;
};

int main()
{
	ulang:
	int max;
	cout<<"masukkan berapa mahasiswa ingin di tambah : ";cin>>max;
	DataMhs mhs[max];
	for (int i=0;i<max;i++){
	cout<<"Menghitung Nilai akhir: \n";
	cout<<"Masukkan NIM : "; cin>>mhs[i].nim; 
	cout<<"Masukkan Nama : "; cin>>mhs[i].nama; 
	cout<<"Masukkan Alamat : \n jalan: ";cin>>mhs[i].Asisten.Alamat.jalan;
	cout<<"Kelurahan/desa : ";cin>>mhs[i].Asisten.Alamat.kelDes;
	cout<<"Kecamatan : ";cin>>mhs[i].Asisten.Alamat.kecamatan;
	cout<<"Kabupaten : ";cin>>mhs[i].Asisten.Alamat.kabupaten;
	cout<<"masukkan Nilai Absen : ";cin>>mhs[i].Nilai.ab;
	cout<<"Masukkan Nilai Tugas: "; cin>>mhs[i].Nilai.nt; 
	cout<<"Masukkan Nilai Mid : "; cin>>mhs[i].Nilai.nm; 
	cout<<"Masukkan Nilai Final: "; cin>>mhs[i].Nilai.nf;
	cout<<"Masukkan Matkul : ";cin>>mhs[i].Asisten.matkul;
	cout<<"Masukkan nama asisten : ";cin>>mhs[i].Asisten.nama;
    mhs[i].Nilai.na = (0.10*mhs[i].Nilai.ab) + (0.20 * mhs[i].Nilai.nt) + (0.30 * mhs[i].Nilai.nm) + (0.40 * mhs[i].Nilai.nf);
	}
		char pil;
	cout<<"ingin edit? y/t : ";cin>>pil;
	if (pil=='y'){
		string ed;
		cout<<"masukkan nim yang mau di edit =";cin>>ed;
		for(int i=0;i<max;i++){
		if(ed==mhs[i].nim)
		{
			int edit;
			cout<<"pilih data yang mau di edit :\n";
			cout<<"1.nilai absen\n2.nilai tugas\n3.nilai mid\n4.nilai final\n: ";
			cin>>edit;
			switch (edit){
				case 1:
					cout<<"masukkan data baru : ";cin>>edit;
					mhs[i].Nilai.ab=edit;
					mhs[i].Nilai.na = (0.10*mhs[i].Nilai.ab) + (0.20 * mhs[i].Nilai.nt) + (0.30 * mhs[i].Nilai.nm) + (0.40 * mhs[i].Nilai.nf);
					break;
				case 2:
					cout<<"masukkan data baru : ";cin>>edit;
					mhs[i].Nilai.nt=edit;
					mhs[i].Nilai.na = (0.10*mhs[i].Nilai.ab) + (0.20 * mhs[i].Nilai.nt) + (0.30 * mhs[i].Nilai.nm) + (0.40 * mhs[i].Nilai.nf);
					break;
				case 3:
					cout<<"masukkan data baru : ";cin>>edit;
					mhs[i].Nilai.nm=edit;
					mhs[i].Nilai.na = (0.10*mhs[i].Nilai.ab) + (0.20 * mhs[i].Nilai.nt) + (0.30 * mhs[i].Nilai.nm) + (0.40 * mhs[i].Nilai.nf);
					break;
				case 4:
					cout<<"masukkan data baru : ";cin>>edit;
					mhs[i].Nilai.nf=edit;
					mhs[i].Nilai.na = (0.10*mhs[i].Nilai.ab) + (0.20 * mhs[i].Nilai.nt) + (0.30 * mhs[i].Nilai.nm) + (0.40 * mhs[i].Nilai.nf);
					break;
			}
			break;	
		}	
		}		
	}
	for (int i=0;i<max;i++)
	{
    	cout << "Nilai Akhir dari mahasiswa ini ke-"<<i+1<<" = " << mhs[i].Nilai.na << endl;
	}
	cout<<"akhiri program? y/t:";cin>>pil;
	if (pil=='t'){
		goto ulang;
	}
}
