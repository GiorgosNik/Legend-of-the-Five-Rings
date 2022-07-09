all: BlackCard.cpp BlackCard.hpp GreenCard.cpp GreenCard.hpp Card.cpp Card.hpp Core.cpp DeckBuilder.cpp DeckBuilder.hpp Follower.cpp Follower.hpp Item.cpp Item.hpp Personality.hpp Personality.cpp Holding.cpp Holding.hpp Player.cpp Player.hpp Phases.cpp Phases.hpp Stronghold.cpp Stronghold.hpp TypeConverter.cpp TypeConverter.hpp GameBoard.cpp GameBoard.hpp
		g++ -c -std=c++11 Card.cpp
		g++ -c -std=c++11 BlackCard.cpp
		g++ -c -std=c++11 GreenCard.cpp
		g++ -c -std=c++11 Item.cpp
		g++ -c -std=c++11 Follower.cpp
		g++ -c -std=c++11 Holding.cpp
		g++ -c -std=c++11 Personality.cpp
		g++ -c -std=c++11 Stronghold.cpp
		g++ -c -std=c++11 DeckBuilder.cpp
		g++ -c -std=c++11 Phases.cpp
		g++ -c -std=c++11 GameBoard.cpp
		g++ -c -std=c++11 TypeConverter.cpp
		g++ -c -std=c++11 Player.cpp
		g++ -o game -std=c++11 Core.cpp Card.o BlackCard.o GreenCard.o Item.o Follower.o Holding.o Personality.o Stronghold.o DeckBuilder.o Phases.o GameBoard.o TypeConverter.o Player.o

clean:
	rm Card.o BlackCard.o GreenCard.o Item.o Follower.o Holding.o Personality.o Stronghold.o DeckBuilder.o Phases.o GameBoard.o TypeConverter.o Player.o
