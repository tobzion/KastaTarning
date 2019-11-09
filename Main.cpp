#include "HighScore.h"
#include "time.h"
#include "windows.h"

int main()
{
	setlocale(LC_ALL, "Swedish");
	// tid f�r random rullningen, NULL f�r at resetta vid k�rning.
	srand((unsigned int)time(NULL));
	// Variablar f�r kasta t�rning spel
	int choice = 0;
	int roll = 0;
	int total = 0;
	int diceSize = 6;
	int playerScore = 0;
	string playerName;
	// ny vector f�r Spelarna av klassen Players, och T�rningar
	vector<Players> scoreList;
	vector<int> diceCollection;
	//Meny vid start
	cout << "-----KASTA T�RNING-----" << endl;
	cout << "\n";
	cout << "V�lkommen, V�lj f�rst hur m�nga t�rningar som ni vill skall andv�ndas vid kast." << endl;
	cout << "\n";
	cout << "1: L�gg till en t�rning, 0: Avsluta spelet" << endl;
	cout << "\n";
	cout << "Val: ";
	cin >> choice;
	system("CLS"); // rensa sk�rmen

	// While >0 , bryt loop vid 0
	while (choice > 0)
	{
		// Byt choice. 
		switch (choice)
		{
		case 1:
			// L�gg till en t�rning
			diceCollection.push_back(diceSize);
			cout << "En t�rning har lags till. " << "Totalt antal: " << diceCollection.size() << endl;
			cout << "\n";
			cout << "Vill du l�gga till en till tryck 1, annars b�rja spelet genom att trycka 3." << endl;
			cout << "\n";
			cout << "Du kan �ven ta bort en t�rning om du valt f�rm�nga. " << endl;
			cout << "\n";
			break;

		case 2:
			// Ta bort en t�rning
			if (!diceCollection.empty())
			{
				diceCollection.pop_back();
				cout << "En t�rning har tagits bort " << "Totalt antal: " << diceCollection.size() << endl;
				cout << "\n";
			}
			//Om vector tom 
			else
				cout << "Det finns inga t�rningar" << endl;
			break;
			// Starta spel
		case 3:
			// f�r tills storlek av antal t�rningar
			for (unsigned int i = 0; i < diceCollection.size(); i++)
			{
				// rand % v�rdet p� t�rning vector[i] +1
				roll = rand() % diceCollection[i] + 1;
				cout << "T�rning " << i + 1 << ": " << roll << endl;
				cout << "\n";
				total += roll;
			}
			cout << "Total po�ng: " << total << endl;
			playerScore += total;
			cout << "______________________________" << endl;
			cout << "Skriv ditt namn(Ett ord): ";
			// Efter cast ta andv�ndarens namn
			cin >> playerName;
			// L�gg till spelare med po�ng till vector.
			HighScore().Add(scoreList, playerName, total);
			cout << playerName << " har lagts till p� po�ngslistan!" << endl;
			// v�nta 3 sec
			Sleep(3000);
			// s�tt total till 0
			total = 0;
			system("CLS");
			break;
		case 4:
			// skriv ut sorterad po�nglista
			cout << "Plats     Namn          Po�ng" << endl;
			cout << "______________________________" << endl;
			HighScore().Print(scoreList);
			break;
		default:
			// default i fall ej giltigt val
			cout << "Felaktigt val" << endl;
			break;
		}

		cout << "-----KASTA T�RNING-----" << endl;
		cout << "\n";
		//Menu f�r p� b�rjat spel

		// om det inte finns n�gra t�rningar och ingen har spelat �nnu
		if (diceCollection.size() > 0 && scoreList.size() == 0)
		{
			cout << "1: L�gg till en t�rning, 2: Ta bort en t�rning, 3: Kasta T�rningen/T�rningarna, 0: Avsluta Programmet" << endl;
		}
		// om det finns en redan registrerad spelare
		else if (scoreList.size() > 0)
		{
			// om n�gon finns p� listan. Kan inte l�gga till mer t�rningar, samma villkor f�r alla spelare.
			cout << "3: Kasta T�rningen/T�rningarna, 4: Visa po�nglistan, 0: Avsluta Programmet" << endl;
		}
		else if (scoreList.size() == 0 && diceCollection.size() == 0)
		{
			// om ingen �r p� listan och inga t�rningar finns.
			cout << "1: L�gg till en t�rning, 0: Avsluta Programmet" << endl;
		}
		else
		{
			// annars
			cout << "3: Kasta T�rningen/T�rningarna, 0: Avsluta Programmet" << endl;
		}
		// Val
		cout << "\n";
		cout << "Val: ";
		cin >> choice;
		system("CLS");
	}
	// avslut
	cout << "Tack f�r att du spelade" << endl;
	cout << "________________________" << endl;
	cout << "\n";
	cout << "Programmet avslutat om 5 Sekunder" << endl;
	// Auto avslut vid st�ngning :) *fungerar ifs bara p� windows!
	Sleep(5000);
	return 0;
}