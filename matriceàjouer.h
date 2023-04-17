#ifndef MATRICE_A_JOUER_H
#define MATRICE_A_JOUER_H
#include <iostream>
using namespace std ;

class matrice_a_jouer
{
    char**tab;
    int colonne;
    int ligne ;
    public:
        matrice_a_jouer(int l , int c):ligne(l),colonne(c),tab(0){
            tab=new char*[ligne];
            for(int x=0;x<ligne;x++){
               tab[x]=new char[colonne];} //allocation de la matrice

            for(int i=0;i<ligne;i++){
               for(int j=0; j<colonne; j++)
                      tab[i][j]="X";//on initialise la matrice par des X qui indique un blanc
           }

        }
        char getval(int i ,int j) const
        {
            return tab[i][j];
        }
        void afficher_case(int i ,int j)const
        {
            cout<<tab[i][j]<<endl;
        }
        int taille_matrice()
        {
            return ligne*colonne ;
        }
        /*char  operator [](int i)
        {
            return tab[i];
        }*/
        matrice_à_jouer(const matrice_a_jouer& obj)
        {     ligne=obj.ligne;
              colonne=obj.colonne;
              tab=new char*[ligne]//[colonne];
              for (int x=0;x<ligne;x++){
                tab[x]=new char[colonne];}

              for (int i=0;i<ligne;i++){
                for(int j=0;j<=colonne;j++)
                    tab[i][j]= obj.tab[i][j];}
        }

        virtual ~matrice_a_jouer(){
            delete [][] tab;
        }


};

#endif // MATRICE_A_JOUER_H
