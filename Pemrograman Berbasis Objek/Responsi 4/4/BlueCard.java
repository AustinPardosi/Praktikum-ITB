class BlueCard extends Card {
    public BlueCard() {
        super();
    }

    public BlueCard(Double _number) {
        super(_number);
    }

    public Double value() {
        return super.getNumber() + 0.6;
    }

    public void printInfo() {
        System.out.println("Kartu Biru: " + super.getNumber());
    }
}
