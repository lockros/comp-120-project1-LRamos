#include <iostream>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void init_board (char board[]) {
    int i;
    for (i = 0; i < 9; i++) {
        if (i==0 || i==1||i==3||i==4||i==6||i==7){
            printf(" %c |", board[i]);
        }
        if(i==2||i==5||i==8){
            printf(" %c ", board[i]);
        }
        if (i==2 || i==5) {
            printf("\n");
            printf("---+---+--- \n");
        }
    }
}


void display_board () {
    char c[9] = {'0','1','2','3','4','5','6','7','8'};
    int i;
    for (i = 0; i < 9; i++) {
        if (i==0 || i==1||i==3||i==4||i==6||i==7){
            printf(" %c |", c[i]);
        }
        if(i==2||i==5||i==8){
            printf(" %c ", c[i]);
        }
        if (i==2 || i==5) {
            printf("\n");
            printf("---+---+--- \n");
        }
    }
}

void get_human_move(int user_input, char board[]) {
    printf("\nIt is your turn, type a number between 0 and 8: ");
    while (1) {
        if (scanf(" %d", &user_input) != 1) {
            printf("Not a number, input a number from 0-8, try again: ");
            while (getchar() != '\n');
            continue;
        }
        char next_digit = getchar();
        if (next_digit != '\n') {
            printf("Not a valid input, input a number from 0-8, try again: ");
            while (getchar() != '\n' && next_digit != EOF) {
                next_digit = getchar();
            }
            continue;
        }
        if (user_input < 0 || user_input > 8) {
            printf("Not within 0-8, input a number from 0-8, try again: ");
            continue;
        }
        if (board[user_input] == 'O' || board[user_input] == 'X') {
            printf("Square is already taken, input a new number: ");
            continue;
        }
        board[user_input] = 'O';
        break;
    }
}

void get_computer_move (char board[]) {
    printf("\nComputer is thinking...\n");
    int computer_move;
    computer_move = rand() % 9;
    while (1) {
        if (board[computer_move] == 'O' || board[computer_move] == 'X') {
            computer_move = rand() % 9;
            continue;
        }
        board[computer_move] = 'X';
        break;
    }
}
bool is_player_winner (const char board[]) {
    if (board[0] == 'O' && board[1] == 'O' && board[2] == 'O') {
        return true;
    }
    if (board[3] == 'O' && board[4] == 'O' && board[5] == 'O') {
        return true;
    }
    if (board[6] == 'O' && board[7] == 'O' && board[8] == 'O') {
        return true;
    }
    if (board[0] == 'O' && board[3] == 'O' && board[6] == 'O') {
        return true;
    }
    if (board[1] == 'O' && board[4] == 'O' && board[7] == 'O') {
        return true;
    }
    if (board[2] == 'O' && board[5] == 'O' && board[8] == 'O') {
        return true;
    }
    if (board[0] == 'O' && board[4] == 'O' && board[8] == 'O') {
        return true;
    }
    if (board[2] == 'O' && board[4] == 'O' && board[6] == 'O') {
        return true;
    }

    return false;

}
bool is_computer_win (const char board[]) {
    if (board[0] == 'X' && board[1] == 'X' && board[2] == 'X') {
        return true;
    }
    if (board[3] == 'X' && board[4] == 'X' && board[5] == 'X') {
        return true;
    }
    if (board[6] == 'X' && board[7] == 'X' && board[8] == 'X') {
        return true;
    }
    if (board[0] == 'X' && board[3] == 'X' && board[6] == 'X') {
        return true;
    }
    if (board[1] == 'X' && board[4] == 'X' && board[7] == 'X') {
        return true;
    }
    if (board[2] == 'X' && board[5] == 'X' && board[8] == 'X') {
        return true;
    }
    if (board[0] == 'X' && board[4] == 'X' && board[8] == 'X') {
        return true;
    }
    if (board[2] == 'X' && board[4] == 'X' && board[6] == 'X') {
        return true;
    }

    return false;

}

bool is_draw (const char board[]) {
    if (is_player_winner (board) == false && is_computer_win (board) == false) {
        return true;
    }
        return false;

}
bool continue_play () {
    char cont;
    while (1) {
        printf("Do you wish to play again? (Y/N):");
        if (scanf(" %c", &cont) != 1) {
           while (getchar() != '\n');
            continue;
        }
        while (getchar() != '\n');
        if (cont == 'Y' || cont == 'y') {
            return true;
        }
        if (cont == 'N' || cont == 'n') {
            return false;
        }
    }
}

void gameplay (char board[]) {
    int user_input;
    int i;
    for (i = 0; i < 5; i++) {
        if (i!=4) {
            if (is_player_winner (board) == false && is_computer_win (board) == false) {
                get_human_move(user_input, board);
                init_board (board);
                    if (is_player_winner (board) == true && is_computer_win (board) == false) {
                        printf("\nPlayer won!\n");
                        break;
                    }
                get_computer_move (board);
                init_board (board);
                    if (is_player_winner (board) == false && is_computer_win (board) == true) {
                        printf("\nComputer won!\n");
                        break;
                    }
            }
            if (is_player_winner (board) == true && is_computer_win (board) == false) {
                printf("\nPlayer won!\n");
                break;
            }
            if (is_player_winner (board) == false && is_computer_win (board) == true) {
                printf("\nComputer won!\n");
                break;
            }
        }
        else if (i==4) {
            get_human_move(user_input, board);
            init_board (board);
            if (is_draw (board) == true) {
                printf("\nDraw!\n");
            }
            else if (is_draw (board) == false) {
                if (is_computer_win (board) == true && is_player_winner (board) == false) {
                    printf("\nComputer won!\n");
                }
                else if (is_player_winner (board) == true && is_computer_win (board) == false) {
                    printf("\nPlayer won!\n");
                }
            }
        }
    }
}
int main (void) {
    srand(time(NULL));
    char board[9] = {'0','1','2','3','4','5','6','7','8'};
    int i;
    char initial_board[9] = {'0','1','2','3','4','5','6','7','8'};
    char cont;
    do {
        for (i = 0; i < 9; i++) {
            board[i] = initial_board[i];
        }

        printf("You are O and you go first. The computer is X.\n");
        printf("When it is your turn, type a number between 0 and 8 to place your O.\n");
        display_board ();
        gameplay (board);
    } while (continue_play () == true);
    printf("Thank you for playing!");


    return 0;
}