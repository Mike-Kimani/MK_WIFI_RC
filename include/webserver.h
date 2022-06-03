// Load Wi-Fi library
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <html.h>


// Variable to store the HTTP request
String header;

void wificonnect()
{
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while(WiFi.status()!= WL_CONNECTED)
    {
        Serial.println("Attempting WiFi reconnection");
        delay(1000);
    }
    Serial.println(WiFi.localIP());

}

// Set web server port number to 80
AsyncWebServer server(80);

void notFound(AsyncWebServerRequest *request)
{
  request->send(404, "text/plain", "Not found");
}


void clientinput()
{
    // Send web page to client
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", index_html); });

    // Receive an HTTP GET request
    server.on("/on1", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    accelerator_state = 1;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/off1", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    accelerator_state = 0;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/on2", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    leftstate = 1;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/off2", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    leftstate = 0;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/on3", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    rightstate = 1;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/off3", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    rightstate = 0;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/on4", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    decelerator_state = 1;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/off4", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    decelerator_state = 0;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/on6", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    centerstate = 1;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/off6", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    centerstate = 0;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/on5", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    emergency_state = 1;
    request->send(200, "text/plain", "ok"); });

    // Receive an HTTP GET request
    server.on("/off5", HTTP_GET, [](AsyncWebServerRequest *request)
            {
    emergency_state = 0;
    request->send(200, "text/plain", "ok"); });

    server.onNotFound(notFound);
    server.begin();   
}




