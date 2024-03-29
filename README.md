# 31-card-game-LinkedList

Though I added comments to my code, but I feel it would be easier to you to understand how my code works by also me annotating here.

## Card creation and shuffling:

![image](https://user-images.githubusercontent.com/107953912/175070277-8adb70bc-82dc-4ad1-a333-05e05b343d19.png)

The User has an option either to put a file or just use the current deck with 52 cards and shuffle it, if he chooses to input a file, this format description will print out.

![image](https://user-images.githubusercontent.com/107953912/175071360-eb561120-4075-4b89-8462-d44299c8f416.png)  ![image](https://user-images.githubusercontent.com/107953912/175071396-5322ae38-1a62-4522-bbc0-a79fe4dce5c0.png)

## Betting system:

Here players start to bet (its multiplayer though), what happens in my bet is the following. Each player has 1 chance to re-raise. And when someone re-raises he doesn’t have the r option anymore.

![image](https://user-images.githubusercontent.com/107953912/175071704-40b3a66e-ac90-4eb2-853c-199b03b7fd19.png)

This is how the bet looks like after the first bet of first round. (fold option added)

![image](https://user-images.githubusercontent.com/107953912/175071816-d30fdbd4-e18c-4f08-b848-ee28523064a6.png)

If Bob chosen to fold, his first re-raise which is 15 will be added to the pot, and deducted from his money. Then Alice will win the pot incase Bob folded. And the same happens if vice versa (if Alice folded after bob re-raise, Alice initial bet will be added to the pot, and deducted from his money. – if Alice didn’t fold from the first place)

If there are 3 players or more this what will happen. If for example, Alice folded, the game will continue with Bob and Ali and Bob will have a new option of placing a bet (when there are three players or more it asks for the new joined players names) unless either Bob or Ali also folds. (Let’s say if Alice before folding he did a bet, then the amount he betted before will be added to the bot and deducted from his money) – Play means “To accept the bet and play” like 
```c
Player 1: bets 20$
Player 2: raises to 40$
Player 1: presses play and pays another 20$
```

![image](https://user-images.githubusercontent.com/107953912/175071960-79341cb7-1021-438b-8600-4782a1be60a5.png)

If a player tried to put a re-raise lower than the initial bet, previous re-raise, or higher than his current money these messages will come out to let him to write another amount.

![image](https://user-images.githubusercontent.com/107953912/175074536-6c02637a-e481-4a8e-a636-7b0cc901f833.png)

There are much more possible and different cases for these bets I just illustrated the most common and important ones, you will be able to see the other possible cases when you run my code.

## Card dealting, and Top & discard pile management:

![image](https://user-images.githubusercontent.com/107953912/175072178-181d22da-4bd0-4818-b7cc-36dfa1da1b07.png)

Gives three cards to each player like if the cards are:
```c
1 1 2 2 3 3 (gives out cards alternating)
Player 1: 1 2 3 
Player 2: 1 2 3
```

He has three options to take from top pile and then remove one of the cards to the discard pile or if he doesn’t want the card he will just dismiss it to discard pile, either to choose from the discard pile and replace it with one of his cards and this can be seen that discard pile card on top changed when Alice took the club 10 instead of the first card (heart 5) which is now added to the discard pile, or he can just knock knock (endgame) and each player has one more turn.(no more bets are taken place after a player knocks knocks)
```c
Player 1 : knocks
Player 2: takes his turn
Then Winner is chosen and declared
```

## Game statistics:

When the game ends the winner is declared and game statistics is shown.

![image](https://user-images.githubusercontent.com/107953912/175074600-e3fb72fb-ba8f-4319-9a82-4d1e210729af.png)

## Other points:
```c
Some other points in my code:
1-	If someone knocks knocks and ends the game no more bets will take place and everyone will have one more turn.
2-	If there are more than 2 players, and someone folds the game will continue with the other two players without the player who folded.
3-	If the player chosen from discard pile it won’t print the graphics twice just once as usual.
4-	The game can be multiplayer,  shows game statics, and shows graphics.
5-	The game re-initialize the deck and shuffles it successfully in case the players wanted another game.
6-	I printed out the current and updated points (after he takes his turn) for each player turn.
7-	Cards that are 2 – 10 values (Not Aces or face cards) I printed them as Heart 2 as it would be easier to the player to read instead of putting 3 words fragments for each 2 – 10 values cards.
8-	There are some many other features but I can’t explain it here using DOC. Hope this document helped abit! Thank you.
```
