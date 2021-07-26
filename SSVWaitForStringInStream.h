#ifndef WaitForStringInStream_h
#define WaitForStringInStream_h

class WaitForStringInStream
{
  public:
    WaitForStringInStream();
    WaitForStringInStream(char *strToWait);
    void setStrToWait(char *strToWait);
    char* getStrToWait();
    bool CheckNextChar(char c);
    bool getCaseSensitive();
    void setCaseSensitive(bool CaseSensitive);
    bool getLastCheck();
  
  protected:
    char *_str;
    int _index;
    bool _casesensitive;
    bool _lastcheck;
    bool charcomp(char a, char b);
};

#endif
// END OF FILE