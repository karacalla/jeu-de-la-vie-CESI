// ce script à pour but de prendre la matrice de base, la transformer
// en données utilisables, de l'afficher sur le terminal (au cas où)
// et de faire de même pour plusieurs autres "fausses" matrices;
// comme placeholder pour le vrai jeu de la vie.

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>

// Lit la dimension de la matrice de base
bool parseFileHeader(std::ifstream& file, int& lines, int& columns) {
    file >> lines >> columns;
    return !file.fail();
}

// Génère la matrice initiale
bool loadMatrix(std::ifstream& file, std::vector<std::vector<int>>& mat, int lines, int columns) {
    mat.assign(lines, std::vector<int>(columns));
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            file >> mat[i][j];
            if (file.fail()) return false;
        }
    }
    return true;
}


// génération d'une FAUSSE deuxième matrice
bool generateFakeMatrix(int lines, int columns) {
    std::ofstream out("matricetemp.txt");
    if (!out) return false;
    out << lines << " " << columns << "\n";
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < columns; j++) {
            out << (std::rand() % 2) << " ";
        }
        out << "\n";
    }

    return true;
}


// Print de la matrice avec symboles ▓ / ░
void printMatrix(const std::vector<std::vector<int>>& mat) {
    std::cout << "[PARSE] Lecture terminée, affichage de la matrice :\n";
    for (const auto& row : mat) {
        for (int value : row) {
            std::cout << (value ? "▓" : "░");
        }
        std::cout << "\n";
    }
}

int main() {
    std::srand(std::time(nullptr)); // à faire

    std::ifstream file("matrice.txt");
    if (!file) return 1;

    int lines, columns;
    file >> lines >> columns;

    std::vector<std::vector<int>> mat;

    // matrice originale
    if (!loadMatrix(file, mat, lines, columns)) {
        std::cerr << "[PARSE] Erreur: loadMatrix() a échoué.\n";
        return 1;
    }
    printMatrix(mat);


    generateFakeMatrix(lines, columns);

    // 2. Loop: load matrixTemp and print it
    for (int k = 0; k < 3; k++) {   // loop count adjustable
        generateFakeMatrix(lines, columns);
        std::ifstream temp("matricetemp.txt");
        if (!temp) {
            std::cerr << "[PARSE] Impossible d'ouvrir matricetemp.txt\n";
            return 1;
        }

        int tLines, tCols;
        temp >> tLines >> tCols;

        std::vector<std::vector<int>> tempMat;
        if (!loadMatrix(temp, tempMat, tLines, tCols)) {
            std::cerr << "[PARSE] Erreur lors du rechargement.\n";
            return 1;
        }

        std::cout << "\n[PARSE] fake matrice lancée!\n";
        printMatrix(tempMat);
    }

    return 0;
}
