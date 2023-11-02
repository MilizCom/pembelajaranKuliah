#include <iostream> 
#include <conio.h>
using namespace std;

struct DataMhs
{ 
char nim[10]; 
char nama [30]; 
int nt, nm, nf; 
float na;
};

int main()
{
	int max;
	cout<<"masukkan berapa mahasiswa ingin di tambah : ";cin>>max;
	DataMhs mhs[max];
	for (int i=0;i<max;i++){
	cout<<"Menghitung Nilai akhir: \n";
	cout<<"Masukkan NIM : "; cin>>mhs[i].nim; 
	cout<<"Masukkan Nama : "; cin>>mhs[i].nama; 
	cout<<"Masukkan Nilai Tugas: "; cin>>mhs[i].nt; 
	cout<<"Masukkan Nilai Mid : "; cin>>mhs[i].nm; 
	cout<<"Masukkan Nilai Final: "; cin>>mhs[i].nf;
    mhs[i].na = (0.25 * mhs[i].nt) + (0.35 * mhs[i].nm) + (0.40 * mhs[i].nf);
	}
	for (int i=0;i<max;i++)
	{
    	cout << "Nilai Akhir dari mahasiswa ini ke-"<<i+1<<" = " << mhs[i].na << endl;
	}
}
