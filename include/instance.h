//
// Created by mei on 3/10/2024.
//

#ifndef UMV_FSTSP_INSTANCE_H
#define UMV_FSTSP_INSTANCE_H
#include <string>
#include <vector>
using namespace std;
class Instance{
public:
    vector<string> products;
    vector<string> components;
    vector<vector<int>> demand;
    vector<int> profit;
    vector<int> stock;
    void readData(const string& productsFile, const string& componentsFile,
                  const string& demandFile, const string& profitFile,
                  const string& stockFile);
    void readProducts(const std::string& filename);
    void readComponents(const std::string& filename);
    void readDemand(const std::string& filename);
    void readProfit(const std::string& filename);
    void readStock(const std::string& filename);
};

#endif //UMV_FSTSP_INSTANCE_H
