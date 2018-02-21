#ifndef DIALOGARISTA_H
#define DIALOGARISTA_H

#include <QDialog>

namespace Ui {
class DialogArista;
}

class DialogArista : public QDialog
{
    Q_OBJECT

public:
    explicit DialogArista(QWidget *parent = 0);
    ~DialogArista();

private:
    Ui::DialogArista *ui;
};

#endif // DIALOGARISTA_H
