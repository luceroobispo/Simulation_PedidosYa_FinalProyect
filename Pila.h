#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include <functional>
using namespace std;

template<class Generico>
class NodoP {
private:
    Generico dato;
    NodoP<Generico>* siguiente;
    short pos;
public:
    NodoP(Generico v, NodoP<Generico>* sig = NULL) {
        dato = v;
        siguiente = sig;
        pos = 0;
    }
    ~NodoP() {}
    Generico getdato() { return dato; }
    void setdato(Generico dato) { this->dato = dato; }
    NodoP<Generico>* getsiguiente() { return siguiente; }

    void setpos(short c) { pos = c;}
    short getpos() { return pos; }
};

template<class Generico>
class Pila {
private:
    NodoP<Generico>* tope;
    short MAX;
    short cont;
public:
    Pila() {
        tope = NULL;
        MAX = 5; //solo se pueden hacer 5 envios por usuario
        cont = 0;
    };
    ~Pila() {}
    short getcont() { return cont; }
    NodoP<Generico>* gettope() { return tope; }

    void print(function<void(Generico)> imprime) //1
    {
        NodoP<Generico>* aux = tope; // 2  ->  apunta al inicio de la pila
        while (aux != NULL) { // n (1 + INTERNA)
            imprime(aux->getdato()); // 2
            aux = aux->getsiguiente(); //2
        }
    }

    void push(Generico v) { // 1 -> Añadir un elemento al final de la pila
        if (isEmpty()) { // 1
            tope = new NodoP<Generico>(v); // 1
        }
        else {
            tope = new NodoP<Generico>(v, tope); // 1
        }
        cont++; // 2
        tope->setpos(cont); // 2
    }

    Generico pop() { // Leer y eliminar un elemento final de la pila (TOPE)
        if (isEmpty()) {
            return nullptr;
        }
        else {
            Generico elemento = (Generico)(tope->getdato());
            tope = (NodoP<Generico>*) tope->getsiguiente();
            cont--;
            return elemento;
        }
    }

    bool isEmpty() {
        return (tope == NULL); //1
    }

    bool isFull() {
        return (cont == MAX); //1
    }

    Generico peek() {
        return tope->getdato();//1
    }

    void clear() {
        NodoP<Generico>* n; //1
        while (!isEmpty()) { //n (1 + INTERNA)
            n = tope; //1
            tope = tope->getsiguiente();//2
            delete n;//1
        }
    }

    void print_c(function<bool(NodoP<Generico>*)> condicion, function<void(Generico)> imprime) { //2
       NodoP<Generico>* aux = tope; //2
       while (aux != NULL) { // n(1 + INTERNA)
           if (condicion(aux)) { //1
               imprime(aux->getdato()); //2
           }
           aux = aux->getsiguiente();//2
       }   
    }

    void BuscarNodoP(short d, function<void(Generico)> imprime) { //2
        NodoP<Generico>* aux = tope;//2
        bool encontrado = false;//2
        while (aux != NULL && encontrado != true) {//n (2 + INTERNA)
            if (aux->getpos() == d ) { // 2
                imprime(aux->getdato()); //2
                encontrado = true; //1
            }
            aux = aux->getsiguiente(); //2
        }     
    }

    NodoP<Generico>* obtenernodopos(short d, function<void(Generico)> imprime) { //2
        NodoP<Generico>* aux = tope; //2
        bool encontrado = false; //2
        while (aux != NULL && encontrado != true) { //n (2 + INTERNA)
            if (aux->getpos() == d) { //2
                imprime(aux->getdato()); //2
                encontrado = true; //1
                return aux; //1
            }
            aux = aux->getsiguiente(); //2
        }
        if (encontrado == false) return 0; //2
    }

    void modificar( Generico e, NodoP<Generico>* p) { // 2
       p->setdato(e); //2 -> setear el dato de tope
    }

};