//position check
//cout << Tape[a.posx][a.posy] << "-" << a.rot << endl << "==========================" << endl;


#include <iostream>
using namespace std;

class ant {
public:
    ant(int y, int x, int r) {
        posx = x;
        posy = y;
        rot = r;
        startposx = x;
        startposy = y;
    }
    int posx;
    int posy;
    int rot;
    int startposy;
    int startposx;
};


int main() {
    //creating components
    int outputcode;
    int moves = 0;
    int sqb = 0;
    int sqw = 0;
    //creating user-end variables
    int tapey;
    int tapex;
    int tapefilling;
    int anty;
    int antx;
    int antrot;
    int rounds;
    int tapesmaller;
    int tapebigger;
    char invalidsize;
    //reactive programme
    cout << "Please input the Tape's number of rows (Y)." << endl;
    cin >> tapey;
    cout << "Please input the Tape's number of columns (X)." << endl;
    cin >> tapex;
    cout << "Please input the Tape's filling. Note that it limits to either 0(as white) and 1(as black)." << endl;
    cin >> tapefilling;
    while (tapefilling != 0 && tapefilling != 1) {
        cout
                << "You have input a tape filling different than 1 or 0. The ant can only operate on a 2-state tape so please use a proper value."
                << endl;
        cin >> tapefilling;
    }
    cout << "Please input the ant's starting Y coordinate (humanized)." << endl;
    cin >> anty;
    if (anty == 0)
        anty = 0;
    else anty -= 1;
    cout << "Please input the ant's starting X coordinate (humanized)." << endl;
    cin >> antx;
    if (antx == 0)
        antx = 0;
    else antx -= 1;
    cout << "Please input the ant's starting rotation. Note that it is limited to 0, 90, 180 and 270 degrees." << endl;
    cin >> antrot;
    while (antrot != 0 && antrot != 90 && antrot != 180 && antrot != 270) {
        cout
                << "You have input a rotation different from 0, 90, 180 or 270 degrees. The ant can only operate on those values so please use a proper angle."
                << endl;
        cin >> antrot;
    }
    cout << "Please input the number of moves you would like the ant to execute." << endl;
    cin >> rounds;
    //safety check, delete this if you want to experiment
    if (tapey > tapex) {
        tapesmaller = tapex;
        tapebigger = tapey;
    } else {tapesmaller = tapey; tapebigger = tapex;}
    //2x+2
   while ((tapesmaller == 1 && rounds > 1) || (tapesmaller == 2 && rounds > 4) || (rounds > 3 * tapesmaller + tapebigger / 2 && tapesmaller < 9) || (tapesmaller > 8 && rounds > 10 * (tapesmaller + tapebigger))) {
        cout << "By rough calculation it seems that you want the ant to move a lot of times for the tape you've used." << endl;
        cout << "During those moves the ant is likely to go off the tape and that guarantees an error in the programme" << endl;
        cout << "Please make sure to make the tape big enough for the ant to move freely around it." << endl;
        cout << "Please input a character (t or m) to choose what you'd like to edit a value of." << endl;
        cin >> invalidsize;
        while (invalidsize != 'm' && invalidsize != 't') {
            cout << "Please input a correct character (t or m)." << endl;
            cin >> invalidsize;
        }
        if (invalidsize == 't') {
            cout << "You've chose to correct the tape size. Please now input its Y size." << endl;
            cin >> tapey;
            cout << "Now X size." << endl;
            cin >> tapex;
        }
        if (invalidsize == 'm') {
            cout << "You've chosen to correct the number of moves the ant will execute. Please input a corrected value."
                << endl;
            cin >> rounds;
        }
    }

    cout << endl << "==========================" << endl;
    //applying user-end variables
    ant a(anty, antx, antrot);
    int Tape[tapey][tapex];
    //making and checking the Tape
    for (int i = 0; i<tapey; i++) {
        cout << "|";
        for (int j = 0; j<tapex; j++) {
            Tape[i][j] = tapefilling;
            cout << Tape[i][j] << "|";
        }
        cout << endl;
    }
    //testing moves

    cout << "==========================" << endl;
    //main math, rounds
    for (int i = 0; i<rounds; i++) {
        if (Tape[a.posy][a.posx] == 0) {
            Tape[a.posy][a.posx] = 1;
            switch (a.rot){
                case 0:
                    a.rot = 270;
                    a.posx--;
                    break;
                case 270:
                    a.rot = 180;
                    a.posy++;
                    break;
                case 180:
                    a.rot = 90;
                    a.posx++;
                    break;
                case 90:
                    a.rot = 0;
                    a.posy--;
                    break;
                default:break;
            }
        }
        else {
            Tape[a.posy][a.posx] = 0;
            switch (a.rot) {
                case 0:
                    a.rot = 90;
                    a.posx++;
                    break;
                case 90:
                    a.rot = 180;
                    a.posy++;
                    break;
                case 180:
                    a.rot = 270;
                    a.posx--;
                    break;
                case 270:
                    a.rot = 0;
                    a.posy--;
                    break;
                default:break;
            }
        }
        // computing final note
        moves++;
        //numeration
        cout << "Move humanized " << i+1 << "(" << i << ")" << endl;
        //array printing
        for (int i = 0; i<tapey; i++) {
            cout << "|";
            for (int j = 0; j<tapex; j++) {
                if (i == a.posy && j == a.posx) {
                        if (Tape[i][j] == 0) {
                            switch (a.rot) {
                                case 0:
                                    cout << 2 << "|";
                                    break;
                                case 90:
                                    cout << 3 << "|";
                                    break;
                                case 180:
                                    cout << 4 << "|";
                                    break;
                                case 270:
                                    cout << 5 << "|";
                                    break;
                                default:break;
                            }
                        }
                        else {
                            switch (a.rot){
                                case 0:
                                    cout << 6 << "|";
                                    break;
                                case 90:
                                    cout << 7 << "|";
                                    break;
                                case 180:
                                    cout << 8 << "|";
                                    break;
                                case 270:
                                    cout << 9 << "|";
                                    break;
                                default:break;
                            }
                        }
                }
                else {cout << Tape[i][j] << "|";}
            }
            cout << endl;
        }
        if (Tape[a.posy][a.posx] == 0) {
            switch (a.rot) {
                case 0:
                    outputcode = 2;
                    break;
                case 90:
                    outputcode = 3;
                    break;
                case 180:
                    outputcode = 4;
                    break;
                case 270:
                    outputcode = 5;
                    break;
                default:
                    break;
            }
        }
        else {
            switch (a.rot){
                case 0:
                    outputcode = 6;
                    break;
                case 90:
                    outputcode = 7;
                    break;
                case 180:
                    outputcode = 8;
                    break;
                case 270:
                    outputcode = 9;
                    break;
                default:break;
            }
        }
        //displaying final note per move
        cout << "Ant position-rotation: " << Tape[a.posy][a.posx] << "-" << a.rot << endl;
        cout << "Ant coordinates: [" << a.posy << "]y[" << a.posx << "]x." << endl;
        cout << "Ant pos-rot output code: " << outputcode << endl;
        cout << "==========================" << endl;
    }
    //displaying numerators
    cout << "|";
    for (int i = 0; i < tapex; i++){
        if (i >= 10) {
            cout << i-10 << "|";
        }
        else cout << i << "|";
    }
    cout << endl << "==========================" << endl;
    //computing final note
    for (int i = 0; i < tapey; i++) {
        for (int j = 0; j < tapex; j++) {
            switch (Tape[i][j]) {
                case 0:
                    sqw++;
                    break;
                case 1:
                    sqb++;
                    break;
                default:break;
            }
        }
    }
    //displaying final note
    cout << "The ant has moved " << moves << " times and has changed the same number of squares." << endl;
    if (tapefilling == 0) {
        cout << sqw << " of them stayed white while " << sqb << " got changed to black." << endl;
    }
    else {
        cout << sqb << " of them stayed black while " << sqw << " got changed to white." << endl;
    }
    cout << "The ant finished on point [" << a.posy << "]y[" << a.posx <<
    "]x, which is [" << a.posy-a.startposy << "]y[" << a.posx-a.startposx << "]x squares away from its starting point." << endl;
}
