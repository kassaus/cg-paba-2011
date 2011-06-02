/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 2. Jun 11:48:55 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDial>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include "view_gl.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QHBoxLayout *horiz;
    QTabWidget *tabSet;
    QWidget *tabMap;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_5;
    ViewMapGL *glViewMap;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pushNew;
    QSpacerItem *horizontalSpacer_2;
    QWidget *tabFP2D;
    QVBoxLayout *verticalLayout_3;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_6;
    View2DGL *glView2D;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushTurnLeft2D;
    QPushButton *pushMoveFwd2D;
    QPushButton *pushTurnRight2D;
    QSpacerItem *horizontalSpacer;
    QWidget *tabFP3D;
    QVBoxLayout *verticalLayout_7;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_8;
    View3DGL *glView3D;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *pushTurnLeft3D;
    QPushButton *pushMoveFwd3D;
    QPushButton *pushTurnRight3D;
    QSpacerItem *horizontalSpacer_10;
    QWidget *tabAbout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QDial *dialCompass;
    QLabel *label_3;
    QSpacerItem *verticalSpacer;
    QMenuBar *menubar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(640, 430);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/mainwindow/imgs/mainwindow.icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        horiz = new QHBoxLayout();
        horiz->setObjectName(QString::fromUtf8("horiz"));
        tabSet = new QTabWidget(centralwidget);
        tabSet->setObjectName(QString::fromUtf8("tabSet"));
        tabSet->setEnabled(true);
        tabSet->setContextMenuPolicy(Qt::NoContextMenu);
        tabSet->setTabPosition(QTabWidget::South);
        tabSet->setTabShape(QTabWidget::Rounded);
        tabSet->setElideMode(Qt::ElideNone);
        tabSet->setUsesScrollButtons(false);
        tabMap = new QWidget();
        tabMap->setObjectName(QString::fromUtf8("tabMap"));
        verticalLayout_2 = new QVBoxLayout(tabMap);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(tabMap);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Box);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout_5 = new QVBoxLayout(frame);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        glViewMap = new ViewMapGL(frame);
        glViewMap->setObjectName(QString::fromUtf8("glViewMap"));
        glViewMap->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_5->addWidget(glViewMap);


        verticalLayout_2->addWidget(frame);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);

        pushNew = new QPushButton(tabMap);
        pushNew->setObjectName(QString::fromUtf8("pushNew"));
        pushNew->setMinimumSize(QSize(0, 26));
        pushNew->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout_2->addWidget(pushNew);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout_2->addLayout(horizontalLayout_2);

        tabSet->addTab(tabMap, QString());
        tabFP2D = new QWidget();
        tabFP2D->setObjectName(QString::fromUtf8("tabFP2D"));
        tabFP2D->setEnabled(true);
        verticalLayout_3 = new QVBoxLayout(tabFP2D);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        frame_2 = new QFrame(tabFP2D);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::Box);
        frame_2->setFrameShadow(QFrame::Plain);
        verticalLayout_6 = new QVBoxLayout(frame_2);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        glView2D = new View2DGL(frame_2);
        glView2D->setObjectName(QString::fromUtf8("glView2D"));
        glView2D->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_6->addWidget(glView2D);


        verticalLayout_3->addWidget(frame_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushTurnLeft2D = new QPushButton(tabFP2D);
        pushTurnLeft2D->setObjectName(QString::fromUtf8("pushTurnLeft2D"));
        pushTurnLeft2D->setMinimumSize(QSize(32, 24));
        pushTurnLeft2D->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/mainwindow/imgs/mainwindow.icon.turnLeft.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushTurnLeft2D->setIcon(icon1);
        pushTurnLeft2D->setIconSize(QSize(11, 9));
        pushTurnLeft2D->setShortcut(QString::fromUtf8("Left"));

        horizontalLayout->addWidget(pushTurnLeft2D);

        pushMoveFwd2D = new QPushButton(tabFP2D);
        pushMoveFwd2D->setObjectName(QString::fromUtf8("pushMoveFwd2D"));
        pushMoveFwd2D->setMinimumSize(QSize(48, 26));
        pushMoveFwd2D->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/mainwindow/imgs/mainwindow.icon.goFwd.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushMoveFwd2D->setIcon(icon2);
        pushMoveFwd2D->setIconSize(QSize(11, 11));
        pushMoveFwd2D->setShortcut(QString::fromUtf8("Up"));

        horizontalLayout->addWidget(pushMoveFwd2D);

        pushTurnRight2D = new QPushButton(tabFP2D);
        pushTurnRight2D->setObjectName(QString::fromUtf8("pushTurnRight2D"));
        pushTurnRight2D->setMinimumSize(QSize(32, 24));
        pushTurnRight2D->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/mainwindow/imgs/mainwindow.icon.turnRight.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushTurnRight2D->setIcon(icon3);
        pushTurnRight2D->setIconSize(QSize(11, 9));
        pushTurnRight2D->setShortcut(QString::fromUtf8("Right"));
        pushTurnRight2D->setFlat(false);

        horizontalLayout->addWidget(pushTurnRight2D);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        verticalLayout_3->addLayout(horizontalLayout);

        tabSet->addTab(tabFP2D, QString());
        tabFP3D = new QWidget();
        tabFP3D->setObjectName(QString::fromUtf8("tabFP3D"));
        tabFP3D->setEnabled(true);
        verticalLayout_7 = new QVBoxLayout(tabFP3D);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        frame_3 = new QFrame(tabFP3D);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::Box);
        frame_3->setFrameShadow(QFrame::Plain);
        verticalLayout_8 = new QVBoxLayout(frame_3);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        glView3D = new View3DGL(frame_3);
        glView3D->setObjectName(QString::fromUtf8("glView3D"));
        glView3D->setContextMenuPolicy(Qt::NoContextMenu);

        verticalLayout_8->addWidget(glView3D);


        verticalLayout_7->addWidget(frame_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        pushTurnLeft3D = new QPushButton(tabFP3D);
        pushTurnLeft3D->setObjectName(QString::fromUtf8("pushTurnLeft3D"));
        pushTurnLeft3D->setMinimumSize(QSize(32, 24));
        pushTurnLeft3D->setContextMenuPolicy(Qt::NoContextMenu);
        pushTurnLeft3D->setIcon(icon1);
        pushTurnLeft3D->setIconSize(QSize(11, 9));
        pushTurnLeft3D->setShortcut(QString::fromUtf8("Left"));

        horizontalLayout_8->addWidget(pushTurnLeft3D);

        pushMoveFwd3D = new QPushButton(tabFP3D);
        pushMoveFwd3D->setObjectName(QString::fromUtf8("pushMoveFwd3D"));
        pushMoveFwd3D->setMinimumSize(QSize(48, 26));
        pushMoveFwd3D->setContextMenuPolicy(Qt::NoContextMenu);
        pushMoveFwd3D->setIcon(icon2);
        pushMoveFwd3D->setIconSize(QSize(11, 11));
        pushMoveFwd3D->setShortcut(QString::fromUtf8("Up"));

        horizontalLayout_8->addWidget(pushMoveFwd3D);

        pushTurnRight3D = new QPushButton(tabFP3D);
        pushTurnRight3D->setObjectName(QString::fromUtf8("pushTurnRight3D"));
        pushTurnRight3D->setMinimumSize(QSize(32, 24));
        pushTurnRight3D->setContextMenuPolicy(Qt::NoContextMenu);
        pushTurnRight3D->setIcon(icon3);
        pushTurnRight3D->setIconSize(QSize(11, 9));
        pushTurnRight3D->setShortcut(QString::fromUtf8("Right"));
        pushTurnRight3D->setFlat(false);

        horizontalLayout_8->addWidget(pushTurnRight3D);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_10);


        verticalLayout_7->addLayout(horizontalLayout_8);

        tabSet->addTab(tabFP3D, QString());
        tabAbout = new QWidget();
        tabAbout->setObjectName(QString::fromUtf8("tabAbout"));
        horizontalLayout_4 = new QHBoxLayout(tabAbout);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(tabAbout);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);
        label_4->setWordWrap(true);
        label_4->setOpenExternalLinks(true);

        horizontalLayout_4->addWidget(label_4);

        tabSet->addTab(tabAbout, QString());

        horiz->addWidget(tabSet);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("MS Serif"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setContextMenuPolicy(Qt::NoContextMenu);
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        dialCompass = new QDial(centralwidget);
        dialCompass->setObjectName(QString::fromUtf8("dialCompass"));
        dialCompass->setEnabled(false);
        dialCompass->setFocusPolicy(Qt::NoFocus);
        dialCompass->setContextMenuPolicy(Qt::NoContextMenu);
        dialCompass->setMaximum(4);
        dialCompass->setSingleStep(1);
        dialCompass->setPageStep(1);
        dialCompass->setValue(2);
        dialCompass->setSliderPosition(2);
        dialCompass->setTracking(false);
        dialCompass->setOrientation(Qt::Horizontal);
        dialCompass->setInvertedAppearance(false);
        dialCompass->setInvertedControls(false);
        dialCompass->setWrapping(true);
        dialCompass->setNotchTarget(1);
        dialCompass->setNotchesVisible(true);

        verticalLayout_4->addWidget(dialCompass);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font1);
        label_3->setContextMenuPolicy(Qt::NoContextMenu);
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);


        horiz->addLayout(verticalLayout_4);


        verticalLayout->addLayout(horiz);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 21));
        MainWindow->setMenuBar(menubar);
        QWidget::setTabOrder(tabSet, pushNew);
        QWidget::setTabOrder(pushNew, pushTurnLeft2D);
        QWidget::setTabOrder(pushTurnLeft2D, pushMoveFwd2D);
        QWidget::setTabOrder(pushMoveFwd2D, pushTurnRight2D);
        QWidget::setTabOrder(pushTurnRight2D, dialCompass);

        retranslateUi(MainWindow);

        tabSet->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "LOOM - Doom na Lus\303\263fona!", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "LOOM - Doom na Lus\303\263fona!", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushNew->setToolTip(QApplication::translate("MainWindow", "Come\303\247ar de novo com outro labirinto", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushNew->setText(QApplication::translate("MainWindow", "&Novo", 0, QApplication::UnicodeUTF8));
        tabSet->setTabText(tabSet->indexOf(tabMap), QApplication::translate("MainWindow", "&Mapa", 0, QApplication::UnicodeUTF8));
        tabSet->setTabToolTip(tabSet->indexOf(tabMap), QApplication::translate("MainWindow", "Vista de cima do labirinto (mapa)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushTurnLeft2D->setToolTip(QApplication::translate("MainWindow", "Virar \303\240 esquerda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushTurnLeft2D->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushMoveFwd2D->setToolTip(QApplication::translate("MainWindow", "Avan\303\247ar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushMoveFwd2D->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushTurnRight2D->setToolTip(QApplication::translate("MainWindow", "Virar \303\240 direita", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushTurnRight2D->setText(QString());
        tabSet->setTabText(tabSet->indexOf(tabFP2D), QApplication::translate("MainWindow", "1\302\252 Pessoa &2D", 0, QApplication::UnicodeUTF8));
        tabSet->setTabToolTip(tabSet->indexOf(tabFP2D), QApplication::translate("MainWindow", "Vista de dentro do labirinto (com OpenGL 2D)", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushTurnLeft3D->setToolTip(QApplication::translate("MainWindow", "Virar \303\240 esquerda", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushTurnLeft3D->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushMoveFwd3D->setToolTip(QApplication::translate("MainWindow", "Avan\303\247ar", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushMoveFwd3D->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushTurnRight3D->setToolTip(QApplication::translate("MainWindow", "Virar \303\240 direita", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushTurnRight3D->setText(QString());
        tabSet->setTabText(tabSet->indexOf(tabFP3D), QApplication::translate("MainWindow", "1\302\252 Pessoa &3D", 0, QApplication::UnicodeUTF8));
        tabSet->setTabToolTip(tabSet->indexOf(tabFP3D), QApplication::translate("MainWindow", "Vista de dentro do labirinto (com OpenGL 3D)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/mainwindow/imgs/mainwindow.icon.png\" /></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Jogo do labirinto para Computa\303\247\303\243o Gr\303\241fica, v1.1<br />Exemplo e exerc\303\255cio acad\303\251mico</span></p>\n"
"<p style=\"-qt-paragraph-type:empty; margi"
                        "n-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\302\251 2010 Pedro Freire</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><a href=\"http://www.pedrofreire.com/\"><span style=\" font-size:8pt; text-decoration: underline; color:#0000ff;\">www.pedrofreire.com</span></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-b"
                        "lock-indent:0; text-indent:0px;\"><a href=\"http://creativecommons.org/licenses/by-nc-sa/2.5/pt/\"><img src=\":/mainwindow/imgs/mainwindow.icon.cc.png\" /></a></p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Este software \303\251 gratuito </span><span style=\" font-size:8pt; font-weight:600;\">desde que</span><span style=\" font-size:8pt;\"><br />mantenha esta mensagem de direito de autor.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:8pt;\">\302\240</span><span style=\" font-size:8pt;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-righ"
                        "t:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:8pt;\">Ant\303\263nio Louren\303\247o a20091565</span><span style=\" font-size:8pt;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:8pt;\">Paulo Lu\303\255s a20095165 ???</span><span style=\" font-size:8pt;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:8pt;\">Bruno Machado</span><span style=\" font-size:8pt;\"> </span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'MS Shell Dlg 2,sans-serif'; font-size:8pt;\">Alexandre Palma</span><span style=\" font-size:8pt;\"> a20090894</span><"
                        "/p>\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px; font-size:8pt;\"></p></body></html>", 0, QApplication::UnicodeUTF8));
        tabSet->setTabText(tabSet->indexOf(tabAbout), QApplication::translate("MainWindow", "&Autoria", 0, QApplication::UnicodeUTF8));
        tabSet->setTabToolTip(tabSet->indexOf(tabAbout), QApplication::translate("MainWindow", "Autoria do jogo", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        label_2->setToolTip(QApplication::translate("MainWindow", "Norte", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("MainWindow", "N", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        dialCompass->setToolTip(QApplication::translate("MainWindow", "Orienta\303\247\303\243o da vista", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        label_3->setToolTip(QApplication::translate("MainWindow", "Sul", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("MainWindow", "S", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
