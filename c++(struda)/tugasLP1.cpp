//program mencari luas segitiga dengan constanta
#include <iostream>
using namespace std;

int main() {
	string chat = "luas segitiga = ";
    double panjang_alas = 5.0;
    int tinggi_segitiga = 8;
    double luas_segitiga;
    const float setengah = 0.5;
    luas_segitiga = setengah * panjang_alas * tinggi_segitiga;
    cout << chat << luas_segitiga << endl;
    return 0;
}

//program hitung registrasi dan penentuan nilai tertinggin dengan output nama,no.reg,dan nilai

#include<iostream>
using namespace std;
int main(){
	int reg;
	string nama;
	char bahasa,pilih='y';
	unsigned nilai;
	int regMaxB,regMaxP,regMaxC;
	string namaB,namaP,namaC;
	unsigned nilaiB,nilaiP,nilaiC;
	while (pilih=='y'){
		cout<<"kursus bahasa pemrograman\n";
		ulang1:
		cout<<"masukkan no.registrasi (max 6 digit): ";cin>>reg;
		if (reg>=1000000) {
			cout<<"ada masalah\n";
			goto ulang1;
		}
		cout<<"masukkan nama: ";cin>>nama;
		ulang4:
		cout<<"masukkan bahasa yang ingin di pelajari: \n1.Basic(B)\n2.Pascal(P)\n3.C++(C)\n: ";
		cin>>bahasa;
		if (bahasa!='B'&&bahasa!='P'&&bahasa!='C'){
			cout<<"ulang\n";
			goto ulang4;
		}
		ulang3:
		cout<<"masukkan nilai: ";cin>>nilai;
		if (nilai>100){
			cout<<"ada yang salah\n";
			goto ulang3;
		}
		if (bahasa == 'B'&&nilai>nilaiB){
			regMaxB = reg;
			namaB=nama;
			nilaiB=nilai;
		}
		if (bahasa == 'P'&&nilai>nilaiP){
			regMaxP = reg;
			namaP=nama;
			nilaiP=nilai;
		}
		if (bahasa == 'C'&&nilai>nilaiC){
			regMaxC = reg;
			namaC=nama;
			nilaiC=nilai;
		}
		ulang2:
		cout<<"masih ada yang mau di tambah(y/t): ";cin>>pilih;
		if (pilih!='y'&&pilih!='t'){
			cout<<"ada masalah ini\n";
			goto ulang2;
		}
	}
	cout<<"nilai tertinggi basic : \n";
	cout<<regMaxB<<endl;
	cout<<namaB<<endl;
	cout<<nilaiB<<endl;
	cout<<"nilai tertinggi pascal : \n";
	cout<<regMaxP<<endl;
	cout<<namaP<<endl;
	cout<<nilaiP<<endl;
	cout<<"nilai tertinggi C++ : \n";
	cout<<regMaxC<<endl;
	cout<<namaC<<endl;
	cout<<nilaiC<<endl;
}