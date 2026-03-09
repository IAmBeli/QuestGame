#include<fstream>
#include<vector>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
int main(){
    srand(time(0));
    string name;
    int health = 100;
    int damage = 20;
    int gold = 0;
    int level = 1;
    ifstream loadFile("save.txt");
    if(loadFile.is_open()){
        string savedName;
        int savedHealth;
        int savedDamage;
        int savedGold;
        int savedLevel;
        if(loadFile >> savedName >> savedHealth >> savedDamage >> savedGold >> savedLevel){
            name = savedName;
            health = savedHealth;
            damage = savedDamage;
            gold = savedGold;
            level = savedLevel;
            cout << "Welcome back!" << endl;
            cout << "Health: " << health << " HP" << endl;
            cout << "Damage: " << damage << " DMG" << endl;
            cout << "Gold: " << gold << endl;
        }
        loadFile.close();
    }else{cout << "Welcome to the dark forest!" << endl;
    cout << "Enter your hero's name: ";
    cin >> name;}
    cout << "Hero " << name << ", you have " << health << " HP. Your journey begins!" << endl;
    if(level == 1){int choice;
    cout << "1. Go into the cave" << endl;
    cout << "2. Follow the forest path" << endl;
    do{cout << "Your choice(1/2): ";
    cin >> choice;}while(choice != 1 && choice != 2);
    if(choice == 1){
        cout << "It's dark here... You found a rusty sword! Damage increased!" << endl;
        damage += 20;
        level += 1;
    }else if(choice == 2){
        cout << "A wolf is blocking your way! Fight is starting!" << endl;
        int takenDamage = rand() % 20 + 10;
        health -= takenDamage;
        gold += 50;
        cout << "You defeated the wolf, but lost " << damage << " HP during this fight" << endl;
        cout << "You found 50 gold" << endl;
        level += 1; 
    }}
    if(level == 2){cout << "You found a mysterious merchant. Do you want to buy healing potion for 40 gold?(y/n): ";
    char choice1;
    cin >> choice1;
    if(choice1 == 'Y' || choice1 == 'y'){
        cout << "You bought a healing potion for 40 gold." << endl;
        gold -= 40;
        cout << "You have " << gold << " gold left" << endl;
        level += 1;
    }else if(choice1 == 'N' || choice1 == 'n'){
        cout << "You declined his offer." << endl;
        cout << "You have " << gold << " gold left" << endl;
        level += 1;
    }}
    
    ofstream saveFile("save.txt");
    if(saveFile.is_open()){
        saveFile << name << endl;
        saveFile << health << endl;
        saveFile << damage << endl;
        saveFile << gold << endl;
        saveFile << level << endl;
        saveFile.close();
        cout << "Progress saved to save.txt!" << endl;
    }else if(!saveFile.is_open()){cout << "Error: could not create save file!" << endl;}
    return 0;
}