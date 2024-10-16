#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

const char* ssid = "Wi-Ghost ";
const char* password = "<-#740.monline.io#->";

int ledPin = 2; // Pin del LED
WiFiServer server(80); // Servidor web en el puerto 80

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Conectando a WiFi...");
  }
  
  server.begin();
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  WiFiClient client = server.available(); // Espera a un cliente
  if (client) {
    String request = client.readStringUntil('\r');
    
    if (request.indexOf("/led/on") != -1) {
      digitalWrite(ledPin, HIGH); // Enciende el LED
    }
    if (request.indexOf("/led/off") != -1) {
      digitalWrite(ledPin, LOW); // Apaga el LED
    }

    client.flush();
    client.stop();
  }
}
