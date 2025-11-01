// Programmation C++ : TP01
// Exercice 1.d
// Auteur : Yahya Saadaoui

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

// Reuse constants from 1.c
const int IMAGE_WIDTH  = 900;
const int IMAGE_HEIGHT = 600;
const int DOMINO_SIDE  = 80;
const int STROKE_WIDTH = 3;
const char* COLOR_DOMINO = "white";
const char* COLOR_BORDER = "black";
const char* COLOR_PIP    = "black";

// -------------
// Structure
// -------------
struct DominoPosition {
    int a;
    int b;
    bool is_vertical;
    int grid_x;
    int grid_y;
};

// -------------
// SVG utilities
// -------------
void write_preamble_svg(std::ofstream& f) {
    // MIME type : image/svg+xml
    f << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    f << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\" "
      << "width=\"" << IMAGE_WIDTH << "\" height=\"" << IMAGE_HEIGHT << "\">\n";
}

void write_postamble_svg(std::ofstream& f) {
    f << "</svg>\n";
}

// Draw pips
void write_pips(std::ofstream& f, int n, int cx, int cy, int offset, const char* color) {
    const int r = 6;
    const int half = DOMINO_SIDE / 2;
    const int dx = half / 2;
    const int dy = half / 2;

    int x_left   = cx - dx;
    int x_right  = cx + dx;
    int y_top    = cy - half + dy + offset;
    int y_bottom = cy + offset + dy;

    switch (n) {
    case 1:
        f << "  <circle cx=\"" << cx << "\" cy=\"" << cy + offset
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        break;
    case 2:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        break;
    case 3:
        f << "  <circle cx=\"" << cx << "\" cy=\"" << cy + offset
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        break;
    case 4:
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        break;
    case 5:
        f << "  <circle cx=\"" << cx << "\" cy=\"" << cy + offset
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_top
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_left << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        f << "  <circle cx=\"" << x_right << "\" cy=\"" << y_bottom
          << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        break;
    case 6:
        for (int i = -1; i <= 1; ++i) {
            f << "  <circle cx=\"" << x_left + (i+1)*dx << "\" cy=\""
              << y_top << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
            f << "  <circle cx=\"" << x_left + (i+1)*dx << "\" cy=\""
              << y_bottom << "\" r=\"" << r << "\" fill=\"" << color << "\" />\n";
        }
        break;
    }
}

// Draw one domino
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
        write_pips(f, a, cx, cy - DOMINO_SIDE / 2, -DOMINO_SIDE / 2, COLOR_PIP);
        write_pips(f, b, cx, cy + DOMINO_SIDE / 2, +DOMINO_SIDE / 2, COLOR_PIP);
    } else {
        write_pips(f, a, cx - DOMINO_SIDE / 2, cy, -DOMINO_SIDE / 2, COLOR_PIP);
        write_pips(f, b, cx + DOMINO_SIDE / 2, cy, +DOMINO_SIDE / 2, COLOR_PIP);
    }
}

// -----------------------------
// Lecture du fichier positions
// -----------------------------
int read_positions_file(const char* filename, DominoPosition dominos[], bool debug)
{
    std::ifstream f(filename);
    if (!f) {
        std::cerr << "Erreur: impossible d'ouvrir " << filename << "\n";
        return 0;
    }

    int count = 0;
    while (f >> dominos[count].a
             >> dominos[count].b
             >> dominos[count].is_vertical
             >> dominos[count].grid_x
             >> dominos[count].grid_y)
    {
        if (debug) {
            std::cout << "Lu: " << dominos[count].a << "|"
                      << dominos[count].b << " "
                      << (dominos[count].is_vertical ? "V" : "H")
                      << " (" << dominos[count].grid_x
                      << "," << dominos[count].grid_y << ")\n";
        }
        ++count;
        if (count >= 28) break;
    }
    f.close();
    return count;
}

// -----------------------------
// Génération à partir du fichier
// -----------------------------
void write_dominos_from_positions_svg(const char* positions_file, const char* svg_file)
{
    DominoPosition dominos[28];
    int n = read_positions_file(positions_file, dominos, true);
    if (n == 0) {
        std::cerr << "Aucune position lue.\n";
        return;
    }

    std::ofstream f(svg_file);
    if (!f) {
        std::cerr << "Erreur: impossible de créer " << svg_file << "\n";
        return;
    }

    write_preamble_svg(f);

    for (int i = 0; i < n; ++i) {
        int cx = dominos[i].grid_x * (DOMINO_SIDE / 2);
        int cy = dominos[i].grid_y * (DOMINO_SIDE / 2);
        write_domino_svg(f,
                         dominos[i].a,
                         dominos[i].b,
                         dominos[i].is_vertical,
                         COLOR_DOMINO,
                         cx, cy);
    }

    write_postamble_svg(f);
    f.close();
}

// -----------------------------
// main
// -----------------------------
int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " --help pour afficher l'aide\n";
        return 0;
    }

    if (std::strcmp(argv[1], "--help") == 0) {
        std::cout << "Options :\n"
                  << "  --from-positions positions.txt image.svg\n";
        return 0;
    }

    if (std::strcmp(argv[1], "--from-positions") == 0) {
        if (argc < 4) {
            std::cerr << "Erreur: arguments manquants\n";
            return 1;
        }
        const char* positions_file = argv[2];
        const char* svg_file = argv[3];
        write_dominos_from_positions_svg(positions_file, svg_file);
        return 0;
    }

    std::cerr << "Option inconnue : " << argv[1] << "\n";
    return 1;
}
