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
    Template::Dom *parse_ggl(const std::string);
}
namespace Template
{
    int compose_gtml(Dom*, const std::string);
    Dom *parse_gtml(const std::string);
}
namespace Data
{
    Roll *parse_gdt(const std::string);
}
namespace Plot
{
    int compose_gplt(Template::Dom*, Data::Roll*);
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
