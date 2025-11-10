public class Main {

    public static void main(String[] args) {
        System.out.println("Initializing Network Manager...");
        NetworkManager networkManager = new NetworkManager();

        // Create nodes
        System.out.println("Creating network nodes...");
        ServerNode mainServer = new ServerNode("SRV-01");
        ServerNode backupServer = new ServerNode("SRV-02");
        SensorNode tempSensor = new SensorNode("SNS-TEMP-A", "Temperature");
        SensorNode humiditySensor = new SensorNode("SNS-HUM-B", "Humidity");
        FirewallNode mainFirewall = new FirewallNode("FW-MAIN");
        SensorNode pressureSensor = new SensorNode("SNS-PRES-C", "Pressure");

        // Add all of them
        System.out.println("Adding nodes to the network...");
        networkManager.addNode(mainServer);
        networkManager.addNode(backupServer);
        networkManager.addNode(tempSensor);
        networkManager.addNode(humiditySensor);
        networkManager.addNode(mainFirewall);
        networkManager.addNode(pressureSensor);
        
        System.out.println("\nInitial Network Status:");
        networkManager.printNetworkStatus();

        // Run the simulation
        int simulationCycles = 10;
        System.out.println("\nStarting Simulation for " + simulationCycles + " cycles\n");
        
        for (int i = 1; i <= simulationCycles; i++) {
            System.out.println("==================== Cycle " + i + " ====================");
            
            // Run one cycle of the simulation
            networkManager.runSimulationCycle();
            
            // Print the status of all nodes after the cycle
            networkManager.printNetworkStatus();

            try {
                Thread.sleep(1000); // 1 second pause
            } catch (InterruptedException e) {
                System.err.println("Simulation interrupted.");
                Thread.currentThread().interrupt();
            }
        }

        // Print summary message
        System.out.println("\n==============================================");
        System.out.println("Simulation Finished.");
        System.out.println("Final Network Status:");
        networkManager.printNetworkStatus();
    }
}