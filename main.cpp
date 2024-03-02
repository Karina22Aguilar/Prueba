#include <iostream>
using namespace std;
#include<stdlib.h>
#include"Estudiante.h"
#include"Materia.h"
#include"Inscripcion.h"
#define NA 5

int menu(){
    int op;
    cout <<"MENU DE OPCIONES "<< endl;
    cout <<"1. Agregar estudiante "<< endl;
    cout <<"2. Agregar materias "<< endl;
    cout <<"3. Hacer inscripcion "<< endl;
    cout <<"4. Lista de estudiantes "<< endl;
    cout <<"5. Lista de materias "<< endl;
    cout <<"6. Lista de inscripciones"<< endl;
    cout <<"7. Detalle de la inscripcion  "<< endl;
    cout <<"8. salir"<< endl;
    cout <<"DIGITE LA OPCION :";cin>>op;
    return op;
}
Estudiante buscarEstudiante(Estudiante lst[],int contEst, int codE){
     bool encontrado = false;
     int contador=0;
     Estudiante est;
     while(contador< contEst && !encontrado){
        if(lst[contador].getcodEst()==codE){
            encontrado = true;
            est=lst[contador];
        }
        else{
            contador ++;
        }
     }
      return est;
}
Estudiante agreagarEstudiante(Estudiante lst[],int cont){
     int cod;
     string n,a;
     cout <<"Digite el codigo de estudiante "; cin>>cod;
     Estudiante est= buscarEstudiante(lst,cont,cod);
     if(est.getcodEst()!=0){
        est.setCodEst(0);
     }
     else{
        cout <<"Digite el nombre del estudiante "<< endl;cin>>n;
        cout <<"Digite el apellido del estudiante "<< endl;cin>>a;
        est.setCodEst(cod);
        est.setnombre(n);
        est.setapellido(a);
     }
     return est;

}
Materia *agregarMaterias(){
    int cod;
    string n;
    Materia *mat;
    cout <<"Digite el codigo de la materia "<< endl;cin>>cod;
    cout <<"Digite el nombre de la materia "<< endl;cin>>n;
    mat= new Materia(cod,n);
    return mat;
}
void mostrarLstEstudiantes(Estudiante lst[],int cont){
if(cont==0){
    cout <<"La lista esta vacia "<< endl;
  }
  else{
    cout <<"Cod\t Nombre\t Apellido\n"<< endl;
    for(int i=0;i<cont;i++){
        cout<<lst[i].getcodEst()<<"\t";
        cout<<lst[i].getnombre()<<"\t";
        cout<<lst[i].getapellido()<<"\n";
   }
  }
}
void mostrarLstMaterias(Materia*lst[],int cont){
    if(cont==0){
    cout <<"La lista esta vacia "<< endl;
  }
  else{
    cout <<"Cod\tNombre de Materia "<< endl;
    for(int i=0;i<cont;i++){
        cout<<lst[i]->getCodMat()<<"\t";
        cout<<lst[i]->getNomMateria()<<endl;
   }
  }
}
void mostrarLstInscripciones(Inscripcion *lst[],int cont){
    if(cont==0){
    cout <<"La lista esta vacia "<< endl;
  }
  else{
    cout <<"Cod\tEstudiante\tCiclo\n"<< endl;
    for(int i=0;i<cont;i++){
        cout<<lst[i]->getCodInscripcion()<<"\n";
        cout<<lst[i]->getEstudiante().getnombre()<<" "<<lst[i]->getEstudiante().getapellido()<<"\t";
        cout<<lst[i]->getCicloAcademico()<<"\n";
   }
  }
}
Materia *buscarMaterias(Materia *lst[],int cont,int cod01){
   bool encontrado=false;
   int contador=0;
   Materia *mat= NULL;
   while (contador<cont && !encontrado){
    if(lst[contador]->getCodMat()==cod01){
       encontrado=true;
       mat=lst[contador];
    }
    else{
        contador ++;
   }
   return mat;
 }
}
Inscripcion *agregarInscripcion(Estudiante est, Materia *lstMat[],int contMat){
    int cod,codMat,resp;
    string ca;
    Inscripcion *ins;
    cout <<"Digite el codigo de la inscripcion "<< endl;cin>>cod;
    cout <<"Digite el ciclo academico"<< endl;cin>>ca;
    ins=new Inscripcion(cod,est,ca);
    do{
    cout <<"Digite el codigo de la materia a inscribir "<< endl;cin>>codMat;
    Materia *mat = buscarMaterias(lstMat,contMat,codMat);
    if(mat){
        /// se encontro
        ins->agregarMaterias(mat);
        cout <<"La materia se agrego con exito "<< endl;
      }
      else{
        cout <<"La materia no esta en la lista "<< endl;
      }
        cout <<"Desea agregar otra materia si=1, No=2"<< endl;cin>>resp;

   }while(resp==1);
   return ins;
}
Inscripcion *buscarInscripcion(Inscripcion *lst[],int cont, int codI){
   bool encontrado = false;
   int contador =0;
   Inscripcion *ins=NULL;
   while(contador <cont && !encontrado){
    if(lst[contador]->getCodInscripcion()==codI){
        encontrado = true;
        ins=lst[contador];
    }
    else{
        contador ++;
    }
  }
   return ins;
}

int main(){
    Estudiante lstEst[NA];
    int contEst=0;
    Materia *lstMat[NA];
    int contMat=0;
    Inscripcion *lstIns[NA];
    int contIns=0;
    int opc;
    do{
        system("cls");
        opc=menu();
        switch(opc){
    case 1:
        ///Agregar Estudiante
        if(contEst<NA){
            Estudiante est = agreagarEstudiante(lstEst,contEst);
            if (est.getcodEst()==0){
                cout <<"Erro el estudiante ya esta adicionado a la lista "<< endl;
            }
            else{
                lstEst[contIns]=est;
                contEst++;
                cout <<"El estudiante se agrego con exito "<< endl;
            }
          }
        else{
            cout <<"La lista de estudiantes esta llena "<< endl;
        }
        break;
        case 2:
            /// Agregar materias
                if(contMat<NA){
                    lstMat[contMat]=agregarMaterias();
                    contMat++;
                    cout <<"La materia se agrego con exito "<< endl;
                }
                else{
                    cout <<"La lista de estudiantes esta llena "<< endl;
                }
                break;
        case 3:
            ///Hacer inscripcion
            {
            int codE;
            cout <<"Digite el codigo del estudiante "<< endl;cin>>codE;
            Estudiante _est= buscarEstudiante(lstEst,contIns,codE);
            if(_est.getcodEst()==0){
                cout <<"El estudiante no esta en la lista "<< endl;

            }
            else{
                lstIns[contIns]=agregarInscripcion(_est,lstMat,contMat);
                contIns++;
                cout <<"La inscrippcion se realizo con exito "<< endl;
            }
        }
        break;
         case 4:
            ///Los estudiantes
            mostrarLstEstudiantes(lstEst,contEst);
            break;
        case 5:
            //Las materias
            mostrarLstMaterias(lstMat,contMat);
            break;
        case 6:
            // Las inscripciones
            mostrarLstInscripciones(lstIns,contIns);
            break;
        case 7:
            ///Detalles de la inscripcion
            {
                int codI;
                cout <<"Digite el codigo de la inscripcion "<< endl;cin>>codI;
                Inscripcion *ins=buscarInscripcion(lstIns,contIns,codI);
                if(ins){
                    /// encontrado
                    cout <<"Inscripcion: "<<ins->getCodInscripcion()<< endl;
                    cout <<"Estudiante: "<< ins->getEstudiante().getnombre()<<" "<<ins->getEstudiante().getapellido()<<endl;
                    cout <<"Ciclo adademico : "<<ins->getCicloAcademico()<<endl;
                    if(ins->getContadorMaterias()==0)
                        cout <<"No hay materias inscritas "<< endl;
                    else{
                        cout <<"Materias inscritas "<< endl;
                        cout <<"Cod\tNombre Materia\n"<< endl;
                        Materia **lstMat=ins->getLsMaterias();
                        for(int i=0;i<ins->getContadorMaterias();i++){
                                cout <<lstMat[i]->getCodMat()<<"\t";
                                cout <<lstMat[i]->getNomMateria()<<"\t";



                        }
                    }
                 }
                 else{
                    cout <<"La inscripcion no se encontro "<< endl;

                 }
            }
            break;
        case 8:
             cout <<"Abandonando el programa ..."<< endl;
             break;
        default:
            cout <<"Error la opcion no esta definida "<< endl;

          }
          system("pause");
    }while(opc!=8);
    cout <<""<< endl;
    return 0;
}
