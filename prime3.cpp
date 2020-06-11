#include <bits/stdc++.h>
#include <iostream>
 
using namespace std;

void genPrimes(int argc,char** argv){
        //Initialisations
    int nombreCalcule=0;
    // On verifie que l'utilisateur a rentré le nombre n
    if(argc<2){
        cout << "Entrez un nombre n bits \n\n";
    }
    nombreCalcule = pow(2,atoi(argv[1]));
    bool tousLesNombres[nombreCalcule]; // Notre tableau de nombres
    tousLesNombres[0] = true; // 0 n'est pas premier
    tousLesNombres[1] = true; // 1 n'est pas premier

    for (int i=2; i<nombreCalcule; i++)
    tousLesNombres[i] = false;

    for (int i=2; i<nombreCalcule; i++)
    if (!tousLesNombres[i]) {
        int multiple = 2 * i;
        while (multiple < nombreCalcule) {
          tousLesNombres[multiple] = true;
          multiple += i;
        }
    }
    ofstream file("hello.txt");
    for (int i=0; i<nombreCalcule; i++)
    if (!tousLesNombres[i])
        file << i << endl;
}

int main(int argc, char** argv){

genPrimes(argc,argv);
    
}