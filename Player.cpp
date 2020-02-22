#include <iostream>
#include <vector>
#include <GreenCard>		//Fate Deck	μαζί με συναρτήσεις
#include <BlackCard>		//Dynasty Deck	-//-
using namespace std;

class Player 
{
private:
	int honour;
    int numOfProvinces = 4;
    int balance = 0;
    list<GreenCard*> Fate;		//Το άλλαξα απο vector σε list, list επιστρέφει το deckBuilder
    list<BlackCard*> Dynasty;
    vector<Card> handCards;
    vector<BlackCard> provinces;
    vector<BlackCard> Army;
public:
    Player(int handCards)
	{
		//Φτιάχνεις ένα deckBuilder και μετά κάνεις shufle και δίνεις το Green στο Fate, Black στο Dynasty
		//Αν θές βάλε να ζητάει το όνομα του παίκτη κλπ
		//Μόλις βάλεις τις κάρτες στα decks βάλε handCards αριθμό απο αυτές στα χέρια του παικτή
		//Φτιάξε ενα Stronghold καλώντας Stronghold(string "ΟΝΟΜΑΤΟΥSTRONGHOLDΕΔΩ") για να δώσεις αρχικό honour κλπ
		//Κάνε getters για κάθε στοιχείο του Player, honour, balance κλπ
	}

    void loseProvince()
	{
	    //player loses a health point
        numOfprovinces--;
    }

    void untapEverything()
	{
        //change state of all player cards to untapped
    }

    void drawFateCard()
	{
        //κάνε pop μια απο τη λίστα
    }

    void buyProvince()
	{
        for(int n : dynDeck)
		{
            if(dynDeck<n>.isProvince)
			{
                //print card details including price
                //μπορείς να τυπώσεις πληροφορίες της κάρτας με .print()
                cout << "Buy province? (1 : Yes/0 : No)";
                int choice;
                cin >> choice;
                if (choice == 1 && dynDeck<n>.getPrice <= balance)
				{
                    provinces.pushback(dynDeck<n>);
                    //remove card from dyndeck?
                    //remove money from balance
                    //increment province counter

                }

            }

        }

    }
    bool isArmyEmpty(){
    	return Army.empty();
	}

};

