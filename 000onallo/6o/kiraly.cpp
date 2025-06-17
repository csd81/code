#include "kiraly.h"



bool Kiraly::lephet(const string &pos) const
{
    if (pos==pozicio) return false;
    else if ((pos[0]==pozicio[0]+1 ||  pos[0]==pozicio[0]-1 || pos[0]==pozicio[0])
    && (pos[1]==pozicio[1]+1 ||    pos[1]==pozicio[1]-1 ||    pos[1]==pozicio[1] )
    )
    return true;
    else return false;
    }


char Kiraly::jeloles() const
{
    return 'K';
}
