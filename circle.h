#ifndef CIRCLE_H
#define CIRCLE_H

#include "figures.h"


class Circle : public Figures
{
public:
    Circle();
    QPainterPath getPath() override;
    void paintFigure() override;

private:
    QPainterPath circlePath;

};

#endif // CIRCLE_H
