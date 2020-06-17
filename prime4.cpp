#include <QApplication>
#include <QThread>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>
 
using namespace std;
    string line,linePrime;
    ifstream inFile,primeFile;

class MyThreadDecomposition: public QThread {
    private: string line;
    private: std::ifstream& inFile;
        void run() {
            while (getline(inFile, line) )
            {
                cout << line << endl;
            }
            cout << "hello World" << endl;
        }
        public:
            MyThreadDecomposition(std::ifstream& inFile, string line) : QThread(), inFile(inFile), line(line) {};
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
       // std::cout << threadDecomp << std::endl;

        threadDecomp.start();
        threadDecomp.wait();


}

int main(int argc, char** argv){

    prime_factors(argc,argv);


    
}