#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

vector<int> graph[1000];
char color[1000];     //÷вет будем представл€ть типом char
                        //0 - не покрашена; 1, 2 - красный и синий.

 char invert(int c) {
    return c == 1 ? 2 : 1;
}

void dfs(int k, char c) {   //c - цвет текущей вершины
    color[k] = c;

    for (int l : graph[k]) {
        if (color[l] == 0) {    //непосещЄнна€ вершина
            dfs(l, invert(c));
        }
        else if (color[l] == c)
        {
            cout << "Graph ne dvudolniy" << endl;
            exit(0);
        }
    }
}

int main() {
    string path;
    cout << "Vvedite nomer testa" << endl;
    cin >> path;
    path = path + ".txt";
    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "error" << endl;
        
    }
    

    int n, m;       //количество вершин и рЄбер 
    fin >> n >> m;


        for (int i = 0; i < m; i++)
        {
            int u, v;   //номера вершин
            fin >> u >> v;
            u--, v--;


            graph[u].push_back(v);
            graph[v].push_back(u);
        
        }

        for (int i = 0; i < n; i++) {
            cout << i + 1<<" ";
            for (int v : graph[i]) {     
                cout<<v+1<<" ";                    
            }                           

            cout << endl;
        }
    
    
    for (int i = 0; i < n; i++) {
        if (color[i] == 0) {
            dfs(i, 1);
        }
    }

    cout << "Graph dvudolniy" << endl;
}