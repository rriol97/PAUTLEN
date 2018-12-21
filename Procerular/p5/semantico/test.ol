main {
    int i;
    
    function int sinIva(int precio) {
        int iva;
        boolean b;

        iva = precio * 5;
        b = 1;
        return (b + iva);
    }

    printf sinIva(1000);

}