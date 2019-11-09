#ifndef PLAYER_S
#define PLAYER_S
#include <iostream>
#include <vector>
using namespace std;


// Player klass med medlemmarna Namn och Po�ng
class Players
{
public:
	string name;
	int points;
	//Standard Constructor, deconstucktor
	Players();
	// Egen Constructor
	Players(string, int);
	~Players();
};


// Klass Highscore som struklturera Po�nglistan
class HighScore
{
public:
	// Reserverar Storlek p� listan vid start.
	int listSize = 0;

	HighScore();
	// Andv�ndas vid manuell inmatning 
	// HighScore(int);
	~HighScore();
	// metod f�r att l�gga till spelare
	void Add(vector<Players>&, string, int);
	// Metod att Skriva ut po�nglistan
	void Print(vector<Players>&);

private:
	// Privat metod till klassen f�r att sortera.
	void Sort(vector<Players>&, int);
};

#endif 
