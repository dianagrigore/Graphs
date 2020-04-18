//
// Created by Diana Grigore on 10-Apr-20.
//

#include "Graf.h"
#include <iostream>

Graf :: Graf(int nr_noduri) : nr_noduri {nr_noduri}{
}

Graf :: ~Graf(){
    nr_noduri = 0;
}

Graf :: Graf(const Graf &graf){
    nr_noduri = graf.nr_noduri;
}

void swap(Graf &first, Graf &second) {
    using std :: swap;
    swap(first.nr_noduri, second.nr_noduri);
}

void Graf :: f(int ns){
    std :: cout << ns << '\n';
}