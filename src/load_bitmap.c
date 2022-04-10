/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** load_bitmap - 2021
**
** *****************************************************************************
*/

#include "bitmap.h"

static int	std_bmp_header(const char	*file,
			       t_bitmap		*bmp)
{
  int fd;
  
  fd = open(file, O_RDONLY);
  if (fd == -1)
    return (-1);
  read(fd, bmp, sizeof(*bmp));
  read(fd, NULL, bmp->file_header.Offset - sizeof(*bmp));
  return (fd);
}

t_bunny_pixelarray	*std_load_bitmap(const char	*file)
{
  int			fd;
  t_bitmap		bmp;
  t_bunny_pixelarray	*px;
  t_bunny_position	pos;
  t_bmp_rgb		rgb;

  pos.x = 0;
  fd = std_bmp_header(file, &bmp);
  if (fd == -1)
    return (NULL);
  px = bunny_new_pixelarray(bmp.dib_header.Width,  bmp.dib_header.Height);
  pos.y = px->clipable.buffer.height - 1;
  while (pos.y != -1 || pos.x != px->clipable.buffer.width)
    {
      if (pos.x == px->clipable.buffer.width)
	{
	  pos.x = 0;
	  pos.y = pos.y - 1;
	}
      read(fd, &rgb, sizeof(rgb));
      std_set_pixel(px, pos, COLOR(255, rgb.r, rgb.g, rgb.b));
      pos.x = pos.x + 1;
    }
  return (px);
}

