//
// Simple class to compare coming characters from any stream and compare it with predefined string constants.
// Get characters from stream, one by one, perform non-blocking comparison with predefined string constants, on the fly.
// Return true if match found. May perform case sensitive or case in-sensitive comparison.
// Allow multiple instances and re-assigning string constants.
//
// By Serge Skorodinsky, 2017
//

#include "SSVWaitForStringInStream.h"
#include <Arduino.h> 

WaitForStringInStream::WaitForStringInStream()
{
  _str = "";
  _index=0;  
  _casesensitive=true;
  _lastcheck=false;
}

WaitForStringInStream::WaitForStringInStream(char *strToWait)
{
  _str = strToWait;
  _index=0;  
  _casesensitive=true;
  _lastcheck=false;
}

void WaitForStringInStream::setStrToWait(char *strToWait)
{
  _str = strToWait;
  _index=0; 
  _lastcheck=false;
}

char * WaitForStringInStream::getStrToWait()
{
  return _str;
}

bool WaitForStringInStream::CheckNextChar(char c)
{
  if (c ==0) {_lastcheck=false; return false;}  //just in case, ignore zero-char

  if (_str[_index] == 0) 
    {
    //already matching, just in case of _str is empty, always matching
    _index=0;
    _lastcheck=true;
    return true;
    }
  
  if ( charcomp(_str[_index], c) )
    {
    //current char match
    _index++;
    if (_str[_index] == 0) 
      {//done, all characters matched
      _index=0;
      _lastcheck=true;
      return true;
      }
  }
  else
    {
    //current char not match - reset index
    _index=0;
    }
_lastcheck=false;
return false;
}

bool WaitForStringInStream::getCaseSensitive()
{
return _casesensitive;
}

void WaitForStringInStream::setCaseSensitive(bool CaseSensitive)
{
_casesensitive = CaseSensitive;
_index=0;
_lastcheck=false;
}

bool WaitForStringInStream::charcomp(char a, char b)
{
if (_casesensitive)
  return (a == b);
 else 
  return (toupper(a) == toupper(b));
}

bool WaitForStringInStream::getLastCheck()
{
return _lastcheck;
}

// END OF FILE   `