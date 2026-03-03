#include<fstream>
#include<vector>
#include<iostream>
#include<string>
using namespace std;
int main(){
    string name;
    int health = 100;
    int damage = 20;
    cout << "Welcome to the dark forest!" << endl;
    cout << "Enter your hero's name: ";
    cin >> name;
    cout << "Hero " << name << ", you have " << health << " HP. Your journey begins!" << endl;
    int choice;
    cout << "1. Go into the cave" << endl;
    cout << "2. Follow the forest path" << endl;
    do{cout << "Your choice(1/2): ";
    cin >> choice;}while(choice != 1 && choice != 2);
    if(choice == 1){
        cout << "It's dark here... You found a rusty sword! Damage increased!" << endl;
        damage += 20;
    }else if(choice == 2){
        cout << "A wolf is blocking your way! It bites you before you run away." << endl;
        health -= 20;
    }
    ofstream saveFile("save.txt");
    if(saveFile.is_open()){
        saveFile << name << endl;
        saveFile << health << endl;
        saveFile << damage << endl;
        saveFile.close();
        cout << "Progress saved to save.txt!" << endl;
    }else if(!saveFile.is_open()){cout << "Error: could not create save file!" << endl;}
    return 0;
}