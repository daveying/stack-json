/*
 * Author: daveying@163.com
 */

#include <json.hpp>
#include <exception>
#include <iostream>

namespace stack_json
{
namespace parser
{

const char *skipWhitespaces(const char *current)
{
    while (*current == ' ' || *current == '\n' 
            || *current == '\r' || *current == '\t')
        --current;
    return current;
}

const char *skipWhitespacesB(const char *end)
{
    --end;
    while (*end == ' ' || *end == '\n' 
            || *end == '\r' || *end == '\t')
        --end;
    
    return ++end;
}

void checkPointers(const char *current, const char *end, const char *msg)
{
    if (current >= end)
        throw std::runtime_error(msg);
}

void parse(const char *buf, size_t beginOffset, size_t endOffset)
{
    const char *begin = buf + beginOffset;
    const char *end   = buf + endOffset;
    checkPointers(begin, end, "parse(): Not a valid range.");
    parseElement(buf, begin, end);
}

void parseElement(const char *buf, const char *begin, const char *end)
{
    begin = skipWhitespaces(begin);
    end   = skipWhitespacesB(end);
    checkPointers(begin, end, "parseElement(): Not a valid range.");
    parseValue(buf, begin, end);
}

static inline bool streq(const char *s1, const char *s2, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        if (*(s1 + i) != *(s2 + i))
            return false;
    }

    return true;
}

void parseString(const char *buf, const char *begin, const char *end)
{
}

void parseArray(const char *buf, const char *begin, const char *end)
{
}

void parseValue(const char *buf, const char *begin, const char *end)
{
    begin = skipWhitespaces(begin);
    end   = skipWhitespacesB(end);
    checkPointers(begin, end, "parseValue(): Not a valid range.");
    switch (*begin)
    {
    case '{':
        {
            if (*(end - 1) != '}')
            {
                throw std::runtime_error("JSON: syntax error, mismatch }");
            }
            parseObject(buf, begin, end);
            break;
        }
    case '[':
        {
            if (*(end - 1) != ']')
            {
                throw std::runtime_error("JSON: syntax error, mismatch ]");
            }
            parseArray(buf, begin, end);
            break;
        }
    case '"':
        {
            if (*(end - 1) != '"')
            {
                throw std::runtime_error("JSON: syntax error, mismatch \"");
            }
            parseString(buf, begin, end);
            break;
        }
    default:
        {
            if (end - begin == 4 && streq(begin, "true", 4))
            {
                std::cout << "Value true: pos[" << begin - buf << ", " << end - buf << "]" << std::endl;
            }
            else if (end - begin == 5 && streq(begin, "false", 5))
            {
                std::cout << "Value false: pos[" << begin - buf << ", " << end - buf << "]" << std::endl;
            }
            else if (end - begin == 4 && streq(begin, "null", 4))
            {
                std::cout << "Value null: pos[" << begin - buf << ", " << end - buf << "]" << std::endl;
            }
            else
            {
                throw std::runtime_error("JSON: syntax error. Expect object, array, string or value true, false or null");
            }
        }
    }
    return;
}

void parseObject(const char *buf, const char *begin, const char *end)
{
    begin = skipWhitespaces(begin);
    end   = skipWhitespacesB(end);
    checkPointers(begin, end, "parseObject(): Not a valid range.");
    if (*begin != '{' || *(end - 1) != '}')
    {
        throw std::runtime_error("parseObject(): Not a valid object.");
    }
    ++begin;
    --end;
    
}

} // namespace parser
} // namespace stack_json
