#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

void boj(int &Zivoty, int Damage) {
    int typBandity = rand() % 3;
    int banditaZivoty;
    int banditaDamage;
    string jmenoBandity;

    switch (typBandity) {
        case 0:
            jmenoBandity = "Zloděj";
            banditaZivoty = 40;
            banditaDamage = 10;
            break;
        case 1:
            jmenoBandity = "Žoldák";
            banditaZivoty = 70;
            banditaDamage = 20;
            break;
        case 2:
            jmenoBandity = "Vrah";
            banditaZivoty = 55;
            banditaDamage = 30;
            break;
}
cout << "\nBojuješ s nepřítelem: " << jmenoBandity;
cout << "\nMá " << banditaZivoty << " životů a útočí za " << banditaDamage << ".\n";
        while (Zivoty > 0 && banditaZivoty > 0) {
        cout << "\nÚtočíš na banditu!";
        banditaZivoty -= Damage;
        cout << "\nZpůsobil jsi " << Damage << " poškození. Banditovi zbývá " 
             << (banditaZivoty > 0 ? banditaZivoty : 0) << " HP.";
            if (banditaZivoty <= 0) {
            cout << "\n\nBandita padá k zemi. Přežil jsi boj!" << endl;
            return;
            }
            cout << "\nBandita útočí!";
            Zivoty -= banditaDamage;
            cout << "\nUtrpěl jsi " << banditaDamage << " poškození. Zbývá ti " 
                 << (Zivoty > 0 ? Zivoty : 0) << " HP.";
            if (Zivoty <= 0) {
                cout << "\n\nTvé tělo padá k zemi... Bandité zvítězili." << "\n\nGAME OVER" << endl;
                exit(0);
        }
    }
}

int main(){
string Jmeno;
int Postava, Rozhodnuti, Rozhodnuti2, Rozhodnuti3, Rozhodnuti4, Rozhodnuti5;
int Zivoty = 0, Damage = 0;

srand(time(0));  

cout << "Výtej v této dobrodružné hře! ";
cout << "\nJaké je tvé jmáno dobrodruhu? ";
cin >> Jmeno;
cout << Jmeno << "\n\nZajmavé jméno, opravdu zajmavé. No tak se vydáme na toto dobrodružství, ale jsště před tím si zvol postavu!";

cout << "\nVyber si svou postavu:\n";
cout << "1. Válečník (Zivoty: 100, Damage: 40)\n";
cout << "2. Zloděj   (Zivoty: 70, Damage: 20)\n";
cout << "3. Lovec    (Zivoty: 85, Damage: 55)\n";
cout << "Zadej číslo postavy: ";
cin >> Postava;
switch(Postava){
    case 1:
        Zivoty = 100;
        Damage = 40;
        cout << "\nZvolil jsi Válečníka!" << endl;
        break;
    case 2:
        Zivoty = 70;
        Damage = 20;
        cout << "\nZvolil jsi Zloděje!" << endl;
        break;
    case 3:
        Zivoty = 85;
        Damage = 55;
        cout << "\nZvolil jsi Lovce!" << endl;
        break;
    default:
        cout << "\nNeplatná volba, rozhodnu za tebe, když jseš tak neschopnej, budeš Lovec." << endl;
        Zivoty = 85;
        Damage = 55;
}
cout << "\nDostali jsme se na křižovatku levý směr vede do lesa, pravý do malé vesničky" << "\nKam se vydáme? [P=1/L=2]";
cin >> Rozhodnuti;
  if(Rozhodnuti==1){ cout << "\nZajmavé rozhodnutí, jdeme do vesničky";
                   cout << "\nVesnice vypadá opuštěně, chceš ji vyrabovat? [A=1/N=0]";
                   cin >> Rozhodnuti2;
                      if(Rozhodnuti2==1){ cout << "\nBěhem tvého rabování se objevili vesničani s jejich iron golemem, boj byl zbytečný, byl jsi zabit."<< "\n\nGAME OVER" <<endl;}
                      else{ cout << "\nMoudré rozhodnutí, protože se během chvilky objevili vesničani s jejich iron golemem, naštěstí byli přátelští a moohl jsi pokračovat dál ve své cestě";} //-------------------------------------------------------------------------------------
  }else{ cout << "\nZajmavé rozhodnutí, jdeme do lesa";
        cout << "\nLes je tichý a ponurý, ale po chvíli slyšíš zvláštní zvuky.";
        cout << "\nNarazíš na starého muže sedícího u ohně. Chceš se s ním promluvit? [A=1/N=0]";
        cin >> Rozhodnuti3;
        if(Rozhodnuti3==1){
          cout << "\nStarý muž ti nabídne jídlo a varuje tě před nebezpečím hlouběji v lese.";
          cout << "\nZískal jsi nové informace. Pokračuješ dál a vyhíbáš se úseku s nebezpečím."; //-----------------------------------------------------------------------------
        } else {
          cout << "\nIgnoruješ starce a pokračuješ dál. Po pár krocích tě přepadne skupina banditů!";
          cout << "\nPřiprav se na boj! Máš šanci se bránit. Bojuješ? [A=1/N=0]";
          cin >> Rozhodnuti4;
                if(Rozhodnuti4==1){ 
                  boj(Zivoty, Damage);
                  } else {
                  cout << "\nSnažíš se utéct, ale bandité tě rychle doženou.";
                  cout << "\nByl jsi poražen a okraden. Dobrodružství pro tebe zde končí." << "\n\nGAME OVER" << endl;}
            }
      }
}
