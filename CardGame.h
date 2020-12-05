/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                      CSI 2372 
                                                                                Card Game Final Project

                                                                                      Authors
                                                                              Ivan Godoy-Smirnov (8135127)
                                                                              Mustafa Basheer (8792149)

                                                                                    Due: Dec 7, 2020
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Card;
class Deck;
class DiscardPile;
class Chain;
class Table;
class TradeArea;
class Hand;
class Player;
class CardFactory;

int main() {
    Blue blue;
    Card *blue1 = &blue;
    blue1->getName();
    return 0;
}


/*
Each component of the game is represented by its corresponding class: Card, Deck, DiscardPile, Chain, Table, TradeArea, Coins, Hand, Players.

The classes Deck, DiscardPile, Hand and Chain are all containers holding cards:
- Deck will initially hold all the cards which will have to be shuffled to produce a randomized order, then players' hands are dealt and during game play players draw cards from the Deck. 
        There is no insertion into the Deck. Deck can therefore usefully extend a std::vector.

- DiscardPile must support insertion and removal but not at random locations but all at the end. 
        Again a std::vector will work fine but here we can use simple aggregation.

- Hand is well mapped by a queue since players have to keep their hand in order and the first card drawn is the first card played. 
        The only derivation form this pattern is if players discard a card from the middle in Step 4 in the above description of a player's turn. Therefore, we can use a std::list to remove at an arbitrary location efficiently with a std::queue adapter.

- Chain is also a container and will have to grow and shrink as the game progresses. 
        Again insertion is only to one end of the chain and a std::vector is fine (see below). 
            A template class will have to created for Chain being parametric in the type of card. In this project, we will instantiate Chain for the corresponding bean card.

- Card will be an abstract base class and the eight different bean cards will be derived from it (inheritance). 
        All containers will hold cards through the base type. However, standard containers do not work well with polymorphic types because they hold copies (slicing will occur).

- TradeArea class will have to hold cards openly and support random access insertion and removal.

- CardFactory will generate all cards, and so, we will explore the factory pattern. A factory ensures that there is only a single unit in the program that is responsible to create and delete cards. 
        Other parts of the program will only use pointers to access the cards. Note that means, we will delete the copy constructor and assignment operator in Card.



You will be using:
- exceptions: with downcasts to distinguish between different bean cards, and also of IllegalType if a player attempts to place a card illegally into a chain (a chain that holds different beans).

- standard algorithms: such as std::shuffle at the beginning to ensure the cards in the deck are in a random order.

- stream insertion and extraction operator to save and reload the game from file (for pause functionality).
*/