#ifndef SQUARE_H
#define SQUARE_H

#include "figures.h"

class Square : public Figures
{
public:
    Square();
    QPainterPath getPath() override;
    void paintFigure() override;
private:
      QPainterPath squarePath;
};

#endif // SQUARE_H
