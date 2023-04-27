#ifndef FILLCELLDIALOG_HPP
#define FILLCELLDIALOG_HPP

#include <QDialog>
#include "DataClass.hpp"

namespace Ui {
class FillCellDialog;
}

class FillCellDialog : public QDialog
{
    Q_OBJECT

public:
    explicit FillCellDialog( FieldData number, QWidget *parent = nullptr );
    ~FillCellDialog();

protected:
    void showEvent( QShowEvent * ) override;

private slots:
    void accept() override;
    void reject() override;

private:
    Ui::FillCellDialog *ui;
};

#endif // FILLCELLDIALOG_HPP
