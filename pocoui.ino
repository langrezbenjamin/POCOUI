#include <ESP8266WiFi.h>
#include <Adafruit_NeoPixel.h>
#include <WiFiClient.h> 
#include <ESP8266WebServer.h>
 
#define PIN      4
#define N_LEDS  8

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

#define LARGEUR  22
#define HAUTEUR  5
#define LARGEUR_LETTRE  (3-1)
#define HAUTEUR_LETTRE  (5-1)

int valeur = 0;
int valeur2 = 0;
int valeur3 = 0;

int aa=0;
int dd=22;
int ee=44;
int gg=66;
int hh=88;

uint8_t tableau_lettre[16][5]= {{0b111,0b101,0b101,0b101,0b111},\
                               {0b001,0b001,0b001,0b001,0b001},\
                               {0b111,0b001,0b111,0b100,0b111},\
                               {0b111,0b001,0b111,0b001,0b111},\
                               {0b101,0b101,0b111,0b001,0b001},\
                               {0b111,0b100,0b111,0b001,0b111},\
                               {0b111,0b100,0b111,0b101,0b111},\
                               {0b111,0b001,0b001,0b001,0b001},\
                               {0b111,0b101,0b111,0b101,0b111},\
                               {0b111,0b101,0b111,0b001,0b111},\
                               {0b111,0b100,0b110,0b100,0b111},\
                               {0b100,0b100,0b100,0b100,0b111},\
                               {0b111,0b111,0b111,0b111,0b111},\
                               {0b010,0b010,0b010,0b010,0b010},\
                               {0b111,0b100,0b111,0b100,0b111},\
                               {0b101,0b111,0b111,0b111,0b101},};

//0-3 => todo

int delayval = 500; // delay for half a second1

//const char* ssid = "benaur";
//const char* password = "benjaminaurelie";

const char *ssid = "nodemcu";
const char *password = "password";

//ESP8266WebServer server(80);

// Create an instance of the server
// specify the port to listen on as an argument
WiFiServer server(80);

void display(int val,uint8_t  pos, byte red, byte green, byte blue){
int8_t i;
int8_t j;
for(i=0;i<3;i++)
  {
  for(j=0;j<5;j++)
    {

//4 est la largeur d'une lettre
      uint8_t led_position=(pos)+(LARGEUR_LETTRE-i)+j*LARGEUR;
      if(((tableau_lettre[val][j]) & (1<<i)) !=0)
        strip.setPixelColor(led_position  ,red, green, blue);
      else
        strip.setPixelColor(led_position  ,0, 0, 0);
    }
  strip.show();
  }
}
void ccc(){
    for(uint16_t i=0; i<strip.numPixels(); i++) {
            strip.setPixelColor(i  ,0, 0, 0); // Draw new pixel
            strip.show();
      }
}

void  fff(){
  strip.setPixelColor(0  ,0, 0, 255); // Draw new pixel
  strip.setPixelColor(1  ,0, 0, 255); // Draw new pixel
  strip.setPixelColor(2  ,0, 0, 255); // Draw new pixel

  strip.setPixelColor(3  ,255, 255, 255); // Draw new pixel
  strip.setPixelColor(4  ,255, 255, 255); // Draw new pixel

  strip.setPixelColor(5  ,255, 0, 0); // Draw new pixel
  strip.setPixelColor(6  ,255, 0, 0); // Draw new pixel
  strip.setPixelColor(7  ,255, 0, 0);
  strip.show();
}
void  lil(){
  display(11,0, 255, 255, 0);
  display(13,4, 42, 62, 80);
  display(11,8, 255, 255, 0);
}
void  jam(){
  ccc();
  display(12,0, 0, 255, 0);
    delay(1000);   
  display(12,4, 255, 255, 0);
    delay(1000);   
  display(12,8, 255, 0, 0);
}  
void  jem(){
  ccc();
  display(8,0, 255, 0, 255);
  display(14,4, 128, 128, 255);
  display(15,8, 255, 0, 0);
  delay(500);
  ccc();
  display(8,0, 255, 255, 0);
  display(14,4, 0, 255, 69);
  display(15,8, 255, 0, 0);
}  

static void chase(uint32_t x,uint32_t y,uint32_t tt) {
  for(uint16_t i=x; x<y+4; x++) {
      strip.setPixelColor(x  , tt); // Draw new pixel
      strip.setPixelColor(x-4, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}
static void chase2(uint32_t x,uint32_t y) {
  for(uint16_t i=x; x<y+4; x++) {
      strip.setPixelColor(x  , strip.Color(255, 128, 128)); // Draw new pixel
      strip.setPixelColor(x-4, 0); // Erase pixel a few steps back
      strip.setPixelColor(x+21  , strip.Color(255, 0, 0)); // Draw new pixel
      strip.setPixelColor(x-17, 0); // Erase pixel a few steps back
      strip.setPixelColor(x+43  , strip.Color(128, 0, 0)); // Draw new pixel
      strip.setPixelColor(x+39, 0); // Erase pixel a few steps back
      strip.setPixelColor(x+65  , strip.Color(255, 0, 0)); // Draw new pixel
      strip.setPixelColor(x+61, 0); // Erase pixel a few steps back
      strip.setPixelColor(x+87  , strip.Color(255, 128, 128)); // Draw new pixel
      strip.setPixelColor(x-83, 0); // Erase pixel a few steps back
      strip.show();
      delay(25);
  }
}
void  kite(){
  ccc();
  chase(1,11,strip.Color(255, 0, 0)); // Red
  ccc();
  chase(22,33,strip.Color(255, 0, 0)); // Red
  ccc();
  chase(44,55,strip.Color(255, 0, 0)); // Red
  ccc();
  chase(44,55,strip.Color(255, 128, 128)); // Red 75
  chase(66,77,strip.Color(255, 0, 0)); // Red
  chase(88,99,strip.Color(255, 128, 128)); // Red 75
  chase(88,99,strip.Color(255, 0, 0)); // Red
  ccc();
} 
void  kite2(){
  ccc();
  chase2(1,11);
  ccc();
} 
void loop() 
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }
  while(!client.available()){
    delay(1);
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  client.flush();
  
  // Match the request
  bool val0, val4, val5, val16;
  val0=digitalRead(0);
  val4=digitalRead(4);
  val5=digitalRead(5);
  val16=digitalRead(16);

  String a = req.substring(5,6);
  String b = req.substring(6,7);
  String c = req.substring(7,8);
  String d = req.substring(8,9);

  valeur = a.toInt();
  valeur2 = b.toInt();
  valeur3 = c.toInt();


  client.flush();
    // Prepare the response 
 String s = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<!DOCTYPE HTML>\r\n<html>\r\n";

 
  if (req.indexOf("cc") != -1 ){
    aa=0;
    dd=22;
    ee=44;
    gg=66;
    hh=88;
    ccc();
  }

if (req.indexOf("aa") != -1 ){
  for(uint16_t i=0; i<N_LEDS; i++) {
      strip.setPixelColor(i  ,255, 0, 0); // Draw new pixel
      strip.show();
  }  
}

if (req.indexOf("dd") != -1 ){
  for(uint16_t i=0; i<N_LEDS; i++) {
      strip.setPixelColor(i  ,0, 0, 255); // Draw new pixel
      strip.show();
  }
}
if (req.indexOf("ee") != -1 ){
  for(uint16_t i=0; i<N_LEDS; i++) {
      strip.setPixelColor(i  ,0, 255, 0); // Draw new pixel
      strip.show();
  }
}
if (req.indexOf("gg") != -1 ){
  for(uint16_t i=0; i<N_LEDS; i++) {
      strip.setPixelColor(i  ,255, 255, 0); // Draw new pixel
      strip.show();
  }
}
if (req.indexOf("hh") != -1 ){
  for(uint16_t i=0; i<N_LEDS; i++) {
      strip.setPixelColor(i  ,42, 62, 80); // Draw new pixel
      strip.show();
  }
}

  if (req.indexOf("ff") != -1 )
    fff(); 
  if (req.indexOf("lil") != -1 )
    lil();  
  if (req.indexOf("jem") != -1 )
    jem();  
  if (req.indexOf("jam") != -1 )
    jam();  
  if (req.indexOf("kite") != -1 )
    kite();  
  if (req.indexOf("mak") != -1 )
    kite2();      
  if (req.indexOf("/etat/") != -1 ){
    String xx = req.substring(10,13);
    String yy = req.substring(14,17);
    String zz = req.substring(18,21);
    int x=xx.toInt();
    int y=yy.toInt();
    int z=zz.toInt();
    display(12,0, x, y, z);
    display(12,4, x, y, z);
    display(12,8, x, y, z); 

    s += xx;
    s +=" V --<br>";
    s += yy;
    s +=" R --<br>";
        s += zz;
    s +=" B --<br>";
    s +=" Couleur<br>";
    s += "</html>\n";
    
  }
  // Send the response to the client
  client.print(s);
  delay(1);
}
void setup() {
  strip.begin();
  delay(10);
  // prepare GPIO4 Interupteur front
  pinMode(4, OUTPUT);
  digitalWrite(4, 0);
  WiFi.softAP(ssid, password);

  fff();
  delay(1000);
  ccc();
  server.begin();
}
