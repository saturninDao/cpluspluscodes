#include <QApplication>
#include <QThread>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
 
using namespace std;
string line,linePrime;
ifstream inFile,primeFile;
// unsigned long long int tabNombresADecomposer[6];
unsigned long long int tabNombresADecomposer[6];
unsigned long long int tabNombresPremiers[6542];


class MyThreadDecomposition: public QThread {
    private: string line;
    private: std::ifstream& inFile;
    void run() {
        if (inFile.is_open())
        {
            for (int i = 0; i < 6; i++)
            {
                inFile >> tabNombresADecomposer[i];
                //cout << tabNombresADecomposer[i] << " ";
            }
            inFile.close(); // CLose input file
        }
        else { //Error message
            cerr << "Fichier introuvable "<< endl;
        }
    }
    public:
        MyThreadDecomposition(std::ifstream& inFile, string line) : QThread(), inFile(inFile), line(line) {};
};

class MyThreadPremiers: public QThread {
    private: string linePrime;
    private: std::ifstream& primeFile;
    void run() {
        if (primeFile.is_open())
        {
            for (int i = 0; i < 6542; i++)
            {
                primeFile >> tabNombresPremiers[i];
                //cout << tabNombresADecomposer[i] << " ";
            }
            primeFile.close(); // CLose input file
        }
        else { //Error message
            cerr << "Fichier introuvable "<< endl;
        }
    }
    public:
        MyThreadPremiers(std::ifstream& primeFile, string linePrime) : QThread(), primeFile(primeFile), linePrime(linePrime) {};
};

void decomposition(unsigned long long int number, unsigned long long int tabPremiers[6542]) {
/*for(int i=2; i <= number/i; i++){*/
    // cout << tabPremiers[i] << "\n";

   cout << number << ": ";
   for(int i=0;i<6542;i++){
      if(tabPremiers[i]<number){
           
            while(number%tabPremiers[i] == 0) 
            {
                number = number/tabPremiers[i];
                cout << "" << tabPremiers[i] << " ";
            }
            //cout<<"i= "<< tabPremiers[i] <<" number= " << number <<endl;
      }
   }

/*}*/
  
 if(number > 1) {
 cout << "" << number << " ";
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
    
    MyThreadDecomposition threadDecomp(inFile,line);
    MyThreadPremiers threadPremiers(primeFile,linePrime);
    threadDecomp.start();
    threadDecomp.wait();
    threadPremiers.start();
    threadPremiers.wait();
    
    for (int i = 0; i < 6; i++)
    {
        decomposition(tabNombresADecomposer[i],tabNombresPremiers);
        cout << "\n\n";
    }

    // for (int i = 0; i < 6542; i++)
    // {
    //     cout << tabNombresPremiers[i] << "\n";
    // }

    // Faison notre traitement

    // decomposition(7);

  




}

int main(int argc, char** argv){
    prime_factors(argc,argv);
}