#include <iostream>
using namespace std;

int main()
{
	int data[12]={3,6,7,2,1,2,9,5,1,9,32,1};
	int *a;
	
	cout<<&a<<" Nilai pointer A"<<endl;
	
	
	for (int i=0;i<4;i++)
	{
		for (int k=0;k<i;k++)
		{
			cout<<"  ";
		}
		
		for (int j=0;j<4-i;j++)
		{
			cout<<"* "	;
		}
		cout<<endl;	
	}
	
	return(0);
}
