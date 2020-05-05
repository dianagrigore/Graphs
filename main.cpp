#include <iostream>
#include <fstream>
#include "Vector.h"
#include "MatriceAdiacenta.h"
#include "Lista.h"
#include "Graf.h"
#include "Graf_Orientat.h"
#include "Graf_Neorientat.h"



void testeaza_graf(Graf& graf, std :: istream& f){
    int nod_start;
    f >> nod_start;
    f >> graf;
    graf.afisare_rezultat(nod_start);
}

int main() {
    std :: ifstream f("graf.in");
    Graf_Orientat go;
    Graf_Neorientat gn;
    testeaza_graf(go, f);
    testeaza_graf(gn, f);
    f.close();
    return 0;
}
