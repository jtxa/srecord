//
// srecord - manipulate eprom load files
// Copyright (C) 2001, 2005-2008, 2010 Peter Miller
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program. If not, see
// <http://www.gnu.org/licenses/>.
//

#ifndef SRECORD_OUTPUT_FILE_EMON52_H
#define SRECORD_OUTPUT_FILE_EMON52_H

#include <cstdint>
#include <srecord/output/file.h>
#include <string>

#include <srecord/output.h>
#include <srecord/record.h>

namespace srecord
{

/**
  * The srecord::output_file_emon52 class is used to write an EMON52 formatted
  * file (Elektor Monitor, dunno what the 52 is for).
  */
class output_file_emon52:
    public output_file
{
public:
    /**
      * The destructor.
      */
    ~output_file_emon52() = default;

private:
    /**
      * A constructor.  The input will be read from the named file (or
      * the standard input if the file name is "-"). It is private on
      * purpose, use the create class method instead.
      *
      * @param file_name
      *     The name of the file to be written.
      */
    output_file_emon52(const std::string &file_name);

public:
    /**
      * The create class method is used to create new dynamically
      * allocated instances of this class.  The input will be read from
      * the named file (or the standard input if the file name is "-").
      *
      * @param file_name
      *     The name of the file to be written.
      */
    static pointer create(const std::string &file_name);

protected:
    // See base class for documentation.
    void write(const record &) override;

    // See base class for documentation.
    void line_length_set(int) override;

    // See base class for documentation.
    void address_length_set(int) override;

    // See base class for documentation.
    int preferred_block_size_get() const override;

    // See base class for documentation.
    bool preferred_block_size_set(int nbytes) override;

    // See base class for documentation.
    const char *format_name() const override;

private:
    /**
      * The pref_block_size is used to remember the preferred block
      * size.  Set by the line_length_set() method.  Read by the
      * preferred_block_size_get() method.
      */
    int pref_block_size{16};

    /**
      * The write_inner method is used to write a single line (record)
      * to the file.  Use by the write() method.
      */
    void write_inner(int type, uint32_t addr, int addr_len,
        const void *data, int data_len);

public:
    /**
      * The default constructor.
      */
    output_file_emon52() = delete;

    /**
      * The copy constructor.
      */
    output_file_emon52(const output_file_emon52 &) = delete;

    /**
      * The assignment operator.
      */
    output_file_emon52 &operator=(const output_file_emon52 &) = delete;
};

};

#endif // SRECORD_OUTPUT_FILE_EMON52_H
