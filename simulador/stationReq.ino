/*
  Conexão AP - WebServer
  IOT na prática com o ESP8266
  https://github.com/esp8266/Arduino/tree/master/doc/esp8266wifi
  http://tomeko.net/online_tools/cpp_text_escape.php?lang=en
*/

#include <ESP8266WiFi.h>

const char *ssid = "SSID"; //Nome do AP a ser conectado
const char *password = "SENHA"; //Senha do AP

//Configura o WifiServer
WiFiServer servidor(80);

void setup() {
  Serial.begin(115200);
  Serial.println();
  //Conectando no AP
  WiFi.begin(ssid, password);
  Serial.print("Conectando");
  while (WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  IPAddress MeuIP = WiFi.localIP();
  Serial.print("Endereço AP : ");
  Serial.println(MeuIP);
  /*Start WebServer*/
  servidor.begin();
}

void loop() {
  WiFiClient client = servidor.available();
  if (client){
      Serial.println("Requisicao Feita");
      pagina = "{\"debug\":\"OK\"}";
      client.print(pagina);
      // delay(1000);
  } else {
    // Serial.println("Sem Requisicao");
  }
}