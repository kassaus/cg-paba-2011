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
#include <cmath>
#include <QtOpenGL>
#include "student_view3d.h"
#include "map.h"
#include "compass.h"


/* Construtor
   Atencao que "map" pode ser NULL!
*/
View3D::View3D( Map *map, const QImage textures[VIEW3D_TEXTURES_NUMBER] )
{
    this->map = map;



    if (map==NULL){
        //ver se temos de fazer clear
        return;
    }

    // Inicializar OpenGL

    GLuint texturas[VIEW3D_TEXTURES_NUMBER];
    glGenTextures(VIEW3D_TEXTURES_NUMBER, texturas);


    for (int i=0; i<VIEW3D_TEXTURES_NUMBER ; i++ ){
        glBindTexture( GL_TEXTURE_2D, texturas[i] );
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); //verificar se são as melhores
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);  //verificar se são as melhores
        gluBuild2DMipmaps(GL_TEXTURE_2D, 3, textures[i].width(), textures[i].height(), GL_RGBA, GL_UNSIGNED_BYTE, textures[i].bits());
    }


    glEnable(GL_TEXTURE_2D);
    glShadeModel(GL_SMOOTH);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);

    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    glFrontFace( GL_CCW );
//    glCullFace( GL_BACK );
//    glEnable(GL_CULL_FACE);
//ligar depois, apenas para testar se funciona!







}




/* Metodo chamado quando a janela do jogo e' redimensionada, pelo que deve ser
   usado para (re-)configurar o OpenGL para uma nova dimensao da janela do
   jogo (ve^ glViewport()).
   Tambem e' chamado no arranque, logo apos o construtor.
   Atencao que "this->map" pode ser NULL!


   o gluPerspective faz-se aqui!

*/
void View3D::resize( int view_width, int view_height )
{

            if( view_width  < 1 )  view_width  = 1;
            if( view_height < 1 )  view_height = 1;

            glViewport( 0, 0, view_width, view_height );

//            glViewport( 0, 0, 150, 150 );
//            //glViewport( 0, 0, (GLint)width, (GLint)height );

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            //gluOrtho2D( -5 , 5, -5 , 5 );
            gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();



}


/* Desenha a vista com centro em x,y e orientacao compass_direction
   (que podem ser todos numeros reais para animacao de movimento).
   Atencao que "this->map" pode ser NULL!
*/
void View3D::paint( float x, float y, float compass_direction )
{




    //para pintar as texturas certas
    if(c.isWall())
        glColor3ub( VIEWMAP_COLOR_3UB_WALL );

    if(c.isFloor())
        glColor3ub( VIEWMAP_COLOR_3UB_FLOOR );

    if(c.players !=0)
        glColor3ub( VIEWMAP_COLOR_3UB_PLAYER1 );


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


/* para pintar uma parede
    recebe      as coordenadas de onde vai partir, o x e o z (y é sempre entre 0 e 1)
                a textura que vai aplicar

    vai fazer um cubo, apenas as laterais, com os pontos em CCW, usando a textura com o index recebido

*/
void View3D::paintParede(int x, int z, GLuint textura)
{

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
    //será preciso????

    int y = 0; //apenas para se quizermos alterar a "altura"

    glBindTexture(GL_TEXTURE_2D, texturas[textura]);

    glBegin(GL_QUADS);

    //frente
    glVertex3f( x + 0.0f, y + 0.0f, z + 0.0f);
    glVertex3f( x + 1.0f, y + 0.0f, z + 0.0f);
    glVertex3f( x + 1.0f, y + 1.0f, z + 0.0f);
    glVertex3f( x + 0.0f, y + 1.0f, z + 0.0f);


    //lado direito
    glVertex3f( x + 1.0f, y + 0.0f, z + 0.0f);
    glVertex3f( x + 1.0f, y + 1.0f, z + 0.0f);
    glVertex3f( x + 1.0f, y + 1.0f, z + 1.0f);
    glVertex3f( x + 1.0f, y + 1.0f, z + 0.0f);


    //fundo
    glVertex3f( x + 1.0f, y + 1.0f, z + 0.0f);
    glVertex3f( x + 0.0f, y + 0.0f, z + 1.0f);
    glVertex3f( x + 0.0f, y + 1.0f, z + 1.0f);
    glVertex3f( x + 1.0f, y + 1.0f, z + 1.0f);


    //lado esquerdo
    glVertex3f( x + 0.0f, y + 0.0f, z + 1.0f);
    glVertex3f( x + 0.0f, y + 0.0f, z + 0.0f);
    glVertex3f( x + 0.0f, y + 1.0f, z + 0.0f);
    glVertex3f( x + 0.0f, y + 1.0f, z + 1.0f);



    glEnd();


}




}
