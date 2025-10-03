public abstract class NetworkNode {
    protected String id; // should be final
    protected Integer upTime = 0;
    protected Boolean isActive = false;

    public NetworkNode() {}
    
    public NetworkNode(String id, Integer upTime, Boolean isActive) {
        this.setId(id);
        this.setUpTime(upTime);
        this.setIsActive(isActive);
    }

    public String getId() {
        return this.id;
    }

    private void setId(String id) {
        if (id != null) {
            this.id = id;
        }
    }

    public void setUpTime(Integer upTime) {
        if (upTime != null) {
            this.upTime = upTime;
        }
    }

    public Integer getUpTime() {
        return this.upTime;
    }

    public void setIsActive(Boolean isActive) {
        if (isActive != null) {
            this.isActive = isActive;
        }
    }

    public Boolean getIsActive() {
        return this.isActive;
    }

    public void tick() {
        this.upTime = this.upTime + 1;
    }

    public abstract String getStatus();
}