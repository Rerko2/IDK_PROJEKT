#include <iostream>
#include <string>
using namespace std;

int main(){
string Jmeno;
int Rozhodnuti, Rozhodnuti2, Rozhodnuti3, Rozhodnuti4, Rozhodnuti5;
cout << "výtej v této dobrodružné hře! ";
cout << "\nJaké je tvé jmáno dobrodruhu? ";
cin >> Jmeno;
cout << Jmeno << "\n\nZajmavé jméno, opravdu zajmavé. No tak se vydáme na toto dobrodružství";
cout << "\nDostali jsme se na křižovatku levý směr vede do lesa, pravý do malé vesničky" << "\nKam se vydáme? [P=1/L=2]";
cin >> Rozhodnuti;
  if(Rozhodnuti==1){ cout << "\nZajmavé rozhodnutí, jdeme do vesničky";
                   cout << "\nVesnice vypadá opuštěně, chceš ji vyrabovat? [A=1/N=0]";
                   cin >> Rozhodnuti2;
                      if(Rozhodnuti2==1){ cout << "\nBěhem tvého rabování se objevili vesničani s jejich iron golemem, boj byl zbytečný, byl jsi zabit."<< "\n\nGAME OVER" <<endl;}
                      else{ cout << "\nMoudré rozhodnutí, protože se během chvilky objevili vesničani s jejich iron golemem, naštěstí byli přátelští a moohl jsi pokračovat dál ve své cestě";}
  }else{ cout << "\nZajmavé rozhodnutí, jdeme do lesa";
        cout << "\nLes je tichý a ponurý, ale po chvíli slyšíš zvláštní zvuky.";
        cout << "\nNarazíš na starého muže sedícího u ohně. Chceš se s ním promluvit? [A=1/N=0]";
        cin >> Rozhodnuti3;
        if(Rozhodnuti3==1){
          cout << "\nStarý muž ti nabídne jídlo a varuje tě před nebezpečím hlouběji v lese.";
          cout << "\nZískal jsi nové informace. Pokračuješ dál a vyhíbáš se úseku s nebezpečím.";
        } else {
          cout << "\nIgnoruješ starce a pokračuješ dál. Po pár krocích tě přepadne skupina banditů!";
          cout << "\nPřiprav se na boj! Máš šanci se bránit. Bojuješ? [A=1/N=0]";
                if(Rozhodnuti4==1){ -BOJ/SYSTÉM-;
                  } else {
                  cout << "\nSnažíš se utéct, ale bandité tě rychle doženou.";
                  cout << "\nByl jsi poražen a okraden. Dobrodružství pro tebe zde končí." << "\n\nGAME OVER" << endl;}
            }
      }
}
