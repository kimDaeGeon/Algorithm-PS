#include<bits/stdc++.h>
using namespace std;

void print(const vector<int> elements, const vector<int> &index);
void pick(int toPick, int size, vector<int> elements, vector<int> &index);

int main(){
    int n,m;
    cin >> n >> m;

    vector<int> elements, index;
    for(int i =  1; i <= n ; i++){
        elements.push_back(i);
    }

    pick(m, n, elements, index);


    return 0;
}

void print(const vector<int> elements, const vector<int> &index){
    for(int idx : index){
        cout << elements[idx] << ' ';
    }
    cout << '\n';
}
void pick(int toPick, int size, vector<int> elements, vector<int> &index){
    if(toPick == 0){
        print(elements, index);
        return;
    }
    int min = index.empty() ? 0 : index.back();

    for(int idx = min ; idx < size ; idx++){
        index.push_back(idx);
        pick(toPick-1, size, elements, index);
        index.pop_back();
    }
}