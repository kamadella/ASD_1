#include <iostream>
#include <fstream>
#include <chrono>
#include <bits/stdc++.h>


using namespace std;
using namespace std::chrono;

int main()
{

    //WCZYTYWANIE PLIKU DO TABLICY TAB
    ifstream plik;
    plik.open("duzy1.txt");

    if(!plik.good()){
        cout<<"Plik nie istnieje";
        exit (0);
    }

    int rozmiar;
    plik>>rozmiar;
    int analiza;

    int **tab = new int *[rozmiar]; //kulturalnie tworzę tablicę dynamiczną (bo inaczej nie pyka)

    string wiersz="";

    for(int i=0; i<rozmiar; i++){
        tab[i] = new int [rozmiar]; //tu deklaruję ilość wierszy
        plik>>wiersz; //wczytuje sobie wiersz
        for(int j=0; j<rozmiar; j++){ //i przechodze po kazdym znaku w napisie
            tab[i][j] = wiersz[j]-48;  //konwertuje stringa do inta i każdy pojedyńczy znak trafia tam gdzie chcę do tablicy
        }
    }
    plik>>analiza;
    plik.close();

    auto start = high_resolution_clock::now();

    //-------------------------------------------------------------------------------------------------------------------------
    //WERSJA WOLNA
/*

     //liczenie wystapien 1
    int liczba_podmacierzy = (rozmiar-analiza+1)*(rozmiar-analiza+1);
    int suma[liczba_podmacierzy];
    int maximum=0;
    int licznik=0;

    for (int wiersze=0; wiersze<(rozmiar-analiza+1); wiersze++){
        for (int kolumny=0; kolumny<(rozmiar-analiza+1); kolumny++){ //fory przechodza tylko po lewej górnej granicy kwadratów

            //teraz dla każdej podmacierzy liczymy liczbê wystapien 1
            for (int i=0;i<analiza;i++){
                for (int j=0;j<analiza;j++){
                    if (tab[wiersze+i][kolumny+j] == 1) maximum++;

                }
            }
            // cout<<" "<<maximum; //ogólnie to wypisuje mi wszystkie sumy
            suma[licznik]=maximum;
            maximum=0;
            licznik++;
        }
    }


    //znajdowanie maximum
    maximum = suma[0];
    for (int i=0; i<liczba_podmacierzy; i++){
        if (maximum < suma[i]) maximum = suma[i];
    }



*/
    //-------------------------------------------------------------------------------------------------------------------------
    //WERSJA SZYBKA


    //TWORZENIE TABLICY SUM
    int **suma = new int *[rozmiar];
    for (int i = 0 ; i < rozmiar ; i++) {
        suma[i] = new int[rozmiar];
    }

    //ZAPEŁNIANIE TABLICY SUMAMI
    suma[0][0]=tab[0][0]; //suma pierwszego elementu jest równa sama sobie

    //dla 1 wiersza
    for (int k = 1; k < rozmiar; k++) {
        suma[0][k] = suma[0][k - 1] + tab[0][k];
    }

    // dla 1 kolumny
    for (int w = 1; w < rozmiar; w++) {
        suma[w][0] = suma[w - 1][0] + tab[w][0];
    }

    // dla całej reszty
    for (int w = 1; w < rozmiar; w++)
    {
        for (int k = 1; k < rozmiar; k++) {
            suma[w][k] = suma[w][k - 1] + suma[w - 1][k] + tab[w][k] - suma[w - 1][k - 1];
        }
    }


    //NISZCZENIE TABLICY TAB
    for ( int i(0); i < rozmiar; ++i )
        delete [] tab[i]; //uwolnienie pamieci
    delete [] tab; //uwolnienie pamieci
    tab = NULL;


    //ZNAJDYWANIE MAX SUMY
    int maximum = 0;
    for (int w = (analiza - 1); w < rozmiar; w++)
    {
        for (int k = (analiza - 1); k < rozmiar; k++)
        {

            int pomocnicza = suma[w][k];

            //w przypadku bycia w 1 kolumnie
            if (w - analiza >= 0) {
                pomocnicza = pomocnicza - suma[w - analiza][k];
            }

            //w przypadku bycia w 1 wierszu
            if (k - analiza >= 0) {
                pomocnicza = pomocnicza - suma[w][k - analiza];
            }

            //gdziekolwiek moze być
            if (w - analiza >= 0 && k - analiza >= 0) {
                pomocnicza = pomocnicza + suma[w - analiza][k - analiza];
            } //jezeli oba z gory sa spelnione to dodatkowo trzeba dodac to co odjelam 2 razy

            if (pomocnicza > maximum) { //i jezeli wyliczona sumka jest wieksza od poprzedniej to zostaje maxem
                maximum = pomocnicza;
            }
        }
    }


    //NISZCZENIE TABLICY SUMA
    for ( int i(0); i < rozmiar; ++i )
        delete [] suma[i]; //uwolnienie pamieci
    delete [] suma; //uwolnienie pamieci
    suma = NULL;



    //-------------------------------------------------------------------------------------------------------------------------

    auto end = chrono::high_resolution_clock::now();
    double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;

    cout<<endl<<endl<<"rozmiar obrazu = "<<rozmiar<<endl;
    cout<<"analizowany fragment obrazu = "<<analiza<<endl;
    cout<<"tyle ciemnych pikseli ma fragment o najwiekszej ich liczbie = "<<maximum<<endl;


    cout << "Czas wykonania : " << fixed << time_taken << setprecision(9);
    cout << " sec" << endl;


    ofstream zapis("out.txt");
	zapis<<maximum;
	zapis.close();


    return 0;
}
