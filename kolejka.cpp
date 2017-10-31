/*
Zadeklarowanie kolejki na klasie jako ³añcuchu odsy³aczowym.
Z góry za³o¿one, ¿e kolejka jest na int-ach. Czyli nie jest to zrobione na szablonie.
Opis danych w obiekcie klasy queue:
	first - wskaŸnik na pierwszy element kolejki
	last - wskaŸnik na ostatni element kolejki
	s - pomocniczy licznik do przechowywania informacji, ile elementów zawiera dana kolejka
Opis metod obietu klasy queue:
	bool empty() - metoda sprawdzaj¹ca, czy s¹ jakieœ elementy w kolejce
	void push(int l) - metoda dodaj¹ca element na koniec kolejki
	void pop() - metoda zdejmuj¹ca pierwszy element z kolejki, bez wypisywania b¹dŸ zwracania
	int front() - metoda zwracajaca wartoœæ pierwszego elementu kolejki
	int back() - metoda zwracaj¹ca ostatni element kolejki
	void out() - metoda wypisuj¹ca wszystkie elementy kolejki. Pomocniczo do sprawdzania, czy wszystko dzia³a, jak nale¿y.
	int size() - metoda zwracaj¹ca iloœæ elementów kolejki. Nie jest za ka¿dym razem liczone w pêtli, lecz po prostu za ka¿dym razem
				przy dodawaniu elementu zwiêkszany jest licznik s o jeden. W razie zdejmowania pierwszego elementu, s jest pomniejszane o 1.
	konstruktor - ustawia wskaŸnik pierwszego elementu na NULL i licznik na zero
	konstruktor kopiuj¹cy - kopiuje wskaŸnik na pierwszy element kolejki, wskaŸnik na ostatni element kolejki oraz licznik wyrazów s.
	destruktor - metoda liniowa, id¹ca po kolei po wszystkich elementach. Zastepuje wskaznik na pierwszy wskaznikiem na nastepny element
	kasuj¹c jednoczesnie pierwszy( mo¿na powiedzieæ, ¿e to funkcja pop w pêtli while).
*/
#include<iostream>

using namespace std;

struct queue_s{
	int value;
	queue_s *next;
};

class queue
{
	queue_s *first;
	queue_s *last;
	int s;
	
	public:
		bool empty();						//sprawdzenie, czy kolejka jest pusta
		void push(int);						//dodanie elementu na koniec kolejki
		int pop();							//zdjêcie elementu z koñca kolejki
		void out();							//wypisanie elementów kolejki. Pomocniczo.
		int size();
		int front();
		int back();
		queue();							//kostruktor
		queue(queue&);						//konstruktor kopiuj¹cy
		~queue();							//destruktor
};

queue::queue():						//konstruktor
	first(NULL),
	s(0)
{
	;
}

queue::queue(queue & newq)
{
	s=newq.s;
	first=newq.first;
	last=newq.last;
	//cout << "Konstruktor kopiujacy" << endl;
}

queue::~queue(){
	//cout << "Destruktor" << endl;
	//queue_s *newq = new queue_s;
	
	while(first!=NULL)					//problemy. Przy zamykaniu programu z jakiegoœ powodu siê wysypuje. Tak to dzia³a normalnie.
	{
		//cout << "Usuniety wlasnie element byl rowny: " << first->value << endl;
		queue_s *newq = first->next;
		delete first;
		//cout << "Usuniety" << endl;
		//queue_s *first=newq;
		first=newq;
	}
}

bool queue::empty()
{
	if(first==NULL)
	{
		return true;
	} 
	else
	{
		return false;
	}
}

void queue::push(int l)
{

	if(this->empty())
	{	
		first=new queue_s;
		first->value=l;
		first->next=NULL;
		last=first;
	}
	else{
		queue_s *newq=new queue_s;
		newq->value=l;
		newq->next=NULL;
		last->next=newq;
		last=newq;
		//delete newq; ??? czy to czasem nie usunie wartoœci pod wskaŸnikiem?
	}
	s++;
}

void queue::out()
{
	queue_s *newq=first;
	while(newq!=NULL)
	{
		cout << newq->value << endl;;
		newq=newq->next;
	}
}

int queue::pop()
{
	queue_s *newq = first->next;
	delete first;
	first=newq;
	s--;
}

int queue::front()				
{
	return first->value;
}

int queue::back()
{
	return last->value;
}

int queue::size()
{
	return s;
}

int main()
{
	queue dumdum;
	int wyb, liczba;
	cout << "Ile elementow chcesz podac?" << endl;
	cin >> wyb;
	
	for(int j=0;j<wyb;j++)
	{
		cout << "Wprowadz wyraz kolejki: " << endl;
		cin >> liczba;
		dumdum.push(liczba);
	}
	cout << "A teraz wypisanie naszej kolejki: " << endl;
	dumdum.out();
	cout << "Zdjecie pierwszego elementu" << endl;
	dumdum.pop();
	dumdum.out();
	cout << "Pierwszy element: " << dumdum.front() << endl;
	cout << "Ostatni element: " << dumdum.back() << endl;
	cout << "Rozmiar: " << dumdum.size() << endl;
	
	//cout << "Dzialanie konstruktora kopiujacego: " << endl;
	queue dimdim(dumdum);
	//dimdim.out();
	dumdum.~queue();
	
	{
		queue domdom=dimdim;
		domdom.push(10);
	}
	
	
	system("PAUSE");
	return 0;
}

