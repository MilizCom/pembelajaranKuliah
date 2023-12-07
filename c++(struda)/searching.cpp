#include <iostream>
using namespace std;

int main()
{
	int data[];
	int bil_cari,a=0;
	cin>>data[0];
	cout<<"Masukkan data yang mau dicari : ";
	cin>>bil_cari;
	
	for (int i=0;i<12;i++)
	{
		if (bil_cari == data[i])
		{
			cout<<data[i]<<" Ditemukan pada indeks = "<<i<<endl;
			a++;
		}
		
		
	}
	if (a==0)
	{
		cout<<"Maaf, data tidak ditemukan !!!!!!!!";
	}
	return(0);
}
