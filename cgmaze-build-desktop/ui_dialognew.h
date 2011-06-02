/********************************************************************************
** Form generated from reading UI file 'dialognew.ui'
**
** Created: Sun 29. May 15:21:39 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNEW_H
#define UI_DIALOGNEW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSlider>
#include <QtGui/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogNew
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinCorridorWidth;
    QLabel *label_2;
    QSpinBox *spinCorridorHeight;
    QLabel *label_3;
    QSlider *sliderComplexity;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogNew)
    {
        if (DialogNew->objectName().isEmpty())
            DialogNew->setObjectName(QString::fromUtf8("DialogNew"));
        DialogNew->setWindowModality(Qt::WindowModal);
        DialogNew->resize(335, 120);
        DialogNew->setModal(true);
        formLayout = new QFormLayout(DialogNew);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(DialogNew);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinCorridorWidth = new QSpinBox(DialogNew);
        spinCorridorWidth->setObjectName(QString::fromUtf8("spinCorridorWidth"));
        spinCorridorWidth->setMinimum(1);
        spinCorridorWidth->setMaximum(1000);
        spinCorridorWidth->setSingleStep(5);
        spinCorridorWidth->setValue(25);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinCorridorWidth);

        label_2 = new QLabel(DialogNew);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinCorridorHeight = new QSpinBox(DialogNew);
        spinCorridorHeight->setObjectName(QString::fromUtf8("spinCorridorHeight"));
        spinCorridorHeight->setMinimum(1);
        spinCorridorHeight->setMaximum(1000);
        spinCorridorHeight->setSingleStep(5);
        spinCorridorHeight->setValue(15);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinCorridorHeight);

        label_3 = new QLabel(DialogNew);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        sliderComplexity = new QSlider(DialogNew);
        sliderComplexity->setObjectName(QString::fromUtf8("sliderComplexity"));
        sliderComplexity->setMinimum(1);
        sliderComplexity->setMaximum(100);
        sliderComplexity->setValue(40);
        sliderComplexity->setSliderPosition(40);
        sliderComplexity->setOrientation(Qt::Horizontal);
        sliderComplexity->setTickPosition(QSlider::NoTicks);

        formLayout->setWidget(2, QFormLayout::FieldRole, sliderComplexity);

        buttonBox = new QDialogButtonBox(DialogNew);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(3, QFormLayout::SpanningRole, buttonBox);

#ifndef QT_NO_SHORTCUT
        label->setBuddy(spinCorridorWidth);
        label_2->setBuddy(spinCorridorHeight);
        label_3->setBuddy(sliderComplexity);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(spinCorridorWidth, spinCorridorHeight);
        QWidget::setTabOrder(spinCorridorHeight, sliderComplexity);
        QWidget::setTabOrder(sliderComplexity, buttonBox);

        retranslateUi(DialogNew);
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogNew, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogNew, SLOT(accept()));

        QMetaObject::connectSlotsByName(DialogNew);
    } // setupUi

    void retranslateUi(QDialog *DialogNew)
    {
        DialogNew->setWindowTitle(QApplication::translate("DialogNew", "LOOM - Novo labirinto", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogNew", "&Largura (Este-Oeste):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinCorridorWidth->setToolTip(QApplication::translate("DialogNew", "N\303\272mero de corredores, de 1 a 1000", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_2->setText(QApplication::translate("DialogNew", "&Altura (Norte-Sul):", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        spinCorridorHeight->setToolTip(QApplication::translate("DialogNew", "N\303\272mero de corredores, de 1 a 1000", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label_3->setText(QApplication::translate("DialogNew", "&Complexidade:", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        sliderComplexity->setToolTip(QApplication::translate("DialogNew", "Probabilidade de os corredores serem curtos", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class DialogNew: public Ui_DialogNew {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNEW_H
