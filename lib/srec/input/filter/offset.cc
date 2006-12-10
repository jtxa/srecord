//
//	srecord - manipulate eprom load files
//	Copyright (C) 1998, 1999, 2001, 2002, 2005, 2006 Peter Miller;
//	All rights reserved.
//
//	This program is free software; you can redistribute it and/or modify
//	it under the terms of the GNU General Public License as published by
//	the Free Software Foundation; either version 2 of the License, or
//	(at your option) any later version.
//
//	This program is distributed in the hope that it will be useful,
//	but WITHOUT ANY WARRANTY; without even the implied warranty of
//	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//	GNU General Public License for more details.
//
//	You should have received a copy of the GNU General Public License
//	along with this program; if not, write to the Free Software
//	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
//
// MANIFEST: functions to impliment the srec_input_filter_offset class
//


#include <srec/input/filter/offset.h>
#include <srec/record.h>


srec_input_filter_offset::srec_input_filter_offset(srec_input *a1, long a2) :
    srec_input_filter(a1),
    nbytes(a2)
{
}


srec_input_filter_offset::~srec_input_filter_offset()
{
}


int
srec_input_filter_offset::read(srec_record &record)
{
    if (!srec_input_filter::read(record))
	return 0;
    long addr = record.get_address() + nbytes;

    //
    // Cope with machines with 64-bit longs, since all the code assumes
    // addresses are in the modulo-2**32 range.
    //
    // FIXME: need to cope with data records which span zero.
    //
    addr &= 0xFFFFFFFF;

    record.set_address(addr);
    return 1;
}
