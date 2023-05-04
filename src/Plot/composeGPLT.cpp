#include "Template/plot.h"

#include "Template/dom.h"
#include "Data/roll.h"

namespace Plot
{
    int composeGPLT(Template::Dom *document, Data::Roll *roll)
    {
        /* Basically compine the data file, which is a collection of points
           and the template file, which dictates how to render the graph.
           The final product, the .gplt file, can be opened on demand, to
           render the graph (in a matplotlib-like interactive window)

           The graph can as well be exported into image-like file formats
           like .jpeg, .png, .bmp etc. However these formats are not
           interactive
        */
        return 0;
    }
}
