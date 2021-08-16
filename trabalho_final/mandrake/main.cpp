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
//32168

//#define LOCAL

using namespace std;
class ponto{
public:
    uint_fast32_t x;
    uint_fast32_t y;
};
class ptrString{
    string str;
};
typedef unordered_map<string, shared_ptr<ponto>> table;
typedef unordered_map<int, int> prime;

int main(){
    uint_fast32_t i = 0;
    uint_fast32_t j = 0;
    uint_fast32_t index = 0;
    uint_fast32_t numA;
    uint_fast32_t numB;
    string palavra;
    string line2;
    string line1;
    string line3;
    size_t posfA = 0;
    size_t posfB= 0;
    size_t posiA = 0;
    size_t posiB = 0;

    table tableH;
    table::hasher func = tableH.hash_function();

#ifdef LOCAL
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif

    getline(cin, line1);
    getline(cin, line2);
    getline(cin, line3);

    posfA = line1.find(' ');
    numA = stoi(line1.substr(0,posfA));
    numB = stoi(line1.substr(posfA, line1.size()-posfA));

    posfA = 0;
    posiA = 0;
    posfB = 0;
    posiB = 0;
    prime primeA;
    prime primeB;

    line2 += " ";
    line3 += " ";
//    for (int i = 0; i < numA; ++i) {
//        posfA = line2.find(' ', posiA);
//        palavra = line2.substr(posiA, posfA - posiA);
//        shared_ptr<ponto> my (new ponto);
//        my->x = i;
//        my->y = j;
//        tableH.insert(pair<string, shared_ptr<ponto>>(palavra, my));
//        posiA = posfA+1;
//    }
    for (i=0;i < numA; i++) {
        posfA = line2.find(' ', posiA);
        for (j = 0; j < numB; j++) {
            posfB = line3.find(' ', posiB);
            palavra = line2.substr(posiA, posfA - posiA) + line3.substr(posiB, posfB - posiB);
            shared_ptr<string> ptrPal (new string);
            auto it = tableH.find(palavra);
            if (it == tableH.end()) {
                shared_ptr<ponto> my (new ponto);
                my->x = i;
                my->y = j;
                tableH.insert(pair<string, shared_ptr<ponto>>(palavra, my));
            } else {
                primeA.insert(pair<int, int>(it->second->x, 1));
                primeA.insert(pair<int, int>(i, 1));
                primeB.insert(pair<int, int>(it->second->y, 1));
                primeB.insert(pair<int, int>(j, 1));
            }
            posiB = posfB + 1;
        }
        posfB = 0;
        posiB = 0;
        index += j;
        posiA = posfA + 1;
    }


#ifdef LOCAL
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << endl;
#endif
    cout << numA-primeA.size() << " " << numB-primeB.size()<< endl;
    return 0;
}
