
#include <iostream>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"

using namespace rapidjson;

int main() {
    // 1. Parse a JSON string into DOM.
    //const char* json = R"foo({ "glossary": { "title": "example glossary", "GlossDiv": { "title": "S", "GlossList": { "GlossEntry": { "ID": "SGML", "SortAs": "SGML", "GlossTerm": "Standard Generalized Markup Language", "Acronym": "SGML", "Abbrev": "ISO 8879:1986", "GlossDef": { "para": "A meta-markup language, used to create markup languages such as DocBook.", "GlossSeeAlso": ["GML", "XML"] }, "GlossSee": "markup" } } } } })foo";
    const char* json = R"foo({ "glossary": { "title": "example glossary", "GlossDiv": { "title": "S", "GlossList": { "GlossEntry": { "ID": "SGML", "SortAs": "SGML", "GlossTerm": "Standard Generalized Markup Language", "Acronym": "SGML", "Abbrev": "ISO 8879:1986", "GlossDef": { "para": "A meta-markup language, used to create markup languages such as DocBook.", "GlossSeeAlso": ["GML", "XML"] }, "GlossSee": "markup" } } } } })foo";
    // const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d;

    for(uint32_t i=0; i<1e6; i++) {
        d.Parse(json);
    }

    // 2. Modify it by DOM.
    // Value& s = d["stars"];
    // s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    // StringBuffer buffer;
    // Writer<StringBuffer> writer(buffer);
    // d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    // std::cout << buffer.GetString() << std::endl;
    return 0;
}
