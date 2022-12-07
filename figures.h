#ifndef FIGURES_H
#define FIGURES_H

#include <QWidget>
#include <QPainterPath>


class Figures : public QWidget
{
    Q_OBJECT
public:
    Figures(QWidget *parent = nullptr);
    virtual QPainterPath getPath() = 0 ;
    virtual void paintFigure() = 0;
};

#endif // FIGURES_H
