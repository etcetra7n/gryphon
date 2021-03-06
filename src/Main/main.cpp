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
#include "Layout/layout.h"
#include "Template/template.h"

int main(int argc, char **argv)
{
    Template::Dom document;
    Layout::parseGGL(&document, "_test/test.ggl");
    composeGTML("_test/test.gtml", &document);
    Template::parseGTML(&document, "_test/test.gtml");
    return 0;
}
