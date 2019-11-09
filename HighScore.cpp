#include "HighScore.h"

//Standard Constructor
HighScore::HighScore()
{	
	
}
/* Egen Constructor för poänlista storlek vid manuell skapande av objekt lista
HighScore::HighScore(int listSize)
{
	this->listSize = listSize;
}
*/

//Deconstructor
HighScore::~HighScore()
{
}
// En method för att andvända i ett spel.
void HighScore::Add(vector<Players>& newScoreList, string name, int points)
{
	Players newPlayer(name, points);
	newScoreList.push_back(newPlayer);
}

/* En method för att manuellt fylla på en poänglista.

void HighScore::Add(vector<Players>& newScoreList, int newListSize)
{
	string name;
	int points;
	
	for (int i = 0; i < newListSize; i++)
	{
		cout << "Skriv ditt namn: ";
		cin >> name;
		cout << "Ange poäng: ";
		cin >> points;

		Players newPlayer(name, points);
		newScoreList.push_back(newPlayer);
		cout << "\n";
	}
	cout << "\n";

}
*/

//Metod för att skriva ut poänglista
void HighScore::Print(vector<Players>& newScoreList)
{
	// skapa en storleks variable "unsigned " för vector
	unsigned int size = newScoreList.size();
	//Sortera med privar metod Sort innan utskrift.
	HighScore::Sort(newScoreList, size);
	// För varge element io vectoren skriv ut med lite styling :P
	for (unsigned int i = 0; i < size; i++)
	{
		cout << i + 1 << ":       " << newScoreList[i].name << "             " << newScoreList[i].points << endl;
		cout << "\n";

	}
	cout << "\n";
}
/*En metod för bubble sortering med rekursion.
Sorterar högst till lägst*/
void HighScore::Sort(vector<Players>& newScoreList, int n)
{
	// När vectorn är på första elementet då är den klar.
	if (n == 1)
	{
		return;
	}
	// Itterera över vektorn tills n - 1  
	for (int i = 0; i < n - 1; i++)
	{
		// om nästa poäng är större
		if (newScoreList[i].points < newScoreList[i + 1].points)
		{
			// Byt plats på elementen.
			swap(newScoreList[i], newScoreList[i + 1]);
		}
	}
	// Kör om, men tittar inte på sista elementet då det är minst och på plats.
	HighScore::Sort(newScoreList, n - 1);
	
}
// Metod för att byta (x pointer,  y pointer)
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}