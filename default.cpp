#include <iostream>
using namespace std;

int main(){
int a,b;
cout << "výtej v této dobrodružné hře! ";
cout << "\nJaké je tvé jmáno dobrodruhu? ";
cin >> a;
cout << "\n\nZajmavé jméno, opravdu zajmavé. No tak se vydáme na toto dobrodružství" << a << " ";
cout << "Dostali jsme se na křižovatku levý směr vede do lesa, pravý do malé vesničky" << "\nKam se vydáme? [P=1/L=2]";
cin >> b; 
if(b==1){ cout << "Zajmavé rozhodnutí, jdeme do vesničky";
  }else{ cout << "Zajmavé rozhodnutí, jdeme do lesa";
    }
}
