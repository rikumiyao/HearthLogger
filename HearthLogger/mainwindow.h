#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

typedef struct {
    QString hero;
    QStringList decks;
} heroDecks;

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
    void on_yourClass_currentIndexChanged(const QString &arg1);
    void on_opponentClass_currentIndexChanged(const QString &arg1);

private:
    Ui::MainWindow *ui;
    void configureUI();
    void log(QString text);
    void setupDeckNames();
    QList<heroDecks>deckLists;
};

#endif // MAINWINDOW_H
