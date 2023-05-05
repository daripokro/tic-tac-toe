#include "StyleHelper.hpp"

StyleHelper::StyleHelper()
{

}

QString StyleHelper::setFieldStyle()
{
    return QString( "background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0"
                    ", stop:0 rgba(255, 178, 102, 255)"
                    ", stop:0.55 rgba(235, 148, 61, 255)"
                    ", stop:0.98 rgba(0, 0, 0, 200)"
                    ", stop:1 rgba(0, 0, 0, 0));" );
}

QString StyleHelper::setDefaultButtonStyle()
{
    return QString( "QPushButton{"
                    "border:none;"
                    "}" );
}

QString StyleHelper::setZeroStyle()
{
    return QString( "" );
}

QString StyleHelper::setCrossStyle()
{
    return QString( "" );
}
