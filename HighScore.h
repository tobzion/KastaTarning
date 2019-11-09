#ifndef PLAYER_S
#define PLAYER_S
#include <iostream>
#include <vector>
using namespace std;


// Player klass med medlemmarna Namn och Poäng
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


// Klass Highscore som struklturera Poänglistan
class HighScore
{
public:
	// Reserverar Storlek på listan vid start.
	int listSize = 0;

	HighScore();
	// Andvändas vid manuell inmatning 
	// HighScore(int);
	~HighScore();
	// metod för att lägga till spelare
	void Add(vector<Players>&, string, int);
	// Metod att Skriva ut poänglistan
	void Print(vector<Players>&);

private:
	// Privat metod till klassen för att sortera.
	void Sort(vector<Players>&, int);
};

#endif 
