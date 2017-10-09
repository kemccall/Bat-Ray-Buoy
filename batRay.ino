/***************************************************
  This is an example for our Adafruit FONA Cellular Module
 ****************************************************/

#include "Adafruit_FONA.h"

#define FONA_RX 2
#define FONA_TX 3
#define FONA_RST 4

extern float getCurrentTide (void);

// this is a large buffer for replies

char replybuffer[255];

#include <SoftwareSerial.h>

SoftwareSerial fonaSS = SoftwareSerial(FONA_TX, FONA_RX);
SoftwareSerial *fonaSerial = &fonaSS;

// Use this for FONA 800 and 808s

Adafruit_FONA fona = Adafruit_FONA(FONA_RST);

uint8_t readline(char *buff, uint8_t maxbuff, uint16_t timeout = 0);

uint8_t type;

uint32_t minuteCnt =0;
char url[100] = "http://data.sparkfun.com/input/AJllvdoZpYhbYJ33RX2o.txt?private_key=rzVVNADErKueN5MM1kVE";
char url1[150];
float currentTide;
int d1;
float d2;
char buffer[8];

void setup() 
    {
    fona_setup();
    tide_setup();
    }

void fona_setup()
    {
    while (!Serial);

    Serial.begin(115200);
    Serial.println(F("FONA basic test"));
    Serial.println(F("Initializing....(May take 3 seconds)"));

    fonaSerial->begin(4800);
    if (! fona.begin(*fonaSerial)) 
        {
        Serial.println(F("Couldn't find FONA"));
        while (1);
        }

    type = fona.type();
    Serial.println(F("FONA is OK"));
    Serial.print(F("Found "));
    switch (type) 
        {
        case FONA800L:
            Serial.println(F("FONA 800L")); break;
        case FONA800H:
            Serial.println(F("FONA 800H")); break;
        case FONA808_V1:
            Serial.println(F("FONA 808 (v1)")); break;
        case FONA808_V2:
            Serial.println(F("FONA 808 (v2)")); break;
        case FONA3G_A:
            Serial.println(F("FONA 3G (American)")); break;
        case FONA3G_E:
            Serial.println(F("FONA 3G (European)")); break;
        default: 
            Serial.println(F("???")); break;
        }
  
    // Print module IMEI number.

    char imei[15] = {0}; // MUST use a 16 character buffer for IMEI!
    uint8_t imeiLen = fona.getIMEI(imei);
    if (imeiLen > 0) 
        {
        Serial.print(F("Module IMEI: ")); Serial.println(imei);
        }

    // Optionally configure a GPRS APN, username, and password.
    // You might need to do this to access your network's GPRS/data
    // network.  Contact your provider for the exact APN, username,
    // and password values.  Username and password are optional and
    // can be removed, but APN is required.
    //fona.setGPRSNetworkSettings(F("your APN"), F("your username"), F("your password"));

    fona.setGPRSNetworkSettings(F("epc.tmobile.com"), F(""), F(""));

    // Optionally configure HTTP gets to follow redirects over SSL.
    // Default is not to follow SSL redirects, however if you uncomment
    // the following line then redirects over SSL will be followed.
    //fona.setHTTPSRedirect(true);

    //fona.setHTTPSRedirect(true);

    Serial.print(F("FONA> "));

#if 0
    while (! Serial.available() ) 
        {
        Serial.print("!");
        if (fona.available()) 
            {
            Serial.println(F("Calling Serial.write(fona.read()"));
            Serial.write(fona.read());
            }
        }
#endif

    delay (10000);

    // read the CCID
    Serial.println("read the CCID");
    fona.getSIMCCID(replybuffer);  // make sure replybuffer is at least 21 bytes!
    Serial.print(F("SIM CCID = ")); Serial.println(replybuffer);

    // read the network/cellular status

    Serial.println(F("read the network/cellular status"));
    uint8_t n = fona.getNetworkStatus();
    Serial.print(F("Network status "));
    Serial.print(n);
    Serial.print(F(": "));
    if (n == 0) Serial.println(F("Not registered"));
    if (n == 1) Serial.println(F("Registered (home)"));
    if (n == 2) Serial.println(F("Not registered (searching)"));
    if (n == 3) Serial.println(F("Denied"));
    if (n == 4) Serial.println(F("Unknown"));
    if (n == 5) Serial.println(F("Registered roaming"));

    // turn GPRS on

    Serial.println(F("Turn GPRS on"));
        
    if (!fona.enableGPRS(true))
        {
        Serial.println(F("Failed to turn on"));
        return;
        }
          
    minuteCnt = 0;
    }

void loop() 
    {
    fona_loop();
    tide_loop();
    }

void fona_loop ()
    {
    // Post data to website

    Serial.println(F("Post data to website every 10 secs."));

    delay (30000);

    minuteCnt++;

    if (minuteCnt >= 5)
        {
        Serial.println(F("Returning from loop"));
        return;
        }
    else
        {
        Serial.print(F("minuteCnt = "));
        Serial.println(minuteCnt,DEC);
        }

    // read website URL
    uint16_t statuscode;
    int16_t length;
    //char url[80];

    flushSerial();
        
    //Serial.println(url);
    currentTide = getCurrentTide();
    Serial.print(F("CurrentTide = "));
    Serial.println(currentTide);
    dtostrf(currentTide,10,4,buffer);
    Serial.print(F("buffer = "));
    Serial.println(buffer);
    
    sprintf (url1, "%s&tide=%s&val1=sek&count=%d&temp=1.444", url, buffer, minuteCnt);
    Serial.println(url1);
    if (!fona.HTTP_GET_start(url1, &statuscode, (uint16_t *)&length))
        {
        Serial.println("Failed!");
        return;
        }
    while (length > 0) 
        {
        while (fona.available()) 
            {
            char c = fona.read();

            // Serial.write is too slow, we'll write directly to Serial register!
#if defined(__AVR_ATmega328P__) || defined(__AVR_ATmega168__)
            loop_until_bit_is_set(UCSR0A, UDRE0); /* Wait until data register empty. */
            UDR0 = c;
#else
            Serial.write(c);
#endif
            length--;
            if (! length) break;
            }
        }
    Serial.println(F("\n****"));
    fona.HTTP_GET_end();
  
    // flush input
    flushSerial();

    while (fona.available()) 
        {
        Serial.write(fona.read());
        }
    }

void flushSerial() 
    {
    while (Serial.available())
        Serial.read();
    }


