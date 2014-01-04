#ifndef __CRC_H__
#define __CRC_H__

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

#define CRC_8     0
#define CRC_10    1
#define CRC_12    2
#define CRC_16    3
#define CRC_CCITT 4
#define CRC_32    5

#define CRC_INIT 0

unsigned long crc_block(int type, const char* data, int len);
void crc(int type, unsigned long* crc, const char* data, int len);

#endif
