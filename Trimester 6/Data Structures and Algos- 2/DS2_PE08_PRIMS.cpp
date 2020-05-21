/*
Name: Atharva Jibhakate
S.Y.BTech CSE
Panel E - E1
PE 08
*/

#include <iostream>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX 100
#define INF 9999

class node {
   public:
    int vertex;
    char name[MAX];
};

class graph {
    node* head[MAX];
    int n, cost[MAX][MAX], nearest[MAX];
    bool directed;

   public:
    graph() {
        int i, j;
        char ch;
        cout << "Do you want a directed graph? Enter y" << endl;
        cout << "ch: ";
        cin >> ch;
        directed = ch == 'y';
        cout << "Enter number of nodes in the graph!\n";
        cout << "n: ";
        cin >> n;
        for (i = 0; i < n; i++) {
            head[i] = new node;
            cout << "Enter name of node " << i + 1 << "!\n";
            cout << "name: ";
            cin >> head[i]->name;
            head[i]->vertex = i;
        }
        for (i = 0; i < MAX; i++) {
            for (j = 0; j < MAX; j++) {
                if (i == j) {
                    cost[i][j] = 0;
                } else {
                    cost[i][j] = INF;
                }
            }
        }
    }

    int index(char* name) {
        int i;
        for (i = 0; i < n; i++) {
            if (!strcmp(head[i]->name, name)) return i;
        }
        cout << "Name " << name << " not found in graph!\n";
        return -1;
    }

    void create() {
        node *temp, *current;
        int v, c;
        char ch;
        char start[MAX], end[MAX];
        cout << "Vertices are: " << endl;
        for (int i = 0; i < n; i++) {
            temp = head[i];
            cout << head[i]->name << endl;
        }
        do {
            cout << "Enter starting vertex!" << endl;
            cout << "start: ";
            cin >> start;
            cout << "Enter ending vertex!" << endl;
            cout << "end: ";
            cin >> end;
            if (!strcmp(start, end)) {
                cout << "Start and end vertex cannot be the same!" << endl;
                continue;
            }
            int startIndex = index(start);
            if (startIndex == -1) {
                cout << "Start vertex does not exist!" << endl;
                continue;
            }
            int endIndex = index(end);
            if (endIndex == -1) {
                cout << "End vertex does not exist!" << endl;
                continue;
            }
            cout << "Enter cost!" << endl;
            cout << "cost: ";
            cin >> c;
            if (c >= INF) {
                cout << "Cost must be less than " << INF << "!" << endl;
                continue;
            }
            cost[startIndex][endIndex] = c;
            if (!directed) {
                cost[endIndex][startIndex] = c;
            }
            cout << "Enter y to continue!" << endl;
            cout << "ch: ";
            cin >> ch;
        } while (ch == 'y');
    }

    void display() {
        int i, j;
        for (i = 0; i < n; i++) {
            cout << "\t" << head[i]->name;
        }
        cout << endl;
        for (i = 0; i < n; i++) {
            cout << head[i]->name << "\t";
            for (j = 0; j < n; j++) {
                cout << cost[i][j] << "\t";
            }
            cout << endl;
        }
    }

    void prims() {
        char vertex[MAX];
        int i, j, k, mincost, min, r, v;
        int t[n][2];
        cout << "Please enter the vertex you want to start prim's algorithm "
                "from!"
             << endl;
        cout << "vertex: ";
        cin >> vertex;
        v = index(vertex);
        if (v == -1) {
            cout << "Vertex " << vertex << " doesn't exist!" << endl;
            return;
        }
        nearest[v] = -1;
        for (i = 0; i < n; i++) {
            if (i != v) {
                nearest[i] = v;
            }
        }
        r = 0;
        mincost = 0;
        for (i = 0; i < n - 1; i++) {
            min = INF;
            for (j = 0; j < n; j++) {
                if (nearest[j] != -1 && cost[j][nearest[j]] < min) {
                    k = j;
                    min = cost[j][nearest[j]];
                }
            }
            t[r][0] = k;
            t[r][1] = nearest[k];
            r++;
            if (cost[k][nearest[k]] == INF) {
                break;
            }
            mincost = mincost + cost[k][nearest[k]];
            nearest[k] = -1;
            for (j = 0; j < n; j++) {
                if (nearest[j] != -1 && cost[j][nearest[j]] > cost[j][k]) {
                    nearest[j] = k;
                }
            }
        }
        cout << "Minimum cost is " << mincost << endl;
    }
};

int main() {
    graph g;
    g.create();
    g.display();
    g.prims();
    return 0;
}

/*
OUTPUT:
Do you want a directed graph? Enter y
ch: n
Enter number of nodes in the graph!
n: 6
Enter name of node 1!
name: A
Enter name of node 2!
name: B
Enter name of node 3!
name: C
Enter name of node 4!
name: D
Enter name of node 5!
name: E
Enter name of node 6!
name: F
Vertices are: 
A
B
C
D
E
F
Enter starting vertex!
start: A
Enter ending vertex!
end: B
Enter cost!
cost: 7
Enter y to continue!
ch: B y
Enter starting vertex!
start: B
Enter ending vertex!
end: C
Enter cost!
cost: 3
Enter y to continue!
ch: y
Enter starting vertex!
start: A
Enter ending vertex!
end: C
Enter cost!
cost: 8
Enter y to continue!
ch: b y
Enter starting vertex!
start: B
Enter ending vertex!
end: D
Enter cost!
cost: 6
Enter y to continue!
ch: y
Enter starting vertex!
start: C
Enter ending vertex!
end: D
Enter cost!
cost: 4
Enter y to continue!
ch: y
Enter starting vertex!
start: C
Enter ending vertex!
end: E
Enter cost!
cost: 3
Enter y to continue!
ch: E y
Enter starting vertex!
start: E
Enter ending vertex!
end: D
Enter cost!
cost: 2
Enter y to continue!
ch: E
	A	B	C	D	E	F
A	0	7	8	9999	9999	9999	
B	7	0	3	6	9999	9999	
C	8	3	0	4	3	9999	
D	9999	6	4	0	2	9999	
E	9999	9999	3	2	0	9999	
F	9999	9999	9999	9999	9999	0	
Please enter the vertex you want to start prim's algorithm from!
vertex: A
Minimum cost is 15


*/