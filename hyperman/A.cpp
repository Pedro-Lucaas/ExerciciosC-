//
// Created by pedro on 26/07/2021

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <chrono>
#include <algorithm>
#include <unordered_map>
#include <memory>

//#define LOCAL

using namespace std;

class nodeG{
public:
    int num;
    int height;
    size_t size;
    vector<shared_ptr<nodeG>> childPtr;
    shared_ptr<nodeG> dad;
};



int recursiveF(shared_ptr<nodeG> item){
    int kill = 0;
    int tmpH = 0;
    if (item->dad == nullptr){
        return kill;
    }

    if(item->height!=0){
        tmpH = item->height+1;
        item->height = 0;
        kill++;
    }
    if (item->dad->height > tmpH){
        return kill;
    }

    kill = kill + recursiveF(item->dad);

    return kill;
}

int main(){
    uint_fast32_t i = 0;
    uint_fast32_t j = 0;
    int chef;
    int power;
    string line2;
    string line1;
    size_t posf = 0;
    size_t posi = 0;
    int dad;
    line2 += " ";

#ifdef LOCAL
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif
    getline(cin, line1);
    getline(cin, line2);

    posf = line1.find(" ");
    chef = stoi(line1.substr(0,posf));
    line1.erase(0,posf+1);
    power = stoi(line1);

    vector<shared_ptr<nodeG>> vecLeaf;

    vector<shared_ptr<nodeG>> vecNode(chef+1);
    for (int k=0;k<=chef;k++){
    shared_ptr<nodeG> in (new nodeG);
    vecNode[k] = in;
    vecNode[k]->num = k;
    }

    i = 2;
    posf = 0;
    posi = 0;
    int hgt;
    shared_ptr<nodeG> atual;
    while (i <= chef) {
        posf = line2.find(' ', posi);
        dad = stoi(line2.substr(posi, posf - posi));
        atual = vecNode[i];
        vecNode[dad]->childPtr.push_back(atual);
        atual->dad = vecNode[dad];
        vecNode[dad]->size = vecNode[dad]->childPtr.size();
        if (atual->size==0){
            atual->height = 1;
        }
        while (atual->dad!= nullptr){
            if(atual->dad->height < atual->height+1 ){
                atual->dad->height = atual->height+1;
            }
            atual = atual->dad;
        }
        posi = posf + 1;
        i++;
    }

    int kills = 0;
    for (i=1; i<=chef;i++){
        if(vecNode[i]->size == 0){
            vecLeaf.push_back(vecNode[i]);
        }
    }
    vector<int> vecKills (vecLeaf.size());
    i=0;
    for (auto &item : vecLeaf){
        vecKills[i] = recursiveF(item);
            i++;
    }
    stable_sort(vecKills.begin(), vecKills.end());
    i=vecKills.size()-1;
    for (int j = 0; j < power; ++j) {
        kills +=  vecKills[i];
        i--;
    }
    cout << kills+1 << endl;
#ifdef LOCAL
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << endl;
#endif
   return 0;
}
