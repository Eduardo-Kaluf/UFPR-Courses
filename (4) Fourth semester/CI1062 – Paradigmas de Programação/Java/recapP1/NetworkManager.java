import java.util.*;

public class NetworkManager {
    private Map<String, NetworkNode> web = new HashMap<String, NetworkNode>();

    public void addNode(NetworkNode node) {
        this.web.put(node.getId(), node);
    }

    public NetworkNode getNode(String id) {
        return this.web.get(id);
    }

    public void runSimulationCycle() {
        List<DataPacket> packetsProducedThisCycle = new ArrayList<>();

        for (NetworkNode node : this.web.values()) {
            node.tick();

            if (node instanceof Producible) {
                Producible producer = (Producible) node;
                DataPacket newPacket = producer.produceData();

                if (newPacket != null) {
                    packetsProducedThisCycle.add(newPacket);
                }
            }
        }

        for (DataPacket packet : packetsProducedThisCycle) {
            for (NetworkNode targetNode : this.web.values()) {
                
                if (targetNode instanceof Consumable && !targetNode.getId().equals(packet.getSourceId())) {
                    
                    packet.setDestinationId(targetNode.getId());

                    Consumable consumer = (Consumable) targetNode;
                    consumer.consumeData(packet);
                    break;
                }
            }
        }
    }

    public void printNetworkStatus() {
        System.out.println("--- Current Network Status ---");
        for (NetworkNode node : this.web.values()) {
            System.out.println(node.getStatus());
        }
    }
}