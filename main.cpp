#include <iostream>
#include <limits>

#include "Graph.h"
#include "BellmanFord.h"
#include "Prim.h"
#include "Dijkstra.h"
#include "Kruskal.h"
#include "Timer.h"

using namespace std;

void menuMST()
{
    Graph graph;
    int action;
    int value;
    int min_weight, max_weight;
    char filename[50];
    float density;
    bool directed = false;
    do
    {
        cout << endl
             << "Wybierz opcje ktora chcesz wykonac:" << endl;
        cout << "1 - Wyswietl graf" << endl;
        cout << "2 - Wygeneruj graf" << endl;
        cout << "3 - Wczytaj graf z pliku" << endl;
        cout << "4 - Algorytm Prima" << endl;
        cout << "5 - Algorytm Kruskala" << endl;
        cout << "6 - Wroc do poprzedniego menu " << endl;
        cout << "Wybierz opcje:";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> action;
        cout << endl;
        switch (action)
        {
            case 1: // wypisanie
                graph.print();
                break;
            case 2: // utworzenie losowego
                cout << "Podaj liczbe wierzcholkow:";
                cin >> value;
                if (value <= 0)
                {
                    cout << "Niepoprawna liczba wierzcholkow!" << endl;
                    break;
                }
                cout << "Podaj gestosc grafu z przedzialu <0;1>:";
                cin >> density;
                if (density < 0 || density > 1)
                {
                    cout << "Niepoprawna gestosc!";
                    break;
                }
                cout << endl << "Podaj minimalna wage krawedzi:";
                cin >> min_weight;
                cout << "Podaj maksymalna wage krawedzi:";
                cin >> max_weight;
                cout << endl;
                if (min_weight < 0 || max_weight < 0)
                {
                    cout << "Waga musi byc pozytywna!" << endl;
                    break;
                }
                graph.randomStructure(value, density, min_weight, max_weight, directed);
                break;
            case 3: // utworzenie z pliku
                cout << "Podaj nazwe pliku:";
                cin >> filename;
                cout << endl;
                graph.loadGraphFromFile(filename, directed);
                break;
            case 4: // Prim
                primMatrix(graph);
                primList(graph);
                break;
            case 5: // Kruskal
                kruskalMatrix(graph);
                kruskalList(graph);
                break;
            case 6: // wyjście
                break;
            default:
                cout << "Opcja nie istnieje!" << endl;
                break;
        }
    } while (action != 6);
}

void menuPath()
{
    Graph graph;
    int action;
    int value;
    int start;
    int min_weight, max_weight;
    char filename[50];
    float density;
    bool directed = true;
    do
    {
        cout << endl
             << "Wybierz opcje ktora chcesz wykonac:" << endl;
        cout << "1 - Wyswietl graf" << endl;
        cout << "2 - Wygeneruj graf" << endl;
        cout << "3 - Wczytaj graf z pliku" << endl;
        cout << "4 - Algorytm Bellmana-Forda" << endl;
        cout << "5 - Algorytm Dijkstry" << endl;
        cout << "6 - Wroc do poprzedniego menu" << endl;
        cout << "Wybierz opcje:";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> action;
        cout << endl;
        switch (action)
        {
            case 1: // wypisanie
                graph.print();
                break;
            case 2: // utworzenie losowego
                cout << "Podaj liczbe wierzcholkow:";
                cin >> value;
                if (value <= 0)
                {
                    cout << "Niepoprawna liczba wierzcholkow!" << endl;
                    break;
                }
                cout << "Podaj gestosc grafu z przedzialu <0;1>:";
                cin >> density;
                if (density < 0 || density > 1)
                {
                    cout << "Niepoprawna gestosc!" << endl;
                    break;
                }
                cout << endl << "Podaj minimalna wage krawedzi:";
                cin >> min_weight;
                cout << "Podaj maksymalna wage krawedzi:";
                cin >> max_weight;
                cout << endl;
                graph.randomStructure(value, density, min_weight, max_weight, directed);
                break;
            case 3: // utworzenie z pliku
                cout << "Podaj nazwe pliku:";
                cin >> filename;
                cout << endl;
                graph.loadGraphFromFile(filename, directed);
                min_weight = max_weight = 0; // wczytując nie znam wag, ta linijka zakłada że wagi są dobre
                break;
            case 4: // Bellman - Ford
                cout << "Podaj wierzcholek startowy:";
                cin >> start;
                if (start > graph.size_nodes - 1)
                {
                    cout << "Nie ma takiego wierzcholka!" << endl;
                    break;
                }
                graph.start_node = start;
                bellmanFordMatrix(graph);
                bellmanFordList(graph);
                break;
            case 5: // Dijkstra
                cout << "Podaj wierzcholek startowy:";
                cin >> start;
                if (start > graph.size_nodes - 1)
                {
                    cout << "Nie ma takiego wierzcholka!" << endl;
                    break;
                }
                graph.start_node = start;
                dijkstraMatrix(graph);
                dijkstraList(graph);
                break;
            case 6: // wyjście
                break;
            default:
                cout << "Opcja nie istnieje!" << endl;
                break;
        }
    } while (action != 6);
}

void menu()
{
    int choice;
    do
    {
        cout << endl
             << "Podaj, ktory typ algorytmow chcesz wykonac:" << endl;
        cout << "1 - minimalne drzewo rozpinajace (MST)" << endl;
        cout << "2 - najkrotsza sciezka (Shortest Path)" << endl;
        cout << "0 - Wyjdz z programy" << endl;
        cout << "Wybierz opcje:";
        cin >> choice;
        switch (choice)
        {
            case 1:
                menuMST();
                break;
            case 2:
                menuPath();
                break;
            case 0:
                break;
            default:
                cout << "OBrak takiej opcji" << endl;
                break;
        }
    } while (choice != 0);
}

int main()
{
    menu();

    //Timer t;
    //t.count_time();

    return 0;
}
