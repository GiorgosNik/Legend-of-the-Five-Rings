#include <iostream>
#include <vector>
#include <GreenCard>		//Fate Deck	���� �� �����������
#include <BlackCard>		//Dynasty Deck	-//-
using namespace std;

class Player 
{
private:
	int honour;
    int numOfProvinces = 4;
    int balance = 0;
    list<GreenCard*> Fate;		//�� ������ ��� vector �� list, list ���������� �� deckBuilder
    list<BlackCard*> Dynasty;
    vector<Card> handCards;
    vector<BlackCard> provinces;
    vector<BlackCard> Army;
public:
    Player(int handCards)
	{
		//��������� ��� deckBuilder ��� ���� ������ shufle ��� ������ �� Green ��� Fate, Black ��� Dynasty
		//�� ��� ���� �� ������ �� ����� ��� ������ ���
		//����� ������ ��� ������ ��� decks ���� handCards ������ ��� ����� ��� ����� ��� ������
		//������ ��� Stronghold �������� Stronghold(string "��������STRONGHOLD���") ��� �� ������ ������ honour ���
		//���� getters ��� ���� �������� ��� Player, honour, balance ���
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
        //���� pop ��� ��� �� �����
    }

    void buyProvince()
	{
        for(int n : dynDeck)
		{
            if(dynDeck<n>.isProvince)
			{
                //print card details including price
                //������� �� �������� ����������� ��� ������ �� .print()
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

