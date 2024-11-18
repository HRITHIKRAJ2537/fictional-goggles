#include "mdns_discovery.h"

void discoverLaptops() {
  // Ensure Wi-Fi is connected
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("Wi-Fi not connected. Cannot perform mDNS discovery.");
    return;
  }

  Serial.println("Starting mDNS discovery...");

  // Query for mDNS services (e.g., "_http._tcp." for HTTP services)
  int n = MDNS.queryService("http", "tcp"); // Replace with your desired service type

  // Check for discovered services
  if (n == 0) {
    Serial.println("No mDNS services found.");
  } else {
    Serial.println("mDNS services discovered:");
    for (int i = 0; i < n; i++) {
      Serial.printf("  %d: %s at %s:%u\n",
                    i + 1,
                    MDNS.hostname(i).c_str(),
                    MDNS.IP(i).toString().c_str(),
                    MDNS.port(i));
    }
  }
}

