#include "GameFieldDialog.hpp"
#include "ui_GameFieldDialog.h"
#include "Utils/StyleHelper.hpp"
#include <QFontDatabase>
#include <QStyleOptionButton>
#include <QPainter>

#include <QDebug>

GameFieldDialog::GameFieldDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GameFieldDialog)
{
    ui->setupUi( this );
    QFontDatabase::addApplicationFont( ":/fonts/Resources/fonts/noah.ttf" );

    //QString fam = QFontDatabase::applicationFontFamilies( id ).at( 0 );
    //qDebug() << fam << endl; // Noah

    QFontDatabase::addApplicationFont( ":/fonts/Resources/fonts/noah_bold.ttf" );
    //fam = QFontDatabase::applicationFontFamilies( id ).at( 0 );
   // qDebug() << fam << endl;
}

GameFieldDialog::~GameFieldDialog()
{
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
