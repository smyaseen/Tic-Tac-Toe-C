#include<stdio.h>


//functions
void dsplyInst();
void dsplyBoard();
void getUserInput();
void updateBoard(int);
int hasPlayerWon();


//initializing array for board
char board[3][3] = {{'1','2','3'},
                   {'4','5','6'},
                   {'7','8','9'},
                    };

//initializing marker for x || o
char marker;

//move count that if %2 == 0 it will be player 1's move else player 2's
int move_count=0;

//this array is for storing the user inputs
int user_input[9]={0};




void dsplyInst() {

    printf("Tic Tac Toe\n-----------\n"
            "Player1: x\nPlayer2: o\n"
            "User enters position no. to mark the place of his/her choice.\n"
            "Input position: 1\n"
            "Game is starting...\n\n");

}

void dsplyBoard() {

//initializing iterators for loop
int i,j;

//printing board using loop
for(i=0;i<3;i++) {
    for(j=0;j<3;j++) {
    printf("%c ",board[i][j]);

//used if because not want to print | in the end
    if (j < 2) {
        printf("| ");
    }

}

printf("\n");
//used if because not want to print --- in the end
if (i < 2) {
printf("---------");
}

printf("\n");
}

}


void getUserInput() {

//initialize move to get player's input
int move;


if (move_count % 2 == 0) {
printf("Player 1: ");
marker = 'x';
}
else {
printf("Player 2: ");
marker = 'o';
}

scanf("%d",&move);
printf("\n");

//storing player's input in user_input array
user_input[move_count] = move;

//using some genius level code to see if the position is already marked or not
//basically what it does is that it sees if the input is appeared already or not
//in previous blocks of user_input array from the current one
//if it does appear then recall the getUserInput to get input again

for(int i=move_count-1;i>=0;i--) {
   if (user_input[i] == move) {
    printf("Position already marked! Enter again...\n");
    getUserInput();
   }
}

//passing the user input to update the board
updateBoard(move);

}


void updateBoard(int move) {

//using switch to update board as received input
switch (move) {

case 1:
    board[0][0] = marker;
    break;
case 2:
    board[0][1] = marker;
    break;
case 3:
    board[0][2] = marker;
    break;
case 4:
    board[1][0] = marker;
    break;
case 5:
    board[1][1] = marker;
    break;
case 6:
    board[1][2] = marker;
    break;
case 7:
    board[2][0] = marker;
    break;
case 8:
    board[2][1] = marker;
    break;
case 9:
    board[2][2] = marker;
    break;
default:
    printf("Enter correct position!\n");
    getUserInput();
}

//incrementing move_count for next player's input
move_count++;

}

int hasPlayerWon() {

//if the game draws then ends
if (move_count == 9)
    return 2;

//if a player wins it will return 1 and the game ends
//else it returns 0 and the game will continue


//first checking in row

if (board[0][0] == board[0][1] && board[0][0] == board[0][2])
return 1;

else if (board[1][0] == board[1][1] && board[1][0] == board[1][2])
return 1;

else if (board[2][0] == board[2][1] && board[2][0] == board[2][2])
return 1;

//Second checking in column

if (board[0][0] == board[1][0] && board[0][0] == board[2][0])
return 1;

else if (board[0][1] == board[1][1] && board[0][1] == board[2][1])
return 1;

else if (board[0][2] == board[1][2] && board[0][2] == board[2][2])
return 1;

//third checking in diagonal

if (board[0][0] == board[1][1] && board[0][0] == board[2][2])
return 1;

else if (board[0][2] == board[1][1] && board[0][2] == board[2][0])
return 1;

else
    return 0;

}



int main() {

int flag=0,plyr1_wins=0,plyr2_wins=0;
char play_again,board_pos='1';

//used two loops because want some funcs to display at the start of game only
do {

dsplyInst();
dsplyBoard();

do {

getUserInput();
flag = hasPlayerWon();
dsplyBoard();

}while(flag==0);


//determining winning side by checking last marker
if (flag == 1) {
if (marker == 'x') {
    printf("Player 1 Won!\n");
    plyr1_wins++;
}
else {
    printf("Player 2 Won!\n");
    plyr2_wins++;
}
}
//for draw
else if (flag == 2) {
    printf("The Game is DRAW!!\n");
}

//printing score
printf("Player 1 Wins: %d Games\n",plyr1_wins);
printf("Player 2 Wins: %d Games\n",plyr2_wins);

//asking for again play
do {
fflush(stdin);
printf("Do you want to play again (y/n)? ");
scanf("%c",&play_again);

if (play_again == 'y' || play_again == 'n') {
    break;
}

else
    printf("Enter either y or n!\n");

}while(0==0);
//lol

printf("\n");

if (play_again == 'y') {
//resetting board for next game if any
for(int i=0;i<=3;i++) {
    for(int j=0;j<3;j++) {
        board[i][j] = board_pos;
        board_pos++;
    }
}

//resetting move_count for next game if any
move_count = 0;
}

}while(play_again == 'y');

printf("\nGOOD BYE!");

return 0;
}
