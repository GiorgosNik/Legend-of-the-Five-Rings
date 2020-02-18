#ifndef _TYPECONVERTER_HPP_
#define _TYPECONVERTER_HPP_

#include "Card.hpp"
#include "Personality.hpp"
#include "Holding.hpp"
#include "Follower.hpp"
#include "Item.hpp"
class TypeConverter
{
public:
	TypeConverter();
	void getCorrectType(Black *card, Personality **person, Holding **hold);
	void getCorrectType(Green *card, Follower **follow, Item **item);
	Personality *getPersonality(Black *d);
	Holding *getHolding(Black *d);
	Follower *getFollower(Green *d);
	Item *getItem(Green *d);
};

#endif
