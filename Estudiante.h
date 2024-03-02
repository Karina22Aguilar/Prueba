#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED
#include<string.h>
class Estudiante {
  private:
    int codEst;
    string nombre;
    string apellido;
    public:
        Estudiante(){
            this->codEst=0;
        }
        void setCodEst(int c){
            this->codEst=c;
        }
        int getcodEst(){
           return this->codEst;

        }
        void setnombre(string n){
            this->nombre=n;
        }
        string getnombre(){
            return this->nombre;
        }
        void setapellido(string a){
             this->apellido=a;
        }
        string getapellido(){
            return this->apellido;
        }


};





#endif // ESTUDIANTE_H_INCLUDED
