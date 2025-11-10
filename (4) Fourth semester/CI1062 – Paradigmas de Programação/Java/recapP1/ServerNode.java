import java.util.*;

public class ServerNode extends NetworkNode implements Consumable {
    private Double cpuLoad = 0.0;
    private Integer processedPacketCount = 0;
    private List<DataPacket> storage = new ArrayList<DataPacket>();

    public ServerNode() {}


    public ServerNode(String id, Integer upTime, Boolean isActive, Double cpuLoad, Integer processedPacketCount, List<DataPacket> storage) {
        super(id, upTime, isActive);
        this.setCpuLoad(cpuLoad);
        this.setProcessedPacketCount(processedPacketCount);
        this.setStorage(storage);
    }

    public ServerNode(String id) {
        this(id, null, null, null, null, null);
    }

    public void setCpuLoad(Double cpuLoad) {
        if (cpuLoad != null) {
            this.cpuLoad = cpuLoad;
        }
    }

    public Double getCpuLoad() {
        return this.cpuLoad;
    }

    public void setProcessedPacketCount(Integer processedPacketCount) {
        if (processedPacketCount != null) {
            this.processedPacketCount = processedPacketCount;
        }
    }

    public Integer getProcessedPacketCount() {
        return this.processedPacketCount;
    }

    public void setStorage(List<DataPacket> storage) {
        if (storage != null) {
            this.storage = storage;
        }
    }

    public List<DataPacket> getStorage() {
        return this.storage;
    }

    public void consumeData(DataPacket dataPacket) {
        this.cpuLoad = this.cpuLoad + 2;
        this.processedPacketCount = this.processedPacketCount + 1;
        this.storage.add(dataPacket);
    }

    public String getStatus() {
        return this.getId() + " " + this.getUpTime() + " " + this.getIsActive() + " " + this.getCpuLoad() + " " + this.getProcessedPacketCount();
    }
}