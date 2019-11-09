#include "HighScore.h"

//Standard Constructor
HighScore::HighScore()
{	
	
}
/* Egen Constructor f�r po�nlista storlek vid manuell skapande av objekt lista
HighScore::HighScore(int listSize)
{
	this->listSize = listSize;
}
*/

//Deconstructor
HighScore::~HighScore()
{
}
// En method f�r att andv�nda i ett spel.
void HighScore::Add(vector<Players>& newScoreList, string name, int points)
{
	Players newPlayer(name, points);
	newScoreList.push_back(newPlayer);
}

/* En method f�r att manuellt fylla p� en po�nglista.

void HighScore::Add(vector<Players>& newScoreList, int newListSize)
{
	string name;
	int points;
	
	for (int i = 0; i < newListSize; i++)
	{
		cout << "Skriv ditt namn: ";
		cin >> name;
		cout << "Ange po�ng: ";
		cin >> points;

		Players newPlayer(name, points);
		newScoreList.push_back(newPlayer);
		cout << "\n";
	}
	cout << "\n";

}
*/

//Metod f�r att skriva ut po�nglista
void HighScore::Print(vector<Players>& newScoreList)
{
	// skapa en storleks variable "unsigned " f�r vector
	unsigned int size = newScoreList.size();
	//Sortera med privar metod Sort innan utskrift.
	HighScore::Sort(newScoreList, size);
	// F�r varge element io vectoren skriv ut med lite styling :P
	for (unsigned int i = 0; i < size; i++)
	{
		cout << i + 1 << ":       " << newScoreList[i].name << "             " << newScoreList[i].points << endl;
		cout << "\n";

	}
	cout << "\n";
}
/*En metod f�r bubble sortering med rekursion.
Sorterar h�gst till l�gst*/
void HighScore::Sort(vector<Players>& newScoreList, int n)
{
	// N�r vectorn �r p� f�rsta elementet d� �r den klar.
	if (n == 1)
	{
		return;
	}
	// Itterera �ver vektorn tills n - 1  
	for (int i = 0; i < n - 1; i++)
	{
		// om n�sta po�ng �r st�rre
		if (newScoreList[i].points < newScoreList[i + 1].points)
		{
			// Byt plats p� elementen.
			swap(newScoreList[i], newScoreList[i + 1]);
		}
	}
	// K�r om, men tittar inte p� sista elementet d� det �r minst och p� plats.
	HighScore::Sort(newScoreList, n - 1);
	
}
// Metod f�r att byta (x pointer,  y pointer)
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}