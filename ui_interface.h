/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created: Sun May 27 21:42:36 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *table_width_sp;
    QLabel *label_2;
    QSpinBox *table_height_sp;
    QPushButton *reset_button;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *back_button;
    QPushButton *forward_button;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QSpinBox *depth_sp;
    QCheckBox *full_search_cb;
    QPushButton *play_button;
    QSpacerItem *verticalSpacer;
    QFrame *table_frame;
    QHBoxLayout *horizontalLayout;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox = new QGroupBox(frame_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        table_width_sp = new QSpinBox(groupBox);
        table_width_sp->setObjectName(QString::fromUtf8("table_width_sp"));
        table_width_sp->setMinimum(1);
        table_width_sp->setMaximum(99);
        table_width_sp->setValue(7);

        gridLayout->addWidget(table_width_sp, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 2, 1, 1);

        table_height_sp = new QSpinBox(groupBox);
        table_height_sp->setObjectName(QString::fromUtf8("table_height_sp"));
        table_height_sp->setMinimum(1);
        table_height_sp->setValue(7);

        gridLayout->addWidget(table_height_sp, 0, 3, 1, 1);

        reset_button = new QPushButton(groupBox);
        reset_button->setObjectName(QString::fromUtf8("reset_button"));

        gridLayout->addWidget(reset_button, 1, 1, 1, 2);


        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(frame_2);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        horizontalLayout_3 = new QHBoxLayout(groupBox_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        back_button = new QPushButton(groupBox_2);
        back_button->setObjectName(QString::fromUtf8("back_button"));

        horizontalLayout_3->addWidget(back_button);

        forward_button = new QPushButton(groupBox_2);
        forward_button->setObjectName(QString::fromUtf8("forward_button"));

        horizontalLayout_3->addWidget(forward_button);


        verticalLayout_2->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(frame_2);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        gridLayout_2 = new QGridLayout(groupBox_3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        depth_sp = new QSpinBox(groupBox_3);
        depth_sp->setObjectName(QString::fromUtf8("depth_sp"));
        depth_sp->setMinimum(1);

        gridLayout_2->addWidget(depth_sp, 0, 1, 1, 1);

        full_search_cb = new QCheckBox(groupBox_3);
        full_search_cb->setObjectName(QString::fromUtf8("full_search_cb"));

        gridLayout_2->addWidget(full_search_cb, 0, 2, 1, 1);

        play_button = new QPushButton(groupBox_3);
        play_button->setObjectName(QString::fromUtf8("play_button"));

        gridLayout_2->addWidget(play_button, 1, 1, 1, 1);


        verticalLayout_2->addWidget(groupBox_3);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);


        horizontalLayout_2->addWidget(frame_2);

        table_frame = new QFrame(centralwidget);
        table_frame->setObjectName(QString::fromUtf8("table_frame"));
        table_frame->setFrameShape(QFrame::NoFrame);
        table_frame->setFrameShadow(QFrame::Plain);
        horizontalLayout = new QHBoxLayout(table_frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));

        horizontalLayout_2->addWidget(table_frame);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "Configura\303\247\303\265es", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Largura", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Altura", 0, QApplication::UnicodeUTF8));
        reset_button->setText(QApplication::translate("MainWindow", "Resetar", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Jogadas", 0, QApplication::UnicodeUTF8));
        back_button->setText(QApplication::translate("MainWindow", "Voltar", 0, QApplication::UnicodeUTF8));
        forward_button->setText(QApplication::translate("MainWindow", "Avan\303\247ar", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "MiniMax", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Profundidade M\303\241xima", 0, QApplication::UnicodeUTF8));
        full_search_cb->setText(QApplication::translate("MainWindow", "\303\201rvore Inteira", 0, QApplication::UnicodeUTF8));
        play_button->setText(QApplication::translate("MainWindow", "Jogar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
