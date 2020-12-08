/*///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
                                                                                      CSI 2372 
                                                                                Card Game Final Project 

                                                                                      Authors
                                                                              Ivan Godoy-Smirnov (8135127)
                                                                              Mustafa Basheer (8792149)
                                                                              Sop Nwakaeze (8901361)

                                                                                    Due: Dec 7, 2020
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
#include "CardGame.h"

// C++ program Implementation
/* 
1. You need to decide on class variables and the private and protected interface of the classes. Your mark will depend on a reasonable design and documentation in the code. 
2. Use const as much as possible, you can make any function or operator const as you see fit, even if it is not indicated in the prototype below. 
3. You can add others constructor and destructor to a class if needed.
*/

/*
Card class and its derived classes (4 marks) Create the bean card and its derived classes: 
Card is the base class and will be abstract. Card class will have the following pure virtual functions:
    - virtual int getCardsPerCoin(int coins) will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins.
    - virtual string getName() returns the full name of the card (e.g., Blue).
    - virtual void print(ostream& out) inserts the first character for the card into the output stream supplied as argument. If the first character is the same for two cards, use uppercase for the first one and lowercase for the second one (For example B for Blue and b for Black).
    - A global stream insertion operator for printing any objects of such a class which implements the “Virtual Friend Function Idiom” with the class hierarchy.
*/ 

//abstract class: class that has pure virtual functions inside it
class Card{ // delete the copy constructor and assignment operator in Card.
    protected:
        string name;
    public:
        Card() {
            name = "";
        };
        void setName(string str) { name = str; };
        //deleted copy constructor and assignment operator
        Card(const Card&) = delete;
        Card &operator=(const Card&) = delete;
        //pure virtual functions: has no implementation in the parent class, so need to be implemented (override) in children classes
        virtual ~Card() = default;
        virtual int getCardsPerCoin(int coins) = 0; // will implement in the derived classes the above table for how many cards are necessary to receive the corresponding number of coins. -pure virtual function
        virtual string getName() = 0; // returns the full name of the card (e.g., Blue). -pure virtual function
        virtual void print(ostream & out) = 0; // inserts the first character for the card into the output stream supplied as argument. -pure virtual function
        // and a global stream insertion operator for printing any objects of such a class which implements the “Virtual Friend Function Idiom” with the class hierarchy.
        friend ostream& operator << (ostream & out, const Card & c);
};

/*Blue, Chili, Stink, Green, soy, black, Red and garden are derived classes (from Card) and will have to be concrete classes (when we override all oure virtual functions in derived classes, we call the derived class a concrete class).*/

/*A bean card can be printed to console with its first character of its name.*/
/*Total in deck Blue=20, Chili=18, Stink=16, Green=14, soy=12, black=10, Red=8 and garden=6*/

class Blue : public Card{
    // Card Value per coin [coin,card]: [1,4], [2,6], [3,8], [4,10]
    public:
        Blue() {
            name = "Blue";
        };
    int getCardsPerCoin(int coins) override {
        //numbers are from the table in the project document
        try {
            if (coins < 1 || coins > 4) {
                throw coins;
            }
            else if (coins == 1) {
                return 4;
            }
            else if (coins == 2) {
                return 6;
            }
            else if (coins == 3) {
                return 8;
            }
            else if (coins == 3) {
                return 10;
            }
        }
        catch (int ex) {
            cout << "Exception: coins cannot be less than one or greater than 4!";
        }
        return 0;
    };
    string getName() override {
        cout << name << endl;
        return name;
    };
    void print(ostream& out) override {
        out << "B";
    };
};

class Chili : public Card{
    // Card Value per coin[coin,card]: [1,3], [2,6], [3,8], [4,9]
    public:
        Chili() {
            name = "Chili";
        };
    int getCardsPerCoin(int coins) override {
        //numbers are from the table in the project document
        try {
            if (coins < 1 || coins > 4) {
                throw coins;
            }
            else if (coins == 1) {
                return 3;
            }
            else if (coins == 2) {
                return 6;
            }
            else if (coins == 3) {
                return 8;
            }
            else if (coins == 3) {
                return 9;
            }
        }
        catch (int ex) {
            cout << "Exception: coins cannot be less than one or greater than 4!";
        }
        return 0;
    };
    string getName() override {
        cout << name << endl;
        return name;
    };
    void print(ostream& out) override {
        out << "C";
    };
};

class Stink : public Card{
    // Card Value per coin[coin,card]: [1,3], [2,5], [3,7], [4,8]
    public:
        Stink() {
            name = "Stink";
        };
    int getCardsPerCoin(int coins) override {
        //numbers are from the table in the project document
        try {
            if (coins < 1 || coins > 4) {
                throw coins;
            }
            else if (coins == 1) {
                return 3;
            }
            else if (coins == 2) {
                return 5;
            }
            else if (coins == 3) {
                return 7;
            }
            else if (coins == 3) {
                return 8;
            }
        }
        catch (int ex) {
            cout << "Exception: coins cannot be less than one or greater than 4!";
        }
        return 0;
    };
    string getName() override {
        cout << name << endl;
        return name;
    };
    void print(ostream& out) override {
        out << "S";
    };
};

class Green : public Card{
    // Card Value per coin[coin,card]: [1,3], [2,5], [3,6], [4,7]
    public:
        Green() {
            name = "Green";
        };
    int getCardsPerCoin(int coins) override {
        //numbers are from the table in the project document
        try {
            if (coins < 1 || coins > 4) {
                throw coins;
            }
            else if (coins == 1) {
                return 3;
            }
            else if (coins == 2) {
                return 5;
            }
            else if (coins == 3) {
                return 6;
            }
            else if (coins == 3) {
                return 7;
            }
        }
        catch (int ex) {
            cout << "Exception: coins cannot be less than one or greater than 4!";
        }
        return 0;
    };
    string getName() override {
        cout << name << endl;
        return name;
    };
    void print(ostream& out) override {
        out << "G";
    };
};

class soy : public Card{
    // Card Value per coin [coin,card]: [1,2], [2,4], [3,6], [4,7]
    public:
        soy() {
            name = "soy";
        };
    int getCardsPerCoin(int coins) override {
        //numbers are from the table in the project document
        try {
            if (coins < 1 || coins > 4) {
                throw coins;
            }
            else if (coins == 1) {
                return 2;
            }
            else if (coins == 2) {
                return 4;
            }
            else if (coins == 3) {
                return 6;
            }
            else if (coins == 3) {
                return 7;
            }
        }
        catch (int ex) {
            cout << "Exception: coins cannot be less than one or greater than 4!";
        }
        return 0;
    };
    string getName() override {
        cout << name << endl;
        return name;
    };
    void print(ostream& out) override {
        out << "s";
    };
};

class black : public Card{
    // Card Value per coin [coin,card]: [1,2], [2,4], [3,5], [4,6]
    public:
        black() {
            name = "black";
        };
    int getCardsPerCoin(int coins) override {
        //numbers are from the table in the project document
        try {
            if (coins < 1 || coins > 4) {
                throw coins;
            }
            else if (coins == 1) {
                return 2;
            }
            else if (coins == 2) {
                return 4;
            }
            else if (coins == 3) {
                return 5;
            }
            else if (coins == 3) {
                return 6;
            }
        }
        catch (int ex) {
            cout << "Exception: coins cannot be less than one or greater than 4!";
        }
        return 0;
    };
    string getName() override {
        cout << name << endl;
        return name;
    };
    void print(ostream& out) override {
        out << "b";
    };
};

class Red : public Card{
    // Card Value per coin [coin,card]: [1,2], [2,3], [3,4], [4,5]
    public:
        Red() {
            name = "Red";
        };
    int getCardsPerCoin(int coins) override {
        //numbers are from the table in the project document
        try {
            if (coins < 1 || coins > 4) {
                throw coins;
            }
            else if (coins == 1) {
                return 2;
            }
            else if (coins == 2) {
                return 3;
            }
            else if (coins == 3) {
                return 4;
            }
            else if (coins == 3) {
                return 5;
            }
        }
        catch (int ex) {
            cout << "Exception: coins cannot be less than one or greater than 4!";
        }
        return 0;
    };
    string getName() override {
        cout << name << endl;
        return name;
    };
    void print(ostream& out) override {
        out << "R";
    };
};

class garden : public Card{
    // Card Value per coin [coin,card]: [1,-], [2,2], [3,3], [4,-]
    public:
        garden(){
            name = "garden";
        };
    int getCardsPerCoin(int coins) override {
        //numbers are from the table in the project document
        try {
            if (coins < 2 || coins > 3) {
                throw coins;
            }
            else if (coins == 2) {
                return 2;
            }
            else if (coins == 3) {
                return 3;
            }
        }
        catch (int ex) {
            cout << "Exception: coins cannot be less than 2 or greater than 3!";
        }
        return 0;
    };
    string getName() override {
        cout << name << endl;
        return name;
    };
    void print(ostream& out) override {
        out << "g";
    };
};

/*
Chain class (2 marks): The template Chain will have to be instantiated in the program by the concrete derived card classes, e.g., Chain<Red>. 
    Note that in this example Chain will hold the Red cards by pointer in a std::vector<Red*>. 
    So, you will need an abstract chain interface (Chain_Base) to be able to reference chains of any type from the Player class.
    Chain will have the following functions:
        - Chain(istream&, const CardFactory*) is a constructor which accepts an istream and reconstructs the chain from file when a game is resumed.
        - Chain<T>& operator+=(Card*) adds a card to the Chain. If the run-time type does not match the template type of the chain and exception of type IllegalType needs to be raised.
        - int sell() counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin.
        - and the insertion operator (friend) to print Chain on an std::ostream. The hand should print a start column with the full name of the bean, for example with four cards:
            Red RRRR
*/

// A template class will have to created for Chain being parametric in the type of card.
// container holding cards --> std::vector is fine

class Chain {
  class IllegalTypeException: public std::exception{
    virtual const char* what() const throw(){
        return "IllegalTypeException";
    }
};
  
  
  class Chain_Base{
protected:
    std::string type_bean;
public:
    Chain_Base(std::string type_bean) : type_bean(type_bean) {};**********************
    virtual ~Chain_Base() = default;
    virtual int sell() = 0;
    std::string getBean() {
        return type_bean;
    }
    virtual void print(std::ostream&) const = 0;
    
    friend std::ostream& operator<<(std::ostream& out, Chain_Base& chain) {
        out << chain.getBean() << "\t";
        chain.print(out);
        return out;
    };
};

template<class T> class Chain : public Chain_Base {
    std::vector<T*> type_card;
public:
    
    Chain() {
    }
    
    Chain(T* x) :
    Chain_Base(x->getName()) {
        type_card->push_back(x);
    };
    virtual ~Chain() {
        delete type_card;
    }

    bool chainEnded() {
        if (myChain.empty()) {
            return true;
        };
        return false;
    }
    
    //add a card to the chain
    virtual Chain<T>& operator+=(T* bean) {
        try {
            type_card.push_back(bean);
        }
        catch (IllegalTypeException e) {
            std::cout << "Invalid bean type:" << getBean() << " Cannot be added to:" << type_card.at(0)->getName() << std::endl;
        }
        return *this;
    }
    
    //counts the number cards in the current chain and
    //returns the number of coins according to the function Card::getCardsPerCoin.
    virtual int sell() override {
        
        int num_cards = static_cast<int>(type_card.size());
      
        return type_card.at(0)->getCoinsPerCard(num_cards);
    }
    
    //prints the name of the chain and the nuber of cards the chain contains in the format "Ruby  R R R"
    virtual void print(std::ostream& o) const override{
        for (auto& i : type_card) {
            i.print(o);
            o << " ";
            }
    }
            
    void setBeanType(std::string nameofbean) {
       type_bean = nameofbean;
    }
};
   // private:
    //vector<Card*> myChain;
    //public:
    //Chain(); //constructor
    //Chain(istream&, const CardFactory*); //constructor which accepts an istream and reconstructs the chain from file when a game is resumed.
    //~Chain() = default; //destructor
    //Chain& operator+=(Card*);
    //int sell(); //counts the number cards in the current chain and returns the number coins according to the function Card::getCardsPerCoin.
    //ostream &print(ostream &os, const Chain &item);//insertion operator (friend) to print Chain on an std::ostream. The hand should print a start column with the full name of the bean, for example with four cards:
>>>>>>> 26985f2d55734642adbb1092d58054e9ade171ee
            //Red RRRR
};


/* 
Deck class (2 marks): Deck is simple derived class from std::vector. Deck will have the following functions:
    - Deck(istream&, const CardFactory*) is a constructor which accepts an istream and reconstructs the deck from file.
    - Card* draw() returns and removes the top card from the deck.
    - the insertion operator (friend) to insert all the cards in the deck to an std::ostream. 
*/
//container holding cards --> std::vector is fine
class Deck: public vector<Card*>{ 
    private:
    vector<Card*> myDeck;
    public:
    Deck(istream&, const CardFactory*); //constructor which accepts an istream and reconstructs the deck from file.
    ~Deck() = default; //destructor
    Card* draw(); 
    ostream& print(ostream& os, const Deck& item);//the insertion operator (friend) to insert all the cards in the deck to an std::ostream.
    friend istream& operator >> (istream& in, const  CardFactory* c);
    friend ostream& operator << (ostream& out, const Deck& d);
};

Card* Deck::draw() { //returns and removes the top card from the deck.
    Card *myPick = myDeck.back();
    myDeck.pop_back();
    return myPick;
}

/* 
DiscardPile class (2 marks): The DiscardPile class holds cards in a std::vector and is similar to Deck. DiscardPile will have the following functions:
    - DiscardPile(istream&, const CardFactory*) is a constructor which accepts an istream and reconstructs the DiscardPile from file.
    - DiscardPile& operator+=(Card*) discards the card to the pile.
    - Card* pickUp() returns and removes the top card from the discard pile.
    - Card* top() returns but does not remove the top card from the discard pile.
    - void print(std::ostream&) to insert all the cards in the DiscardPile to an std::ostream. 
    - and the insertion operator (friend) to insert only the top card of the discard pile to an std::ostream. 
*/

//container holding cards --> std::vector is fine
class DiscardPile{
    private: 
    vector<Card*> myDiscPile; //container
    public:
    DiscardPile(istream&, const CardFactory*); //constructor which accepts an istream and reconstructs the DiscardPile from file.
    ~DiscardPile() = default; //destructor
    DiscardPile& operator+=(Card*);
    Card* pickUp();
    Card* top();
    void print(std::ostream&); 
    ostream &print(ostream &os, const DiscardPile &item);//the insertion operator (friend) to insert only the top card of the discard pile to an std::ostream.
};

DiscardPile& DiscardPile::operator += (Card *discCard) { //discards the card to the pile.
    myDiscPile.push_back(discCard);
    return *this;
}

Card* DiscardPile:: pickUp() { //returns and removes the top card from the discard pile.
    Card *myPick = myDiscPile.back();
    myDiscPile.pop_back();
    return myPick;
}

Card* DiscardPile:: top() { //returns but does not remove the top card from the discard pile.
    return myDiscPile.back();
}

void DiscardPile::print(std::ostream &os) { //insert all the cards in the DiscardPile to an std::ostream
    for (int i = 0; i < myDiscPile.size(); i++){
        os << myDiscPile[i];
    }
}


/* 
TradeArea class (3 marks): The TradeArea holds cards in a std::list, and will have the following functions:
    - TradeArea(istream&, const CardFactory*) is a constructor which accepts an istream and reconstruct the TradeArea from file.
    - TradeArea& operator+=(Card*) adds the card to the trade area but it does not check if it is legal to place the card.
    - bool legal(Card*) returns true if the card can be legally added to the TradeArea, i.e., a card of the same bean is already in the TradeArea.
    - Card* trade(string) removes a card of the corresponding bean name from the trade area.
    - int numCards() returns the number of cards currently in the trade area.
    - and the insertion operator (friend) to insert all the cards of the trade area to an std::ostream. 
*/

class TradeArea{
    private:
    list<Card*> myList; //holds cards in a std::list
    public:
    TradeArea(istream& file, const CardFactory*); //constructor which accepts an istream and reconstruct the TradeArea from file.
    ~TradeArea() = default; //destructor
    TradeArea& operator+=(Card*);  
    list<Card*> getTradeArea() {
        return myList;
    };
    bool legal(Card*); 
    Card* trade(string); 
    int numCards(); 
    ostream &print(ostream &os, const TradeArea &item);//insertion operator (friend) to insert all the cards of the trade area to an std::ostream. 
};

TradeArea& TradeArea::operator += (Card *tradeCard){ //adds the card to the trade area but it does not check if it is legal to place the card.
    myList.push_back(tradeCard);
    return *this;
}

bool TradeArea::legal(Card *tradeCard){ //returns true if the card can be legally added to the TradeArea, i.e., a card of the same bean is already in the TradeArea.
    bool mybool = false;
    for (auto i: myList){
        if (i->getName() == tradeCard->getName()){
            mybool = true;
            break;
        }
    }
    return mybool;
}

Card* TradeArea:: trade(string card) { //removes a card of the corresponding bean name from the trade area.
    Card *myPick;
    for (auto i : myList){
        if (card == i->getName()){
            myPick = i;
            myList.remove(i);
            break;
        }
    }
    return myPick;
}

int TradeArea::numCards(){ //returns the number of cards currently in the trade area.
    return myList.size();
}

/* 
Hand class (2 marks): Hand class will have the following functions:
    - Hand(istream&, const CardFactory*) is a constructor which accepts an istream and reconstruct the Hand from file.
    - Hand& operator+=(Card*) adds the card to the rear of the hand.
    - Card* play() returns and removes the top card from the player's hand.
    - Card* top() returns but does not remove the top card from the player's hand.
    - Card* operator[](int) returns and removes the Card at a given index.
    - and the insertion operator (friend) to print Hand on an std::ostream. The hand should print all the cards in order. 
*/

//container holding cards --> we can use a std::list to remove at an arbitrary location
class Hand{
    private:
    list<Card*> myHand;
    public:
    Hand(istream&, const CardFactory*); //constructor which accepts an istream and reconstruct the Hand from file.
    ~Hand() = default; //destructor
    Hand& operator+=(Card*); 
    Card* play(); 
    Card* top(); 
    Card* operator[](int);
    ostream &print(ostream &os, const Hand &item);//the insertion operator (friend) to print Hand on an std::ostream. The hand should print all the cards in order. 
};

Hand& Hand:: operator+=(Card *handCard){ //adds the card to the rear of the hand.
    myHand.push_back(handCard);
    return *this;
}

Card* Hand::play(){ //returns and removes the top card from the player's hand.
    Card *myPick = myHand.front();
    myHand.pop_front();
    return myPick;
}

Card* Hand::top(){ //returns but does not remove the top card from the player's hand.
    return myHand.front();
}

Card* Hand::operator[](int){ //returns and removes the Card at a given index.
    Card *myPick;
    return myPick; //need to update this
}
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

class Player {
    private:
    string name; // players name
    int coins; // players number of coins
    int chains; // only increment when chain has at least 1 Card in it
    vector<Chain*> myChains; //players chains
    public:
        Player(string& newName) {
            name = newName;
        };
    Player(istream&, const CardFactory*); //constructor which accepts anistream and reconstruct the Player from file.
    ~Player() = default; //destructor
    string getName(); 
    int getNumCoins(); 
    Player& operator+=(int); 
    int getMaxNumChains();
    int getNumChains();
    Chain& operator[](int i); 
    void buyThirdChain(); //adds an empty third chain to the player for three coins. The functions reduces the coin count for the player by two. If the player does not have enough coins then an exception NotEnoughCoins is thrown.
    void printHand(ostream&, bool); //prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true) to the supplied ostream.
    ostream &print(ostream &os, const Player &user);//the insertion operator (friend) to print a Player to an std::ostream. The player's name, the number of coins in the player's possession and each of the chains (2 or 3, some possibly empty) should be printed. 
};

Player::Player(string &newName){ //constructor that creates a Player with a given name.
    name = newName;
}

string Player::getName(){ //get the name of the player.
    return name;
}

int Player::getNumCoins(){ //get the number of coins currently held by the player.
    return coins;
}

Player& Player::operator += (int toAdd) { //add a number of coins
    coins += toAdd;
    return *this;
}

int Player::getMaxNumChains() { //returns either 2 or 3.
    return 2; //for the purpose of this project
}

int Player::getNumChains(){ //returns the number of non-zero chains
    return chains;
}

Chain& Player::operator[](int i){ //returns the chain at position i.
    return *myChains[i];
}

void Player::buyThirdChain(){ //adds an empty third chain to the player for three coins. The functions reduces the coin count for the player by two. If the player does not have enough coins then an exception NotEnoughCoins is thrown.
} 

void Player::printHand(ostream &os, bool select) { //prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true) to the supplied ostream.
    if (select) {

    }
}
/* 
Table class (2 marks): Table will manage all the game components. It will hold two objects of type Player, the Deck and the DiscardPile, as well as the TradeArea. Table class will have the following functions:
    - Table(istream&, const CardFactory*) is a constructor which accepts an istream and reconstruct the Table from file.
    - bool win(std::string&) returns true when a player has won. The name of the player is returned by reference (in the argument). The winning condition is that all cards from the deck must have been picked up and then the player with the most coins wins.
    - void printHand(bool) prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true).
    - and the insertion operator (friend) to print a Table to an std::ostream. The two players, the discard pile, the trading area should be printed. This is the top level print out. Note that a complete output with all cards for the pause functionality is printed with a separate function.
*/

class Table{
    private:
    Player user1,user2;
    Deck myDeck;
    DiscardPile myDiscardPile;
    TradeArea myTradeArea;
    public:
    Table(istream&, const CardFactory*); //constructor which accepts an istream and reconstruct the Table from file.
    ~Table() = default; //destructor
    bool win(std::string&); 
    void printHand(bool); 
    ostream &print(ostream &os, const Table &item);//the insertion operator (friend) to print a Table to an std::ostream. The two players, the discard pile, the trading area should be printed. This is the top level print out. Note that a complete output with all cards for the pause functionality is printed with a separate function.
};

bool Table::win(string& winner){ //returns true when a player has won. The name of the player is returned by reference (in the argument). The winning condition is that all cards from the deck must have been picked up and then the player with the most coins wins.
    bool val = false;

    if (myDeck.size() != 0) {
        return val;
    } else if ((user1.getName()==winner) && (user1.getNumCoins() > user2.getNumCoins())){
        val = true;
    } else if ((user2.getName()==winner) && (user2.getNumCoins() > user1.getNumCoins())) {
        val = true;
    }

    return val;
}

void Table::printHand(bool select){ //prints the top card of the player's hand (with argument false) or all of the player's hand (with argument true).
    return;
}

/*
CardFactory class (2 marks): The card factory serves as a factory for all the bean cards. CardFactory class will have the following functions:
    - constructor in which all the cards need to be created in the numbers needed for the game (see the above table).
    - static CardFactory* getFactory() returns a pointer to the only instance of CardFactory.
    - Deck getDeck() returns a deck with all 104 bean cards. Note that the 104 bean cards are always the same but their order in the deck needs to be different every time. Use std::shuffle to achieve this.
*/
class CardFactory{ // Other parts of the program will only use pointers to access the cards. Note that means, we will delete the copy constructor and assignment operator in Card.
    std::vector<Card> CardPile;
public:
    CardFactory() {
        for (int n = 0; n < 104; n++) {
            if (0 <= n && n < 20) {
                Blue blue;
                CardPile.push_back(blue);
            }
            else if (20 <= n && n < 38) {
                Chili chili;
                CardPile.push_back(chili);
            }
            else if (38 <= n && n < 54) {
                Stink stink;
                CardPile.push_back(stink);
            }
            else if (54 <= n && n < 68) {
                Green green;
                CardPile.push_back(green);
            }
            else if (68 <= n && n < 80) {
                soy soy;
                CardPile.push_back(soy);
            }
            else if (80 <= n && n < 90) {
                black black;
                CardPile.push_back(black);
            }
            else if (90 <= n && n < 98) {
                Red red;
                CardPile.push_back(red);
            }
            else if (98 <= n && n < 104) {
                garden garden;
                CardPile.push_back(garden);
            }
        };
    };
    ~CardFactory() = default;
    static CardFactory* getFactory(); //returns a pointer to the only instance of CardFactory.
    Deck getDeck() {
        std::shuffle(std::begin(CardPile), std::end(CardPile), std::default_random_engine());
        //need to return a deck - not sure how to approach this
    }; //returns a deck with all 104 bean cards. Use std::shuffle
};

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

//for global stream insertion operator "<<", so we can do somthing like "cout << blue" - this is good;
ostream& operator << (ostream& out, const Card& c)
{
    out << c.name << endl;
    return out;
};

//for global stream insertion operator "<<", so we can do somthing like "cout << deck" - not sure if implemented correctly, need to go over it;
ostream& operator << (ostream& out, const Deck& d) {
    for (std::vector<Card*>::const_iterator i = d.myDeck.begin(); i != d.myDeck.end(); ++i)
        out << &i;
    return out;
};


//for global stream insertion operator ">>" - I think this one is good, we just need to implement getFactory method in CardFactory class.
istream& operator >> (istream& in, const CardFactory* cf) {
    in >> cf->getFactory();
    return in;
};

int main() {
    string selection;
    string play;
    string showCards;
    string chainYN;
    Card* discardedCard;
    CardFactory myFactory = CardFactory();
    Deck* myDeck = new Deck(std::cin,&myFactory);
    Table* table = new Table(std::cin, &myFactory);
    TradeArea* tradeArea = new TradeArea(std::cin, &myFactory);
    Chain* chain = new Chain(std::cin, &myFactory);
    Hand* hand = new Hand(std::cin, &myFactory);
    DiscardPile* discardPile = new DiscardPile(std::cin, &myFactory);
    cout<< "would you like to laod a previous game? [y/n]" << endl;
    cin >> selection;
    if (selection == "y"){
        //body to load previous game
    } else {
        //new game
        string p1, p2;
        cout << "please enter the name of player 1: " << endl;
        cin >> p1;
        Player player1(p1);
        cout << "please enter the name of player 2: " << endl;
        cin >> p2;
        Player player2(p2);
        Player players[2] = { player1, player2 };
        
        while (!myDeck->empty()) {
            for (Player p : players) {
                cout << table;
                Card* drawnCard = myDeck->draw();
                if (tradeArea->legal(drawnCard)) {
                    //add bean cards from the TradeArea to chains or discard them -> ???
                    chain->sell();
                }
                hand->play();
                //checks if chain ended 
                if (chain->chainEnded()) {
                    //receive the coins for current chain
                    int coins = chain->sell();
                    //add coins to the player
                    p += coins;
                };
                cout << "would you like to play? [y/n]" << endl;
                cin >> play;
                if (play == "y") {
                    hand->play();
                };
                if (chain->chainEnded()) {
                    //receive the coins for current chain
                    int coins = chain->sell();
                    //add coins to the player
                    p += coins;
                };
                cout << "would you like to show your cards? [y/n]" << endl;
                cin >> showCards;
                //player wants to show cards
                if (showCards == "y") {
                    cout << hand;
                    //draws a card from deck
                    myDeck->draw();
                    discardedCard = hand->top();
                    //add card to discardPile
                    discardPile->operator+=(discardedCard);
                };
                //draw 3 cards
                Card* card1 = myDeck->draw();
                Card* card2 = myDeck->draw();
                Card* card3 = myDeck->draw();
                //add the 3 cards to tradeArea
                tradeArea->operator+=(card1);
                tradeArea->operator+=(card2);
                tradeArea->operator+=(card3);
                list<Card *> myTradeArea = tradeArea->getTradeArea();
                //while top card of discard pile matches an existing card in the trade area
                while (std::find(myTradeArea.begin(), myTradeArea.end(), discardPile->top()) != myTradeArea.end()) {
                    Card* cardd = discardPile->pickUp();
                    //place top most card from discard pile to tradeArea
                    tradeArea->operator+=(cardd);
                };
                //loop over my tradeArea
                for (Card* cc : myTradeArea) {
                    cout << "would you like to chain? [y/n]" << endl;
                    cin >> chainYN;
                    if (chainYN == "y") {
                        //take number of coins, assumed 5 for simplicity
                        cc->getCardsPerCoin(5);
                    }
                }
                //draw 2 cards
                Card* c1 = myDeck->draw();
                Card* c2 = myDeck->draw();
                //add these cards to playe's hands
                hand->operator+= (c1);
                hand->operator+= (c2);
            };
        }
    }
    return 0;
};
