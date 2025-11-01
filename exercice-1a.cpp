// Programmation C++ : TP01
// Exercice 1.a
// Auteur : Yahya Saadaoui
// Date : 31 octobre 2025
#include <iostream>
#include <fstream>
#include <cstring>

int main(int argc, char* argv[]) {
    if (argc == 1) {
        std::cout << "Usage: " << argv[0] << " --help pour afficher l'aide\n";
        return 0;
    }

    if (std::strcmp(argv[1], "--help") == 0) {
        std::cout << "Options:\n"
                  << "  --help                   affiche l'aide\n"
                  << "  --exemple-svg fichier    écrit un exemple en SVG\n";
        return 0;
    }
    else if (std::strcmp(argv[1], "--exemple-svg") == 0) {
        if (argc < 3) {
            std::cerr << "Erreur: nom de fichier svg attendu\n";
            return 1;
        }

        const char* filename = argv[2];
        std::cout << "Génération de " << filename << " ...\n";
        std::ofstream file(filename);

        if (!file) {
            std::cerr << "Erreur: impossible d'ouvrir le fichier " << filename << " pour écriture\n";
            return 1;
        }

        file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
        file << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" width=\"300\" height=\"200\">\n";
        file << "  <title>Exemple simple de figure SVG</title>\n";
        file << "  <desc>\n";
        file << "    Cette figure est constituée d'un rectangle,\n";
        file << "    d'un segment de droite et d'un cercle.\n";
        file << "  </desc>\n\n";
        file << "  <line x1=\"5\" y1=\"5\" x2=\"250\" y2=\"95\" stroke=\"red\" />\n";
        file << "  <circle cx=\"110\" cy=\"80\" r=\"50\" fill=\"blue\" />\n";
        file << "  <rect width=\"100\" height=\"80\" x=\"10\" y=\"80\" rx=\"10\" ry=\"10\"\n";
        file << "        style=\"fill:rgb(200,200,200);stroke-width:2;stroke:black\" />\n";
        file << "  <text x=\"180\" y=\"60\">Un texte</text>\n";
        file << "</svg>\n";
        file.close();
        return 0;
    }
    else {
        std::cerr << "Option inconnue: " << argv[1] << "\n";
        std::cout << "Utilisez --help pour afficher l'aide.\n";
        return 1;
    }
}
