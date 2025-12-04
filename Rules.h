#ifndef TEST_RULES_H
#define TEST_RULES_H

// Règle pour le nombre de cellule maximum et minimum
inline int NB_MAX_CELL = 3;
inline int NB_MIN_CELL = 2;

// Chemin d'accès vers le fichier de sauvegarde et le fichier initial
inline char INIT_FILE_PATH = *"Matrice.txt";
inline char SAVE_FILE_PATH = *"Save.txt";

// Nombre d'itérations nécessaires pour faire une sauvegarde
inline int NB_ITERATIONS = 10;

// Compteur d'itérations
inline int cptIterations = 0;

// Gestion de l'affichage
inline bool UI = false;
inline bool CONSOLE = true;


#endif //TEST_RULES_H
