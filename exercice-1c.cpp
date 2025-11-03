// Programmation C++ : TP01
// Exercice 1.c
// Auteur : Yahya Saadaoui

#include <iostream>
#include <fstream>
#include <cstring>


// ----------------------
// 1. Constantes globales
// ----------------------
const int IMAGE_WIDTH  = 900;
const int IMAGE_HEIGHT = 600;
const int DOMINO_SIDE  = 80;
const int STROKE_WIDTH = 3;
const char* COLOR_DOMINO = "white";
const char* COLOR_BORDER = "black";
const char* COLOR_PIP    = "black";

// ----------------------
// 2. Fonctions de base
// ----------------------

void write_preamble_svg(std::ofstream& f)
{
    f << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    f << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" "
      << "width=\"" << IMAGE_WIDTH << "\" height=\"" << IMAGE_HEIGHT << "\">\n";
    f << "  <title>Tous les dominos</title>\n";
}

void write_postamble_svg(std::ofstream& f)
{
    f << "</svg>\n";
}

void write_pips(std::ofstream& f, int n, int cx, int cy)
{
    const int r = 6;
    const int half = DOMINO_SIDE / 2;
    const int gap = half / 2;
    int x_left  = cx - gap;
    int x_mid   = cx;
    int x_right = cx + gap;
    int y_top   = cy - gap;
    int y_mid   = cy;
    int y_bottom= cy + gap;

    switch (n) {
    case 1:
        f << "  <circle cx=\"" << x_mid << "\" cy=\"" << y_mid
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        break;
    case 2:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        break;
    case 3:
        f << "  <circle cx=\"" << x_mid << "\" cy=\"" << y_mid
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        break;
    case 4:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        break;
    case 5:
        f << "  <circle cx=\"" << x_mid << "\" cy=\"" << y_mid
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        break;
    case 6:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_mid << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_mid << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << COLOR_PIP << "\" />\n";
        break;
    }
}


// ----------------------
// 3. Écrit un domino
// ----------------------
void write_domino_svg(std::ofstream& f, int a, int b, bool vertical,
                      const char* color, int cx, int cy)
{
    const int w = vertical ? DOMINO_SIDE : 2 * DOMINO_SIDE;
    const int h = vertical ? 2 * DOMINO_SIDE : DOMINO_SIDE;
    const int x = cx - w / 2;
    const int y = cy - h / 2;


    f << "  <rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << w
      << "\" height=\"" << h << "\" rx=\"10\" ry=\"10\" "
      << "style=\"fill:" << color << ";stroke:" << COLOR_BORDER
      << ";stroke-width:" << STROKE_WIDTH << "\" />\n";

    if (vertical)
        f << "  <line x1=\"" << x << "\" y1=\"" << cy << "\" x2=\""
          << x + w << "\" y2=\"" << cy
          << "\" style=\"stroke:" << COLOR_BORDER
          << ";stroke-width:" << STROKE_WIDTH << "\" />\n";
    else
        f << "  <line x1=\"" << cx << "\" y1=\"" << y << "\" x2=\""
          << cx << "\" y2=\"" << y + h
          << "\" style=\"stroke:" << COLOR_BORDER
          << ";stroke-width:" << STROKE_WIDTH << "\" />\n";

    f << "  <circle cx=\"" << cx << "\" cy=\"" << cy
      << "\" r=\"4\" fill=\"" << COLOR_PIP << "\" />\n";
    if (vertical) {
        write_pips(f, a, cx, cy - DOMINO_SIDE / 2);
        write_pips(f, b, cx, cy + DOMINO_SIDE / 2);

    } else {
        write_pips(f, a, cx, cy - DOMINO_SIDE / 2);
        write_pips(f, b, cx, cy + DOMINO_SIDE / 2);

    }
}

// ----------------------
// 4. Tous les dominos
// ----------------------
void draw_all_dominos_svg(const char* filename)
{
    std::ofstream f(filename);
    if (!f) {
        std::cerr << "Erreur: impossible d'ouvrir " << filename << "\n";
        return;
    }

    write_preamble_svg(f);
    const int cols = 7;
    const int rows = 4;
    const int domino_w = DOMINO_SIDE;
    const int domino_h = 2 * DOMINO_SIDE;
    const int spacing_x = 110;
    const int spacing_y = 140;
    const int grid_w = cols * spacing_x;
    const int grid_h = rows * spacing_y;
    const int margin_x = (IMAGE_WIDTH  - grid_w) / 2;
    const int margin_y = (IMAGE_HEIGHT - grid_h) / 2;

    int cx, cy;
    int index = 0;
    for (int a = 0; a <= 6; ++a) {
        for (int b = 0; b <= a; ++b) {
            int col = index % cols;
            int row = index / cols;
            cx = margin_x + col * spacing_x + domino_w / 2;
            cy = margin_y + row * spacing_y + domino_h / 2;

            write_domino_svg(f, a, b, true, COLOR_DOMINO, cx, cy);
            ++index;
        }
    }

    write_postamble_svg(f);
    f.close();
}


// ----------------------
// 5. Programme principal
// ----------------------
int main(int argc, char* argv[])
{
    if (argc == 1) {
        std::cout << "Usage: " << argv[0] << " --help pour afficher l'aide\n";
        return 0;
    }

    if (std::strcmp(argv[1], "--help") == 0) {
        std::cout << "Options :\n"
                  << "  --help                        affiche l'aide\n"
                  << "  --all-dominos fichier.svg     génère tous les dominos\n";
        return 0;
    }

    if (std::strcmp(argv[1], "--all-dominos") == 0) {
        if (argc < 3) {
            std::cerr << "Erreur: nom de fichier svg attendu\n";
            return 1;
        }
        const char* filename = argv[2];
        std::cout << "Génération de tous les dominos dans "
                  << filename << " ...\n";
        draw_all_dominos_svg(filename);
        return 0;
    }

    std::cerr << "Option inconnue : " << argv[1] << "\n";
    std::cerr << "Utilisez --help pour voir les options.\n";
    return 1;
}
