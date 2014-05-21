# include "warrior.h"

Warrior::Warrior(){
name = "";
level = 1;
hp = getMaxhp();
}

Warrior::Warrior(string s, int l){
name = s;
level = l;
hp = getMaxhp();
}
