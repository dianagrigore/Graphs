//
// Created by Diana Grigore on 10-Apr-20.
//

#include "Graf.h"
#include <iostream>

Graf :: Graf(int nr_noduri) : nr_noduri {nr_noduri}{
}

Graf :: ~Graf() = default;

std :: istream& operator >>(std :: istream& in, Graf &src){
    src.citeste(in);
    return in;
}

void  Graf :: afisare_rezultat(int nod_start){
    std :: cout << nr_noduri << '\n' << nod_start;
}

void Graf :: citeste(std::istream &in) {
    in >> nr_noduri;
}