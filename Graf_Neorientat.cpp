//
// Created by Diana Grigore on 14-Apr-20.
//

#include <ostream>
#include <iostream>
#include "Graf_Neorientat.h"
#include "Lista.h"

Graf_Neorientat :: Graf_Neorientat(int nr, Lista lista) : Graf{nr}, L{lista} {
}

void Graf_Neorientat :: citeste(std::istream &in) {
    in >> nr_noduri;
    in >> L;
}
std :: ostream& operator <<(std :: ostream& out, Graf_Neorientat const &src){
    out << src.nr_noduri <<'\n';
    out << src.L <<'\n';
    return out;
}

void swap(Graf_Neorientat &first, Graf_Neorientat &second){
    using std :: swap;
    swap(first.nr_noduri, second.nr_noduri);
    swap(first.L, second.L);
}

Graf_Neorientat :: Graf_Neorientat(const Graf_Neorientat& src) : Graf{src}, L{src.L} {
}

Graf_Neorientat &Graf_Neorientat ::operator=(Graf_Neorientat src){
    if (this != &src) {
        swap(src, *this);
    }
    return *this;
}

void Graf_Neorientat :: afisare_rezultat(int nod_start){
    int *tata = new int[nr_noduri];
    int poz = nod_start-1;
    for (int i = 0; i < nr_noduri; i++)
        tata[i] = 0;
    tata[nod_start - 1] = -1;
    int dimensiune_lista = L.getdimensiune();
    for (int i = poz; i < dimensiune_lista; i++){
        int dimensiune_locala = L[i].getdimensiune();
        for (int j = 0; j < dimensiune_locala; j++)
            if(tata[L[i][j] - 1] == 0)
                tata[L[i][j] - 1] = i + 1;
    }

    for (int i = 0; i < dimensiune_lista; i++)
        if (tata[i] == -1)
            std :: cout << "Elementul " << i + 1 << " este radacina.\n";
        else
            std :: cout << "Tatal elementului " << i + 1 << " este " << tata[i] << '\n';

    delete [] tata;
}



