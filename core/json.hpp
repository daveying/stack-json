/*
 * Author: daveying@163.com
 */

#ifndef STACK_JSON_HPP
#define STACK_JSON_HPP

#include <string>
#include <exception>
#include <iostream>

namespace stack_json
{

using size_t = std::size_t;
using string = std::string;

enum class type : uint8_t
{
    object,
    array,
    string,
    number,
    boolean,
    null,
    invalid
};

class json
{
public:
    void parse();
protected:
    const char *m_buf;
    size_t m_begin;
    size_t m_end;
    type m_type;
};

class object : public json
{

};

namespace parser
{

const char *skipWhitespaces(const char *current);
const char *skipWhitespacesB(const char *end);
void checkPointers(const char *current, const char *end, const char *msg);
void parse(const char *buf, size_t beginOffset, size_t endOffset);
void parseElement(const char *buf, const char *begin, const char *end);
void parseValue(const char *buf, const char *begin, const char *end);
void parseObject(const char *buf, const char *begin, const char *end);
void parseString(const char *buf, const char *begin, const char *end);
void parseArray(const char *buf, const char *begin, const char *end);

} // namespace parser
} // namespace stack_json

#endif // #define STACK_JSON_HPP
