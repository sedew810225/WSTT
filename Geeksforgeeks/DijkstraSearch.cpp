#include <iostream>
#include <cstring>
#include <stack>
#include <vector>
#include <csignal> 


using namespace std;
void dijkstra(vector<vector<int>>, int, int);

#if 0
int main()
{
    int t;
    int V;
    cin >> t;
    while (t--) {
        cin >> V;

        vector<vector<int>> g(V);

        for (int i = 0; i < V; i++) {
            vector<int> temp(V);
            g[i] = temp;
        }

        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cin >> g[i][j];
            }
        }

        int s;
        cin >> s;

        dijkstra(g, s, V);
        cout << endl;
    }
    return 0;
}
#endif

/*This is a function problem.You only need to complete the function given below*/
/*  Function to implement Dijkstra
*   graph: vector of vectors which represents the graph
*   src: source vertex to start traversing graph with
*   V: number of vertices
*/
void updateAdj(vector<vector<int>> graph, int src, int V, stack<int>* travelStack, int* result) {
    int i = 0;

    if (travelStack->size() == V) return;
    int prev = travelStack->top();

    for (i = 0; i < V; i++) {

        if (i == prev || i == src) continue;
        if (graph[prev][i] == 0) continue;

        if ((result[prev] + graph[prev][i]) <= result[i]) result[i] = (result[prev]) + (graph[prev][i]);
        else if ((result[prev] + graph[prev][i]) > result[i]) continue;

        travelStack->push(i);
        updateAdj(graph, src, V, travelStack, result);
        travelStack->pop();
    }

    return;
}

void signal_handler(int signal_num) {
    cout << "The interrupt signal is (" << signal_num << "). \n";
    // terminate program   
    exit(signal_num);
}

void dijkstra(vector<vector<int>> graph, int src, int V)
{
    int i = 0;

    int* result = new int[V];
    if (result == 0) return;

    int temp = 4000 * V;

   // signal(SIGABRT, signal_handler);

    if (src >= V || src < 0) return;

    //for (i=0;i<V;i++){
    //    result[i] = temp;
    //}
    //memset(result, temp, sizeof(int)*V );

    stack<int> travelStack;
    travelStack.empty();
    travelStack.push(src);

    for (i = 0; i < V; i++) {
        result[i] = graph[src][i];
    }
    result[src] = 0;

    updateAdj(graph, src, V, &travelStack, result);

    for (i = 0; i < V; i++) {
        cout << result[i];
        cout << " ";
    }

    if (result != 0) delete result;

    return;
}