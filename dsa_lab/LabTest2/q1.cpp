#include <iostream>
using namespace std;

#define V 4

void printResult(int color[])
{
    int countRed = 0;

    for (int i = 0; i < V; i++)
    {
        if (color[i] == 1)
        {
            countRed++;
        }
        if (color[i] == 1)
            cout
                << "For Node " << i + 1 << " "
                << "Color is Red" << endl;
        if (color[i] == 2)
            cout
                << "For Node " << i + 1 << " "
                << "Color is Blue" << endl;
        if (color[i] == 3)
            cout
                << "For Node " << i + 1 << " "
                << "Color is Green" << endl;
    }
    cout << "\n";
    cout << "Number of Red Coloured Node " << countRed;
}

bool isSafe(int v, bool graph[V][V],
            int color[], int c)
{
    for (int i = 0; i < V; i++)
        if (graph[v][i] && c == color[i])
            return false;

    return true;
}

bool graphColoringUtil(bool graph[V][V], int m,
                       int color[], int v)
{

    if (v == V)
        return true;

    for (int c = 1; c <= m; c++)
    {

        if (isSafe(v, graph, color, c))
        {
            color[v] = c;

            if (graphColoringUtil(
                    graph, m, color, v + 1) == true)
                return true;

            color[v] = 0;
        }
    }

    return false;
}

bool graphColoring(bool graph[V][V], int m)
{

    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = 0;

    if (graphColoringUtil(graph, m, color, 0) == false)
    {
        cout << "Solution does not exist";
        return false;
    }

    printResult(color);
    return true;
}

int main()
{
    bool graphA[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 0},
        {0, 1, 0, 0},
    };
    // bool graphB[V][V] = {
    //     {0, 1, 1, 1, 0, 0, 0},
    //     {1, 0, 1, 0, 1, 0, 0},
    //     {1, 1, 0, 1, 1, 0, 1},
    //     {1, 0, 1, 0, 0, 0, 0},
    //     {0, 1, 1, 0, 0, 1, 0},
    //     {0, 0, 1, 0, 1, 0, 1},
    //     {0, 0, 1, 0, 0, 1, 0},
    // };

    bool graphC[V][V] = {
        {0, 1, 1, 0},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {0, 1, 1, 0},
    };
    // bool graphD[V][V] = {
    //     {0, 1, 1, 1, 1, 0},
    //     {1, 0, 1, 0, 1, 1},
    //     {1, 1, 0, 1, 0, 1},
    //     {1, 0, 1, 0, 1, 1},
    //     {1, 1, 0, 1, 0, 1},
    //     {0, 1, 1, 1, 1, 0},
    // };

    int m = 3;
    graphColoring(graphA, m);
    return 0;
}
