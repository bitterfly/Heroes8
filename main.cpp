# include "gameplay.h"
# include <time.h>
int main(){
    srand(time(NULL));
    Gameplay gp;
    while(gp.prompt()){
        gp.prompt();
    }
}
