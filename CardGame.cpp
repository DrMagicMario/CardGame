/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                      CSI 2372 
                                                                                Card Game Final Project 

                                                                                      Authors
                                                                              Ivan Godoy-Smirnov (8135127)

                                                                                    Due: Dec 4, 2020
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


// C++ program Implementation
/* 
1. You need to decide on class variables and the private and protected interface of the classes. Your mark will depend on a reasonable design and documentation in the code. 
2. Use const as much as possible, you can make any function or operator const as you see fit, even if it is not indicated in the prototype below. 
3. You can add others constructor and destructor to a class if needed.
*/

/* 
Deck class (2 marks): Deck is simple derived class from std::vector. Deck will have the following functions:
    - Deck(istream&, const CardFactory*) is a constructor which accepts an istream and reconstructs the deck from file.
    - Card* draw() returns and removes the top card from the deck.
    - and the insertion operator (friend) to insert all the cards in the deck to an std::ostream. 
*/

class Deck : public std::vector {

};

/* 
DiscardPile class (2 marks): The DiscardPile class holds cards in a std::vector and is similar to Deck. DiscardPile will have the following functions:
    - DiscardPile(istream&, const CardFactory*) is a constructor which accepts an istream and reconstructs the DiscardPile from file.
    - DiscardPile& operator+=(Card*) discards the card to the pile.
    - Card* pickUp() returns and removes the top card from the discard pile.
    - Card* top() returns but does not remove the top card from the discard pile.
    - void print(std::ostream&) to insert all the cards in the DiscardPile to an std::ostream. 
    - and the insertion operator (friend) to insert only the top card of the discard pile to an std::ostream. 
*/

/* 
TradeArea class (3 marks): The TradeArea holds cards in a std::list, and will have the following functions:
    - TradeArea(istream&, const CardFactory*) is a constructor which accepts an istream and reconstruct the TradeArea from file.
    - TradeArea& operator+=(Card*) adds the card to the trade area but it does not check if it is legal to place the card.
    - bool legal(Card*) returns true if the card can be legally added to the TradeArea, i.e., a card of the same bean is already in the TradeArea.
    - Card* trade(string) removes a card of the corresponding bean name from the trade area.
    - int numCards() returns the number of cards currently in the trade area.
    - and the insertion operator (friend) to insert all the cards of the trade area to an std::ostream. 
*/

/* 
Hand class (2 marks): Hand class will have the following functions:
    - Hand(istream&, const CardFactory*) is a constructor which accepts an istream and reconstruct the Hand from file.
    - Hand& operator+=(Card*) adds the card to the rear of the hand.
    - Card* play() returns and removes the top card from the player's hand.
    - Card* top() returns but does not remove the top card from the player's hand.
    - Card* operator[](int) returns and removes the Card at a given index.
    - and the insertion operator (friend) to print Hand on an std::ostream. The hand should print all the cards in order. 
*/

/* 
Player class (3 marks): Player class will have the following functions:
    - Player(std::string&) is a constructor that creates a Player with a given name.
    - Player(istream&, const CardFactory*) is a constructor which accepts anistream and reconstruct the Player from file.
    - std:string getName() get the name of the player.
    - int getNumCoins() get the number of coins currently held by the player.
    - Player& operator+=(int) add a number of coins
    - int getMaxNumChains() returns either 2 or 3.
    - int getNumChains() returns the number of non-zero chains
    - Chain& operator[](int i) returns the chain at position i.
    - void buyThirdChain() adds an empty third chain to the player for three coins. The functions reduces the coin count for the player by two. If the player does not have enough coins then an exception NotEnoughCoins is thrown.
    - void printHand(std::ostream&, bool) prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true) to the supplied ostream.
    - and the insertion operator (friend) to print a Player to an std::ostream. The player's name, the number of coins in the player's possession and each of the chains (2 or 3, some possibly empty) should be printed. 
        The player printout may look as follows:
            Dave 3 coins 
            Red RRRR 
            Blue B 
*/

/* 
Table class (2 marks): Table will manage all the game components. It will hold two objects of type Player, the Deck and the DiscardPile, as well as the TradeArea. Table class will have the following functions:
    - Table(istream&, const CardFactory*) is a constructor which accepts an istream and reconstruct the Table from file.
    - bool win(std::string&) returns true when a player has won. The name of the player is returned by reference (in the argument). The winning condition is that all cards from the deck must have been picked up and then the player with the most coins wins.
    - void printHand(bool) prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true).
    - and the insertion operator (friend) to print a Table to an std::ostream. The two players, the discard pile, the trading area should be printed. This is the top level print out. Note that a complete output with all cards for the pause functionality is printed with a separate function.
*/

/*
CardFactory class (2 marks): The card factory serves as a factory for all the bean cards. CardFactory class will have the following functions:
    - constructor in which all the cards need to be created in the numbers needed for the game (see the above table).
    - static CardFactory* getFactory() returns a pointer to the only instance of CardFactory.
    - Deck getDeck() returns a deck with all 104 bean cards. Note that the 104 bean cards are always the same but their order in the deck needs to be different every time. Use std::shuffle to achieve this.
*/

/*
Pseudo Code (4 marks for main loop) The pseudo-code of the main loop (game loop) is as follows. 

Setup:
• Input the names of 2 players. Initialize the Deck and draw 5 cards for the Hand of each Player; or
• Load paused game from file.

Code:
While there are still cards on the Deck 
    if pause save game to file and exit 
    For each Player
        Display Table
        Player draws top card from Deck 
        If TradeArea is not empty
            Add bean cards from the TradeArea to chains or discard them.
        Play topmost card from Hand.
        If chain is ended
            cards for chain are removed and player receives coin(s). 
        If player decides to
            Play the now topmost card from Hand.
        If chain is ended
            cards for chain are removed and player receives coin(s). 
        If player decides to
            Show the player's full hand and player selects an arbitrary card
            Discard the arbitrary card from the player's hand and place it on the discard pile. 
        Draw three cards from the deck and place cards in the trade area
        while top card of discard pile matches an existing card in the trade area
            draw the top-most card from the discard pile and place it in the trade area
        end
        for all cards in the trade area
            if player wants to chain the card 
                chain the card.
            else
                card remains in trade area for the next player.
            end
        Draw two cards from Deck and add the cards to the player's hand (at the back).
    end 
end
*/