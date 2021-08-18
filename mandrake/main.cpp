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
#include <unordered_set>
#include <memory>
//32168

#define LOCAL

using namespace std;

typedef unordered_map<string , vector<string>> primeMap;
typedef unordered_set<string> primeSet;

int main(){
    uint_fast32_t i = 0;
    uint_fast32_t j = 0;
    uint_fast32_t index = 0;
    uint_fast32_t numA;
    uint_fast32_t numB;
    string palavra;
    string line1;
    string line2;
    string line3;
    size_t posfA = 0;
    size_t posfB= 0;
    size_t posiA = 0;
    size_t posiB = 0;
    size_t tmp;

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
    primeSet speciesA;
    primeSet speciesB;
    primeSet primesA;
    primeSet primesB;
    primeMap part;
    line2 += ' ';
    line3 += ' ';
    for (i=0;i < numA; i++) {
        posfA = line2.find(' ', posiA);
        speciesA.insert(line2.substr(posiA, posfA - posiA));
        posiA = posfA + 1;
    }
    for (j = 0; j < numB; j++) {
        posfB = line3.find(' ', posiB);
        speciesB.insert(line3.substr(posiB, posfB - posiB));
        posiB = posfB + 1;
    }

    for (auto &item : speciesA){
        for (tmp = item.size()-1; tmp > 0; tmp--) {
            palavra = item.substr(0, tmp);
            auto it = speciesA.find(palavra);
            if (it!= speciesA.end()){
                string partKey = item.substr(tmp,item.size());
                auto it2 = part.find(partKey);
                if (it2 != part.end()){
                    it2->second.push_back(item);
                    it2->second.push_back(palavra);
                }else{
                    vector<string> primes;
                    primes.push_back(item);
                    primes.push_back(palavra);
                    part.insert(pair<string, vector<string>>(partKey, primes));
                }
            }
        }
    }
    for (auto &item : speciesB){
        for (tmp = 1; tmp < item.size() ; ++tmp) {
            palavra = item.substr(tmp, item.size());
            auto it = speciesB.find(palavra);
            if ( it!= speciesB.end() ){
                string partkey = item.substr(0,tmp);
                auto it2 = part.find(partkey);
                if (it2 != part.end()){
                    primesB.insert(item);
                    primesB.insert(palavra);
                    for (auto &item2 : it2->second){
                        primesA.insert(item2);
                    }
                }
            }
        }
    }

#ifdef LOCAL
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time = " << std::chrono::duration_cast<std::chrono::microseconds>(end-begin).count() << endl;
#endif
    cout << numA-primesA.size() << " " << numB-primesB.size()<< endl;
    return 0;
}
