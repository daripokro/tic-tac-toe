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

QString StyleHelper::defaultButtonStyle()
{
    return QString( "QPushButton{"
                    "   color:#fff;"
                    "   background: none;"
                    "   border:none;"
                    "   border-radius:19px;"
                    "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(89, 156, 208, 255), stop:1 rgba(65, 118, 184, 255));"
                    "   font-family: 'Roboto Medium';"
                    "   font-size:16px;"
                    "}"
                    "QPushButton::hover{"
                    "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(104, 173, 226, 255), stop:1 rgba(79, 144, 223, 255));"
                    "}"
                    "QPushButton::pressed{"
                    "   background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0, y2:0.955, stop:0 rgba(89, 156, 208, 255), stop:1 rgba(65, 118, 184, 255));"
                    "}" );
}

QString StyleHelper::zeroNormalStyle()
{
    return QString( "QPushButton{"
                    "  border:none;"
                    "  border-radius:19px;"
                    "  background: #272D39 url(:/resourses/zero.png) no-repeat center center;"
                    "}"
                    "QPushButton::hover{"
                    "  background-color: #373D49;"
                    "}" );
}

QString StyleHelper::crossNormalStyle()
{
    return QString( "QPushButton{"
                    "  border:none;"
                    "  border-radius:19px;"
                    "  background: #272D39 url(:/resourses/cross.png) no-repeat center center;"
                    "}"
                    "QPushButton::hover{"
                    "  background-color: #373D49;"
                    "}" );
}

QString StyleHelper::crossVictoryStyle()
{
    return QString( "QPushButton{"
                    "  border:none;"
                    "  border-radius:19px;"
                    "  background-color: #20401B;"
                    "  background-image: url(:/resourses/images/cross_large.png); "
                    "  background-repeat: no-repeat;"
                    "  background-position: center center;"
                    "}" );
}

QString StyleHelper::zeroVictoryStyle()
{
    return QString( "QPushButton{"
                    "  border:none;"
                    "  border-radius:19px;"
                    "  background-color: #20401B;"
                    "  background-image: url(:/resourses/zero.png); "
                    "  background-repeat: no-repeat;"
                    "  background-position: center center;"
                    "}" );
}

QString StyleHelper::crossLostStyle()
{
    return QString( "QPushButton{"
                    "  border:none;"
                    "  border-radius:19px;"
                    "  background-color: #7F1F8C;"
                    "  background-image: url(:/resourses/images/cross.png); "
                    "  background-repeat: no-repeat;"
                    "  background-position: center center;"
                    "}" );
}

QString StyleHelper::zeroLostStyle()
{
    return QString( "QPushButton{"
                    "  border:none;"
                    "  border-radius:19px;"
                    "  background-color: #7F1F8C;"
                    "  background-image: url(:/resourses/zero.png); "
                    "  background-repeat: no-repeat;"
                    "  background-position: center center;"
                    "}" );
}
