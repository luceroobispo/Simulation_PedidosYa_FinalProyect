#pragma once
#include <iostream>
#include <array>
#include <list>
#include <vector>
#include <string>
using namespace std;

template<typename S, class G> 
class Entity {
	S key;
	G value;
public:
	Entity() {}
	Entity(S k, G v) :key(k), value(v) {}
	~Entity() {}
	S getkey() { return key; }
	G getvalue() { return value; }

	void setelem(S key, G value) {
		this->key = key;
		this->value = value;
	}
};

template<typename S, class G>
class HT {
	array<list<Entity<S, G>>, 5> container;
public:
	HT() {}
	~HT() {}

	array<list<Entity<S, G>>, 5> getcontainer() { return container; }

	int hash(S key) { //1   //lucero
		int result = 0;//2
		for (int i = 0; i < key.length(); i++) {//1 + n(1 + 2 +INTERNA)
			result += int(key[i]); //3
		}
		return result % 5;//2
	}

	int hash_e(S key) { //1 //eric
		int value = key[1]; //2
		return value % 4; //2
	}

	void add_e(S key, G value) { //2
		container[hash_e(key)].push_back(Entity<S, G>(key, value)); //1 + 5 + 1 
	}

	void add(S key, G value) { //2
		container[hash(key)].push_back(Entity<S, G>(key, value));//1 + 4 + 6n + 1
	}

	void addInTheMiddle(S key, G value) { //2
		if (container[hash_e(key)].empty()) // 1 + 5 + 1
			container[hash_e(key)].push_back(Entity<S, G>(key, value)); //1 + 5 + 1 
		else {
			auto iter = container[hash_e(key)].begin(); // 2 + 1 + 6 + 1 
			advance(iter, int(container[hash_e(key)].size() / 2)); // 1 + 9
			container[hash_e(key)].insert(iter, Entity<S, G>(key, value)); // 1 + 5 + 1 
		}
	}

	void displayCondicion(function<void(S, G)> imprime, function<bool(G)> comp) {
		int i = 0;
		for (auto itArray : container) {
			cout << "  Area " << i + 1 << ": ";
			for (list<Entity<S, G>>::iterator it = container[i].begin(); it != container[i].end(); ++it) {
				if (comp((*it).getvalue())) {
					cout << "\n	  -> "; imprime((*it).getkey(), (*it).getvalue());
				}
			}
			cout << endl;
			i++;
		}
	}

	void display(function<void(S, G)> imprime) { //1
		int i = 0; //2
		for (auto itArray : container) { //n (INTERNA)
			cout << "  Area " << i + 1 << ": "; //2
			for (list<Entity<S, G>>::iterator it = container[i].begin(); it != container[i].end(); ++it) { //1 + 1 + n(1 + 1 + 2 + INTERNA)
				cout << "\n	  -> "; //1
				imprime((*it).getkey(), (*it).getvalue()); // 2
			}
			cout << endl;//1
			i++;//2
		}
	}

	int particion(Entity<S, G>* A, int inicio, int final, function<bool(G, G)> condicion) {
		Entity<S, G> x = A[final]; //el pivote
		int i = inicio - 1; //indice de los menores
		for (int j = inicio; j < final; j++) {
			if (condicion(A[j].getvalue(), x.getvalue())) {
				i++;
				swap(A[i], A[j]);
			}
		}
		swap(A[i+1], A[final]);
		return i+1;
	}

	Entity<S, G> quickselect(Entity<S, G>* A, int inicio, int final, int k, function<bool(G, G)> condicion) {
		if (inicio == final) return A[inicio];
		//indice del pivote con A ordenado Izq(Menores) Der(Mayores) al pivote
		int pivote = particion(A, inicio, final,condicion);
		int l = pivote - inicio + 1; //nro elementos del sub arreglo donde se encuentra el kesimo elemento
		if (k== l)
			return A[pivote];
		else if (k < l) {
			return quickselect(A, inicio, pivote - 1, k, condicion);
		}
		else {
			return quickselect(A, pivote + 1, final, k - l, condicion);
		}
	}

	Entity<S, G> listaToArrayQuickselect(list<Entity<S, G>> Lista, int k, function<bool(G, G)> condicion) {
		int n = Lista.size(); int i = 0;
		Entity<S, G>* A = new Entity<S, G>[n];
		for (list<Entity<S, G>>::iterator it = Lista.begin(); it != Lista.end(); ++it) {
			A[i] = (*it);
			i++;
		}

		return quickselect(A, 0, n-1, k, condicion);
	}

    void listaToArrayQuicksort(list<Entity<S, G>> Lista, int p, int r, function<bool(G, G)> condicion, function<void(S, G)> imprime) { //5
		int n = Lista.size();  //3
		int i = 0; //2
		Entity<S, G>* A = new Entity<S, G>[n]; //2
		for (list<Entity<S, G>>::iterator it = Lista.begin(); it != Lista.end(); ++it) { //3 + n( 2 + 2 + Interno)
			A[i] = (*it);//1
			i++;//2
		}
		quicksort(A, 0, n - 1, condicion); // 22 + 9n + 2 log(n)

		list<Entity<S, G>> l ; //1
		for (int i = 0; i < n; i++) { //2 + n(1 + 2 + Interno)
			l.push_back(A[i]); //1
		}

		for (list<Entity<S, G>>::iterator it = l.begin(); it != l.end(); ++it) {// 3 + n( 2 + 2 + Interno)
			cout << "\n	  -> "; // 1
			imprime((*it).getkey(), (*it).getvalue()); //3
		}
		
	}

	void quicksort(Entity<S, G>* A, int p, int r, function<bool(G, G)> condicion) {//4
		int q; //1
		if (p < r) { //1
			q = particion(A, p, r, condicion); //1 + 15 + 9n
			quicksort(A, p, q - 1, condicion); // log n
			quicksort(A, q + 1, r, condicion); // log n
		}	
	}

};