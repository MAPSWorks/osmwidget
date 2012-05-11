#ifndef OSM_WIDGET_H
#define OSM_WIDGET_H

#include <QWidget>
#include <QGLWidget>
#include <QMouseEvent>
#include "osmparser.hpp"

class OsmWidget : public QGLWidget {
  Q_OBJECT

  private:
    OsmDataSource *osm;
    int zoom;
    int dragStartX;
    int dragStartY;
    int tempMoveX;
    int tempMoveY;
    bool renderFast;
    double lonCentre;
    double latCentre;
    
    void translateView(int x, int y);
    
  public:
    OsmWidget(QWidget *parent=0);
    QSize minimumSizeHint() const;
    QSize sizeHint() const;
    void setOsmSource(OsmDataSource *);
    
  public slots:
    void set_zoom(int);

  protected:
    void paintEvent(QPaintEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

int calc_dist(double, double, double, double, double *, double *);
#endif // ifndef OSM_WIDGET_H