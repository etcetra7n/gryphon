#ifndef GRYPHON_H
#define GRYPHON_H

#define GRYPHON_MAJOR_VERSION 0
#define GRYPHON_MINOR_VERSION 1
#define GRYPHON_PATCH_VERSION 0

#include <string>
#include "Template/dom.h"
#include "Data/roll.h"

#define H 512
#define V 512

struct pixel{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
namespace Layout
{
    int parse_ggl(Template::Dom*, std::string);
}
namespace Template
{
    int compose_gtml(const Dom&, std::string);
    int parse_gtml(Dom*, std::string);
}
namespace Data
{
    int parse_gdt(Roll*, std::string);
}
namespace Plot
{
    int compose_gplt(const Template::Dom&, const Data::Roll&);
}
namespace Graph
{
    int raster(struct pixel[V][H]);
}
namespace Export
{
    int export_bmp(struct pixel[V][H]);
}

#endif
