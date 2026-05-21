#include <iostream>
using namespace std;

class Abcd {
private:
    int *tab;
    int size;
    string name;

public:
    Abcd(int newSize = 3, string newName = "") : size(newSize), name(newName) {
        tab = new int[size];
        for (int i = 0; i < size; i++) {
            tab[i] = i;
        }
        cout<<"Obiekt utworzony z uzyciem standardowego konstruktora"<<endl;
    }

    Abcd(const Abcd &obj) : size(obj.size), name(obj.name) {
        tab = new int[size];
        for (int i = 0; i < size; i++) {
            tab[i] = obj.tab[i];
        }
        cout<<"Obiekt utworzony z uzyciem konstruktora kopiujacego"<<endl;
    }

    Abcd& operator=(const Abcd &obj) {
        cout<<"Uzyto operatora przypisania"<<endl;
        if (this == &obj) {
            return *this;
        }

        delete [] tab;
        size = obj.size;
        name = obj.name;
        tab = new int[size];
        for (int i = 0; i < size; i++) {
            tab[i] = obj.tab[i];
        }
        return *this;
    }

    ~Abcd() {
        delete [] tab;
        cout<<"[Destruktor]"<<endl;
    }

    friend ostream& operator<<(ostream &os, const Abcd &obj) {
        os << "Nazwa: " << obj.name << ", Rozmiar: " << obj.size << ", Tablica: [ ";
        for (int i = 0; i < obj.size; i++) {
            os << obj.tab[i] << " ";
        }
        os << "]" << endl;
        return os;
    }
};

int main() {
    cout << "Abcd a(5,'Pierwszy'): " << endl;
    Abcd a(5,"Pierwszy");
    cout << a << endl;
    cout << "-------------------------------------------" << endl;

    cout << "Abcd b = a: " << endl;
    Abcd b = a;
    cout << b << endl;
    cout << "-------------------------------------------" << endl;

    cout << "Abcd c(3,'Trzeci'): " << endl;
    Abcd c(3, "Trzeci");
    cout << c << endl;
    cout << "-------------------------------------------" << endl;

    cout << "c = a: " << endl;
    c = a;
    cout << c << endl;
    cout << "-------------------------------------------" << endl;

    cout << "c = c: " << endl;
    c = c;
    cout << c << endl;
    cout << "-------------------------------------------" << endl;
    return 0;
}