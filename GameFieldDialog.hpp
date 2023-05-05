#ifndef GAMEFIELDDIALOG_HPP
#define GAMEFIELDDIALOG_HPP

#include <QDialog>

namespace Ui {
class GameFieldDialog;
}

class GameFieldDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameFieldDialog(QWidget *parent = nullptr);
    ~GameFieldDialog();

protected:
    void paintEvent( QPaintEvent* event ); // Разрешение отрисовки
private:
    Ui::GameFieldDialog *ui;
};

#endif // GAMEFIELDDIALOG_HPP
