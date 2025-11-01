// Programmation C++ : TP01
// Exercice 1.b
// Auteur : Yahya Saadaoui

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

void write_pips(std::ofstream &f, int n, int y_offset)
{
    const int x_center = 60;
    const int y_center = y_offset + 50;

    const int x_left   = 30;
    const int x_right  = 90;
    const int y_top    = y_offset + 25;
    const int y_bottom = y_offset + 75;

    switch (n) {
    case 0:
        break;
    case 1:
        f << "  <circle cx=\"" << x_center << "\" cy=\""
          << y_center << "\" r=\"6\" fill=\"black\" />\n";
        break;
    case 2:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        break;
    case 3:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_center << "\" cy=\"" << y_center
          << "\" r=\"6\" fill=\"black\" />\n";
        break;
    case 4:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        break;
    case 5:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_center << "\" cy=\"" << y_center
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        break;
    case 6:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_center << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_top
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_center << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"6\" fill=\"black\" />\n";
        break;
    }
}

void write_domino_svg(const char *filename, int a, int b)
{
    std::ofstream f(filename);
    if (!f) {
        std::cerr << "Erreur: impossible de créer le fichier "
                  << filename << "\n";
        return;
    }

    f << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    f << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" "
      << "width=\"140\" height=\"260\">\n";
    f << "  <title>Domino " << a << "|" << b << "</title>\n";

    f << "  <rect x=\"10\" y=\"10\" width=\"120\" height=\"240\" "
      << "rx=\"15\" ry=\"15\" "
      << "style=\"fill:white;stroke:black;stroke-width:3\" />\n";

    f << "  <line x1=\"10\" y1=\"130\" x2=\"130\" y2=\"130\" "
      << "style=\"stroke:black;stroke-width:3\" />\n";

    f << "  <circle cx=\"70\" cy=\"130\" r=\"5\" fill=\"black\" />\n";

    write_pips(f, a, 10);

    write_pips(f, b, 130);

    f << "</svg>\n";
    f.close();
}

int main(int argc, char* argv[])
{
    if (argc == 1) {
        std::cout << "Usage: " << argv[0]
                  << " --help pour afficher l'aide\n";
        return 0;
    }

    if (std::strcmp(argv[1], "--help") == 0) {
        std::cout << "Options :\n"
                  << "  --help                       affiche l'aide\n"
                  << "  --exemple-svg fichier.svg    écrit un exemple en SVG\n"
                  << "  --domino a b fichier.svg     écrit le domino a|b en SVG\n";
        return 0;
    }

    if (std::strcmp(argv[1], "--exemple-svg") == 0) {
        if (argc < 3) {
            std::cerr << "Erreur: nom de fichier svg attendu\n";
            return 1;
        }
        const char* filename = argv[2];
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Erreur: impossible de créer " << filename << "\n";
            return 1;
        }
        file << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
        file << "<svg xmlns=\"http://www.w3.org/2000/svg\" "
             << "version=\"1.1\" width=\"300\" height=\"200\">\n";
        file << "  <title>Exemple simple de figure SVG</title>\n";
        file << "  <desc>\n";
        file << "    Cette figure est constituée d'un rectangle,\n";
        file << "    d'un segment de droite et d'un cercle.\n";
        file << "  </desc>\n";
        file << "  <line x1=\"5\" y1=\"5\" x2=\"250\" y2=\"95\" "
             << "stroke=\"red\" />\n";
        file << "  <circle cx=\"110\" cy=\"80\" r=\"50\" fill=\"blue\" />\n";
        file << "  <rect width=\"100\" height=\"80\" x=\"10\" y=\"80\" "
             << "rx=\"10\" ry=\"10\" "
             << "style=\"fill:rgb(200,200,200);stroke-width:2;"
             << "stroke:black\" />\n";
        file << "  <text x=\"180\" y=\"60\">Un texte</text>\n";
        file << "</svg>\n";
        file.close();
        return 0;
    }

    if (std::strcmp(argv[1], "--domino") == 0) {
        if (argc < 5) {
            std::cerr << "Erreur: il faut 2 nombres et un nom de fichier\n";
            return 1;
        }

        int a = std::atoi(argv[2]);
        int b = std::atoi(argv[3]);
        const char* filename = argv[4];

        if (a < 0 || a > 6 || b < 0 || b > 6) {
            std::cerr << "Erreur: a et b doivent être entre 0 et 6\n";
            return 1;
        }

        std::cout << "Génération du domino " << a
                  << "|" << b << " dans " << filename << " ...\n";
        write_domino_svg(filename, a, b);
        return 0;
    }

    std::cerr << "Erreur: option inconnue '" << argv[1] << "'\n";
    std::cerr << "Utilisez --help pour voir les options.\n";
    return 1;
}
