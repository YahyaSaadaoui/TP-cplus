#  Programmation C++ – TP01  
### Auteur : Yahya Saadaoui  
### Sujet : Dessin et manipulation de dominos en SVG

---

##  Description

Ce projet contient les 4 exercices du **TP01 de Programmation C++**.  
Chaque exercice introduit une nouvelle notion du langage :  
- les **entrées/sorties** et les **arguments de la ligne de commande**,  
- la **manipulation de fichiers**,  
- la **génération d’images SVG**,  
- la **lecture et écriture de structures de données**.

Les programmes produisent des **fichiers SVG** représentant des dominos dessinés en fonction des paramètres fournis.

---

##  Prérequis

- Un **compilateur C++17** (par exemple `g++` ou `clang++`)  
- (Optionnel) un **IDE** comme CLion, VSCode ou Code::Blocks  
- Un **navigateur web** ou un logiciel compatible SVG (Inkscape, GIMP…)  

### Vérifier votre installation :
```bash
g++ --version
````

Si la commande fonctionne, vous êtes prêt à compiler.

---

##  Structure du projet

```
progcpp-TP01-SAADAOUI-mono/
│
├── exercice-1a.cpp      → Génération d’un exemple SVG
├── exercice-1b.cpp      → Dessin d’un domino simple
├── exercice-1c.cpp      → Dessin des 28 dominos
├── exercice-1d.cpp      → Lecture d’un fichier de positions
├── positions.txt        → Exemple de fichier de positions
├── README.md            → Documentation (ce fichier)
└── (sorties SVG)
```

---

##  Compilation

Dans le terminal, depuis le dossier du projet :

```bash
g++ --std=c++17 -Wall exercice-1a.cpp -o exercice-1a
g++ --std=c++17 -Wall exercice-1b.cpp -o exercice-1b
g++ --std=c++17 -Wall exercice-1c.cpp -o exercice-1c
g++ --std=c++17 -Wall exercice-1d.cpp -o exercice-1d
```

Cela génère 4 exécutables :
`exercice-1a`, `exercice-1b`, `exercice-1c`, `exercice-1d`

Sous Windows, ils seront nommés `exercice-1a.exe`, etc.

---

##  Exécution et options

###  1.a — Exemple SVG de base

**Commande :**

```bash
./exercice-1a --exemple-svg image.svg
```

**Résultat :**
Crée le fichier `image.svg` contenant un exemple simple
(rectangle, cercle, ligne, texte...).

Autres options :

```bash
./exercice-1a --help
```

Affiche l’aide disponible.
Si aucun argument n’est fourni, le programme affiche un message d’utilisation.

---

###  1.b — Dessin d’un domino vertical

**Commande :**

```bash
./exercice-1b --domino 3 5 domino35.svg
```

* `3` = nombre de points sur la moitié supérieure
* `5` = nombre de points sur la moitié inférieure
* `domino35.svg` = nom du fichier de sortie

Le programme génère un fichier SVG représentant un domino vertical 3|5.

**Option d’aide :**

```bash
./exercice-1b --help
```

---

###  1.c — Dessin des 28 dominos

**Commande :**

```bash
./exercice-1c --all-dominos all_dominos.svg
```

* Crée un fichier `all_dominos.svg` contenant les **28 dominos** du jeu.
* Chaque domino est positionné dans une grille 7×4,
  centré automatiquement dans une image de 900×600 pixels.

**Option d’aide :**

```bash
./exercice-1c --help
```

---

###  1.d — Fichier de positions

Cet exercice lit un fichier texte décrivant des positions de dominos
et génère une image SVG correspondante.

#### Format du fichier de positions (`positions.txt`)

```
a b is_vertical grid_x grid_y
```

* `a` et `b` : nombres de points du domino
* `is_vertical` : `1` pour vertical, `0` pour horizontal
* `grid_x`, `grid_y` : position du centre du domino sur une grille
  (chaque unité de grille = DOMINO_SIDE / 2 = 40 pixels)

#### Exemple :

```
0 0 1 3 3
1 2 0 5 3
3 6 1 7 5
4 4 1 9 7
6 6 0 11 9
```

#### Commande :

```bash
./exercice-1d --from-positions positions.txt dominos_from_file.svg
```

**Résultat :**

* Lit le fichier `positions.txt`
* Dessine chaque domino à sa position correspondante
* Produit l’image `dominos_from_file.svg`

**Option d’aide :**

```bash
./exercice-1d --help
```

---

##  Visualiser les SVG

Les fichiers SVG générés peuvent être ouverts avec :

* un **navigateur web** : double-cliquez sur le fichier,
* ou **Inkscape**, **GIMP**, etc.

---

##  Débogage

Le programme `exercice-1d` affiche les dominos lus du fichier `positions.txt` :

```
Lu: 0|0 V (3,3)
Lu: 1|2 H (5,3)
Lu: 3|6 V (7,5)
Lu: 4|4 V (9,7)
Lu: 6|6 H (11,9)
```

Cela confirme la lecture correcte du fichier.

---

##  Concepts abordés

| Notion                                       | Exercices |
| -------------------------------------------- | --------- |
| Entrées/sorties (cout, cin, fichiers)        | 1.a – 1.d |
| Arguments de la ligne de commande            | 1.a – 1.d |
| Fichiers SVG et balises XML                  | 1.a – 1.c |
| Constantes globales et passage par référence | 1.c       |
| Structures (`struct`)                        | 1.d       |
| Lecture/écriture de fichiers texte           | 1.d       |

---

## Exemple rapide

```bash
g++ --std=c++17 -Wall exercice-1d.cpp -o exercice-1d
./exercice-1d --from-positions positions.txt dominos_from_file.svg
start dominos_from_file.svg   # (Windows)
# ou
xdg-open dominos_from_file.svg # (Linux)
```

---

© 2025 SAADAOUI YAHYA – Tous droits réservés


