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

#include "student_viewmap.h"


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

    glGenTextures(VIEW3D_TEXTURES_NUMBER, id_textures);

    for (int i=0; i<VIEW3D_TEXTURES_NUMBER ; i++ ){
        glBindTexture( GL_TEXTURE_2D, id_textures[i] );
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_NEAREST); //verificar se s�o as melhores
        glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR_MIPMAP_NEAREST);  //verificar se s�o as melhores
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

    glCullFace( GL_BACK );
    glEnable(GL_CULL_FACE);
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

            //garantir que a janela tem pelo menos 1 ponto, evitar divis�es por zero
            view_width = view_width?view_width:1;
            view_height = view_height?view_height:1;

            glViewport( 0, 0, view_width, view_height );

            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();

            gluPerspective(45.0f,(GLfloat)view_width/(GLfloat)view_height,0.1f,100.0f);

            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();



}



/* Desenha a vista com centro em x,y e orientacao compass_direction
   (que podem ser todos numeros reais para animacao de movimento).
   Atencao que "this->map" pode ser NULL!
*/
void View3D::paint( float x, float y, float compass_direction )
{



    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();





    /* passar o compass_direction para um angulo em Radianos
            passar o compass_direction para um angulo em rela��o ao eixo x
            transform�-lo em radianos
    */
    float anguloRad = (270.0f - (90.0f * compass_direction))  / 180.0f * 3.141592654;


    /* para cada eixo, calcular o incremento em rela��o ao �ngulo
    */
    float xview = cos(anguloRad);
    float yview = sin(anguloRad);

    /* colocar e apontar a c�mara
            coloc�-la no meio do cubo x,y,z
            apont�-la para o ponto de visualiza��o consoante o compasso
            definir "cima" o eixo posivo z

    */
    gluLookAt( x+0.5f, y+0.5f, 0.5f ,                                               //meio do cubo x,y,z
               x + 0.5f + (xview * 0.5f) , y + 0.5f + (yview * 0.5f)  , 0.5f ,      //ponto do cubo onde apontamos a c�mara
               0, 0, 1 );                                                           //



    Cell c;

    int mx, my;
    for( my = 0; my < map->getHeight(); my++ )
        for( mx = 0; mx < map->getWidth(); mx++ )
        {
            c = map->getCell( mx, my );


            if(c.isWall()){

                paintParede(mx, my, c.hasObject()? (int)c.object : VIEW3D_IX_TEXTURE_WALL);

            }

            else if(c.isFloor()){
                paintChao(mx, my, VIEW3D_IX_TEXTURE_FLOOR, VIEW3D_IX_TEXTURE_CEILING);
            }
            else if(c.isDoor()){
                paintParede(mx, my, VIEW3D_IX_TEXTURE_WALL);
            }
             //ter cuidado  que se for uma porta, estamos ainda apenas a desenhar parede, e n�o ch�o



            else {
                paintParede(mx, my, VIEW3D_IX_TEXTURE_WALL);
            }

    }





}

































/* para pintar uma parede
    recebe      as coordenadas de onde vai partir, o x e o z (y � sempre entre 0 e 1)
                a textura que vai aplicar

    vai fazer um cubo, apenas as laterais, com os pontos em CCW, usando a textura com o index recebido

*/
void View3D::paintParede(int x, int y, GLuint textura)
{

//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//    glLoadIdentity();
    //ser� preciso????

    int z = 0; //apenas se quizermos alterar a "altura"


    /*
        em princ�pio, z ficar� ao "contr�rio"
        dever� ser necess�rio colocar

        z = -z;

        ser� necess�rio colocar as normais, ou apenas para ilumina��o?
    */

    glBindTexture(GL_TEXTURE_2D, id_textures[textura]);

    glBegin(GL_QUADS);


    //frente

        glTexCoord2i(0, 0);
        glVertex3i( x + 0, y + 0, z + 0);

        glTexCoord2i(1, 0);
        glVertex3i( x + 1, y + 0, z + 0);

        glTexCoord2i(1 , 1 );
        glVertex3i( x + 1 , y + 0 , z + 1 );

        glTexCoord2i(0 , 1 );
        glVertex3i( x + 0 , y + 0 , z + 1 );


    //lado direito

        glTexCoord2i(0 , 0 );
        glVertex3i( x + 1 , y + 0 , z + 0 );

        glTexCoord2i(1 , 0 );
        glVertex3i( x + 1 , y + 1, z + 0 );

        glTexCoord2i(1 , 1 );
        glVertex3i( x + 1 , y + 1 , z + 1 );

        glTexCoord2i(0 , 1 );
        glVertex3i( x + 1 , y + 0 , z + 1 );


    //fundo

        glTexCoord2i(0 , 0 );
        glVertex3i( x + 1 , y + 1 , z + 0 );

        glTexCoord2i(1 , 0 );
        glVertex3i( x + 0 , y + 1 , z + 0 );

        glTexCoord2i(1 , 1 );
        glVertex3i( x + 0 , y + 1 , z + 1 );

        glTexCoord2i(0 , 1 );
        glVertex3i( x + 1 , y + 1 , z + 1 );


    //lado esquerdo

        glTexCoord2i(0 , 0 );
        glVertex3i( x + 0 , y + 1 , z + 0 );

        glTexCoord2i(1 , 0 );
        glVertex3i( x + 0 , y + 0 , z + 0 );

        glTexCoord2i(1 , 1 );
        glVertex3i( x + 0 , y + 0 , z + 1 );

        glTexCoord2i(0 , 1 );
        glVertex3i( x + 0 , y + 1 , z + 1 );

    glEnd();


}






/* para pintar ch�o
    recebe      as coordenadas de onde vai partir, o x e o z (y � sempre entre 0 e 1)
                a textura que vai aplicar

    vai fazer apenas o ch�o e tecto, com os pontos em CCW, usando a textura com o index recebido

    neste caso, as texturas v�o ficar para "dentro", tecto e ch�o

*/
void View3D::paintChao(int x, int y, GLuint texturaBaixo, GLuint texturaCima)
{


    int z = 0; //apenas se quizermos alterar a "altura"

    //cima, textura virada para baixo

    glBindTexture(GL_TEXTURE_2D, id_textures[texturaCima]);

    glBegin(GL_QUADS);

        glTexCoord2i(0 , 0 );
        glVertex3i( x + 0 , y + 0 , z + 1 );

        glTexCoord2i(1 , 0 );
        glVertex3i( x + 0 , y + 1 , z + 1 );

        glTexCoord2i(1 , 1 );
        glVertex3i( x + 1 , y + 1 , z + 1 );

        glTexCoord2i(0 , 1 );
        glVertex3i( x + 1 , y + 0 , z + 1 );

    glEnd();




    //baixo, textura virada para cima

    glBindTexture(GL_TEXTURE_2D, id_textures[texturaBaixo]);

    glBegin(GL_QUADS);

        glTexCoord2i(0 , 0 );
        glVertex3i( x + 0 , y + 0 , z + 0 );

        glTexCoord2i(1 , 0 );
        glVertex3i( x + 1 , y + 0 , z + 0 );

        glTexCoord2i(1 , 1 );
        glVertex3i( x + 1 , y + 1 , z + 0 );

        glTexCoord2i(0 , 1 );
        glVertex3i( x + 0 , y + 1 , z + 0 );

    glEnd();


}

