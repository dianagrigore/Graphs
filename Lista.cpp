//
// Created by Diana Grigore on 07-Apr-20.
//

#include "Lista.h"
#include "Vector.h"
#include <iostream>
Lista :: Lista(int dimensiune) : dimensiune{dimensiune}{
    l = new Vector [dimensiune];
    Vector val(1,1);
    for (int i = 0; i < dimensiune; i++)
        l[i] = val;
}

std :: istream& operator >>(std :: istream& in, Lista &lis){
    delete []lis.l;
    in >> lis.dimensiune;
    lis.l = new Vector[lis.dimensiune];
    for (int i = 0; i < lis.dimensiune; i++)
        in >> lis.l[i];
    return in;
}

std :: ostream& operator <<(std :: ostream& out, const Lista& lis){
    for (int i = 0; i < lis.dimensiune; i++)
        out << lis.l[i] <<'\n';
    return out;
}

Lista :: ~Lista(){
    dimensiune = 0;
    delete [] l;
}

void swap(Lista &first, Lista &second){
    using std :: swap;
    swap(first.dimensiune, second.dimensiune);
    swap(first.l, second.l);
}

Lista :: Lista(const Lista& lis){
    dimensiune = lis.dimensiune;
    l = new Vector [dimensiune];
    for (int i = 0; i<dimensiune; i++)
        l[i] = lis.l[i];
}

Lista &Lista :: operator =(Lista src){
    if (this != &src)
        swap(*this, src);
    return *this;
}

int Lista :: getdimensiune() const {
    return dimensiune;
}

Vector* Lista :: getvector() const {
    return l;
}