#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
char board[8][8]={
    {'R','N','B','Q','K','B','N','R'},
    {'P','P','P','P','P','P','P','P'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'p','p','p','p','p','p','p','p'},
    {'r','n','b','q','k','b','n','r'}
};
int checkmate(){
    bool Kcheck=false;
    bool kcheck=false;
    for (int i=0;i<8;i++){
        for (int j=0;j<8;j++){
            if (board[i][j]=='K'){
                Kcheck=true;
            }
            if (board[i][j]=='k'){
                kcheck=true;
            }
        }
    }
    if (Kcheck==false){
        return 1;//white win
    }
    else if (kcheck==false){
        return -1; //black win
    }
    else {
        return 0; //game continue
    }
}
void display(){
    system("cls");
    cout<<"   a b c d e f g h\n";
    cout<<"  ----------------\n";
    for(int i=0;i<8;i++){
        cout<<8-i<<"| ";
        for(int j=0;j<8;j++){
            if (board[i][j]==' '){
                if (i%2==j%2) cout <<char (178);
                else cout <<' ';
                cout <<" ";
            }
            else 
            {  
                cout <<board[i][j];
                cout <<" ";
            }
        }
        cout<<"\n";
    }
    
}

signed main(){
    int turn=0;
    //system("color 0A");
    cout<<"Welcome to Chess!\n";
    cout<<"-------------------\n";
    cout <<"press enter to start the game\n";
    cin.get();
    // main loop
    while (true){
        turn++;
        display();
        if (checkmate()==0) {
            if (turn%2==1) cout <<"White's turn(lower_bound):";
            else cout <<"Black's turn(upper_bound):";
        }
        else if (checkmate()==1) {
            cout <<"White has win the game!";
            break;
        }
        else if (checkmate()==-1) {
            cout <<"Black has win the game!";
            break;
        }
        else {
            cout <<"Game over!";
            break;
        }
        cout <<turn;
        if (turn%10==1) cout <<"st";
        else if (turn%10==2) cout <<"nd";
        else if (turn%10==3) cout <<"rd";
        else cout <<"th";
        cout << " turn\n";
        string move;
        cout<<"Enter your move (e.g., e2 e4): ";
        getline(cin,move);
        bool val=true;
        if (move=="exit") break;
        if (move.length()!=5 || move[2]!=' ') {
            cout<<"Invalid move format. Please use 'e2 e4' format.\n";
            Sleep(2000);
            continue;
        }
        int startX=8-(move[1]-'0'),startY=move[0]-'a',endX=8-(move[4]-'0'),endY=move[3]-'a';
        if (startX<0 || startX>7 || startY<0 || startY>7 || endX<0 || endX>7 || endY<0 || endY>7) {
            val=false;
            cout<<"Invalid move. Out of bounds.\n";
            Sleep(2000);
            continue;
        }
        if (board[startX][startY]==' ') {
            val=false;
            cout<<"No piece at starting position.\n";
            Sleep(2000);
            continue;
        }
        // white is lower_bound
        if (turn%2==1 && isupper(board[startX][startY])) {
            val=false;
            cout<<"It's white's turn.\n";
            Sleep(2000);
            turn--;
            continue;
        }
        // black is upper_bound
        if (turn%2==0 && isupper(board[startX][startY])==false)
        {
            val=false;
            cout <<"It's black's turn.\n";
            Sleep(2000);
            turn--;
            continue;
        }
        if (val){
            board[endX][endY]=board[startX][startY];
            board[startX][startY]=' ';
        }

    }
}