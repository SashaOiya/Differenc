#ifndef LATEX
#define LATEX

#include "front.h"
#include <stdio.h>

#define print_latex_start(latex_file) fprintf ( latex_file, "\\documentclass{article}\n" \
                                                            "\\usepackage{amsmath, amsfonts, amssymb, amsthm, mathtools}\n " \
                                                            "\\usepackage{physics}\n"    \
                                                            "\\begin{document}\n" );
                                                            //"\\[" );

#define print_latex_close(latex_file) fprintf ( latex_file, "\\end{document}\n" );

void Latex_Op         ( Node_t* node, FILE* latex_file );
void Put_Op           ( Node_t* node, FILE* latex_file );
void Print_Latex      ( Node_t* node, FILE* latex_file );
void Print_Latex_Body ( Node_t* node, FILE* latex_file );
void Put_Brackets     ( Node_t* node, FILE* latex_file, char bracket_type);

#endif     // LATEX
