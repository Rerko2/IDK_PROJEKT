#include <iostream>
#include <string>
using namespace std;

int main(){
string Jmeno;
int Rozhodnuti;
cout << "výtej v této dobrodružné hře! ";
cout << "\nJaké je tvé jmáno dobrodruhu? ";
cin >> Jmeno;
cout << Jmeno << "\n\nZajmavé jméno, opravdu zajmavé. No tak se vydáme na toto dobrodružství";
cout << "\nDostali jsme se na křižovatku levý směr vede do lesa, pravý do malé vesničky" << "\nKam se vydáme? [P=1/L=2]";
cin >> Rozhodnuti;
if(Rozhodnuti==1){ cout << "\nZajmavé rozhodnutí, jdeme do vesničky";
                   cout << "\nVesnice vypadá opuštěně, chceš ji vyrabovat?;
  }else{ cout << "\nZajmavé rozhodnutí, jdeme do lesa";
    }
}
