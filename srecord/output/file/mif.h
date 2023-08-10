//
// srecord - Manipulate EPROM load files
// Copyright (C) 2009-2011 Peter Miller
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation; either version 3 of the License, or (at
// your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.
//

#ifndef SRECORD_OUTPUT_FILE_MIF_H
#define SRECORD_OUTPUT_FILE_MIF_H

#include <srecord/output.h>
#include <srecord/output/file.h>
#include <srecord/record.h>

#include <cstdint>
#include <string>


namespace srecord
{

class arglex_tool; // forward

/**
  * The srecord::output_file_mif class is used to represent the output state
  * of a file in Memory Initialization File (MIF) format (Altera).
  */
class output_file_mif:
    public output_file
{
public:
    /**
      * The destructor.
      */
    ~output_file_mif() override;

private:
    /**
      * The constructor.  It is private on purpose, use the #create
      * class method instead.
      *
      * @param file_name
      *     The name of the file to be written.  The special name "-"
      *     indicates the standard output is to be used.
      */
    output_file_mif(const std::string &file_name);

public:
    /**
      * The create class method is used to create new dynamically
      * allocated instances of this class.
      *
      * @param file_name
      *     The name of the file to be written.
      */
    static pointer create(const std::string &file_name);

protected:
    // See base class for documentation
    void write(const record &) override;

    // See base class for documentation
    void line_length_set(int) override;

    // See base class for documentation
    void address_length_set(int) override;

    // See base class for documentation
    int preferred_block_size_get() const override;

    // See base class for documentation.
    bool preferred_block_size_set(int nbytes) override;

    // See base class for documentation
    void command_line(arglex_tool *cmdln) override;

    // See base class for documentation.
    const char *format_name() const override;

    // See base class for documentation.
    void notify_upper_bound(uint32_t addr) override;

private:
    /**
      * The depth instance variable is used to remember how many bytes
      * of data there is.  Kind of broken, because we don't know this
      * when the header is actually printed.
      */
    uint32_t depth{65536};

    /**
      * The width instance variable is used to remember how many bits
      * there are per data item.  Default to 8 (traditional bytes).
      */
    unsigned width{8};

    /**
      * The width_in_bytes instance variable is used to remember how
      * many bytes there are per data item.  Defaults to 1.
      */
    unsigned width_in_bytes{1};

    /**
      * The actual_depth instance variable is used to remember how many
      * bytes of data there were.  This is printed in the footer.
      */
    uint32_t actual_depth{0};

    /**
      * The header_done instance variable is used to remember whether
      * the emit_header method has already been called.
      */
    bool header_done{false};

    /**
      * The pref_blk_sz instance variable is used to remember the
      * preferred block size, in bytes.
      */
    int pref_blk_sz{32};

    /**
      * The emit_header method is used to emit the file header,
      * if necessary.
      */
    void emit_header();

public:
    /**
      * The default constructor.
      */
    output_file_mif() = delete;

    /**
      * The copy constructor.
      */
    output_file_mif(const output_file_mif &) = delete;

    /**
      * The assignment operator.
      */
    output_file_mif &operator=(const output_file_mif &) = delete;
};

};

#endif // SRECORD_OUTPUT_FILE_MIF_H
