class YellowCard extends Card {
    public YellowCard() {
        super();
    }

    public YellowCard(Double _number) {
        super(_number);
    }

    public Double value() {
        return super.getNumber() + 0.6;
    }

    public void printInfo() {
        System.out.println("Kartu Kuning: " + super.getNumber());
    }
}
