#include "FillCellDialog.hpp"
#include "ui_FillCellDialog.h"
#include <QMessageBox>
#include <QIcon>

#include <QDebug>

FillCellDialog::FillCellDialog( FieldData number, QWidget *parent ) :
    QDialog( parent ),
    ui( new Ui::FillCellDialog )
  , _cellNumber( number )
{
    ui->setupUi(this);
    Q_ASSERT_X( ( _cellNumber != FieldData::Undefined ) || ( _cellNumber < FieldData::Nine )
                , "FillCellDialog", "invalid cell number" );
    this->setWindowIcon( QIcon( ":/icons/Resources/appIcon.png" ) );
    ui->imageLabel->setPixmap( ":/icons/Resources/numbers/" + QString::number( _cellNumber ) + ".png"  );
    ui->titleLabel->setText( "Установить текст " + QString::number( _cellNumber ) + " ячейки" );

    connect( ui->buttonBox, &QDialogButtonBox::accepted,this, &FillCellDialog::accept );
    connect( ui->buttonBox, &QDialogButtonBox::rejected,this, &FillCellDialog::reject );

    ui->textEdit->setPlainText( DataClass::instance().textFromCell( _cellNumber ) );
}

FillCellDialog::~FillCellDialog()
{
    delete ui;
}

void FillCellDialog::accept()
{
    if ( _checkInput() )
    {
        DataClass::instance().setTextForCell( _cellNumber, ui->textEdit->toPlainText() );
        QDialog::accept();
    }
}

void FillCellDialog::reject()
{
    QDialog::reject();
}

bool FillCellDialog::_checkInput()
{
    if ( ui->textEdit->toPlainText().isEmpty() )
    {
        QMessageBox *error = new QMessageBox( QMessageBox::Warning, "Предупреждение"
                                              , "Текст ячейки не может быть пустым", QMessageBox::Ok, this );
        error->setAttribute( Qt::WA_DeleteOnClose, true );
        connect( this, &FillCellDialog::reject, error, &QMessageBox::close );
        error->open();
        ui->textEdit->setFocus();
        return false;
    }
    return true;
}
