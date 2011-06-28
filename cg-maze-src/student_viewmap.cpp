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


#include <cassert>
#include <cstring>
#include <QtOpenGL>
#include "student_viewmap.h"
#include "cell.h"

int playerX = 0, playerY = 0;

/* Construtor
*/
ViewMap::ViewMap( int map_width, int map_height )
{

    //inicializar as variáveis da classe com os valores recebidos
         this->map_width = map_width;
         this->map_height = map_height;

    //inicializar o flush
         doFlush = true;





    // Inicializar OpenGL

        glShadeModel( GL_SMOOTH );
        glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
        glDisable( GL_DEPTH_TEST );

        //carregar a matriz de projecção
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        //valores esq, dir, baixo,
        gluOrtho2D( 0, map_width, 0, map_height );

        //carregar a matriz de transformação
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

}


/* Metodo chamado quando a janela do jogo e' redimensionada, pelo que deve ser
   usado para (re-)configurar o OpenGL para uma nova dimensao da janela do
   jogo (ve^ glViewport()).
   Tambem e' chamado no arranque, logo apos o construtor.
*/
void ViewMap::resize( int view_width, int view_height )
{
    glViewport(0, 0, view_width, view_height);
    glClear( GL_COLOR_BUFFER_BIT );

}


/* (Re-)desenhar o mapa todo.
*/
void ViewMap::paint()
{
    /*
    dicas do professor

    o paint com argumentos tem de guardar o que já foi feito
    guardar matriz
                x, y, cell
*/

    int x;
    int y;

    doFlush = false;

    for (x=0; x < map_width; x++){

        for (y=0; y <map_height; y++){
            paint( x, y, mapStore[x][y] );
        }

    }

    doFlush = true;

    glFlush();



    /* Util para verificar se o labirinto esta' a ser devidamente gerado
    char line[map_width*2+1];
    qDebug( "\nFull paint:" );
    line[map_width*2] = '\0';
    for( y = map_height-1;  y >= 0;  y-- )
	{
	for( x = 0;  x < map_width;  x++ )
	    line[x*2+1] = line[x*2] = map_painted[convCoord(x,y)].isWallOrDoor() ? '$' : '_';
	qDebug( line );
	}
    qDebug( " " );
    */
}


/* Desenhar uma celula do mapa
*/
void ViewMap::paint( int x, int y, Cell c )
{


    if(c.isWall())
        glColor3ub( VIEWMAP_COLOR_3UB_WALL );

    if(c.isFloor())
        glColor3ub( VIEWMAP_COLOR_3UB_FLOOR );

    if(c.players !=0)
        glColor3ub( VIEWMAP_COLOR_3UB_PLAYER1 );

    if ( (playerX == x) && (playerY == y)){
        glColor3ub( VIEWMAP_COLOR_3UB_PLAYER1POS );
    }



    glBegin(GL_QUADS);
        glVertex3f( x, y, 0.0f);
        glVertex3f( x+1, y, 0.0f);
        glVertex3f( x+1, y+1, 0.0f);
        glVertex3f( x, y+1, 0.0f);
    glEnd();


    if (doFlush)
        glFlush();

    //guarda a cell no array;
    mapStore[x][y]=c;




}








/* Limpar a area de desenho do mapa.
*/
void ViewMap::clear()
{
}
