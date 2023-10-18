#include <iostream>
#include <cmath>
#include <iomanip>
//#include <windows.h> 
using namespace std;

//CliFret 0.1.1  CC BY-NC-SA 4.0

//resoudre le problme d'accent
//enregistrer sur github et mettre un liens dans le code
//interface graphique plus joli
//ajouter une icone (https://www.iconarchive.com/download/i125408/pictogrammers/material/guitar-electric.ico)

float siToImp(float a) {
    return a / 25.4;
}

float impToSI(float b) {
    return b * 25.4;
}

float roundDot(float d, int pres) {
    return floor(d * pow(10, pres) + 0.5) / pow(10, pres);
}


int main() {
    system("Color 09");
    cout << fixed;

    float lenthGiven, lenthSI, lenthImp, fretXSI;
    int numberFret;
    bool siOverImp;

    wcout << "Bonjour,preferes-tu utiliser des mm ou inche ? (mm = 1, inch = 0)" << endl;
    cin >> siOverImp;
    wcout << "Quelle est le diapason de la corde (distance entre sillet et chevalet)(en ";
    if (siOverImp == 1) { cout << "mm)"; }
    else { cout << "inch)"; }
    cout << endl;
    cin >> lenthGiven;
    wcout << "Combien de frettes a calculer ?" << endl;
    cin >> numberFret;

    for (int i = 1; i <= 2; i++) {
        cout << endl;
    }

    wcout << "CliFret © 2023 by Chloe CHATEAU@Polytech-Saclay is licensed under CC BY-NC-SA 4.0" << endl;
    wcout << "Sur une idée de Nathan BECKER@Lycee-Fernand-Leger" << endl;

    for (int i = 1; i <= 2; i++) {
        cout << endl;
    }

    if (siOverImp == true) {
        lenthSI = lenthGiven;
    }
    if (siOverImp == false) {
        lenthSI = impToSI(lenthGiven);
        lenthImp = lenthGiven;
    }

    cout << "N    mm      inch" << endl;
    //cout << "━━━━━━━━━━━┳━━━━━━" << endl;
    cout << "------------------" << endl;

    for (float i = 1; i <= numberFret; i++) {
        fretXSI = lenthSI - (lenthSI * pow(2.0, (-i / 12)));
        cout << setprecision(0) << i;
        if (i < 10) { cout << " "; }
        cout << " : ";
        cout << setprecision(1) << roundDot(fretXSI, 1);
        if (roundDot(fretXSI, 1) < 100) { cout << " "; }
        //cout << " ┃ ";
        cout << " | ";
        cout << setprecision(2) << roundDot(siToImp(fretXSI), 2) << endl;
    }



    if (numberFret > 100) { wcout << "tu te fous de ma gueule ?"; }

    system("pause");

    return 0;



}
