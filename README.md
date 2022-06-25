# ASD_1
Ćwiczenia w optymalizacji rozwiązań algorytmicznych pod względem złożoności
czasowej. Należy:
1) Zaimplementować i przetestować dwa różne rozwiązania dla jednego z
problemów, jedno z nich powinno mieć możliwie najniższą złożoność
czasową (oraz czas wykonania)
2) Przygotować tabele z czasem wykonania/liczbą operacji elementarnych
dla rosnących rozmiarów danych
3) W rozwiązaniach tego zestawu nie można korzystać z gotowych
kontenerów i algorytmów

**Problem 1 – Analiza obrazu**
Pewna firma informatyczna zajmuje się analizą obrazów medycznych. Aktualnie potrzebne jest
specjalistyczne oprogramowanie pozwalające wykrywać pewne cechy obrazu. Po wstępnej obróbce
piksele obrazu zostały podzielone na jaśniejsze (0) i ciemniejsze (1). Celem jest wykrywanie
dużych kwadratowych i ciemnych obszarów. Jesteś pracownikiem tej firmy i twoim zadaniem jest
napisanie wydajnego algorytmu rozwiązującego ten problem.

**Wejście:**
W pierwszej linii wejścia podany jest rozmiar n (1<=n<=3000) kwadratowego obrazu. W kolejnych
n liniach wejścia znajdują się znaki (po n w każdej linii) oznaczające oznaczające jasny (0) lub
ciemny (1) piksel. W ostatniej linii znajduje się liczba całkowita m (1<=m<=n) oznaczająca rozmiar
analizowanego kwadratowego fragmentu obrazu.

**Wyjście:**
W pierwszej linii wyjścia ma pojawić się liczba całkowita oznaczająca największą liczbę ciemnych
pikseli jaką posiada pewien fragment obrazu (o zadanym rozmiarze).


**Przykład:**

Wejście (in.txt):

5 //rozmiar obrazu (5x5)

10010

11101

10100

01111

11001

3 //analizowany fragment rozmiaru 3x3

Wyjście (out.txt):

7 //tyle ciemnych pikseli ma fragment o największej ich liczbie (pogrubiony)
