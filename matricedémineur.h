#ifndef MATRICEDéMINEUR_H
#define MATRICEDéMINEUR_H
#include<iostream>
using namespace std;


class matricedémineur
{
    char**mat;
    int colonne;
    int ligne;
    public:
        matricedémineur(int l , int c):ligne(l),colonne(c),mat(0)
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
        matricedémineur(const matricedémineur& obj)
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

        virtual ~matricedémineur()
        {
            delete [][] mat;
        };


};

#endif // MATRICEDéMINEUR_H
