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

//    if (map!=NULL){
//        this->map = map;
//    } else {
//        //ver se temos de fazer clear
//        return;
//    }


    //carregar as texturas
    glGenTextures(VIEW3D_TEXTURES_NUMBER, id_textures);

    for (int i=0; i<VIEW3D_TEXTURES_NUMBER ; i++ ){
        glBindTexture( GL_TEXTURE_2D, id_textures[i] );
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

    glCullFace( GL_BACK );
    glEnable(GL_CULL_FACE);







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

        //garantir que a janela tem pelo menos 1 ponto, evitar divisões por zero
        view_width = view_width ? view_width : 1;
        view_height = view_height ? view_height : 1;

        glViewport( 0, 0, view_width, view_height );

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();

        //para o frustrum de perspectiva
        float altura = map->getHeight();
        float largura = map->getWidth();
        float profMax = (altura > largura) ? altura+1 : largura+1;

        gluPerspective( 45.0f,(GLfloat)view_width/(GLfloat)view_height ,0.1f , profMax);

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
            passar o compass_direction para um angulo em relação ao eixo x
            transformá-lo em radianos
    */
    float anguloRad = (270.0f - (90.0f * compass_direction))  / 180.0f * 3.141592654;


    /* para cada eixo, calcular o incremento em relação ao ângulo
    */
    float xview = cos(anguloRad);
    float yview = sin(anguloRad);


    /* colocar e apontar a câmara
            colocá-la no meio do cubo x,y,z
            apontá-la para o ponto de visualização consoante o compasso
            definir "cima" o eixo posivo z
    */
    gluLookAt( x+0.5f, y+0.5f, 0.5f ,
               x + 0.5f + (xview * 0.5f) , y + 0.5f + (yview * 0.5f)  , 0.5f ,
               0, 0, 1 );


    Cell c;
    int mx, my;
    int distanciaMax = 100;

    int paredeXmin = x;
    int paredeYmin = y;
    int paredeXmax = x;
    int paredeYmax = y;





    /*para procurar centrado na célula certa, temos de avançar .5 em relação a x,y
    */
    float difCentro = 0.5f;



    if (  !(compass_direction <0.5 && compass_direction >=3.5) ){
        //procura parede para NORTE
        do {
            c = map->getCell( x + difCentro, paredeYmax );
            paredeYmax++;
        } while ( !c.isWallOrClosed());

        //paint NORTE
        paintIntervalos(x-2, y+5 , x+2 , paredeYmax);
    }



    if ( !(compass_direction >=1.5 && compass_direction <=2.5) ){
        //procura parede para SUL
        do {
            c = map->getCell( x + difCentro, paredeYmin );
            paredeYmin--;
        } while ( !c.isWallOrClosed());

        //paint SUL
        paintIntervalos(x-2 , paredeYmin , x+2 , y -5);
    }


    if ( !(compass_direction >=0.5 && compass_direction <=1.5) ){
        //procura parede para ESTE
        do {
            c = map->getCell( paredeXmax, y + difCentro );
            paredeXmax++;
        } while ( !c.isWallOrClosed());

        //paint ESTE
        paintIntervalos(x+5 , y-2 , paredeXmax , y+2);
    }


    if ( !(compass_direction >=2.5 && compass_direction <=3.5) ){
        //procura parede para OESTE
        do {
            c = map->getCell( paredeXmin, y + difCentro );
            paredeXmin--;
        } while ( !c.isWallOrClosed());

        //paint OESTE
        paintIntervalos(paredeXmin , y-2 , x -5 , y+2);
    }


    // paint à volta do x,y
    paintIntervalos(x - 5 , y-5 , x +5 , y+5);


}









/*
*/
void View3D::paintIntervalos( float xMin, float yMin, float xMax, float yMax )
{
    Cell celula;
    int mx;
    int my;

    for( my = (int)yMin ; my <= (int)yMax ; my++ )
        for( mx = (int)xMin ; mx <= (int)xMax ; mx++ )
        {



        celula = map->getCell( mx, my );


        if(celula.isWall()){

            paintParede(mx, my, celula.hasObject()? (int)celula.object : VIEW3D_IX_TEXTURE_WALL);

        }

        else if(celula.isFloor()){

            paintChao(mx, my, (celula.hasObject()? (int)celula.object : VIEW3D_IX_TEXTURE_FLOOR) , VIEW3D_IX_TEXTURE_CEILING);

        }
        else if(celula.isDoor()){
            paintParede(mx, my, VIEW3D_IX_TEXTURE_WALL);
        }
         //ter cuidado  que se for uma porta, estamos ainda apenas a desenhar parede, e não chão



        else {
            paintParede(mx, my, VIEW3D_IX_TEXTURE_WALL);
        }

}

}




















/* para pintar uma parede
    recebe      as coordenadas de onde vai partir, o x e o y (z é a "altura")
                a textura que vai aplicar

    vai fazer um cubo, apenas as laterais, com os pontos em CCW, usando a textura com o index recebido

*/
void View3D::paintParede(int x, int y, GLuint textura)
{

    int z = 0; //apenas se quizermos alterar a "altura"

    glBindTexture(GL_TEXTURE_2D, id_textures[textura]);

    glBegin(GL_QUADS);

    //frente
//        glNormal3i( 0, -1, 0);
        glTexCoord2i(0, 0); glVertex3i( x + 0, y + 0, z + 0);
        glTexCoord2i(1, 0); glVertex3i( x + 1, y + 0, z + 0);
        glTexCoord2i(1, 1); glVertex3i( x + 1, y + 0, z + 1);
        glTexCoord2i(0, 1); glVertex3i( x + 0, y + 0, z + 1);

    //lado direito
//        glNormal3i( 1, 0, 0);
        glTexCoord2i(0, 0); glVertex3i( x + 1, y + 0, z + 0);
        glTexCoord2i(1, 0); glVertex3i( x + 1, y + 1, z + 0);
        glTexCoord2i(1, 1); glVertex3i( x + 1, y + 1, z + 1);
        glTexCoord2i(0, 1); glVertex3i( x + 1, y + 0, z + 1);

    //fundo
//        glNormal3i( 0, 1, 0);
        glTexCoord2i(0, 0); glVertex3i( x + 1, y + 1, z + 0);
        glTexCoord2i(1, 0); glVertex3i( x + 0, y + 1, z + 0);
        glTexCoord2i(1, 1); glVertex3i( x + 0, y + 1, z + 1);
        glTexCoord2i(0, 1); glVertex3i( x + 1, y + 1, z + 1);

    //lado esquerdo
//        glNormal3i( -1, 0, 0);
        glTexCoord2i(0, 0); glVertex3i( x + 0, y + 1, z + 0);
        glTexCoord2i(1, 0); glVertex3i( x + 0, y + 0, z + 0);
        glTexCoord2i(1, 1); glVertex3i( x + 0, y + 0, z + 1);
        glTexCoord2i(0, 1); glVertex3i( x + 0, y + 1, z + 1);

    glEnd();


}






/* para pintar chão
    recebe      as coordenadas de onde vai partir, o x e o y (z é a "altura")
                a textura que vai aplicar

    vai fazer apenas o chão e tecto, com os pontos em CCW, usando a textura com o index recebido

    neste caso, as texturas vão ficar para "dentro", tecto e chão

*/
void View3D::paintChao(int x, int y, GLuint texturaBaixo, GLuint texturaCima)
{

    int z = 0; //apenas se quizermos alterar a "altura"

    //cima, textura virada para baixo

    glBindTexture(GL_TEXTURE_2D, id_textures[texturaCima]);

    glBegin(GL_QUADS);
//        glNormal3i( 0, 0, -1);
        glTexCoord2i(0, 0); glVertex3i( x + 0, y + 0, z + 1);
        glTexCoord2i(1, 0); glVertex3i( x + 0, y + 1, z + 1);
        glTexCoord2i(1, 1); glVertex3i( x + 1, y + 1, z + 1);
        glTexCoord2i(0, 1); glVertex3i( x + 1, y + 0, z + 1);
    glEnd();


    //baixo, textura virada para cima

    glBindTexture(GL_TEXTURE_2D, id_textures[texturaBaixo]);

    glBegin(GL_QUADS);
//        glNormal3i( 0, 0, 1);
        glTexCoord2i(0, 0); glVertex3i( x + 0, y + 0, z + 0);
        glTexCoord2i(1, 0); glVertex3i( x + 1, y + 0, z + 0);
        glTexCoord2i(1, 1); glVertex3i( x + 1, y + 1, z + 0);
        glTexCoord2i(0, 1); glVertex3i( x + 0, y + 1, z + 0);
    glEnd();

}

