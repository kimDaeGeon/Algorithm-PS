#include<bits/stdc++.h>
using namespace std;

int user, friends;
int BFS(vector<int> graph[], int start);

int main(){
    cin >> user >> friends;
    vector<int> *graph = new vector<int>[friends];

    cout << friends<<'\n';
    for(int f = 0 ; f < friends; f++){
        int a, b;
        cout << f << ':';
        cin >> a >> b;
        
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> dist;
    for(int node = 0 ; node < user ; node++){
        dist.push_back(BFS(graph, node));
    }

    std::sort(dist.begin(), dist.end());
    cout << dist.back() << '\n';

    return 0;
}

int BFS(vector<int> graph[], int start){
    queue<int> bfs;
    int *isVisited = new int[user];
    for(int i = 0 ; i < user; i++) isVisited[i] = false;

    isVisited[start] = 1;
    bfs.push(start);

    while(!bfs.empty()){
        for(int node : graph[bfs.front()]){
            if(isVisited[node] == 0){
                isVisited[node] = isVisited[bfs.front()] + 1;
                bfs.push(node);
            }
        }
        bfs.pop();
    }

    int baconConst = 0;
    for(int i = 0 ; i < user ; i++){
        baconConst += isVisited[i];
    }
    return baconConst;
}