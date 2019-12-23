#include <iostream>  
#include <vector>
#include <unistd.h>
using namespace std; 


/*   ^
    ^^^
   ^^^^^
  ^^^^^^^
 ^^^^^^^^^
^^^^^^^^^^^ */

int enterNum();
void draw_tree1(int levels);
void draw_tree2(int levels);
vector <vector<char> > tree;
void printTree();

int main(){
    //draw_tree1(enterNum());
     draw_tree2(enterNum());
    return 0;
}

int enterNum(){
    int num ;
    cout << "Enter a number: " ;
    cin >> num;
    return num; 
}

void draw_tree1(int levels){
    for (int i= 0; i < levels; i++){ // level 
       // cout << "I'm level at : " << i+1 << endl;
       for (int k = levels; k >= i; k--){
           cout << " ";
       }
       for (int j= 0; j <= (i * 2); j++){ // leaves
           cout << "^";
       }
       cout << endl; // for another line
    }
}

void draw_tree2(int levels){
    for (int i= 0; i < levels; i++){ // level 
       // cout << "I'm level at : " << i+1 << endl;
       vector<char>level;
       for (int k = levels; k >= i; k--){
           level.push_back(' '); //cout << " ";
       }
       for (int j= 0; j <= (i * 2); j++){ // leaves
           level.push_back('^'); //cout << "^";
       }
       tree.push_back(level); //cout << endl; // for another line
    }
    //printTree();
    while(1){
        system("clear"); 
        int row = rand() % tree.size();  // random level
        int col = rand() % tree.at(row).size(); // random leave at level
        if (tree.at(row).at(col)== '^'){
            tree.at(row).at(col) = '*';
        }
        else if (tree.at(row).at(col)=='*'){
            tree.at(row).at(col) = '^';
        }
        printTree();
        usleep(1000000); // miliseconds
    }
}

void printTree(){
    for (int i = 0; i< tree.size(); i++){
        for (int j= 0; j< tree.at(i).size(); j++){
            cout << tree.at(i).at(j);
        }
        cout << endl;
    }
}
