#include "Chess.h"


///
/// \brief Chess::paintEvent
///
void Chess::paintEvent(QPaintEvent *)
{
    QPainter painter(this) ;
    _chess->paintChess(this,&painter);
}

void Chess::mouseReleaseEvent(QMouseEvent *me)
{
    QPoint point = me->pos() ;
    if(_chess->tryToMove(point) )
        update() ;
}
