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


#ifndef VIEW3D_H
#define VIEW3D_H

#include <QtOpenGL>
#include <QImage>
#include "map.h"
#include "compass.h"

#define VIEW3D_IX_TEXTURE_CEILING      0
#define VIEW3D_IX_TEXTURE_WALL         1
#define VIEW3D_IX_TEXTURE_DOOR_OPEN    2
#define VIEW3D_IX_TEXTURE_DOOR_CLOSED  3
#define VIEW3D_IX_TEXTURE_FLOOR        4




#define VIEW3D_IX_TEXTURE_CARAPAULO     1
#define VIEW3D_IX_TEXTURE_CARAANTONIO   6
#define VIEW3D_IX_TEXTURE_CARAALEX      7
#define VIEW3D_IX_TEXTURE_CARABRUNO     8
#define VIEW3D_IX_TEXTURE_CARAPEDRO     9
#define VIEW3D_IX_TEXTURE_CHAVE         10
#define VIEW3D_IX_TEXTURE_PORTA         11


#define VIEW3D_IX_TEXTURE_PAREDERISCADA 5

//adicionar depois as novas texturas


//para j�, apenas 6, originalmente 5
#define VIEW3D_TEXTURES_NUMBER         6



class View3D
{
private:
    Map *map;
    GLuint id_textures[ VIEW3D_TEXTURES_NUMBER ];


    static const float piover180 = 0.0174532925f;

//        GLuint texturas[VIEW3D_TEXTURES_NUMBER];

public:


//    bool doFlush ;   //para n�o fazer flush sem raz�o no paint


    View3D( Map *map, const QImage textures[VIEW3D_TEXTURES_NUMBER] );
    // Atencao que "map" pode ser NULL!
    // Para as funcoes OpenGL glTexImage2D() ou gluBuild2DMipmaps(), acedemos
    // 'a largura, altura, formato (GLenum) e dados das imagens com:
    // textures[#].width(), textures[#].height(), GL_RGBA e textures[#].bits()

    void resize( int view_width, int view_height );
    void paint( float x, float y, float compass_direction );


    void paintParede(int x, int z, GLuint textura);
    void paintChao(int x, int z, GLuint texturaBaixo, GLuint texturaCima);

};


#endif // VIEW3D_H
