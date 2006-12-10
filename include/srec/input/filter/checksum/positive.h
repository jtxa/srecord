//
//	srecord - manipulate eprom load files
//	Copyright (C) 2000-2002, 2005, 2006 Peter Miller;
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
// MANIFEST: interface definition for lib/srec/input/filter/checksum/positive.cc
//

#ifndef INCLUDE_SREC_INPUT_FILTER_CHECKSUM_POSITIVE_H
#define INCLUDE_SREC_INPUT_FILTER_CHECKSUM_POSITIVE_H


#include <srec/input/filter/checksum.h>

/**
  * The srec_input_filter_checksum_positive class is used to represent the
  * state of a checksum filter that inserts a positive sum into the data.
  */
class srec_input_filter_checksum_positive:
    public srec_input_filter_checksum
{
public:
    /**
      * The destructor.
      */
    virtual ~srec_input_filter_checksum_positive();

    /**
      * The constructor.
      *
      * @param deeper
      *     The deeper input source being checksummed.
      * @param address
      *     The address to place the checksum.
      * @param length
      *     The number of bytes of checksum to be placed into the result.
      * @param order
      *     The byte order: false => bigendian, true => little endian.
      * @param width
      *     The width of the values being summed.  Usually 1 byte, but
      *     wider combinations are possible.  If you use something
      *     wider, it is assumed that they are alligned on multiples of
      *     that width, no provision for an offset is provided.
      */
    srec_input_filter_checksum_positive(srec_input *deeper, int address,
	    int length, int order, int width = 1);

protected:
    // See base class for documentation.
    sum_t calculate();

private:
    /**
      * The default constructor.  Do not use.
      */
    srec_input_filter_checksum_positive();

    /**
      * The copy constructor.  Do not use.
      */
    srec_input_filter_checksum_positive(
	const srec_input_filter_checksum_positive &);

    /**
      * The assignment operator.  Do not use.
      */
    srec_input_filter_checksum_positive &operator=(
	const srec_input_filter_checksum_positive &);
};

#endif // INCLUDE_SREC_INPUT_FILTER_CHECKSUM_POSITIVE_H
