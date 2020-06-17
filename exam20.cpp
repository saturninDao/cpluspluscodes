#include <QApplication>
#include <QThread>
#include <bits/stdc++.h>
#include <iostream>
#include <fstream>

typedef struct {
        int a;
        int b;
} struct_t;

class MyThread1 : public QThread {
        private:
                struct_t *var;
                void run() Q_DECL_OVERRIDE {
                        std::cout<< "Task 1: a= " << var->a << ", b= " << var->b <<std::endl;
                }
        public:
                MyThread1(struct_t *arg) : QThread(),var(arg) {};
};
class MyThread2 : public QThread {
        private:
                int aValue;
                void run() Q_DECL_OVERRIDE {
                        std::cout << "Task 2: value= "<< aValue << std::endl;
                }
        public:
                MyThread2(int value) : QThread(),aValue(value) {};
};

int main(int argc,char *argv[]){
        struct_t v;
        v.a = 1; v.b = 2;

        MyThread1 thread1(&v);
        thread1.start();
        thread1.wait();

        MyThread2 thread2(3);
        thread2.start();
        thread2.wait();

        return EXIT_SUCCESS;
}