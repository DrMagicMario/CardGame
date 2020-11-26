# CardGame
 CSI 2372 Final Project - Fall 2020

Card Game:
In this project, you are asked to program a card game in C++ language. The game is played with a deck of cards with comical illustrations of eight different types of beans (some more scarce than others), which two players place cards in chains, trade the cards and sell the chains in order to raise money.
 
The player obtains cards of all different types randomly from the deck, and so must engage in trade with the other player to be successful.

The cards have 8 different faces corresponding to different types of Beans (see Table below). The goal of the game is to chain-up the cards of same bean to gain coins. The player with the most coins at the end wins. The chains for the cards are formed by each player for all to see and there are a maximum of either two or three chains at any point per player. Each chain can only be formed with a single type of Bean.

Each player is dealt a hand of five cards to start and the remaining cards form a draw deck. The rule is that cards in a player’s hand need to be kept sorted. Cards will be placed on a discard pile during the game.

Cards in the hand are kept hidden. Cards in trading areas and chains are visible to all players. The discard pile is face up, but only the top card is visible.

The game proceeds with the players taking turns. During their turn, each player does the following:
    
    1. If the other player has left cards in the trade area from the previous turn (in Step 5), the player may add these cards to his/her chains or discard them.

    2. The player then plays the topmost card from his/her hand. The card must be added to a chain with the same beans. If the player has currently no such chain on the table, an old chain on the table will have to be tied and sold, and a new chain must be started. If the chain has not reached a sufficient length, a player may receive 0 coins.

    3. The player has the option to repeat Step 2.

    4. Then, the player has the option of discarding one arbitrary card (in any order) from his/her hand on the discard pile face up.

    5. The player draws three cards from the draw deck and places them in the trade area. Next, the player draws cards from the discard pile as long as the card matches one of the beans in the trade area. Once the top card does not match or the pile is empty, the player can either chain the cards or leave them in the trade area for the next player. As in Step 2, if the player has currently no such chain matching the bean of the card, an old chain on the table will have to be tied and sold, and then a new chain is started.

    6. The turn ends with the player drawing always two cards from the deck and placing them at the back of his/her hand.
