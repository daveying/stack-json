/*
 * BISON file for stack-json parser
 * Author: daveying@163.com
 */

%{
#include <stdio.h>

%}

%union {
}

%token TRUE FALSE NUL WS LCB RCB LSB RSB COL COMMA DQUOTE

%%

json    : element

element : WS value WS
        | value WS
        | WS value

value   : object
        | array
        | string
        | number
        | TRUE
        | FALSE
        | NUL

object  : LCB WS RCB
        | LCB RCB                   // WS doesn't contain empty string
        | LCB members RCB

members : member
        | member COMMA members

member  : WS string WS COL element
        | string WS COL element     // WS doesn't contain empty string
        | WS string COL element     // WS doesn't contain empty string
        | string COL element        // WS doesn't contain empty string

array   : LSB WS RSB
        | LSB RSB                   // WS doesn't contain empty string
        | LSB elements RSB

elements: element
        | element COMMA elements

element : WS value WS
        | WS value                  // WS doesn't contain empty string
        | value WS                  // WS doesn't contain empty string

string  : DQUOTE characters DQUOTE

characters:
          | character characters

character: 

%%
