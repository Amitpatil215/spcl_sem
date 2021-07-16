#include "adjacencyMatrix.cpp"

// Disjoint set Union
const int N = 1e5 + 6;
vector<int> parent(N);
vector<int> sz(N); // size of each set

void make_set(int v)
{
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v)
{
    if (v == parent[v])
        return v;

    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b)
{
    a = find_set(a);
    b = find_set(b);

    if (a != b)
    {
        if (sz[a] < sz[b])
            swap(a, b);
        parent[b] = a;
        sz[a] = sz[a] + sz[b];
    }
}
}
void print(vector<vector<int>> graph)
{
    int n = graph.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}
