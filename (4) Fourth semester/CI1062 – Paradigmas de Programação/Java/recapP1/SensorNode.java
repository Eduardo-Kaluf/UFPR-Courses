import java.util.Random;
import java.util.*;

public class SensorNode extends NetworkNode implements Producible {
    private static final Random random = new Random();

    private String sensorType = "TESTE SENSOR";

    public SensorNode() {}

    public SensorNode(String id, Integer upTime, Boolean isActive, String sensorType) {
        super(id, upTime, isActive);
        this.setSensorType(sensorType);
    }

    public SensorNode(String id) {
        this(id, null, null, null);
    }

    public SensorNode(String id, String sensorType) {
        this(id, null, null, sensorType);
    }

    public void setSensorType(String sensorType) {
        if (sensorType != null) {
            this.sensorType = sensorType;
        }
    }

    public String getSensorType() {
        return this.sensorType;
    }

    public DataPacket produceData() {
        return new DataPacket(this.getId(), this.getSensorType() + ":" + random.nextInt(), System.currentTimeMillis());
    }

    public String getStatus() {
        return this.getId() + " " + this.getUpTime() + " " + this.getIsActive() + " " + this.getSensorType();
    }
}