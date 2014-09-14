#ifndef GAME_H
#define GAME_H

#include <QMainWindow>
#include <QTimer>

namespace Ui {
class Game;
}

class Game : public QMainWindow
{
    Q_OBJECT

public:
    explicit Game(QWidget *parent = 0);
    ~Game();

private slots:
    void on_pushButton_2_clicked();
    void updateLabel(int i);
    void on_pushButton_clicked();
    void timeOUT();
    void on_actionNew_triggered();
    void starttime();
    void stoptime();
    void updatetime();
    void on_actionAdd_to_existing_triggered();
    void playagain();
    void on_pushButton_5_clicked();
    void kaishile(int state);
    void on_pushButton_6_clicked();
    void xianshi(QString remotename);
    void on_action_2_triggered();
    void setconnected();
    void on_action_3_triggered();

private:
    Ui::Game *ui;
    QTimer *timer;
    int count,second;
};

#endif // GAME_H
