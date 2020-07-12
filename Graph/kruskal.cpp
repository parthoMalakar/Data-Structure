#include <iostream>
#include <algorithm>
using namespace sid;

class Edge {
    public :
    int source;
    int dest;
    int weight;
}

void compare (Edge e1, Edge e2) {
    return e1.weight < e2.weight;
}

int findParent (int v, int *parent) {
    if (parent[v] == v) {
        return v;
    }
    return findParent(parent[v], parent);
} 

void kruskal (Edge *input, int n, int E) {
    sort(input, input+E, compare);
    Edge *output = new Edge[n-1];

    int *parent = new int[n];
    for (int i = 0; i < ; i++) {
        parent[i] = i;
    }
    
    int count = 0;
    int i = 0;

    while (count != n-1) {
        int currEdge = input[i];
        int sourceParent = findParent(input[i].source, parent);
        int destParent = findParent(input[i].dest, parent);
        
        if (sourceParent != destParent) {
            output[count] = currEdge;
            parent[sourceParent] = destParent;
            count++;
        }
        i++;
    }
    for (int i = 0; i < n-1; i++) {
        if(output[i].source < output[i].dest) {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }

}

int main () {
    int n, E;
    cin >> n >> E;

    Edge *input = new Edge[E];

    for (int i = 0; i < E; i++) {
        int s, d, w;
        cin >> s >> d >> w;
        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskal (Edge, n, E);
}