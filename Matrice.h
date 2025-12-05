#ifndef TEST_MATRICE_H
#define TEST_MATRICE_H
#include <vector>
using namespace std;

class Matrice {
    private:
    int row, column;
    public:
    vector<vector<int>> matrice;
    vector<vector<int>> buffer;

    Matrice();
    ~Matrice();

    const int getRow();
    const int getColumn();

    void createMatrice();
    void saveMatrice();
};


#endif //TEST_MATRICE_H
