/*****************************************************************************
 * Gryphon - Main/main.cpp
 *****************************************************************************
 * Copyright(C) 2021 John Anchery
 * 
 * Authors: John Anchery <etcetra7n@gmail.com>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>. 
 *****************************************************************************/

#include <iostream>
#include <vector>
#include "Template/element.h"
#include "gryphon.h"

int main(int argc, char **argv)
{
    Template::Gtemplate *tml = Layout::parse_ggl("Workspace/This100.ggl");
    std::vector<Template::Element> v = tml->elements();
    return 0;
    compose_gtml(tml, "Workspace/This100.gtml");
    Template::parse_gtml("Workspace/This100.gtml");
    return 0;
}
