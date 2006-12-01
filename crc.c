/******************************************************************************
 *
 * Author      : Mario Korand, Mario.Konrad@gmx.net
 * Creation    : August 04, 2001
 * Last Change : August 04, 2001 / Mario Konrad
 *
 * Copyright (C) Mario Konrad
 *
 ******************************************************************************
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 ******************************************************************************/

/*
 * $Id: crc.c,v 1.1.1.1 2003/01/29 20:50:07 ninja Exp $
 */

#include "crc.h"

static const struct CRC CRC_TYPES[] =
{
  {  8, 0x00000007, 0x000000ff },
  { 10, 0x00000233, 0x000003ff },
  { 12, 0x0000080f, 0x00000fff },
  { 16, 0x00008005, 0x0000ffff },
  { 16, 0x00001021, 0x0000ffff },
  { 32, 0x04c11db7, 0xffffffff },
};

void crc(int type, unsigned long * crc, const char * data, int len)
{
  unsigned long tmpcrc;
  int i, j;
  unsigned long c;

  if (!data) return;
  if (!crc) return;
  tmpcrc = *crc;
  for (j = 0; j < len; j++)
    {
      c = data[j] << (CRC_TYPES[type].bits - 8);
      for (i = 0; i < 8; i++)
	{
	  if ((tmpcrc ^ c) & (1 << (CRC_TYPES[type].bits-1)))
	    {
	      tmpcrc = (tmpcrc << 1) ^ CRC_TYPES[type].mask;
	    }
	  else
	    {
	      tmpcrc <<= 1;
	    }
	  c <<= 1;
	}
    }
  *crc = tmpcrc & CRC_TYPES[type].r_mask;
}

unsigned long crc_block(int type, const char * data, int len)
{
  unsigned long crc_value = CRC_INIT;
  crc(type, &crc_value, data, len);
  return crc_value;
}

/* EOF */
