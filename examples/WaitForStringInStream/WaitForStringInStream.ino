#include "SSVWaitForStringInStream.h"

WaitForStringInStream wss1; // --- empty string, will match always, to any character ---
WaitForStringInStream wss2("qwe");
WaitForStringInStream wss3("ASD");

int cnt1,cnt2,cnt3; //matching counters

void ShowStatusWSS(WaitForStringInStream wss)
{
  //just to show current status
  if (wss.getCaseSensitive()) {Serial.print("CaseSensitive, ");} else {Serial.print("NO CaseSensitive, ");}
  Serial.print("StrToWait: "); Serial.println( wss.getStrToWait() ); 
}

void setup() 
{
  Serial.begin(9600); 
  //wss1
  wss2.setCaseSensitive(false); // set wss1 as NON-Case Sensitive, default is CaseSensitive
  Serial.print("Show wss1 status: "); ShowStatusWSS(wss1);
  Serial.print("Show wss2 status: "); ShowStatusWSS(wss2);
  Serial.print("Show wss3 status: "); ShowStatusWSS(wss3);

  Serial.println(); Serial.println("Now enter something...");
  
}

void loop() 
{
 char incomingByte;
 if (Serial.available() > 0) 
   {
   // read the incoming byte:
   incomingByte = Serial.read();
   // say what you got:
   Serial.print("Received: "); Serial.print(incomingByte); Serial.print(" ");
  
   if ( wss1.CheckNextChar(incomingByte) ) 
     {
     cnt1++;
     Serial.print("\r\n--> MATCH wss1 "); Serial.print(cnt1); Serial.println(" times");
     wss1.setCaseSensitive(false);
     wss1.setStrToWait("ABC");
     Serial.print("wss1 status changed to: "); ShowStatusWSS(wss1);
     }

  if ( wss2.CheckNextChar(incomingByte) ) 
     {
     cnt2++;
     Serial.println("\r\n--> MATCH wss2 "); Serial.print(cnt2); Serial.println(" times");
     wss2.setCaseSensitive(true);
     wss2.setStrToWait("KUKU");
     Serial.print("wss2 status changed to: "); ShowStatusWSS(wss2);
     }

  if ( wss3.CheckNextChar(incomingByte) ) 
     {
      cnt3++;
     Serial.println("\r\n--> MATCH wss3 "); Serial.print(cnt3); Serial.println(" times");
     wss3.setCaseSensitive(false);
     wss3.setStrToWait("TEST");
     Serial.print("wss3 status changed to: "); ShowStatusWSS(wss3);
     }
   
  }
}
