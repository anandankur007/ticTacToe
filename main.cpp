#include "iostream"
using namespace std;

class Move {
    int player;
    int row;
    int col;
    public:
    Move(int player, int row, int col) {
        this->player = player;
        this->row = row;
        this->col = col;
    }
};
class Game {
    int board[3][3];    // game board
    int rowVec[3];      //row val storage to check if the current player won the game
    int colVec[3];      //col val storage to check if the current player won the game
    int dia;        //diagonal val storage to check if the current player won the game
    int revDia;     //reverse diagonal val storage to check if the current player won the game
    int numberOfMoves;  //total number of moves till current timestamp
    int winner;     //winning player of the game
    vector<Move*> moveList;     //stores all the moves and user can print it. Also useful for undo movess
    public:
    Game() {
        memset(board, -1, sizeof(board));
        memset(rowVec, 0, sizeof(rowVec));
        memset(colVec, 0, sizeof(colVec));
        dia = 0;
        revDia = 0;
        numberOfMoves = 0;
        winner = 0;
    }
    static int lastTurn;    //player with last turn
    int status;     //current status of the game
    int makeMove(int player, int row, int col);
    void getCurrStatus();
    void getWinner();
};
int Game :: lastTurn = 0;
int Game :: makeMove(int player, int row, int col) {
    if(winner != 0)
    return winner;
    //move out of range
    if(row<0 || row>=3 || col<0 || col>=3)
    return INT_MAX;
    //same player again
    if(lastTurn!=0 && lastTurn==player)
    return INT_MIN;
    if(board[row][col] != -1)
    return -1;
    moveList.push_back(new Move(player, row, col));
    numberOfMoves++;
    board[row][col] = player;
    int plyr = (player==1)?1:-1; 
    rowVec[row]+=plyr;
    colVec[col]+=plyr;
    if(row==col)
    dia+=plyr;
    if(row+col==2)
    revDia+=plyr;
    lastTurn = player;
    if(abs(rowVec[row])==3 || abs(colVec[col])==3 || abs(dia)==3 || abs(revDia)==3)
    return player;
    //not decided yet
    return 0;
}

void Game :: getCurrStatus() {
    if(status == 1 || status == 2) {
        winner = status;
        cout<<"Game finished! Player "<<status<<" won the game\n";
    } else if(status == 0 && numberOfMoves < 9) {
        cout<<"Game in progress\n";
    } else if(status == INT_MAX) {
        cout<<"Invalid move\n";
    } else if(status == INT_MIN) {
        cout<<"Other player's turn\n";
    }
    else if(status == -1) {
        cout<<"Invalid entry\n";
    } else {
        cout<<"Game drawn\n";
    }
}

void Game :: getWinner() {
    if(winner != 0) {
        cout<<"Player "<<status<<" won the game\n";
    } else if(numberOfMoves > 0 && numberOfMoves < 9){
        cout<<"Not any winner yet. Game in progress\n";
    } else if(numberOfMoves == 0){
        cout<<"Game not started yet\n";
    } else {
        cout<<"Game drawn\n";
    }
}

int main() {
    Game *game = new Game();
    game->getWinner();
    game->status = game->makeMove(1, 0, 0);
    game->getCurrStatus();
    game->status = game->makeMove(2, 0, 1);
    game->getCurrStatus();
    game->status = game->makeMove(1, 0, 2);
    game->getCurrStatus();
    game->status = game->makeMove(2, 1, 0);
    game->getCurrStatus();
    game->status = game->makeMove(1, 1, 1);
    game->getCurrStatus();
    game->getWinner();
    game->status = game->makeMove(2, 1, 2);
    game->getCurrStatus();
    game->status = game->makeMove(1, 2, 0);
    game->getCurrStatus();
    game->getWinner();
    game->status = game->makeMove(2, 2, 1);
    game->getCurrStatus();
    game->status = game->makeMove(1, 2, 2);
    game->getCurrStatus();
    game->getWinner();
}

