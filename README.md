# comp-120-project1-LRamos
Description

This project is a tic tac toe game that has two players, the user and the computer. This project demonstrates basic concepts of the C++ programming language and applies them to make something a little more complex. The concepts are as follow:

-Functions
-Loops (for, while, do-while)
-Random number generator
-Arrays

The integral functions of this project:
- init_board (char board[]), shows us the initial board
- display_board (), shows the board after every turn
- get_human_move(int user_input, char board[]), is in charge of getting the users input and processing whether or not its valid.
- get_computer_move (char board[]), gets the computers move through a random number generator, and checks whether or not the square is occupied or not.
- is_player_winner (const char board[]), checks if the player won.
- is_computer_win (const char board[]), checks if the computer won.
- is_draw (const char board[]), checks if its a draw.
- continue_play, asks the player if they want to continue playing
- gameplay (char board[]), where the main functions of the game are, combining all of the previous functions into this one to make main cleaner.

How to start the game:
When the game starts the screen will ask you to input a number from 0 to 8, if you put a number within this range then a box will be filled with a O, and the goal is to get three O's in a row.


