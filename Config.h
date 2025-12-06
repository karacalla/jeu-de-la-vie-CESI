#pragma once
#include <string>

using namespace std;

// Chemin d'accès vers le fichier de sauvegarde et le fichier initial
inline string INIT_FILE_PATH = "";
inline string SAVE_FILE_PATH = "";

// Nombre d'itérations nécessaires pour faire une sauvegarde
inline int NB_IT_SAVE = 10;

// Compteur d'itérations
inline int cptIterations = 0;

// Gestion de l'affichage
inline bool UI = true;
inline bool CONSOLE = false;

// Taille des cellules pour l'affichage graphique
inline int CELL_SIZE = 10;

// Nombre d'itération possible
inline int NB_ITERATIONS = 0;

// Temps d'attente entre chaque itérations
inline int TIME = 10;
