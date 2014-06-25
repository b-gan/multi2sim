/*
 *  Multi2Sim
 *  Copyright (C) 2014  Yifan Sun (yifansun@coe.neu.edu)
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef ARCH_HSA_EMU_REGISTERS_H
#define ARCH_HSA_EMU_REGISTERS_H

#include <map>
#include <memory>

#include <lib/cpp/String.h>

namespace HSA
{

/// Class representing the state of the hsa architecture register file
class Registers
{

protected:

	// Number of bits used. If allocated size exceed 128x32 bits, expception
	// will be raised. C registers would not occupy this space
	unsigned int allocated_size;

	// Register name and their position in the register file
	std::map<std::string, std::unique_ptr<char *>> register_profile;

public:

	/// Constructor
	Registers();

	/// Destructor
	~Registers();

	/// Get register value
	///
	/// \param name 
	/// 	Name of the register to get. For example $s0...
	///
	/// \return 
	/// 	Pointer to the content of the register. Callers will have to 
	/// 	convert the type of returned pointer
	char *getRegister(const std::string &name);

	/// Set register value
	///
	/// \param name 
	/// 	Name of the register to get. For example $s0...
	///
	/// \param value
	/// 	Value of the data to be write into a certain register
	///
	/// \return 
	/// 	Pointer to the content of the register. Callers will have to 
	/// 	convert the type of returned pointer
	void setRegister(const std::string &name, char *value);

	/// Dump register states for debug propose
	void Dump(std::ostream &os) const;

	/// Operator \c << invoking the function Dump9) on an output stream
	friend std::ostream &operator<<(std::ostream &os,
			const Registers &registers)
	{
		registers.Dump(os);
		return os;
	}

};

}  // namespace HSA

#endif