#include <bits/stdc++.h> 
using namespace std; 

class DSU { 
    map<char, char> parent; 
    map<char, int> rank; 

public: 
    DSU() {}

    char find(char i) { 
        if (parent.find(i) == parent.end()) 
            return i; 

        return parent[i] = find(parent[i]); 
    } 

    void unite(char x, char y) { 
        char s1 = find(x); 
        char s2 = find(y); 

        if (s1 != s2) { 
            if (rank[s1] < rank[s2]) { 
                parent[s1] = s2; 
            } 
            else if (rank[s1] > rank[s2]) { 
                parent[s2] = s1; 
            } 
            else { 
                parent[s2] = s1; 
                rank[s1] += 1; 
            } 
        } 
    } 
}; 

class Graph { 
    vector<tuple<int, char, char>> edgelist; 

public: 
    Graph() {} 

    void addEdge(char x, char y, int w) { 
        edgelist.push_back(make_tuple(w, x, y)); 
    } 

    void kruskals_mst() { 
        sort(edgelist.begin(), edgelist.end()); 

        DSU s; 
        int ans = 0; 
        for (auto edge : edgelist) { 
            int w = get<0>(edge); 
            char x = get<1>(edge); 
            char y = get<2>(edge); 

            if (s.find(x) != s.find(y)) { 
                s.unite(x, y); 
                ans += w; 
                cout << x << " -- " << y << " ==> " << w << endl; 
            } 
        } 
        cout << "Minimum Cost Spanning Tree: " << ans; 
    } 
}; 

int main() { 
    Graph g; 
    g.addEdge('A', 'B', 2); 
    g.addEdge('A', 'F', 7); 
    g.addEdge('A', 'G', 3); 
    g.addEdge('B', 'G', 6); 
    g.addEdge('B', 'C', 4); 
    g.addEdge('C', 'H', 2); 
     g.addEdge('C', 'D', 2);
    g.addEdge('D', 'H', 8);
    g.addEdge('D', 'E', 1);
    g.addEdge('E', 'I', 2);
    g.addEdge('E', 'F', 6);
    g.addEdge('F', 'I', 2);
    g.addEdge('G', 'I', 1);
    g.addEdge('G', 'H', 3); 

 

 



 



    g.kruskals_mst(); 

    return 0; 
}
