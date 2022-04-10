/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** set_pixel - 2021
**
** *****************************************************************************
*/

#include "bitmap.h"

void            std_set_pixel(t_bunny_pixelarray        *px,
                              t_bunny_position          pos,
                              unsigned int              color)
{
  int           a;
  unsigned int  *adresse;

  adresse = px->pixels;
  if (pos.x >= 0 && pos.x < px->clipable.buffer.width && pos.y >= 0
      && pos.y < px->clipable.buffer.height)
    {
      a = (px->clipable.buffer.width * pos.y) + pos.x;
      adresse[a] = color;
    }
}

