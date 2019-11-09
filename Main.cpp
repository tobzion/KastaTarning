#include "HighScore.h"
#include "time.h"
#include "windows.h"

int main()
{
	setlocale(LC_ALL, "Swedish");
	// tid för random rullningen, NULL för at resetta vid körning.
	srand((unsigned int)time(NULL));
	// Variablar för kasta tärning spel
	int choice = 0;
	int roll = 0;
	int total = 0;
	int diceSize = 6;
	int playerScore = 0;
	string playerName;
	// ny vector för Spelarna av klassen Players, och Tärningar
	vector<Players> scoreList;
	vector<int> diceCollection;
	//Meny vid start
	cout << "-----KASTA TÄRNING-----" << endl;
	cout << "\n";
	cout << "Välkommen, Välj först hur många tärningar som ni vill skall andvändas vid kast." << endl;
	cout << "\n";
	cout << "1: Lägg till en tärning, 0: Avsluta spelet" << endl;
	cout << "\n";
	cout << "Val: ";
	cin >> choice;
	system("CLS"); // rensa skärmen

	// While >0 , bryt loop vid 0
	while (choice > 0)
	{
		// Byt choice. 
		switch (choice)
		{
		case 1:
			// Lägg till en tärning
			diceCollection.push_back(diceSize);
			cout << "En tärning har lags till. " << "Totalt antal: " << diceCollection.size() << endl;
			cout << "\n";
			cout << "Vill du lägga till en till tryck 1, annars börja spelet genom att trycka 3." << endl;
			cout << "\n";
			cout << "Du kan även ta bort en tärning om du valt förmånga. " << endl;
			cout << "\n";
			break;

		case 2:
			// Ta bort en tärning
			if (!diceCollection.empty())
			{
				diceCollection.pop_back();
				cout << "En tärning har tagits bort " << "Totalt antal: " << diceCollection.size() << endl;
				cout << "\n";
			}
			//Om vector tom 
			else
				cout << "Det finns inga tärningar" << endl;
			break;
			// Starta spel
		case 3:
			// för tills storlek av antal tärningar
			for (unsigned int i = 0; i < diceCollection.size(); i++)
			{
				// rand % värdet på tärning vector[i] +1
				roll = rand() % diceCollection[i] + 1;
				cout << "Tärning " << i + 1 << ": " << roll << endl;
				cout << "\n";
				total += roll;
			}
			cout << "Total poäng: " << total << endl;
			playerScore += total;
			cout << "______________________________" << endl;
			cout << "Skriv ditt namn(Ett ord): ";
			// Efter cast ta andvändarens namn
			cin >> playerName;
			// Lägg till spelare med poäng till vector.
			HighScore().Add(scoreList, playerName, total);
			cout << playerName << " har lagts till på poängslistan!" << endl;
			// vänta 3 sec
			Sleep(3000);
			// sätt total till 0
			total = 0;
			system("CLS");
			break;
		case 4:
			// skriv ut sorterad poänglista
			cout << "Plats     Namn          Poäng" << endl;
			cout << "______________________________" << endl;
			HighScore().Print(scoreList);
			break;
		default:
			// default i fall ej giltigt val
			cout << "Felaktigt val" << endl;
			break;
		}

		cout << "-----KASTA TÄRNING-----" << endl;
		cout << "\n";
		//Menu för på börjat spel

		// om det inte finns några tärningar och ingen har spelat ännu
		if (diceCollection.size() > 0 && scoreList.size() == 0)
		{
			cout << "1: Lägg till en tärning, 2: Ta bort en tärning, 3: Kasta Tärningen/Tärningarna, 0: Avsluta Programmet" << endl;
		}
		// om det finns en redan registrerad spelare
		else if (scoreList.size() > 0)
		{
			// om någon finns på listan. Kan inte lägga till mer tärningar, samma villkor för alla spelare.
			cout << "3: Kasta Tärningen/Tärningarna, 4: Visa poänglistan, 0: Avsluta Programmet" << endl;
		}
		else if (scoreList.size() == 0 && diceCollection.size() == 0)
		{
			// om ingen är på listan och inga tärningar finns.
			cout << "1: Lägg till en tärning, 0: Avsluta Programmet" << endl;
		}
		else
		{
			// annars
			cout << "3: Kasta Tärningen/Tärningarna, 0: Avsluta Programmet" << endl;
		}
		// Val
		cout << "\n";
		cout << "Val: ";
		cin >> choice;
		system("CLS");
	}
	// avslut
	cout << "Tack för att du spelade" << endl;
	cout << "________________________" << endl;
	cout << "\n";
	cout << "Programmet avslutat om 5 Sekunder" << endl;
	// Auto avslut vid stängning :) *fungerar ifs bara på windows!
	Sleep(5000);
	return 0;
}