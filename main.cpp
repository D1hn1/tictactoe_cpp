#include <iostream>

// 0x1b

bool decision = true;

int player = 0;
int x_type = 1; 
int o_type = 2;
int null_type = 0;
const char* x_tyle = "X"; // YOU CAN CHANGE THIS.
const char* o_tyle = "O"; // YOU CAN CHANGE THIS.
const char* null_tyle = "-"; // YOU CAN CHANGE THIS.
int boardGame[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

void changePlayer()
{
    if ( player == 0 ) { player++; } else { player--; };
}

void printBoard( int array[3][3] )
{
    std::cout << "  012" << std::endl;
    for ( int x = 0; x < 3; x++ ) {
        std::cout << x << " ";
        for ( int y = 0; y < 3; y++ ) {
            if ( array[x][y] == x_type ) { std::cout << x_tyle;} 
            else if ( array[x][y] == o_type ) { std::cout << o_tyle;}
            else { std::cout << null_tyle; };
        };
        std::cout << std::endl;
    };
}

int* askPlayer()
{   
    const char* actualPlayer;
    int x_pos, y_pos;
    if ( player == 0 ) { actualPlayer = x_tyle; } else { actualPlayer = o_tyle; };
   
    std::cout << "(" << actualPlayer << ")" << " Choose a x position: ";
    std::cin >> x_pos;
   
    std::cout << "(" << actualPlayer << ")" << " Choose a y position: ";
    std::cin >> y_pos;
   
    int* final_pos = new int[2];
    final_pos[0] = x_pos;
    final_pos[1] = y_pos;
    return final_pos;
}

void checkInBoard( int* values, int array[3][3] )
{
    int actualPlayer;
    if ( player == 0 ) { actualPlayer = x_type; } else { actualPlayer = o_type; };
    for ( int x = 0; x < 3; x++ ) {
        for ( int y = 0; y < 3; y++ ) {
            if ( x == values[0] && y == values[1] ) {
                if ( array[x][y] == 0  ) {
                    array[x][y] = actualPlayer;
                    delete[] values;
                    decision = true;
                } else {
                    std::cout << "The current place is taken" << std::endl;
                    decision = false;
                };
            };
        };
    };
}

bool checkWin( int array[3][3] )
{   
    int actualNum;
    int array_one[3] = { array[0][0], array[0][1], array[0][2] };
    int array_two[3] = { array[1][0], array[1][1], array[1][2] };
    int array_three[3] = { array[2][0], array[2][1], array[2][2] };
    int array_four[3] = { array[0][0], array[1][0], array[2][0] };
    int array_five[3] = { array[0][1], array[1][1], array[2][1] };
    int array_six[3] = { array[0][2], array[1][2], array[2][2] };
    int array_seven[3] = { array[0][0], array[1][1], array[2][2] };
    int array_eight[3] = { array[0][2], array[1][1], array[2][0] };
    int* all_arrays[8] = { array_one, array_two, array_three, array_four, array_five, array_six, array_seven, array_eight};
    for ( int a = 0; a < 8; a++ ) {
        actualNum = all_arrays[a][0];
        if ( actualNum != 0 ) {
            if ( actualNum == all_arrays[a][1] && actualNum == all_arrays[a][2] ) {
                if ( player == 0 ) { std::cout << "(O) Wins!" << std::endl; } else { std::cout << "(X) Wins!!"; };
                printBoard( array );
                return 0;
            };
        };
    };
    return 1;
}

void gameLoop()
{  
    while ( checkWin(boardGame) ) {
        printBoard(boardGame);
        checkInBoard( askPlayer() , boardGame );
        if ( decision != false ) {
            changePlayer();
        };
    };
}

int main()
{
    gameLoop();
    return 0;
}