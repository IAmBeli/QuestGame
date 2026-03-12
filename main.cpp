#include<fstream>
#include<vector>
#include<iostream>
#include<string>
#include<ctime>
using namespace std;
struct Level{
    string description;
    int hp_change;
    int damage_change;
    int gold_change;
};
int main(){
    srand(time(0));
    string name = "Hero";
    int health = 100;
    int damage = 20;
    int gold = 0;
    vector<Level> game_levels = {
        {"Forest", 0, 50},
        {"Dark cave", 20, 0},
        {"Mountain path", -10, 100}
    };
    for(const auto& lvl : game_levels){
        cout << "\nEnterring: " << lvl.description << "..." << endl;
        health += lvl.hp_change;
        damage += lvl.damage_change;
        gold += lvl.gold_change;
        cout << "Stats changed! HP: " << health << " | DMG: " << damage << " | Gold: " << gold << endl;
        if(health <= 0){
            cout << "You died!" << endl;
            break;
        }
    }
    ofstream saveFile("save.txt");
    saveFile << name << "\n" << health << "\n" << damage << "\n" << gold << "\n1" << endl;
    saveFile.close();
    cout << "\nGame finished! Stats saved." << endl;
    return 0;
}