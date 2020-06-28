#include <QApplication>
#include <QThread>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <array> 

#define NB 6

/*

3-/ TEMPS D'EXECUTION 
real	0m0,008s
user	0m0,004s
sys	    0m0,004s

real	0m0,009s
user	0m0,005s
sys	    0m0,004s

dexieme partie
real	0m0,008s
user	0m0,008s
sys	    0m0,000s

NB300
//parallele       
real	0m0,086s  
user	0m0,072s
sys	    0m0,018s

//serie
real	0m0,028s
user	0m0,024s
sys	0m0,004s

NB900
//SERIE
real	0m0,075s
user	0m0,067s
sys	    0m0,009s

//parallele
real	0m0,230s
user	0m0,154s
sys	    0m0,089s

NB1500
//Parallele
real	0m0,346s
user	0m0,187s
sys	    0m0,114s

//serie
real	0m0,121s
user	0m0,116s
sys	    0m0,004s

NB10
//serie
real	0m0,012s
user	0m0,012s
sys	    0m0,001s

//parallele
real	0m0,012s
user	0m0,012s
sys	    0m0,001s

NB6

//serie
real	0m0,006s
user	0m0,000s
sys	    0m0,006s

//par
real	0m0,868s
user	0m0,006s
sys	    0m0,006s


Explication:
Les threads sont executes de manieres consecutives l'un attend toujours la fin de l'autre pour commencer



















*/
 
using namespace std;
string line,linePrime;
ifstream inFile,primeFile;
// unsigned long long int tabNombresADecomposer[6];
// unsigned long long int tabNombresADecomposer[6];
array<unsigned long long int, NB> tabNombresADecomposer;
array<unsigned long long int, 6542> tabNombresPremiers;



class MyThreadDecomposition: public QThread {
    private: string line;
    private: std::ifstream& inFile;
    void run() {
        if (inFile.is_open())
        {

            if(tabNombresADecomposer.empty()){
                cout << "jes suis vide!";
            }
            
            for (int i = 0; i < NB; i++)
            {
                // inFile >> tabNombresADecomposer[i];
                inFile >> tabNombresADecomposer.at(i);
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
                primeFile >> tabNombresPremiers.at(i);
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


void decomposition(unsigned long long int number, array<unsigned long long int, 6542> tabPremiers) {


/*for(int i=2; i <= number/i; i++){*/
    // cout << tabPremiers[i] << "\n";

   cout << number << ": ";
   for(int i=0;i<6542;i++){
      if(tabPremiers.at(i)<number){
           
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

class DecompUnNombre: public QThread {
   private: int i; 
   private: array<unsigned long long int, NB> tabNombresADecomposer;
   private: array<unsigned long long int, 6542> tabNombresPremiers;

   public:
        DecompUnNombre(
            int i, 
            array<unsigned long long int, NB> tabNombresADecomposer, 
            array<unsigned long long int, 6542> tabNombresPremiers
            ) : QThread(), 
        i(i), 
        tabNombresADecomposer(tabNombresADecomposer),
        tabNombresPremiers(tabNombresPremiers) {};

    void run(){
        decomposition(tabNombresADecomposer.at(i),tabNombresPremiers);
        cout << "\n\n";
   }
};

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
    /*
    DecompDeuxNombres thread1(0,tabNombresADecomposer,tabNombresPremiers);
    DecompDeuxNombres thread2(1,tabNombresADecomposer,tabNombresPremiers);
    thread1.start();
    thread1.wait();
    thread2.start();
    thread2.wait();
    */


    // Parrallere
    /*
    for (int k = 0; k < NB; k=k+2)
    {

    DecompUnNombre thread1(k,tabNombresADecomposer,tabNombresPremiers);
    DecompUnNombre thread2(k+1,tabNombresADecomposer,tabNombresPremiers);
    thread1.start();
    thread1.wait();

    thread2.start();
    thread2.wait();
    }
    /*

    // Serie
    /**/
    for(int k = 0; k < NB; k++){
        decomposition(tabNombresADecomposer.at(k),tabNombresPremiers);
        cout << " \n";
    }
    /**/


}

int main(int argc, char** argv){
    prime_factors(argc,argv);
}