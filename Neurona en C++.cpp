#include <iostream>
#include <vector>
using namespace std;

class Neurona {
private:
    vector<int> entradas;
    vector<int> pesos;
    int umbral;

public:
    int calcular(const vector<int>& e, const vector<int>& p, int u) {
        entradas = e;
        pesos = p;
        umbral = u;
        int suma = 0;
        for (size_t i = 0; i < entradas.size(); i++) {
            suma += entradas[i] * pesos[i];
        }
        return (suma >= umbral) ? 1 : 0;
    }
};

int main() {
    Neurona n;

    cout << "X1 X2 | AND OR NOT(X1) NAND NOR XOR XNOR\n";
    cout << "---------------------------------------\n";

    for (int x1 = 0; x1 <= 1; x1++) {
        for (int x2 = 0; x2 <= 1; x2++) {
            int AND_gate = n.calcular({x1, x2}, {1, 1}, 2);
            int OR_gate  = n.calcular({x1, x2}, {1, 1}, 1);
            int NOT_gate = n.calcular({x1}, {-1}, 0);
            int NAND_gate = n.calcular({!AND_gate}, {1}, 1);
            int NOR_gate  = n.calcular({!OR_gate}, {1}, 1);
            int XOR_gate = n.calcular({OR_gate, !AND_gate}, {1, 1}, 2);
            int XNOR_gate = !XOR_gate;

            cout << x1 << "  " << x2 << "  |  "
                 << AND_gate << "   "
                 << OR_gate << "    "
                 << NOT_gate << "       "
                 << NAND_gate << "    "
                 << NOR_gate << "    "
                 << XOR_gate << "    "
                 << XNOR_gate << "\n";
        }
    }

    return 0;
}
