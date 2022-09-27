#include <iostream>

using namespace std;


enum Vertex{
	A,
	B, 
	C,
	D,
	E,
	F
};
class Edge {
    public:
    int src, dest, weight;
};

class Graph {
    public:
    int V, E;
    Edge* edge;
    int numOfECur = 0;

    void createGraph(int V, int E) {
        cout << "Graph created" << ' ';
        this->V = V;
        this->E = E;
        this->edge = new Edge[100];
    }

    void addEdge(int v1, int v2, int weight) {
        if (numOfECur > E){
            cout << "Cant insert anymore" << endl;
            return;
        }
        edge[numOfECur].src = v1;
        edge[numOfECur].dest = v2;
        edge[numOfECur].weight = weight;
        numOfECur++;
    }

    void printArr() {
        cout << "Print Edge list" << endl;
        for (int i = 0; i < E; i++) {
            cout << i  << "  ";
            cout << edge[i].src << '\t' << edge[i].dest << '\t' << edge[i].weight;
            cout << endl;
        }
    }
    void printDist(int *dist)  {
        cout << endl;
        cout << "Vertex " << '\t' << "Dist" <<endl;
        for (int i = 0; i < V; i++) {
            cout << i << '\t' << *dist;
            dist++;
            cout << endl;
        }
        cout << endl;
    }
    void BellmanFord(int src) {
        int V = this->V;
        int E = this->E;
        int dist[100];

        for (int i = 0; i < V; i++) {
            dist[i] = INT_MAX;
        }
        int countSoLap = 0;
        dist[0] = 0;
        
        for (int i = 1; i <= V-1; i++) {
            bool check =false;
            for (int j = 0; j < E; j++) {
                //printDist(dist);
                int Src = this->edge[j].src;
                int Dest = edge[j].dest; 
                int weight = edge[j].weight;
                if (dist[Src] != INT_MAX 
                    && dist[Src] + weight < dist[Dest]) {
                        dist[Dest] = dist[Src] + weight;
                        check = true;
                    }
            }
            countSoLap ++;
            if (!check) {
                printDist(dist);
                return ;
            }
        }

        for (int i = 0; i < E; i++) {
            int Src = edge[i].src;
            int Dest = edge[i].dest; 
            int weight = edge[i].weight;
            if (dist[Src] != INT_MAX
			    && dist[Src] + weight < dist[Dest]) {
			    printf("Graph contains negative weight cycle");
			    return; 
		    }
        }
        cout << "So lan lap " << countSoLap << endl;
        printDist(dist);
    }
};

int main(){
/* Let us create the graph given in above example */
	int V = 5; // Number of vertices in graph
	int E = 8; // Number of edges in graph
	Graph graph;
    graph.createGraph(V, E);

    graph.addEdge(Vertex::A, Vertex::B, 1);
        graph.addEdge(Vertex::B, Vertex::A, 1);

    graph.addEdge(Vertex::A, Vertex::C, 4);
        graph.addEdge(Vertex::C, Vertex::A, 4);

    graph.addEdge(Vertex::B, Vertex::C, 3);
        graph.addEdge(Vertex::C, Vertex::B, 3);

    graph.addEdge(Vertex::B, Vertex::D, 2);
        graph.addEdge(Vertex::D, Vertex::B, 2);

    graph.addEdge(Vertex::B, Vertex::E, 2);
        graph.addEdge(Vertex::E, Vertex::B, 2);

    graph.addEdge(Vertex::D, Vertex::C, 5);
        graph.addEdge(Vertex::C, Vertex::D, -1);
    
    graph.addEdge(Vertex::D, Vertex::B, 1);
        graph.addEdge(Vertex::B, Vertex::D, 1);
        //.addEdge(Vertex::E, Vertex::B, -3);
        graph.BellmanFord(Vertex::A);

        graph.printArr();
}


