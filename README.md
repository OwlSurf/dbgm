Debug, log, warning and error messages formatter.
============
## Status:

## Brief:
A little set of macro definitions for comfortable print debug, warning, error and log messages. And another messages.

## Contents:
* [Print debug messages only if you compile your application in debug mode. (DEBUG macro definition added in the compiler options)]()
* [Print log messages in format "Log: Log message...]()
* [Print warning messages in format "Warning: Warning message..."]()
* [Print error messages in format "Error: Error message..."]()

## How to use:
1) Just add module in your project. 
2) Then just include dbgm.h file into your module where you want print messages.
3) Define DEBUG macro (for use DEBUG_PRINT) in your source files or in your compile options (actualy it difined by default in compile debug configuration).
4) Define LOG macro (for use LOG_PRINT, ERROR_PRINT and WARNING) in your source files or in your cmpiler options.
5) Use macroses where you need.
6) If need can redefine print function (for examplr redirect to UART).


It usefull to create configurations DEBUG and RELEASE.

For example:

In DEBUG configuration add DEBUG and LOG macroses to compiler options. In RELEASE configuration add just LOG macro to compiler options.

So you won't need remove your debug messages in release build.
