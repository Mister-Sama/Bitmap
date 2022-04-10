/*
** *****************************************************************************
** yann.lebib
** yann.lebib <yann.lebib@stu003.cst.bunny.local>
**
** bitmap - 2021
**
** *****************************************************************************
*/

#include <lapin.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>

#ifndef			__BITMAP_H__
#define			__BITMAP_H__

#pragma			pack(1)

typedef struct		s_file_header
{
  int16_t		Signature;
  int32_t		FileSize;
  int16_t		Reserved1;
  int16_t		Reserved2;
  int32_t		Offset;
}			t_file_header;

typedef struct		s_dib_header
{
  int32_t		DIBHeaderSize;
  uint32_t		Width;
  uint32_t		Height;
  int16_t		Planes;
  int16_t		BitsPerPixel;
  int32_t		Compression;
  int32_t		ImageSize;
  uint32_t		XPixelsPerMeter;
  uint32_t		YPixelsPerMeter;
  int32_t		ColorsUsed;
  int32_t		ImportantColorUsed;
}			t_dib_header;

typedef struct		s_bitmap
{
  t_file_header		file_header;
  t_dib_header		dib_header;
}			t_bitmap;

typedef struct		s_bmp_rgb
{
  unsigned char		b;
  unsigned char		g;
  unsigned char		r;
}			t_bmp_rgb;

#pragma			pack()

t_bunny_pixelarray	*std_load_bitmap(const char			*file);

void			std_set_pixel(t_bunny_pixelarray		*px,
				      t_bunny_position			pos,
				      unsigned int			color);

void			std_all_gray(t_bunny_pixelarray			*px);

void			std_black_and_white(t_bunny_pixelarray		*px,
					    unsigned int		toggle);

#endif

