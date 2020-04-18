//
// Created by Diana Grigore on 05-Apr-20.
//

#ifndef TEMA2_VECTOR_H
#define TEMA2_VECTOR_H
#include<istream>
#include<ostream>

class Vector {
    int *v;
    int dim;

public:
    explicit Vector(int dim=1, int val=0);

    virtual ~Vector();

    Vector(const Vector& x);

    friend void swap(Vector &first, Vector &second);

    Vector& operator =(Vector src);

    friend std::ostream& operator <<(std::ostream &out, const Vector &vec);

    friend std::istream& operator >>(std::istream &in, Vector &vec);

    int getdimensiune() const;

    int* getelemente() const;
};


#endif //TEMA2_VECTOR_H
