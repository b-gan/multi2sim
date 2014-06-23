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

#include "Context.h"

namespace HSA
{

Context::Context()
{
	emu = Emu::getInstance();

	pid = emu->getPid();	

	emu->hsa_debug << "Context " << pid << " created\n";
}

Context::~Context(){
	
}

void Context::Load(const std::vector<std::string> &args,
	const std::vector<std::string> &env, 
	const std::string &cwd,
	const std::string &stdin_file_name,
	const std::string &stdout_file_name)
{
	loader.reset(new Loader);
	loader->exe = misc::getFullPath(args[0], cwd);
	loader->args = args;
	loader->cwd = cwd.empty() ? misc::getCwd() : cwd;
	loader->stdin_file_name = misc::getFullPath(stdin_file_name, cwd);
	loader->stdout_file_name = misc::getFullPath(stdout_file_name, cwd);

	LoadBinary();	
}

void Context::Execute()
{

}

}