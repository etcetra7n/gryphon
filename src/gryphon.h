#ifndef GRYPHON_H
#define GRYPHON_H

#define GRYPHON_MAJOR_VERSION 0
#define GRYPHON_MINOR_VERSION 1
#define GRYPHON_PATCH_VERSION 0

#include <string>
#include "Template/template.h"
#include "Data/data.h"

#define H 512
#define V 512

struct pixel{
    unsigned char r;
    unsigned char g;
    unsigned char b;
};
namespace Graph
{
    int raster(struct pixel[V][H]);
}
namespace Export
{
    int export_bmp(struct pixel[V][H]);
}
namespace Template
{
    Template *parse_ggl(const std::string);
    int compose_gtml(Template*, const std::string);
}
namespace Plot
{
    int compose_gplt(Template::Template*, Data::Data*);
    Template::Template *parse_gtml(const std::string);
}
namespace Data
{
    Data *parse_gdt(const std::string);
}

#endif
