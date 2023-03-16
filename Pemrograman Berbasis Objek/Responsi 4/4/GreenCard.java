class GreenCard extends Card {
    public GreenCard() {
        super();
    }

    public GreenCard(Double _number) {
        super(_number);
    }

    public Double value() {
        return super.getNumber() + 0.6;
    }

    public void printInfo() {
        System.out.println("Kartu Hijau: " + super.getNumber());
    }
}
