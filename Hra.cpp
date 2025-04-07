#include <iostream>
#include <string>
using namespace std;

int main(){
string Jmeno;
int Rozhodnuti, Rozhodnuti2;
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
    }
}
