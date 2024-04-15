#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

int main() {
    ifstream inputFile("data.csv"); // apro file input
    ofstream outputFile("result.txt"); // apro file di output
    string line;
    double S;
    int n;
    double* w; // puntatore per gli investimenti w
    double* r; // puntatore per i tassi di rendimento r

    // Leggere S e n dal file
    getline(inputFile, line);
    S = stod(line.substr(2));
    getline(inputFile, line);
    n = stoi(line.substr(2));

    // Allocazione dinamica della memoria per w e r
    w = new double[n];
    r = new double[n];

    // Salto la linea con "w;r"
    getline(inputFile, line);

    // Leggo i valori di w e r dal file di input
    for (int i = 0; i < n; i++) {
        getline(inputFile, line);
        stringstream ss(line);
        string element; // memorizzo temporaneamente i valori della riga presi dal file di input
        // leggo il peso w dell'investimento
        getline(ss, element, ';');
        w[i] = stod(element);
        // leggo il tasso di rendimento r dell'investimento
        getline(ss, element, ';');
        r[i] = stod(element);
    }

    inputFile.close();

    // Calcolo il tasso di rendimento totale del portafoglio
    double Rendimento = 0;
    for (int i = 0; i < n; i++) {
        Rendimento += w[i] * r[i];
    }

    // Calcolo il valore finale del portafoglio
    double V = S * (1 + Rendimento);

    // Stampo i risultati e li scrivo nel file di output
    cout << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    outputFile << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;

    cout << "w = [ ";
    outputFile << "w = [ ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << w[i] << " ";
        outputFile << fixed << setprecision(2) << w[i] << " ";
    }
    cout << "]" << endl;
    outputFile << "]" << endl;

    cout << "r = [ ";
    outputFile << "r = [ ";
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << r[i] << " ";
        outputFile << fixed << setprecision(2) << r[i] << " ";
    }
    cout << "]" << endl;
    outputFile << "]" << endl;

    cout << "Tasso di rendimento del portafoglio: " << fixed << setprecision(4) << Rendimento << endl;
    outputFile << "Tasso di rendimento del portafoglio: " << fixed << setprecision(4) << Rendimento << endl;

    cout << "V: " << fixed << setprecision(2) << V << endl;
    outputFile << "V: " << fixed << setprecision(2) << V << endl;

    // Deallocazione della memoria
    delete[] w;
    delete[] r;

    // chiudo il file di output
    outputFile.close();

    return 0;
}
