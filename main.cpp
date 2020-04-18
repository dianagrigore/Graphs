#include <iostream>
#include "Vector.h"
#include "MatriceAdiacenta.h"
#include "Lista.h"
#include "Graf.h"
#include "Graf_Orientat.h"
#include "Graf_Neorientat.h"
#include <fstream>

int main() {
    std :: ifstream f("graf.in");
    int nr_neorientate, nod_start, nr_orientate, m;
    f >> nr_orientate >> nr_neorientate;
    Graf_Orientat* grafuriorientate;
    grafuriorientate = new Graf_Orientat[nr_orientate];
    for (int i = 0; i < nr_orientate; i++){
        f >> nod_start;
        f >> grafuriorientate[i];
        try {
                m = grafuriorientate[i].isgraf();
                throw m;
        }
        catch(int m)
        {   if (m == 0)
                std :: cout << "Matrice de adiacenta invalida ";
            else
                grafuriorientate[i].f(nod_start);
        }

    }
    Graf_Neorientat* grafurineorientate;
    grafurineorientate = new Graf_Neorientat[nr_neorientate];
    for (int i = 0; i < nr_neorientate; i++){
        f >> nod_start;
        f >> grafurineorientate[i];
        grafurineorientate[i].f(nod_start);
    }
    delete [] grafurineorientate;
    delete  [] grafuriorientate;
    f.close();

    return 0;
}
