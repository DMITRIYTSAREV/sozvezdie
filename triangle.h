#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figures.h"

class Triangle : public Figures
{
public:
    Triangle();
    QPainterPath getPath() override;
    void paintFigure() override;

private:
    QPainterPath trianglePath;
};

#endif // TRIANGLE_H
