#include <bits/stdc++.h>
#include <windows.h>
#include <conio.h>
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
void notfinished(){
    system("cls");
    cout<<"Dev-note:\n";
    cout<<"logic system and promotion funcion are unfinished yet\n";
    cout <<"press any key to continue...\n";
    getch();
}
void introduction(){
    system("cls");
    cout<<"Introduction:\n";
    cout<<"Chess is a two-player strategy board game played on an 8x8 grid.\n";
    cout<<"The objective is to checkmate the opponent's king.\n";
    cout<<"Each type of piece has its own movement rules.\n";
    cout<<"The game starts with each player having 16 pieces:\n";
    cout<<"1 King, 1 Queen, 2 Rooks, 2 Knights, 2 Bishops, and 8 Pawns.\n";
    cout<<"Players take turns moving one piece at a time.\n";
    cout<<"If a player's king is in check and cannot escape, it's checkmate!\n";
    cout <<"press any key to continue...\n";
    getch();
}   
void help(){
    system("cls");
    cout<<"Help:\n";
    cout<<"1. Enter your move in the format 'e2 e4'.\n";
    cout<<"2. The first part is the starting position, and the second part is the ending position.\n";
    cout<<"3. Use lowercase letters for black pieces and uppercase for white pieces.\n";
    cout<<"4. Type 'exit' to quit the game.\n";
    cout <<"press any key to continue...\n";
    getch();
}
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

void game(){
    int turn=01;
    //system("color 0A");
    
    // main loop
    while (true){
        
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
            
            continue;
        }
        // black is upper_bound
        if (turn%2==0 && isupper(board[startX][startY])==false)
        {
            val=false;
            cout <<"It's black's turn.\n";
            Sleep(2000);
            
            continue;
        }
        if (val){
            board[endX][endY]=board[startX][startY];
            board[startX][startY]=' ';
            turn++;
        }

    }
}
signed main(){
    while (true){
        system ("cls");
        cout<<"Welcome to Chess!\n";
        cout<<"-------------------\n";
        cout <<"press 1 to start the game\n";
        cout <<"press 2 for introduction\n";
        cout <<"press 3 to get help\n";
        cout <<"press 4 for dev-note\n";
        cout <<"press 5 to quit\nYour choice: ";
        int choice;
        cin >>choice;
        if (choice==1) game();
        else if (choice==2) introduction();
        else if (choice==3) help();
        else if (choice==4) notfinished();
        else if (choice==5) return 0;
    }
    return 0;
}
