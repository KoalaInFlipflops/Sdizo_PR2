#include "Timer.h"
#include "Graph.h"
#include "Prim.h"
#include "Kruskal.h"
#include "Dijkstra.h"
#include "BellmanFord.h"
#include <windows.h>
#include <iostream>
#include <iomanip>

using namespace std;

long long int Timer::read_QPC()
{
    LARGE_INTEGER count;
    QueryPerformanceCounter(&count);
    return((long long int)count.QuadPart);
}

//Przeprowadzanie pomiarów czasu wykonwania operacji
void Timer::count_time()
{
    Graph graph;

    srand(time(NULL));
    long long int frequency, start, elapsed, mean_time;
    long long int total_time = 0;
    QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);


    //Pętla do przeprowadzenia 100 pomiarów czasu i obliczenia średniego czasu wykonania operacji
    for (int i = 0; i < 100; ++i)
    {
        graph.randomStructure(50, 0.5, 1, 10, true);
        start = read_QPC();
        //miejsce na kod do zmierzenia czasu
        //primMatrix(graph);
        //kruskalMatrix(graph);
        //dijkstraMatrix(graph);
        //bellmanFordMatrix(graph);
        //primList(graph);
        //kruskalList(graph);
        //dijkstraList(graph);
        //bellmanFordList(graph);
        elapsed = read_QPC() - start;


        total_time += (1000000000.0 * elapsed) /frequency;
    }


    mean_time = total_time/100;

    cout << "Sredni czas ze 100 pomiarow [ns] = " << fixed << setprecision(0) << mean_time << endl << endl;
    system("PAUSE");
}