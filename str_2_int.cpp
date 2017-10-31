//Program zmieniaj¹cy podan¹ liczbê  jako string (lub char) do int. Zbudowane jako klasa(?), dzia³a na kodzie ASCII.
//Nie uwzglêdnione zosta³y liczby ujemne oraz u³amkowe (zmiennoprzecinkowe)
#include<iostream>

using namespace std;

int str_2_int(char *word)
{
	int num=0;
	for(int i=0; word[i]!=NULL;i++)
	{
		switch(word[i])
		{
			case '1':
				{
					num+=1;
					break;
				}
			case '2':
				{
					num+=2;
					break;
				}
			case '3':
				{
					num+=3;
					break;
				}
			case '4':
				{
					num+=4;
					break;
				}
			case '5':
				{
					num+=5;
					break;
				}
			case '6':
				{
					num+=6;
					break;
				}
			case '7':
				{
					num+=7;
					break;
				}
			case '8':
				{
					num+=8;
					break;
				}
			case '9':
				{
					num+=9;
					break;
				}
			}
		num*=10;
	}
	num/=10;
	//cout << "Funkcja: " << j << endl;
	return num;
}

int main()
{
	char tab[20];
	cout << "Podaj pewien ciag znakow: " << endl;
	cin >> tab;
	
	/*cout << "Podany ciag ma postac: " << endl;
	for(int i=0; tab[i]!=NULL; i++)
	{
		cout << tab[i];
	}*/													//Sprawdzenie, czy NULL dzia³a jako oznaczenie koñca ³añcucha
	//cout << endl << j << endl;
	
	cout << "Liczba ta zapisana jako int ma postac: " << str_2_int(tab) << endl;
	
	return 0;
}

