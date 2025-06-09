#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <thread>
#include <chrono>
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
            jmenoBandity = "Vrah";
            banditaZivoty = 60;
            banditaDamage = 20;
            break;
        case 2:
            jmenoBandity = "Velitel";
            banditaZivoty = 80;
            banditaDamage = 30;
            break;
    }

    cout << "\nPřišel " << jmenoBandity << " (HP: " << banditaZivoty << ", Damage: " << banditaDamage << ")\n";

    bool hracNaTahu = true;
    while (Zivoty > 0 && banditaZivoty > 0) {
        if (hracNaTahu) {
            cout << "Útočíš na " << jmenoBandity << " za " << Damage << " poškození.\n";
            banditaZivoty -= Damage;
            if (banditaZivoty <= 0) {
                cout << jmenoBandity << " padl.\n";
                break;
            }
        } else {
            cout << jmenoBandity << " útočí za " << banditaDamage << ".\n";
            Zivoty -= banditaDamage;
            if (Zivoty <= 0) {
                cout << "Zemřel jsi. GAME OVER\n";
                exit(0);
            }
        }
        hracNaTahu = !hracNaTahu;
    }

    cout << "Vyhrál jsi souboj!\n";
}

void vyberPostavu(int &Zivoty, int &Damage) {
    int Postava;
    cout << "Vyber si postavu:\n1 - Válečník (Životy 100, Damage 80)\n2 - Zloděj (Životy 70, Damage 120)\n3 - Lovec (Životy 85, Damage 100)\nTvoje volba: ";
    cin >> Postava;

    switch(Postava) {
        case 1: Zivoty=100; Damage=80; break;
        case 2: Zivoty=70; Damage=120; break;
        case 3: Zivoty=85; Damage=100; break;
        default:
            cout << "Špatná volba, budeš Lovec.\n";
            Zivoty=85; Damage=100;
    }
}

void vesnice1(int &Zivoty, int &Damage, int &zlato) {
    cout << "\nPrvní vesnice, máš " << zlato << " zlata. Můžeš doplnit životy (20 zlata), nebo zvýšit Damage (50 zlata).\n";
    int volbaVesnice;
    do {
        cout << "1 - doplnit životy o 30, 2 - zvýšit damage o 5, 0 - odejít: ";
        cin >> volbaVesnice;
        if (volbaVesnice == 1) {
            if (zlato >= 20) {
                Zivoty += 30;
                zlato -= 20;
                cout << "Doplnil jsi životy, máš nyní " << Zivoty << " HP.\n";
            } else cout << "Nemáš dost zlata.\n";
        } else if (volbaVesnice == 2) {
            if (zlato >= 50) {
                Damage += 5;
                zlato -= 50;
                cout << "Zvýšil jsi Damage na " << Damage << ".\n";
            } else cout << "Nemáš dost zlata.\n";
        }
    } while (volbaVesnice != 0);
}

void vesnice2(int &Zivoty, int &zlato) {
    cout << "\nDorazil jsi do vesnice, kde můžeš doplnit životy za 20 zlata.\n";
    cout << "Doplnit životy? (1 - ano, 0 - ne): ";
    int volba2; cin >> volba2;
    if(volba2 == 1) {
        if(zlato >= 20) {
            Zivoty += 40;
            zlato -= 20;
            cout << "Doplnil jsi životy, máš " << Zivoty << " HP.\n";
        } else cout << "Nemáš dost zlata.\n";
    }
}

void bojVicMonstru(int &Zivoty, int Damage, int pocetMonstru) {
    string jmena[] = {"Goblin", "Skelet", "Ork", "Pavoučí démon", "Nemrtvý voják", "Bandita"};
    int hpMonstra[3];
    int damageMonstra[3];
    string jmenaMonstra[3];

    for(int i=0; i<pocetMonstru; i++) {
        int idx = rand() % 6;
        jmenaMonstra[i] = jmena[idx];
        hpMonstra[i] = 40 + rand() % 40;
        damageMonstra[i] = 10 + rand() % 20;
        cout << "Přišel " << jmenaMonstra[i] << " (HP: " << hpMonstra[i] << ", Damage: " << damageMonstra[i] << ")\n";
    }

    bool hracNaTahu = true;
    while(Zivoty > 0) {
        if(hracNaTahu) {
            bool utocil = false;
            for(int i=0; i<pocetMonstru; i++) {
                if(hpMonstra[i] > 0) {
                    cout << "Útočíš na " << jmenaMonstra[i] << " za " << Damage << " poškození.\n";
                    hpMonstra[i] -= Damage;
                    if(hpMonstra[i] <= 0) cout << jmenaMonstra[i] << " padl.\n";
                    utocil = true;
                    break;
                }
            }
            if(!utocil) break;
        } else {
            cout << "Monstra útočí!\n";
            for(int i=0; i<pocetMonstru; i++) {
                if(hpMonstra[i] > 0) {
                    cout << jmenaMonstra[i] << " útočí za " << damageMonstra[i] << ".\n";
                    Zivoty -= damageMonstra[i];
                    if(Zivoty <= 0) {
                        cout << "Zemřel jsi. GAME OVER\n";
                        exit(0);
                    }
                }
            }
        }
        hracNaTahu = !hracNaTahu;
    }
    cout << "Vyhrál jsi nad všemi monstry!\n";
}

void soubojKlonem(int &Zivoty, int &Damage, const string& Jmeno) {
    cout << "\nVstupuje do arény tvůj temný dvojník!\n";
    int klonHP = Zivoty + 30;
    int klonDamage = (Damage > 10) ? Damage - 10 : 5;

    cout << "Temný " << Jmeno << " má " << klonHP << " HP a útočí za " << klonDamage << ".\n";

    while(Zivoty > 0 && klonHP > 0) {
        cout << "\nÚtočíš na klona za " << Damage << " poškození.\n";
        klonHP -= Damage;
        if(klonHP <= 0) {
            cout << "\nPorazil jsi svého temného dvojníka!\n";
            Zivoty += 30;
            Damage += 30;
            cout << "Získáváš 30 HP a 30 Damage navíc! Nyní máš " << Zivoty << " HP a " << Damage << " Damage.\n";
            return;
        }
        cout << "Temný dvojník útočí za " << klonDamage << " poškození.\n";
        Zivoty -= klonDamage;
        if(Zivoty <= 0) {
            cout << "Tvůj temný dvojník tě porazil... GAME OVER\n";
            exit(0);
        }
        cout << "Zbývá ti " << Zivoty << " HP.\n";
    }
}

void soubojeMiniBosse(int &Zivoty, int Damage, int &zlato, const string& Jmeno) {
    struct Boss {
        string jmeno;
        int hp;
        int dmg;
    };

    Boss miniBosse[] = {
        {"Drak", 200, 35},
        {"Temný klon", 0, 0}
    };

    // Souboj s Drakem
    cout << "\nMini-boss #1 - " << miniBosse[0].jmeno << "\n";
    int bossHP = miniBosse[0].hp;
    int bossDamage = miniBosse[0].dmg;
    while(Zivoty > 0 && bossHP > 0) {
        cout << "\nÚtočíš na " << miniBosse[0].jmeno << " za " << Damage << " poškození.\n";
        bossHP -= Damage;
        if(bossHP <= 0) break;
        cout << miniBosse[0].jmeno << " útočí za " << bossDamage << " poškození.\n";
        Zivoty -= bossDamage;
        if(Zivoty <= 0) {
            cout << "Zemřel jsi. GAME OVER\n";
            exit(0);
        }
    }
    cout << "Porazil jsi " << miniBosse[0].jmeno << "! Získáváš 100 zlata.\n";
    zlato += 100;

    // Souboj s klonem
    soubojKlonem(Zivoty, Damage, Jmeno);

    cout << "Získáváš 100 zlata za poražení temného klona!\n";
    zlato += 100;
}

void bossSilentchant(int &Zivoty, int &Damage) {
    int hp = 300;
    int kolo = 0;
    int pocetSchopnosti = 0;
    const int maxKolNasavani = 5;

    cout << "Silentchant má " << hp << " HP.\n";

    while(hp > 0 && Zivoty > 0) {
        kolo++;
        cout << "\nKolo " << kolo << " - Silentchant nasává energii.\n";

        cout << "Vyber akci:\n1 - Útok\n2 - Použít schopnost\nTvůj výběr: ";
        int volba;
        cin >> volba;

        if(volba == 1) {
            cout << "Útočíš za " << Damage << " poškození.\n";
            hp -= Damage;
        } else if(volba == 2) {
            cout << "Používáš schopnost a způsobuješ 50 poškození.\n";
            hp -= 50;
            pocetSchopnosti++;
        } else {
            cout << "Nic neděláš.\n";
        }

        if(hp <= 0) {
            cout << "Porazil jsi Silentchanta!\n";
            break;
        }

        if(kolo == maxKolNasavani) {
            int dmgVybuchu = 10 * maxKolNasavani;
            if(pocetSchopnosti >= 3) {
                dmgVybuchu = dmgVybuchu * 3 / 2;
                cout << "Silentchant vybíjí posílený tichý výbuch!\n";
            } else {
                cout << "Silentchant vybíjí tichý výbuch!\n";
            }
            Zivoty -= dmgVybuchu;
            cout << "Dostal jsi " << dmgVybuchu << " poškození, zbývá ti " << (Zivoty > 0 ? Zivoty : 0) << " HP.\n";
            if(Zivoty <= 0) {
                cout << "Zemřel jsi na výbuch Silentchanta. GAME OVER\n";
                exit(0);
            }
            kolo = 0;
            pocetSchopnosti = 0;
        }
    }
}

int main() {
    srand(time(0));

    string Jmeno;
    int Zivoty = 0, Damage = 0;
    int zlato = 0;

    cout << "Jak se jmenuješ? ";
    cin >> Jmeno;

    vyberPostavu(Zivoty, Damage);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    boj(Zivoty, Damage);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    vesnice1(Zivoty, Damage, zlato);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 1);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 1);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 2);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    soubojeMiniBosse(Zivoty, Damage, zlato, Jmeno);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    vesnice2(Zivoty, zlato);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 1);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 2);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 2);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    vesnice1(Zivoty, Damage, zlato);
    boj(Zivoty, Damage);
    soubojeMiniBosse(Zivoty, Damage, zlato, Jmeno);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    vesnice2(Zivoty, zlato);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 2);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 2);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bojVicMonstru(Zivoty, Damage, 3);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    vesnice2(Zivoty, zlato);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    boj(Zivoty, Damage);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    vesnice1(Zivoty, Damage, zlato);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    bossSilentchant(Zivoty, Damage);
    std::this_thread::sleep_for(std::chrono::seconds(3));
    cout << "\nGratulace, dokončil jsi hru!\n";
    return 0;
}
