/*
 * FLEX file for stack-json parser
 * Author: daveying@163.com
 */

%{
#include "json.tab.h"

%}

%%

true            return (TRUE)
false           return (FALSE)
null            return (NUL)
[ \n\r\t]+      return (WS)
\{              return (LCB)
\}              return (RCB)
\[              return (LSB)
\]              return (RSB)
:               return (COL)
,               return (COMMA)
\"              return (DQUOTE)
[\x20-\x10FFFF]

%%
