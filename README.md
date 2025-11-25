# Le Jeu de la Vie

## Partie 1: Une introduction

*"Le tout est plus que la somme des parties."*
Plus de 65 ans après sa création, on s'intéresse toujours au Jeu de la Vie pour ses règles de jeux d'une simplicité trompeuse; en effet, à partir de **4 simples règles**, à partir de motifs paraissant aléatoires, nous pouvons créer une infinité de comportements, avec de nouveaux étant découverts jusqu' aujourd'hui.
---

### Quel est le vocabulaire?

- **grille à deux dimensions**: repère orthonormé à deux dimensions. En programmation, nous pouvons chercher à la représenter par une **matrice**.
Exemple:

<img src='https://i.pinimg.com/564x/4d/56/8e/4d568efd021cbcf82945fab3993dfb72.jpg' width=200px height=auto>

- **cellule**: Une coordonnée sur la grille.

- **voisine**: Les cellules adjacentes à une cellule donnée, sur les axes orthogonaux et diagonaux. 
Par exemple, ici la cellule de centre est entourée par ses voisines.

<img src="https://i.sstatic.net/BXvtK.png" width= 150px>


- (cellule) **morte / vivante**: Les deux états que peuvent être attribués les cellules. C'est sur ces deux états que repose le fonctionnement de notre jeu — soit, nos **règles**. Ces deux états sont *mutuellement exclusifs*. Dans le Jeu de la Vie, l'état des cellules est représenté par un **codage couleur** pour chaque état _(d'habitude noir et blanc)_

- **morte**: Le passage d'une cellule vivante à un état **mort**.
- **naissance**: Le passage d'une cellule morte à un état **vivant**.





