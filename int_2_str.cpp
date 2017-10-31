//Program zamieniaj¹cy lczbê int na string. Dwie funkcje. Jedna zamienia tylko jedn¹ cyfrê danej liczby (przydatne przy zamianie liczby 
//w postaci dziesiêtnej z okreœlon¹ dok³adnoœci¹, np. 1000), druga zamienia ca³¹ liczbê. Piersza korzysta z drugiej, aby nie pisaæ dwa razy
//tej samej rzeczy.
#include<iostream>

using namespace std;

char int_2_string(short num)
{
	switch(num)
	{
		case 1:
			{
				return '1';
				break;
			}
		case 2:
			{
				return '2';
				break;
			}
		case 3:
			{
				return '3';
				break;
			}
		case 4:
			{
				return '4';
				break;
			}
		case 5:
			{
				return '5';
				break;
			}
		case 6:
			{
				return '6';
				break;
			}
		case 7:
			{
				return '7';
				break;
			}
		case 8:
			{
				return '8';
				break;
			}
		case 9:
			{
				return '9';
				break;
			}
		case 0:
			{
				return '0';
				break;
			}
		default:
			{
				cout << "Podany zostal zly argument funkcji" << endl;
			}
	}
}

char* int_2_str(int num)
{
	int nub=num;					//pomocnicza do obliczenia ilosci cyfr
	int pow=1;						//zmienna do przechowywania potêg dziesi¹tki
	int digit=0;					//zmienna do przechowywania ilosci cyfr
	while(nub>0)
	{
		pow*=10;
		nub/=10;
		digit++;
	}
	nub=num;
	char *tab = new char[digit+1];
	//cout << digit << endl;
	for(int i=0; i<digit; i++)
	{
		pow/=10;
		tab[i]=int_2_string(nub/pow);
		nub%=pow;
		//cout << tab << endl;
		
	}
	tab[digit]=NULL;
	return tab;
}

int main()
{
	int k;
	cout << "Podaj, jaka liczbe chcesz zamienic na string: " << endl;
	cin >>k;
	cout << "String tej liczby ma postac: " << int_2_str(k) << endl;
	return 0;
}

