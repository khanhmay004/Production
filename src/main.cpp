#include <iostream>
#include "../include/instance.h"
#include <iostream>
#include <ilconcert/ilosys.h>
#include <ilcplex/ilocplex.h>
#include <vector>

using namespace std;
ILOSTLBEGIN
int main() {
    //Data
    Instance instance;
    instance.readData("C:\\Users\\drnan\\CLionProjects\\production_plan\\data\\data.txt","../data/com.txt","data/demand.txt","data/profit.txt","data/stock.txt");

    IloEnv env;
    try {
        IloModel model(env);
        IloCplex cplex(model);
        IloNumVarArray x(env, instance.products.size(),0,IloInfinity);
       /* for (int i = 0; i < Products.size(); i++) {
            string name = "x_" + to_string(i);
            x[i] = IloIntVar(env, 1, IloInfinity, name.c_str());
        }*/
        //Object fuctions: Maximize profit
        IloExpr objective(env);
        for(int i = 0; i < instance.products.size(); i++){
            objective += instance.profit[i] * x[i];
        }
        model.add(IloMaximize(env, objective));

        //Constraint
//        for(int i = 0; i < Products.size(); i++) {
//            IloExpr totalStock(env);
//            for(int j = 0; j < Components.size(); j++){
//                totalStock += Demand[j][i] * x[i];
//            }
//
//            model.add(totalStock <= Stock[j]);
//        }
        for (int j = 0; j < instance.components.size(); j++) {
            IloExpr component_constraint(env);
            for (int i = 0; i < instance.products.size(); i++) {
                component_constraint += instance.demand[i][j] * x[i];
            }
            model.add(component_constraint <= instance.stock[j]);
        }


        cplex.solve();
        cout << cplex.getObjValue() << endl;
        for (int i = 0; i < instance.products.size();i++){
            cout << cplex.getValue(x[i]) << " ";
        }

    }  catch (IloException &ex) {
        std::cerr << "Error: " << ex << std::endl;
    } catch (...) {
        std::cerr << "Unknown exception caught!" << std::endl;
    }
    env.end();
    return 0;
}
