/*****************************************************************************
 * Gryphon - Main/main.cpp
 *****************************************************************************
 * Copyright(C) 2021 John Anchery
 *
 * Authors: John Anchery <etcetra7n@gmail.com>
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
