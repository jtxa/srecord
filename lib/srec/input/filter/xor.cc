/*
 *	srecord - manipulate eprom load files
 *	Copyright (C) 1998, 1999 Peter Miller;
 *	All rights reserved.
 *
 *	This program is free software; you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation; either version 2 of the License, or
 *	(at your option) any later version.
 *
 *	This program is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with this program; if not, write to the Free Software
 *	Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111, USA.
 *
 * MANIFEST: functions to impliment the srec_input_filter_xor class
 */

#pragma implementation "srec_input_filter_xor"

#include <srec/input/filter/xor.h>
#include <srec/record.h>


srec_input_filter_xor::srec_input_filter_xor()
	: srec_input_filter(), value(0)
{
}


srec_input_filter_xor::srec_input_filter_xor(srec_input *a1, int a2)
	: srec_input_filter(a1), value(a2)
{
}


srec_input_filter_xor::srec_input_filter_xor(const srec_input_filter_xor &arg)
	: srec_input_filter(arg), value(arg.value)
{
}


srec_input_filter_xor &
srec_input_filter_xor::operator=(const srec_input_filter_xor &arg)
{
	srec_input_filter::operator=(arg);
	value = arg.value;
	return *this;
}


srec_input_filter_xor::~srec_input_filter_xor()
{
}


int
srec_input_filter_xor::read(srec_record &record)
{
	if (!srec_input_filter::read(record))
		return 0;
	if (record.get_type() == srec_record::type_data)
	{
		for (int j = 0; j < record.get_length(); ++j)
			record.set_data(j, record.get_data(j) ^ value);
	}
	return 1;
}
