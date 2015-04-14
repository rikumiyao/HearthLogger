#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:


    void on_submitButton_clicked();

    void on_yourRank_activated(const QString &arg1);

    void on_opponentRank_activated(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void configureUI();
    void log(QString text);
};

#endif // MAINWINDOW_H
