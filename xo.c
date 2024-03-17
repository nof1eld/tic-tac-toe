#include <stdlib.h>
#include <stdlib.h>

char board[3][3];
char column = '1';
char X_column, O_column;

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

void drawBoard(){
    for (int i = 0; i < 3; i++)
    {
       for (int j = 0; j < 3; j++)
       {
           printf("%c",board[i][j]);
           if(j<2){
               printf(" | ");
           }   
       }
       printf("\n");
    }
}

void fillBoard_X(){
    printf("Enter column number: ");
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
    drawBoard();
}
void fillBoard_O(){
    printf("Enter column number: ");
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

int checkWinner(void){
    return 0;
    for (int j = 0; j < 3; j++)
    {
        if (board[0][j] == board[1][j])
        {
            return 1;
            break;
        } else
        {
            return 0;
        }
    }
    for (int i = 0; i < 3 && checkWinner()!= 1; i++)
    {
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2])
        {
            return 1;
            break;
        } else
        {
            return 0;
        }
        
    }
    for (int i = 0; i < 3 && checkWinner()!= 1; i++)
    {
        for (int j = 0; j < 3; j++)
        {
           if ((board[0][0] == board[1][1] && board[1][1] == board[2][2]) || (board[2][0] == board[1][1] && board[1][1] == board[0][2]))
        {
            return 1;
            break;
        } else
        {
            return 0;
        }
        }
        
    }
    
}
void checkwinner(){
    for (int i = 0; i < 5; i++)
    {
        printf("checkwinner value = %d\n", checkWinner());
        if (checkWinner() != 1)
        {
            fillBoard_X();
        } else
        {
            printf("The winner is: O\n");
            break;
        }
        printf("checkwinner value = %d\n", checkWinner());
        if (checkWinner() != 1)
        {
            fillBoard_O();
        } else
        {
            printf("The winner is: X\n");
            break;
        }
    }
}

int main(){
    setBoard();
    drawBoard();
    checkwinner();
    return 0;
}