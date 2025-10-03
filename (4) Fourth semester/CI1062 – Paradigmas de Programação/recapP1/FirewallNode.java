import java.util.*;

public class FirewallNode extends NetworkNode implements Producible, Consumable {
    private String forwardingRule = "TEST RULE";
    private List<String> logList = new ArrayList<String>();
    private DataPacket hostedPacket;

    public FirewallNode() {}

    public FirewallNode(String id, Integer upTime, Boolean isActive, String forwardingRule, List<String> logList, DataPacket hostedPacket) {
        super(id, upTime, isActive);
        this.setForwardingRule(forwardingRule);
        this.setLogList(logList);
        this.setHostedPacket(hostedPacket);
    }

    public FirewallNode(String id) {
        this(id, null, null, null, null, null);
    }

    public FirewallNode(String id, Integer upTime, Boolean isActive, String forwardingRule, List<String> logList) {
        this(id, upTime, isActive, forwardingRule, logList, null);
    }

    public void setForwardingRule(String forwardingRule) {
        if (forwardingRule != null) {
            this.forwardingRule = forwardingRule;
        }
    }

    public String getForwardingRule() {
        return this.forwardingRule;
    }

    public void setLogList(List<String> logList) {
        if (logList != null) {
            this.logList = logList;
        }
    }

    public List<String> getLogList() {
        return this.logList;
    }

    public void setHostedPacket(DataPacket hostedPacket) {
        if (hostedPacket != null) {
            this.hostedPacket = hostedPacket;
        }
    }

    public DataPacket getHostedPacket() {
        return this.hostedPacket;
    }

    public void consumeData(DataPacket hostedPacket) {
        this.logList.add(hostedPacket.getPayload());
    
        this.setHostedPacket(hostedPacket);
    }

    public DataPacket produceData() {
        DataPacket dataPacket = this.getHostedPacket();

        if (dataPacket != null) {
            this.setHostedPacket(null);
            return dataPacket;
        }

        return null;
    }

    public String getStatus() {
        return this.getId() + " " + this.getUpTime() + " " + this.getIsActive() + " " + this.getLogList().size();
    }
}
