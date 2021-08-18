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

#define LOCAL

using namespace std;

class nodeG{
public:
    //int num = 0;
    uint_fast32_t height = 1;
    size_t size = 0;
    //vector<shared_ptr<nodeG>> childPtr;
    shared_ptr<nodeG> dad;
};



int recursiveF(shared_ptr<nodeG> item){
    int kill = 0;
    int tmpH = 0;

    if(item->height!=0){
        tmpH = item->height;
        item->height = 0;
        kill++;
    }
    if (item->dad == nullptr)
        return kill;
    if (item->dad->height != tmpH+1)
        return kill;
    kill = kill + recursiveF(item->dad);
    return kill;
}

int main(){
    uint_fast32_t i = 0;
    uint_fast32_t j = 0;
    uint_fast32_t chef;
    uint_fast32_t power;
    string line2;
    string line1;
    size_t posf = 0;
    size_t posi = 0;
    uint_fast32_t dad;
    line2 += " ";
    uint_fast32_t kills = 0;

#ifdef LOCAL
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif
    getline(cin, line1);
    getline(cin, line2);

    posf = line1.find(" ");
    chef = stoi(line1.substr(0,posf));
    line1.erase(0,posf+1);
    power = stoi(line1);

    vector<shared_ptr<nodeG>> vecNode(chef+1);
    for (int k=0;k<=chef;k++){
    shared_ptr<nodeG> in (new nodeG);
    vecNode[k] = in;
    }

    i = 2;
    posf = 0;
    posi = 0;
    shared_ptr<nodeG> atual;
    while (i <= chef) {
        atual = vecNode[i];
        posf = line2.find(' ', posi);
        dad = stoi(line2.substr(posi, posf - posi));
        atual->dad = vecNode[dad];
        vecNode[dad]->size++;
        while (atual->dad!= nullptr && atual->dad->height < atual->height+1){
            atual->dad->height = atual->height+1;
            atual = atual->dad;
        }
        posi = posf + 1;
        i++;
    }

    vector<int> vecKills ;
    for (i=1; i<=chef;i++){
        if(vecNode[i]->size == 0){
            vecKills.push_back(recursiveF(vecNode[i]));
        }
    }
    stable_sort(vecKills.begin(), vecKills.end());
    i=vecKills.size()-1;
    for (int j = 0; j < power; ++j) {
        kills +=  vecKills[i];
        i--;
    }

#ifdef LOCAL
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << endl;
#endif
    cout << kills << endl;
}
