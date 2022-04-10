/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@csr-pi02.ecole-89.com>
**
** main - 2021
**
** *****************************************************************************
*/

#include		"bitmap.h"

int			main(int	argc,
			     char	**argv)
{
  t_bunny_window	*win;
  t_bunny_pixelarray	*px;

  if (argc != 2)
    return (0);
  px = std_load_bitmap(argv[1]);
  if (px == NULL)
    return (-1);
  win = bunny_start(px->clipable.buffer.width, px->clipable.buffer.height, false, "Sequencer");
  bunny_blit(&win->buffer, &px->clipable, NULL);
  bunny_display(win);
  bunny_usleep(5e6);
  bunny_stop(win);
}

