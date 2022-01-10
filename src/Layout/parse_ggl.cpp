#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "Template/element.h"
#include "Template/template.h"
#include "Parser/parser.h"
#include "Parser/trim_ends.h"
#include "gryphon.h"

namespace Layout
{
    Template::Template *parse_ggl(const std::string filepath)
    {
        std::ifstream file(filepath, std::ios::in);
        std::stringstream buffer;
        if(file.good())
        {
            buffer << file.rdbuf();
        } else
        {
            return NULL;
        }
        file.close();
        
        /*
          Technical notes on parsing process:
          
          All the parsing happens inside a while loop which runs as long as the
          parser has a content to parse. 
          
          Inside the loop the tags are stored into an instace of the Parser 
          classwhich parses the individual tags. Each type of tags gets 
          processed in the a if or an else block designated for it.
      
          Here are the four types of tags:
            - Comment tag: has the syntax "<!__>"
            - Opening tag: has the syntax "<__>"
            - Closing tag: has the syntax "</__>"
            - Attribute tag: has the syntax "<__/>"
          
          here "__" can either be name of the element alone or both name and
          some attributes of the element
          
          Important variable description:
            -`parser` is the instance variable of the Parser class, and is used
             to parse the entire file
          
            -`tag` is the instance variable of the Parser class, used to parse
              a tag individually. It gets updated after the tag is parsed, 
              so the next tagcan be parsed
          
            -`e` is the instance pointer variable of the Element class, which
              points to the element, currently being parsed. After it gets
              parsed it gets re-addressed to a new element to store the next
              element
         
           -`open_tags` is an  std::vector<Element*> which holds the pointer 
             to the elements whose corresponding closing tag is not parsed yet
             
           - `tree` is an instance of GGLTree class, used to store the tree
        */
        
        Parser::Parser parser(buffer.str());
        delete &buffer;
        std::vector<Template::Element*> open_tags;
        Template::Template *tml = new Template::Template();
        
        if (parser.active())
        {
            //The cursor is placed at a convinient position for the first 
            //iteration
            parser.ignore_till("<");
        }
            
        while(parser.active())
        {
            Parser::Parser tag(parser.parse_till(">"));
            if (!(tag.begins_with("!")))
            {
                if (tag.begins_with("/"))
                {
                    //For every closing tag, the last element of the 
                    //open_tags vector is removed
                    tag.ignore_till("/");
                    std::string e_name = tag.parse_alpha();
                    if(open_tags[open_tags.size()-1]->name() == e_name)
                    {
                        open_tags.pop_back();
                        parser.ignore_till("<");
                    }
                    else {
                        //Only the most recently opened tag can be closed
                        return nullptr;
                    }
                }
                else
                {
                    //non closing tags are either opening tags or attribute
                    //tags. for both of the tags, the name and attributes
                    //are parsed
                    Template::Element *e = tml->new_element();
                    e->set_name(tag.parse_alpha());
                    while(isalpha(tag.next_non_space_char()))
                    {
                        std::string attr_n = tag.parse_alpha();
                        tag.ignore_till("=");
                        tag.ignore_till("\"");
                        std::string attr_v = tag.parse_till("\"");
                        e->add_attr(attr_n, attr_v);
                    }
                    if (open_tags.size() > 0)
                    {
                        //Both opening and attribute tags are appended to their
                        //parent
                        open_tags[open_tags.size()-1]->append_child(e);
                    }
                    if (tag.next_non_space_char() == '/')
                    {
                        //For attribute tags, there is nothing to parse now.
                        //The cursor is placed a convinient position
                        parser.ignore_till("<");
                    }
                    else
                    {
                        //For every opening tag, the current element get
                        //appended to the open_tags vector and the value 
                        //of the element get parsed
                        open_tags.push_back(e);
                        e->set_value(Parser::trim_ends(parser.parse_till("<")));
                    }
                }
            } else{
                //For every comment tags, cursor is placed at a position after
                //the comment, thereby ignoring it
                parser.ignore_till("<");
            }
        }
        return tml;
    }
}
