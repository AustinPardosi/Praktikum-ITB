class RedCard extends Card {
    public RedCard() {
        super();
    }

    public RedCard(Double _number) {
        super(_number);
    }

    public Double value() {
        return super.getNumber() + 0.8;
    }

    public void printInfo() {
        System.out.println("Kartu Merah: " + super.getNumber());
    }
}
