#include "HighScore.h"


Players::Players()
{
	points = 0;
}
// Construktor till Spelar objekt.
Players::Players(string _name, int _points)
{
	name = _name;
	points = _points;
}

Players::~Players()
{

}