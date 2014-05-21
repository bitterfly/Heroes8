# include "gameplay.h"

int main(){
    /*for (int ch = 0; ch <= 255; ch++) {
        cout<<(int)ch<<": "<<ch<<endl;
    } */
    Gameplay gp;
    while(gp.prompt()){
        gp.prompt();
    }
    //gp.prompt();
}
