# include "gameplay.h"
# include <time.h>
int main(){
    srand(time(NULL));
    /*for (int ch = 0; ch <= 255; ch++) {
        cout<<(int)ch<<": "<<ch<<endl;
    } */
    Gameplay gp;
    while(gp.prompt()){
        gp.prompt();
    }
    //gp.prompt();
}
