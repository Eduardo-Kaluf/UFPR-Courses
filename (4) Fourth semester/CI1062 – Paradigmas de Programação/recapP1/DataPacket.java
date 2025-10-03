public class DataPacket {
    private String sourceId;
    private String destinationId;
    private String payload;
    private Long timeStamp;

    public DataPacket() {}

    public DataPacket(String sourceId, String payload, Long timeStamp) {
        this.setSourceId(sourceId);
        this.setPayload(payload);
        this.setTimeStamp(timeStamp);
    }

    public void setSourceId(String sourceId) {
        if (sourceId != null) {
            this.sourceId = sourceId;
        }
    }
    
    public String getSourceId() {
        return this.sourceId;
    }

    public void setDestinationId(String destinationId) {
        if (destinationId != null) {
            this.destinationId = destinationId;
        }
    }

    public String getDestinationId() {
        return this.destinationId;
    }

    public void setPayload(String payload) {
        if (payload != null) {
            this.payload = payload;
        }
    }

    public String getPayload() {
        return this.payload;
    }

    public void setTimeStamp(Long timeStamp) {
        if (timeStamp != null) {
            this.timeStamp = timeStamp;
        }
    }

    public Long getTimeStamp() {
        return this.timeStamp;
    }
}
