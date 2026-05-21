# Pytania:
## 1. Czy operator= może być realizowany globalnie?
Nie, musi znajdować sięjako metoda klasy.

## 2. Czy przeładowany operator= może zwracać rezultat typu void?
Można stworzyć metodę przeciążającą operator = typu void, ale nie można wtedy tworzyć takich zapisów: a = b = c; [łańcuchowe przypisanie wartości]

## 3. Kiedy automatycznie generowany operator= ("składnik po składniku") może być niewystarczający?
Gdy klasa używa zasobów dynamicznych (wskaźniki, otwarte pliki)

## 4. Analiza kodu
m=p  ->  Operator przypisania 
X z=p  ->  Konstruktor kopiujący
X h = X()  ->  Konstruktor standardowy

## 5. Co możemy dodatkowo zyskać jeśli zdecydujemy by operator= zwracał referencję do obiektu?
Dzięki temu zyskujemy możliwość tworzenia takich zapisów: a = b = c; [łańcuchowe przypisanie wartości]

## 6. Dlaczego w operatorze= trzeba sprawdzać czy nie przypisujemy obiektowi tego samego obiektu?
Aby zapobiec sytuacji, w której obiekt niszczy swoje własne dane przed skopiowaniem ich. Bez tego zapis a = a; najpierw zwolnił by pamięć obiektu a, a następnie próbował by skopiować dane z już zwolnionej pamięci.

## 7. Jakie składniki mogą spowodować, że operator= nie zostanie wygenerowany automatycznie?
Jeżeli klasa zawiera:
pola referencyjne,
pola stałe,
operator= nie zostanie wygenerowany automatycznie

# Wnioski po napisaniu programu:
### 1. Konstruktor standardowy poprawnie rezerwuje pamięć dla tablicy za pomocą 'tab = new int[size]'.
### 2. Konstruktor kopiujący wykonuje kopię, dzięki czemu zmiana danych w obiekcie oryginalnym nie zmienia nic w kopii.
### 3. Operator = wykonuje się tylko gdy obiekt już istnieje (a nie przy samej inicjalizacji)
### 4. Operator = musi sprawdzać czy obiekt do skopiowania nie jset obiektem do nadpisania. (inaczej usuną się dane przed ich skopiowaniem)
