//
//  main.cpp
//  GenomeData
//
//  Created by jperdomo on 11/15/15.
//  Copyright © 2015 jperdomo. All rights reserved.
//


//  Finds percent similarity of chromosomes, longest identical span of nucleotides, locations.

#include<iostream>
#include<fstream>

using namespace std;

int main() {
    
    ifstream myReadFile;
    myReadFile.open("chm1.fa");
    if (myReadFile.is_open()) {
        printf("File opened successfully.\n");
        
        printf("\n");
        
        string info;
        getline(myReadFile, info);
        
        printf("%s\n\n", info.c_str());
        
        int max = 200;
        
        float countA, countC, countG, countT, countN = 0;
        
        float total = 0;
        
        int ind = 0;
        
        while (ind < max) {
            string nucStr;
            getline(myReadFile, nucStr);
            
            total += nucStr.length();
            size_t a = count(nucStr.begin(), nucStr.end(), 'A');
            countA += a;
            
            size_t g = count(nucStr.begin(), nucStr.end(), 'G');
            countG += g;
            
            size_t c = count(nucStr.begin(), nucStr.end(), 'C');
            countC += c;
            
            size_t t = count(nucStr.begin(), nucStr.end(), 'T');
            countT += t;
            
            size_t n = count(nucStr.begin(), nucStr.end(), 'N');
            countN += n;
            
            ind++;
            }
        
        printf("Bases Counted: %.0f\n", total);
        
        printf("\n");

        
        printf("Adenine Count: %.0f\n", countA);
        printf("Guanine Count: %.0f\n", countG);
        printf("Cytosine Count: %.0f\n", countC);
        printf("Thymine Count: %.0f\n", countT);
        printf("Unknown Count: %.0f\n", countN);

        printf("\n");
        
        printf("%.2f Percent Adenine\n", (countA / total) * 100);
        printf("%.2f Percent Guanine\n", (countG / total) * 100);
        printf("%.2f Percent Cytosine\n", (countC / total) * 100);
        printf("%.2f Percent Thymine\n", (countT / total) * 100);
        printf("%.2f Percent Unknown\n", (countN / total) * 100);

        
        /*while (!myReadFile.eof()) {
            
            
            myReadFile >> output;
            cout<<output;
            
            
        }*/
    }
    myReadFile.close();
    return 0;
}
