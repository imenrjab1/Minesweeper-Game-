#ifndef MATRICED�MINEUR_H
#define MATRICED�MINEUR_H
#include<iostream>
using namespace std;


class matriced�mineur
{
    char**mat;
    int colonne;
    int ligne;
    public:
        matriced�mineur(int l , int c):ligne(l),colonne(c),mat(0)
        {
           mat=new char*[ligne];
           for(int i=0;i<ligne;i++){
                mat[i]=new char[colonne];}//allocation de la matrice

           for (int m=0;m<ligne;m++){
              for(int n=0; n<colonnes; n++)
                    mat[m][n]="$"; //case couverte
           }

        }
        /*char operator [](int i)
        {
            return mat[i];
        }*/
        matriced�mineur(const matriced�mineur& obj)
        {     ligne=obj.ligne;
              colonne=obj.colonne;
              mat=new char*[ligne];
              for(int x=0;x<ligne;x++){
                  mat[x]=new char[colonne];}

              for(int i=0;i<ligne;i++){
                  for(int j=0;j<=colonne;j++)
                     mat[i][j] = obj.mat[i][j];}
            }
        void afficher() const
        {
              for(int m=0; m<ligne; m++)
           {
               for(int n=0; n<colonnes; n++)
               {
                    cout << mat[m][n] << endl;
                }
           }
        }

        virtual ~matriced�mineur()
        {
            delete [][] mat;
        };


};

#endif // MATRICED�MINEUR_H
