/*
Labirinto para Computacao Grafica (CG).
(C) 2010 Pedro Freire (www.pedrofreire.com)
    Licenca Creative Commons:
    Atribuicao - Uso Nao-Comercial - Partilha nos termos da mesma Licenca
    http://creativecommons.org/licenses/by-nc-sa/2.5/pt/

Computer Graphics Maze.
(C) 2010 Pedro Freire (www.pedrofreire.com)
    All comments in Portuguese.
    Creative Commons license:
    Attribution - Noncommercial - Share Alike
    http://creativecommons.org/licenses/by-nc-sa/2.5/pt/deed.en_US

=============================================================================
#### Podes alterar este ficheiro ############################################
=============================================================================
*/


#ifndef VIEWMAP_H
#define VIEWMAP_H

#include <QtOpenGL>
#include "cell.h"

// Cores
#define VIEWMAP_COLOR_3UB_WALL     0xC9, 0xC9, 0xFF  // 0xB8, 0xB8, 0xF0 / 0x99, 0x99, 0xCB
#define VIEWMAP_COLOR_3UB_FLOOR    0x83, 0x6E, 0x3E  // 0xB1, 0x89, 0x4E / 0x66, 0x4F, 0x2D
#define VIEWMAP_COLOR_3UB_PLAYER1  0xFF, 0x33, 0x33

#define VIEWMAP_COLOR_3UB_PLAYER1POS  0x00, 0xff, 0x00 //***nosso, para apresentar o local do player


//************nosso, para guardar a posi��o actual do jogador
extern int playerX, playerY;

class ViewMap
{
private:
    int map_width;
    int map_height;


public:

    Cell mapStore[1000][1000]; //*****nosso, para guardar o mapa

    bool doFlush ;   //para n�o fazer flush sem raz�o no paint

    ViewMap( int map_width, int map_height );
    void resize( int view_width, int view_height );
    void clear();
    void paint();
    void paint( int x, int y, Cell c );    

};


#endif // VIEWMAP_H
