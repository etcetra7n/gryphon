#ifndef GRYPHON_H
#define GRYPHON_H

#define GRYPHON_MAJOR_VERSION 0
#define GRYPHON_MINOR_VERSION 1
#define GRYPHON_PATCH_VERSION 0

#include <string>
#include "Template/gtemplate.h"
#include "Data/gdata.h"

#define H 512
#define V 512

struct pixel{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
namespace Layout
{
    Template::Gtemplate *parse_ggl(const std::string);
}
namespace Template
{
    int compose_gtml(Gtemplate*, const std::string);
    Gtemplate *parse_gtml(const std::string);
}
namespace Data
{
    Gdata *parse_gdt(const std::string);
}
namespace Plot
{
    int compose_gplt(Template::Gtemplate*, Data::Gdata*);
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
