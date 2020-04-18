//
// Created by Diana Grigore on 10-Apr-20.
//

#ifndef TEMA2_GRAF_H
#define TEMA2_GRAF_H
#include <istream>
#include <ostream>

class Graf {
protected:
    int nr_noduri;
public:
    explicit Graf(int nr_noduri=1);

    virtual ~Graf();

    virtual void f(int ns)=0;

    Graf(const Graf& graf);

    friend void swap(Graf &first, Graf &second);

};

#endif //TEMA2_GRAF_H
