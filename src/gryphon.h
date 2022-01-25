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
    int parseGgl(Template::Dom*, const std::string&);
}
namespace Template
{
    int composeGtml(Dom*, const std::string&);
    int parseGtml(Dom*, const std::string&);
}
namespace Data
{
    int parseGdt(Roll*, const std::string&);
}
namespace Plot
{
    int composeGplt(Template::Dom*, Data::Roll*);
}
namespace Graph
{
    int raster(struct pixel[V][H]);
}
namespace Export
{
    int exportBmp(struct pixel[V][H]);
}

#endif
