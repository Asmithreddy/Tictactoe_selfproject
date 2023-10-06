#include <iostream>
using namespace std;

void display(char board[3][3]){
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            cout << board[row][col];
            if (col < 2) {
                cout << " | ";
            }
        }
        cout << endl;
        if (row < 2) {
            cout << "----------" << endl;
        }
    }
    cout << endl;
}

void makemove(char board[3][3],char current){
    int m,n;
    cout<<"Make a move(select Row and column)";
    cin>>m>>n;
    if ((m>=1 && m<=3)&(n>=1 && n<=3)&& (board[m-1][n-1]==' ')){
        board[m-1][n-1]=current;
        display(board);
    }
    else {cout<<"Invalid move, try again !!";}   
    } 

bool Check_win(char board[3][3],char current){
    int i,j;
    for (int i=0;i<3;i++){
        if (board[i][0]==current && board[i][1]==current && board[i][2]==current ){return true;}
    }
    for (int j=0;j<3;j++){
        if (board[0][j]== current && board[1][j]== current && board[2][j]==current ){return true;}
    }
    if (board[0][0]== current && board[1][1]== current && board[2][2]==current ){return true;}
    if (board[0][2]== current && board[1][1]== current && board[2][0]==current ){return true;}
    else return false;

}

bool IsBoardFull(char board[3][3]) {
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board[row][col] == ' ') {
                return false; // There's an empty space; board is not full
            }
        }
    }
    return true; // No empty spaces; board is full
}


int main(){
    char board[3][3]= {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};
    char Player_1='X';
    char Player_2='O';
    bool win;
    display(board);
    char current='X';
    cout<<"Its player_1 Turn"<<endl;
    while (true){
        makemove(board,current);
        win = Check_win(board,current);
        if (win == true){
            if (current == 'X'){cout<<"The winner is Player_1";}
            else {cout<<"The winner is Player_2";}
            break;
        }
        if (IsBoardFull(board)) {
            display(board);
            cout << "It's a draw!" << endl;
            break;
        }
        if (current=='X'){
            current='O';
            cout<<"its player_2 turn :"<<endl;   
        }
        else { 
            current='X';
            cout<<"Its player_1 Turn :"<<endl;
        }

    }    
}



    
