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
                      if(Rozhodnuti2==1){ cout << "\nBěhem tvého rabování se objevili vesničani s jejich iron golemem, boj byl zbytečný, byl jsi zabit."<< "\n\nGAME OVER" <<endl;
                      }else{ cout << "\nMoudré rozhodnutí, protože se během chvilky objevili vesničani s jejich iron golemem, naštěstí byli přátelští a moohl jsi pokračovat dál ve své cestě"; 
                      cout << "\n Chceš ve vesnici zůstat a pomoci místním? [A=1/N=0]";
                      cin >> Rozhodnuti5;}
                            if(Rozhodnuti5==1){
                            cout << "\nRozhodl ses zůstat ve vesnici a pomoci místním."<< "\nMístní tě přijali mezi sebe a nabídli ti přístřeší a zásoby na cestu." << "\nPo několika dnech odpočinku se rozhodneš pokračovat dál na svou cestu.";
                            cout << "\nNa okraji vesnice potkáš kupce, který ti nabízí zdarma lepší zbraň. Přijmeš jeho nabídku? [A=1/N=0]";
                            
                              }else{
                                    int Rozhodnuti6;
                                    cin >> Rozhodnuti6;
                                    if (Rozhodnuti6 == 1) {
                                    cout << "\nPřijal jsi vylepšenou zbraň! Tvá útočná síla se zvýšila.";
                                    Damage += 20;
                                    } else {
                                    cout << "\nRozhodl ses ponechat svou původní výbavu a pokračovat bez nové zbraně.";
                                    }
                                    }
                                        cout << "\nPo opuštění vesnice se vydáváš do hustého lesa.";
                                        cout << "\nCesta je klidná, dokud tě nenapadne bandita!";
                                        boj(Zivoty, Damage);
                                            cout << "\nPo vítězství nad banditou nacházíš starou mapu ukazující skrytý poklad v horách.";
                                            cout << "\nVydáváš se tedy na nebezpečnou cestu do hor...";

                                            cout << "\nPo několika dnech narazíš na jeskyni ukrytou mezi skalami.";
                                            cout << "\nU vchodu do jeskyně stojí tajemný rytíř. Varuje tě, že poklad je prokletý a strážený drakem.";
                                            
                                            cout << "\nBez možnosti úniku vstupuješ do jeskyně. Z temnoty se vynoří drak!";
                                            cout << "\nJe to obrovské monstrum s 200 životy a útočí za 35.";

                                            int drakZivoty = 200;
                                            int drakDamage = 35;

                                                while (Zivoty > 0 && drakZivoty > 0) {
                                                    cout << "\nÚtočíš na draka!";
                                                    drakZivoty -= Damage;
                                                    cout << "\nZpůsobil jsi " << Damage << " poškození. Drakovi zbývá " << (drakZivoty > 0 ? drakZivoty : 0) << " HP.";
                                                
                                                    if (drakZivoty <= 0) {
                                                        cout << "\n\nZasazuješ poslední ránu! Drak padá k zemi a před tebou se otevírá poklad!";
                                                        cout << "\nNacházíš magické artefakty, zlato a legendární zbraň.";
                                                        Damage += 50;
                                                        cout << "\nStáváš se hrdinou známým po celém světě!";
                                                        cout << "\nAle stále na tebe čeká další bobrodružství";
                                                        //-----------------------------------------------------------------------------
                                                    }
                                                
                                                    cout << "\nDrak útočí!";
                                                    Zivoty -= drakDamage;
                                                    cout << "\nUtrpěl jsi " << drakDamage << " poškození. Zbývá ti " << (Zivoty > 0 ? Zivoty : 0) << " HP.";
                                                
                                                    if (Zivoty <= 0) {
                                                        cout << "\n\nDrak tě spálil na popel... Poklad zůstává nedotčen." << "\n\nGAME OVER" << endl;
                                                        exit(0);
                                                    }
                                                }
                                
    } else {
    cout << "\nRozhodl ses pokračovat dál na vlastní pěst.";
    cout << "\nPo pár hodinách chůze tě v lese napadne bandita!";
    boj(Zivoty, Damage);

    cout << "\nPo vítězství nad banditou se ti podaří najít cestu ven z lesa.";
    cout << "\nDobrodružství však stále pokračuje...\n";
       }
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
