#ifndef GRYPHON_H
#define GRYPHON_H

#define GRYPHON_MAJOR_VERSION 0
#define GRYPHON_MINOR_VERSION 1
#define GRYPHON_PATCH_VERSION 0

#include <string>
#include "Template/tree.h"

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
    Template::GGLTree *parse_ggl(const std::string filepath);
    int compose_gtml(Template::GGLTree *tree, const std::string filepath);
}

#endif
