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
    explicit Graf(int nr_noduri);

    virtual ~Graf() = 0;

    Graf(const Graf& graf) = default;

    Graf& operator= (Graf const &src) = default;

    virtual void citeste(std :: istream &in);

    friend std::istream& operator >>(std::istream &in, Graf &src);

    virtual void afisare_rezultat(int nod_start) = 0;

};

#endif //TEMA2_GRAF_H
