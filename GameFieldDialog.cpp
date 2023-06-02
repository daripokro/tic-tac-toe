#include "GameFieldDialog.hpp"
#include "ui_GameFieldDialog.h"
#include "Utils/StyleHelper.hpp"
#include <QFontDatabase>
#include <QStyleOptionButton>
#include <QPainter>
#include <QMessageBox>

#include <QDebug>

GameFieldDialog::GameFieldDialog( QWidget *parent ) :
    QDialog( parent ),
    ui( new Ui::GameFieldDialog )
{
    ui->setupUi( this );
    this->setWindowIcon( QIcon( ":/icons/Resources/appIcon.png" ) );
    _drawField();
    _fieldConfiguration();
    _addFonts();
    _fillCellsText();
}

GameFieldDialog::~GameFieldDialog()
{
    _clearField();
    delete ui;
}

void GameFieldDialog::paintEvent( QPaintEvent *event )
{
    QStyleOptionButton* option = new QStyleOptionButton();
    option->init( this );
    QPainter p( this );
    style()->drawPrimitive( QStyle::PE_Widget, option, &p, this );
    QWidget::paintEvent( event );
}

void GameFieldDialog::_onGameAreaButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>( sender() );
    int row = btn->property( "row" ).toInt();
    int column = btn->property( "column" ).toInt();
    QString style;
    if ( _currentPlayer == Cross )
    {
        style = StyleHelper::crossNormalStyle();
    }
    else if ( _currentPlayer == Zero )
    {
        style = StyleHelper::zeroNormalStyle();
    }
    _gameArea[ row ][ column ] = _currentPlayer;

    _changeButtonStyle( row, column, style );
    _gameProgress++;
    _chekGameStop();
    _endGame();
}

void GameFieldDialog::_drawField()
{
    QString style = StyleHelper::defaultButtonStyle();
    for ( int row = 0; row < 3; ++row )
    {
        for ( int column = 0; column < 3; ++column )
        {
            _changeButtonStyle( row, column, style );
        }
    }
}

void GameFieldDialog::_fieldConfiguration()
{
    QGridLayout *grid = qobject_cast < QGridLayout* >(  this->layout() );
    for( int row = 0; row < 3; ++row )
    {
        for( int column = 0; column < 3; ++column )
        {
             QPushButton *btn = qobject_cast <QPushButton*>( grid->itemAtPosition( row, column )->widget() );
             btn->setProperty( "row", row );
             btn->setProperty( "column", column );
             connect( btn, &QPushButton::clicked, this, &GameFieldDialog::_onGameAreaButtonClicked );
        }
    }
}

void GameFieldDialog::_addFonts()
{
    QFontDatabase::addApplicationFont( ":/fonts/Resources/fonts/noah.ttf" );
    //QString fam = QFontDatabase::applicationFontFamilies( id ).at( 0 );
    //qDebug() << fam << endl; // Noah

    QFontDatabase::addApplicationFont( ":/fonts/Resources/fonts/noah_bold.ttf" );
    //fam = QFontDatabase::applicationFontFamilies( id ).at( 0 );
   // qDebug() << fam << endl;
}

void GameFieldDialog::_changeButtonStyle( int row, int colum, QString style )
{
    QGridLayout *grid = qobject_cast < QGridLayout* >( this->layout() );
    QPushButton *btn = qobject_cast < QPushButton* >( grid->itemAtPosition( row, colum )->widget() );
    btn->setStyleSheet( style );
}

void GameFieldDialog::_chekGameStop()
{
    _winner = Unknown;
    QString style;
    Player symbols[ PlayerCount ] = { Cross, Zero };

    for( int i = 0; i < PlayerCount; ++i )
    {
        for (int row = 0; row < 3; ++row )
        {
            if( ( _gameArea[ row ][ 0 ] == symbols[ i ] )
                    && ( _gameArea[ row ][ 1 ] == symbols[ i ] )
                    && ( _gameArea[ row ][ 2 ] == symbols[ i ] ) )
            {
                _stop = true;
                _winner = symbols[ i ];
                if( _winner == _currentPlayer )
                {
                    if( _currentPlayer == Cross )
                    {
                        style=StyleHelper::crossVictoryStyle();
                    }
                    else
                    {
                        style=StyleHelper::zeroVictoryStyle();
                    }
                }
                else
                {
                    if( _currentPlayer == Cross )
                    {
                        style=StyleHelper::zeroLostStyle();
                    }
                    else
                    {
                        style=StyleHelper::crossLostStyle();
                    }
                }
                _changeButtonStyle( row, 0 , style );
                _changeButtonStyle( row, 1, style );
                _changeButtonStyle( row, 2, style );
                return;
            }
        }
        for ( int col = 0; col < 3; ++col )
        {
            if( ( _gameArea[ 0 ][ col ] == symbols[ i ] )
                    && ( _gameArea[ 1 ][ col ] == symbols[ i ] )
                    && ( _gameArea[ 2 ][ col ] == symbols[ i ] ) )
            {
                _stop = true;
                _winner = symbols[ i ];
                if( _winner == _currentPlayer )
                {
                    if( _currentPlayer == Cross )
                    {
                        style=StyleHelper::crossVictoryStyle();
                    }
                    else
                    {
                        style=StyleHelper::zeroVictoryStyle();
                    }
                }
                else
                {
                    if( _currentPlayer == Cross )
                    {
                        style = StyleHelper::zeroLostStyle();
                    }
                    else
                    {
                        style=StyleHelper::crossLostStyle();
                    }
                }
                _changeButtonStyle( 0, col, style );
                _changeButtonStyle( 1, col, style );
                _changeButtonStyle( 2, col, style );
                return;
            }
        }
        if( ( _gameArea[ 0 ][ 0 ] == symbols[ i ] )
                && ( _gameArea[ 1 ][ 1 ] == symbols[ i ] )
                && ( _gameArea[ 2 ][ 2 ] == symbols[ i ] ) )
        {
            _stop = true;
            _winner = symbols[ i ];
            if( _winner == _currentPlayer )
            {
                if( _currentPlayer == Cross )
                {
                    style = StyleHelper::crossVictoryStyle();
                }
                else
                {
                    style = StyleHelper::zeroVictoryStyle();
                }
            }
            else
            {
                if( _currentPlayer == Cross )
                {
                    style = StyleHelper::zeroLostStyle();
                }
                else
                {
                    style = StyleHelper::crossLostStyle();
                }
            }
            _changeButtonStyle( 0, 0, style );
            _changeButtonStyle( 1, 1, style );
            _changeButtonStyle( 2, 2, style );
            return;
        }
        if( ( _gameArea[ 0 ][ 2 ] == symbols[ i ] )
                && ( _gameArea[ 1 ][ 1 ] == symbols[ i ] )
                && ( _gameArea[ 2 ][ 0 ] == symbols[ i ] ) )
        {
            _stop = true;
            _winner = symbols[ i ];
            if( _winner == _currentPlayer )
            {
                if( _currentPlayer == Cross )
                {
                    style = StyleHelper::crossVictoryStyle();
                }
                else
                {
                    style = StyleHelper::zeroVictoryStyle();
                }
            }
            else
            {
                if ( _currentPlayer == Cross )
                {
                    style = StyleHelper::zeroLostStyle();
                }
                else
                {
                    style = StyleHelper::crossLostStyle();
                }
            }
            _changeButtonStyle( 0, 2, style );
            _changeButtonStyle( 1, 1, style );
            _changeButtonStyle( 2, 0, style );
            return;
        }
    }
    if( _gameProgress == 9 )
    {
        _stop = true;
    }
}

void GameFieldDialog::_clearField()
{
    _gameProgress = 0;
    _currentPlayer = Cross;
    for( int row = 0; row < 3; ++row )
    {
        for( int column = 0; column < 3; ++column )
        {
            _gameArea[ row ][ column ] = Unknown;
        }
    }
    _stop = false;
}

void GameFieldDialog::_endGame()
{
    if ( _stop )
    {
        if ( _winner == _currentPlayer )
        {
            QMessageBox *info = new QMessageBox( QMessageBox::Icon::Information, "Победа!", "Ура"
                                                 , QMessageBox::Ok, this );
            info->setAttribute( Qt::WA_DeleteOnClose, true );
            connect( this, &GameFieldDialog::reject, info, &QMessageBox::close );
            info->open();
            //ui->messageLabel->setText("Победа!");
            //ui->messageLabel->setStyleSheet(StyleHelper::getVictoryMessageStyle());
        }
        else if ( _winner == Unknown )
        {
            QMessageBox *info = new QMessageBox( QMessageBox::Icon::Information, "Ничья!", "Ничья"
                                                 , QMessageBox::Ok, this );
            info->setAttribute( Qt::WA_DeleteOnClose, true );
            connect( this, &GameFieldDialog::reject, info, &QMessageBox::close );
            info->open();
            //ui->messageLabel->setText("Ничья!");
        }
        else
        {
            QMessageBox *info = new QMessageBox( QMessageBox::Icon::Information, "Проиграл!", ":("
                                                 , QMessageBox::Ok, this );
            info->setAttribute( Qt::WA_DeleteOnClose, true );
            connect( this, &GameFieldDialog::reject, info, &QMessageBox::close );
            info->open();
            //ui->messageLabel->setText("Проиграл");
            //ui->messageLabel->setStyleSheet(StyleHelper::getLostMessageStyle());
        }
        //ui->startButton->setText("Играть");
        //ui->startButton->setStyleSheet(StyleHelper::getStartButtonsStyle());
        //gameStart = false;
    }
    else
    {
        if ( _currentPlayer == Cross )
        {
            _currentPlayer = Zero;
        }
        else if ( _currentPlayer == Zero )
        {
            _currentPlayer = Cross;
        }
    }
}

void GameFieldDialog::_fillCellsText()
{
    _cellNumber = 1;
    for( int row = 0; row < 3; ++row )
    {
        for( int column = 0; column < 3; ++column )
        {
            QGridLayout *grid = qobject_cast < QGridLayout* >( this->layout() );
            QPushButton *btn = qobject_cast < QPushButton* >( grid->itemAtPosition( row, column )->widget() );
            // перенос слов; фиксировать размер кнопок?
            btn->setText( DataClass::instance().textFromCell( static_cast< FieldData >( _cellNumber ) ) );
            _cellNumber++;
        }
    }
}
