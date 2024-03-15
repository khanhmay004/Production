//
// Created by mei on 3/10/2024.
//

#include "../include/instance.h"
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

void Instance::readData(const string& productsFile, const string& componentsFile,
                        const string& demandFile, const string& profitFile,
                        const string& stockFile) {
    readProducts(productsFile);
    readComponents(componentsFile);
    readDemand(demandFile);
    readProfit(profitFile);
    readStock(stockFile);
}

void Instance::readProducts(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string product;
    while (getline(file, product)) {
        products.push_back(product);
    }
    file.close();
}

void Instance::readComponents(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string component;
    while (getline(file, component)) {
        components.push_back(component);
    }
    file.close();
}

void Instance::readDemand(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        vector<int> temp_demand;
        int val;
        while (iss >> val) {
            temp_demand.push_back(val);
        }
        demand.push_back(temp_demand);
    }
    file.close();
}

void Instance::readProfit(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    while (getline(file, line)) {
        profit.push_back(stoi(line));
    }
    file.close();
}

void Instance::readStock(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file " << filename << endl;
        return;
    }

    string line;
    getline(file, line);
    istringstream iss(line);
    int val;
    while (iss >> val) {
        stock.push_back(val);
    }
    file.close();
}