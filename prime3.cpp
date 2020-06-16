#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
 
using namespace std;
    string line,linePrime;
    ifstream inFile;
    ifstream primeFile;

void genPrimes(int argc,char** argv){
    //Initialisations
    long int nombreCalcule=0;
    // On verifie que l'utilisateur a rentré le nombre n
    if(argc<2){
        cout << "Entrez un nombre n bits \n\n";
    }
    nombreCalcule = pow(2,atoi(argv[1]));
    bool tousLesNombres[nombreCalcule]; // Notre tableau de nombres
    tousLesNombres[0] = true; // 0 n'est pas premier
    tousLesNombres[1] = true; // 1 n'est pas premier

    for (long int i=2; i<nombreCalcule; i++)
    tousLesNombres[i] = false;

    for (long int i=2; i<nombreCalcule; i++)
    if (!tousLesNombres[i]) {
        int multiple = 2 * i;
        while (multiple < nombreCalcule) {
          tousLesNombres[multiple] = true;
          multiple += i;
        }
    }
    ofstream file("hello.txt");
    for (long int i=0; i<nombreCalcule; i++)
    if (!tousLesNombres[i])
        file << i << endl;
}


    void tache(){
                   
            while (getline(inFile, line) )
        {
            cout << line << endl;
                while (getline(primeFile, linePrime))
                {
                    cout << linePrime << endl;
                    tache();
                }
                //tache();
        }
    }

void prime_factors(int argc,char** argv){

    primeFile.open("hello.txt");
    long int nombre;
    long int primeNombre;
    // On verifie que l'utilisateur a rentré un nom de fichier
    if(argc<2){
        cout << "Entrez un nom de fichier contenant vos nombres a decomposer \n\n";
    }
        
    inFile.open(argv[1]);
    if(!inFile){
        cout << "Probleme lors de l'ouverture du fichier\n\n";
        exit(1);
    }

    tache();

}

int main(int argc, char** argv){

// genPrimes(argc,argv);
prime_factors(argc,argv);
    
}