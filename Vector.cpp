//
// Created by Diana Grigore on 05-Apr-20.
//

#include "Vector.h"
Vector :: Vector(int dim, int val) : dim{dim} {
    v = new int [dim];
    for (int i = 0; i < dim ; i++)
        v[i] = val;
}

Vector :: ~Vector() {
    dim = 0;
    delete [] v;
}

Vector :: Vector(const Vector &x) {
    dim = x.dim;
    v = new int [dim];
    for (int i = 0; i < dim; i++)
        v[i] = x.v[i];
}

void swap(Vector &first, Vector &second) {
    using std :: swap;
    swap(first.dim, second.dim);
    swap(first.v, second.v);
}

std::istream &operator >>(std::istream &in, Vector &vec){
    delete [] vec.v;
    in >> vec.dim;
    vec.v = new int [vec.dim];
    for(int i = 0; i < vec.dim; i++)
        in >> vec.v[i];
    return in;
}

std::ostream &operator <<(std::ostream &out, const Vector &vec){
    for(int i = 0; i < vec.dim; i++)
        out << vec.v[i] << " ";
    out << '\n';
    return out;
}

Vector &Vector::operator=( Vector src) {
    if(this != &src)
        swap(*this, src);
    return *this;
}

int Vector :: getdimensiune() const {
    return dim;
}

int* Vector :: getelemente() const {
    return v;
}
