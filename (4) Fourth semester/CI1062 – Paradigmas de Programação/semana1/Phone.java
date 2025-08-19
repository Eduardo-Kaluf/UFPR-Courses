
public class Phone {
    private int countryCode;
    private int areaCode;
    private int number;


    public int getCountryCode() {
        return this.countryCode;
    }

    public int getAreaCode() {
        return this.areaCode;
    }

    public int getNumber() {
        return this.number;
    }

    public void setCountryCode(int countryCode) {
        if (countryCode == 55 || countryCode == 1 || countryCode == 61) {
            this.countryCode = countryCode;
        }
    }

    public void setAreaCode(int areaCode) {
        this.areaCode = areaCode;
    }

    public void setNumber(int number) {
        if ((number > 9999999) && (number < 100000000)) {
            this.number = number;
        }
    }

    @Override
    public String toString() {
        return getClass().getName() + "+" + countryCode + " (" + areaCode + ") " + number;
    }
}