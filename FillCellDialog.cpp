#include "FillCellDialog.hpp"
#include "ui_FillCellDialog.h"

FillCellDialog::FillCellDialog( FieldData number, QWidget *parent ) :
    QDialog(parent),
    ui(new Ui::FillCellDialog)
{
    ui->setupUi(this);
    Q_ASSERT_X( ( number != FieldData::Undefined ) || ( number < FieldData::Nine ), "FillCellDialog", "invalid cell number" );
    ui->imageLabel->setPixmap( ":/icons/Resources/numbers/" + QString::number( number ) + ".png"  );
    ui->titleLabel->setText( "Установить текст " + QString::number( number ) + " ячейки" );

    connect( this, &FillCellDialog::accepted, this, &FillCellDialog::accept );
    connect( this, &FillCellDialog::rejected, this, &FillCellDialog::reject );

}

FillCellDialog::~FillCellDialog()
{
    delete ui;
}

void FillCellDialog::showEvent( QShowEvent * )
{

}

void FillCellDialog::accept()
{

}
