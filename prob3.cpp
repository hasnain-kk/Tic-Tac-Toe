#include <bits/stdc++.h>
using namespace std;

string space[3][3]={ { "1", "2", "3" } , { "4", "5", "6" } , { "7", "8", "9" } };
int input1, input2, row, col;

void table(){


        cout<< "\t\t            *         *        \n";
        cout<< "\t\t        "<<space[0][0]<<"   *    "<<space[0][1]<<"    *    "<<space[0][2]<<"   \n";
        cout<< "\t\t            *         *        \n";
        cout<< "\t\t    ***************************\n";
        cout<< "\t\t            *         *        \n";
        cout<< "\t\t        "<<space[1][0]<<"   *    "<<space[1][1]<<"    *    "<<space[1][2]<<"   \n";
        cout<< "\t\t            *         *        \n";
        cout<< "\t\t    ***************************\n";
        cout<< "\t\t            *         *        \n";
        cout<< "\t\t        "<<space[2][0]<<"   *    "<<space[2][1]<<"    *    "<<space[2][2]<<"   \n";
        cout<< "\t\t            *         *        \n\n";

        return;
}

bool check(int n){

    switch(n){
        case 1: row=0; col=0; break;
        case 2: row=0; col=1; break;
        case 3: row=0; col=2; break;
        case 4: row=1; col=0; break;
        case 5: row=1; col=1; break;
        case 6: row=1; col=2; break;
        case 7: row=2; col=0; break;
        case 8: row=2; col=1; break;
        case 9: row=2; col=2; break;
    }

    if(n<1 || n>9 || space[row][col]=="X" || space[row][col]=="O"){
        cout << "Not acceptable" << endl;
        cout << "Enter again: "; return true;
    }

    return false;
}

void changeTable1(){

    space[row][col]="X";
    return;
}

void changeTable2(){
    space[row][col]="O";
    return;
}

bool win(string s){
    
    for(int i=0; i<3; i++){
        if(space[i][0]==s && space[i][1]==s && space[i][2]==s) return true;
        if(space[0][i]==s && space[1][i]==s && space[2][i]==s) return true;
    }

    if(space[0][0]==s && space[1][1]==s && space[2][2]==s) return true;
    if(space[0][2]==s && space[1][1]==s && space[2][0]==s) return true;
    
    return false;
}

int main ()

{

 
    table();
    int i=1;

    string name1;
    cout << "Enter name of 1st player: ";
    cin >> name1;
    string n1=name1;
    name1+=" Your Turn: ";

    string name2;
    cout <<"Enter name of 2nd player: ";
    cin >> name2;
    string n2=name2;
    name2+=" Your Turn: ";

    for(i ; i<=9; i++){

        if(i%2==1){
            cout << name1;
            do{
                cin >> input1;
            }while( check(input1) );
            changeTable1();
            system("cls");
            table();
            if(win("X")){
                cout << n1<<" wins";
                break;
            }
        }

        else {
            cout << name2;
            do{
                cin >> input2;
            }while( check(input2) );
            changeTable2();
            system("cls");
            table();
            
            if(win("O")){
                cout << n2<<" wins";
                break;
            }
        }
    }

    if(i==10) cout << "Game is tie";

    return 0;
}