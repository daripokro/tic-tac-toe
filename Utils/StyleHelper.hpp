#ifndef STYLEHELPER_HPP
#define STYLEHELPER_HPP

#include <QString>

class StyleHelper
{
public:
    StyleHelper();

    static QString setFieldStyle();
    static QString defaultButtonStyle();

    static QString zeroNormalStyle();
    static QString crossNormalStyle();

    static QString crossVictoryStyle();
    static QString zeroVictoryStyle();

    static QString crossLostStyle();
    static QString zeroLostStyle();

protected:

};

#endif // STYLEHELPER_HPP
