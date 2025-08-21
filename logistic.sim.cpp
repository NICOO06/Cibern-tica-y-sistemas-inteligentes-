#include <iostream>
#include <fstream>

int main() {
    double r;
    double x0;
    int steps;
    std::cout << "Simulador logístico (principiante)\n";
    std::cout << "Ingresa r (ej: 2.5, 3.2, 3.8): ";
    std::cin >> r;
    std::cout << "Ingresa x0 en (0,1) (ej: 0.2): ";
    std::cin >> x0;
    std::cout << "Cuantos pasos quieres simular? (ej: 200): ";
    std::cin >> steps;

    std::ofstream fout("serie.csv");
    fout << "n,x\n";

    double x = x0;
    for (int n = 0; n <= steps; ++n) {
        if (n < 30 || n % 20 == 0) {
            std::cout << "n=" << n << "  x=" << x << "\n";
        }
        fout << n << "," << x << "\n";
        x = r * x * (1.0 - x);
    }

    fout.close();
    std::cout << "Serie guardada en 'serie.csv'. Puedes abrirla con Excel o Python.\n";
    return 0;
}
