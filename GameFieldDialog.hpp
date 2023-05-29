#ifndef GAMEFIELDDIALOG_HPP
#define GAMEFIELDDIALOG_HPP

#include <QDialog>
#include "DataClass.hpp"

namespace Ui {
class GameFieldDialog;
}

class GameFieldDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GameFieldDialog( QWidget *parent = nullptr );
    ~GameFieldDialog();

protected:
    void paintEvent( QPaintEvent* event ); // Разрешение отрисовки

private slots:
    void _onGameAreaButtonClicked();

private:
    enum Player
    {
        Unknown = -1
        , Cross = 0
        , Zero = 1
        , PlayerCount
    };
    Ui::GameFieldDialog *ui;
    void _drawField();
    void _fieldConfiguration();
    void _addFonts();
    void _changeButtonStyle( int row, int column, QString style );
    void _chekGameStop();
    void _clearField();
    void _endGame();
    void _fillCellsText();

    Player _gameArea[ 3 ][ 3 ] = { { Unknown, Unknown, Unknown }
                          , { Unknown, Unknown, Unknown }
                          , { Unknown, Unknown, Unknown } };
    Player _currentPlayer = Cross;
    Player _winner = Unknown;
    uint _gameProgress = 0;
    bool _stop = false;
    uint _cellNumber = 0;
};

#endif // GAMEFIELDDIALOG_HPP
