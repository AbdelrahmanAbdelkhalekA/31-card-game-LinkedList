#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#define SPADE "\x06"
#define CLUB "\x05"
#define HEART "\x03"
#define DIAMOND "\x04"

//Created by Abdelrahman Ahmed Abdelkhalek
//Class:ECE 175 - Professor Loukas Lazos.

typedef struct cardsfchar {
    char  suit[9];
    int value;
    int points;
    struct cards* pt;
} card;

// Checks the suit for each king, jack, or queen and add it to the string of str1 in the artc function to print the corresponding suits.
// Instead of putting this function 3 times in the artc function i just put it one time here.
void checksuit(char str[10], char temp[10], int v) {
    if (strcmp("Spade", temp) == 0) {
        strcpy(str, SPADE);
    }
    else if (strcmp("Diamond", temp) == 0) {
        strcpy(str, DIAMOND);
    }
    else if (strcmp("Club", temp) == 0) {
        strcpy(str, CLUB);
    }
    else if (strcmp("Heart", temp) == 0) {
        strcpy(str, HEART);
    }
}
//It prints the graphics of each 3 cards or 1 card.
void artc(card temp[], int limit, const card temp1) { //make function
    char str[10][3];
    char str1[10][3];
    char tempo[10];
    int values[3] = { 0 };
    if (limit == 1) { // if limit 1 means if i just need one card to be printed. example: discard pile which has 1 card and the players hand which has 3
        strcpy(temp[0].suit, temp1.suit);
        temp[0].value = temp1.value;
    }
    if (temp[0].value != 0) {
        for (int g = 0; g < limit; g++) {
            if (temp[g].value == -1) {
                strcpy(str[g], "K");
                checksuit(str1[g], temp[g].suit ,g);
            }
            else if (temp[g].value == -2) {
                strcpy(str[g], "Q");
                checksuit(str1[g], temp[g].suit, g);
            }
            else if (temp[g].value == -3) {
                strcpy(str[g], "J");
                checksuit(str1[g], temp[g].suit, g);
            }
            else if (strcmp("Spade", temp[g].suit) == 0) {
                strcpy(str[g], SPADE);
                values[g] = temp[g].value;
            }
            else if (strcmp("Diamond", temp[g].suit) == 0) {
                strcpy(str[g], DIAMOND);
                values[g] = temp[g].value;
            }
            else if (strcmp("Club", temp[g].suit) == 0) {
                strcpy(str[g], CLUB);
                values[g] = temp[g].value;
            }
            else if (strcmp("Heart", temp[g].suit) == 0) {
                strcpy(str[g], HEART);
                values[g] = temp[g].value;
            }
        }

        for (int i = 0; i < limit; i++) {
            printf("  ----------");
        }
        printf("\n");
        for (int i = 0; i < limit; i++) {
            if (values[i] == 10) {
                printf("  |%d%s     |", values[i], str[i]);
            }
            else if (values[i] == 1){
                printf("  |A%s      |", str[i]);
            }
            else if (values[i] > 0) {
                printf("  |%d%s      |", values[i], str[i]);
            }
            else {
                printf("  |%s%s      |", str[i], str1[i]);
            }
        }
        printf("\n");
        for (int i = 0; i < limit; i++) {
            printf("  |        |");
        }
        printf("\n");
        for (int i = 0; i < limit; i++) {
            printf("  |        |");
        }
        printf("\n");
        for (int i = 0; i < limit; i++) {
            if (values[i] == 10) {
                printf("  |     %s%d|", str[i], values[i]);
            }
            else if (values[i] == 1) {
                printf("  |      %sA|", str[i]);
            }
            else if (values[i] > 0) {
                printf("  |      %s%d|", str[i], values[i]);
            }
            else {
                printf("  |      %s%s|", str1[i], str[i]);
            }
        }
        printf("\n");
        for (int i = 0; i < limit; i++) {
            printf("  ----------");
        }
        printf("\n");
    }
}

//prints the discard pile card for each players turn
void printvalDiscard(card temp) {
    char temp1[10];
    if (temp.value < 0 || temp.value == 1) {
        if (temp.value == -1) {
            strcpy(temp1, "King");
        }
        else if (temp.value == -2) {
            strcpy(temp1, "Queen");
        }
        else if (temp.value == -3) {
            strcpy(temp1, "Jack");
        }
        else if (temp.value == 1) {
            strcpy(temp1, "Ace");
        }
        printf("The card on table (Discard pile): %s of %ss\n", temp1, temp.suit);
    }
    else {
        printf("The card on table (Discard pile): %s", temp.suit);
        printf(" %d\n", temp.value);
    }
}

//This function calculates a players points for each turn he takes to keep track of it as if someone ends game, reachs 31 points, and to help record game statics.
int playerPoints(const card points[3]) {
    int value = 0, count = 0;
    int temp[3] = { 0 };
    for (int i = 0; i < 3; i++) {
        if (points[i].value == 1) {
            temp[i] = 11;
        }
        else if (points[i].value == -1 || points[i].value == -2 || points[i].value == -3) {
            temp[i] = 10;
        }
        else {
            temp[i] = points[i].value;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (temp[i] >= 10) {
            count++;
        }
    }
    if (((temp[0] + temp[1] + temp[2]) == 31) && ((strcmp(points[0].suit, points[1].suit) == 0) && (strcmp(points[1].suit, points[2].suit) == 0) && (strcmp(points[0].suit, points[2].suit) == 0))) {
        value = 31;
    }
    else if (((points[0].value == points[1].value) && (points[1].value == points[2].value) && (points[0].value == points[2].value))) {
        value = 30;
    }
    else if ((strcmp(points[0].suit, points[1].suit) == 0) && (strcmp(points[1].suit, points[2].suit) == 0) && (strcmp(points[0].suit, points[2].suit) == 0)) {
        value = temp[0] + temp[1] + temp[2];
    }
    else if (strcmp(points[0].suit, points[1].suit) == 0) {
        value = temp[0] + temp[1];
        if (value < temp[2]) {
            value = temp[2];
        }
    }
    else if (strcmp(points[1].suit, points[2].suit) == 0) {
        value = temp[1] + temp[2];
        if (value < temp[0]) {
            value = temp[0];
        }
    }
    else if (strcmp(points[0].suit, points[2].suit) == 0) {
        value = temp[0] + temp[2];
        if (value < temp[1]) {
            value = temp[1];
        }
    }
    else { // if there is no matching suits or similar values it will take the one with highest points
        int x = 0;
        int max = temp[0];
        for (int i = 0; i < 3; i++) {
            if (temp[i] > max) {
                max = temp[i];
            }
        }
        value = max;
    }
    return value;
}

//i and j are the random numbers which is like the number of iterations, example: j = 8 it will keep iterating till it reaches the 8th cards.
void swap(card* pt, int i, int j) { //By professor lazos (from lab)
    card* pt1 = pt, * pt2 = pt;
    card* temp = (card*)malloc(sizeof(card));
    while (i > 0) {
        pt1 = pt1->pt;
        i--;
    }
    while (j > 0) {
        pt2 = pt2->pt;
        j--;
    }
    *temp = *pt1; //swap data
    strcpy(pt1->suit, pt2->suit);
    pt1->value = pt2->value;
    strcpy(pt2->suit, temp->suit);
    pt2->value = temp->value;
}

// generate random numbers to iterate to (explained in more detail in the comment above too).
int rand_gen(int count) { //By professor lazos (from lab)
    double frac;
    frac = (double)rand() / ((double)RAND_MAX + 1);
    return floor(count * frac);
}

//here this function generates random integers (numbers) using rand_gen and passes it 1000 times to the swap function were suits and values are exchanged within the two targeted nodes
void shufflelist(card* k, int count) //By professor lazos (from lab)
{
    srand((int)time(NULL));
    for (int i = 1; i <= 1000; i++)
        swap(k, rand_gen(count), rand_gen(count));
}

//Deletes the the card in the first of the list (either in top pile or discard pile works for both) USING FREE()
void deleteList(card** head) {  //by Professor Lazos
    card* toDelete;
    if (*head == NULL)
    {
        printf("No more cards are their");
        return 0;
    }
    else
    {
        toDelete = *head;
        *head = (*head)->pt;
        free(toDelete);
    }
}

//Here were the bet of players take place and when a player folds, re-riase etc..
//it updates the pot money and each player money, it also updates the folded players array (valid).
void playersBet(int num, int valid[], int money[], int* bet, char names[][100], int jj) {
    char bett;
    int raises[10] = { 0 }, con = -1, folds = 0, fold1 = 0, imbet[10] = { 0 }, vali = 0;
    int temp1 = 0, temporary = *bet, yo = 0;
    bool temp = true, go = false;
    int condi = 0, condi1, mu = num, maximuimBet = 10000;
    for (int h = 0; h < num; h++) {
        if (maximuimBet > money[h]) {
            maximuimBet = money[h];
        }
    }
    printf("Maximuim amount to bet: %d$\n", maximuimBet);
    if (jj == 1) {
        yo = num - 1;
        go = true;
    }
    for (int m = 0; m < num; m++) {
        condi1 = 0;
        for (int i = 0; i < num; i++) {
            condi += raises[i];
            if (raises[i] == 1) {
                mu--;
            }
            if (valid[i] == 1) {
                folds++;
            }
        }
        for (int g = 0; g < num; g++) {
            if (jj == 1 && valid[g] != 1) {
                printf("%s current money: %d$\n", names[0], money[0]);
                printf("%s how much you want to bet on? ", names[0]);
                scanf("%d", &temp1);
                while (temp1 > money[g]) {
                    printf("You cant bet that amount as it exceeds your avaliable money.\n");
                    printf("How much you want to bet? ");
                    scanf("%d", &temp1);
                }
                condi1++;
            }
            else if ((raises[g] != 1 && condi != 0 && valid[g] != 1 && condi1 != mu) || (temp && valid[g] != 1)) {
                if (g == 0 && temp) {
                    printf("%s current money: %d$\n", names[0], money[0]);
                    printf("%s Do you want to bet or fold (b/f)? ", names[0]);
                    scanf(" %c", &bett);
                }
                else if (valid[g - 1] == 1 && con != g) {
                    printf("%s current money: %d$\n", names[g], money[g]);
                    printf("%s do you want to bet or fold(b/f)? ", names[g]);
                    scanf(" %c", &bett);
                    con = g;
                }
                else if (yo > 0) {
                    printf("%s current money: %d$\n", names[g], money[g]);
                    printf("%s do you want to re-raise or play(r/p)? ", names[g]);
                    scanf(" %c", &bett);
                }
                else {
                    printf("%s current money: %d$\n", names[g], money[g]);
                    printf("%s do you want to re-raise, fold, or play(r/f/p)? ", names[g]);
                    scanf(" %c", &bett);
                }
                if (bett == 'f') {
                    valid[g] = 1;
                    condi1++;
                    folds++;
                }
                else if (bett == 'r') {
                    raises[g]++;
                    printf("How much you want to re-raise? ");
                    scanf("%d", &temp1);
                    while (temp1 > money[g]) {
                        printf("Your re-raise is less then the previous re-raise or more than your available money.\n");
                        printf("How much you want to re-raise? ");
                        scanf("%d", &temp1);
                    }
                    imbet[g] = temp1;
                }
                else if (bett == 'p') {
                    condi1++;
                }
                else if (bett == 'b') {
                    printf("How much you want to bet? ");
                    scanf("%d", &temp1);
                    while (temp1 > money[g]) {
                        printf("You cant bet that amount as it exceeds your avaliable money.\n");
                        printf("How much you want to bet?");
                        scanf("%d", &temp1);
                    }
                    imbet[g] = temp1;
                }
            }
            else if ((condi != 0 && valid[g] != 1 && condi1 != mu) || (temp && valid[g] != 1)) {
                if (!(go)) {
                    printf("%s current money: %d$\n", names[g], money[g]);
                    printf("%s do you want to fold or play(f/p)? ", names[g]);
                    scanf(" %c", &bett);
                }
                else {
                    printf("%s current money: %d$\n", names[g], money[g]);
                    printf("%s do you want to play(p)? ", names[g]);
                    scanf(" %c", &bett);
                }
                if (bett == 'f') {
                    valid[g] = 1;
                    folds++;
                    condi1++;
                }
                else if (bett == 'p') {
                    condi1++;
                }
            }
            jj++;
            fold1 = 0;
            for (int i = 0; i < num; i++) {
                if (valid[i] == 1) {
                    fold1++;
                }
            }
            if ((folds == (num - 1)) || (fold1 == (num - 1)) || ((num - fold1) == 1)) { // if only 1 player who stays unfolded the game ends ex: player 1: f player 2: f player 3: will be the winner.
                break;
            }
            if (num == (g + 1)) {
                temp = false;
            }
        }
        if ((folds == (num - 1)) || (fold1 == (num - 1)) || ((num - fold1) == 1)) {
            break;
        }
        if (condi1 == mu) {
            break;
        }
    }
    //This is the part where money are dedeucted and bets are added.
    if (folds > 0) { //This function checks if there is a player who have done a bet or re- raise and then folded. Ex: player 1: 20$, player 2: reraise 30$, player 1: reraise 40, player 2: folds --> then the 30$ raised by player 2 will be added to the pot and deducted from his money and then player 1 will just be the winner as the other player folded
        for (int y = 0; y < num; y++) {
            if (valid[y] == 1) {
                *bet += imbet[y];
                money[y] -= imbet[y];
            }
        }
    }

    int validty = 0;
    for (int i = 0; i < num; i++) {
        if (valid[i] == 1) {
            validty++;
        }
    }
    if ((validty != (num - 1)) || ((num - fold1) != 1)) {
        for (int i = 0; i < num; i++) {
            if (valid[i] != 1) {
                money[i] -= temp1;
                *bet += temp1;
            }
        }
    }

}
// -1 king
// -2 queen
//-3 jack
//prints the card choosen when taken a card from either the discard pile or top pile.
void printval(card tem, int d) {
    char temp1[10];
    if (tem.value < 0 || tem.value == 1) {
        if (tem.value == -1) {
            strcpy(temp1, "King");
        }
        else if (tem.value == -2) {
            strcpy(temp1, "Queen");
        }
        else if (tem.value == -3) {
            strcpy(temp1, "Jack");
        }
        else if (tem.value == 1) {
            strcpy(temp1, "Ace");
        }
        if (d == 1) {
            printf("The card chosen from top pile: %s of %ss\n", temp1, tem.suit);
        }
        else {
            printf("The card chosen from discard: %s of %ss\n", temp1, tem.suit);
        }
    }
    else {
        if (d == 1) {
            printf("The card chosen from top pile: %s", tem.suit);
            printf(" %d\n", tem.value);
        }
        else {
            printf("The card chosen from discard pile: %s", tem.suit);
            printf(" %d\n", tem.value);
        }
    }
}


void printList(card* pt) { //prints the entire list

    while (pt != NULL) {
        char temp1[10] = "";
        if (pt->value < 0 || pt->value == 1) {
            if (pt->value == -1) {
                strcpy(temp1, "King");
            }
            else if (pt->value == -2) {
                strcpy(temp1, "Queen");
            }
            else if (pt->value == -3) {
                strcpy(temp1, "Jack");
            }
            else if (pt->value == 1) {
                strcpy(temp1, "Ace");
            }
            printf("%s of %ss\n", temp1, pt->suit);
        }
        else {
            printf("%s", pt->suit);
            printf(" %d\n", pt->value);
        }
        pt = pt->pt;
    }

}
//here is where the linked list for discard pile is created.
card* discardLink(card* temp) { //by Professor Lazos
    card* headp = NULL;
    card* tailp = NULL;
    if (headp == NULL) {
        headp = temp;
    }
    else {
        tailp->pt = temp;
    }
    tailp = temp;
    temp->pt = NULL;
    return headp;
}
//calculates the game statitics each round
void gradestatics(int game[][2], int points[10], int num) {
    int max = 0;
    int sa = 0;
    for (int i = 0; i < num; i++) {
        if (max < points[i]) {
            max = points[i];
            sa = i;
        }
    }
    game[sa][1]++;
    for (int i = 0; i < num; i++) {
        if (i != sa) {
            if (max == points[i]) {
                game[i][1]++;
            }
        }
    }

}
//adds a new card each time its called for the discard list
void insertingdiscard(card** head, const card* newhead) { //by Professor Lazos
    card* newcard;
    newcard = (card*)malloc(sizeof(card));
    strcpy(newcard->suit, newhead->suit);
    newcard->value = newhead->value;
    newcard->pt = *head;
    *head = newcard;
}
//here is where the turns are given, winner identified, cards passed, discarded, taken from top pile, points calculated, and players hand are manitulated (addition/remove of cards).
//i am thinking this would make it easier for me to have control of my main function and be easy to change anything in my main, and make it more organized there.
void givePLayer(card* h, char name[][100], card player[][3], int x, double winnings[], int mone[], int Gamestaticss[][2]) {
    bool condi = true;
    int win = 0;
    int pp = 0;
    card inti[3], temp1;
    // GIVES EACH PLAYER ONE CARD (Alternating)
    for (int i = 0; i < x; i++) {
        player[i][0] = *h;
        deleteList(&h);
    }

    for (int i = 0; i < x; i++) {
        player[i][1] = *h;
        deleteList(&h);
    }

    for (int i = 0; i < x; i++) {
        player[i][2] = *h;
        deleteList(&h);
    }
    char temp = 'y';
    bool go = false;
    int count = 1, max1 = 0, co;
    int points = 0, imp, point1[10] = {0};
    int yo, mee = -1, me = 0;
    int to = 0, valid[10] = { 0 }, valid1;
    card* discardp;
    card* tempor;
    tempor = (card*)malloc(sizeof(card));
    strcpy(tempor->suit, "No Card");
    tempor->value = 0;
    discardp = discardLink(tempor); //intially adds "No Card"(will not be used in the game just as a reference point)
    insertingdiscard(&discardp, h); //Then adding the first card after distrubuting to players
    while (points != 31 && condi) {
        printList(discardp);
        valid1 = 0;
        imp = x;
        if (!(me > 0)) {
            pp++;
            playersBet(x, valid, mone, &win, name, pp);
        }
        for (int f = 0; f < x; f++) {
            if (valid[f] == 1) {
                valid1++;
                imp--;
            }
        }
        for (int i = 0; i < x; i++) {
            bool temtt = false;
            if (valid[i] != 1) {
                if (valid1 != (x - 1)) {
                    printf("%s cards:\n", name[i]);
                    for (int j = 0; j < 3; j++) {
                        char temp1[10] = "";
                        if (player[i][j].value < 0 || player[i][j].value == 1) {
                            if (player[i][j].value == -1) {
                                strcpy(temp1, "King");
                            }
                            else if (player[i][j].value == -2) {
                                strcpy(temp1, "Queen");
                            }
                            else if (player[i][j].value == -3) {
                                strcpy(temp1, "Jack");
                            }
                            else if (player[i][j].value == 1) {
                                strcpy(temp1, "Ace");
                            }
                            printf("%d-%s of %ss\n", j + 1, temp1, player[i][j].suit);
                        }
                        else {
                            printf("%d-%s", j + 1, player[i][j].suit);
                            printf(" %d\n", player[i][j].value);
                        }
                    }
                    Gamestaticss[9][0]++;
                    artc(player[i], 3, *player[i]);
                    printvalDiscard(*discardp);
                    artc(inti, 1, *discardp);
                    printf("Current points: %d\n", playerPoints(player[i]));
                    printf("Do you want to take from top pile,discard pile, or knock knock(t/d/k)? ");
                    scanf(" %c", &temp);
                    if (temp == 'd') {
                        printval(*discardp, 2);
                        printf("Which card to discard(1/2/3)? \n");
                        scanf("%d", &yo);
                        temp1 = player[i][yo - 1];
                        player[i][yo - 1] = *discardp;
                        deleteList(&discardp);
                        insertingdiscard(&discardp, &temp1);
                        points = playerPoints(player[i]);
                        printf("Updated points: %d\n", points);
                        point1[i] = points;
                    }
                    if (temp == 't') {
                        deleteList(&h);
                        printval(*h, 1);
                        artc(inti, 1, *h);
                        printf("Which card to discard or type 4 to dismiss to discard pile(1/2/3/4)? \n");
                        scanf("%d", &yo);
                        if (yo == 4) {
                            card tempq;
                            strcpy(tempq.suit, h->suit);
                            tempq.value = h->value;
                            insertingdiscard(&discardp, &tempq);
                        }
                        else
                        {
                            insertingdiscard(&discardp, &player[i][yo - 1]);
                            player[i][yo - 1] = *h;
                        }
                        points = playerPoints(player[i]);
                        printf("Updated points: %d\n", points);
                        point1[i] = points;
                    }
                }
                else {
                    go = true;
                }
                if (temp == 'k' || me == imp - 1 || go) { //i tried to put this in a function but it needed 12 variables to be passed and this would just make the function look wierd so i keep it here
                    if (me != imp - 1 && !(go)) {
                        points = playerPoints(player[i]);
                        mee = 1;
                    }
                    else { //distribute the money for other players and checks the winners and give the bet tp the winner either if its just one winner or a tie
                        int pointss[10];
                        for (int j = 0; j < x; j++) {
                            if (valid[j] != 1) {
                                pointss[j] = playerPoints(player[j]);
                            }
                        }
                        int winner = 0;
                        for (int w = 0; w < x; w++) {
                            if (max1 < pointss[w] && valid[w] != 1) {
                                max1 = pointss[w];
                                winner = w;
                            }
                        }
                        for (int t = 0; t < x; t++) {
                            if (t != winner && valid[t] != 1) {
                                if (max1 == pointss[t]) {
                                    count++;
                                }
                            }
                        }
                        if (count == 1) {
                            winnings[winner] = win;
                            condi = false;
                            break;
                        }
                        else {
                            for (int g = 0; g < x; g++) {
                                if (valid[g] != 1) {
                                    if (max1 == pointss[g]) {
                                        winnings[g] = ((double)win) / count;
                                    }
                                }
                            }
                            condi = false;
                            break;
                        }
                    }
                }
            }

            if (points == 31) {
                winnings[i] += win;
                condi = false;
                break;
            }

            if (mee == 1) {
                me++;
            }
        }
        if (condi) {
            Gamestaticss[10][0]++;
            gradestatics(Gamestaticss, point1, x); //record game statitics
        }
    }
    discardp = NULL;
}

int main() {
    char names[10][100] = { "Alice", "Bob" };
    int Gamestatics[11][2] = { 0 }, gamescount = 0;
    int money[10] = { 100,100,100,100,100,100,100,100,100,100 }, ro, num;
    char anog = 'y';
    printf("Game instructions:-\n");
    printf("-Play (p) - To accept and meet the bet.\n-Knock Knock (k) - To end game.\n-The rest instructions are clearly illustrated in the game\n\n");
    while (anog == 'y') {
        char g, s;
        int j, x = 0;
        char t, count11 = 0;
        char file[20] = "CardsArray.txt";
        card* headp = NULL;
        card* temp = NULL;
        card* tailp = NULL;
        printf("Dear user do you want to input a file(y/n)? ");
        scanf(" %c", &t);
        if (t == 'y') {
            printf("Required file formats:\nSuit | Card Number\nEx: Spade 8\nFace cards:\nInput -1 for King\nInput -2 for Queen\nInput -3 for Jack\nEx: Diamond 1\nEx: Heart -1\n");
            printf("please enter the file you want: ");
            scanf("%s", file);
            x = 1;
        }
        FILE* inp = fopen(file, "r");
        while (!feof(inp)) { //linked list function here is by professor Lazos
            temp = (card*)malloc(sizeof(card));
            fscanf(inp, "%s%d", temp->suit, &temp->value); //scans the file
            count11++;
            if (headp == NULL) {
                headp = temp;
            }
            else {
                tailp->pt = temp;
            }
            tailp = temp;
            temp->pt = NULL;
        }

        int winns;
        printList(headp);
        if (x != 1) {
            printf("Do you want to Shuffle the card deck(y/n)? ");
            scanf(" %c", &s);
            while (s == 'y') {
                shufflelist(headp, count11);
                printf("Do you want to re-shuffle the card deck(y/n)? ");
                scanf(" %c", &s);
            }
            printList(headp);
        }
        if (!(gamescount > 0)) {
            printf("How many players are there? ");
            scanf(" %d", &num);
        }
        ro = num;
        if (num > 2 && (!(gamescount > 0))) {
            for (int i = 2; i < num; i++) {
                printf("Please enter the name of player %d: ", i + 1);
                scanf("%s", names[i]);
            }
        }
        card* players;
        players = (card*)malloc(num * 4 * sizeof(card));
        double winnings[10] = { 0 };
        givePLayer(headp, names, players, num, winnings, money, Gamestatics);
        for (int i = 0; i < num; i++) {
            if (winnings[i] != 0) { //prints the winners
                printf("%s win(s) pot %.2lf$\n", names[i], winnings[i]);
                money[i] += winnings[i];
                Gamestatics[i][0]++;
            }
        }
        printf("Do you want to play another game(y/n)? ");
        scanf(" %c", &anog);
        gamescount++;
    }
    printf("Game statistics:- \n");
    printf("Number of games: %d\n", gamescount);
    printf("Number of rounds: %d\n", Gamestatics[10][0]);
    for (int p = 0; p < ro; p++) {
        printf("%s dominated %d rounds out of %d\n", names[p], Gamestatics[p][1], Gamestatics[10][0]);
        printf("%s winning percentage (Of total rounds played - hand values): %.2lf%% \n", names[p], (((double)Gamestatics[p][1]) / Gamestatics[10][0]) * 100.0);
        printf("%s winning percentage (Per game): %.2lf%% \n", names[p], (((double)Gamestatics[p][0]) / gamescount) * 100.0);
    }
    printf("Thanks for playing!");
    return 0;
}
