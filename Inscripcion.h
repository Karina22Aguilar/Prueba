#ifndef INSCRIPCION_H_INCLUDED
#define INSCRIPCION_H_INCLUDED
#include"Estudiante.h"
#include"Materia.h"
#include<string.h>
# define TAM 5
class Inscripcion{
   private:
      int codInscripcion;
      Estudiante est;
      string cicloAcademico;
      Materia *materiasInscritas[TAM];
      int contadorMaterias;
   public:
       Inscripcion (int c, Estudiante _est, string ca){
           this->codInscripcion=c;
           this->est=_est;
           this->cicloAcademico=ca;
           this->contadorMaterias=0;
       }
       int getCodInscripcion(){
            return this->codInscripcion;
       }
       Estudiante getEstudiante(){
            return this->est;
       }
       string getCicloAcademico(){
            return this->cicloAcademico;
       }
       void agregarMaterias(Materia *mat){
          if(this->contadorMaterias<TAM){
            this->materiasInscritas[this->contadorMaterias]= mat;
            this->contadorMaterias++;
          }
          else{
            cout<<"LA LISTA DE MATERIAS ESTA LLENA "<<endl;
          }
        }
        Materia **getLsMaterias(){
           return this->materiasInscritas;
        }
        int getContadorMaterias(){
            return this-> contadorMaterias;

        }

 };



#endif // INSCRIPCION_H_INCLUDED
