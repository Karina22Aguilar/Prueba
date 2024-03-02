#ifndef MATERIA_H_INCLUDED
#define MATERIA_H_INCLUDED
#include<string.h>
class Materia{
    private:
        int codMat;
        string nomMateria;
    public:
        Materia(int c, string n){
            this->codMat=c;
            this->nomMateria=n;
        }
        int getCodMat(){
            return this->codMat;
        }
        string getNomMateria(){
                return this->nomMateria;
        }

};


#endif // MATERIA_H_INCLUDED
