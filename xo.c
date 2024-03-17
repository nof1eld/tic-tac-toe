#include <stdlib.h>
#include <stdlib.h>

char board[3][3];
char column = '1';
char X_column, O_column;

//fill the board with numbers from 1 to 9
void setBoard(){
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           board[i][j] = column;
           column++;
        }    
    }
}
//draw the board for the user to pick a column (numerated from 1 to 9)
void drawBoard(){
    for (int i = 0; i < 3; i++)
    {
        if (i==0)
        {
           printf("\n");
        }
        
        
        for (int j = 0; j < 3; j++)
        {
            printf("%c",board[i][j]);
            if(j<2){
                printf(" | ");
            }   
        }
        if(i<2){
               printf("\n----------\n");
            } else {
                printf("\n");
            }
             
       
    }
}
//accept input(column number) from player X
void fillBoard_X(){
    printf("\n(Player X) Enter column number: ");
    scanf(" %c", &X_column);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == X_column)
            {
                board[i][j] = 'X';
            }
        }    
    }
    //draw the board for next turn
    drawBoard();
}
//same here (player O)
void fillBoard_O(){
    printf("\n(Player O) Enter column number: ");
    scanf(" %c", &O_column);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == O_column)
            {
                board[i][j] = 'O';
            }
        }    
    }
    drawBoard();
}
//check for any win case
int checkWin(void){
    //check x axis
    for (int j = 0; j < 3; j++)
    {
        if (board[j][1] == board[j][0] && board[j][0] == board[j][2])
        {
            return 1;
            break;
        }
    }
    //check y axis
    for (int i = 0; i < 3; i++)
    {
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i])
        {
            return 1;
            break;
        }
        
    }
    //check diagonals
     for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) 
           || (board[2][0] == board[1][1] && board[1][1] == board[0][2]))
        {
            return 1;
            break;
        } 
        }
        
    }

}
//decide if there is a win or tie and decide the winner (according to previous checkWin()), then either stops or continues the game
void checkWinner(){
    //count number of turns played (must not exceed 9 ==> 5 for X, 4 for O)
    int turn = 0;
    for (int i = 0; i < 5; i++)
    {
        if (checkWin() != 1)
        {
            fillBoard_X();
            turn++;
        } else
        {
            //if previous turn of player O made him win
            printf("\nPlayer O has won !\n");
            break;
        }
        if (checkWin() != 1 && turn != 9)
        {
            fillBoard_O();
            turn++;
        } else if (turn != 9) // && checkWin() == 1
        {
            printf("\nPlayer X has won !");
            break;
        } 
        else //9 turns were played with no winner
        {
            printf("Tie !\n");
            break;
        }
       
        
    }
}

int main(){
    setBoard();
    drawBoard();
    checkWinner();
    return 0;
}