#include "wind.h"
#include <time.h>
#include <stdlib.h>

Wind::Wind()
{
    srand(time(NULL));
    xDir_ = rand()%3-1;
    yDir_ = rand()%3-1;
}

void Wind::change()
{
    //TODO: evtl. Änderung abhängig von bisheriger Windrichtung
    //um zu heftige Änderungen zu vermeiden
    xDir_ = rand()%3-1;
    yDir_ = rand()%3-1;
}
