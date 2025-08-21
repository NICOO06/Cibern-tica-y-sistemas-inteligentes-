// bifurcation.cpp
// Genera datos para un diagrama de bifurcacion (archivo bifurcation.csv)
#include <iostream>
#include <fstream>

int main() {
    double r_min = 2.5;
    double r_max = 4.0;
    double r_step = 0.001; // ajusta este valor si quieres menos datos (ej: 0.005)
    int transient = 1000;  // iteraciones a desechar
    int samples = 100;     // iteraciones a guardar por cada r

    std::ofstream fout("bifurcation.csv");
    fout << "r,x\n";

    for (double r = r_min; r <= r_max; r += r_step) {
        double x = 0.2; // condicion inicial
        for (int i = 0; i < transient; ++i) {
            x = r * x * (1.0 - x);
        }
        for (int i = 0; i < samples; ++i) {
            x = r * x * (1.0 - x);
            fout << r << "," << x << "\n";
        }
    }
    fout.close();
    std::cout << "Datos de bifurcacion guardados en 'bifurcation.csv'.\n";
    return 0;
}
