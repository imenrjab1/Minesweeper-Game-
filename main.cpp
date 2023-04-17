#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

int main()
{

    int choix ;
    cout<<"Bienvenue au Jeu Démineur !\n"<<endl;
    cout<<"Si vous voulez consulter la liste des meilleurs scores tapez 1 et si vous voulez commencez une nouvelle partie tapez 2"<<endl;
    cin>>choix ;
    if (choix==1)
    {
        /*consulter la liste des meilleurs scores */
       ifstream fichier("score.txt", ios::in);  // on ouvre le ficher

       if(fichier)
        {
                string ligne;
                while(getline(fichier, ligne))  // tant que l'on peut mettre la ligne dans "contenu"
                {
                cout << ligne << endl;  // on l'affiche
                }
                fichier.close();
        }
        else
                cerr << "Impossible d'ouvrir le fichier !" << endl;



    }
    else if (choix==2)
    {
        /*choix de la matrice et le nombre de mines selon le joueur */

        int compteurmines;
        int compteurcoups=0;
        int l,c;
        srand(time(0));
        int score=0;
        char nom;

        cout<<"Veuillez saisir le nombre de mines :"<<endl;
        cin>>compteurmines;
        cout<<"Veuillez saisir la taille de la matrice :\n"<<endl;
        cout<<"Nombre de ligne"<<endl;
        cin>>l;
        cout<<"Nombre de colonnes"<<endl;
        cin>>c;
        cout<<"allez au jeu " <<endl;

        /*le jeu commence*/
        matricedémineur A(l,c);

        /*affichage de la matrice dont toutes les cases sont couvertes*/
        cout <<"Nombre de mines="<<compteurmines<<endl;
        cout<<"Nombre de coups="<<compteurcoups<<endl;
        cout<<"**********************************************"<<endl;
        for(int i=0 ; i<l ; i++) {
            cout << "  | \t" <<i<<endl;
        }
         for(int j=0 ; j<c ; j++) {
            cout <<j<<" | \n"<<endl;
        }
         A(l,c).afficher();
        cout<<"**********************************************"<<endl;

        /*initialisation de la matrice de jeu*/
        /*j'ai utilisé deux matrices A de classe matricedémineur pour l'affichage au début de jeu dont toutes les cases sont couvertes
         et une autre matrice B sur laquelle le joueur va jouer implicitement et decouvrir une case */

         matrice_a_jouer B(l,c);

        /*remplir la matrice avec les mines selon le nombre demandé par l'utilisateur*/
        /*cette matrice B est initialement rempli par des X qui indique un blanc je veux choisir des cases aleatoirement et remplacer les x par m */

       while (compteurmines>0)
       {
           i=rand()%l;//on choisit la ligne de manière aléatoire
           j=rand()%c;//on choisit la colonne de manière aléatoire
           if (B.getval(i,j)!="M")
           {
               B.getval(i,j)="M";
               compteurmines --;
           }
       }
       /*comptabiliser pour chaque position le nombre de mines voisines */
       for(int y=0; y<l;y++)
       {
           for(int x=0;x<c;x++)
           {
                int z=0
                if(B.getval(y,x)=="M")
                {
                    if (x-1>=0)//controler l'existance de la position x et de meme pour y
                    {
                        if (B.getval(y,x-1)!="M" {//voir si il ya une mine à la position voisine
                            z++;
                            B.getval(y,x-1)="z";}//si oui on ajoute à la place de X la variable Z qui indique le nombre de mines voisines
                        if (y-1>=0){
                            if (B.getval(y-1,x-1)!="M"){
                                 z++;
                                B.getval(y-1,x-1)="z";}}
                        if (y+1<l){
                            if(B.getval(y+1,x-1)!="M"){
                                z++;
                                B.getval(y+1,x-1)="z";}
                        }
                    }

                    if (x+1<c)
                    {
                        if (B.getval(y,x+1)!="M" {
                            z++;
                            B.getval(y,x+1)="z";}
                        if (y-1>=0){
                            if (B.getval(y-1,x+1)!="M"){
                                 z++;
                                B.getval(y-1,x+1)="z";}}
                        if (y+1<l){
                            if(B.getval(y+1,x+1)!="M"){
                                z++;
                                B.getval(y+1,x+1)="z";}
                        }
                  }
                  if (y-1>=0){
                    if(B.getval(y-1,x)!="M"){
                        z++;
                        B.getval(y-1,x)="z";
                    }
                  }
                  if (y+1<l){
                    if(B.getval(y+1,x)!="M"){
                        z++;
                        B.getval(y+1,x)="z";
                    }
                  }



           }
       }
       }
        while (score<=(B.taille_matrice()-compteurmines))
        {
            /*demander au joueur de choisir une case*/
            cout<<"Découvrez une case de votre choix en précisant respectivement son numéro de ligne et son numéro de colonne"<<endl;
            cin>>a;
            cin>>b;
            /*afficher le contenu de la case */
            B.afficher_case(a,b);

            /*Verifier la case choisie par le joueur */
            if (B.getval(a,b)=="M"){
                 cout <<"vous avez perdu!"<<endl;
                 /*fin du jeu et affichage de tous les mines */
                 int x,y;
                 for(int y=0;y<l;y++){
                    for (int x=0;x<c;x++){
                        if (B.getval(y,x)=="M")
                            B.afficher_case(y,x);
                    }
                 }

                 break ;}
            else if (B.getval(a,b)=="z"){ //la case contient un chiffre
                compteurcoups+=1;
                score+=compteurscoups;
                break ;}
            else if (B.getval(a,b)=="X") //la case contient un blanc
            {
                 compteurcoup+=1;
                 if (B.getval(a,b-1)!="D"){
                       B.afficher_case(a,b-1);}
                       compteurcoup+=1;

                 if (B.getval(a-1,b-1)!="D"){
                      B.afficher_case(a-1,b-1);
                      compteurcoup+=1;}

                 if (B.getval(a+1,b-1)!="D") {
                      B.afficher_case(a+1,b-1);
                      compteurcoup+=1;}

                 if (B.getval(a,b+1)!="D"){
                      B.afficher_case(a,b+1);
                      compteurcoup+=1;}

                 if (B.getval(a-1,b+1)!="D"){
                      B.afficher_case(a-1,b+1);
                      compteurcoup+=1;}

                 if (B.getval(a-1,b)!="D"){
                      B.afficher_case(a-1,b);
                      compteurcoup+=1;}

                 if (B.getval(a+1,b)!="D"){
                      B.afficher_case(a+1,b);
                      compteurcoup+=1;}

                 if (B.getval(a+1,b+1)!="D"){
                     B.afficher_case(a+1,b+1);
                     compteurcoup+=1;}

                 score+=compteurscoups;
                 break;
            }

        }
        if (score==(B.taille_matrice()-compteurmines))
        {
            cout<<"bravo vous avez gagné!!!"<<endl;
            cout<<"prière de donner votre nom "<<endl;
            cin>>nom;
            ofstream fichier("score.txt", ios::out | ios::app);  // ouverture du fichier en écriture pour ajouter le nom et le score
                if(fichier)
                {
                   fichier<<"nom:"<<nom<<"score="<<score<<endl;
                   }

                   fichier.close();
                else
                   cerr << "Impossible d'ouvrir le fichier !" << endl;


        }
    }
    else
        cout<<"votre choix est invalide"<<endl;


}
