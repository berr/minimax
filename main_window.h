#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>

#include "connect4.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
  Ui::MainWindow *ui;
  ConnectFour game;		    		    

private slots:
    void on_back_button_clicked();
    void on_forward_button_clicked();
    void on_reset_button_clicked();
    void on_play_button_clicked();

    void draw_state(const State* s);
};

#endif // MAINWINDOW_H
